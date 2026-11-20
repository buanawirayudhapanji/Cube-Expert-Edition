"""Nonblocking MIDI connection, identity query, and read-only device info."""
import json
import sys
import time
from pathlib import Path
from datetime import datetime, timezone
import mido
from PySide6.QtCore import QTimer
from PySide6.QtWidgets import (
    QApplication, QComboBox, QDoubleSpinBox, QFileDialog, QHBoxLayout, QLabel,
    QMainWindow, QMessageBox, QPushButton, QPlainTextEdit, QVBoxLayout, QWidget,
)
from .midi import enumerate_ports, message_record
from .theme_styles import stylesheet
from .theme_tokens import css
from .protocol import (
    identity_request, decode_packet, parse_identity, device_info_request, parse_device_info, ir_slot_address, slot_with_distance, parse_ir_slot, IR_SLOT_SIZE,
)

from .ir_reader import IRReader
from .ir_writer import IRWriter, save_backup, load_ir_file, write_profile_supported


class Window(QMainWindow):
    def __init__(self):
        super().__init__()
        self.backend = self.port = self.output_port = None
        self.pending = self.identity = self.device_info = None
        self.memory_job = None
        self.ir_reader = self.ir_snapshot = None
        self.ir_writer = self.imported_ir = self.imported_sector = None
        self.distance_edited = False
        self.records = []
        self.setWindowTitle('CubeBabyMOD')
        self.resize(1030, 840)
        root = QWidget()
        self.setCentralWidget(root)
        layout = QVBoxLayout(root)
        title = QLabel('CubeBabyMOD')
        title.setStyleSheet('font-size: 27px; font-weight: bold; color: '+css('accent_text')+';')
        layout.addWidget(title)
        layout.addWidget(QLabel('Hubungkan pedal untuk membaca identitas dan informasi perangkat.'))
        input_row = QHBoxLayout()
        input_row.addWidget(QLabel('Input MIDI'))
        self.ports = QComboBox()
        input_row.addWidget(self.ports, 1)
        self.refresh_button = QPushButton('Cari perangkat')
        self.refresh_button.clicked.connect(self.refresh)
        input_row.addWidget(self.refresh_button)
        layout.addLayout(input_row)
        output_row = QHBoxLayout()
        output_row.addWidget(QLabel('Output MIDI'))
        self.outputs = QComboBox()
        output_row.addWidget(self.outputs, 1)
        layout.addLayout(output_row)
        controls = QHBoxLayout()
        self.connect_button = QPushButton('Hubungkan')
        self.connect_button.clicked.connect(self.connect_device)
        controls.addWidget(self.connect_button)
        self.info_button = QPushButton('Baca info perangkat')
        self.info_button.clicked.connect(self.read_device_info)
        self.info_button.setEnabled(False)
        controls.addWidget(self.info_button)
        self.toggle = QPushButton('Mulai pantau pasif')
        self.toggle.clicked.connect(self.toggle_monitor)
        controls.addWidget(self.toggle)
        layout.addLayout(controls)
        self.device_label = QLabel('Perangkat belum terhubung')
        self.device_label.setStyleSheet('font-size: 18px; color: '+css('accent_text')+';')
        layout.addWidget(self.device_label)
        self.status = QLabel('')
        self.status.setWordWrap(True)
        layout.addWidget(self.status)
        ir_controls = QHBoxLayout()
        ir_controls.addWidget(QLabel('Slot IR'))
        self.ir_slot = QComboBox()
        self.ir_slot.addItems([str(i) for i in range(1, 9)])
        ir_controls.addWidget(self.ir_slot)
        self.ir_button = QPushButton('Baca slot IR')
        self.ir_button.clicked.connect(self.read_ir_slot)
        ir_controls.addWidget(self.ir_button)
        self.ir_export_button = QPushButton('Ekspor slot IR JSON')
        self.ir_export_button.clicked.connect(self.export_ir)
        ir_controls.addWidget(self.ir_export_button)
        layout.addLayout(ir_controls)
        self.ir_status = QLabel('Baca info perangkat terlebih dahulu untuk mengenali model pedal.')
        self.ir_status.setWordWrap(True)
        layout.addWidget(self.ir_status)
        layout.addWidget(QLabel('Pilih slot yang sudah dibaca untuk mengubah Distance atau memuat IR JSON.'))
        edit_row = QHBoxLayout()
        edit_row.addWidget(QLabel('Distance tersimpan'))
        self.distance = QDoubleSpinBox()
        self.distance.setRange(0, 100)
        self.distance.setDecimals(2)
        self.distance.setSuffix(' / 100')
        self.distance.valueChanged.connect(self.distance_changed)
        edit_row.addWidget(self.distance)
        self.import_button = QPushButton('Muat IR / cadangan JSON')
        self.import_button.clicked.connect(self.import_ir)
        edit_row.addWidget(self.import_button)
        self.save_button = QPushButton('Simpan ke slot')
        self.save_button.clicked.connect(self.save_ir)
        edit_row.addWidget(self.save_button)
        layout.addLayout(edit_row)
        self.edit_status = QLabel('Penyimpanan membuat cadangan sektor dan memverifikasi hasil baca ulang.')
        self.edit_status.setWordWrap(True)
        layout.addWidget(self.edit_status)
        self.log = QPlainTextEdit()
        self.log.setReadOnly(True)
        self.log.setMaximumBlockCount(5000)
        layout.addWidget(self.log, 1)
        export = QPushButton('Simpan log JSON')
        export.clicked.connect(self.export)
        layout.addWidget(export)
        self.timer = QTimer(self)
        self.timer.setInterval(30)
        self.timer.timeout.connect(self.poll)
        self.ports.currentTextChanged.connect(self.match_output)
        self.outputs.currentIndexChanged.connect(self.update_controls)
        self.ir_slot.currentIndexChanged.connect(self.update_controls)
        self.setStyleSheet(stylesheet())
        self.refresh()

    def append_record(self, record):
        self.records.append(record)
        if len(self.records) > 10000:
            del self.records[:1000]
        detail = record.get('message', record.get('hex', ''))
        self.log.appendPlainText(f"{record['timestamp']}  {record['direction'].upper()}  {detail}")

    def log_event(self, text):
        self.append_record({'timestamp': datetime.now(timezone.utc).isoformat(),
                            'direction': 'event', 'type': 'status', 'message': text})

    def update_controls(self, *_):
        active = self.port is not None
        writing = self.ir_writer is not None or self.memory_job is not None
        self.connect_button.setEnabled(not writing and (self.output_port is not None or
                                       (not active and self.ports.currentIndex() >= 0
                                        and self.outputs.currentIndex() >= 0)))
        self.refresh_button.setEnabled(not writing)
        self.toggle.setEnabled(self.output_port is None and self.ports.currentIndex() >= 0)
        self.info_button.setEnabled(self.identity is not None and self.pending is None and not writing and
                                    self.identity['name'] == 'SINCO-CubeBaby')
        ready = self.ir_supported() and self.pending is None and not writing
        self.ir_button.setEnabled(ready)
        self.ir_slot.setEnabled(ready)
        self.ir_export_button.setEnabled(self.ir_snapshot is not None and not writing)
        editable = (ready and self.ir_snapshot is not None and
                    self.ir_snapshot['slot'] == self.ir_slot.currentIndex()+1 and
                    write_profile_supported(self.device_info))
        self.import_button.setEnabled(editable)
        self.distance.setEnabled(editable and self.ir_snapshot['format_recognized'] and self.imported_sector is None)
        changed = False
        if editable:
            try:
                changed = (self.imported_sector is not None or
                           self.desired_record() != bytes.fromhex(self.ir_snapshot['raw_hex']))
            except ValueError:
                pass
        self.save_button.setEnabled(editable and changed)
        self.save_button.setText(('Pulihkan' if self.imported_sector is not None else 'Simpan')+
                                 (f" ke slot {self.ir_snapshot['slot']}" if self.ir_snapshot else ' ke slot'))

    def ir_supported(self):
        if self.identity is None or self.identity['name'] != 'SINCO-CubeBaby' or self.device_info is None:
            return False
        try:
            ir_slot_address(self.device_info, self.ir_slot.currentIndex())
            return True
        except ValueError:
            return False

    def match_output(self, name):
        # Prefer the exact same endpoint. Do not silently select Midi Through.
        self.outputs.setCurrentIndex(self.outputs.findText(name))
        self.update_controls()

    def stop(self):
        self.timer.stop()
        self.memory_job = None
        self.pending = self.identity = self.device_info = None
        self.ir_reader = self.ir_snapshot = None
        self.ir_writer = self.imported_ir = self.imported_sector = None
        self.distance_edited = False
        for attr in ('output_port', 'port'):
            port = getattr(self, attr)
            setattr(self, attr, None)
            if port is not None:
                try:
                    port.close()
                except (RuntimeError, OSError) as exc:
                    self.log_event(f'Port ditutup dengan kesalahan: {exc}')
        self.toggle.setText('Mulai pantau pasif')
        self.connect_button.setText('Hubungkan')
        self.ports.setEnabled(True)
        self.outputs.setEnabled(True)
        self.device_label.setText('Perangkat belum terhubung')
        self.ir_status.setText('Baca info perangkat terlebih dahulu untuk mengenali model pedal.')
        self.edit_status.setText('Penyimpanan membuat cadangan sektor dan memverifikasi hasil baca ulang.')
        self.update_controls()

    def refresh(self):
        if self.ir_writer is not None or self.memory_job is not None:
            return
        self.stop()
        self.ports.clear()
        self.outputs.clear()
        try:
            self.backend, inputs, outputs = enumerate_ports()
            self.outputs.addItems(outputs)
            self.ports.addItems(inputs)
            for i, name in enumerate(inputs):
                if 'USB2.0' in name or 'Cube' in name:
                    self.ports.setCurrentIndex(i)
                    break
            self.match_output(self.ports.currentText())
            self.status.setText(f'{len(inputs)} input dan {len(outputs)} output terdeteksi. '
                                'Klik Hubungkan untuk membaca identitas pedal.')
        except (RuntimeError, OSError, ValueError, ImportError) as exc:
            self.status.setText(f'MIDI belum dapat diakses: {exc}')
            self.log_event(self.status.text())
        self.update_controls()

    def lock_ports(self):
        self.ports.setEnabled(False)
        self.outputs.setEnabled(False)
        self.timer.start()
        self.update_controls()

    def connect_device(self):
        if self.ir_writer is not None or self.memory_job is not None:
            return
        if self.output_port is not None:
            self.stop()
            self.status.setText('Koneksi diputuskan.')
            self.log_event(self.status.text())
            return
        if self.port is not None or self.outputs.currentIndex() < 0:
            return
        try:
            self.port = self.backend.open_input(self.ports.currentText())
            self.output_port = self.backend.open_output(self.outputs.currentText())
            self.connect_button.setText('Putuskan')
            self.lock_ports()
            self.send_query('identity', identity_request())
        except (RuntimeError, OSError, ValueError) as exc:
            self.fail(f'Gagal menghubungkan: {exc}')

    def send_query(self, kind, raw, timeout=2.0):
        if self.pending is not None or self.output_port is None:
            return
        self.output_port.send(mido.Message.from_bytes(raw))
        self.append_record(message_record(mido.Message.from_bytes(raw), 'out'))
        self.pending = (kind, time.monotonic()+timeout)
        labels = {'identity': 'Membaca identitas…', 'info': 'Membaca informasi perangkat…', 'ir': 'Membaca slot IR…', 'flash': 'Memproses penyimpanan slot…', 'memory': 'Memproses pengaturan perangkat…'}
        self.status.setText(labels[kind])
        self.update_controls()

    def read_device_info(self):
        if self.ir_writer is not None or self.memory_job is not None:
            return
        if self.identity is None or self.identity['name'] != 'SINCO-CubeBaby' or self.pending:
            return
        try:
            self.send_query('info', device_info_request())
        except (RuntimeError, OSError, ValueError) as exc:
            self.fail(f'Gagal membaca informasi: {exc}')

    def read_ir_slot(self):
        if self.ir_writer is not None or self.memory_job is not None:
            return
        if self.pending is not None or not self.ir_supported():
            return
        self.ir_snapshot = self.imported_ir = self.imported_sector = None
        self.distance_edited = False
        try:
            self.ir_reader = IRReader(self.device_info, self.ir_slot.currentIndex())
            self.ir_status.setText(f'Slot {self.ir_reader.slot+1}: membaca 0 / 2056 byte…')
            self.send_query('ir', self.ir_reader.next_request())
        except (RuntimeError, OSError, ValueError) as exc:
            self.fail(f'Gagal membaca slot IR: {exc}')

    def toggle_monitor(self):
        if self.ir_writer is not None or self.memory_job is not None:
            return
        if self.output_port is not None:
            return
        if self.port is not None:
            self.stop()
            self.status.setText('Pemantauan berhenti.')
            self.log_event(self.status.text())
            return
        try:
            self.port = self.backend.open_input(self.ports.currentText())
            self.toggle.setText('Berhenti pantau')
            self.lock_ports()
            self.status.setText('Memantau pasif. Pedal mungkin hanya membalas setelah menerima perintah.')
            self.log_event(self.status.text())
        except (RuntimeError, OSError, ValueError) as exc:
            self.fail(f'Gagal membuka port: {exc}')

    def fail(self, text):
        self.stop()
        self.status.setText(text)
        self.log_event(text)
        studio = getattr(self, 'studio_ui', None)
        if studio is not None:
            studio.report_error(text)

    def accept_packet(self, packet):
        if self.pending is None:
            return
        kind, _ = self.pending
        if kind == 'identity':
            try:
                identity = parse_identity(packet)
            except ValueError:
                return
            self.identity = identity
            self.pending = None
            self.device_label.setText(identity['name'])
            self.status.setText('Terhubung. Identitas perangkat berhasil dibaca.')
            self.log_event(self.status.text())
        elif kind == 'info':
            try:
                info = parse_device_info(packet)
            except ValueError:
                return
            self.device_info = info
            self.ir_reader = self.ir_snapshot = None
            self.ir_writer = self.imported_ir = self.imported_sector = None
            self.distance_edited = False
            self.pending = None
            model = info['model'] or 'Model belum dikenali'
            self.device_label.setText(f"{self.identity['name']} · {model} · Kode {info['device_code']}")
            self.status.setText('Informasi perangkat berhasil dibaca.')
            self.log_event(f"Informasi perangkat: {json.dumps(info)}")
            if self.ir_supported():
                self.ir_status.setText('Cube Baby 20230: pilih slot 1–8, lalu klik Baca slot IR.')
            else:
                self.ir_status.setText('Pembacaan slot belum tersedia untuk model/alamat perangkat ini.')
        elif kind == 'ir':
            try:
                self.ir_reader.accept(packet)
            except ValueError:
                return
            self.pending = None
            count, total = self.ir_reader.progress
            self.ir_status.setText(f'Slot {self.ir_reader.slot+1}: membaca {count} / {total} byte…')
            if self.ir_reader.complete:
                self.ir_snapshot = self.ir_reader.snapshot()
                self.ir_reader = None
                snapshot = self.ir_snapshot
                self.set_distance(snapshot.get("distance_percent", 0))
                if snapshot['format_recognized']:
                    self.ir_status.setText(f"Slot {snapshot['slot']} · Distance tersimpan: "
                                           f"{snapshot['distance_percent']:.2f} / 100 · 512 koefisien IR")
                    if snapshot['all_zero']:
                        self.ir_status.setText(self.ir_status.text()+' · Semua data bernilai nol')
                else:
                    self.ir_status.setText(f"Slot {snapshot['slot']}: format belum dikenali. Data mentah dapat diekspor.")
                self.status.setText('Pembacaan slot IR selesai.')
                summary = {key: value for key, value in snapshot.items() if key not in ('raw_hex', 'coefficients')}
                self.log_event(f"Slot IR: {json.dumps(summary)}")
            else:
                self.send_query('ir', self.ir_reader.next_request())
        elif kind == 'flash':
            if self.ir_writer.accept(packet):
                self.pending = None
                self.drive_writer()
        elif kind == 'memory':
            if self.memory_job.accept(packet):
                self.pending = None
                self.drive_job()
        self.update_controls()

    def poll(self):
        if self.port is None:
            return
        try:
            for _ in range(128):
                message = self.port.poll()
                if message is None:
                    break
                record = message_record(message)
                packet = None
                if message.type == 'sysex':
                    try:
                        packet = decode_packet(bytes(message.bytes()))
                        record.update(opcode=packet['opcode'], payload_hex=packet['payload'].hex(' '))
                    except ValueError as exc:
                        record['decode_error'] = str(exc)
                self.append_record(record)
                if packet is not None:
                    self.accept_packet(packet)
                    if self.port is None:
                        break
            if self.pending is not None and time.monotonic() >= self.pending[1]:
                kind = self.pending[0]
                self.pending = None
                if kind == 'memory':
                    self.memory_failed('batas waktu respons perangkat terlampaui')
                elif kind == 'flash':
                    self.writer_failed('Batas waktu respons perangkat terlampaui.')
                elif kind == 'identity':
                    self.fail('Tidak ada respons identitas yang valid dalam 2 detik.')
                else:
                    if kind == 'ir':
                        self.ir_reader = None
                        self.ir_status.setText('Pembacaan slot terhenti. Data belum lengkap dan belum dapat diekspor.')
                    label = 'slot IR' if kind == 'ir' else 'info'
                    self.status.setText(f'Tidak ada respons {label} yang valid dalam 2 detik. Koneksi identitas tetap aktif.')
                    self.log_event(self.status.text())
                    self.update_controls()
            if self.ir_writer is not None and self.pending is None:
                self.drive_writer()
        except (RuntimeError, OSError, ValueError) as exc:
            if self.ir_writer is not None:
                self.writer_failed(str(exc))
            elif self.memory_job is not None:
                self.memory_failed(str(exc))
            else:
                self.fail(f'Pemantauan berhenti: {exc}')

    def set_distance(self, value):
        self.distance.blockSignals(True)
        self.distance.setValue(value)
        self.distance.blockSignals(False)
        self.distance_edited = False

    def start_job(self, job):
        if self.output_port is None or self.pending is not None or self.ir_writer is not None or self.memory_job is not None:
            raise RuntimeError('Perangkat belum siap atau operasi lain masih berlangsung')
        self.memory_job = job
        self.drive_job()

    def drive_job(self):
        job = self.memory_job
        if job.complete:
            self.memory_job = None
            if getattr(job, 'recovering', False):
                message = getattr(job, 'recovery_success', None)
                self.fail(message.format(error=job.error) if message else
                          f'{job.label} gagal: {job.error}. Status aktif/nonaktif IR sebelumnya '
                          'berhasil dipulihkan dan dibaca ulang; koefisien IR tidak diubah. '
                          'Nilai Distance perlu dibaca ulang.')
                return
            job.done({key: bytes(value) for key, value in job.results.items()})
            self.log_event(job.label+' selesai.')
        else:
            request = job.next_request()
            if request is not None:
                self.send_query('memory', request.data, request.timeout)
            self.status.setText(f'{job.label} · {job.index} / {len(job.steps)}')
        self.update_controls()

    def memory_failed(self, reason):
        job = self.memory_job
        if job is None:
            self.fail(reason)
            return
        reason = f'{reason} [{job.waiting_description}]'
        if job.recover(reason):
            self.pending = None
            self.log_event(f'{job.label} terhenti: {reason}. Memulihkan status IR sebelumnya…')
            try:
                self.drive_job()
            except (OSError, RuntimeError, ValueError) as exc:
                self.fail(f'Pemulihan status IR gagal: {exc}. Status IR perangkat belum dapat dipastikan.')
            return
        if getattr(job, 'recovering', False):
            self.fail(f'{job.label} gagal: {job.error}. Pemulihan IR juga gagal: {reason}. '
                      'Status IR perangkat belum dapat dipastikan. Nyalakan ulang pedal untuk keluar dari kondisi RAM ini.')
            return
        self.fail(f'{job.label} dihentikan: {reason}'+
                  (' Perubahan mungkin sudah diterima; hubungkan dan baca ulang perangkat.' if job.modified else ''))

    def distance_changed(self, *_):
        self.distance_edited = True
        self.update_controls()

    def desired_record(self):
        if self.ir_snapshot is None:
            raise ValueError('Baca slot terlebih dahulu')
        original = bytes.fromhex(self.ir_snapshot['raw_hex'])
        if self.imported_sector is not None:
            return self.imported_sector[:IR_SLOT_SIZE]
        raw = original if self.imported_ir is None else original[:4]+bytes.fromhex(self.imported_ir['raw_hex'])[4:]
        return slot_with_distance(raw, self.distance.value()) if self.distance_edited else raw

    def import_ir(self, path=None):
        if not self.import_button.isEnabled():
            return
        if not isinstance(path, (str, Path)) or not path:
            path, _ = QFileDialog.getOpenFileName(self, 'Muat IR atau cadangan slot', '', 'JSON (*.json)')
        if not path:
            return
        try:
            snapshot, sector = load_ir_file(path, self.ir_snapshot['address'], self.ir_snapshot['slot']-1)
            if not self.ir_snapshot['format_recognized'] and sector is None:
                raise ValueError('Format slot target belum dikenali. Gunakan cadangan sektor penuh untuk pemulihan.')
            self.imported_ir, self.imported_sector = snapshot, sector
            self.set_distance(snapshot.get('distance_percent', 0))
            action = 'Cadangan pemulihan' if sector is not None else 'IR sumber'
            self.edit_status.setText(f'{action}: {Path(path).name}. Target slot {self.ir_snapshot["slot"]}.')
            self.update_controls()
        except (OSError, ValueError) as exc:
            QMessageBox.warning(self, 'File tidak dapat dimuat', str(exc))

    def save_ir(self):
        if not self.save_button.isEnabled() or self.pending is not None or self.ir_writer is not None:
            return
        snapshot = self.ir_snapshot
        try:
            self.ir_writer = IRWriter(self.device_info, snapshot['slot']-1,
                                      bytes.fromhex(snapshot['raw_hex']), self.desired_record(),
                                      lambda address, slot, raw: save_backup(
                                          Path(__file__).resolve().parent.parent/'backups', address, slot, raw),
                                      desired_sector=self.imported_sector, clock=time.monotonic)
            self.edit_status.setText(f'Membaca sektor slot {snapshot["slot"]} untuk cadangan…')
            self.drive_writer()
        except (OSError, ValueError, RuntimeError) as exc:
            self.writer_failed(str(exc))

    def drive_writer(self):
        writer = self.ir_writer
        if writer is None:
            return
        if writer.complete:
            self.ir_snapshot = parse_ir_slot(writer.result_sector[:IR_SLOT_SIZE], writer.slot, writer.address)
            backup_path = writer.backup_path
            self.ir_writer = self.imported_ir = self.imported_sector = None
            self.set_distance(self.ir_snapshot.get('distance_percent', 0))
            if self.ir_snapshot['format_recognized']:
                self.ir_status.setText(f'Slot {self.ir_snapshot["slot"]} · Distance tersimpan: '
                                       f'{self.ir_snapshot["distance_percent"]:.2f} / 100')
            else:
                self.ir_status.setText(f'Slot {self.ir_snapshot["slot"]}: sektor terverifikasi, format IR belum dikenali.')
            self.status.setText('Tidak ada perubahan.' if writer.no_change else 'Slot tersimpan dan seluruh sektor terverifikasi.')
            self.edit_status.setText(f'Cadangan: {backup_path}' if backup_path else 'Data sudah sama dengan isi sektor.')
            self.log_event(self.status.text()+(f' Cadangan: {backup_path}' if backup_path else ''))
            self.update_controls()
            return
        state, count, total = writer.progress
        labels = {'preflight': 'Membaca cadangan', 'erase': 'Menghapus sektor',
                  'settle': 'Menunggu sektor siap', 'write': 'Menulis', 'verify': 'Memverifikasi'}
        self.edit_status.setText(f'{labels.get(state, state)} · {count} / {total} byte'+
                                (f' · Cadangan: {writer.backup_path}' if writer.backup_path else ''))
        request = writer.next_request()
        if request is not None:
            self.send_query('flash', request.data, request.timeout)
        self.update_controls()

    def writer_failed(self, reason):
        writer = self.ir_writer
        backup = writer.backup_path if writer is not None else None
        uncertain = writer is not None and writer.modified
        text = f'Penyimpanan dihentikan: {reason}'
        if uncertain:
            text += ' Isi slot mungkin belum lengkap. Hubungkan ulang dan pulihkan cadangan.'
        if backup:
            text += f' Cadangan: {backup}'
        self.fail(text)
        self.edit_status.setText(text)

    def export(self):
        path, _ = QFileDialog.getSaveFileName(self, 'Simpan log', 'cubebaby-midi.json', 'JSON (*.json)')
        if path:
            try:
                with open(path, 'w', encoding='utf-8') as stream:
                    json.dump(self.records, stream, indent=2)
            except OSError as exc:
                QMessageBox.warning(self, 'Gagal menyimpan', str(exc))

    def export_ir(self):
        if self.ir_snapshot is None:
            return
        snapshot = dict(self.ir_snapshot)
        snapshot['device_code'] = self.device_info['device_code']
        path, _ = QFileDialog.getSaveFileName(self, 'Ekspor slot IR',
                                            f"cubebaby-ir-slot-{snapshot['slot']}.json", 'JSON (*.json)')
        if path:
            try:
                with open(path, 'w', encoding='utf-8') as stream:
                    json.dump(snapshot, stream, indent=2, allow_nan=False)
            except OSError as exc:
                QMessageBox.warning(self, 'Gagal menyimpan slot IR', str(exc))

    def closeEvent(self, event):
        if (self.ir_writer is not None and self.ir_writer.modified and not self.ir_writer.complete or
                self.memory_job is not None and self.memory_job.modified and not self.memory_job.complete):
            self.status.setText('Penulisan sedang berlangsung. Tunggu hingga verifikasi selesai.')
            event.ignore()
            return
        self.stop()
        event.accept()


def run():
    from .suite_gui import SuiteWindow
    app = QApplication(sys.argv)
    window = SuiteWindow()
    window.show()
    return app.exec()
