"""Shared visual tokens and small Qt widgets for the Studio."""
from pathlib import Path

from PySide6.QtCore import QRect, QSize, Signal, Qt
from PySide6.QtGui import QColor, QPainter
from PySide6.QtWidgets import QFrame, QStyle, QStyledItemDelegate, QListView


from .theme_tokens import palette, qc
from .ui_metrics import SPACE, RADII, type_font


class DropZone(QFrame):
    """Forward local files to an existing import action."""
    files_dropped = Signal(list)

    def __init__(self, extensions, parent=None):
        super().__init__(parent)
        self.extensions = frozenset(extensions)
        self.setAcceptDrops(True)
        self.setObjectName('dropZone')

    def paths(self, event):
        urls = event.mimeData().urls()
        if not urls or not all(url.isLocalFile() for url in urls):
            return []
        paths = [url.toLocalFile() for url in urls]
        return paths if all(Path(path).suffix.lower() in self.extensions for path in paths) else []

    def dragEnterEvent(self, event):
        if self.isEnabled() and self.paths(event):
            event.acceptProposedAction()
        else:
            event.ignore()

    def dropEvent(self, event):
        paths = self.paths(event)
        if self.isEnabled() and paths:
            self.files_dropped.emit(paths)
            event.acceptProposedAction()
        else:
            event.ignore()


class CollectionItemDelegate(QStyledItemDelegate):
    """Paint the same item content for list and grid navigation."""

    def sizeHint(self, option, index):
        view = option.widget
        width = view.gridSize().width() if isinstance(view, QListView) and view.viewMode() == QListView.IconMode else 240
        return QSize(max(1, width), 112)

    def paint(self, painter, option, index):
        name, kind, summary, modified = index.data(Qt.UserRole + 2)
        selected = bool(option.state & QStyle.State_Selected)
        hovered = bool(option.state & QStyle.State_MouseOver)
        focused = bool(option.state & QStyle.State_HasFocus)
        rect = option.rect.adjusted(4, 4, -4, -4)
        painter.save()
        painter.setRenderHint(QPainter.Antialiasing)
        theme = palette(option.widget.property('lightTheme'))
        painter.setBrush(qc('accent_soft' if selected or hovered else 'control', option.widget.property('lightTheme')))
        painter.setPen(qc('accent' if selected or focused else 'glass_border', option.widget.property('lightTheme')))
        painter.drawRoundedRect(rect, 9, 9)

        icon = index.data(Qt.DecorationRole)
        if icon:
            icon.paint(painter, QRect(rect.left() + 12, rect.top() + 12, 20, 20))
        x = rect.left() + 40
        width = max(0, rect.right() - x - 12)
        font = type_font('fieldLabel', option.font)
        painter.setFont(font)
        painter.setPen(QColor(theme['text_primary']))
        painter.drawText(QRect(x, rect.top() + 8, width, 20), Qt.AlignVCenter,
                         painter.fontMetrics().elidedText(name, Qt.ElideRight, width))

        font = type_font('muted', font)
        painter.setFont(font)
        badge_width = min(width, painter.fontMetrics().horizontalAdvance(kind) + 12)
        badge = QRect(x, rect.top() + 32, badge_width, 16)
        painter.setPen(Qt.NoPen)
        painter.setBrush(qc('glass_1', option.widget.property('lightTheme')))
        painter.drawRoundedRect(badge, 6, 6)
        painter.setPen(qc('accent_text', option.widget.property('lightTheme')))
        painter.drawText(badge, Qt.AlignCenter, kind)
        painter.setPen(QColor(theme['text_secondary']))
        for offset, text in ((52, summary), (72, modified)):
            painter.drawText(QRect(x, rect.top() + offset, width, 16), Qt.AlignVCenter,
                             painter.fontMetrics().elidedText(text, Qt.ElideRight, width))
        painter.restore()
