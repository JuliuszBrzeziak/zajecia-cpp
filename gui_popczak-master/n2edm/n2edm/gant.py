import weakref
from collections import OrderedDict
from copy import copy
from typing import Any
from weakref import finalize

import libconf
import matplotlib as mpl
import matplotlib.pyplot as plt
from matplotlib import pyplot as plt
import matplotlib.patheffects as mpe
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.backends.backend_qt5agg import NavigationToolbar2QT as NavigationToolbar
from numpy.core.numeric import Infinity
from PyQt5 import Qt, QtCore, QtGui, QtWidgets, uic

from .dialogs import SetTimeline, SetTimeWizzard
from .utils import Action, Actor, Command, Group


class n2EDMGant(QtWidgets.QWidget):
    """n2EDMGant class (Schedule widget). Widget is used with utils.py and tree.py classes
    to create visual representation of n2EDM mesurement schedule.

    Args:
        parent (QWidget): parent widget

    Attributes:
        self.actors (list): list of schedule lines (called actors)
        self.artist (object): last clicked matplotlib artist reference
        self.requested_action (str): unique id for action request reference
        self.timeline_action (Action): Independent action for timeline actors
        self.figure (object): matplotlib figure object reference
        self.ax (object): matplotlib axes object reference
        self.canvas (object): matplotlib canvas object reference
        self.toolbar (object): matplotlib toolbar object reference

    Returns:
        None
    """
    save_schedule_sig = QtCore.pyqtSignal(list)
    request_action_sig = QtCore.pyqtSignal(str)
    undo_redo = QtCore.pyqtSignal(object)
    schedule_changed = QtCore.pyqtSignal()

    def __init__(self, parent: Any) -> None:
        super().__init__(parent=parent)
        self.actors = []
        self.artist = None
        self.requested_action = None
        self.figure = None
        self.ax = None
        self.canvas = None
        self.toolbar = None
        self.prepare_wiget()
        self.prepare_scene()
        self.add_timeline_line()
        self.timeline_action = Action(
            "Timeline", None, group=Group("Timeline"))
        self.canvas.mpl_connect("pick_event", self.lmb_click)
        self.canvas.mpl_connect("button_press_event", self.lmb_double_click)
        self.canvas.mpl_connect("motion_notify_event", self.on_hover)

    def prepare_wiget(self) -> None:
        """Create matplotlib objects to be reffered to and add them to layout
        """
        main_layout = QtWidgets.QVBoxLayout(self)

        self.figure, self.ax = plt.subplots()

        self.canvas = FigureCanvas(self.figure)
        main_layout.addWidget(self.canvas)

        self.toolbar = NavigationToolbar(self.canvas, self)
        main_layout.addWidget(self.toolbar)

    def prepare_scene(self) -> None:
        """Prepares matplotlib axes to reflect look of schedule
        """
        Y_MAX = 100
        bbox = self.ax.get_window_extent().transformed(
            self.figure.dpi_scale_trans.inverted())
        WIDTH = 2 * bbox.height

        mpl.rcParams["lines.solid_capstyle"] = "butt"
        self.ax.grid(True)
        self.ax.set_xbound(0)
        self.ax.set_ylim(25, -1)
        self.ax.set_xlim(-1, 200)
        plt.yticks(range(-2, 25))
        self.ax.set_yticklabels(["", "Timeline"])
        self.update_tigth_layout()
        self.canvas.draw()

    def add_timeline_line(self):
        """Add green transtarent line indicating timeline space
        """
        self.ax.plot([0, 999999], [-1, -1], alpha=0.3,
                     color="green", lw=10, zorder=0)

    @QtCore.pyqtSlot(object)
    def resize_event(self, resize: Any) -> None:
        """Slot for resizeEvent signal. Scales schedule to fit window.

        Args:
            resize (Any): resizeEvent signal
        """
        self.update_tigth_layout()

    @QtCore.pyqtSlot(object)
    def draw_actor_from_action(self, action: Action) -> None:
        """Creates actor in schedule based on action argument

        Args:
            action (Action): action from tree to be actor parent
        """
        action._clear_reference()
        command = SceneChange(self)
        bbox = self.ax.get_window_extent().transformed(
            self.figure.dpi_scale_trans.inverted())
        WIDTH = 2 * bbox.height
        outline = mpe.withStroke(
            edgecolor='black', linewidth=1.1, capstyle="projecting")

        actor = weakref.proxy(Actor(action))
        actor.y_pos = self.find_y_pos(actor)
        set_time_dialog = SetTimeWizzard(actor)
        set_time_dialog.exec()

        if set_time_dialog.closed:
            actor.remove()
            return
        line2d, = self.ax.plot(
            [actor.start_pos, actor.stop_pos],
            [actor.y_pos, actor.y_pos],
            color=actor.color,
            lw=WIDTH,
            picker=5,
            ms=0,
        )
        line2d.set_path_effects([outline])

        actor.annotate = self.ax.annotate("",
                                          xy=(
                                              actor.start_pos, actor.y_pos),
                                          xytext=(actor.start_pos+5,
                                                  actor.y_pos+2),
                                          bbox=dict(
                                              boxstyle="round", fc="w"),
                                          size=WIDTH)
        actor.annotate.set_text(actor.name)
        actor.annotate.get_bbox_patch().set_alpha(0.7)

        actor.text = self.ax.text(actor.start_pos, actor.y_pos, actor.name,
                                  verticalalignment='center',
                                  fontsize=WIDTH/1.5)

        self.actors.append(actor)
        actor.add_line(line2d)
        setattr(line2d, "parent_actor", actor)

        if actor.text.get_window_extent().width > actor.line2d.get_window_extent(None).width:
            actor.text.set_alpha(0)

        self.set_labels()
        self.canvas.draw()
        command.finalize(self)
        self.schedule_changed.emit()
        self.undo_redo.emit(command)

    def draw_actor_from_dict(self, list_actor: dict, action: Action) -> None:
        """After loading schedule saved file recreates actors and make reference to 
        action if action exist.

        Args:
            list_actor (dict): actor in form of dict (all data to create Actor object)
            action (Action): action for actor to be referenced to
        """
        bbox = self.ax.get_window_extent().transformed(
            self.figure.dpi_scale_trans.inverted())
        WIDTH = 2 * bbox.height
        outline = mpe.PathPatchEffect(edgecolor='black', linewidth=1.1)

        actor = weakref.proxy(Actor(action))
        actor.color = list_actor["color"]
        actor.x_position = (
            int(list_actor["start_pos"]), int(list_actor["stop_pos"]))
        actor.y_pos = int(list_actor["y_pos"])
        line2d, = self.ax.plot(
            [actor.start_pos, actor.stop_pos],
            [actor.y_pos, actor.y_pos],
            color=list_actor["color"],
            lw=WIDTH,
            picker=5,
            ms=0,
            path_effects=[outline],

        )
        actor.annotate = self.ax.annotate("",
                                          xy=(
                                              actor.start_pos, actor.y_pos),
                                          xytext=(actor.start_pos+5,
                                                  actor.y_pos+1),
                                          bbox=dict(
                                              boxstyle="round", fc="w"),
                                          size=WIDTH)
        actor.annotate.set_text(actor.name)
        actor.annotate.get_bbox_patch().set_alpha(0.7)
        actor.annotate.set_visible(False)
        actor.text = self.ax.text(actor.start_pos, actor.y_pos, actor.name,
                                  verticalalignment='center',
                                  fontsize=WIDTH/1.5)

        if actor.group.name == "Timeline":
            actor.vline = self.ax.axvline(
                actor.stop_pos, color=actor.color, label="TVLine", zorder=99)

        actor.add_line(line2d)
        setattr(line2d, "parent_actor", actor)
        if actor.text.get_window_extent().width > actor.line2d.get_window_extent(None).width:
            actor.text.set_alpha(0)
        self.actors.append(actor)
        self.canvas.draw()
        self.schedule_changed.emit()

    def add_timeline_element(self):
        """Creates timeline element for schedule. Works similar to add_actor_from_action
        """
        command = SceneChange(self)
        bbox = self.ax.get_window_extent().transformed(
            self.figure.dpi_scale_trans.inverted())
        WIDTH = 2 * bbox.height
        outline = mpe.PathPatchEffect(edgecolor='black', linewidth=1.1)

        actor = Actor(self.timeline_action)
        actor.y_pos = -1
        add_timeline_element_dialog = SetTimeline(actor)
        add_timeline_element_dialog.exec()
        if add_timeline_element_dialog.closed:
            return
        line2d, = self.ax.plot(
            [actor.start_pos, actor.stop_pos],
            [actor.y_pos, actor.y_pos],
            color=actor.color,
            lw=WIDTH,
            picker=5,
            ms=0,
            path_effects=[outline],

        )

        actor.annotate = self.ax.annotate("",
                                          xy=(
                                              actor.start_pos, actor.y_pos),
                                          xytext=(actor.start_pos+5,
                                                  actor.y_pos+2),
                                          bbox=dict(
                                              boxstyle="round", fc="w"),
                                          size=WIDTH)
        actor.annotate.set_text(actor.name)
        actor.annotate.get_bbox_patch().set_alpha(0.7)

        actor.text = self.ax.text(actor.start_pos, actor.y_pos, actor.name,
                                  verticalalignment='center',
                                  fontsize=WIDTH/1.5)

        actor.add_line(line2d)
        if actor.text.get_window_extent().width > actor.line2d.get_window_extent(None).width:
            actor.text.set_alpha(0)

        actor.vline = self.ax.axvline(
            actor.stop_pos, color=actor.color, label="TVLine", zorder=99)
        self.actors.append(actor)
        setattr(line2d, "parent_actor", actor)
        self.update_tigth_layout()
        self.canvas.draw()
        command.finalize(self)
        self.schedule_changed.emit()
        self.undo_redo.emit(command)

    def update_tigth_layout(self) -> int:
        """Updates all width, spaceing, colors, sizes etc. of axes actors

        Returns:
            int: width of line
        """
        bbox = self.ax.get_window_extent().transformed(
            self.figure.dpi_scale_trans.inverted())
        WIDTH = 2 * bbox.height
        outline = mpe.withStroke(linewidth=WIDTH+3, foreground='black')
        for actor in self.actors:

            if actor.text.get_window_extent().width > actor.line2d.get_window_extent(None).width:
                actor.text.set_alpha(0)

            else:
                actor.text.set_alpha(1)

            if actor.line2d.get_label() == "TVLine":
                continue
            actor.line2d.set_linewidth(WIDTH)
            actor.annotate.set_size(WIDTH/1.5)
            if actor.line2d.get_label() == "TTLine":
                continue
            actor.line2d.set_path_effects([outline])
            actor.text.set_fontsize(WIDTH/1.5)

        self.figure.tight_layout()

        return WIDTH

    def update_schedule_y_pos(self) -> None:
        """Controll and update Y-axis placment and distribution of actors
        """
        pos_list = [
            actor.y_pos for actor in self.actors if actor.group.name != "Timeline"]
        pos_list = list(set(pos_list))
        if not pos_list:
            return
        if not self.diff(list(range(max(pos_list) + 1)), pos_list):
            return
        update_pos, = self.diff(list(range(max(pos_list) + 1)), pos_list)
        for actor in self.actors:
            if actor.y_pos > update_pos:
                actor.y_pos = actor.y_pos - 1
                actor.update_line()
        self.schedule_changed.emit()

    def set_labels(self) -> None:
        """Controll and update Y-axis labels of groups and lines
        """
        labels = ["", "Timeline"]
        drop_timeline_labels = list(
            OrderedDict.fromkeys(
                [
                    actor.group.name if actor.group.name != "..." else actor.parent.name
                    for actor in self.actors
                ]
            )
        )
        if "Timeline" in drop_timeline_labels:
            drop_timeline_labels.remove("Timeline")
        if drop_timeline_labels != None:
            labels = labels + drop_timeline_labels
        self.ax.set_yticklabels(labels)
        self.update_tigth_layout()
        self.canvas.draw()

    @classmethod
    def diff(cls, first: list, second: list) -> list:
        """Calculate difference between two lists (longer - longer and shorter)

        Args:
            first (list): 1st list of elements
            second (list): 2nd list of elements

        Returns:
            list: difference list
        """
        if len(first) < len(second):
            first, second = second, first
        return [item for item in first if item not in second]

    def find_y_pos(self, actor: Actor) -> None:
        """Looks for position in y-axis for actors (depends on group and free space)

        Args:
            actor (Actor): actor to place in schedule

        Returns:
            None
        """
        if not self.actors:
            return 0
        if (
            actor.group.name not in [
                actor_ex.group.name for actor_ex in self.actors]
            and actor.group.name != "..."
        ):
            y_pos = max([actor.y_pos for actor in self.actors]) + 1
        elif (
            actor.name not in [actor_ex.name for actor_ex in self.actors]
            and actor.group.name == "..."
        ):
            y_pos = max([actor.y_pos for actor in self.actors]) + 1
        elif (
            actor.name in [
                actor_ex.name for actor_ex in self.actors] and actor.group.name == "..."
        ):
            for actor_ex in self.actors:
                if actor.name == actor_ex.name:
                    y_pos = actor_ex.y_pos
        else:
            all_pos = []
            for action in actor.group.children:
                for child in action.children:
                    all_pos.append(child.y_pos)
            y_pos = max(all_pos)
        return y_pos

    def remove_actor(self, actor: Actor) -> None:
        """After clicking with RMB on actor and select Delete this functtion removes
        actor from schedule.

        Args:
            actor (Actor): actor to remove.
        """
        self.actors.remove(actor)
        actor.remove()
        self.schedule_changed.emit()
        for actor in self.actors:
            actor.infinity_actor_handler()
        self.artist = None
        self.update_schedule_y_pos()
        self.set_labels()
        self.canvas.draw()

    @QtCore.pyqtSlot(list)
    def remove_action_schedule(self, actors: list) -> None:
        """Removes actors given in list. Used when removing action.

        Args:
            actors (list(Actor)): List of actors
        """
        for actor in actors:
            actor.remove()
            if actor in self.actors:
                self.actors.remove(actor)
        self.update_schedule_y_pos()
        self.set_labels()
        self.canvas.draw()

    def remove_line(self, group):
        """TBD

        Args:
            group (Group): TBD
        """
        pass

    def save_schedule(self) -> None:
        """Emits signal to save schedule.
        """
        self.save_schedule_sig.emit(self.actors)

    @QtCore.pyqtSlot(object)
    def load_schedule(self, actors: dict) -> None:
        """Loads schedule from dict with actors

        Args:
            actors (dict): dictionary with actors in dict format
        """
        for actor in self.actors:
            actor.remove()
        self.actors = []
        for actor in actors.values():
            self.request_action(actor["hash"])
            if actor["hash"] == self.timeline_action.hashed_id:
                self.requested_action = self.timeline_action
            elif not self.requested_action:
                return
            self.draw_actor_from_dict(actor, self.requested_action)

        self.set_labels()

    def request_action(self, hash_id: str) -> None:
        """Calls tree of actions to get action if exist

        Args:
            hash_id (str): uniqe id of action
        """
        self.request_action_sig.emit(hash_id)

    @QtCore.pyqtSlot(object)
    def recieve_requested_action(self, action: Action) -> None:
        """Requested action reciever

        Args:
            action (Action): Requested action
        """
        self.requested_action = action

    def lmb_click(self, event: Any) -> None:
        """Gets clicked actor

        Args:
            event (MouseEvent): Mouse click event
        """
        self.artist = event.artist

    def lmb_double_click(self, event: Any) -> None:
        """Opens time wizzard window after db click on actor

        Args:
            event (event): Mouse db click event
        """
        try:
            if event.dblclick and self.artist != None:
                if self.artist.parent_actor.parent.name == "Timeline":
                    set_time_dialog = SetTimeline(self.artist.parent_actor)
                    set_time_dialog.exec()
                else:
                    set_time_dialog = SetTimeWizzard(self.artist.parent_actor)
                    set_time_dialog.exec()
                self.canvas.draw()
                self.schedule_changed.emit()
                self.artist = None
        except AttributeError as e:
            print("No Event Secelted")

    def copy(self) -> None:
        """Copy used in undo/redo feature
        """
        return copy(self.actors)

    @QtCore.pyqtSlot()
    def update(self):
        """Updates all labels and actors after parent action changed
        """
        self.set_labels()
        self.canvas.draw()

    def contextMenuEvent(self, event: Any) -> None:
        """Context menu for actors

        Args:
            event (event): Mouse rbm click event

        """
        if self.artist == None or not hasattr(self.artist, "parent_actor"):
            return
        self.menu = QtWidgets.QMenu(self)
        del_action = QtWidgets.QAction("Delete...", self)
        del_action.triggered.connect(
            lambda: self.remove_actor(self.artist.parent_actor))
        self.menu.addAction(del_action)
        self.menu.popup(QtGui.QCursor.pos())

    def on_hover(self, event: Any) -> None:
        """Handles hover events and annotations in schedule

        Args:
            event (event): Mouse move event

        """
        if event.inaxes == self.ax:
            for line2d in [actor.line2d for actor in self.actors]:
                cont, ind = line2d.contains(event)
                if cont and hasattr(line2d, "parent_actor"):
                    line2d.parent_actor.annotate.set_x(
                        event.xdata + 5)
                    line2d.parent_actor.annotate.set_y(
                        event.ydata)
                    line2d.parent_actor.annotate.set_visible(True)

                elif hasattr(line2d, "parent_actor"):
                    line2d.parent_actor.annotate.set_visible(False)

        self.canvas.draw()


class SceneChange(Command):
    def __init__(self, parent):
        super().__init__()
        self.parent = parent
        self.schedule_init = parent.copy()

    def finalize(self, parent):
        self.schedule_final = parent.copy()
        self.schedule_diff, = n2EDMGant.diff(
            self.schedule_final, self.schedule_init)

    def undo(self):
        try:
            self.parent.actors.remove(self.schedule_diff)
        except (ValueError, ReferenceError):
            return
        for line in self.parent.ax.get_lines():
            line.remove()
        for actor in self.schedule_init:
            self.parent.ax.add_line(actor.line2d)
        self.parent.set_labels()
        self.schedule_diff.visibility = False

    def redo(self):
        self.parent.actors.append(self.schedule_diff)
        for line in self.parent.ax.get_lines():
            line.remove()
        for actor in self.schedule_final:
            self.parent.ax.add_line(actor.line2d)
        self.parent.set_labels()
        self.schedule_diff.visibility = True
