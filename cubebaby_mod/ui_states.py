"""Presentation-only loading and offline illustrations."""
from PySide6.QtCore import QTimer, Qt
from PySide6.QtGui import QColor, QPainter, QPen
from PySide6.QtWidgets import QWidget
from .ui_preferences import reduced_motion
from .theme_tokens import qc


class PedalPreview(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setFixedSize(48, 42)
        self.setAccessibleName('Ilustrasi pedal gitar')

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.setRenderHint(QPainter.Antialiasing)
        painter.setPen(QPen(qc('accent_text'), 2))
        painter.drawRoundedRect(7, 2, 34, 37, 7, 7)
        for x in (16, 25, 34):
            painter.drawEllipse(x - 2, 9, 4, 4)
        painter.drawEllipse(20, 25, 10, 10)


class LoadingSkeleton(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setFixedHeight(22)
        self.phase = 0
        self.setAccessibleName('Memuat data…')
        self.timer = QTimer(self)
        self.timer.setInterval(90)
        self.timer.timeout.connect(self.advance)

    def run(self, callback):
        if self.property('running'):
            return
        self.setProperty('running', True)
        self.show()

        def finish():
            try:
                callback()
            finally:
                self.setProperty('running', False)
                self.hide()

        QTimer.singleShot(25, finish)

    def advance(self):
        self.phase = (self.phase + 1) % 12
        self.update()

    def showEvent(self, event):
        if not reduced_motion():
            self.timer.start()
        super().showEvent(event)

    def hideEvent(self, event):
        self.timer.stop()
        super().hideEvent(event)

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.setPen(Qt.NoPen)
        color = qc('glass_border')
        color.setAlpha(110 + 10 * min(self.phase, 12 - self.phase))
        painter.setBrush(color)
        width = max(20, (self.width() - 24) // 3)
        for index in range(3):
            painter.drawRoundedRect(index * (width + 8), 5, width, 12, 5, 5)


def confirm_overwrite(parent, title, message):
    from PySide6.QtWidgets import QMessageBox

    dialog = QMessageBox(QMessageBox.Warning, title, message, parent=parent)
    dialog.setAccessibleName(title)
    dialog.setAccessibleDescription(message)
    cancel = dialog.addButton('Batal', QMessageBox.RejectRole)
    proceed = dialog.addButton('Timpa dan simpan', QMessageBox.AcceptRole)
    dialog.setDefaultButton(cancel)
    dialog.setEscapeButton(cancel)
    dialog.exec()
    return dialog.clickedButton() is proceed


def confirm_question(parent, title, message, buttons=None, default=None):
    """Keep the original Yes/No result while giving cancellation a clear label."""
    from PySide6.QtWidgets import QMessageBox

    dialog = QMessageBox(QMessageBox.Warning, title, message, parent=parent)
    dialog.setAccessibleName(title)
    dialog.setAccessibleDescription(message)
    cancel = dialog.addButton('Batal', QMessageBox.RejectRole)
    proceed = dialog.addButton('Lanjutkan', QMessageBox.AcceptRole)
    proceed.setProperty('role', 'danger')
    dialog.setDefaultButton(cancel)
    dialog.setEscapeButton(cancel)
    dialog.exec()
    return QMessageBox.Yes if dialog.clickedButton() is proceed else QMessageBox.No


def highlight_value(widget):
    """Briefly emphasize a number edited through an existing control."""
    timer = getattr(widget, '_value_feedback_timer', None)
    if timer is None:
        timer = QTimer(widget)
        timer.setSingleShot(True)
        def clear():
            widget.setProperty('editedValue', False)
            widget.style().unpolish(widget)
            widget.style().polish(widget)
            widget.update()
        timer.timeout.connect(clear)
        widget._value_feedback_timer = timer
    widget.setProperty('editedValue', True)
    widget.style().unpolish(widget)
    widget.style().polish(widget)
    widget.update()
    timer.start(200)
