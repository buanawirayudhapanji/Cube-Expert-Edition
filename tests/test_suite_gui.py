from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch
import mido
from PySide6.QtWidgets import QApplication, QMessageBox
from PySide6.QtCore import QCoreApplication, QEvent
from cubebaby_mod.suite_gui import SuiteWindow, ASSETS
from cubebaby_mod.presets import FACTORY_PRESETS
from cubebaby_mod.protocol import decode_packet, encode_packet
from cubebaby_mod.ir_writer import save_backup
from test_write_gui import Backend as OldBackend
from test_connection import PORT
from test_ir_writer import SECTOR
import test_wav_ir


class Output:
    def __init__(self, backend): self.backend = backend; self.closed = False
    def close(self): self.closed = True
    def send(self, message):
        b = self.backend
        parsed = decode_packet(bytes(message.bytes()))
        op, p = parsed['opcode'], parsed['payload']
        if op == 0x11 or op == 0x23 and int.from_bytes(p[1:5], 'little') == 0x2100:
            b.original_output.send(message)
            return
        region = p[0]; address = int.from_bytes(p[1:5], 'little')
        b.commands.append((op, region, address, p))
        if op == 0x21:
            b.flash[address:address+4096] = b'\xff'*4096
            response = encode_packet(0, b'\0')
        elif op == 0x24:
            n = int.from_bytes(p[5:9], 'little')
            checksum = sum(b.ram[address:address+n])&65535
            response = encode_packet(op, p+checksum.to_bytes(2, 'little'))
        else:
            n = int.from_bytes(p[5:8], 'little')
            if region == 5:
                storage = b.live if address & 0x80000000 else b.presets
                start = address & 0x7fffffff
            elif region == 4: storage, start = b.ram, address
            else: storage, start = b.flash, address
            if op == 0x23:
                response = encode_packet(op, p+bytes(storage[start:start+n]))
            elif op == 0x22:
                storage[start:start+n] = p[8:]
                response = encode_packet(0, b'\0')
            else: raise AssertionError(op)
        b.input.messages.append(mido.Message.from_bytes(response))


class Backend(OldBackend):
    def __init__(self):
        super().__init__()
        self.original_output = self.output
        self.output = Output(self)
        self.presets = bytearray(FACTORY_PRESETS)
        self.live = bytearray(self.presets)
        self.flash = bytearray(0x80000)
        for i in range(8): self.flash[0x69000+i*4096:0x6a000+i*4096] = SECTOR
        self.ram = bytearray(8192)
        self.commands = []


class SuiteTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls): cls.app = QApplication.instance() or QApplication([])
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.clock = [0.]
        self.backend = Backend()
        self.patches = [
            patch.dict('os.environ', {'CUBEBABY_UI_SETTINGS': str(Path(self.tmp.name)/'ui.ini')}),
            patch('cubebaby_mod.gui.enumerate_ports', return_value=(self.backend, [PORT], [PORT])),
            patch('cubebaby_mod.gui.time.monotonic', side_effect=lambda: self.clock[0]),
            patch('cubebaby_mod.suite_gui.save_backup', side_effect=lambda directory,a,s,data: save_backup(self.tmp.name,a,s,data)),
        ]
        for p in self.patches: p.start()
        self.w = SuiteWindow()
        self.w.connect_device()
        self.finish()
    def tearDown(self):
        self.w.stop(); self.w.close()
        self.w.deleteLater()
        QCoreApplication.sendPostedEvents(None,QEvent.DeferredDelete)
        for p in reversed(self.patches): p.stop()
        self.tmp.cleanup()
    def finish(self):
        for _ in range(600):
            self.w.poll(); self.clock[0] += .11
            if self.w.pending is None and self.w.ir_writer is None and self.w.memory_job is None and self.w.factory_queue is None and not self.w.effect_queue:
                return
        self.fail('Operation did not finish')

    def test_connect_automatically_reads_info_effects_loopback_without_writing(self):
        self.assertEqual(self.w.preset_data, FACTORY_PRESETS)
        self.assertTrue(self.w.effect_controls[5][0].isEnabled())
        self.assertFalse(self.w.loopback.isChecked())
        self.assertTrue(all(op == 0x23 for op,_,_,_ in self.backend.commands))

    def test_live_edit_targets_selected_record_then_save_reads_back(self):
        self.w.preset_selector.setCurrentIndex(1)
        self.w.change_effect(5, 100)
        self.assertFalse(self.w.connect_button.isEnabled())
        self.finish()
        self.assertEqual(self.backend.live[21], 100)
        self.assertEqual(self.backend.presets, FACTORY_PRESETS)
        self.w.save_presets(); self.finish()
        self.assertEqual(self.backend.presets[21], 100)
        self.assertIn('terverifikasi', self.w.status.text())
        self.assertEqual(self.backend.presets[:16], FACTORY_PRESETS[:16])

    def test_switches_enable_original_parameter_groups(self):
        self.w.change_effect(12, 0); self.finish()
        self.assertFalse(self.w.effect_controls[0][0].isEnabled())
        self.assertFalse(self.w.effect_controls[1][0].isEnabled())
        self.assertFalse(self.w.effect_controls[2][0].isEnabled())
        self.assertTrue(self.w.effect_controls[3][0].isEnabled())
        self.assertTrue(self.w.effect_controls[5][0].isEnabled())

    def test_loopback_write_only_targets_register(self):
        self.w.loopback.click(); self.finish()
        self.assertEqual(self.backend.flash[0x3000], 1)
        writes = [(r, a) for op,r,a,_ in self.backend.commands if op == 0x22]
        self.assertEqual(writes, [(0, 0x3000)])
        self.assertTrue(self.w.loopback_value)

    def test_wav_preview_and_distance_do_not_erase_or_write_flash(self):
        self.w.read_ir_slot(); self.finish()
        path = test_wav_ir.WavTests().wav(self.tmp.name, 2, 1, [32767, 16384, 0])
        self.w.open_wav(path); self.finish()
        self.assertTrue(self.w.preview_active)
        self.assertEqual(self.backend.ram[0x764], 1)
        self.assertEqual(self.backend.ram[0x768:0x768+2052], self.w.desired_record()[4:])
        self.assertEqual(self.w.desired_record()[:4], b'\0'*4)
        self.w.distance.setValue(70); self.w.preview_distance(); self.finish()
        self.assertEqual(self.backend.ram[0x768:0x76c], self.w.desired_record()[4:8])
        self.assertTrue(all(region != 0 for op,region,_,_ in self.backend.commands if op == 0x22))
        self.assertFalse(any(op == 0x21 for op,_,_,_ in self.backend.commands))

    def test_factory_reset_backs_up_and_verifies_all_eight_sectors(self):
        factory = (ASSETS/'factory/cubebaby-20230-ir.bin').read_bytes()
        with patch('cubebaby_mod.suite_gui.confirm_question', return_value=QMessageBox.Yes):
            self.w.reset_irs(); self.finish()
        self.assertEqual(self.backend.flash[0x69000:0x71000], factory)
        backups = list(Path(self.tmp.name).glob('*.json'))
        self.assertEqual(len(backups), 8)
        self.assertIn('Delapan slot', self.w.status.text())

    def test_disconnect_invalidates_cached_effects(self):
        self.w.connect_device()
        self.assertIsNone(self.w.preset_data)
        self.assertFalse(self.w.preset_save.isEnabled())

    def test_wav_can_preview_and_save_without_first_reading_a_slot(self):
        self.assertIsNone(self.w.ir_snapshot)
        self.w.ir_slot.setCurrentIndex(4)
        path = test_wav_ir.WavTests().wav(self.tmp.name, 2, 1, [32767, -16384, 0])
        self.w.open_wav(path); self.finish()
        desired = self.w.desired_record()
        self.assertTrue(self.w.save_button.isEnabled())
        self.w.save_ir(); self.finish()
        base = 0x69000+4*4096
        self.assertEqual(self.backend.flash[base:base+2056], desired)
        self.assertEqual(self.backend.flash[base+2056:base+4096], SECTOR[2056:])
        self.assertEqual(len(list(Path(self.tmp.name).glob('*.json'))), 1)
        self.assertIsNone(self.w.wav_source)
        self.assertEqual(self.w.ir_snapshot['slot'], 5)

    def test_memory_timeout_does_not_claim_effect_saved_or_retry(self):
        self.w.change_effect(5, 100)
        self.backend.input.messages.clear()
        count = len(self.backend.commands)
        self.clock[0] += 11
        self.w.poll()
        self.assertIsNone(self.w.identity)
        self.assertIsNone(self.w.preset_data)
        self.assertIn('batas waktu', self.w.status.text())
        self.assertEqual(len(self.backend.commands), count)

    def test_preview_does_not_depend_on_ram_checksum_responses(self):
        self.w.read_ir_slot(); self.finish()
        self.w.preview_ir()
        original_send = self.backend.output.send
        def corrupt(message):
            original_send(message)
            parsed = decode_packet(bytes(message.bytes()))
            if parsed['opcode'] == 0x24:
                self.backend.input.messages.pop()
        self.backend.output.send = corrupt
        self.finish()
        self.assertIsNotNone(self.w.identity)
        self.assertTrue(self.w.preview_active)
        writes = [p[8:] for op,r,a,p in self.backend.commands if op == 0x22 and r == 4 and a == 0x764]
        self.assertEqual(writes, [b'\0', b'\1'])
        self.assertFalse(any(op == 0x24 for op,r,a,p in self.backend.commands))

    def test_factory_effects_restores_exact_original_constants(self):
        self.w.change_effect(0, 1); self.finish()
        self.w.save_presets(); self.finish()
        with patch('cubebaby_mod.suite_gui.confirm_question', return_value=QMessageBox.Yes):
            self.w.reset_presets(); self.finish()
        self.assertEqual(self.backend.presets, FACTORY_PRESETS)

    def test_preset_read_rejects_out_of_range_layout_before_any_write(self):
        self.backend.presets[0] = 255
        self.w.read_presets(); self.finish()
        self.assertIsNone(self.w.preset_data)
        self.assertFalse(self.w.preset_save.isEnabled())
        self.assertFalse(any(op == 0x22 for op,_,_,_ in self.backend.commands))

    def test_dragging_effect_sends_live_and_keeps_latest_value_while_ack_pending(self):
        slider, spin = self.w.effect_controls[5]
        slider.setValue(90)
        self.assertIsNotNone(self.w.pending)
        self.assertTrue(slider.isEnabled())
        slider.setValue(91)
        slider.setValue(92)
        self.assertFalse(self.w.preset_save.isEnabled())
        self.finish()
        self.assertEqual(self.backend.live[5], 92)
        self.assertEqual(self.w.preset_data[5], 92)
        self.assertEqual(spin.value(), 92)
        writes = [(a,p[8:]) for op,r,a,p in self.backend.commands if op == 0x22 and r == 5]
        self.assertEqual(writes, [(0x80000005,b'\x5a'), (0x80000005,b'\x5c')])
        self.assertTrue(self.w.preset_save.isEnabled())

    def test_queued_live_changes_remain_bound_to_their_preset(self):
        self.w.effect_controls[5][1].setValue(90)
        self.w.preset_selector.setCurrentIndex(2)
        self.w.effect_controls[5][1].setValue(95)
        self.finish()
        self.assertEqual(self.backend.live[5], 90)
        self.assertEqual(self.backend.live[37], 95)
        self.assertEqual(self.backend.live[21], FACTORY_PRESETS[21])

    def test_live_burst_respects_40ms_interval_and_keeps_last_value(self):
        self.w.change_effect(5, 90)
        self.w.poll()
        self.w.change_effect(5, 91)
        self.w.change_effect(5, 92)
        writes = lambda: [(a, p[8:]) for op, r, a, p in self.backend.commands if op == 0x22 and r == 5]
        self.assertEqual(writes(), [(0x80000005, b'\x5a')])
        self.clock[0] += .039
        self.w.poll()
        self.assertEqual(len(writes()), 1)
        self.clock[0] += .002
        self.w.poll()
        self.finish()
        self.assertEqual(writes(), [(0x80000005, b'\x5a'), (0x80000005, b'\x5c')])

    def test_multiple_wavs_are_listed_and_single_click_previews_selected_file(self):
        first = test_wav_ir.WavTests().wav(self.tmp.name, 2, 1, [32767])
        second = Path(self.tmp.name)/'second.wav'
        second.write_bytes(first.read_bytes())
        with patch('cubebaby_mod.suite_gui.QFileDialog.getOpenFileNames',
                   return_value=([str(first), str(second)], 'WAV')):
            self.w.choose_wav()
        self.assertEqual(self.w.wav_list.count(), 2)
        self.assertIsNone(self.w.wav_source)
        self.w.wav_list.itemClicked.emit(self.w.wav_list.item(1))
        self.finish()
        self.assertTrue(self.w.preview_active)
        self.assertIn('second.wav', self.w.wav_label.text())

    def test_distance_edit_on_stored_slot_never_implicitly_uploads_ir(self):
        self.w.read_ir_slot(); self.finish()
        before = len(self.backend.commands)
        self.w.distance.setValue(70)
        self.w.preview_distance(); self.finish()
        self.assertFalse(self.w.preview_active)
        self.assertEqual(len(self.backend.commands), before)
        self.assertTrue(self.w.save_button.isEnabled())

    def prepare_distance_preview(self):
        path = test_wav_ir.WavTests().wav(self.tmp.name, 2, 1, [32767, -1000, 250])
        self.w.open_wav(path); self.finish()
        self.assertTrue(self.w.preview_active)
        return bytes(self.backend.ram[0x76c:0x76c+2048])

    def test_distance_update_keeps_coefficients_and_finishes_with_activation_command(self):
        coefficients = self.prepare_distance_preview()
        self.backend.ram[0x764] = 0
        self.w.distance.setValue(70); self.w.preview_distance(); self.finish()
        self.assertEqual(self.backend.ram[0x764], 1)
        self.assertEqual(bytes(self.backend.ram[0x76c:0x76c+2048]), coefficients)
        self.assertIn('aktivasi IR diterima', self.w.status.text())

    def test_distance_rejected_ack_restores_ir_before_reporting_error(self):
        coefficients = self.prepare_distance_preview()
        original_send = self.backend.output.send
        def reject_distance(message):
            original_send(message)
            parsed = decode_packet(bytes(message.bytes()))
            p = parsed['payload']
            if parsed['opcode'] == 0x22 and p[0] == 4 and int.from_bytes(p[1:5], 'little') == 0x768:
                self.backend.input.messages[-1] = mido.Message.from_bytes(encode_packet(0, b'\1'))
        self.backend.output.send = reject_distance
        before = len(self.backend.commands)
        self.w.distance.setValue(70); self.w.preview_distance(); self.finish()
        self.assertEqual(self.backend.ram[0x764], 1)
        self.assertEqual(bytes(self.backend.ram[0x76c:0x76c+2048]), coefficients)
        self.assertIn('aktivasi IR diterima kembali', self.w.status.text())
        self.assertIsNone(self.w.identity)
        self.assertTrue(all(a in (0x764, 0x768) and len(p[8:]) <= 4
                            for op,r,a,p in self.backend.commands[before:] if op == 0x22))

    def test_distance_timeout_restores_gate_without_retrying_distance(self):
        coefficients = self.prepare_distance_preview()
        original_send = self.backend.output.send
        def drop_distance_ack(message):
            original_send(message)
            parsed = decode_packet(bytes(message.bytes()))
            p = parsed['payload']
            if parsed['opcode'] == 0x22 and int.from_bytes(p[1:5], 'little') == 0x768:
                self.backend.input.messages.pop()
        self.backend.output.send = drop_distance_ack
        before = len(self.backend.commands)
        self.w.distance.setValue(70); self.w.preview_distance(); self.w.poll()
        self.assertEqual(self.backend.ram[0x764], 0)
        self.clock[0] += 11
        self.w.poll(); self.finish()
        self.assertEqual(self.backend.ram[0x764], 1)
        self.assertEqual(bytes(self.backend.ram[0x76c:0x76c+2048]), coefficients)
        writes = [(a, p[8:]) for op,r,a,p in self.backend.commands[before:] if op == 0x22]
        self.assertEqual([a for a,p in writes], [0x764, 0x768, 0x764])
        self.assertIn('batas waktu', self.w.status.text())
        self.assertIn('aktivasi IR diterima kembali', self.w.status.text())

    def test_unchanged_distance_focus_event_does_not_send_ir_commands(self):
        self.prepare_distance_preview()
        before = len(self.backend.commands)
        self.w.preview_distance(); self.finish()
        self.assertEqual(len(self.backend.commands), before)

    def test_non_boolean_control_does_not_block_distance_or_change_coefficients(self):
        coefficients = self.prepare_distance_preview()
        self.backend.ram[0x764] = 255
        before = len(self.backend.commands)
        self.w.distance.setValue(70); self.w.preview_distance(); self.finish()
        self.assertIsNotNone(self.w.identity)
        self.assertEqual(bytes(self.backend.ram[0x76c:0x76c+2048]), coefficients)
        writes = [p[8:] for op,r,a,p in self.backend.commands[before:] if op == 0x22 and a == 0x764]
        self.assertEqual(writes, [b'\0', b'\1'])
        self.assertIn('Distance RAM terverifikasi', self.w.status.text())

    def test_failed_distance_gate_recovery_stops_once_and_reports_uncertainty(self):
        coefficients = self.prepare_distance_preview()
        original_send = self.backend.output.send
        def reject_update_and_restore(message):
            original_send(message)
            parsed = decode_packet(bytes(message.bytes()))
            p = parsed['payload']
            if parsed['opcode'] == 0x22 and (int.from_bytes(p[1:5], 'little') == 0x768 or
                                           int.from_bytes(p[1:5], 'little') == 0x764 and p[8:] == b'\1'):
                self.backend.input.messages[-1] = mido.Message.from_bytes(encode_packet(0, b'\1'))
        self.backend.output.send = reject_update_and_restore
        before = len(self.backend.commands)
        self.w.distance.setValue(70); self.w.preview_distance(); self.finish()
        writes = [(a, p[8:]) for op,r,a,p in self.backend.commands[before:] if op == 0x22]
        self.assertEqual([a for a,p in writes], [0x764, 0x768, 0x764])
        self.assertEqual(bytes(self.backend.ram[0x76c:0x76c+2048]), coefficients)
        self.assertIn('belum dapat dipastikan', self.w.status.text())
        self.assertNotIn('berhasil dipulihkan', self.w.status.text())

    def test_preview_preflight_timeout_never_disables_or_writes_ir(self):
        self.w.read_ir_slot(); self.finish()
        self.backend.ram[0x764] = 1
        before = len(self.backend.commands)
        self.w.preview_ir()
        self.backend.input.messages.clear()
        self.clock[0] += 3
        self.w.poll()
        self.assertEqual(self.backend.ram[0x764], 1)
        self.assertFalse(any(op == 0x22 for op,r,a,p in self.backend.commands[before:]))
        self.assertIn('region 4', self.w.status.text())
        self.assertIn('0x00000764', self.w.status.text())

    def test_preview_partial_upload_timeout_rolls_back_entire_original_ram(self):
        self.w.read_ir_slot(); self.finish()
        self.backend.ram[0x764] = 1
        original = bytes((i*17+3)%256 for i in range(2052))
        self.backend.ram[0x768:0x768+2052] = original
        original_send = self.backend.output.send
        dropped = []
        def drop_one_ack(message):
            original_send(message)
            parsed = decode_packet(bytes(message.bytes())); p = parsed['payload']
            if (not dropped and parsed['opcode'] == 0x22 and
                    int.from_bytes(p[1:5], 'little') == 0x7e8):
                self.backend.input.messages.pop(); dropped.append(True)
        self.backend.output.send = drop_one_ack
        self.w.preview_ir(); self.w.poll()
        self.assertTrue(dropped)
        self.assertEqual(self.backend.ram[0x764], 0)
        self.clock[0] += 11
        self.w.poll(); self.finish()
        self.assertEqual(self.backend.ram[0x764], 1)
        self.assertEqual(bytes(self.backend.ram[0x768:0x768+2052]), original)
        self.assertIn('berhasil dipulihkan', self.w.status.text())
        self.assertIn('0x000007E8', self.w.status.text())
        self.assertFalse(self.w.preview_active)
        self.assertFalse(any(op == 0x21 for op,r,a,p in self.backend.commands))

    def test_preview_verification_mismatch_restores_original_ir_and_issues_activation(self):
        self.w.read_ir_slot(); self.finish()
        original = bytes((i*7+5)%256 for i in range(2052))
        self.backend.ram[0x768:0x768+2052] = original
        original_send = self.backend.output.send
        corrupted = []
        def corrupt_once(message):
            original_send(message)
            parsed = decode_packet(bytes(message.bytes())); p = parsed['payload']
            if (not corrupted and parsed['opcode'] == 0x23 and
                    int.from_bytes(p[1:5], 'little') == 0x768 and
                    self.w.memory_job.phase == 'upload'):
                response = decode_packet(bytes(self.backend.input.messages[-1].bytes()))
                data = bytearray(response['payload']); data[-1] ^= 1
                self.backend.input.messages[-1] = mido.Message.from_bytes(encode_packet(0x23, bytes(data)))
                corrupted.append(True)
        self.backend.output.send = corrupt_once
        self.w.preview_ir(); self.finish()
        self.assertTrue(corrupted)
        self.assertEqual(self.backend.ram[0x764], 1)
        self.assertEqual(bytes(self.backend.ram[0x768:0x768+2052]), original)
        self.assertIn('Verifikasi gagal', self.w.status.text())
        self.assertIn('berhasil dipulihkan', self.w.status.text())

    def test_preview_failed_rollback_reports_uncertain_state_without_retry_loop(self):
        self.w.read_ir_slot(); self.finish()
        self.backend.ram[0x764] = 1
        original_send = self.backend.output.send
        def reject_data(message):
            original_send(message)
            parsed = decode_packet(bytes(message.bytes())); p = parsed['payload']
            if parsed['opcode'] == 0x22 and int.from_bytes(p[1:5], 'little') == 0x768:
                self.backend.input.messages[-1] = mido.Message.from_bytes(encode_packet(0, b'\1'))
        self.backend.output.send = reject_data
        self.w.preview_ir(); self.finish()
        self.assertIn('Pemulihan IR juga gagal', self.w.status.text())
        self.assertNotIn('berhasil dipulihkan', self.w.status.text())
        data_writes = [a for op,r,a,p in self.backend.commands if op == 0x22 and a == 0x768]
        self.assertEqual(len(data_writes), 2)

    def test_preview_gate_close_rejection_restores_gate_without_writing_coefficients(self):
        self.w.read_ir_slot(); self.finish()
        self.backend.ram[0x764] = 1
        original_send = self.backend.output.send
        rejected = []
        def reject_gate_once(message):
            original_send(message)
            parsed = decode_packet(bytes(message.bytes())); p = parsed['payload']
            if not rejected and parsed['opcode'] == 0x22 and p[8:] == b'\0':
                self.backend.input.messages[-1] = mido.Message.from_bytes(encode_packet(0, b'\1'))
                rejected.append(True)
        self.backend.output.send = reject_gate_once
        before = len(self.backend.commands)
        self.w.preview_ir(); self.finish()
        self.assertEqual(self.backend.ram[0x764], 1)
        self.assertTrue(all(a == 0x764 for op,r,a,p in self.backend.commands[before:] if op == 0x22))
        self.assertIn('berhasil dipulihkan', self.w.status.text())

    def install_self_clearing_control(self):
        original_send = self.backend.output.send
        def control_clears_after_command(message):
            original_send(message)
            parsed = decode_packet(bytes(message.bytes())); p = parsed['payload']
            if (parsed['opcode'] == 0x22 and p[0] == 4 and
                    int.from_bytes(p[1:5], 'little') == 0x764 and p[8:] == b'\1'):
                self.backend.ram[0x764] = 0
        self.backend.output.send = control_clears_after_command

    def test_preview_control_readback_zero_does_not_rollback_verified_ir(self):
        self.install_self_clearing_control()
        self.w.read_ir_slot(); self.finish()
        desired = self.w.desired_record()[4:]
        before = len(self.backend.commands)
        self.w.preview_ir(); self.finish()
        self.assertEqual(self.backend.ram[0x764], 0)
        self.assertEqual(bytes(self.backend.ram[0x768:0x768+2052]), desired)
        self.assertTrue(self.w.preview_active)
        self.assertIsNotNone(self.w.identity)
        self.assertIn('terverifikasi', self.w.status.text())
        control_writes = [p[8:] for op,r,a,p in self.backend.commands[before:] if op == 0x22 and a == 0x764]
        self.assertEqual(control_writes, [b'\0', b'\1'])
        self.assertTrue(any('Byte kontrol terbaca: 00' in r.get('message', '') for r in self.w.records))

    def test_distance_control_readback_zero_is_not_treated_as_disabled_ir(self):
        self.install_self_clearing_control()
        coefficients = self.prepare_distance_preview()
        before = len(self.backend.commands)
        self.w.distance.setValue(70); self.w.preview_distance(); self.finish()
        self.assertIsNotNone(self.w.identity)
        self.assertTrue(self.w.preview_active)
        self.assertEqual(self.backend.ram[0x764], 0)
        self.assertEqual(bytes(self.backend.ram[0x76c:0x76c+2048]), coefficients)
        control_writes = [p[8:] for op,r,a,p in self.backend.commands[before:] if op == 0x22 and a == 0x764]
        self.assertEqual(control_writes, [b'\0', b'\1'])
        self.assertIn('Distance RAM terverifikasi', self.w.status.text())

    def test_preview_accepts_non_boolean_control_before_and_after_upload(self):
        self.w.read_ir_slot(); self.finish()
        desired = self.w.desired_record()[4:]
        self.backend.ram[0x764] = 255
        original_send = self.backend.output.send
        def observed_control_is_not_boolean(message):
            original_send(message)
            parsed = decode_packet(bytes(message.bytes())); p = parsed['payload']
            if parsed['opcode'] == 0x22 and int.from_bytes(p[1:5], 'little') == 0x764:
                self.backend.ram[0x764] = 255
        self.backend.output.send = observed_control_is_not_boolean
        self.w.preview_ir(); self.finish()
        self.assertTrue(self.w.preview_active)
        self.assertIsNotNone(self.w.identity)
        self.assertEqual(bytes(self.backend.ram[0x768:0x768+2052]), desired)
        self.assertTrue(any('Byte kontrol terbaca: ff' in r.get('message', '') for r in self.w.records))
