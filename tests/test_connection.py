from pathlib import Path
import unittest
from unittest.mock import patch
import mido
from PySide6.QtWidgets import QApplication
from PySide6.QtCore import QCoreApplication, QEvent
from cubebaby_mod.gui import Window
from cubebaby_mod.protocol import (
    decode_packet, encode_packet, parse_identity, identity_request,
    device_info_request, parse_device_info,
)

IDENTITY = bytes.fromhex((Path(__file__).parent/'fixtures/identity_response.hex').read_text())
PORT = 'USB2.0 Device:USB2.0 Device MIDI 1 24:0'


class Port:
    def __init__(self):
        self.messages = []
        self.sent = []
        self.closed = False
    def send(self, message): self.sent.append(bytes(message.bytes()))
    def poll(self): return self.messages.pop(0) if self.messages else None
    def close(self): self.closed = True


class Backend:
    def __init__(self):
        self.input = Port()
        self.output = Port()
    def open_input(self, name): return self.input
    def open_output(self, name): return self.output


def info_response(address=0x2100):
    data = b''.join(v.to_bytes(4, 'little') for v in [123, 10030, 0x100, 0x200, 0x300])
    return encode_packet(0x23, b'\x00'+address.to_bytes(4, 'little')+b'\x14\0\0'+data)


class ConnectionTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.app = QApplication.instance() or QApplication([])

    def setUp(self):
        self.backend = Backend()
        self.patcher = patch('cubebaby_mod.gui.enumerate_ports', return_value=(self.backend, [PORT], [PORT]))
        self.patcher.start()
        self.w = Window()

    def tearDown(self):
        self.w.close()
        self.w.deleteLater()
        QCoreApplication.sendPostedEvents(None,QEvent.DeferredDelete)
        self.patcher.stop()

    def connect(self):
        self.w.connect_device()
        self.backend.input.messages.append(mido.Message.from_bytes(IDENTITY))
        self.w.poll()

    def test_real_user_packet_identity(self):
        self.assertEqual(parse_identity(decode_packet(IDENTITY))['name'], 'SINCO-CubeBaby')

    def test_connect_is_nonblocking_and_logs_both_directions(self):
        self.w.connect_device()
        self.assertIsNotNone(self.w.pending)
        self.assertIsNone(self.w.identity)
        self.assertEqual(self.backend.output.sent, [identity_request()])
        self.backend.input.messages.append(mido.Message.from_bytes(IDENTITY))
        self.w.poll()
        self.assertIsNone(self.w.pending)
        self.assertEqual(self.w.identity['name'], 'SINCO-CubeBaby')
        self.assertTrue(self.w.info_button.isEnabled())
        self.assertIn('SINCO-CubeBaby', self.w.device_label.text())
        self.assertTrue({'in', 'out', 'event'} <= {r['direction'] for r in self.w.records})
        self.assertFalse(self.w.toggle.isEnabled())

    def test_query_echo_does_not_mark_connected(self):
        self.w.connect_device()
        self.backend.input.messages.append(mido.Message.from_bytes(identity_request()))
        self.w.poll()
        self.assertIsNone(self.w.identity)
        self.assertFalse(self.w.info_button.isEnabled())
        self.assertIsNotNone(self.w.pending)

    def test_timeout_closes_ports_and_reports_reason(self):
        with patch('cubebaby_mod.gui.time.monotonic', return_value=10):
            self.w.connect_device()
        with patch('cubebaby_mod.gui.time.monotonic', return_value=13):
            self.w.poll()
        self.assertTrue(self.backend.input.closed and self.backend.output.closed)
        self.assertIsNone(self.w.pending)
        self.assertIn('2 detik', self.w.status.text())
        self.assertEqual(len(self.backend.output.sent), 1)

    def test_read_info_matches_region_address_and_length(self):
        self.connect()
        self.w.read_device_info()
        self.w.read_device_info()  # No duplicate during an outstanding request.
        self.assertEqual(self.backend.output.sent, [identity_request(), device_info_request()])
        self.backend.input.messages.append(mido.Message.from_bytes(info_response(0x2200)))
        self.w.poll()
        self.assertIsNone(self.w.device_info)
        self.assertIsNotNone(self.w.pending)
        self.backend.input.messages.append(mido.Message.from_bytes(info_response()))
        self.w.poll()
        self.assertEqual(self.w.device_info['device_code'], 10030)
        self.assertIsNone(self.w.pending)
        self.assertIn('Cube Baby', self.w.device_label.text())

    def test_read_timeout_keeps_identity_and_allows_retry(self):
        self.connect()
        with patch('cubebaby_mod.gui.time.monotonic', return_value=10):
            self.w.read_device_info()
        with patch('cubebaby_mod.gui.time.monotonic', return_value=13):
            self.w.poll()
        self.assertIsNotNone(self.w.identity)
        self.assertTrue(self.w.info_button.isEnabled())
        self.assertFalse(self.backend.output.closed)

    def test_partial_open_failure_closes_input(self):
        with patch.object(self.backend, 'open_output', side_effect=OSError('output busy')):
            self.w.connect_device()
        self.assertTrue(self.backend.input.closed)
        self.assertIsNone(self.w.port)
        self.assertIsNone(self.w.output_port)
        self.assertIn('output busy', self.w.status.text())

    def test_disconnect_then_reconnect_starts_clean(self):
        self.connect()
        self.w.connect_device()
        self.assertIsNone(self.w.identity)
        self.assertIsNone(self.w.pending)
        self.assertFalse(self.w.info_button.isEnabled())
        self.assertTrue(self.backend.input.closed and self.backend.output.closed)
        self.assertTrue(self.w.ports.isEnabled())

    def test_read_query_does_not_contain_write_opcode(self):
        packet = decode_packet(device_info_request())
        self.assertEqual(packet['opcode'], 0x23)
        self.assertEqual(packet['payload'], bytes.fromhex('00 00 21 00 00 14 00 00'))

    def test_bad_read_length_is_rejected(self):
        packet = decode_packet(info_response())
        packet['payload'] = packet['payload'][:-1]
        with self.assertRaises(ValueError): parse_device_info(packet)

    def test_unknown_identity_cannot_read_config(self):
        self.w.connect_device()
        unknown = encode_packet(0x11, b'Other Pedal'.ljust(16, b' ')+bytes(11))
        self.backend.input.messages.append(mido.Message.from_bytes(unknown))
        self.w.poll()
        self.assertIsNotNone(self.w.identity)
        self.assertFalse(self.w.info_button.isEnabled())
        self.w.read_device_info()
        self.assertEqual(len(self.backend.output.sent), 1)

    def test_missing_matching_output_requires_selection(self):
        with patch('cubebaby_mod.gui.enumerate_ports',
                   return_value=(self.backend, [PORT], ['Midi Through:Midi Through Port-0 14:0'])):
            self.w.refresh()
        self.assertEqual(self.w.outputs.currentIndex(), -1)
        self.assertFalse(self.w.connect_button.isEnabled())
