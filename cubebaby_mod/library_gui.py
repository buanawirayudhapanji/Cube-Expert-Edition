"""Offline collection editor and explicit, serialized transfers to the pedal."""
from datetime import datetime
from collections import OrderedDict
from pathlib import Path
from .ui_states import confirm_question
from .accessibility_ui import StatusAnnouncer, describe_range
from .collection_view import CollectionList
from tempfile import mkdtemp
import struct
from PySide6.QtCore import Qt
from PySide6.QtWidgets import (
    QWidget, QVBoxLayout, QHBoxLayout, QGridLayout, QLabel, QPushButton,
    QLineEdit, QComboBox, QCheckBox, QSpinBox, QGroupBox, QDialog, QDialogButtonBox,
    QFileDialog, QInputDialog, QMessageBox,
)
from .collection import Collection, make_item, bank_entry, packed, unpacked, load_item, atomic_json, preset_to_bank, sound_to_bank, clean_name
from .presets import FIELDS, FACTORY_PRESETS
from .convert_ir import convert_wav
from .protocol import parse_ir_slot, slot_with_distance, ir_slot_address
from .memory_job import MemoryJob, read_steps
from .transfers import BankTransfer


def field_label(text):
    widget = QLabel(text)
    widget.setObjectName('fieldLabel')
    return widget


class PresetEditor(QDialog):
    def __init__(self, parent, item=None):
        super().__init__(parent)
        self.setProperty('density', 'compact')
        self.setWindowTitle('Preset virtual — simpan di laptop')
        self.setAccessibleName('Editor preset virtual')
        self.setAccessibleDescription('Simpan preset di laptop. Escape membatalkan.')
        self.raw = unpacked(item, 'preset') if item else FACTORY_PRESETS[:16]
        layout = QVBoxLayout(self)
        layout.setContentsMargins(24,24,24,24); layout.setSpacing(12)
        self.setMinimumWidth(430)
        self.name = QLineEdit(item['name'] if item else 'Preset baru')
        self.name.setAccessibleName('Nama preset')
        self.name.setPlaceholderText('Contoh: Clean intro atau Rock lead')
        layout.addWidget(field_label('Nama preset')); layout.addWidget(self.name)
        grid = QGridLayout(); self.controls = {}
        grid.setVerticalSpacing(4)
        for i, field in enumerate(FIELDS):
            spin = QSpinBox(); spin.setRange(0, field.maximum); spin.setValue(self.raw[field.offset])
            describe_range(spin, field.name)
            self.controls[field.offset] = spin
            grid.addWidget(field_label(field.name), i, 0); grid.addWidget(spin, i, 1)
        for offset in (12, 11, 10):
            check = QCheckBox({12:'Amp aktif',11:'Modulasi & delay aktif',10:'Kabinet & reverb aktif'}[offset])
            check.setChecked(bool(self.raw[offset])); self.controls[offset] = check
            grid.addWidget(check, 22-offset, 0, 1, 2)
        layout.addLayout(grid)
        note = QLabel('IR CAB menunjuk isi slot IR pada pedal. Gunakan bank untuk membawa preset beserta IR-nya.')
        note.setObjectName('muted')
        note.setWordWrap(True); layout.addWidget(note)
        buttons = QDialogButtonBox(QDialogButtonBox.Save | QDialogButtonBox.Cancel)
        buttons.button(QDialogButtonBox.Save).setText('Simpan ke koleksi')
        buttons.button(QDialogButtonBox.Save).setProperty('role','primary')
        buttons.button(QDialogButtonBox.Cancel).setText('Batal')
        buttons.accepted.connect(self.accept); buttons.rejected.connect(self.reject); layout.addWidget(buttons)

    def item(self):
        raw = bytearray(self.raw)
        for offset, widget in self.controls.items():
            raw[offset] = int(widget.isChecked()) if isinstance(widget,QCheckBox) else widget.value()
        return make_item('preset', self.name.text(), raw)


class SoundEditor(QDialog):
    """Compose local snapshots only: never guess that editor IR matches a preset."""
    def __init__(self, parent, entries, current_preset=None, current_ir=None):
        super().__init__(parent)
        self.setWindowTitle('Paket preset + IR')
        self.setAccessibleName('Buat paket preset dan IR')
        self.setAccessibleDescription('Pilih sumber preset dan IR. Escape membatalkan.')
        self.setMinimumWidth(460)
        layout = QVBoxLayout(self); layout.setContentsMargins(24,24,24,24); layout.setSpacing(12)
        self.name = QLineEdit('Suara baru')
        self.name.setAccessibleName('Nama paket')
        layout.addWidget(field_label('Nama paket')); layout.addWidget(self.name)
        self.preset = QComboBox(); self.ir = QComboBox()
        for kind, combo, current in (('preset',self.preset,current_preset),('ir',self.ir,current_ir)):
            combo.setAccessibleName('Sumber preset' if kind == 'preset' else 'Sumber IR kabinet')
            combo.addItem('Pilih sumber…', None)
            if current is not None: combo.addItem('Salinan dari editor saat ini', current)
            for _, item in entries:
                if item['kind'] == kind: combo.addItem(item['name'], item)
            layout.addWidget(field_label('Pengaturan preset' if kind == 'preset' else 'IR kabinet yang disertakan'))
            layout.addWidget(combo)
        note = QLabel('Pilih IR yang memang ingin dipakai oleh preset ini. Isi IR disalin ke paket, '
                      'bukan hanya nomor slot. Saat dikirim, pilih tujuan A/B/C dan slot IR; '
                      'Kabinet IR otomatis diarahkan ke slot itu. Sakelar efek tetap mengikuti preset.')
        note.setObjectName('muted')
        note.setWordWrap(True); layout.addWidget(note)
        self.error = QLabel(); self.error.setWordWrap(True); self.error.setTextFormat(Qt.PlainText); layout.addWidget(self.error)
        self.error.setAccessibleName('Kesalahan pengisian paket')
        self.error_announcer = StatusAnnouncer(self.error)
        buttons = QDialogButtonBox(QDialogButtonBox.Save | QDialogButtonBox.Cancel)
        buttons.button(QDialogButtonBox.Save).setText('Simpan paket'); buttons.button(QDialogButtonBox.Save).setProperty('role','primary')
        buttons.button(QDialogButtonBox.Cancel).setText('Batal')
        buttons.accepted.connect(self.save); buttons.rejected.connect(self.reject); layout.addWidget(buttons)
        self.result_item = None

    def item(self):
        preset, ir = self.preset.currentData(), self.ir.currentData()
        if preset is None or ir is None: raise ValueError('Pilih satu preset dan satu IR terlebih dahulu.')
        return make_item('sound', self.name.text(),
                         preset={'name':preset['name'], **packed(unpacked(preset,'preset'))},
                         ir={'name':ir['name'], **packed(unpacked(ir,'ir'))})

    def save(self):
        try: self.result_item = self.item()
        except ValueError as exc:
            self.error.setText(str(exc))
            self.error_announcer.announce(str(exc), urgent=True)
            return
        self.accept()


class BankEditor(QDialog):
    def __init__(self, parent, entries):
        super().__init__(parent)
        self.setProperty('density', 'compact')
        self.setWindowTitle('Susun bank virtual')
        self.setAccessibleName('Susun bank virtual')
        self.setAccessibleDescription('Pilih isi tujuan IR dan preset. Escape membatalkan.')
        layout = QVBoxLayout(self)
        layout.setContentsMargins(24,24,24,24); layout.setSpacing(12); self.setMinimumWidth(450)
        self.name = QLineEdit('Bank baru'); layout.addWidget(self.name)
        self.name.setAccessibleName('Nama bank')
        grid = QGridLayout(); self.targets = []
        grid.setVerticalSpacing(4)
        for kind, limit in (('ir', 8), ('preset', 3)):
            for slot in range(limit):
                combo = QComboBox(); combo.addItem('Biarkan slot pedal tetap', None)
                for _, item in entries:
                    if item['kind'] == kind: combo.addItem(item['name'], item)
                label = f'IR {slot+1}' if kind == 'ir' else f'Preset {"ABC"[slot]}'
                combo.setAccessibleName(f'Isi untuk {label}')
                row = len(self.targets); grid.addWidget(field_label(label), row, 0); grid.addWidget(combo, row, 1)
                self.targets.append((kind, slot, combo))
        layout.addLayout(grid)
        note = QLabel('Isi slot yang dipilih akan diganti saat bank dikirim. Slot kosong pada bank tidak diubah. '
                      'IR CAB di preset tetap menunjuk nomor slot IR; pastikan pemetaannya sesuai.')
        note.setObjectName('muted')
        note.setWordWrap(True); layout.addWidget(note)
        buttons = QDialogButtonBox(QDialogButtonBox.Save | QDialogButtonBox.Cancel)
        buttons.button(QDialogButtonBox.Save).setText('Simpan bank')
        buttons.button(QDialogButtonBox.Save).setProperty('role','primary')
        buttons.button(QDialogButtonBox.Cancel).setText('Batal')
        buttons.accepted.connect(self.accept); buttons.rejected.connect(self.reject); layout.addWidget(buttons)

    def item(self):
        irs, presets = [], []
        for kind, slot, combo in self.targets:
            item = combo.currentData()
            if item: (irs if kind == 'ir' else presets).append(bank_entry(slot, item))
        return make_item('bank', self.name.text(), irs=irs, presets=presets)


KIND_LABELS = {'preset': 'Preset', 'ir': 'IR', 'bank': 'Bank', 'sound': 'Paket suara'}


def item_summary(item):
    kind = item['kind']
    if kind == 'bank':
        return f'{len(item["presets"])} preset · {len(item["irs"])} IR'
    if kind == 'ir':
        raw = unpacked(item, 'ir')
        return f'512 sampel · Jarak mikrofon {struct.unpack_from("<f", raw, 4)[0]*100:g}%'
    preset = item['preset'] if kind == 'sound' else item
    raw = unpacked(preset, 'preset')
    return f'Amp {raw[0]+1} · Gain {raw[1]} · Tone {raw[2]} · Volume {raw[5]}'


class LibraryPanel(QWidget):
    def __init__(self, owner):
        super().__init__()
        self.owner = owner
        self.store = Collection()
        self.entries = []
        self.display_cache = OrderedDict()
        self.modified_cache = {}
        self.ab = {}
        self.deleted_items = []
        self.item_details = None
        layout = QVBoxLayout(self)
        intro = QLabel('Koleksi di laptop dapat berisi banyak preset, IR, dan bank. Pedal tetap memiliki 3 preset dan 8 IR. '
                       'Membuat/mengimpor file ke koleksi tidak menulis pedal.')
        intro.setWordWrap(True); layout.addWidget(intro)
        offline = QHBoxLayout()
        self.new_preset = self.button('Buat / edit salinan preset', self.edit_preset, offline)
        self.new_bank = self.button('Susun bank', self.edit_bank, offline)
        self.new_sound = self.button('Paket preset + IR', self.create_sound, offline)
        self.import_file = self.button('Impor WAV / koleksi', self.import_files, offline)
        self.export_file = self.button('Ekspor pilihan', self.export_selected, offline)
        self.button('Refresh', self.refresh, offline)
        layout.addLayout(offline)
        self.search = QLineEdit(); self.search.setPlaceholderText('Cari nama atau jenis koleksi…')
        self.search.textChanged.connect(self.render); layout.addWidget(self.search)
        self.list = CollectionList(); self.list.currentRowChanged.connect(self.selection_changed); layout.addWidget(self.list, 1)
        self.description = QLabel(); self.description.setWordWrap(True); layout.addWidget(self.description)
        capture = QHBoxLayout()
        self.capture_preset = self.button('Simpan preset editor ke koleksi', self.capture_current_preset, capture)
        self.capture_ir = self.button('Simpan IR editor ke koleksi', self.capture_current_ir, capture)
        self.capture_bank = self.button('Baca seluruh pedal → bank', self.capture_device, capture)
        layout.addLayout(capture)
        target = QHBoxLayout()
        target.addWidget(QLabel('Target preset'))
        self.preset_target = QComboBox(); self.preset_target.addItems(['A', 'B', 'C']); target.addWidget(self.preset_target)
        target.addWidget(QLabel('Target IR'))
        self.ir_target = QComboBox(); self.ir_target.addItems([str(i) for i in range(1, 9)]); target.addWidget(self.ir_target)
        self.send_button = self.button('Kirim pilihan ke pedal…', self.send_selected, target)
        self.stage_button = self.button('Muat IR ke editor', self.stage_selected, target)
        layout.addLayout(target)
        ab_box = QGroupBox('Perbandingan IR A/B — hanya preview RAM, tidak menulis slot flash')
        ab_layout = QVBoxLayout(ab_box)
        ab_row = QHBoxLayout()
        self.ab_set_a = self.button('IR pilihan/editor → A', lambda: self.set_ab('A'), ab_row)
        self.ab_set_b = self.button('IR pilihan/editor → B', lambda: self.set_ab('B'), ab_row)
        self.ab_play_a = self.button('Dengar A', lambda: self.play_ab('A'), ab_row)
        self.ab_play_b = self.button('Dengar B', lambda: self.play_ab('B'), ab_row)
        ab_layout.addLayout(ab_row)
        options = QHBoxLayout()
        self.same_distance = QCheckBox('Gunakan Distance editor yang sama'); self.same_distance.setChecked(True)
        self.same_peak = QCheckBox('Samakan level puncak A/B')
        options.addWidget(self.same_distance); options.addWidget(self.same_peak); ab_layout.addLayout(options)
        self.ab_status = QLabel('A: belum dipilih · B: belum dipilih'); self.ab_status.setWordWrap(True)
        self.description.setTextFormat(Qt.PlainText)
        self.ab_status.setTextFormat(Qt.PlainText)
        ab_layout.addWidget(self.ab_status); layout.addWidget(ab_box)
        self.errors = QLabel(); self.errors.setWordWrap(True); self.errors.setTextFormat(Qt.PlainText); layout.addWidget(self.errors)
        self.refresh()

    def button(self, text, callback, layout):
        button = QPushButton(text); button.clicked.connect(callback); layout.addWidget(button); return button

    def warn(self, exc): QMessageBox.warning(self, 'Koleksi belum diproses', str(exc))

    def refresh(self, *_):
        self.display_cache.clear()
        self.modified_cache.clear()
        try:
            self.entries, errors = self.store.entries()
            self.errors.setText('\n'.join(errors[:5]))
            self.render()
        except (OSError, ValueError) as exc:
            self.entries = []; self.render(); self.errors.setText(str(exc))

    def modified_time(self, path):
        key = str(path)
        if key not in self.modified_cache:
            try:
                self.modified_cache[key] = path.stat().st_mtime
            except OSError:
                self.modified_cache[key] = None
        return self.modified_cache[key]

    def display_details(self, path, item):
        key = (str(path), id(item))
        metadata = self.display_cache.get(key)
        if metadata is None:
            modified = self.modified_time(path)
            date = (f'Diubah {datetime.fromtimestamp(modified).strftime("%d-%m-%Y")}'
                    if modified is not None else '')
            metadata = (item['name'], KIND_LABELS[item['kind']], item_summary(item), date)
            self.display_cache[key] = metadata
            if len(self.display_cache) > 512:
                self.display_cache.popitem(last=False)
        else:
            self.display_cache.move_to_end(key)
        return metadata

    def render(self, *_):
        current = self.list.currentItem()
        selected = {row.data(Qt.UserRole) for row in self.list.selectedItems()}
        current_path = current.data(Qt.UserRole) if current else None
        query = self.search.text().casefold()
        kind_filter = self.kind_filter.currentData() if hasattr(self, 'kind_filter') else None
        sort_mode = self.sort_mode.currentData() if hasattr(self, 'sort_mode') else None
        records = [(path, item) for path, item in self.entries
                   if query in f'[{KIND_LABELS[item["kind"]]}]  {item["name"]}'.casefold()
                   and (kind_filter is None or item['kind'] == kind_filter)]
        if sort_mode == 'name':
            records.sort(key=lambda record: record[1]['name'].casefold())
        elif sort_mode == 'recent':
            records.sort(key=lambda record: self.modified_time(record[0]) or 0, reverse=True)
        was_blocked = self.list.blockSignals(True)
        updates_enabled = self.list.updatesEnabled()
        self.list.setUpdatesEnabled(False)
        try:
            self.list.replace_records(records, self.display_details,
                                      getattr(self, 'kind_icons', {}), selected, current_path)
        finally:
            self.list.blockSignals(was_blocked)
            self.list.setUpdatesEnabled(updates_enabled)
        self.selection_changed()

    def selected(self):
        rows = self.list.selectedItems()
        return load_item(rows[0].data(Qt.UserRole)) if len(rows) == 1 else None

    def selection_changed(self, *_):
        self.item_details = None
        try:
            item = self.selected()
            self.item_details = (item['name'], KIND_LABELS[item['kind']], item_summary(item)) if item else None
            text = ''
            if item and item['kind'] == 'preset':
                raw = unpacked(item, 'preset')
                text = (f'Kabinet IR {raw[9]} · pilih target A/B/C. '
                        'Isi IR tidak dibawa oleh file preset. Setelah dikirim, pilih preset lewat footswitch pedal.')
            elif item and item['kind'] == 'sound':
                text = (f'Preset {item["preset"]["name"]} + IR {item["ir"]["name"]}. '
                        'Pilih tujuan A/B/C dan slot IR. Kabinet IR otomatis mengikuti slot tujuan; sakelar efek tetap.')
            elif item and item['kind'] == 'bank':
                text = 'Target mengikuti susunan slot di dalam bank.'
            elif item: text = 'Pilih slot tujuan IR 1–8.'
            count = len(self.list.selectedItems())
            if count > 1:
                text = f'{count} item dipilih. Ekspor bersama atau pilih satu item untuk mengirimnya ke pedal.'
            self.description.setText(text)
            self.export_file.setEnabled(count > 0)
        except (OSError, ValueError) as exc: self.description.setText(str(exc))
        self.update_controls()
        if getattr(self.owner,'studio_ui',None) is not None: self.owner.studio_ui.sync()

    def update_controls(self):
        if not hasattr(self, 'send_button'): return
        owner = self.owner
        ready = owner.device_ready()
        busy = owner.pending is not None or owner.ir_writer is not None or owner.transfer is not None or owner.factory_queue is not None
        single = len(self.list.selectedItems()) == 1
        self.send_button.setEnabled(ready and single)
        self.capture_preset.setEnabled(ready and owner.preset_data is not None)
        self.capture_bank.setEnabled(ready)
        try: have_ir = bool(owner.desired_record())
        except (ValueError, KeyError, TypeError): have_ir = False
        self.capture_ir.setEnabled(have_ir and not busy)
        self.stage_button.setEnabled(not busy and single)
        self.ab_set_a.setEnabled(not busy); self.ab_set_b.setEnabled(not busy)
        self.ab_play_a.setEnabled(ready and 'A' in self.ab); self.ab_play_b.setEnabled(ready and 'B' in self.ab)
        self.same_distance.setEnabled(not busy); self.same_peak.setEnabled(not busy)
        self.preset_target.setEnabled(not busy); self.ir_target.setEnabled(not busy)
        if getattr(owner,'studio_ui',None) is not None: owner.studio_ui.sync_comparison()

    def new_preset_dialog(self):
        self.edit_preset(use_selection=False)

    def edit_preset(self, *, use_selection=True):
        try:
            item = self.selected() if use_selection else None
            dialog = PresetEditor(self, item if item and item['kind'] == 'preset' else None)
            if dialog.exec() == QDialog.Accepted:
                self.store.save(dialog.item()); self.refresh()
        except (OSError, ValueError) as exc: self.warn(exc)

    def selected_paths(self):
        known = {path for path, _ in self.entries}
        return [path for row in self.list.selectedItems()
                if (path := Path(row.data(Qt.UserRole))) in known]

    def rename_selected(self):
        paths = self.selected_paths()
        if len(paths) != 1:
            return
        path = paths[0]
        try:
            item = load_item(path)
            name, accepted = QInputDialog.getText(self, 'Ganti nama item', 'Nama baru', text=item['name'])
            if accepted:
                updated = {**item, 'name': clean_name(name)}
                if updated != item:
                    atomic_json(path, updated)
                    self.owner.status.setText('Nama item diperbarui.')
                    self.refresh()
        except (OSError, ValueError) as exc:
            self.warn(exc)

    def duplicate_selected(self):
        paths = self.selected_paths()
        if not paths:
            return
        saved = 0
        try:
            for path in paths:
                item = load_item(path)
                self.store.save(item)
                saved += 1
        except (OSError, ValueError) as exc:
            self.warn(exc)
        finally:
            self.refresh()
            self.owner.status.setText(f'{saved} dari {len(paths)} item diduplikat.')

    def delete_selected(self):
        paths = self.selected_paths()
        if not paths:
            return
        if confirm_question(self, 'Hapus item koleksi',
                                f'Hapus {len(paths)} item dari koleksi laptop? Data di pedal tetap utuh.',
                                QMessageBox.Yes | QMessageBox.No, QMessageBox.No) != QMessageBox.Yes:
            return
        removed = 0
        self.deleted_items = []
        try:
            for path in paths:
                item = load_item(path)
                path.unlink()
                self.deleted_items.append((path, item))
                removed += 1
        except OSError as exc:
            self.warn(exc)
        finally:
            self.refresh()
            self.owner.status.setText(f'{removed} dari {len(paths)} item dihapus dari koleksi laptop.')

    def undo_delete(self):
        remaining = []
        restored = 0
        for path, item in self.deleted_items:
            try:
                if path.exists():
                    remaining.append((path, item))
                    continue
                atomic_json(path, item)
                restored += 1
            except (OSError, ValueError) as exc:
                remaining.append((path, item))
                self.warn(exc)
        self.deleted_items = remaining
        self.refresh()
        self.owner.status.setText(f'{restored} item dikembalikan ke koleksi.')

    def create_sound(self):
        try:
            current_preset = current_ir = None
            if self.owner.preset_data is not None:
                slot = self.owner.preset_selector.currentIndex()
                current_preset = make_item('preset', f'Preset editor {"ABC"[slot]}',
                                           self.owner.preset_data[slot*16:(slot+1)*16])
            try: current_ir = make_item('ir', 'IR editor', self.owner.desired_record())
            except (ValueError, KeyError, TypeError): pass
            # Refresh source bytes before composing; packages never reference external paths.
            entries, errors = self.store.entries()
            if errors: self.errors.setText('\n'.join(errors[:5]))
            dialog = SoundEditor(self, entries, current_preset, current_ir)
            selected = self.selected()
            if selected and selected['kind'] in ('preset','ir'):
                combo = dialog.preset if selected['kind'] == 'preset' else dialog.ir
                for index in range(1,combo.count()):
                    if combo.itemData(index) == selected: combo.setCurrentIndex(index); break
            if dialog.exec() == QDialog.Accepted:
                self.store.save(dialog.result_item); self.refresh()
                self.owner.status.setText('Paket preset + IR disimpan di laptop. Pedal belum diubah.')
        except (OSError, ValueError) as exc: self.warn(exc)

    def edit_bank(self):
        try:
            dialog = BankEditor(self, self.entries)
            if dialog.exec() == QDialog.Accepted:
                self.store.save(dialog.item()); self.refresh()
        except (OSError, ValueError) as exc: self.warn(exc)

    def import_files(self):
        paths, _ = QFileDialog.getOpenFileNames(self, 'Impor koleksi atau IR WAV', '', 'Koleksi / WAV (*.json *.wav *.WAV)')
        self.import_paths(paths)

    def import_paths(self, paths):
        if not paths: return
        saved = 0
        try:
            items = []
            for path in paths:
                if Path(path).suffix.lower() == '.wav':
                    converted = convert_wav(path)
                    items.append(make_item('ir', Path(path).stem[:120], converted.wave.record(b'\0'*4, 50)))
                else: items.append(load_item(path))
            for item in items:
                self.store.save(item); saved += 1
            self.refresh(); self.owner.status.setText(f'{len(items)} item diimpor ke koleksi laptop; pedal tidak ditulis.')
        except (OSError, ValueError) as exc:
            self.refresh()
            self.owner.status.setText(f'Impor berhenti: {saved} item tersimpan di koleksi laptop. Pedal tidak ditulis.')
            self.warn(exc)

    def export_selected(self):
        try:
            rows = self.list.selectedItems()
            if len(rows) > 1:
                folder = QFileDialog.getExistingDirectory(self, 'Pilih folder ekspor')
                if not folder:
                    return
                items = [(Path(row.data(Qt.UserRole)).stem, load_item(row.data(Qt.UserRole))) for row in rows]
                target = Path(mkdtemp(prefix='cubebaby-', dir=folder))
                for stem, item in items:
                    atomic_json(target / f'{stem}.json', item)
                self.owner.status.setText(f'{len(items)} item diekspor ke {target}.')
                return
            item = self.selected()
            if item is None: return
            path, _ = QFileDialog.getSaveFileName(self, 'Ekspor koleksi', f'cubebaby-{item["kind"]}.json', 'JSON (*.json)')
            if path: atomic_json(path, item)
        except (OSError, ValueError) as exc: self.warn(exc)

    def capture_current_preset(self):
        if not self.owner.device_ready() or self.owner.preset_data is None: return
        slot = self.owner.preset_selector.currentIndex()
        raw = bytes(self.owner.preset_data[slot*16:(slot+1)*16])
        name, ok = QInputDialog.getText(self, 'Nama preset', 'Nama koleksi', text=f'Preset {"ABC"[slot]}')
        if not ok: return
        try:
            self.store.save(make_item('preset', name, raw)); self.refresh()
        except (OSError, ValueError) as exc: self.warn(exc)

    def capture_current_ir(self):
        name, ok = QInputDialog.getText(self, 'Nama IR', 'Nama koleksi', text='IR pilihan')
        if not ok: return
        try: self.store.save(make_item('ir', name, self.owner.desired_record())); self.refresh()
        except (OSError, ValueError) as exc: self.warn(exc)

    def capture_device(self):
        if not self.owner.device_ready(): return
        name, ok = QInputDialog.getText(self, 'Nama bank', 'Nama bank', text='Bank dari pedal')
        if not ok: return
        def done(result):
            irs = [{'slot': s, 'name': f'IR {s+1}', **packed(result[f'ir{s}'])} for s in range(8)]
            presets = [{'slot': s, 'name': f'Preset {"ABC"[s]}', **packed(result['presets'][s*16:(s+1)*16])} for s in range(3)]
            self.store.save(make_item('bank', name, irs=irs, presets=presets))
            self.refresh(); self.owner.status.setText('Seluruh bank pedal disimpan ke koleksi laptop.')
        try:
            name = clean_name(name)
            steps = read_steps(5, 0, 48, 'presets')
            for slot in range(8): steps += read_steps(0, ir_slot_address(self.owner.device_info, slot), 2056, f'ir{slot}')
            self.owner.start_job(MemoryJob(steps, done, 'Membaca bank pedal'))
        except (OSError, ValueError, RuntimeError) as exc: self.warn(exc)

    def send_selected(self):
        if not self.owner.device_ready(): return
        try:
            item = self.selected()
            if item is None: return
            if item['kind'] == 'sound':
                bank = sound_to_bank(item, self.preset_target.currentIndex(), self.ir_target.currentIndex())
            elif item['kind'] == 'preset': bank = preset_to_bank(item, self.preset_target.currentIndex())
            elif item['kind'] == 'ir':
                bank = make_item('bank', item['name'], irs=[bank_entry(self.ir_target.currentIndex(), item)])
            else: bank = item
            targets = ([f'IR {r["slot"]+1}: {r["name"]}' for r in bank['irs']]+
                       [f'Preset {"ABC"[r["slot"]]}: {r["name"]}' for r in bank['presets']])
            details = '\n'.join(targets)
            if item['kind'] == 'sound':
                details += (f'\nKabinet IR preset → slot {self.ir_target.currentIndex()+1} (otomatis). '
                            'Sakelar efek tetap mengikuti preset.\nIR ditulis dan diverifikasi sebelum preset. '
                            'Preset lain yang memakai slot IR ini juga akan mendengar kabinet baru.')
            if confirm_question(self, 'Kirim ke pedal', details+
                                    '\n\nSlot tersebut akan diganti. Slot lain tetap. Cadangan dibuat sebelum penulisan. Lanjutkan?',
                                    QMessageBox.Yes | QMessageBox.No, QMessageBox.No) != QMessageBox.Yes: return
            self.owner.start_transfer(bank)
        except (OSError, ValueError, RuntimeError) as exc: self.warn(exc)

    def stage_selected(self):
        try:
            item = self.selected()
            if not item or item['kind'] != 'ir': raise ValueError('Pilih satu IR dari koleksi')
            self.owner.stage_ir_record(unpacked(item, 'ir'), item['name'])
            self.owner.status.setText('IR dimuat ke editor; pilih Coba IR atau Simpan ke slot.')
            if self.owner.studio_ui is not None:
                self.owner.studio_ui.open_ir_slots()
        except (OSError, ValueError) as exc: self.warn(exc)

    def set_ab(self, side, source=None):
        try:
            if source is not None: raw, name = source
            else:
                item = self.selected()
                if item and item['kind'] == 'ir': raw, name = unpacked(item, 'ir'), item['name']
                else: raw, name = self.owner.desired_record(), self.owner.wav_label.text() or 'IR editor'
            make_item('ir', name[:120], raw)
            self.ab[side] = (bytes(raw), name)
            self.ab_status.setText(' · '.join(f'{s}: {self.ab[s][1] if s in self.ab else "belum dipilih"}' for s in ('A', 'B')))
            self.update_controls()
        except (OSError, ValueError) as exc: self.warn(exc)

    def play_ab(self, side):
        if not self.owner.device_ready() or side not in self.ab: return
        try:
            raw, name = self.ab[side]
            if self.same_distance.isChecked(): raw = slot_with_distance(raw, self.owner.distance.value())
            if self.same_peak.isChecked():
                values = struct.unpack_from('<512f', raw, 8); peak = max(abs(v) for v in values)
                if peak == 0: raise ValueError('IR pembanding kosong')
                raw = raw[:8]+struct.pack('<512f', *(v*.8/peak for v in values))
            self.owner.stage_ir_record(raw, name)
            def verified():
                self.ab_status.setText(f'Pilihan {side}: {name} · data RAM terverifikasi')
                studio = getattr(self.owner, 'studio_ui', None)
                if studio is not None:
                    studio.ab_preview = (side, self.ab[side])
                    studio.sync_comparison()

            self.owner.preview_ir(on_success=verified)
        except (OSError, ValueError, RuntimeError) as exc: self.warn(exc)
