"""Native Qt accessibility helpers; no data or pedal operations."""
from PySide6.QtCore import QObject, Qt, QTimer
from PySide6 import QtGui
from PySide6.QtWidgets import (
    QPushButton, QScrollArea, QStackedWidget, QTabWidget, QWidget,
)


def describe_range(control, name, unit='nilai pedal'):
    """Keep Qt's native value interface and supplement it with meaningful text."""
    control.setAccessibleName(name)
    def update(*_):
        control.setAccessibleDescription(
            f'{name}: {control.value():g} {unit}. '
            f'Rentang {control.minimum():g} sampai {control.maximum():g}. '
            'Gunakan tombol panah untuk mengubah nilai.')
    control.valueChanged.connect(update)
    update()


class StatusAnnouncer(QObject):
    """Coalesce short status bursts without moving the user's keyboard focus."""
    def __init__(self, source):
        super().__init__(source)
        self.source = source
        self.last = None
        self.pending = None
        self.timer = QTimer(self)
        self.timer.setSingleShot(True)
        self.timer.timeout.connect(self.deliver)

    def announce(self, message, urgent=False):
        if not message or message == self.last:
            return
        # A routine completion must not replace an error waiting to be spoken.
        if self.pending is not None and self.pending[1] and not urgent:
            return
        self.last = message
        self.pending = (message, urgent)
        self.timer.start(120)

    def deliver(self):
        if self.pending is None:
            return
        message, urgent = self.pending
        self.pending = None
        event_class = getattr(QtGui, 'QAccessibleAnnouncementEvent', None)
        if event_class is not None:
            event = event_class(self.source, message)
            event.setPoliteness(QtGui.QAccessible.AnnouncementPoliteness.Assertive if urgent
                                else QtGui.QAccessible.AnnouncementPoliteness.Polite)
        else:
            # Older Qt exposes status text as a native alert/name change.
            self.source.setAccessibleDescription(message)
            event = QtGui.QAccessibleEvent(self.source, QtGui.QAccessible.Event.Alert if urgent
                                           else QtGui.QAccessible.Event.DescriptionChanged)
        QtGui.QAccessible.updateAccessibility(event)


class SkipButton(QPushButton):
    """Keyboard skip link: visible over the header only while focused."""
    def __init__(self, parent, callback):
        super().__init__('Lewati navigasi ke konten · F6', parent)
        self.setAccessibleName('Lewati navigasi ke konten')
        self.setAccessibleDescription('Tekan Enter untuk menuju kontrol halaman. Pintasan F6.')
        self.setObjectName('skipNavigation')
        self.setFixedSize(1, 1)
        self.move(8, 4)
        self.clicked.connect(callback)

    def focusInEvent(self, event):
        self.setFixedSize(min(self.parentWidget().width() - 16, self.sizeHint().width()), 44)
        self.raise_()
        super().focusInEvent(event)

    def focusOutEvent(self, event):
        super().focusOutEvent(event)
        self.setFixedSize(1, 1)

    def keyPressEvent(self, event):
        if event.key() in (Qt.Key_Return, Qt.Key_Enter):
            self.click()
            event.accept()
        else:
            super().keyPressEvent(event)


def focusable_controls(widget):
    """Follow layout order, treating composite native controls as single stops."""
    if not widget.isVisible() or not widget.isEnabled():
        return []
    if isinstance(widget, QTabWidget):
        return focusable_controls(widget.tabBar()) + (
            focusable_controls(widget.currentWidget()) if widget.currentWidget() else [])
    if isinstance(widget, QStackedWidget):
        return focusable_controls(widget.currentWidget()) if widget.currentWidget() else []
    if isinstance(widget, QScrollArea):
        return focusable_controls(widget.widget()) if widget.widget() else []
    if widget.focusPolicy() & Qt.TabFocus:
        return [widget]
    layout = widget.layout()
    if layout is None:
        return []
    def walk(layout):
        result = []
        for index in range(layout.count()):
            item = layout.itemAt(index)
            if item.widget() is not None:
                result.extend(focusable_controls(item.widget()))
            elif item.layout() is not None:
                result.extend(walk(item.layout()))
        return result
    return walk(layout)


def set_focus_order(widgets):
    unique = list(dict.fromkeys(widgets))
    for first, second in zip(unique, unique[1:]):
        QWidget.setTabOrder(first, second)
    return unique
