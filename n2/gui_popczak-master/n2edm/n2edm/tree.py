import weakref
from copy import copy, deepcopy
from hashlib import md5
from os.path import pardir

from PyQt5 import QtCore, QtGui, QtWidgets

from .dialogs import ActionEdit, ActionWizzard
from .gant import n2EDMGant
from .utils import Action, Command, Group


class ActionTree(QtWidgets.QWidget):
    """QWidget connecting TreeView ant Searchbar for it

    Args:
        parent (QWigdet): Parent widget
    """

    def __init__(self, parent):
        super().__init__(parent=parent)
        self.prepare_wiget()

    def prepare_wiget(self) -> None:
        """Creates layout and widgets (Tree and Bar)
        """
        main_layout = QtWidgets.QVBoxLayout(self)
        self.search_bar = SearchBar(self)
        self.tree = Tree(self)
        self.search_bar.search_sig.connect(self.tree.search)
        main_layout.addWidget(self.search_bar)
        main_layout.addWidget(self.tree)


class Tree(QtWidgets.QTreeView):
    """Tree Structure widget used to controll and hond information about actions.

    Args:
        parent (QWidget): Parent widget

    Attributes:
        self.actions (dict): Dictionary container for created actions
        self.groups (dict): Dictionary container for created groups

    """

    draw_actor_sig = QtCore.pyqtSignal(object)
    save_actions_sig = QtCore.pyqtSignal(dict)
    response_action_sig = QtCore.pyqtSignal(object)
    delete_schedule_sig = QtCore.pyqtSignal(list)
    undo_redo = QtCore.pyqtSignal(object)
    action_updated = QtCore.pyqtSignal()
    actions_changed = QtCore.pyqtSignal()

    def __init__(self, parent: QtWidgets.QWidget) -> None:
        super().__init__(parent=parent)
        self.model = StandardItemModel(self)
        self.proxy_model = QtCore.QSortFilterProxyModel()
        self.proxy_model.setSourceModel(self.model)
        self.proxy_model.setRecursiveFilteringEnabled(True)
        self.proxy_model.setFilterCaseSensitivity(QtCore.Qt.CaseInsensitive)
        self.setModel(self.proxy_model)
        self.setDragDropMode(self.DragOnly)
        self.setSelectionMode(self.SingleSelection)
        self.setSortingEnabled(True)
        self.sortByColumn(0, QtCore.Qt.AscendingOrder)

        self.actions = {}
        self.groups = {}

    def mouseDoubleClickEvent(self, event: QtCore.QEvent) -> None:
        """Overloaded method of mouseDoubleClickEvent. Emits signal with action (Adds actor).

        Args:
            event (QEvent): MouseClickEvent
        """
        action = self.currentIndex().data(role=257)
        if action is None:
            action = self.currentIndex().siblingAtColumn(
                self.currentIndex().column()-1).data(role=257)

        if isinstance(action, Action):
            self.draw_actor_sig.emit(action)

    @QtCore.Slot(str)
    def search(self, search_str: str) -> None:
        """Searches item in tree view by given name

        Args:
            search_str (str): Name of signal to seach
        """
        self.proxy_model.setFilterRegExp(search_str)

    def contextMenuEvent(self, event: QtCore.QEvent) -> None:
        """Context menu controller and looks for action tree.pardir

        Args:
            event (QtCore.QEvent): QContextEvent
        """
        self.menu = QtWidgets.QMenu(self)
        add_action = QtWidgets.QAction("Add Action...", self)
        edit_action = QtWidgets.QAction("Edit...", self)
        del_action = QtWidgets.QAction("Delete...", self)
        add_action.triggered.connect(self.add_action)
        edit_action.triggered.connect(self.edit_action)
        del_action.triggered.connect(self.remove_action)
        self.menu.addAction(add_action)
        self.menu.addAction(edit_action)
        self.menu.addAction(del_action)
        self.menu.popup(QtGui.QCursor.pos())

    @QtCore.pyqtSlot(dict)
    def populate_tree(self, actions_dict: dict) -> None:
        """Method uset to call populate function in model. (Fill tree with actions in dict format)

        Args:
            actions_dict (dict): Dictionary with actions
        """
        self.model.clear()
        self.model.setHorizontalHeaderLabels(["Actions List", "", ""])
        self.header().resizeSection(1, 0)
        try:
            self.actions, self.groups = self.model.populate(actions_dict)
        except ValueError as e:
            return

    @QtCore.pyqtSlot()
    def save_actions(self):
        """Emits signal to save actions
        """
        self.save_actions_sig.emit(self.actions)

    @QtCore.pyqtSlot(str)
    def recive_request_action(self, hash_id: str) -> None:
        """Container for request of action from schedule. Emits back action if exist.

        Args:
            hash_id (str): string with uniqe id
        """
        if hash_id in self.actions.keys():
            self.response_action_sig.emit(self.actions[hash_id])
        else:
            self.response_action_sig.emit(None)

    @QtCore.pyqtSlot()
    def add_action(self) -> None:
        """Opens dialog where user can create and add action.
        """
        add_action_wizzard = ActionWizzard(self)
        add_action_wizzard.action_dict_sig.connect(
            self.model.append_new_action)
        add_action_wizzard.exec()
        self.actions_changed.emit()

    def edit_action(self) -> None:
        """Opens dialog where user can edit action
        """
        action = self.currentIndex().data(role=257)
        if action == None:
            return
        edit_action_wizzard = ActionEdit(self, action)
        edit_action_wizzard.exec()
        if edit_action_wizzard.hash_id == None:
            return
        self.actions[edit_action_wizzard.unqid] = self.actions.pop(
            edit_action_wizzard.hash_id)
        proxy_index = self.currentIndex()
        model_index = self.proxy_model.mapToSource(proxy_index)
        self.model.itemFromIndex(model_index).setText(action.name)
        for actor in action.children:
            actor.update()
        self.action_updated.emit()
        self.actions_changed.emit()

    @QtCore.pyqtSlot(list)
    def update_actions(self, updated_actions: tuple) -> None:
        """Updates actions and groups based on model items

        Args:
            updated_actions (tuple[dict]): tuple of dicts with actions and groups
        """
        self.actions, self.groups = updated_actions

    def remove_action(self):
        """Remove selected group or action from tree
        """
        item = self.currentIndex().data(role=257)
        proxy_index = self.currentIndex()
        model_index = self.proxy_model.mapToSource(proxy_index)
        self.model.removeRow(model_index.row(), model_index.parent())
        if item == None:
            return
        if isinstance(item, Action):
            del self.actions[item.hashed_id]
            actors = item.children
            self.delete_schedule_sig.emit(actors)
            if len(item.group.children) == 1 and item.group.name != "...":
                del self.groups[item.group.name]
                self.model.removeRow(model_index.parent().row())
            else:
                item.remove()
            self.actions_changed.emit()
        else:
            del self.groups[item.name]
            actors = []
            for child in item.children:
                actors.extend(child.children)
            self.delete_schedule_sig.emit(actors)
            self.actions_changed.emit()

    def mousePressEvent(self, event: QtCore.QEvent) -> None:
        """Sets current index of action where user clicked

        Args:
            event (QtCore.QEvent): MousePressEvent
        """
        super().mousePressEvent(event)
        index = self.indexAt(event.pos())
        self.setCurrentIndex(index)

    def copy(self):
        return copy(self.actions)


class SearchBar(QtWidgets.QLineEdit):
    """Constructor for overwritten QLineEdit

    Args:
        QtWidgets (QWidget): QLineEdit
    """

    search_sig = QtCore.Signal(str)

    def __init__(self, parent):
        super().__init__(parent)

    def keyPressEvent(self, event: QtCore.QEvent) -> None:
        """Send string as signal to tree_view to search signals in tree_view

        Args:
            event (QEvent): Pressed key event
        """
        super().keyPressEvent(event)
        if event.key():
            self.search_sig.emit(self.text())


class StandardItemModel(QtGui.QStandardItemModel):
    """Model of items and data to hold by widget

    Args:
        parent (QWidget): parent widget

    Attributes:
        self.actions (dict): dictionary with actions
        self.groups (dict): dictionary with groups

    """

    update_actions_sig = QtCore.pyqtSignal(list)

    def __init__(self, parent: QtWidgets.QWidget) -> None:
        super(QtGui.QStandardItemModel, self).__init__()
        self.setColumnCount(3)
        self.parent = parent
        self.actions = {}
        self.groups = {}

    def populate(self, dictionary: dict) -> tuple:
        """Fills tree with actions based on dictionary. Also creates groups etc...

        Args:
            dictionary (dict): dictionary with actions

        Returns:
            tuple: pair of dictioraries of actions and groups
        """
        self.groups = {}
        self.actions = {}
        for key, value in dictionary.items():
            if len(value.values()) != 7:
                return
            name, start, stop, time_distance, parameter, color, group_name = value.values()
            time_distance = int(time_distance)
            uniqe_name = group_name + name
            hashed_id = md5(uniqe_name.encode("utf-8"))
            unqid = "id" + str(int(hashed_id.hexdigest(), 16))
            item = QtGui.QStandardItem()
            color_item = QtGui.QStandardItem()
            color_item.setBackground(QtGui.QBrush(
                QtGui.QColor(color), QtCore.Qt.SolidPattern))
            if group_name == "...":
                group = Group("...")
                uniqe_name = "..." + name
                hashed_id = md5(uniqe_name.encode("utf-8"))
                unqid = "id" + str(int(hashed_id.hexdigest(), 16))
                action = Action(name, start, stop, time_distance,
                                parameter, color, group)
                group.add_child(action)
                item.setText(f"{name}")
                item.setData(action)
                self.appendRow([item, color_item])
                self.actions[unqid] = action
                continue

            elif group_name not in self.groups.keys():
                group, parent_item = self.add_group_to_tree(group_name)
            else:
                group, parent_item = self.groups[group_name]

            action = Action(name, start, stop, time_distance,
                            parameter, color, group)
            item.setText(f"{name}")
            item.setData(action)
            parent_item.appendRow([item, color_item])
            group.add_child(action)

            self.actions[unqid] = action

        return self.actions, self.groups

    def add_group_to_tree(self, group_name: str) -> tuple:
        """Adds group to tree with at least one action

        Args:
            group_name (str): group name

        Returns:
            tuple: pair of group item with tree item as its parent
        """
        parent_item = QtGui.QStandardItem()
        group = Group(group_name)
        self.groups[group_name] = (group, parent_item)
        parent_item.setData(group)
        parent_item.setText(f"{group_name}")
        self.appendRow([parent_item, QtGui.QStandardItem()])
        return group, parent_item

    @QtCore.pyqtSlot(dict)
    def append_new_action(self, action: dict) -> None:
        """Appends new action to tree

        Args:
            action (dict): action in dict format
        """
        value, = list(action.values())
        name, start, stop, time_distance, parameter, color, group_name = value
        unqid, = list(action.keys())
        item = QtGui.QStandardItem()
        color_item = QtGui.QStandardItem()
        color_item.setBackground(QtGui.QBrush(
            QtGui.QColor(color), QtCore.Qt.SolidPattern))
        if group_name == "...":
            group = Group("...")
            action = Action(name, start, stop, time_distance,
                            parameter, color, group)
            group.add_child(action)
            item.setText(f"{name}")
            item.setData(action)
            self.appendRow([item, color_item])
            self.actions[unqid] = action
            self.update_actions_sig.emit([self.actions, self.groups])
            return
        elif group_name in self.groups.keys():
            group, parent_item = self.groups[group_name]
        else:
            group, parent_item = self.add_group_to_tree(group_name)

        action = Action(name, start, stop, time_distance,
                        parameter, color, group)
        item.setText(f"{name}")
        item.setData(action)
        parent_item.appendRow([item, color_item])
        group.add_child(action)
        self.actions[unqid] = action

        self.update_actions_sig.emit([self.actions, self.groups])
