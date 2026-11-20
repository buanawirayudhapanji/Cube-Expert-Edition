"""Virtual native item view, preserving the collection handlers' row interface."""
from PySide6.QtCore import (
    QAbstractListModel, QItemSelectionModel, QModelIndex, QPersistentModelIndex, Qt, Signal, QSize,
)
from PySide6.QtWidgets import QListView


class CollectionModel(QAbstractListModel):
    def __init__(self, parent):
        super().__init__(parent)
        self.records = []
        self.details = None
        self.icons = {}

    def replace(self, records, details, icons):
        self.beginResetModel()
        self.records = records
        self.details = details
        self.icons = icons
        self.endResetModel()

    def rowCount(self, parent=QModelIndex()):
        return 0 if parent.isValid() else len(self.records)

    def data(self, index, role=Qt.DisplayRole):
        if not index.isValid() or index.column() != 0 or not 0 <= index.row() < len(self.records):
            return None
        path, item = self.records[index.row()]
        if role == Qt.UserRole:
            return str(path)
        if role == Qt.UserRole + 1:
            return item['kind']
        if role == Qt.DecorationRole:
            return self.icons.get(item['kind'])
        if role in (Qt.DisplayRole, Qt.ToolTipRole, Qt.UserRole + 2, Qt.AccessibleTextRole):
            detail = self.details(path, item)
            if role == Qt.UserRole + 2:
                return detail
            name, kind, summary, date = detail
            metadata = f'{kind} · {summary}' + (f' · {date}' if date else '')
            return f'{name}\n{metadata}'
        return None

    def flags(self, index):
        return (Qt.ItemIsEnabled | Qt.ItemIsSelectable) if index.isValid() else Qt.NoItemFlags


class CollectionRow:
    """Short-lived handle; persistent indexes become invalid on model refresh."""
    def __init__(self, view, index):
        self.view = view
        self.index = QPersistentModelIndex(index)

    def data(self, role):
        return self.index.data(role) if self.index.isValid() else None

    def text(self):
        return self.data(Qt.DisplayRole) or ''

    def isSelected(self):
        return self.index.isValid() and self.view.selectionModel().isSelected(QModelIndex(self.index))

    def setSelected(self, selected):
        if self.index.isValid():
            flag = QItemSelectionModel.Select if selected else QItemSelectionModel.Deselect
            self.view.selectionModel().select(QModelIndex(self.index), flag)


class CollectionList(QListView):
    currentRowChanged = Signal(int)
    itemSelectionChanged = Signal()
    itemActivated = Signal(object)

    def __init__(self, parent=None):
        super().__init__(parent)
        self.setObjectName('collectionItems')
        # A stable gutter prevents the column count changing when the list starts scrolling.
        self.setVerticalScrollBarPolicy(Qt.ScrollBarAlwaysOn)
        self.setModel(CollectionModel(self))
        self.setUniformItemSizes(True)
        self.setBatchSize(128)
        self.selectionModel().currentChanged.connect(lambda current, previous: self.currentRowChanged.emit(current.row()))
        self.selectionModel().selectionChanged.connect(lambda *_: self.itemSelectionChanged.emit())
        self.activated.connect(lambda index: self.itemActivated.emit(CollectionRow(self, index)))
        self.verticalScrollBar().rangeChanged.connect(self.update_scroll_gutter)
        self.update_scroll_gutter(0, 0)

    def update_scroll_gutter(self, minimum, maximum):
        bar = self.verticalScrollBar()
        empty = minimum == maximum
        if bar.property('emptyRange') != empty:
            bar.setProperty('emptyRange', empty)
            bar.style().unpolish(bar)
            bar.style().polish(bar)
            bar.update()

    def fit_card_columns(self):
        if self.viewMode() != QListView.IconMode:
            return
        margins = self.contentsMargins()
        # The icon layout also reserves the styled view's contents insets.
        width = max(1, self.viewport().width() - margins.left() - margins.right() - 1)
        columns = max(1, width // 240)
        size = QSize(width // columns, 112)
        if size != self.gridSize():
            self.setGridSize(size)

    def resizeEvent(self, event):
        super().resizeEvent(event)
        self.fit_card_columns()

    def replace_records(self, records, details, icons, selected, current):
        self.setLayoutMode(QListView.Batched if len(records) >= 500 else QListView.SinglePass)
        self.model().replace(records, details, icons)
        for row, (path, _) in enumerate(records):
            key = str(path)
            if key in selected:
                self.selectionModel().select(self.model().index(row), QItemSelectionModel.Select)
            if key == current:
                self.selectionModel().setCurrentIndex(self.model().index(row), QItemSelectionModel.NoUpdate)

    def count(self):
        return self.model().rowCount()

    def item(self, row):
        index = self.model().index(row)
        return CollectionRow(self, index) if index.isValid() else None

    def currentItem(self):
        index = self.currentIndex()
        return CollectionRow(self, index) if index.isValid() else None

    def currentRow(self):
        return self.currentIndex().row()

    def setCurrentRow(self, row, command=QItemSelectionModel.ClearAndSelect):
        self.selectionModel().setCurrentIndex(self.model().index(row), command)

    def setCurrentItem(self, item, command=QItemSelectionModel.ClearAndSelect):
        index = QModelIndex(item.index) if item is not None else QModelIndex()
        self.selectionModel().setCurrentIndex(index, command)

    def selectedItems(self):
        return [CollectionRow(self, index) for index in sorted(self.selectionModel().selectedIndexes(), key=lambda index: index.row())]

    def itemAt(self, position):
        index = self.indexAt(position)
        return CollectionRow(self, index) if index.isValid() else None

    def visualItemRect(self, item):
        return self.visualRect(QModelIndex(item.index))

    def scrollToItem(self, item, hint=QListView.EnsureVisible):
        self.scrollTo(QModelIndex(item.index), hint)
