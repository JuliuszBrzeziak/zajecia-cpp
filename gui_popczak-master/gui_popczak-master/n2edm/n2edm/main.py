import sys
from typing import Any
import ctypes

from matplotlib.pyplot import connect
from PyQt5 import Qt, QtCore, QtGui, QtWidgets, uic

from .dialogs import CloseEventDialog
from .files import FileManager
from .gant import n2EDMGant
from .tree import ActionTree
from .utils import Action, Group, Stack

from .icons import ICONS


class UiWindow(QtWidgets.QMainWindow, QtWidgets.QWidget):
    """MainWindow class
    """

    resize_sig = QtCore.pyqtSignal(object)
    save_actions_sig = QtCore.pyqtSignal()
    load_actions_sig = QtCore.pyqtSignal()
    save_schedule_sig = QtCore.pyqtSignal()
    load_schedule_sig = QtCore.pyqtSignal()
    add_action_sig = QtCore.pyqtSignal()
    add_timeline_element_sig = QtCore.pyqtSignal()

    def __init__(self):
        super(UiWindow, self).__init__()
        self.setWindowTitle("n2EDM Scheduler v. 1.0.2")
        self.init_widgets()
        self.init_menu_bar()
        self.connect_sig_slot()
        self.config = self.file_manager.read_config()
        self.file_manager.load_last_file()
        icon11 = ICONS['icon11'].as_posix()
        pixmap = QtGui.QPixmap(icon11)
        icon = QtGui.QIcon(pixmap)
        self.setWindowIcon(icon)
        self.stack = Stack()

    def init_widgets(self) -> None:
        """Initiate all main widgets in main window

        Returns:
            None
        """
        main_layout = QtWidgets.QVBoxLayout()
        central_widget = QtWidgets.QWidget()
        self.setCentralWidget(central_widget)
        central_widget.setLayout(main_layout)
        self.split_widget = QtWidgets.QSplitter(QtCore.Qt.Horizontal)
        main_layout.addWidget(self.split_widget)
        self.action_tree = ActionTree(self)
        self.n2edm_gant = n2EDMGant(self)
        self.file_manager = FileManager(self)
        self.split_widget.addWidget(self.n2edm_gant)
        self.split_widget.addWidget(self.action_tree)

    def init_menu_bar(self) -> None:
        """Initiate menu bar for main window with signals (menu actions) connections to functions in widgets

        Returns:
            None
        """
        main_menu = self.menuBar()
        self.save_actions_as = QtWidgets.QAction("Save actions as...")
        self.save_actions_as.triggered.connect(
            lambda: self.save_actions_sig.emit())
        self.load_actions_from = QtWidgets.QAction("Load actions from...")
        self.load_actions_from.triggered.connect(
            lambda: self.load_actions_sig.emit())
        self.save_schedule_as = QtWidgets.QAction("Save schedule as...")
        self.save_schedule_as.triggered.connect(
            lambda: self.save_schedule_sig.emit())
        self.load_schedule_from = QtWidgets.QAction("Load schedule from...")
        self.load_schedule_from.triggered.connect(
            lambda: self.load_schedule_sig.emit())

        self.file_menu = main_menu.addMenu("File")
        self.file_menu.addAction(self.save_actions_as)
        self.file_menu.addAction(self.load_actions_from)
        self.file_menu.addAction(self.save_schedule_as)
        self.file_menu.addAction(self.load_schedule_from)

        self.undo_action = QtWidgets.QAction("Undo...")
        self.undo_action.triggered.connect(self.undo)
        self.undo_action.setShortcut(QtGui.QKeySequence("Ctrl+Z"))
        self.redo_action = QtWidgets.QAction("Redo...")
        self.redo_action.triggered.connect(self.redo)
        self.redo_action.setShortcut(QtGui.QKeySequence("Ctrl+Y"))

        self.edit_menu = main_menu.addMenu("Edit")
        self.edit_menu.addAction(self.undo_action)
        self.edit_menu.addAction(self.redo_action)

        self.add_action = QtWidgets.QAction("Add Action...")
        self.add_action.triggered.connect(lambda: self.add_action_sig.emit())

        self.add_timeline = QtWidgets.QAction("Add Timeline...")
        self.add_timeline.triggered.connect(
            lambda: self.add_timeline_element_sig.emit())

        self.actions_menu = main_menu.addMenu("Actions")
        self.actions_menu.addAction(self.add_action)
        self.actions_menu.addAction(self.add_timeline)

    def connect_sig_slot(self) -> None:
        """Connects all custom slots and signals

        Returns:
            None
        """
        self.resize_sig.connect(self.n2edm_gant.resize_event)
        self.save_actions_sig.connect(self.action_tree.tree.save_actions)
        self.load_actions_sig.connect(self.file_manager.load_actions)
        self.save_schedule_sig.connect(self.n2edm_gant.save_schedule)
        self.load_schedule_sig.connect(self.file_manager.load_schedule)
        self.add_action_sig.connect(self.action_tree.tree.add_action)
        self.add_timeline_element_sig.connect(
            self.n2edm_gant.add_timeline_element)

        self.action_tree.tree.draw_actor_sig.connect(
            self.n2edm_gant.draw_actor_from_action)

        self.action_tree.tree.save_actions_sig.connect(
            self.file_manager.save_actions)
        self.file_manager.actions_dict_sig.connect(
            self.action_tree.tree.populate_tree)
        self.action_tree.tree.actions_changed.connect(
            self.file_manager.actions_changed)

        self.n2edm_gant.save_schedule_sig.connect(
            self.file_manager.save_schedule)
        self.file_manager.schedule_dict_sig.connect(
            self.n2edm_gant.load_schedule)
        self.n2edm_gant.schedule_changed.connect(
            self.file_manager.schedule_changed)

        self.n2edm_gant.request_action_sig.connect(
            self.action_tree.tree.recive_request_action)
        self.action_tree.tree.response_action_sig.connect(
            self.n2edm_gant.recieve_requested_action)
        self.action_tree.tree.model.update_actions_sig.connect(
            self.action_tree.tree.update_actions)
        self.action_tree.tree.delete_schedule_sig.connect(
            self.n2edm_gant.remove_action_schedule)
        self.action_tree.tree.action_updated.connect(self.n2edm_gant.update)

        self.n2edm_gant.undo_redo.connect(self.undo_redo)
        self.action_tree.tree.undo_redo.connect(self.undo_redo)

    def resizeEvent(self, event: object) -> None:
        """In addidion to normal resize, method emits signal for proper handling of resizing schedule

        Args:
            event (QEvent): Resize event

        Returns:
            None
        """
        super().resizeEvent(event)
        self.resize_sig.emit(event)

    def changeEvent(self, event: object) -> None:
        """In addidion to normal change (like move from desktop to desktop), method emits signal for proper handling of resizing schedule

        Args:
            event (QEvent): change event

        Returns:
            None
        """
        super().changeEvent(event)
        self.resize_sig.emit(event)

    def closeEvent(self, event: object) -> None:
        """Catch and handle close event if there are unsaved changes in document

        Args:
            event (QEvent): close event

        Returns:
            None

        """
        self.file_manager.save_config()
        if not self.file_manager.actions_saved or not self.file_manager.schedule_saved:
            self.close_dialog = CloseEventDialog()
            self.close_dialog.exec()
            if self.close_dialog.save:
                event.ignore()
        else:
            super().closeEvent(event)

    @QtCore.pyqtSlot(object)
    def undo_redo(self, command: object) -> None:
        """Prototype of undo redo functionality

        Args:
            command (object): Commend to undo changes

        Returns:
            None
        """
        self.stack.add_command(command)

    def undo(self):
        self.stack.undo()

    def redo(self):
        self.stack.redo()


def main():
    app = QtWidgets.QApplication(sys.argv)
    GUI = UiWindow()
    GUI.show()
    sys.exit(app.exec_())


if __name__ == "__main__":
    main()
