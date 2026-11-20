import copy
from pathlib import Path
import struct
import unittest
from unittest.mock import patch
import mido
from PySide6.QtCore import Qt
from PySide6.QtWidgets import QApplication, QMessageBox
from cubebaby_mod.collection import make_item, bank_entry, preset_to_bank, load_item
from cubebaby_mod.presets import FACTORY_PRESETS
from cubebaby_mod.protocol import decode_packet
from cubebaby_mod.transfers import BankTransfer
from cubebaby_mod.library_gui import PresetEditor, BankEditor
import test_suite_gui as suite
import test_wav_ir


def ir_item(name='IR', value=.25):
    return make_item('ir', name, struct.pack('<I513f', 0, .5, *([value]*512)))


class LibraryGuiTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls): cls.app = QApplication.instance() or QApplication([])
    def setUp(self):
        self.env = patch.dict('os.environ', {'CUBEBABY_LIBRARY_DIR': '/tmp/cubebaby-unused-library-tests'})
        self.env.start()
        suite.SuiteTests.setUp(self)
        from cubebaby_mod.collection import Collection
        self.panel = self.w.library_panel
        self.panel.store = Collection(Path(self.tmp.name)/'collection')
        self.panel.refresh()
        self.transfer_patch = patch('cubebaby_mod.transfers.BankTransfer',
                                    side_effect=lambda owner,bank: BankTransfer(owner,bank,Path(self.tmp.name)/'backups'))
        self.transfer_patch.start()
    def tearDown(self):
        self.transfer_patch.stop()
        suite.SuiteTests.tearDown(self)
        self.env.stop()
    def finish(self): return suite.SuiteTests.finish(self)

    def select(self, item):
        path = self.panel.store.save(item); self.panel.refresh()
        for i in range(self.panel.list.count()):
            row = self.panel.list.item(i)
            if row.data(Qt.UserRole) == str(path): self.panel.list.setCurrentItem(row); return
        self.fail('Collection item missing')

    def test_preset_editor_works_offline_and_never_sends_midi(self):
        self.w.stop()
        before = len(self.backend.commands)
        editor = PresetEditor(self.panel)
        editor.name.setText('My clean')
        editor.controls[5].setValue(90)
        item = editor.item()
        self.panel.store.save(item)
        self.assertEqual(bytes.fromhex(item['raw_hex'])[5], 90)
        self.assertEqual(len(self.backend.commands), before)
        self.assertFalse(self.panel.send_button.isEnabled())
        editor.close()

    def test_single_preset_import_preserves_other_slots_and_target_reserved_bytes(self):
        self.backend.presets[29:32] = b'\x88\x99\xaa'
        before = bytes(self.backend.presets)
        raw = bytearray(FACTORY_PRESETS[:16]); raw[5] = 99; raw[13:16] = b'\x11\x22\x33'
        item = make_item('preset', 'Clean', raw)
        self.w.start_transfer(preset_to_bank(item, 1)); self.finish()
        self.assertEqual(bytes(self.backend.presets[:16]), before[:16])
        self.assertEqual(bytes(self.backend.presets[32:]), before[32:])
        self.assertEqual(bytes(self.backend.presets[16:29]), raw[:13])
        self.assertEqual(bytes(self.backend.presets[29:32]), before[29:32])
        backup = next((Path(self.tmp.name)/'backups').glob('*/presets-before.json'))
        self.assertEqual(load_item(backup)['kind'], 'bank')
        self.assertIn('terverifikasi', self.w.status.text())

    def test_confirmed_ui_send_honors_target_selector(self):
        raw = bytearray(FACTORY_PRESETS[:16]); raw[5] = 103
        self.select(make_item('preset', 'To C', raw))
        self.panel.preset_target.setCurrentIndex(2)
        original = bytes(self.backend.presets)
        with patch('cubebaby_mod.library_gui.confirm_question', return_value=QMessageBox.Yes):
            self.panel.send_selected(); self.finish()
        self.assertEqual(bytes(self.backend.presets[:32]), original[:32])
        self.assertEqual(self.backend.presets[37], 103)

    def test_bank_backs_up_all_targets_before_first_erase_and_preserves_padding(self):
        bank = make_item('bank', 'Rock', irs=[bank_entry(0, ir_item('A', .125)), bank_entry(4, ir_item('B', .25))],
                         presets=[bank_entry(2, make_item('preset', 'Rock C', FACTORY_PRESETS[:16]))])
        before = bytes(self.backend.flash)
        original_send = self.backend.output.send
        erases = []
        def observe_erase(message):
            parsed = decode_packet(bytes(message.bytes()))
            if parsed['opcode'] == 0x21:
                folder = self.w.transfer.root
                self.assertEqual(len(list(folder.glob('cubebaby-*.json'))), 2)
                self.assertTrue((folder/'presets-before.json').exists())
                self.assertTrue((folder/'transfer.json').exists())
                erases.append(True)
            original_send(message)
        self.backend.output.send = observe_erase
        self.w.start_transfer(bank); self.finish()
        self.assertEqual(len(erases), 2)
        for slot, value in ((0, .125), (4, .25)):
            address = 0x69000+slot*4096
            self.assertEqual(self.backend.flash[address:address+2056], bytes.fromhex(ir_item(value=value)['raw_hex']))
            self.assertEqual(self.backend.flash[address+2056:address+4096], before[address+2056:address+4096])
        self.assertEqual(self.backend.flash[0x6a000:0x6d000], before[0x6a000:0x6d000])

    def test_invalid_bank_is_rejected_before_any_device_io(self):
        bank = make_item('bank', 'Bad', irs=[bank_entry(0, ir_item())])
        bank['irs'][0]['sha256'] = 'bad'
        before = len(self.backend.commands)
        with self.assertRaises(ValueError): self.w.start_transfer(bank)
        self.assertEqual(len(self.backend.commands), before)
        self.assertIsNone(self.w.transfer)

    def test_backup_failure_prevents_all_bank_writes(self):
        bank = make_item('bank', 'Fail', irs=[bank_entry(0, ir_item())])
        before = len(self.backend.commands)
        with patch('cubebaby_mod.transfers.atomic_json', side_effect=OSError('disk full')):
            self.w.start_transfer(bank); self.finish()
        self.assertFalse(any(op in (0x21, 0x22) for op,r,a,p in self.backend.commands[before:]))
        self.assertIn('disk full', self.w.status.text())
        self.assertIsNone(self.w.transfer)

    def test_partial_bank_failure_reports_completed_slot_and_keeps_both_backups(self):
        bank = make_item('bank', 'Partial', irs=[bank_entry(0, ir_item('One', .125)), bank_entry(1, ir_item('Two', .25))])
        original_send = self.backend.output.send
        def drop_second_erase_ack(message):
            original_send(message)
            parsed = decode_packet(bytes(message.bytes()))
            if parsed['opcode'] == 0x21 and int.from_bytes(parsed['payload'][1:5], 'little') == 0x6a000:
                self.backend.input.messages.pop()
        self.backend.output.send = drop_second_erase_ack
        self.w.start_transfer(bank)
        for _ in range(100):
            self.w.poll(); self.clock[0] += .11
            if self.w.ir_writer is not None and self.w.ir_writer.modified and self.w.ir_writer.slot == 1: break
        self.clock[0] += 31
        self.w.poll(); self.finish()
        self.assertIn('IR 1', self.w.status.text())
        self.assertIn('sebagian', self.w.status.text())
        self.assertNotIn('Transfer selesai', self.w.status.text())
        self.assertEqual(len(list((Path(self.tmp.name)/'backups').glob('*/cubebaby-*.json'))), 2)

    def test_ab_switching_only_uses_ram_and_retains_both_candidates(self):
        a, b = ir_item('A clean', .125), ir_item('B rock', .25)
        self.select(a); self.panel.set_ab('A')
        self.select(b); self.panel.set_ab('B')
        before = len(self.backend.commands)
        self.panel.play_ab('A'); self.finish()
        self.assertIn('Pilihan A', self.panel.ab_status.text())
        self.assertAlmostEqual(struct.unpack_from('<f', self.backend.ram, 0x76c)[0], .125)
        self.panel.play_ab('B'); self.finish()
        self.assertIn('Pilihan B', self.panel.ab_status.text())
        self.assertAlmostEqual(struct.unpack_from('<f', self.backend.ram, 0x76c)[0], .25)
        self.assertEqual(set(self.panel.ab), {'A','B'})
        self.assertFalse(any(op == 0x21 or op == 0x22 and r != 4 for op,r,a,p in self.backend.commands[before:]))

    def test_capture_entire_pedal_creates_bank_without_writes(self):
        before = len(self.backend.commands)
        with patch('cubebaby_mod.library_gui.QInputDialog.getText', return_value=('Current', True)):
            self.panel.capture_device(); self.finish()
        entries, errors = self.panel.store.entries()
        self.assertEqual(errors, [])
        bank = entries[0][1]
        self.assertEqual((len(bank['irs']), len(bank['presets'])), (8,3))
        self.assertTrue(all(op == 0x23 for op,r,a,p in self.backend.commands[before:]))

    def test_cancelled_transfer_confirmation_sends_nothing(self):
        self.select(ir_item())
        before = len(self.backend.commands)
        with patch('cubebaby_mod.library_gui.confirm_question', return_value=QMessageBox.No): self.panel.send_selected()
        self.assertEqual(len(self.backend.commands), before)

    def test_import_44100_wav_offline_is_converted_and_stored_without_midi(self):
        self.w.stop()
        path = test_wav_ir.WavTests().wav(self.tmp.name, 2, 1, [32767]+[0]*1000, 44100)
        before = len(self.backend.commands)
        with patch('cubebaby_mod.library_gui.QFileDialog.getOpenFileNames', return_value=([str(path)], 'WAV')):
            self.panel.import_files()
        entries, errors = self.panel.store.entries()
        self.assertEqual(len(entries), 1); self.assertEqual(errors, [])
        self.assertEqual(entries[0][1]['kind'], 'ir')
        self.assertEqual(len(self.backend.commands), before)

    def test_preset_changed_during_bank_transfer_is_not_overwritten(self):
        raw = bytearray(FACTORY_PRESETS[:16]); raw[5] = 105
        bank = preset_to_bank(make_item('preset', 'New', raw), 0)
        original_send = self.backend.output.send
        reads = []
        def change_before_final_read(message):
            parsed = decode_packet(bytes(message.bytes())); p = parsed['payload']
            if parsed['opcode'] == 0x23 and p[0] == 5:
                reads.append(True)
                if len(reads) == 2: self.backend.presets[5] = 87
            original_send(message)
        self.backend.output.send = change_before_final_read
        before = len(self.backend.commands)
        self.w.start_transfer(bank); self.finish()
        self.assertEqual(self.backend.presets[5], 87)
        self.assertFalse(any(op == 0x22 for op,r,a,p in self.backend.commands[before:]))
        self.assertIn('berubah', self.w.status.text())

    def test_invalid_file_in_import_batch_does_not_save_earlier_valid_item(self):
        path = test_wav_ir.WavTests().wav(self.tmp.name, 2, 1, [32767, 0])
        bad = Path(self.tmp.name)/'bad.json'; bad.write_text('{')
        before = len(self.backend.commands)
        with (patch('cubebaby_mod.library_gui.QFileDialog.getOpenFileNames', return_value=([str(path), str(bad)], '')),
              patch('cubebaby_mod.library_gui.QMessageBox.warning')):
            self.panel.import_files()
        self.assertEqual(self.panel.store.entries()[0], [])
        self.assertEqual(len(self.backend.commands), before)

    def test_bank_editor_can_compose_sparse_bank_without_a_device(self):
        p = make_item('preset', 'Clean', FACTORY_PRESETS[:16]); ir = ir_item()
        self.w.stop()
        dialog = BankEditor(self.panel, [(Path('preset'), p), (Path('ir'), ir)])
        dialog.name.setText('Sparse')
        for kind, slot, combo in dialog.targets:
            if kind == 'ir' and slot == 7 or kind == 'preset' and slot == 1: combo.setCurrentIndex(1)
        bank = dialog.item()
        self.assertEqual([row['slot'] for row in bank['irs']], [7])
        self.assertEqual([row['slot'] for row in bank['presets']], [1])
        dialog.close()

    def test_staging_captured_ir_preserves_header_and_does_not_write_pedal(self):
        from test_ir_writer import ORIGINAL
        raw = ORIGINAL[:4]+struct.pack('<f', .712345)+ORIGINAL[8:]
        self.select(make_item('ir', 'Captured', raw))
        before = len(self.backend.commands)
        self.panel.stage_selected()
        self.assertEqual(self.w.desired_record(), raw)
        self.assertEqual(len(self.backend.commands), before)
        self.w.distance.setValue(70)
        self.assertEqual(self.w.desired_record()[:4], raw[:4])
        self.assertEqual(self.w.desired_record()[8:], raw[8:])

    def test_ab_peak_matching_does_not_modify_saved_collection(self):
        item = ir_item('Quiet', .125)
        self.select(item); self.panel.set_ab('A')
        original = self.panel.selected()
        self.panel.same_peak.setChecked(True)
        self.panel.play_ab('A'); self.finish()
        self.assertAlmostEqual(struct.unpack_from('<f', self.backend.ram, 0x76c)[0], .8, places=6)
        self.assertEqual(self.panel.selected(), original)
