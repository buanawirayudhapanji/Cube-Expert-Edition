import json
from pathlib import Path
import struct
import tempfile
import unittest
from unittest.mock import patch
import mido
from PySide6.QtGui import QCloseEvent
from PySide6.QtWidgets import QApplication
from PySide6.QtCore import QCoreApplication, QEvent
from cubebaby_mod.gui import Window
from cubebaby_mod.ir_writer import save_backup
from cubebaby_mod.protocol import decode_packet, encode_packet, parse_ir_slot, IR_SLOT_SIZE
from test_connection import PORT, IDENTITY
from test_ir_reader import INFO_PACKET
from test_ir_writer import Pedal, ORIGINAL, SECTOR, BASE


class Input:
    def __init__(self): self.messages=[]; self.closed=False
    def poll(self): return self.messages.pop(0) if self.messages else None
    def close(self): self.closed=True


class Output:
    def __init__(self, owner): self.owner=owner; self.closed=False
    def close(self): self.closed=True
    def send(self, message):
        raw=bytes(message.bytes()); packet=decode_packet(raw)
        if packet['opcode']==0x11: response=IDENTITY
        elif packet['opcode']==0x23 and int.from_bytes(packet['payload'][1:5],'little')==0x2100:
            response=INFO_PACKET
        else:
            parsed=self.owner.pedal.respond(raw)
            if self.owner.drop_erase_ack and packet['opcode']==0x21: return
            response=encode_packet(parsed['opcode'],parsed['payload'])
        self.owner.input.messages.append(mido.Message.from_bytes(response))


class Backend:
    def __init__(self):
        self.pedal=Pedal();self.drop_erase_ack=False
        self.input=Input();self.output=Output(self)
    def open_input(self, name): return self.input
    def open_output(self, name): return self.output


class WriteGuiTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls): cls.app=QApplication.instance() or QApplication([])
    def setUp(self):
        self.tmp=tempfile.TemporaryDirectory()
        self.clock=[0]
        self.backend=Backend()
        self.patches=[
            patch('cubebaby_mod.gui.enumerate_ports',return_value=(self.backend,[PORT],[PORT])),
            patch('cubebaby_mod.gui.time.monotonic',side_effect=lambda:self.clock[0]),
            patch('cubebaby_mod.gui.save_backup',side_effect=lambda directory,a,slot,data:save_backup(self.tmp.name,a,slot,data)),
        ]
        for p in self.patches:p.start()
        self.w=Window();self.w.connect_device();self.w.poll()
        self.w.read_device_info();self.w.poll()
        self.w.ir_slot.setCurrentIndex(1);self.w.read_ir_slot();self.w.poll()
        self.assertEqual(self.w.ir_snapshot['slot'],2)
        self.assertEqual(self.w.distance.value(),75)
        self.assertFalse(self.w.save_button.isEnabled())
    def tearDown(self):
        self.w.stop();self.w.close()
        self.w.deleteLater()
        QCoreApplication.sendPostedEvents(None,QEvent.DeferredDelete)
        for p in reversed(self.patches):p.stop()
        self.tmp.cleanup()
    def finish(self):
        for _ in range(100):
            self.w.poll();self.clock[0]+=.11
            if self.w.ir_writer is None:return
        self.fail('GUI write sequence did not finish')

    def test_save_distance_creates_backup_and_verifies(self):
        self.w.distance.setValue(74)
        self.assertTrue(self.w.save_button.isEnabled())
        self.w.save_ir();self.finish()
        self.assertIn('terverifikasi',self.w.status.text())
        self.assertAlmostEqual(self.w.ir_snapshot['distance_percent'],74,places=4)
        self.assertEqual(bytes(self.backend.pedal.memory[:4]),ORIGINAL[:4])
        self.assertEqual(bytes(self.backend.pedal.memory[8:]),SECTOR[8:])
        self.assertFalse(self.w.save_button.isEnabled())
        paths=list(Path(self.tmp.name).glob('*.json'))
        self.assertEqual(len(paths),1)
        self.assertEqual(bytes.fromhex(json.loads(paths[0].read_text())['sector_hex']),SECTOR)

    def test_backup_failure_aborts_before_any_erase(self):
        self.w.distance.setValue(74)
        with patch('cubebaby_mod.gui.save_backup',side_effect=OSError('disk full')):
            self.w.save_ir();self.finish()
        self.assertEqual(self.backend.pedal.erase_count,0)
        self.assertEqual(bytes(self.backend.pedal.memory),SECTOR)
        self.assertIn('disk full',self.w.status.text())
        self.assertIsNone(self.w.identity)

    def test_erase_timeout_keeps_backup_and_blocks_close_during_write(self):
        self.backend.drop_erase_ack=True
        self.w.distance.setValue(74);self.w.save_ir();self.w.poll()
        self.assertEqual(self.backend.pedal.erase_count,1)
        self.assertFalse(self.w.connect_button.isEnabled())
        self.assertFalse(self.w.refresh_button.isEnabled())
        event=QCloseEvent();self.w.closeEvent(event)
        self.assertFalse(event.isAccepted())
        self.clock[0]=31;self.w.poll()
        self.assertIsNone(self.w.ir_writer)
        self.assertIn('Cadangan:',self.w.status.text())
        self.assertIn('mungkin belum lengkap',self.w.status.text())
        self.assertEqual(len(list(Path(self.tmp.name).glob('*.json'))),1)
        self.assertEqual(bytes(self.backend.pedal.memory),b'\xff'*4096)

    def test_import_json_preserves_target_header_and_updates_ir(self):
        raw=struct.pack('<I513f',0,.65,*([.25]*512))
        source=parse_ir_slot(raw,0,0x69000);source['device_code']=20230
        path=Path(self.tmp.name)/'source.json';path.write_text(json.dumps(source))
        with patch('cubebaby_mod.gui.QFileDialog.getOpenFileName',return_value=(str(path),'JSON')):
            self.w.import_ir()
        self.assertEqual(self.w.desired_record()[:4],ORIGINAL[:4])
        self.assertEqual(self.w.desired_record()[4:],raw[4:])
        self.w.save_ir();self.finish()
        self.assertIn('terverifikasi',self.w.status.text())
        self.assertEqual(bytes(self.backend.pedal.memory[:IR_SLOT_SIZE]),ORIGINAL[:4]+raw[4:])
        self.assertEqual(bytes(self.backend.pedal.memory[IR_SLOT_SIZE:]),SECTOR[IR_SLOT_SIZE:])

    def test_restore_backup_returns_original_full_sector(self):
        self.w.distance.setValue(74);self.w.save_ir();self.finish()
        backup=next(Path(self.tmp.name).glob('*.json'))
        with patch('cubebaby_mod.gui.QFileDialog.getOpenFileName',return_value=(str(backup),'JSON')):
            self.w.import_ir()
        self.assertIn('Pulihkan',self.w.save_button.text())
        self.assertFalse(self.w.distance.isEnabled())
        self.w.save_ir();self.finish()
        self.assertIn('terverifikasi',self.w.status.text())
        self.assertEqual(bytes(self.backend.pedal.memory),SECTOR)
        self.assertEqual(len(list(Path(self.tmp.name).glob('*.json'))),2)

    def test_restore_erased_slot_from_backup(self):
        backup=save_backup(self.tmp.name,BASE,1,SECTOR)
        self.backend.pedal.memory[:]=b'\xff'*4096
        self.w.read_ir_slot();self.w.poll()
        self.assertFalse(self.w.ir_snapshot['format_recognized'])
        with patch('cubebaby_mod.gui.QFileDialog.getOpenFileName',return_value=(backup,'JSON')):
            self.w.import_ir()
        self.assertTrue(self.w.save_button.isEnabled())
        self.w.save_ir();self.finish()
        self.assertEqual(bytes(self.backend.pedal.memory),SECTOR)
        self.assertIn('terverifikasi',self.w.status.text())

    def test_restoring_erased_backup_does_not_invent_distance(self):
        path=save_backup(self.tmp.name,BASE,1,b'\xff'*4096)
        with patch('cubebaby_mod.gui.QFileDialog.getOpenFileName',return_value=(path,'JSON')):
            self.w.import_ir()
        self.w.save_ir();self.finish()
        self.assertEqual(bytes(self.backend.pedal.memory),b'\xff'*4096)
        self.assertIn('belum dikenali',self.w.ir_status.text())
        self.assertNotIn('Distance',self.w.ir_status.text())
        self.assertFalse(self.w.distance.isEnabled())
