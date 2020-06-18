"""Utilities classes for n2EDMGant
"""
from typing import Any
from hashlib import md5


class Group:
    """Base class for group object.

    Attributes:
        self.name (str): Group name
        self.children (list): List of children actions
    """

    def __init__(self, name: str) -> None:
        self.name = name
        self.children = []

    @property
    def children(self) -> list:
        """Returns group children

        Returns:
            list: list of actions
        """
        return self._children

    @children.setter
    def children(self, children: list) -> None:
        """Setter for children

        Args:
            children (list): list of actions
        """
        self._children = children

    def add_child(self, child: object) -> None:
        """Adds actions to children

        Args:
            child (Action): Actions object
        """
        self.children.append(child)

    def remove_child(self, child: object) -> None:
        """Removes actions from children

        Args:
            child (Action): Actions object to remove
        """
        self.children.remove(child)
        del child

    @property
    def name(self) -> str:
        """returns name of group

        Returns:
            str: name
        """
        return self._name

    @name.setter
    def name(self, new_name: str) -> None:
        """Sets group name

        Args:
            new_name (str): new group name
        """
        self._name = new_name

    def get_group_actors(self) -> list:
        """Returns all actors in group

        Returns:
            list: list of all group actors
        """
        all_children = []
        for child in self.children:
            if child.children:
                all_children.extend(child.children)

        return all_children


class Action:
    """Base class for action object.

    Attributes:
        self.infinit (bool): Tells if action has no end
        self.name (str): Name of action
        self.start_cmd (str): command for action start
        self.stop_cmd (str): command for action end
        self.time_distance (str): base length of action
        self.parameter (str): string with all additional parameters
        self.color (str): color in hexadecimal format
        self.group (Group): Group parent of Action
        self.children (list): List of children actors
    """

    def __init__(
        self,
        name: str,
        start_cmd: str,
        stop_cmd: str = "",
        time_distance: int = 1,
        parameter: str = None,
        color: str = "#ff00ff",
        group: Group = "",
    ) -> None:
        self.infinit = False
        self.name = name
        self.start_cmd = start_cmd
        self.stop_cmd = stop_cmd
        self.time_distance = time_distance
        self.parameter = parameter
        self.color = color
        self.group = group
        self.children = []

    @property
    def name(self) -> str:
        """Returns name of action

        Returns:
            str: name
        """
        return self._name

    @name.setter
    def name(self, name: str) -> None:
        """Name setter for action

        Args:
            name (str): name
        """
        self._name = name

    @property
    def start_cmd(self) -> str:
        """Start command for action

        Returns:
            str: start command
        """
        return self._start_cmd

    @start_cmd.setter
    def start_cmd(self, start_cmd: str) -> None:
        """Start command setter

        Args:
            start_cmd (str): start command
        """
        self._start_cmd = start_cmd

    @property
    def stop_cmd(self) -> str:
        """Stop command for action

        Returns:
            str: stop command
        """
        return self._stop_cmd

    @stop_cmd.setter
    def stop_cmd(self, stop_cmd: str) -> None:
        """Stop command setter

        Args:
            stop_cmd (str): stop command
        """
        if stop_cmd == "":
            self.infinit = True
        self._stop_cmd = stop_cmd

    @property
    def time_distance(self) -> int:
        """Time distance property

        Returns:
            int: time disdance
        """
        return self._time_distance

    @time_distance.setter
    def time_distance(self, time_distance: int) -> None:
        """Time distance setter

        Args:
            time_distance (int): time distance
        """
        try:
            self._time_distance = int(time_distance)
        except ValueError:
            self._time_distance = 99999

    @property
    def parameter(self) -> str:
        """Returns parameter str

        Returns:
            str: parameters str
        """
        return self._parameter

    @parameter.setter
    def parameter(self, parameter: str) -> None:
        """setter for parameter

        Args:
            parameter (str): string with parameters
        """
        try:
            self._parameter = parameter
        except ValueError:
            self._parameter = None

    @property
    def color(self) -> str:
        """Returns color of action

        Returns:
            str: hexadecimal format of color
        """
        return self._color

    @color.setter
    def color(self, color: str) -> None:
        """Sets coror of action

        Args:
            color (str): hexadecimal format string
        """
        self._color = color

    @property
    def group(self) -> object:
        """Returns group which action belongs to

        Returns:
            object: Group
        """
        return self._group

    @group.setter
    def group(self, group: object) -> None:
        """Sets given group as Action parent

        Args:
            group (object): Group
        """
        self._group = group

    @property
    def children(self) -> list:
        """Returns list of all actors created based on this action

        Returns:
            list: list of actors
        """
        return self._children

    @children.setter
    def children(self, children: list):
        """Sets list of actors as action children

        Args:
            children (list): list with actors

        """
        self._children = children

    def add_child(self, child: object) -> None:
        """Adds actor to children as action chilg

        Args:
            child (object): Actor
        """
        self.children.append(child)

    def remove_child(self, child: object) -> None:
        """Removes given Actor from children

        Args:
            child (object): Actor
        """
        self.children.remove(child)
        del child

    def remove(self):
        """Removes class object from existence
        """
        self.group.remove_child(self)

    def _clear_reference(self):
        """Clears all actor winthout references to actions
        """
        all_children = []
        for action in self.group.children:
            all_children.extend(action.children)
        for idx, actor in enumerate(all_children):
            if not actor.visibility:
                actor.remove()

    @property
    def hashed_id(self) -> str:
        """Returnes unique ID of action based on its group, and name.
        Format "id################"

        Returns:
            str: hashed id
        """
        group_name = self.group.name.replace(" ", "_")
        uniqe_name = group_name + self._name
        hashed_id = md5(uniqe_name.encode("utf-8"))
        unqid = "id" + str(int(hashed_id.hexdigest(), 16))
        return unqid

    def to_dict(self) -> dict:
        """Returns action as dict. Dict have all information to be recreated from dict.

        Returns:
            dict: dict with action properties
        """
        group_name = self.group.name.replace(" ", "_")
        dict_action = {}
        unqid = self.hashed_id
        dict_action[unqid] = {
            "name": self.name.replace(" ", "_"),
            "start": self.start_cmd,
            "stop": self.stop_cmd,
            "time_distance": str(self.time_distance),
            "parameter": str(self.parameter),
            "color": self.color,
            "group": group_name,
        }
        return dict_action


class Actor:
    """Actor class. Can't exist without parent.

    Attributes:
        self.parent (Action): parent Action of actor
        self.line2d (matplotlib.pyplot.Line2D): matplotlib line representation
        self.name (str): actor name
        self.group (Group): actor group
        self.color (str): actor color
        self.start_pos (int): starting time
        self.stop_pos (int): stop time
        self.parameter (str): parameters in str format
        self.y_pos (int): y position
        self.visibility (bool): tells if actor is visible
        self.infinit (bool): tells if actor has no end
        self.annotate (matplotlib.pyplot.Annotation): Annotation to be shown on hover
        self.text (matplotlib.pyplot.Text): Text to be written on actor
        self.vline (matplotlib.pyplot.Line2D): if actor is timeline this holds vertical line
    """

    def __init__(self, action: object) -> None:
        self.parent = action
        self.line2d = None
        self.name = self.parent.name
        self.group = self.parent.group
        self.color = self.parent.color
        self.start_pos = 0
        self.stop_pos = 0
        self.parameter = self.parent.parameter
        self.parent.add_child(self)
        self.y_pos = 0
        self.visibility = True
        self.infinit = action.infinit
        self.annotate = None
        self.text = None
        self.vline = None

    @property
    def visibility(self) -> bool:
        """Returns if actor is visible

        Returns:
            bool: if visible True else False
        """
        return self._visibility

    @visibility.setter
    def visibility(self, visibility: bool) -> None:
        """Sets actor visibility

        Args:
            visibility (bool): if visible True else False
        """
        self._visibility = visibility

    @property
    def annotate(self) -> object:
        """Returns Actor annotation object

        Returns:
            object: matplotlib.pyplot.Annotation
        """
        return self._annotate

    @annotate.setter
    def annotate(self, annotate: object) -> None:
        """Sets annotation for actor

        Args:
            annotate (matplotlib.pyplot.Annotation): matplotlib annotation object
        """
        self._annotate = annotate

    @property
    def vline(self) -> object:
        """If vline exixt returs it

        Returns:
            object: Line2D vertical
        """
        return self._vline

    @vline.setter
    def vline(self, vline: object) -> None:
        """Setter for vline

        Args:
            vline (object): Line2D vertical
        """
        self._vline = vline

    @property
    def text(self) -> object:
        """Holds and returns Text attribute

        Returns:
            object: Text
        """
        return self._text

    @text.setter
    def text(self, text: object) -> None:
        """Setter for text attribute

        Args:
            text (object): Text
        """
        self._text = text

    @property
    def y_pos(self) -> int:
        """Returns y-pos for actor

        Returns:
            int: position
        """
        return self._y_pos

    @y_pos.setter
    def y_pos(self, y_pos: int) -> None:
        """Stes actor y-pos

        Args:
            y_pos (int): position
        """
        self._y_pos = y_pos

    @property
    def color(self) -> str:
        """Returns color of Actor

        Returns:
            str: hexadecimal color
        """
        return self._color

    @color.setter
    def color(self, color: str) -> None:
        """Sets actor color

        Args:
            color (str): hexadecimal color
        """
        self._color = color
        if self.line2d != None:
            self.line2d.set_color(self._color)

    @property
    def parent(self) -> object:
        """Actor parent (Action)

        Returns:
            object: Action
        """
        return self._parent

    @parent.setter
    def parent(self, parent: object) -> None:
        """Setter for actor parent (Action)

        Args:
            parent (object): Action
        """
        self._parent = parent

    def update_line(self) -> None:
        """Updates line2d to reflect set attributes of actor
        """
        try:
            self.line2d.set_xdata([self.start_pos, self.stop_pos])
            self.line2d.set_color(self.color)
            self.line2d.set_ydata([self.y_pos, self.y_pos])
            self.text.set_position((self.start_pos, self.y_pos))
            if self.vline != None:
                self.vline.set_xdata(self.stop_pos)

        except AttributeError as e:
            return

    def update(self) -> None:
        """After editing action updates all actor attributes
        """
        self.name = self.parent.name
        self.color = self.parent.color
        self.parameter = self.parent.parameter
        self.update_line()

    def remove(self) -> None:
        """Removes actor, annotation, text and vline objects. Also removes actor from parent.
        (Weakref is destroyed)
        """
        try:
            self.line2d.remove()
            self.annotate.remove()
            self.text.remove()
            if self.vline != None:
                self.vline.remove()
        except (ValueError, AttributeError):
            pass
        self.parent.remove_child(self)

    def calculate_x_position(self) -> None:
        """Automatic calculation of x position based on schedule and actor attributes
        """
        all_children = []
        for action in self.group.children:
            all_children.extend(action.children)

        if not all_children:
            self.start_pos = 0
            self.stop_pos = int(self.parent.time_distance)
            return
        if [child.stop_pos for child in all_children if not child.infinit]:
            self.start_pos = max(
                [child.stop_pos for child in all_children if not child.infinit])
        else:
            self.start_pos = 0

        if self.infinit:
            self.stop_pos = self.parent.time_distance
            return

        self.stop_pos = self.start_pos + self.parent.time_distance

    def infinity_actor_handler(self) -> None:
        """Resize, change and controll behaviour of Actor with property infinite = True.
        """
        all_children = []
        for action in self.group.children:
            all_children.extend(action.children)
        positions = sorted(
            [actor.start_pos for actor in all_children])
        for actor in all_children:
            if actor.infinit:
                greater_positions = [
                    position for position in positions if position > actor.start_pos]
                if greater_positions == []:
                    actor.stop_pos = 999999
                else:
                    actor.stop_pos = min(greater_positions)

                if actor.start_pos == self.start_pos and actor != self:
                    actor.start_pos = self.stop_pos

            actor.update_line()

    @property
    def x_position(self) -> "Tuple[int, int]":
        """Holds start and stop positions of actor

        Returns:
            Tuple[int, int]: [description]
        """
        return (self.start_pos, self.stop_pos)

    @x_position.setter
    def x_position(self, positions: tuple) -> None:
        """Sets x_position of actor

        Args:
            positions (Tuple[int, int]): Tuple with two ints
        """
        x0, x1 = positions
        self.start_pos = x0
        self.stop_pos = x1
        if self.line2d != None:
            self.update_line()

    @property
    def start_pos(self) -> int:
        """Holds start position of Actor

        Returns:
            int: Start position
        """
        return self._start_pos

    @start_pos.setter
    def start_pos(self, start_pos: int) -> None:
        """Sets start position of actor

        Args:
            start_pos (int): start position

        """
        self._start_pos = start_pos

    @property
    def stop_pos(self) -> int:
        """Holds stop position of Actor

        Returns:
            int: Stop position
        """
        return self._stop_pos

    @stop_pos.setter
    def stop_pos(self, stop_pos) -> int:
        """Sets stop position of actor

        Args:
            start_pos (int): Stop position

        """
        self._stop_pos = stop_pos

    def add_line(self, line2d: "Line2D") -> None:
        """Adds Line2D to actor.

        Args:
            line2d (Line2D): Matplotlib line
        """
        self.line2d = line2d

    def to_dict(self) -> dict:
        """Creates dict with actor propertier to recreate it later

        Returns:
            dict: dict with properties
        """
        dict_actor = {}
        group_name = self.group.name.replace(" ", "_")
        uniqe_name = group_name + self.name + str(self.start_pos)
        hashed_id = md5(uniqe_name.encode("utf-8"))
        unqid = "id" + str(int(hashed_id.hexdigest(), 16))
        dict_actor[unqid] = {
            "start_pos": str(self.start_pos),
            "stop_pos": str(self.stop_pos),
            "start_cmd": str(self.parent.start_cmd),
            "stop_cmd": str(self.parent.stop_cmd),
            "y_pos": str(self.y_pos),
            "hash": self.parent.hashed_id,
            "color": self.color,
            "name": self.name,
            "group": self.group.name,
        }

        return dict_actor


class Command:
    def __init__(self):
        pass

    def finalize(self):
        pass

    def undo(self):
        raise NotImplementedError

    def redo(self):
        raise NotImplementedError


class Stack:
    def __init__(self):
        self.undo_list = []
        self.redo_list = []

    def add_command(self, command: Command) -> None:
        self.undo_list.append(command)
        self.redo_list = []

    def undo(self):
        if self.undo_list == []:
            return
        command = self.undo_list.pop()
        command.undo()
        self.redo_list.append(command)

    def redo(self):
        if self.redo_list == []:
            return
        command = self.redo_list.pop()
        command.redo()
        self.undo_list.append(command)
