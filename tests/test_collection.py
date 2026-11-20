import copy
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch
from cubebaby_mod.collection import Collection, make_item, load_item, atomic_json, validate_item, bank_entry, preset_to_bank, unpacked
from cubebaby_mod.presets import FACTORY_PRESETS
from test_ir_writer import ORIGINAL


class CollectionTests(unittest.TestCase):
    def test_roundtrip_self_contained_bank_and_many_named_presets(self):
        with tempfile.TemporaryDirectory() as tmp:
            store = Collection(tmp)
            preset = make_item('preset', 'Clean', FACTORY_PRESETS[:16])
            ir = make_item('ir', 'Cab', ORIGINAL)
            bank = make_item('bank', 'Rock', irs=[bank_entry(7, ir)], presets=[bank_entry(2, preset)])
            path = store.save(bank)
            self.assertEqual(load_item(path), bank)
            for i in range(40): store.save(make_item('preset', f'Lagu {i}', FACTORY_PRESETS[:16]))
            entries, errors = Collection(tmp).entries()
            self.assertEqual(len(entries), 41); self.assertEqual(errors, [])

    def test_preset_can_target_any_slot_without_mutating_source(self):
        item = make_item('preset', 'My preset', FACTORY_PRESETS[:16])
        for slot in range(3):
            bank = preset_to_bank(item, slot)
            self.assertEqual(bank['presets'][0]['slot'], slot)
            self.assertEqual(unpacked(bank['presets'][0], 'preset'), FACTORY_PRESETS[:16])
        self.assertNotIn('slot', item)

    def test_corrupt_hash_duplicate_slot_model_and_out_of_range_values_rejected(self):
        preset = make_item('preset', 'Preset', FACTORY_PRESETS[:16])
        bank = make_item('bank', 'Bank', presets=[bank_entry(0, preset)])
        bad = copy.deepcopy(bank); bad['presets'].append(copy.deepcopy(bad['presets'][0]))
        with self.assertRaises(ValueError): validate_item(bad)
        bad = copy.deepcopy(bank); bad['presets'][0]['slot'] = True
        with self.assertRaises(ValueError): validate_item(bad)
        bad = copy.deepcopy(preset); bad['raw_hex'] = 'ff'*16
        with self.assertRaises(ValueError): validate_item(bad)
        bad = copy.deepcopy(preset); bad['device_code'] = 20233
        with self.assertRaises(ValueError): validate_item(bad)
        raw = bytearray(FACTORY_PRESETS[:16]); raw[1] = 255
        with self.assertRaises(ValueError): make_item('preset', 'Invalid', raw)

    def test_atomic_save_failure_keeps_old_file_and_cleans_temp(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp)/'file.json'; atomic_json(path, {'old': 1})
            with patch('cubebaby_mod.collection.os.replace', side_effect=OSError('disk error')):
                with self.assertRaises(OSError): atomic_json(path, {'new': 2})
            self.assertEqual(json.loads(path.read_text()), {'old': 1})
            self.assertEqual([p.name for p in Path(tmp).iterdir()], ['file.json'])

    def test_bad_file_in_collection_is_reported_without_hiding_valid_files(self):
        with tempfile.TemporaryDirectory() as tmp:
            store = Collection(tmp); store.save(make_item('preset', '../safe-name', FACTORY_PRESETS[:16]))
            (Path(tmp)/'broken.json').write_text('{"format":')
            items, errors = store.entries()
            self.assertEqual(len(items), 1); self.assertEqual(len(errors), 1)
            self.assertTrue(items[0][0].parent == Path(tmp))

    def test_json_size_and_nan_rejected(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp)/'bad.json'
            path.write_text('{"number":NaN}')
            with self.assertRaises(ValueError): load_item(path)
            path.write_bytes(b' '* (1024*1024+1))
            with self.assertRaises(ValueError): load_item(path)
