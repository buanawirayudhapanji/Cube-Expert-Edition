"""Native Qt adaptive containers and touch-friendly viewport behavior."""
from PySide6.QtCore import QEvent, QObject, QSize, Qt
from PySide6.QtWidgets import QScrollArea, QScroller


class AdaptiveViewport(QScrollArea):
    def __init__(self, content, parent=None):
        super().__init__(parent)
        self.setWidget(content)
        self.setWidgetResizable(True)
        self.setFrameShape(QScrollArea.NoFrame)
        self.setHorizontalScrollBarPolicy(Qt.ScrollBarAlwaysOff)
        self.setVerticalScrollBarPolicy(Qt.ScrollBarAlwaysOff)
        self.setMinimumSize(0, 0)
        self.setAccessibleName('Konten halaman')
        QScroller.grabGesture(self.viewport(), QScroller.TouchGesture)

    def resizeEvent(self, event):
        super().resizeEvent(event)
        self.fit_width()

    def minimumSizeHint(self):
        return QSize(0, 0)

    def set_compact(self, compact):
        self.setVerticalScrollBarPolicy(Qt.ScrollBarAsNeeded if compact else Qt.ScrollBarAlwaysOff)

    def fit_width(self):
        # Height can grow on a narrow display, width follows the viewport.
        if self.widget() is not None:
            content = self.widget()
            width = self.viewport().width()
            content.setMaximumWidth(width)
            # Reparenting into tabs can leave the old, taller sizeHint cached.
            # Refit to the real minimum so returning to desktop removes scrolling.
            content.resize(width, max(content.minimumSizeHint().height(), self.viewport().height()))


class ResizeObserver(QObject):
    def __init__(self, owner, callback):
        super().__init__(owner)
        self.callback = callback
        owner.installEventFilter(self)

    def eventFilter(self, watched, event):
        if event.type() == QEvent.Resize:
            self.callback(event.size().width())
        return False
