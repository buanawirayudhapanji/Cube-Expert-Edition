import math
import struct
import unittest
from types import SimpleNamespace
from unittest.mock import patch
from PySide6.QtCore import QObject, Signal
from PySide6.QtWidgets import QApplication
from cubebaby_mod.audio_meter import PCMLevels, AudioMeter, AudioInputBuffer


class LevelsTests(unittest.TestCase):
    def test_capture_destination_preserves_all_binary_bytes_across_drains(self):
        buffer=AudioInputBuffer()
        raw=bytes(range(256))*4
        self.assertEqual(buffer.write(raw),len(raw))
        self.assertEqual(buffer.take(),raw)
        self.assertEqual(buffer.take(),b'')
        buffer.write(raw[::-1])
        self.assertEqual(buffer.take(),raw[::-1])
        buffer.close()

    def test_sine_peak_and_rms_are_dbfs_not_spl(self):
        data=struct.pack('=480f',*(.5*math.sin(2*math.pi*i/48) for i in range(480)))
        levels=PCMLevels('f32',1); levels.feed(data)
        peak,rms,clipped,frames=levels.take()
        self.assertAlmostEqual(peak,-6.0206,places=3)
        self.assertAlmostEqual(rms,-9.0309,places=3)
        self.assertFalse(clipped); self.assertEqual(frames,480)
        self.assertEqual(levels.take(),(-math.inf,-math.inf,False,0))

    def test_partial_stereo_frames_preserved_and_opposite_phases_do_not_cancel(self):
        levels=PCMLevels('s16',2)
        raw=struct.pack('=4h',16384,-16384,16384,-16384)
        levels.feed(raw[:3]); self.assertEqual(levels.take()[3],0)
        levels.feed(raw[3:]); peak,rms,clip,frames=levels.take()
        self.assertAlmostEqual(peak,-6.0206,places=3); self.assertAlmostEqual(rms,peak)
        self.assertEqual(frames,2); self.assertFalse(clip)

    def test_pcm_rails_silence_and_float_out_of_range(self):
        for kind,raw in [('u8',bytes([0,255])),('s16',struct.pack('=2h',-32768,32767)),
                         ('s32',struct.pack('=2i',-2147483648,2147483647)),('f32',struct.pack('=f',1.2))]:
            levels=PCMLevels(kind,1); levels.feed(raw); self.assertTrue(levels.take()[2])
        levels=PCMLevels('u8',1); levels.feed(bytes([128]*20))
        self.assertEqual(levels.take()[:3],(-math.inf,-math.inf,False))
        with self.assertRaises(ValueError): PCMLevels('f32',1).feed(struct.pack('=f',math.nan))
        with self.assertRaises(ValueError): PCMLevels('f32',0)


class Source(QObject):
    stateChanged=Signal(object)
    def __init__(self,*args): super().__init__(); self.closed=False; self.raw=struct.pack('=2f',1.,-.5)
    def start(self, device): device.write(self.raw); return None
    def readAll(self): raw,self.raw=self.raw,b''; return raw
    def error(self): return 0
    def stop(self): self.closed=True


class MeterTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls): cls.app=QApplication.instance() or QApplication([])
    def setUp(self):
        self.m=AudioMeter()
        fmt=SimpleNamespace(isValid=lambda:True,sampleFormat=lambda:4,channelCount=lambda:1,sampleRate=lambda:48000)
        self.device=SimpleNamespace(id=lambda:b'usb',description=lambda:'Cube audio',preferredFormat=lambda:fmt,isFormatSupported=lambda f:True)
        self.devices=[self.device]
        formats=SimpleNamespace(UInt8=1,Int16=2,Int32=3,Float=4)
        self.audio=SimpleNamespace(NoError=0,StoppedState=2)
        self.m.api=(Source,SimpleNamespace(audioInputs=lambda:self.devices),formats,self.audio)
        self.m.refresh_inputs()
    def tearDown(self): self.m.stop(); self.m.close(); self.m.deleteLater()

    def test_last_audio_choice_restores_without_starting_capture(self):
        import tempfile
        from pathlib import Path
        with tempfile.TemporaryDirectory() as tmp:
            with patch.dict('os.environ', {'CUBEBABY_UI_SETTINGS': str(Path(tmp) / 'ui.ini')}):
                second_device = SimpleNamespace(
                    id=lambda: b'interface2', description=lambda: 'Interface kedua',
                    preferredFormat=self.device.preferredFormat, isFormatSupported=lambda f: True)
                self.devices.append(second_device)
                self.m.refresh_inputs()
                self.m.inputs.setCurrentIndex(1)
                self.m.inputs.activated.emit(1)
                another = AudioMeter()
                try:
                    another.api = self.m.api
                    another.refresh_inputs()
                    self.assertEqual(another.inputs.currentIndex(), 1)
                    self.assertIsNone(another.source)
                finally:
                    another.stop()
                    another.deleteLater()

    def test_explicit_capture_peak_hold_reset_and_stop(self):
        self.assertIsNone(self.m.source); self.assertFalse(self.m.timer.isActive())
        self.m.toggle_monitor(); source=self.m.source
        self.assertTrue(self.m.timer.isActive()); self.m.tick()
        self.assertTrue(self.m.clip_hold); self.assertEqual(self.m.peak_hold,0.)
        self.assertIn('CLIP',self.m.status.text())
        self.m.reset_peak(); self.assertFalse(self.m.clip_hold)
        self.m.toggle_monitor(); self.assertTrue(source.closed); self.assertIsNone(self.m.source)
        self.assertFalse(self.m.timer.isActive()); self.assertEqual(self.m.bar.value(),0)

    def test_unplug_stops_capture_and_missing_inputs_disable_start(self):
        self.m.toggle_monitor(); source=self.m.source; self.devices.clear(); self.m.refresh_inputs()
        self.assertTrue(source.closed); self.assertIsNone(self.m.source)
        self.assertFalse(self.m.toggle.isEnabled())
        self.assertIn('Belum ada input',self.m.status.text())

    def test_open_failure_keeps_editor_usable_and_stops_timer(self):
        with patch.object(Source,'error',return_value=SimpleNamespace(name='OpenError')): self.m.toggle_monitor()
        self.assertIsNone(self.m.source); self.assertFalse(self.m.timer.isActive())
        self.assertTrue(self.m.refresh.isEnabled()); self.assertIn('tidak dapat dibuka',self.m.status.text())

    def test_real_qt_audio_enum_aliases_accept_success_and_handle_stopped_error(self):
        from PySide6.QtMultimedia import QAudio, QtAudio
        self.m.api=(*self.m.api[:3],QAudio)
        with patch.object(Source,'error',return_value=QtAudio.Error.NoError):
            self.m.toggle_monitor()
        self.assertIsNotNone(self.m.source)
        self.assertTrue(self.m.timer.isActive())
        self.m.tick()
        self.assertTrue(self.m.clip_hold)
        source=self.m.source
        with patch.object(Source,'error',return_value=QtAudio.Error.OpenError):
            self.m.audio_state(QtAudio.State.StoppedState)
        self.assertTrue(source.closed)
        self.assertIsNone(self.m.source)
        self.assertIn('OpenError',self.m.status.text())

    def test_open_failure_reports_device_format_and_backend_error_before_cleanup(self):
        error=SimpleNamespace(name='OpenError')
        with patch.object(Source,'error',return_value=error): self.m.toggle_monitor()
        self.assertIsNone(self.m.source)
        self.assertFalse(self.m.timer.isActive())
        for detail in ('Cube audio','OpenError','48000 Hz','PipeWire'):
            self.assertIn(detail,self.m.status.text())

    def test_bad_audio_stops_and_cleans_source(self):
        self.m.toggle_monitor(); source=self.m.source; self.m.stream.write(struct.pack('=f',math.nan))
        self.m.tick(); self.assertTrue(source.closed); self.assertIsNone(self.m.source)
        self.assertIn('nonfinite',self.m.status.text())

    def test_start_with_destination_accepts_none_return_and_consumes_audio(self):
        self.m.toggle_monitor()
        self.assertIsNotNone(self.m.source)
        self.assertTrue(self.m.timer.isActive())
        self.m.tick()
        self.assertTrue(self.m.clip_hold)
        self.assertEqual(self.m.stream.take(), b'')

    def test_capture_buffer_overflow_stops_monitor(self):
        self.m.toggle_monitor(); source=self.m.source
        self.m.stream.write(b'\0'*(1024*1024+1))
        self.m.tick()
        self.assertTrue(source.closed)
        self.assertIsNone(self.m.stream)
        self.assertIn('melampaui batas',self.m.status.text())
