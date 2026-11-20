"""Bank/preset deployment: preflight, durable backups, sequential writes, verify.

No implicit retry or whole-bank rollback; a partial failure reports its completed
slots and backups. IRWriter rechecks every sector before its erase.
"""
from pathlib import Path
from .app_paths import backup_directory
import time
import uuid
from .collection import validate_item, unpacked, make_item, packed, atomic_json, durable_directory
from .presets import validate_presets
from .protocol import ir_slot_address, IR_SLOT_SIZE, parse_ir_slot
from .ir_writer import IRWriter, save_backup, write_profile_supported
from .memory_job import MemoryJob, read_steps, write_steps


class BankTransfer:
    def __init__(self, owner, bank, directory=None):
        validate_item(bank)
        if bank['kind'] != 'bank' or not write_profile_supported(owner.device_info):
            raise ValueError('Bank atau profil pedal tidak didukung')
        self.owner = owner
        # Serialize ownership: no caller can edit an in-progress plan.
        self.irs = [(row['slot'], unpacked(row, 'ir')) for row in bank['irs']]
        self.presets = [(row['slot'], unpacked(row, 'preset')) for row in bank['presets']]
        self.root = Path(directory or backup_directory())/f'transfer-{uuid.uuid4().hex}'
        self.backups = {}
        self.original = {}
        self.original_presets = None
        self.completed = []
        self.queue = list(self.irs)
        self.finished = False

    @property
    def context(self):
        complete = ', '.join(self.completed) or 'belum ada slot selesai'
        return f'Transfer: {complete}. Cadangan: {self.root}. Bank mungkin baru diterapkan sebagian.'

    def start(self):
        steps = []
        for slot, _ in self.irs:
            steps += read_steps(0, ir_slot_address(self.owner.device_info, slot), 4096, f'ir{slot}')
        if self.presets: steps += read_steps(5, 0, 48, 'presets')
        self.owner.start_job(MemoryJob(steps, self.prepared, 'Membaca cadangan bank'))

    def prepared(self, results):
        # No erase/write is scheduled until ALL selected targets are backed up.
        durable_directory(self.root)
        if self.presets:
            self.original_presets = validate_presets(results['presets'])
            entries = [{'slot': i, 'name': f'Preset {"ABC"[i]} sebelum transfer',
                        **packed(self.original_presets[i*16:(i+1)*16])} for i in range(3)]
            atomic_json(self.root/'presets-before.json', make_item('bank', 'Cadangan preset sebelum transfer', presets=entries))
        for slot, _ in self.irs:
            raw = results[f'ir{slot}']
            self.original[slot] = raw
            self.backups[slot] = save_backup(self.root, ir_slot_address(self.owner.device_info, slot), slot, raw)
        atomic_json(self.root/'transfer.json', {'format': 'cubebaby-transfer-v1', 'completed': [],
                    'ir_backups': {str(k+1): v for k,v in self.backups.items()},
                    'presets_backup': 'presets-before.json' if self.presets else None})
        self.advance()

    def advance(self):
        if self.queue:
            slot, desired = self.queue.pop(0)
            def existing_backup(address, saved_slot, raw):
                if saved_slot != slot or raw != self.original[slot]:
                    raise ValueError('Sektor berubah sejak cadangan bank dibuat; transfer dihentikan')
                return self.backups[slot]
            self.owner.ir_slot.setCurrentIndex(slot)
            self.owner.ir_writer = IRWriter(self.owner.device_info, slot,
                                            self.original[slot][:IR_SLOT_SIZE], desired,
                                            existing_backup, clock=time.monotonic)
            self.owner.drive_writer()
        elif self.presets:
            self.owner.start_job(MemoryJob(read_steps(5, 0, 48, 'fresh'), self.write_presets, 'Memeriksa preset target'))
        else: self.finish()

    def ir_completed(self, writer):
        self.completed.append(f'IR {writer.slot+1}')
        self.checkpoint()
        self.advance()

    def checkpoint(self):
        atomic_json(self.root/'progress.json', {'format': 'cubebaby-transfer-progress-v1', 'completed': self.completed})

    def write_presets(self, result):
        original = validate_presets(result['fresh'])
        if original != self.original_presets:
            raise ValueError('Preset pedal berubah sejak cadangan dibuat; baca ulang sebelum transfer')
        desired = bytearray(original)
        for slot, raw in self.presets:
            # Known controls only; preserve reserved bytes 13..15 on the target.
            desired[slot*16:slot*16+13] = raw[:13]
        desired = validate_presets(desired)
        if desired == original:
            self.owner.preset_data = original
            studio = getattr(self.owner, 'studio_ui', None)
            if studio is not None:
                studio.saved_presets = self.owner.preset_data
            self.owner.show_preset()
            self.finish()
            return
        def done(results):
            self.owner.preset_data = validate_presets(results['saved'])
            studio = getattr(self.owner, 'studio_ui', None)
            if studio is not None:
                studio.saved_presets = self.owner.preset_data
            self.owner.show_preset()
            self.completed += [f'Preset {"ABC"[slot]}' for slot,_ in self.presets]
            self.checkpoint()
            self.finish()
        self.owner.start_job(MemoryJob(write_steps(5, 0, desired)+read_steps(5, 0, 48, 'saved', desired),
                                      done, 'Menyimpan preset bank'))

    def finish(self):
        self.finished = True
        self.owner.transfer = None
        self.owner.update_controls()
        self.owner.status.setText(f'Transfer selesai dan terverifikasi. Cadangan: {self.root}')
        self.owner.log_event(self.owner.status.text())
