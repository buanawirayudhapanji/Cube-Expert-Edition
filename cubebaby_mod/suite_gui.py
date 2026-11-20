"""Cube Baby editor, using the original controls and resources from CubeSuite.

Transport/flash backup remains shared with the diagnostic Window. Effects and
preview are serialized with all other MIDI traffic on the same connection.
"""
from pathlib import Path
from .ui_states import confirm_question
from .rendering_ui import Waveform
import time
from PySide6.QtCore import Qt, QTimer
from PySide6.QtGui import QPixmap, QIcon
from PySide6.QtWidgets import (
    QWidget, QVBoxLayout, QHBoxLayout, QGridLayout, QGroupBox, QLabel,
    QPushButton, QComboBox, QCheckBox, QSlider, QSpinBox, QListWidget,
    QFileDialog, QMessageBox, QTabWidget,
)
from .gui import Window
from .presets import FIELDS, FACTORY_PRESETS, validate_presets, edit_preset, live_address
from .memory_job import MemoryJob, DistanceJob, PreviewJob, read_steps, write_steps
from .wav_ir import WaveIR
from .convert_ir import convert_wav
from .ir_writer import IRWriter, save_backup, write_profile_supported
from .protocol import parse_ir_slot, ir_slot_address, IR_SLOT_SIZE

ASSETS = Path(__file__).parent/'assets'


class SuiteWindow(Window):
    def __init__(self):
        self.preset_data = None
        self.loopback_value = None
        self.factory_queue = None
        self.wav_source = None
        self.staged_ir_data = None
        self.wav_folder = None
        self.preview_active = False
        self.preview_distance_value = None
        self.effect_queue = {}
        self.next_effect_at = 0.0
        self.wav_paths = []
        self.transfer = None
        self.library_panel = None
        self.studio_ui = None
        super().__init__()
        self.effect_timer = QTimer(self)
        self.effect_timer.setSingleShot(True)
        self.effect_timer.timeout.connect(self.flush_effects)
        self.setWindowTitle('CubeSuite · Cube Baby')
        self.resize(1075, 790)
        old = self.takeCentralWidget()
        root = QWidget()
        self.setCentralWidget(root)
        outer = QVBoxLayout(root)
        connection = QHBoxLayout()
        for widget in (QLabel('MIDI IN'), self.ports, QLabel('OUT'), self.outputs,
                       self.refresh_button, self.connect_button):
            connection.addWidget(widget)
        outer.addLayout(connection)
        outer.addWidget(self.device_label)
        tabs = QTabWidget()
        outer.addWidget(tabs, 1)
        editor = QWidget()
        tabs.addTab(editor, 'Cube Baby')
        columns = QHBoxLayout(editor)
        left = QVBoxLayout()
        columns.addLayout(left, 3)
        ir_box = QGroupBox('IR CABINET')
        left.addWidget(ir_box)
        ir = QVBoxLayout(ir_box)
        row = QHBoxLayout()
        row.addWidget(QLabel('IR Slot'))
        row.addWidget(self.ir_slot)
        row.addWidget(self.ir_button)
        row.addWidget(self.save_button)
        ir.addLayout(row)
        self.waveform = Waveform()
        ir.addWidget(self.waveform)
        distance = QHBoxLayout()
        distance.addWidget(QLabel('Distance'))
        distance.addWidget(self.distance)
        self.distance.setDecimals(0)
        self.distance.setRange(0, 100)
        self.set_distance(50)
        self.distance_slider = QSlider(Qt.Horizontal)
        self.distance_slider.setRange(0, 100)
        self.distance_slider.setValue(50)
        self.distance_slider.valueChanged.connect(self.distance.setValue)
        self.distance.valueChanged.connect(lambda value: self.distance_slider.setValue(round(value)))
        self.distance_slider.sliderReleased.connect(self.preview_distance)
        self.distance.editingFinished.connect(self.preview_distance)
        distance.insertWidget(1, self.distance_slider, 1)
        self.preview_button = QPushButton('Preview')
        self.preview_button.clicked.connect(self.preview_ir)
        distance.addWidget(self.preview_button)
        ir.addLayout(distance)
        ir.addWidget(self.ir_status)
        files = QGroupBox('WAV FILES')
        left.addWidget(files, 1)
        file_layout = QVBoxLayout(files)
        buttons = QHBoxLayout()
        self.folder_button = QPushButton('Folder')
        self.folder_button.clicked.connect(self.choose_folder)
        self.wav_button = QPushButton('Open WAV')
        self.wav_button.clicked.connect(self.choose_wav)
        self.folder_refresh = QPushButton('Refresh')
        self.folder_refresh.clicked.connect(self.refresh_wavs)
        for button in (self.folder_button, self.wav_button, self.folder_refresh):
            buttons.addWidget(button)
        file_layout.addLayout(buttons)
        self.wav_list = QListWidget()
        self.wav_list.itemClicked.connect(self.open_wav_item)
        self.wav_list.itemActivated.connect(self.open_wav_item)
        file_layout.addWidget(self.wav_list)
        self.wav_label = QLabel('')
        self.wav_label.setWordWrap(True)
        file_layout.addWidget(self.wav_label)
        photo = QLabel()
        pixmap = QPixmap(str(ASSETS/'LooperSuiteQT/CubeBaby'))
        photo.setPixmap(pixmap.scaled(310, 140, Qt.KeepAspectRatio, Qt.SmoothTransformation))
        photo.setAlignment(Qt.AlignCenter)
        left.addWidget(photo)
        effects = QGroupBox('EFFECTS')
        columns.addWidget(effects, 2)
        fx = QVBoxLayout(effects)
        preset_row = QHBoxLayout()
        self.preset_selector = QComboBox()
        self.preset_selector.addItems(['Preset A', 'Preset B', 'Preset C'])
        self.preset_selector.currentIndexChanged.connect(self.show_preset)
        self.preset_read = QPushButton('Read')
        self.preset_read.clicked.connect(self.read_presets)
        preset_row.addWidget(self.preset_selector)
        preset_row.addWidget(self.preset_read)
        fx.addLayout(preset_row)
        switches = QHBoxLayout()
        self.effect_switches = {}
        for offset, name in ((12, 'SW1'), (11, 'SW2'), (10, 'SW3')):
            check = QCheckBox(name)
            check.clicked.connect(lambda checked, o=offset: self.change_effect(o, int(checked)))
            self.effect_switches[offset] = check
            switches.addWidget(check)
        fx.addLayout(switches)
        grid = QGridLayout()
        self.effect_controls = {}
        for row_number, field in enumerate(FIELDS):
            slider = QSlider(Qt.Horizontal)
            slider.setRange(0, field.maximum)
            spin = QSpinBox()
            spin.setRange(0, field.maximum)
            slider.valueChanged.connect(spin.setValue)
            spin.valueChanged.connect(slider.setValue)
            spin.valueChanged.connect(lambda value, f=field: self.change_effect(f.offset, value))
            self.effect_controls[field.offset] = (slider, spin)
            grid.addWidget(QLabel(field.name), row_number, 0)
            grid.addWidget(slider, row_number, 1)
            grid.addWidget(spin, row_number, 2)
        fx.addLayout(grid)
        self.preset_save = QPushButton('Save Effects')
        self.preset_save.clicked.connect(self.save_presets)
        fx.addWidget(self.preset_save)
        self.loopback = QCheckBox('USB Loopback')
        self.loopback.clicked.connect(self.set_loopback)
        fx.addWidget(self.loopback)
        self.factory_presets_button = QPushButton('Reset preset pabrik')
        self.factory_presets_button.clicked.connect(self.reset_presets)
        self.factory_ir_button = QPushButton('Reset IR pabrik')
        self.factory_ir_button.clicked.connect(self.reset_irs)
        fx.addWidget(self.factory_presets_button)
        fx.addWidget(self.factory_ir_button)
        fx.addStretch()
        diagnostic = QWidget()
        tabs.addTab(diagnostic, 'Diagnostics / Backup')
        detail = QVBoxLayout(diagnostic)
        diag_buttons = QHBoxLayout()
        for widget in (self.info_button, self.toggle, self.ir_export_button, self.import_button):
            diag_buttons.addWidget(widget)
        detail.addLayout(diag_buttons)
        detail.addWidget(self.edit_status)
        detail.addWidget(self.log, 1)
        export = QPushButton('Save MIDI Log')
        export.clicked.connect(self.export)
        detail.addWidget(export)
        from .library_gui import LibraryPanel
        self.library_panel = LibraryPanel(self)
        tabs.addTab(self.library_panel, 'Bank / Preset / A-B')
        outer.addWidget(self.status)
        old.deleteLater()
        self.setWindowIcon(QIcon(str(ASSETS/'Icon/LooperSuiteQT.ico')))
        for button, name in ((self.folder_button, 'Folder'), (self.folder_refresh, 'Refresh'),
                             (self.wav_button, 'ChangeWav'), (self.save_button, 'Save')):
            button.setIcon(QIcon(str(ASSETS/f'LooperSuiteQT/Resources/Pictures/{name}.png')))
        from .studio_ui import StudioUI
        self.studio_ui = StudioUI(self)
        self.update_controls()

    def update_controls(self, *_):
        super().update_controls()
        if not hasattr(self, 'preset_read'):
            return
        ready = self.device_ready()
        self.preset_read.setEnabled(ready)
        self.preset_save.setEnabled(ready and self.preset_data is not None)
        self.loopback.setEnabled(ready and self.loopback_value is not None)
        self.factory_presets_button.setEnabled(ready and self.preset_data is not None)
        self.factory_ir_button.setEnabled(ready)
        editable = ready and self.ir_snapshot is not None and self.ir_snapshot['slot'] == self.ir_slot.currentIndex()+1
        have_ir = self.wav_source is not None or editable and self.ir_snapshot['format_recognized']
        self.preview_button.setEnabled(ready and have_ir)
        self.distance.setEnabled(ready and have_ir and self.imported_sector is None)
        self.distance_slider.setEnabled(self.distance.isEnabled())
        for widget in (self.wav_button, self.folder_button, self.folder_refresh, self.wav_list):
            widget.setEnabled(ready)
        if self.wav_source is not None:
            self.save_button.setEnabled(ready)
            self.save_button.setText(f'Save to IR {self.ir_slot.currentIndex()+1}')
        preset = self.preset_selector.currentIndex()
        live_edit = ready or bool(self.effect_queue) or (self.memory_job is not None and self.memory_job.label == 'Mengubah parameter live')
        self.preset_selector.setEnabled(live_edit and self.preset_data is not None)
        for offset, check in self.effect_switches.items():
            check.setEnabled(live_edit and self.preset_data is not None)
        for field in FIELDS:
            enabled = live_edit and self.preset_data is not None
            if enabled and field.switch is not None:
                enabled = bool(self.preset_data[preset*16+field.switch])
            for widget in self.effect_controls[field.offset]:
                widget.setEnabled(enabled)
        if self.factory_queue is not None or self.transfer is not None:
            for widget in (self.connect_button, self.refresh_button, self.ir_slot, self.ir_button,
                           self.info_button, self.save_button, self.distance, self.import_button):
                widget.setEnabled(False)
        if self.library_panel is not None:
            self.library_panel.update_controls()
        if self.studio_ui is not None:
            self.studio_ui.sync()

    def device_ready(self):
        return (write_profile_supported(self.device_info) and self.output_port is not None and
                self.pending is None and self.ir_writer is None and self.memory_job is None and
                self.factory_queue is None and self.transfer is None and not self.effect_queue)

    def start_transfer(self, bank):
        if not self.device_ready():
            raise RuntimeError('Tunggu operasi lain selesai dan hubungkan pedal yang didukung')
        from .transfers import BankTransfer
        transfer = BankTransfer(self, bank)
        self.transfer = transfer
        try:
            transfer.start()
        except (OSError, ValueError, RuntimeError) as exc:
            self.fail(str(exc))

    def fail(self, text):
        if self.transfer is not None:
            text += ' '+self.transfer.context
        super().fail(text)

    def stop(self):
        self.transfer = None
        self.effect_queue.clear()
        self.next_effect_at = 0.0
        if hasattr(self, 'effect_timer'):
            self.effect_timer.stop()
        self.preset_data = self.loopback_value = self.factory_queue = self.wav_source = None
        self.staged_ir_data = None
        self.preview_active = False
        self.preview_distance_value = None
        super().stop()
        if hasattr(self, 'waveform'):
            self.waveform.set_values([])
            self.show_preset()

    def accept_packet(self, packet):
        kind = self.pending[0] if self.pending else None
        super().accept_packet(packet)
        if kind == 'identity' and self.identity is not None and self.pending is None:
            self.read_device_info()
        elif kind == 'info' and self.device_info is not None and self.pending is None:
            self.preset_data = self.loopback_value = None
            if write_profile_supported(self.device_info):
                self.read_presets()
        elif kind == 'ir' and self.ir_snapshot is not None and self.ir_reader is None:
            self.wav_source = None
            self.staged_ir_data = None
            self.preview_active = False
            self.waveform.set_values(self.ir_snapshot.get('coefficients', []))

    def run_memory(self, steps, done, label):
        try:
            self.start_job(MemoryJob(steps, done, label))
        except (ValueError, RuntimeError, OSError) as exc:
            self.fail(str(exc))

    def read_presets(self):
        if not write_profile_supported(self.device_info) or self.pending or self.memory_job or self.ir_writer:
            return
        def done(result):
            self.preset_data = validate_presets(result['presets'])
            if self.studio_ui is not None:
                self.studio_ui.saved_presets = self.preset_data
            self.loopback_value = bool(result['loopback'][0])
            self.loopback.setChecked(self.loopback_value)
            self.show_preset()
            self.status.setText('Tiga preset dan USB Loopback berhasil dibaca.')
        self.run_memory(read_steps(5, 0, 48, 'presets')+read_steps(0, 0x3000, 1, 'loopback'), done, 'Membaca efek')

    def show_preset(self, *_):
        if not hasattr(self, 'effect_controls'):
            return
        start = self.preset_selector.currentIndex()*16
        for field in FIELDS:
            for widget in self.effect_controls[field.offset]:
                widget.blockSignals(True)
                widget.setValue(self.preset_data[start+field.offset] if self.preset_data else 0)
                widget.blockSignals(False)
        for offset, check in self.effect_switches.items():
            check.setChecked(bool(self.preset_data and self.preset_data[start+offset]))
        self.update_controls()

    def change_effect(self, offset, value):
        if self.preset_data is None or not self.preset_selector.isEnabled():
            return
        preset = self.preset_selector.currentIndex()
        desired = edit_preset(self.preset_data, preset, offset, value)
        if desired == self.preset_data:
            return
        self.preset_data = desired
        self.effect_queue[preset, offset] = value
        self.update_controls()
        self.flush_effects()

    def poll(self):
        super().poll()
        if self.effect_queue:
            self.flush_effects()

    def flush_effects(self):
        if self.memory_job is not None or self.pending is not None or not self.effect_queue:
            return
        remaining = self.next_effect_at - time.monotonic()
        if remaining > 0:
            self.effect_timer.start(max(1, round(remaining * 1000)))
            return
        self.effect_timer.stop()
        self.next_effect_at = time.monotonic() + .04
        preset, offset = next(iter(self.effect_queue))
        value = self.effect_queue.pop((preset, offset))
        def done(result):
            if self.effect_queue:
                self.flush_effects()
            else:
                self.update_controls()
                self.status.setText('Perubahan diterima pedal. Klik Simpan efek untuk menyimpannya.')
        self.run_memory(write_steps(5, live_address(preset, offset), bytes([value])), done, 'Mengubah parameter live')

    def save_presets(self, *_):
        if self.preset_data is None or not self.preset_save.isEnabled():
            return
        self.write_presets(self.preset_data)

    def write_presets(self, desired):
        desired = validate_presets(desired)
        def done(result):
            self.preset_data = validate_presets(result['presets'])
            if self.studio_ui is not None:
                self.studio_ui.saved_presets = self.preset_data
            self.show_preset()
            self.status.setText('Ketiga preset tersimpan dan baca ulang terverifikasi.')
        self.run_memory(write_steps(5, 0, desired)+read_steps(5, 0, 48, 'presets', desired), done, 'Menyimpan efek')

    def reset_presets(self):
        if confirm_question(self, 'Reset preset pabrik', 'Kembalikan ketiga preset ke nilai bawaan CubeSuite?', QMessageBox.Yes | QMessageBox.No, QMessageBox.No) == QMessageBox.Yes:
            self.write_presets(FACTORY_PRESETS)

    def set_loopback(self, checked):
        desired = bytes([int(checked)])
        def done(result):
            self.loopback_value = checked
            self.status.setText('USB Loopback tersimpan dan terverifikasi.')
        self.run_memory(write_steps(0, 0x3000, desired)+read_steps(0, 0x3000, 1, 'loopback', desired), done, 'USB Loopback')

    def preview_ir(self, on_success=None):
        if not self.preview_button.isEnabled():
            return
        distance = self.distance.value()
        if self.studio_ui is not None:
            self.studio_ui.ab_preview = None
            self.studio_ui.sync_comparison()
        def done(result):
            self.preview_active = True
            self.preview_distance_value = distance
            self.log_event(f'Preview IR: data 2052 byte terverifikasi; perintah aktivasi diterima. '
                           f'Byte kontrol terbaca: {result["gate_after"].hex(" ")}; '
                           'nilai ini tidak dianggap sebagai status aktif/nonaktif tetap.')
            self.status.setText('Data preview IR terverifikasi; perintah aktivasi IR diterima.')
            if callable(on_success): on_success()
        try:
            self.start_job(PreviewJob(self.desired_record(), done))
        except (OSError, RuntimeError, ValueError) as exc:
            self.memory_failed(str(exc))

    def preview_distance(self):
        if not self.preview_button.isEnabled():
            return
        if not self.preview_active:
            self.status.setText('Distance untuk slot diubah secara lokal. Simpan ke slot untuk menerapkannya; '
                                'gunakan Preview jika ingin memuat IR ini ke RAM.')
            return
        value = self.distance.value()
        if value == self.preview_distance_value:
            return
        def done(result):
            self.preview_distance_value = value
            self.status.setText('Distance RAM terverifikasi; koefisien tetap dan perintah aktivasi IR diterima.')
        try:
            self.start_job(DistanceJob(value, done))
        except (OSError, RuntimeError, ValueError) as exc:
            self.memory_failed(str(exc))

    def set_distance(self, value):
        super().set_distance(value)
        if hasattr(self, 'distance_slider'):
            self.distance_slider.blockSignals(True)
            self.distance_slider.setValue(round(value))
            self.distance_slider.blockSignals(False)

    def desired_record(self):
        # Original 0x49EC50 creates a zero header for newly imported WAVs.
        # Existing records and JSON/sector restores retain their separate rules.
        if self.wav_source is not None and self.imported_sector is None:
            if self.staged_ir_data is not None:
                from .protocol import slot_with_distance
                return (slot_with_distance(self.staged_ir_data, self.distance.value())
                        if self.distance_edited else self.staged_ir_data)
            return self.wav_source.record(b'\0'*4, self.distance.value())
        return super().desired_record()

    def save_ir(self):
        if self.wav_source is None:
            super().save_ir()
            return
        if not self.save_button.isEnabled():
            return
        slot = self.ir_slot.currentIndex()
        address = ir_slot_address(self.device_info, slot)
        desired = self.desired_record()
        def done(result):
            self.ir_writer = IRWriter(self.device_info, slot, result['record'], desired,
                                      lambda a, s, raw: save_backup(Path(__file__).parent.parent/'backups', a, s, raw),
                                      clock=time.monotonic)
            self.drive_writer()
        self.run_memory(read_steps(0, address, IR_SLOT_SIZE, 'record'), done, f'Membaca target IR {slot+1}')

    def import_ir(self, path=None):
        old_ir, old_sector = self.imported_ir, self.imported_sector
        super().import_ir(path if isinstance(path, str) else None)
        if self.imported_ir is not old_ir or self.imported_sector is not old_sector:
            self.wav_source = None
            self.staged_ir_data = None
            self.preview_active = False
            self.waveform.set_values((self.imported_ir or {}).get('coefficients', []))
            self.update_controls()

    def choose_folder(self):
        path = QFileDialog.getExistingDirectory(self, 'Pilih folder WAV', str(self.wav_folder or Path.home()))
        if path:
            self.wav_folder = Path(path)
            self.refresh_wavs()

    def refresh_wavs(self):
        self.wav_list.clear()
        if self.studio_ui is not None: self.studio_ui.sync()
        if self.wav_folder is None:
            return
        try:
            self.wav_paths = [path for path in sorted(self.wav_folder.iterdir(), key=lambda p: p.name.casefold())
                              if path.is_file() and path.suffix.lower() == '.wav']
            self.wav_list.addItems([str(path) for path in self.wav_paths])
            if self.studio_ui is not None: self.studio_ui.sync()
        except OSError as exc:
            self.status.setText(str(exc))

    def choose_wav(self):
        paths, _ = QFileDialog.getOpenFileNames(self, 'Pilih file WAV', str(self.wav_folder or ''), 'WAV (*.wav *.WAV)')
        self.show_wav_files(paths)

    def show_wav_files(self, paths):
        if paths:
            self.wav_paths = [Path(path) for path in paths]
            self.wav_list.clear()
            self.wav_list.addItems([str(path) for path in self.wav_paths])
            if self.studio_ui is not None: self.studio_ui.sync()
            self.wav_folder = self.wav_paths[0].parent

    def open_wav_item(self, item):
        row = self.wav_list.row(item)
        if 0 <= row < len(self.wav_paths):
            self.open_wav(self.wav_paths[row])

    def open_wav(self, path):
        if not self.wav_button.isEnabled():
            return
        try:
            converted = convert_wav(path)
            source = converted.wave
            raw = source.record(b'\0'*4, self.distance.value())
            slot = self.ir_slot.currentIndex()
            self.imported_ir = parse_ir_slot(raw, slot, ir_slot_address(self.device_info, slot))
            self.imported_sector = None
            self.wav_source = source
            self.staged_ir_data = None
            self.waveform.set_values(source.coefficients)
            self.wav_label.setText(f'{Path(path).name} · {converted.description}')
            self.status.setText('WAV dimuat. Buka Slot IR untuk mengatur dan menyimpannya.')
            self.update_controls()
            self.preview_ir()
        except (OSError, ValueError) as exc:
            QMessageBox.warning(self, 'WAV tidak dapat dimuat', str(exc))

    def stage_ir_record(self, raw, name):
        # Staging is local and also works offline. It never invents a pedal snapshot.
        from .collection import make_item
        make_item('ir', name[:120], raw)
        slot = self.ir_slot.currentIndex()
        address = ir_slot_address(self.device_info, slot) if write_profile_supported(self.device_info) else 0
        snapshot = parse_ir_slot(raw, slot, address)
        self.imported_ir = snapshot
        self.imported_sector = None
        self.wav_source = WaveIR(tuple(snapshot['coefficients']), 48000, 1, 32, 512)
        self.staged_ir_data = bytes(raw)
        self.preview_active = False
        self.set_distance(snapshot['distance_percent'])
        self.waveform.set_values(snapshot['coefficients'])
        self.wav_label.setText(f'{name} · IR koleksi · 48000 Hz / 512 sampel')
        self.update_controls()

    def reset_irs(self):
        path = ASSETS/'factory/cubebaby-20230-ir.bin'
        try:
            data = path.read_bytes()
            if len(data) != 32768:
                raise ValueError('Ukuran IR bawaan tidak sesuai')
        except (OSError, ValueError) as exc:
            QMessageBox.warning(self, 'Reset IR pabrik', str(exc))
            return
        if confirm_question(self, 'Reset IR pabrik', 'Kembalikan seluruh 8 slot IR ke bawaan CubeSuite? Cadangan setiap sektor dibuat sebelum penulisan.', QMessageBox.Yes | QMessageBox.No, QMessageBox.No) != QMessageBox.Yes:
            return
        self.factory_queue = [(slot, data[slot*4096:(slot+1)*4096]) for slot in range(8)]
        self.next_factory_slot()

    def next_factory_slot(self):
        if not self.factory_queue:
            self.factory_queue = None
            self.status.setText('Delapan slot IR bawaan dipulihkan dan terverifikasi.')
            self.update_controls()
            return
        slot, sector = self.factory_queue.pop(0)
        address = ir_slot_address(self.device_info, slot)
        self.ir_slot.setCurrentIndex(slot)
        def done(result):
            self.ir_writer = IRWriter(self.device_info, slot, result['record'], sector[:IR_SLOT_SIZE],
                                      lambda a, s, raw: save_backup(Path(__file__).parent.parent/'backups', a, s, raw),
                                      desired_sector=sector, clock=time.monotonic)
            self.drive_writer()
        self.run_memory(read_steps(0, address, IR_SLOT_SIZE, 'record'), done, f'Membaca slot {slot+1}')

    def drive_writer(self):
        completed_writer = self.ir_writer
        was_writing = self.ir_writer is not None
        super().drive_writer()
        if was_writing and self.ir_writer is None:
            self.wav_source = None
            self.staged_ir_data = None
            if self.ir_snapshot:
                self.waveform.set_values(self.ir_snapshot.get('coefficients', []))
            if self.transfer is not None:
                self.transfer.ir_completed(completed_writer)
                return
            if self.factory_queue is not None:
                self.next_factory_slot()

    def closeEvent(self, event):
        if self.factory_queue is not None or self.transfer is not None or self.effect_queue:
            self.status.setText('Transfer/perubahan sedang berlangsung. Tunggu hingga selesai.')
            event.ignore()
            return
        super().closeEvent(event)
        if event.isAccepted() and self.studio_ui is not None:
            self.studio_ui.save_preferences()
            self.studio_ui.audio_meter.stop()
