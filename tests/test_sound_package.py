import copy
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch
from PySide6.QtWidgets import QDialog, QMessageBox
from cubebaby_mod.collection import Collection, make_item, packed, unpacked, load_item, validate_item, sound_to_bank
from cubebaby_mod.library_gui import SoundEditor
from cubebaby_mod.presets import FACTORY_PRESETS
from cubebaby_mod.protocol import decode_packet
import test_library_gui as library


def sound():
    return make_item('sound', 'Clean lengkap',
                     preset={'name':'Clean', **packed(FACTORY_PRESETS[:16])},
                     ir={'name':'Cabinet', **packed(unpacked(library.ir_item(), 'ir'))})


class PackageTests(unittest.TestCase):
    def test_roundtrip_is_self_contained_and_remaps_every_target_without_mutation(self):
        item = sound(); original = copy.deepcopy(item)
        with tempfile.TemporaryDirectory() as tmp:
            self.assertEqual(load_item(Collection(tmp).save(item)), item)
        for preset in range(3):
            for ir in range(8):
                bank = sound_to_bank(item, preset, ir)
                raw = unpacked(bank['presets'][0], 'preset')
                self.assertEqual(bank['presets'][0]['slot'], preset)
                self.assertEqual(bank['irs'][0]['slot'], ir)
                self.assertEqual(raw[9], ir+1)
                self.assertEqual(raw[:9]+raw[10:], FACTORY_PRESETS[:9]+FACTORY_PRESETS[10:16])
                self.assertEqual(unpacked(bank['irs'][0],'ir'), unpacked(item['ir'],'ir'))
        self.assertEqual(item, original)

    def test_missing_corrupt_and_invalid_package_data_rejected(self):
        for key in ('preset','ir'):
            bad = sound(); del bad[key]
            with self.assertRaises(ValueError): validate_item(bad)
            bad = sound(); bad[key]['sha256'] = 'bad'
            with self.assertRaises(ValueError): validate_item(bad)
        for p,i in ((True,0),(0,False),(-1,0),(3,0),(0,8),(0,-1)):
            with self.assertRaises(ValueError): sound_to_bank(sound(),p,i)


class PackageGuiTests(unittest.TestCase):
    setUpClass = library.LibraryGuiTests.__dict__['setUpClass']
    setUp = library.LibraryGuiTests.setUp
    tearDown = library.LibraryGuiTests.tearDown
    finish = library.LibraryGuiTests.finish
    select = library.LibraryGuiTests.select

    def test_composition_offline_requires_both_sources_and_never_sends_midi(self):
        self.w.stop(); before = list(self.backend.commands)
        entries = [(None,make_item('preset','Clean',FACTORY_PRESETS[:16])),(None,library.ir_item())]
        d = SoundEditor(self.panel,entries)
        d.save()
        self.assertNotEqual(d.result(),QDialog.Accepted)
        self.assertIn('Pilih satu preset',d.error.text())
        d.preset.setCurrentIndex(1); d.ir.setCurrentIndex(1); d.save()
        self.assertEqual(d.result(),QDialog.Accepted)
        self.assertEqual(d.result_item['kind'],'sound')
        self.assertEqual(self.backend.commands,before)
        d.close()

    def test_create_button_saves_one_portable_package_without_device_writes(self):
        self.panel.store.save(make_item('preset','Local preset',FACTORY_PRESETS[:16]))
        self.panel.store.save(library.ir_item('Local cab')); self.panel.refresh()
        before=list(self.backend.commands)
        def complete(dialog):
            # Explicit choices from collection, not the editor's unrelated IR.
            dialog.preset.setCurrentIndex(dialog.preset.findText('Local preset'))
            dialog.ir.setCurrentIndex(dialog.ir.findText('Local cab'))
            dialog.save()
            return dialog.result()
        with patch.object(SoundEditor,'exec',new=complete):
            self.panel.new_sound.click()
        items,errors=self.panel.store.entries()
        self.assertEqual(errors,[])
        packages=[item for _,item in items if item['kind']=='sound']
        self.assertEqual(len(packages),1)
        self.assertEqual(packages[0]['ir']['name'],'Local cab')
        self.assertEqual(self.backend.commands,before)

    def test_send_honors_both_targets_and_preserves_other_preset_bytes_and_sectors(self):
        item = sound(); self.select(item)
        self.panel.preset_target.setCurrentIndex(2); self.panel.ir_target.setCurrentIndex(6)
        # Firmware-owned bytes on destination must survive the package's source bytes.
        self.backend.presets[45:48] = b'\xaa\xbb\xcc'
        old_presets = bytes(self.backend.presets); old_flash = bytes(self.backend.flash)
        source = copy.deepcopy(item)
        with patch('cubebaby_mod.library_gui.confirm_question',return_value=QMessageBox.Yes) as confirm:
            self.panel.send_selected()
        self.finish()
        self.assertIn('slot 7', confirm.call_args.args[2])
        self.assertEqual(bytes(self.backend.presets[:32]), old_presets[:32])
        self.assertEqual(bytes(self.backend.presets[45:48]), b'\xaa\xbb\xcc')
        self.assertEqual(self.backend.presets[41],7)
        address=0x69000+6*4096
        self.assertEqual(bytes(self.backend.flash[address:address+2056]),unpacked(item['ir'],'ir'))
        self.assertEqual(bytes(self.backend.flash[:address]),old_flash[:address])
        self.assertEqual(bytes(self.backend.flash[address+4096:]),old_flash[address+4096:])
        self.assertEqual(self.panel.selected(), source)
        self.assertIn('selesai dan terverifikasi',self.w.status.text())
        root = next((Path(self.tmp.name)/'backups').glob('transfer-*'))
        self.assertTrue((root/'presets-before.json').exists())
        self.assertEqual(len(list(root.glob('cubebaby-*.json'))),1)

    def test_ir_failure_never_applies_preset_and_keeps_recovery_files(self):
        self.select(sound()); old = bytes(self.backend.presets)
        send=self.backend.output.send
        def drop_ack(message):
            send(message)
            if decode_packet(bytes(message.bytes()))['opcode']==0x21:
                self.backend.input.messages.pop()
        self.backend.output.send=drop_ack
        with patch('cubebaby_mod.library_gui.confirm_question',return_value=QMessageBox.Yes): self.panel.send_selected()
        for _ in range(150):
            self.w.poll(); self.clock[0]+=.11
            if self.w.ir_writer is not None and self.w.ir_writer.modified: break
        self.clock[0]+=31; self.w.poll(); self.finish()
        self.assertEqual(bytes(self.backend.presets),old)
        self.assertFalse(any(op==0x22 and region==5 for op,region,_,_ in self.backend.commands))
        self.assertIn('sebagian',self.w.status.text())
        self.assertTrue(list((Path(self.tmp.name)/'backups').glob('*/presets-before.json')))

    def test_cancel_send_does_nothing_and_package_filter_displays_both_targets(self):
        self.select(sound()); before=list(self.backend.commands)
        self.panel.kind_filter.setCurrentIndex(4)
        self.assertEqual(self.panel.list.count(),1)
        self.panel.list.setCurrentRow(0)
        ui=self.w.studio_ui
        self.assertFalse(ui.preset_target_row.isHidden()); self.assertFalse(ui.ir_target_row.isHidden())
        with patch('cubebaby_mod.library_gui.confirm_question',return_value=QMessageBox.No): self.panel.send_selected()
        self.assertEqual(self.backend.commands,before)
