"""Files operations
"""
from copy import deepcopy
from os.path import pardir
from pathlib import Path

import libconf
from PyQt5 import QtCore, QtWidgets


class FileManager(QtCore.QObject):
    """FileManager class. Class is used to manage loading, saving, changing and checking 
    files used by program.

    Args:
        parent (QWidget): parent widget

    Attributes:
        self.parent (QWidget): parent widget
        self.actions_saved (bool): holds information if actions was saved
        self.schedule_saved (bool): holds information if schedule was saved
    """

    actions_dict_sig = QtCore.pyqtSignal(object)
    schedule_dict_sig = QtCore.pyqtSignal(object)

    def __init__(self, parent):
        super().__init__(parent)
        self.parent = parent
        self.actions_saved = True
        self.schedule_saved = True
        self.llf = None

    @QtCore.pyqtSlot(dict)
    def save_actions(self, actions: dict) -> None:
        """Saves actions with chosen format in selected directory

        Args:
            actions (dict): dictionary with actions to save
        """
        z = {}
        if actions == None:
            # TODO: Popup with information that there is nothing to save!
            return

        for action in actions.values():
            z = self.join_dicts(z, action.to_dict())

        save_menu = QtWidgets.QFileDialog()
        options = save_menu.Options()
        options |= save_menu.DontUseNativeDialog
        name, end = save_menu.getSaveFileName(
            None,
            "Save actions as...",
            "",
            "libconf File (*.actions);;Data File (*.libconf);;All Files (*)",
            "libconf File (*.actions)",
            options=options,
        )
        if name == "":
            return
        end = end.strip(")").split("*")[-1]
        name = name.strip(end)
        with open(f"{name}{end}", "w") as sf:
            libconf.dump(z, sf)

        self.llf = f"{name}{end}"
        self.actions_saved = True

    @QtCore.pyqtSlot()
    def load_actions(self) -> dict:
        """Loads actions to tree from selected compatible file. Emits dict with those actions

        Returns:
            dict: Returns dict with actions
        """
        load_menu = QtWidgets.QFileDialog()
        options = load_menu.Options()
        options |= load_menu.DontUseNativeDialog
        name, _ = load_menu.getOpenFileName(
            None,
            "Load actions from...",
            "",
            "libconf File (*.actions);;Data File (*.libconf);;All Files (*)",
            "libconf File (*.actions)",
            options=options,
        )
        try:
            with open(f"{name}", "r") as lf:
                actions_dict = libconf.load(lf)
        except (FileNotFoundError, ValueError):
            return
        actions_dict = self.decode_dict(actions_dict)
        self.actions_dict_sig.emit(actions_dict)
        self.llf = f"{name}"

    @QtCore.pyqtSlot(list)
    def save_schedule(self, actors: list) -> None:
        """Saves schedule with chosen format in selected directory

        Args:
            actors (list): list with actors to save
        """
        z = {}
        if actors == None:
            # TODO: Popup with information that there is nothing to save!
            return

        for actor in actors:
            z = self.join_dicts(z, actor.to_dict())

        save_menu = QtWidgets.QFileDialog()
        options = save_menu.Options()
        options |= save_menu.DontUseNativeDialog
        name, end = save_menu.getSaveFileName(
            None,
            "Save schedule as...",
            "",
            "libconf File (*.schedule);;Data File (*.libconf);;All Files (*)",
            "libconf File (*.schedule)",
            options=options,
        )
        end = end.strip(")").split("*")[-1]
        # name = name.strip(end)
        with open(f"{name}{end}", "w") as sf:
            libconf.dump(z, sf)

        self.schedule_saved = True

    @QtCore.pyqtSlot()
    def load_schedule(self) -> dict:
        """Loads schedule to tree from selected compatible file. Emits dict with actors

        Returns:
            dict: Returns dict with actors
        """
        load_menu = QtWidgets.QFileDialog()
        options = load_menu.Options()
        options |= load_menu.DontUseNativeDialog
        name, _ = load_menu.getOpenFileName(
            None,
            "Load schedule from...",
            "",
            "libconf File (*.schedule);;Data File (*.libconf);;All Files (*)",
            "libconf File (*.schedule)",
            options=options,
        )
        try:
            with open(f"{name}", "r") as lf:
                actor_dict = libconf.load(lf)
        except (FileNotFoundError, ValueError):
            return

        actor_dict = self.decode_dict(actor_dict)
        self.schedule_dict_sig.emit(actor_dict)

    def join_dicts(self, x: dict, y: dict) -> dict:
        """Joins two dictionaries into one

        Args:
            x (dict): 1st dictionary
            y (dict): 2nd dictionary

        Returns:
            dict: joined dictionary
        """
        z = {}
        overlapping_keys = x.keys() & y.keys()
        for key in overlapping_keys:
            if isinstance(x[key], list):
                z[key] = y[key]
            else:
                z[key] = self.join_dicts(x[key], y[key])
        for key in x.keys() - overlapping_keys:
            z[key] = x[key]
        for key in y.keys() - overlapping_keys:
            z[key] = y[key]

        return z

    def decode_dict(self, attrdict: dict) -> dict:
        """Decodes dictionary with attributes saved with libconf format to be
        redable by python.pardir

        Args:
            attrdict (dict): undecoded dict

        Returns:
            dict: decoded dict
        """
        new_dict = dict(attrdict)
        for key, value in new_dict.items():
            if not isinstance(value, list):
                new_dict[key] = dict(value)
        return new_dict

    @QtCore.pyqtSlot()
    def actions_changed(self) -> None:
        """Listens to changes in program and change self.actions_saved to false if any occures.
        """
        self.actions_saved = False

    @QtCore.pyqtSlot()
    def schedule_changed(self) -> None:
        """Listens to changes in program and change self.schedule_saved to false if any occures.
        """
        self.schedule_saved = False

    def read_config(self) -> dict:
        """Reads config file given with program

        Returns:
            dict: configuration dictionary
        """
        conf_file = Path(__file__).parent / Path("config.cfg")
        if not conf_file.exists():
            with conf_file.open("w", encoding="utf-8") as conf:
                conf.write("Config Version=1.0.0")
            return {"Config Version": "1.0.0"}

        with conf_file.open("r", encoding="utf-8") as conf_str:
            config = {}
            conf = list(conf_str)
            for line in conf:
                key, value = line.split("=")
                config[key] = value
        return config

    def load_last_file(self) -> None:
        """Loads last used actions file in program.
        """
        if "Last Loaded File" not in self.parent.config.keys():
            return
        self.llf = self.parent.config["Last Loaded File"]

        try:
            with open(f"{self.llf}", "r") as lf:
                actions_dict = libconf.load(lf)
        except (FileNotFoundError, ValueError) as e:
            print("File Not Found")
            return

        actions_dict = self.decode_dict(actions_dict)
        self.actions_dict_sig.emit(actions_dict)

    def save_config(self):
        """Saves config to file.
        """
        conf_file = Path(__file__).parent / Path("config.cfg")
        with conf_file.open("w", encoding="utf-8") as conf:
            conf.write("Config Version=1.0.1\n")
            conf.write(f"Last Loaded File={str(self.llf)}")
