"""Device presentation and actions composed from the existing pedal jobs."""
from datetime import datetime
from html import escape
import json
from pathlib import Path
from .ui_states import confirm_question
from .theme_tokens import css, qc

from PySide6.QtCore import Qt, QTimer
from PySide6.QtGui import QTextCursor
from PySide6.QtWidgets import (
    QApplication, QCheckBox, QComboBox, QDialog, QDialogButtonBox, QHBoxLayout,
    QLabel, QLineEdit, QListWidget, QListWidgetItem, QMessageBox, QPushButton,
    QTextEdit, QVBoxLayout, QWidget,
)

from .ir_writer import load_ir_file, save_backup
from .memory_job import read_steps
from .protocol import IR_SLOT_SIZE, IR_SLOT_STRIDE, ir_slot_address, parse_ir_slot


def confirm_reset(parent, description, action):
    dialog = QDialog(parent)
    dialog.setWindowTitle('Konfirmasi reset pabrik')
    dialog.setAccessibleName('Konfirmasi reset pabrik')
    dialog.setAccessibleDescription(description + ' Ketik RESET untuk melanjutkan. Escape membatalkan.')
    layout = QVBoxLayout(dialog)
    layout.setContentsMargins(24, 24, 24, 24)
    layout.setSpacing(12)
    hint = QLabel(description + '\n\nKetik RESET untuk melanjutkan.')
    hint.setWordWrap(True)
    layout.addWidget(hint)
    entry = QLineEdit()
    entry.setPlaceholderText('Ketik RESET')
    entry.setAccessibleName('Ketik RESET untuk mengonfirmasi')
    layout.addWidget(entry)
    buttons = QDialogButtonBox(QDialogButtonBox.Ok | QDialogButtonBox.Cancel)
    confirm = buttons.button(QDialogButtonBox.Ok)
    confirm.setText('Lanjutkan reset…')
    confirm.setProperty('role', 'danger')
    confirm.setEnabled(False)
    cancel = buttons.button(QDialogButtonBox.Cancel)
    cancel.setText('Batal')
    cancel.setDefault(True)
    confirm.setAutoDefault(False)
    entry.textChanged.connect(lambda text: confirm.setEnabled(text == 'RESET'))
    buttons.accepted.connect(dialog.accept)
    buttons.rejected.connect(dialog.reject)
    layout.addWidget(buttons)
    cancel.setFocus(Qt.OtherFocusReason)
    if dialog.exec() == QDialog.Accepted and entry.text() == 'RESET' and parent.device_ready():
        action()


class BackupPanel(QWidget):
    def __init__(self, owner, directory=None):
        super().__init__()
        self.owner = owner
        self.directory = Path(directory or Path(__file__).resolve().parent.parent / 'backups')
        layout = QVBoxLayout(self)
        layout.setContentsMargins(0, 0, 0, 0)
        controls = QHBoxLayout()
        self.slot = QComboBox()
        self.slot.setAccessibleName('Slot cadangan atau pemulihan IR')
        self.slot.addItems([f'Slot IR {i}' for i in range(1, 9)])
        self.create = QPushButton('Buat cadangan')
        self.create.setProperty('role', 'primary')
        self.create.clicked.connect(self.create_backup)
        self.restore = QPushButton('Pulihkan…')
        self.restore.clicked.connect(self.restore_backup)
        controls.addWidget(self.slot)
        controls.addWidget(self.create)
        controls.addWidget(self.restore)
        layout.addLayout(controls)
        self.list = QListWidget()
        self.list.setMinimumHeight(70)
        self.list.currentRowChanged.connect(self.sync)
        layout.addWidget(self.list, 1)
        self.empty = QLabel('Belum ada cadangan. Pilih slot lalu klik Buat cadangan.')
        self.empty.setWordWrap(True)
        layout.addWidget(self.empty)
        self.refresh_button = QPushButton('Muat ulang cadangan')
        self.refresh_button.clicked.connect(self.refresh)
        layout.addWidget(self.refresh_button)
        self.refresh()

    def refresh(self):
        selected = self.list.currentItem()
        path = selected.data(Qt.UserRole) if selected else None
        self.list.clear()
        paths = []
        if self.directory.exists():
            try:
                for candidate in self.directory.rglob('*.json'):
                    try:
                        paths.append((candidate.stat().st_mtime, candidate))
                    except OSError:
                        continue
            except OSError as exc:
                self.owner.status.setText(f'Daftar cadangan belum dapat dibaca: {exc}')
        paths.sort(key=lambda item: item[0], reverse=True)
        for _, candidate in paths:
            try:
                stat = candidate.stat()
                if stat.st_size > 256 * 1024:
                    continue
                # Existing validator owns all format, slot and checksum checks.
                data = json.loads(candidate.read_text(encoding='utf-8'))
                if data.get('format') != 'cubebaby-sector-backup-v1':
                    continue
                load_ir_file(candidate, data['address'], data['slot'] - 1)
                date = datetime.fromtimestamp(stat.st_mtime).strftime('%d-%m-%Y %H:%M')
                item = QListWidgetItem(f'{candidate.name}\nSlot {data["slot"]} · {date} · {stat.st_size:,} byte')
                item.setToolTip(str(candidate))
                item.setData(Qt.UserRole, str(candidate))
                item.setData(Qt.UserRole + 1, data['slot'] - 1)
                self.list.addItem(item)
                if str(candidate) == path:
                    self.list.setCurrentItem(item)
            except (OSError, ValueError, KeyError, TypeError, AttributeError):
                continue
        self.empty.setVisible(self.list.count() == 0)
        self.sync()

    def sync(self, *_):
        ready = self.owner.device_ready()
        self.create.setEnabled(ready)
        self.restore.setEnabled(ready and self.list.currentItem() is not None)
        self.slot.setEnabled(ready)
        self.create.setToolTip('Cadangkan seluruh sektor 4096 byte dari slot terpilih.' if ready else 'Hubungkan pedal yang didukung dan tunggu proses selesai.')
        self.restore.setToolTip('Pilih cadangan dari slot yang sama, lalu pulihkan.' if ready else 'Hubungkan pedal dan tunggu proses selesai.')
        self.list.setVisible(self.list.count() > 0)

    def create_backup(self):
        o = self.owner
        if not o.device_ready():
            return
        slot = self.slot.currentIndex()
        address = ir_slot_address(o.device_info, slot)
        def done(result):
            try:
                path = save_backup(self.directory, address, slot, result['sector'])
                o.status.setText(f'Cadangan slot {slot+1} dibuat: {Path(path).name}')
                self.refresh()
            except (OSError, ValueError) as exc:
                QMessageBox.warning(self, 'Cadangan gagal', str(exc))
        o.run_memory(read_steps(0, address, IR_SLOT_STRIDE, 'sector'), done, f'Mencadangkan slot IR {slot+1}')

    def restore_backup(self):
        o = self.owner
        item = self.list.currentItem()
        if not o.device_ready() or item is None:
            return
        slot = self.slot.currentIndex()
        path = item.data(Qt.UserRole)
        try:
            address = ir_slot_address(o.device_info, slot)
            _, expected_sector = load_ir_file(path, address, slot)
        except (OSError, ValueError) as exc:
            QMessageBox.warning(self, 'Cadangan belum dapat dipulihkan', str(exc))
            return
        if confirm_question(self, 'Pulihkan cadangan IR',
                                f'Ganti seluruh isi slot IR {slot+1} dengan cadangan ini? Isi terbaru akan dicadangkan sebelum penulisan.',
                                QMessageBox.Yes | QMessageBox.No, QMessageBox.No) != QMessageBox.Yes:
            return
        o.ir_slot.setCurrentIndex(slot)
        def done(result):
            o.ir_snapshot = parse_ir_slot(result['record'], slot, address)
            o.update_controls()
            o.import_ir(path)
            if expected_sector is not None and o.imported_sector == expected_sector and o.save_button.isEnabled():
                o.save_ir()
        o.run_memory(read_steps(0, address, IR_SLOT_SIZE, 'record'), done, f'Membaca slot IR {slot+1}')


class MidiLogPanel(QWidget):
    def __init__(self, owner):
        super().__init__()
        self.owner = owner
        self.last_record = None
        self.view_start = None
        self.layout_box = QVBoxLayout(self)
        self.layout_box.setContentsMargins(0, 0, 0, 0)
        row = QHBoxLayout()
        self.filter = QComboBox()
        self.filter.setAccessibleName('Filter arah log MIDI')
        for text, direction in (('Semua', None), ('IN', 'in'), ('OUT', 'out'), ('Status', 'event')):
            self.filter.addItem(text, direction)
        self.pause = QPushButton('Jeda')
        self.pause.setCheckable(True)
        self.follow = QCheckBox('Ikuti log')
        self.follow.setChecked(True)
        row.addWidget(self.filter)
        row.addWidget(self.pause)
        row.addWidget(self.follow)
        self.layout_box.addLayout(row)
        self.console = QTextEdit()
        self.console.setReadOnly(True)
        self.console.setMinimumHeight(100)
        self.console.setPlaceholderText('Belum ada pesan MIDI')
        self.console.document().setMaximumBlockCount(10000)
        self.layout_box.addWidget(self.console, 1)
        buttons = QHBoxLayout()
        clear = QPushButton('Bersihkan')
        clear.setToolTip('Bersihkan tampilan. Ekspor tetap memuat catatan sesi.')
        clear.clicked.connect(self.clear)
        copy = QPushButton('Salin')
        copy.clicked.connect(lambda: QApplication.clipboard().setText(self.console.toPlainText()))
        export = QPushButton('Ekspor')
        export.clicked.connect(owner.export)
        for button in (clear, copy, export):
            buttons.addWidget(button)
        self.layout_box.addLayout(buttons)
        self.filter.currentIndexChanged.connect(self.redraw)
        self.pause.toggled.connect(self.pause_changed)
        self.timer = QTimer(self)
        self.timer.setInterval(150)
        self.timer.timeout.connect(self.update_log)
        self.timer.start()
        self.update_log()

    def refresh_theme(self):
        from PySide6.QtGui import QTextCharFormat
        document = self.console.document()
        state = self.console.updatesEnabled()
        self.console.setUpdatesEnabled(False)
        transaction = QTextCursor(document); transaction.beginEditBlock()
        try:
            block = document.begin()
            while block.isValid():
                text = block.text()
                cursor = QTextCursor(block)
                cursor.movePosition(QTextCursor.EndOfBlock,QTextCursor.KeepAnchor)
                fmt = QTextCharFormat(); fmt.setForeground(qc('text_primary'))
                cursor.mergeCharFormat(fmt)
                for label, token in (('IN','info_text'),('OUT','accent_text'),('STATUS','warning_text')):
                    offset = text.find(label)
                    if offset >= 0:
                        if label == 'STATUS' and any(term in text.casefold() for term in ('gagal','error','timeout')):
                            token = 'danger_text'
                        cursor.setPosition(block.position())
                        cursor.setPosition(block.position()+offset,QTextCursor.KeepAnchor)
                        fmt.setForeground(qc('text_secondary')); cursor.mergeCharFormat(fmt)
                        cursor.setPosition(block.position()+offset)
                        cursor.setPosition(block.position()+offset+len(label),QTextCursor.KeepAnchor)
                        fmt.setForeground(qc(token)); cursor.mergeCharFormat(fmt)
                        break
                block = block.next()
        finally:
            transaction.endEditBlock()
            self.console.setUpdatesEnabled(state)

    def pause_changed(self, paused):
        self.pause.setText('Lanjutkan' if paused else 'Jeda')
        if not paused:
            self.redraw()

    def clear(self):
        self.view_start = self.owner.records[-1] if self.owner.records else None
        self.last_record = self.view_start
        self.console.clear()

    def redraw(self):
        if self.pause.isChecked():
            return
        self.last_record = self.view_start
        self.console.clear()
        self.update_log()

    def update_log(self):
        if self.pause.isChecked():
            return
        records = self.owner.records
        start = 0
        if self.last_record is not None:
            for index in range(len(records)-1, -1, -1):
                if records[index] is self.last_record:
                    start = index + 1
                    break
            else:
                self.console.clear()
        if start == len(records):
            return
        scroll = self.console.verticalScrollBar()
        previous = scroll.value()
        cursor = QTextCursor(self.console.document())
        cursor.movePosition(QTextCursor.End)
        selected = self.filter.currentData()
        for record in records[start:]:
            direction = record.get('direction', 'event')
            if selected is not None and direction != selected:
                continue
            name = {'in': 'IN', 'out': 'OUT', 'event': 'STATUS'}.get(direction, direction.upper())
            color = css({'in':'info_text', 'out':'accent_text'}.get(direction,'danger_text' if any(term in str(record).casefold() for term in ('gagal','error','timeout')) else 'warning_text'))
            detail = str(record.get('message', record.get('hex', '')))
            cursor.insertHtml(f'<span style="color:{css("text_secondary")}">{escape(str(record.get("timestamp", "")))}</span> '
                              f'<b style="color:{color}">{escape(name)}</b> {escape(detail)}')
            cursor.insertBlock()
        if records:
            self.last_record = records[-1]
        if self.follow.isChecked():
            scroll.setValue(scroll.maximum())
        else:
            scroll.setValue(previous)
