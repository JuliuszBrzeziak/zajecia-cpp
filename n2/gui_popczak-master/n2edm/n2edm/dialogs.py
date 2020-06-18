import sys
from distutils.msvccompiler import read_values
from hashlib import md5
from n2edm.utils import Actor
from utils import Group, Action

from PyQt5 import Qt, QtCore, QtGui, QtWidgets, uic


class ActionWizzard(QtWidgets.QDialog):
    """ActionWizzard class. Dialog window to define action for schedule.

    Args:
        parent (QWidget): parent widget of dialog

    Attributes:
        self.group_name (str): Group name for action.
        self.action_name: (str): Action name
        self.start (int): Start SCPI command
        self.stop (int): Stop SCPI command
        self.parameter (str): Additional parameters to command
        self.time_distance (int): Base time distance (duration) of action
        self.color (str): colour of action as hex
        self.temp_names (list): List of temporary reserved names for groups
    """

    action_dict_sig = QtCore.pyqtSignal(dict)

    def __init__(self, parent: QtWidgets.QWidget) -> None:
        super().__init__(parent)
        self.parent = parent
        self.setWindowTitle("Add Action Wizzard")
        self.resize(640, 100)
        self.init_layout()
        self.init_widgets()
        self.fill_group_combo_box()
        self.connections()
        self.group_name = None
        self.action_name = None
        self.start = None
        self.stop = None
        self.parameter = None
        self.time_distance = None
        self.color = None
        self.temp_names = []

    def init_layout(self) -> None:
        """Initiate all layout for dialog

        Returns:
            None
        """
        self.layout = QtWidgets.QVBoxLayout()
        self.group_line_layout = QtWidgets.QHBoxLayout()
        self.action_line_layout = QtWidgets.QHBoxLayout()
        self.start_cmd_line_layout = QtWidgets.QHBoxLayout()
        self.stop_cmd_line_layout = QtWidgets.QHBoxLayout()
        self.time_distance_line_layout = QtWidgets.QHBoxLayout()
        self.parameter_line_layout = QtWidgets.QHBoxLayout()
        self.color_line_layout = QtWidgets.QHBoxLayout()
        self.button_line_layout = QtWidgets.QHBoxLayout()
        self.layout.addLayout(self.group_line_layout)
        self.layout.addLayout(self.action_line_layout)
        self.layout.addLayout(self.start_cmd_line_layout)
        self.layout.addLayout(self.stop_cmd_line_layout)
        self.layout.addLayout(self.time_distance_line_layout)
        self.layout.addLayout(self.parameter_line_layout)
        self.layout.addLayout(self.color_line_layout)
        self.layout.addLayout(self.button_line_layout)
        self.layout.addStretch(1)
        self.setLayout(self.layout)

    def init_widgets(self) -> None:
        """Initiate all main widgets in main window

        Returns:
            None
        """
        self.group_label = QtWidgets.QLabel("Chose Group")
        self.group_combo_box = QtWidgets.QComboBox()
        self.group_combo_box.setSizePolicy(
            Qt.QSizePolicy.Expanding, Qt.QSizePolicy.Minimum)
        self.group_line_layout.addWidget(self.group_label)
        self.group_line_layout.addWidget(self.group_combo_box)
        self.action_label = QtWidgets.QLabel("Name Action")
        self.action_name_line = QtWidgets.QLineEdit()
        self.action_line_layout.addWidget(self.action_label)
        self.action_line_layout.addWidget(self.action_name_line)
        self.start_label = QtWidgets.QLabel("Start SCPI")
        self.start_line = QtWidgets.QLineEdit()
        self.start_cmd_line_layout.addWidget(self.start_label)
        self.start_cmd_line_layout.addWidget(self.start_line)
        self.stop_label = QtWidgets.QLabel("Stop SCPI")
        self.stop_line = QtWidgets.QLineEdit()
        self.stop_cmd_line_layout.addWidget(self.stop_label)
        self.stop_cmd_line_layout.addWidget(self.stop_line)
        self.time_distance_label = QtWidgets.QLabel("Time Distance")
        self.time_distance_line = QtWidgets.QLineEdit()
        self.time_distance_line_layout.addWidget(self.time_distance_label)
        self.time_distance_line_layout.addWidget(self.time_distance_line)
        self.parameter_label = QtWidgets.QLabel("Parameter")
        self.parameter_line = QtWidgets.QLineEdit()
        self.parameter_line_layout.addWidget(self.parameter_label)
        self.parameter_line_layout.addWidget(self.parameter_line)
        self.color_label = QtWidgets.QLabel("color")
        self.color_button = colorQPushButton("Set")
        self.color_button.setSizePolicy(
            Qt.QSizePolicy.Expanding, Qt.QSizePolicy.Minimum)
        self.color_line_layout.addWidget(self.color_label)
        self.color_line_layout.addWidget(self.color_button)
        self.confirm_button = QtWidgets.QPushButton("Add")
        self.cancel_button = QtWidgets.QPushButton("Cancel")
        self.button_line_layout.addWidget(self.confirm_button)
        self.button_line_layout.addWidget(self.cancel_button)
        self.status_bar = QtWidgets.QStatusBar()
        self.layout.addWidget(self.status_bar)

    def connections(self) -> None:
        """Connects all used slots and signals

        Returns:
            None
        """
        self.group_combo_box.activated.connect(self.add_group)

        self.cancel_button.clicked.connect(self.cancel)
        self.confirm_button.clicked.connect(self.set_action_data)

    def fill_group_combo_box(self) -> None:
        """After loading widgets GroupComboBox is filled with existing group names
        """
        self.group_combo_box.addItem("...", "...")
        self.group_combo_box.addItem("New...", "...")
        if self.parent.groups:
            for group_name, value in self.parent.groups.items():
                self.group_combo_box.addItem(f"{group_name}", value)

    def add_group(self) -> None:
        """Prepares space for group and occupy that name as long as editor is open.
        Unused names will be freed after dialog execution.
        """
        if self.group_combo_box.currentText() != "New...":
            return
        add_group_dialog = GroupWizzard(self, self.parent)
        add_group_dialog.exec()
        if self.group_name != "" and self.group_name is not None:
            self.group_combo_box.addItem(self.group_name, "...")
            self.group_combo_box.setCurrentText(self.group_name)

    def set_action_data(self) -> None:
        """Reads action attributes and data from text fields and assign them with
        uniqe ID for every action. Next data is emmited in signal.
        """
        if self.action_name_line.text() == "" or self.start_line.text() == "":
            self.status_bar.showMessage("Action needs name and start cmd!")
            return
        self.group_name = self.group_combo_box.currentText()
        self.action_name = self.action_name_line.text()
        self.start = self.start_line.text()
        self.stop = self.stop_line.text()
        self.time_distance = self.time_distance_line.text()
        self.parameter = self.parameter_line.text()
        self.color = self.color_button.color()
        uniqe_name = self.group_name + self.action_name

        hashed_id = md5(uniqe_name.encode("utf-8"))
        unqid = "id" + str(int(hashed_id.hexdigest(), 16))
        if unqid in self.parent.actions:
            self.status_bar.showMessage(
                "Action (in that group) exist. Select from list or choose different name"
            )
            return
        self.action_dict_sig.emit(
            {
                unqid: [
                    self.action_name,
                    self.start,
                    self.stop,
                    self.time_distance,
                    self.parameter,
                    self.color,
                    self.group_name,
                ]
            }
        )

    def cancel(self) -> None:
        """After clicking close button dialog is closes.
        """
        self.close()


class ActionEdit(ActionWizzard):
    """ActionEdit class. Opens ActionWizzard dialog with fields filled with chosen action
    and updates data if any change in action (fields) occures.

    Args:
        parent (QWidget): parent widget of dialog
        action (Action): action to be eddited
    """

    def __init__(self, parent: QtWidgets.QWidget, action: "Action") -> None:
        super().__init__(parent)
        self.action = action
        self.unqid = None
        self.hash_id = None
        self.group_combo_box.setCurrentText(self.action.group.name)
        self.group_combo_box.setEditable(False)
        self.action_name_line.setText(self.action.name)
        self.start_line.setText(self.action.start_cmd)
        self.stop_line.setText(self.action.stop_cmd)
        self.time_distance_line.setText(str(self.action.time_distance))
        self.parameter_line.setText(self.action.parameter)
        self.color_button.set_color(self.action.color)
        self.confirm_button.setText("Save")

    def connections(self) -> None:
        """Connects all used slots and signals

        Returns:
            None
        """

        self.cancel_button.clicked.connect(self.cancel)
        self.confirm_button.clicked.connect(self.set_action_data)

    def set_action_data(self):
        """Reads action attributes and data from text fields and assign them with
        uniqe ID for every action. Next data is emmited in signal.
        """
        self.hash_id = self.action.hashed_id
        self.action.name = self.action_name_line.text()
        self.action.start_cmd = self.start_line.text()
        self.action.stop_cmd = self.stop_line.text()
        self.action.time_distance = int(self.time_distance_line.text())
        self.action.parameter = self.parameter_line.text()
        self.action.color = self.color_button.color()
        uniqe_name = self.action.group.name + self.action.name

        grup = Group("")
        act = Action( "asdasda", "asdasd")

        self.act.name = self.action.name



        hashed_id = md5(uniqe_name.encode("utf-8"))
        unqid = "id" + str(int(hashed_id.hexdigest(), 16))
        if unqid in self.parent.actions and self.hash_id != unqid:
            self.status_bar.showMessage(
                "Action (in that group) exist. Select from list or choose different name"
            )
        self.unqid = unqid
        self.close()


class GroupWizzard(QtWidgets.QDialog):
    """GroupWizzard class. Dialog opens when user choses to create new group for actions.

    Args:
        parent (QWidget): parent widget of dialog
        tree (QTreeView): tree with defined actions and groups
    """

    def __init__(self, parent: QtWidgets.QWidget, tree: "QTreeView") -> None:
        super().__init__(parent)
        self.parent = parent
        self.tree = tree
        self.setWindowTitle("Add Group Wizzard")
        self.init_layout()
        self.init_widgets()
        self.connections()
        self.resize(300, 50)

    def init_layout(self) -> None:
        """Initiate all layout for dialog

        Returns:
            None
        """
        self.layout = QtWidgets.QVBoxLayout()
        self.group_line_layout = QtWidgets.QHBoxLayout()
        self.button_line_layout = QtWidgets.QHBoxLayout()
        self.layout.addLayout(self.group_line_layout)
        self.layout.addLayout(self.button_line_layout)
        self.setLayout(self.layout)

    def init_widgets(self) -> None:
        """Initiate all main widgets in main window

        Returns:
            None
        """
        self.group_label = QtWidgets.QLabel("Chose Group")
        self.group_name_line = QtWidgets.QLineEdit()
        self.group_line_layout.addWidget(self.group_label)
        self.group_line_layout.addWidget(self.group_name_line)
        self.confirm_button = QtWidgets.QPushButton("Add")
        self.cancel_button = QtWidgets.QPushButton("Cancel")
        self.button_line_layout.addWidget(self.confirm_button)
        self.button_line_layout.addWidget(self.cancel_button)
        self.status_bar = QtWidgets.QStatusBar()
        self.layout.addWidget(self.status_bar)

    def connections(self) -> None:
        """Connects all used slots and signals

        Returns:
            None
        """
        self.confirm_button.clicked.connect(self.set_name)
        self.cancel_button.clicked.connect(self.cancel)

    def set_name(self) -> None:
        """Sets group name entered in text field
        """
        name = self.group_name_line.text()
        if name in self.tree.groups or name in self.parent.temp_names:
            self.status_bar.showMessage(
                "Group exist. Select from list or choose different name.")
        elif name == "":
            self.status_bar.showMessage(
                "Group has no name. Select from list or name it.")
        else:
            self.parent.group_name = name
            self.parent.temp_names.append(name)
            self.close()

    def cancel(self) -> None:
        """After clicking close button dialog closes.
        """
        self.close()


class SetTimeWizzard(QtWidgets.QDialog):
    """SetTimeWizzard dialog. After doubleclicking on actor or creating it dialog with time settings appears

    Args:
        actor (Actor): clicked actor
    """

    artist_removed = QtCore.pyqtSignal(bool)
    artist_resized = QtCore.pyqtSignal(list)

    def __init__(self, actor: "Actor") -> None:
        super().__init__()
        self.actor = actor
        self.init_layout()
        self.init_widgets()
        self.connections()
        self.read_values()
        self.closed = False
        self.setWindowTitle(f"Set time for: {self.actor.parent.name}")

    def init_layout(self) -> None:
        """Initiate all layout for dialog

        Returns:
            None
        """
        self.layout = QtWidgets.QVBoxLayout()
        self.start_layout = QtWidgets.QHBoxLayout()
        self.stop_layout = QtWidgets.QHBoxLayout()
        self.time_distance_layout = QtWidgets.QHBoxLayout()
        self.button_line_layout = QtWidgets.QHBoxLayout()
        self.layout.addLayout(self.start_layout)
        self.layout.addLayout(self.stop_layout)
        self.layout.addLayout(self.time_distance_layout)
        self.layout.addLayout(self.button_line_layout)
        self.setLayout(self.layout)

    def init_widgets(self) -> None:
        """Initiate all main widgets in main window

        Returns:
            None
        """
        self.start_label = QtWidgets.QLabel("Start time")
        self.start_line = QtWidgets.QLineEdit()
        self.start_layout.addWidget(self.start_label)
        self.start_layout.addWidget(self.start_line)
        self.stop_label = QtWidgets.QLabel("Stop time")
        self.stop_line = QtWidgets.QLineEdit()
        self.stop_layout.addWidget(self.stop_label)
        self.stop_layout.addWidget(self.stop_line)
        self.time_distance_label = QtWidgets.QLabel("Time Distance")
        self.time_distance_line = QtWidgets.QLineEdit()
        self.time_distance_layout.addWidget(self.time_distance_label)
        self.time_distance_layout.addWidget(self.time_distance_line)
        self.start_line.setValidator(QtGui.QIntValidator())
        self.stop_line.setValidator(QtGui.QIntValidator())
        self.time_distance_line.setValidator(QtGui.QIntValidator())
        self.confirm_button = QtWidgets.QPushButton("Ok")
        self.cancel_button = QtWidgets.QPushButton("Cancel")
        self.button_line_layout.addWidget(self.confirm_button)
        self.button_line_layout.addWidget(self.cancel_button)
        self.status_bar = QtWidgets.QStatusBar()
        self.layout.addWidget(self.status_bar)
        if self.actor.infinit:
            self.stop_label.setVisible(False)
            self.stop_line.setVisible(False)
            self.time_distance_line.setVisible(False)
            self.time_distance_label.setVisible(False)

    def connections(self) -> None:
        """Connects all used slots and signals

        Returns:
            None
        """
        self.confirm_button.clicked.connect(self.set_time)
        self.cancel_button.clicked.connect(self.cancel)
        self.stop_line.textEdited.connect(self.set_time_distance)
        self.start_line.textEdited.connect(self.set_time_distance)
        self.time_distance_line.textEdited.connect(self.set_stop_time)

    def read_values(self) -> None:
        """Reads start and stop positions of actor to initially fill text fields
        """
        self.status_bar.showMessage(
            "alo?"
        )
        self.start_line.setText(str(self.actor.start_pos))
        self.stop_line.setText(str(self.actor.stop_pos))
        self.time_distance_line.setText(
            str(self.actor.stop_pos - self.actor.start_pos))

    def cancel(self) -> None:
        """Closes dialog
        """
        self.closed = True
        self.close()

    def set_time_distance(self, time: str) -> None:
        """Calculate and sets absolute difference between start and stop
        time when not in edition state.

        Args:
            time (str): slot for text from start and stop fields signals
        """
        if self.stop_line.text() == "" or self.start_line.text() == "":
            return
        time_distance = abs(int(self.stop_line.text()) -
                            int(self.start_line.text()))
        self.time_distance_line.setText(str(time_distance))

    def set_stop_time(self, time: str) -> None:
        """Calculate and sets stop time based on start and time_distance text fields
        when not in edition state.

        Args:
            time (str): slot for text from start and stop fields signals. Exeption when empty.
        """

        if time == "" or self.start_line.text() == "":
            return
        self.start_line.text()
        stop_time = abs(int(self.start_line.text()) +
                        int(self.time_distance_line.text()))
        self.stop_line.setText(str(stop_time))

    def set_time(self):
        """Reads all values from text fields. Update time for actor and handles infinity actors.
        Handles errors in time flow.
        """
        if self.stop_line.text() == "":
            self.stop_line.setText("0")
        if self.start_line.text() == "":
            self.start_line.setText("0")

        if self.actor.infinit:
            for sibling in self.actor.group.get_group_actors():
                if sibling == self.actor:
                    continue
                x1, x2 = sibling.x_position if not sibling.infinit else (sibling.start_pos, sibling.start_pos)
                if x1 <= int(self.start_line.text()) < x2 and self.start_line.text() != "0":
                    self.status_bar.showMessage(
                        "Action exists in that position")
                    return
            if self.start_line.text() == "0":
                self.actor.calculate_x_position()
                if self.actor.start_pos in [sibling.start_pos for sibling in self.actor.group.get_group_actors() if sibling.infinit and sibling != self.actor]:
                    self.status_bar.showMessage(
                        "Action exists in that position")
                    return
            else:
                self.actor.start_pos = int(self.start_line.text())

            self.actor.infinity_actor_handler()

            self.close()
            return

        if self.start_line.text() == "0" and self.stop_line.text() == "0":
            self.actor.calculate_x_position()
            self.actor.infinity_actor_handler()
            self.close()

        elif self.stop_line.text() == "0":
            self.actor.x_position = (
                int(self.start_line.text()),
                int(self.start_line.text()) + self.actor.parent.time_distance,
            )
            self.actor.infinity_actor_handler()
        else:
            self.actor.x_position = (
                int(self.start_line.text()), int(self.stop_line.text()))
            self.actor.infinity_actor_handler()

        if int(self.start_line.text()) >= int(self.stop_line.text()) and self.stop_line.text() != "0":
            self.status_bar.showMessage("Start >= Stop!")
            return

        for sibling in self.actor.group.get_group_actors():
            if sibling == self.actor:
                continue
            x1, x2 = sibling.x_position
            if x1 <= int(self.start_line.text()) < x2:
                self.status_bar.showMessage(
                    "Action exists in starting position")
                return

            if x1 < int(self.stop_line.text()) <= x2 and self.stop_line.text() != "0":
                self.status_bar.showMessage("Action exists in stop position")
                return

            if int(self.start_line.text()) + self.actor.parent.time_distance in range(x1, x2):
                self.actor.stop_pos = x1

        self.close()


class CloseEventDialog(QtWidgets.QDialog):
    def __init__(self):
        super().__init__()
        self.init_layout()
        self.init_widets()
        self.connections()
        self.setWindowTitle(f"You have unsaved changes, do you want to exit?")
        self.save = True

    def init_layout(self) -> None:
        """Initiate all layout for dialog

        Returns:
            None
        """
        self.layout = QtWidgets.QVBoxLayout()
        self.text_layout = QtWidgets.QHBoxLayout()
        self.button_line_layout = QtWidgets.QHBoxLayout()
        self.layout.addLayout(self.text_layout)
        self.layout.addLayout(self.button_line_layout)
        self.setLayout(self.layout)

    def init_widets(self):
        self.text = QtWidgets.QLabel(
            "You have unsaved changes. Proceed to quit the program?")
        self.save_button = QtWidgets.QPushButton("Exit")
        self.dont_save_button = QtWidgets.QPushButton("Cancel")
        # self.cancel_button = QtWidgets.QPushButton("")

        self.text_layout.addWidget(self.text)
        self.button_line_layout.addWidget(self.save_button)
        self.button_line_layout.addWidget(self.dont_save_button)

    def connections(self) -> None:
        """Connects all used slots and signals

        Returns:
            None
        """
        self.save_button.clicked.connect(self.save_button_clicked)
        self.dont_save_button.clicked.connect(self.dont_save_button_clicked)

    def save_button_clicked(self):
        """When clicked prevents program from closing
        """

        self.save = False
        self.close()

    def dont_save_button_clicked(self):
        """When clicked closes program without saving
        """
        self.save = True
        self.close()


class SetTimeline(QtWidgets.QDialog):
    """SetTimeline dialog. Dialog appears when creating timeline actor.

    Args:
        actor (Actor): Actor for timeline.
    """

    def __init__(self, actor):
        super().__init__()
        self.actor = actor
        self.init_layout()
        self.init_widgets()
        self.connections()
        self.read_values()
        self.closed = False
        self.setWindowTitle(f"Set time for: {self.actor.parent.name}")

    def init_layout(self) -> None:
        """Initiate all layout for dialog

        Returns:
            None
        """
        self.layout = QtWidgets.QVBoxLayout()
        self.name_layout = QtWidgets.QHBoxLayout()
        self.start_layout = QtWidgets.QHBoxLayout()
        self.stop_layout = QtWidgets.QHBoxLayout()
        self.time_distance_layout = QtWidgets.QHBoxLayout()
        self.color_line_layout = QtWidgets.QHBoxLayout()
        self.button_line_layout = QtWidgets.QHBoxLayout()
        self.layout.addLayout(self.name_layout)
        self.layout.addLayout(self.start_layout)
        self.layout.addLayout(self.stop_layout)
        self.layout.addLayout(self.time_distance_layout)
        self.layout.addLayout(self.color_line_layout)
        self.layout.addLayout(self.button_line_layout)
        self.setLayout(self.layout)

    def init_widgets(self) -> None:
        """Initiate all main widgets in main window

        Returns:
            None
        """
        self.name_label = QtWidgets.QLabel("Name")
        self.name_line = QtWidgets.QLineEdit()
        self.name_layout.addWidget(self.name_label)
        self.name_layout.addWidget(self.name_line)
        self.start_label = QtWidgets.QLabel("Start time")
        self.start_line = QtWidgets.QLineEdit()
        self.start_layout.addWidget(self.start_label)
        self.start_layout.addWidget(self.start_line)
        self.stop_label = QtWidgets.QLabel("Stop time")
        self.stop_line = QtWidgets.QLineEdit()
        self.stop_layout.addWidget(self.stop_label)
        self.stop_layout.addWidget(self.stop_line)
        self.time_distance_label = QtWidgets.QLabel("Time Distance")
        self.time_distance_line = QtWidgets.QLineEdit()
        self.time_distance_layout.addWidget(self.time_distance_label)
        self.time_distance_layout.addWidget(self.time_distance_line)
        self.start_line.setValidator(QtGui.QIntValidator())
        self.stop_line.setValidator(QtGui.QIntValidator())
        self.time_distance_line.setValidator(QtGui.QIntValidator())
        self.color_label = QtWidgets.QLabel("Color")
        self.color_button = colorQPushButton("Set")
        self.color_button.setSizePolicy(
            Qt.QSizePolicy.Expanding, Qt.QSizePolicy.Minimum)
        self.color_line_layout.addWidget(self.color_label)
        self.color_line_layout.addWidget(self.color_button)
        self.confirm_button = QtWidgets.QPushButton("Ok")
        self.cancel_button = QtWidgets.QPushButton("Cancel")
        self.button_line_layout.addWidget(self.confirm_button)
        self.button_line_layout.addWidget(self.cancel_button)
        self.status_bar = QtWidgets.QStatusBar()
        self.layout.addWidget(self.status_bar)

    def connections(self) -> None:
        """Connects all used slots and signals

        Returns:
            None
        """
        self.confirm_button.clicked.connect(self.set_time)
        self.cancel_button.clicked.connect(self.cancel)
        self.stop_line.textEdited.connect(self.set_time_distance)
        self.start_line.textEdited.connect(self.set_time_distance)
        self.time_distance_line.textEdited.connect(self.set_stop_time)

    def read_values(self) -> None:
        """Reads start and stop positions, name, color of actor to initially fill text fields
        """
        self.name_line.setText(str(self.actor.name))
        self.start_line.setText(str(self.actor.start_pos))
        self.stop_line.setText(str(self.actor.stop_pos))
        self.time_distance_line.setText(
            str(self.actor.stop_pos - self.actor.start_pos))
        self.color_button.set_color(self.actor.color)

    def cancel(self) -> None:
        """After clicking close button dialog closes.
        """
        self.closed = True
        self.close()

    def set_time(self) -> None:
        """Sets time and parameters of timeline actor
        """
        if int(self.start_line.text()) >= int(self.stop_line.text()):
            self.status_bar.showMessage(
                "Start > Stop!")
            return
        self.actor.x_position = (
            int(self.start_line.text()),
            int(self.stop_line.text())
        )
        self.actor.color = self.color_button.color()
        self.actor.name = self.name_line.text()
        if self.actor.annotate is not None:
            self.actor.annotate.set_text(self.name_line.text())
        self.close()

    def set_time_distance(self, time: str) -> None:
        """Calculate and sets absolute difference between start and stop
        time when not in edition state.

        Args:
            time (str): slot for text from start and stop fields signals
        """
        if self.stop_line.text() == "" or self.start_line.text() == "":
            return
        time_distance = abs(int(self.stop_line.text()) -
                            int(self.start_line.text()))
        self.time_distance_line.setText(str(time_distance))

    def set_stop_time(self, time: str) -> None:
        """Calculate and sets stop time based on start and time_distance text fields
        when not in edition state.

        Args:
            time (str): slot for text from start and stop fields signals. Exeption when empty.
        """
        if time == "" or self.start_line.text() == "":
            return
        self.start_line.text()
        stop_time = abs(int(self.start_line.text()) +
                        int(self.time_distance_line.text()))
        self.stop_line.setText(str(stop_time))


class colorQPushButton(QtWidgets.QPushButton):
    def __init__(self, name):
        super().__init__()
        self.rgba = "#000000"
        self.setStyleSheet("QPushButton {background-color:%s;}" % self.rgba)

    def mousePressEvent(self, event):
        self.q_color = QtWidgets.QColorDialog.getColor()
        self.rgba = self.q_color.name()
        self.setStyleSheet("QPushButton {background-color:%s;}" % self.rgba)

    def color(self):
        return self.rgba

    def set_color(self, color):
        self.rgba = color
        self.setStyleSheet("QPushButton {background-color:%s;}" % color)
