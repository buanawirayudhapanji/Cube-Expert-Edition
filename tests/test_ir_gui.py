import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch
import mido
from PySide6.QtWidgets import QApplication
from cubebaby_mod.gui import Window
from cubebaby_mod.protocol import encode_packet
from test_connection import Backend, PORT, IDENTITY
from test_ir_reader import INFO_PACKET, SLOT_DATA, respond


class IRGuiTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls): cls.app = QApplication.instance() or QApplication([])

    def setUp(self):
        self.backend = Backend()
        self.patcher = patch('cubebaby_mod.gui.enumerate_ports', return_value=(self.backend, [PORT], [PORT]))
        self.patcher.start()
        self.w = Window()
        self.w.connect_device()
        self.backend.input.messages.append(mido.Message.from_bytes(IDENTITY)); self.w.poll()
        self.w.read_device_info()
        self.backend.input.messages.append(mido.Message.from_bytes(INFO_PACKET)); self.w.poll()

    def tearDown(self):
        self.w.close(); self.patcher.stop()

    def finish_slot(self):
        while self.w.ir_reader is not None:
            packet = respond(self.w.ir_reader)
            self.backend.input.messages.append(mido.Message.from_bytes(encode_packet(packet['opcode'], packet['payload'])))
            self.w.poll()

    def test_slot_read_and_json_export(self):
        self.assertTrue(self.w.ir_button.isEnabled())
        self.w.ir_slot.setCurrentIndex(1)
        self.w.read_ir_slot()
        self.assertFalse(self.w.ir_button.isEnabled())
        self.assertFalse(self.w.ir_slot.isEnabled())
        self.finish_slot()
        self.assertIsNone(self.w.pending)
        self.assertEqual(self.w.ir_snapshot['slot'], 2)
        self.assertIn('50.00', self.w.ir_status.text())
        self.assertTrue(self.w.ir_export_button.isEnabled())
        self.assertEqual(len(self.backend.output.sent), 21)  # identity + info + 19 chunks
        with tempfile.TemporaryDirectory() as tmp:
            path = str(Path(tmp)/'slot.json')
            with patch('cubebaby_mod.gui.QFileDialog.getSaveFileName', return_value=(path, 'JSON')):
                self.w.export_ir()
            saved = json.loads(Path(path).read_text())
        self.assertEqual(saved['device_code'], 20230)
        self.assertEqual(saved['address'], 0x6a000)
        self.assertEqual(bytes.fromhex(saved['raw_hex']), SLOT_DATA)
        self.assertEqual(len(saved['coefficients']), 512)

    def test_timeout_discards_partial_read_and_retry_starts_at_zero(self):
        self.w.read_ir_slot()
        packet = respond(self.w.ir_reader)
        self.backend.input.messages.append(mido.Message.from_bytes(encode_packet(packet['opcode'], packet['payload'])))
        self.w.poll()
        self.assertEqual(len(self.w.ir_reader.buffer), 113)
        deadline = self.w.pending[1]
        with patch('cubebaby_mod.gui.time.monotonic', return_value=deadline+1): self.w.poll()
        self.assertIsNone(self.w.ir_reader)
        self.assertIsNone(self.w.ir_snapshot)
        self.assertFalse(self.w.ir_export_button.isEnabled())
        self.assertTrue(self.w.ir_button.isEnabled())
        self.assertIsNotNone(self.w.identity)
        self.w.read_ir_slot()
        self.assertEqual(len(self.w.ir_reader.buffer), 0)

    def test_disconnect_mid_read_cancels_sequence(self):
        self.w.read_ir_slot()
        count = len(self.backend.output.sent)
        self.w.connect_device()  # Disconnect.
        self.w.poll()
        self.assertIsNone(self.w.ir_reader)
        self.assertIsNone(self.w.pending)
        self.assertIsNone(self.w.ir_snapshot)
        self.assertFalse(self.w.ir_button.isEnabled())
        self.assertEqual(len(self.backend.output.sent), count)
        self.assertTrue(self.backend.input.closed and self.backend.output.closed)

    def test_wrong_address_or_double_click_does_not_send_next_chunk(self):
        self.w.read_ir_slot()
        count = len(self.backend.output.sent)
        self.w.read_ir_slot()
        packet = respond(self.w.ir_reader, wrong_address=True)
        self.backend.input.messages.append(mido.Message.from_bytes(encode_packet(packet['opcode'], packet['payload'])))
        self.w.poll()
        self.assertEqual(len(self.backend.output.sent), count)
        self.assertEqual(len(self.w.ir_reader.buffer), 0)

    def test_export_does_nothing_before_complete_read(self):
        with patch('cubebaby_mod.gui.QFileDialog.getSaveFileName') as dialog:
            self.w.export_ir()
        dialog.assert_not_called()
