import unittest
from unittest.mock import patch
import mido
from PySide6.QtWidgets import QApplication
from cubebaby_mod.midi import message_record
from cubebaby_mod.gui import Window


class FakePort:
    def __init__(self):
        self.messages = [mido.Message('sysex', data=[0, 0x21, 0x10, 1])]
        self.closed = False
    def poll(self):
        return self.messages.pop(0) if self.messages else None
    def close(self):
        self.closed = True


class FakeBackend:
    def __init__(self):
        self.input = FakePort()
        self.opened = []
    def open_input(self, name):
        self.opened.append(name)
        return self.input
    def open_output(self, *args):
        raise AssertionError('Passive monitor must never open an output port')


class MonitorTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.app = QApplication.instance() or QApplication([])

    def test_sysex_log_preserves_framing(self):
        row = message_record(mido.Message('sysex', data=[0, 0x21, 0x10, 1]))
        self.assertEqual(row['hex'], 'F0 00 21 10 01 F7')
        self.assertEqual(row['direction'], 'in')

    def test_receive_without_output_and_close(self):
        backend = FakeBackend()
        with patch('cubebaby_mod.gui.enumerate_ports', return_value=(backend, ['USB2.0 Device'], ['USB2.0 Device'])):
            w = Window()
            w.toggle_monitor()
            w.poll()
            received = [r for r in w.records if r['direction'] == 'in']
            self.assertEqual(len(received), 1)
            self.assertEqual(received[0]['type'], 'sysex')
            self.assertEqual(backend.opened, ['USB2.0 Device'])
            w.stop()
            self.assertTrue(backend.input.closed)
            w.close()

    def test_unplug_stops_monitor(self):
        backend = FakeBackend()
        with patch('cubebaby_mod.gui.enumerate_ports', return_value=(backend, ['USB2.0 Device'], [])):
            w = Window()
            w.toggle_monitor()
            with patch.object(backend.input, 'poll', side_effect=OSError('disconnected')):
                w.poll()
            self.assertIsNone(w.port)
            self.assertFalse(w.timer.isActive())
            self.assertIn('disconnected', w.status.text())
            w.close()

    def test_backend_failure_is_visible(self):
        with patch('cubebaby_mod.gui.enumerate_ports', side_effect=RuntimeError('no ALSA')):
            w = Window()
            self.assertFalse(w.toggle.isEnabled())
            self.assertIn('no ALSA', w.status.text())
            w.close()


if __name__ == '__main__':
    unittest.main()
