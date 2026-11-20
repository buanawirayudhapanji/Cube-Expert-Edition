import json
import os
from pathlib import Path
import tempfile
import unittest
from unittest.mock import Mock, patch

from cubebaby_mod.app_paths import data_root, backup_directory
from cubebaby_mod.bundle_support import install_user, uninstall_user
from cubebaby_mod.collection import Collection, atomic_json
from cubebaby_mod.ir_writer import IRWriter, save_backup
from cubebaby_mod.midi import enumerate_ports
from cubebaby_mod.protocol import slot_with_distance
from cubebaby_mod.windows_io import replace_write_through
from test_ir_writer import Pedal, INFO, ORIGINAL, SECTOR, run_writer


class PackagingTests(unittest.TestCase):
    def test_source_paths_and_library_override_remain_compatible(self):
        with patch.dict(os.environ, {}, clear=True), patch('sys.frozen', False, create=True):
            self.assertEqual(data_root(), Path(__file__).resolve().parent.parent)
            self.assertEqual(backup_directory(), data_root() / 'backups')
            with patch.dict(os.environ, {'CUBEBABY_LIBRARY_DIR': 'custom-library'}):
                self.assertEqual(Collection().root, Path('custom-library'))

    def test_frozen_data_uses_writable_user_locations_and_explicit_override(self):
        with tempfile.TemporaryDirectory() as temporary:
            with patch.dict(os.environ, {'XDG_DATA_HOME': temporary, 'LOCALAPPDATA': temporary}, clear=True), patch('sys.frozen', True, create=True):
                for system in ('linux', 'win32'):
                    with patch('sys.platform', system):
                        self.assertEqual(data_root(), Path(temporary) / 'CubeBabyMOD')
                        self.assertEqual(Collection().root, data_root() / 'library_data')
                with patch.dict(os.environ, {'CUBEBABY_DATA_DIR': str(Path(temporary) / 'override')}):
                    self.assertEqual(backup_directory(), Path(temporary) / 'override/backups')

    def test_midi_backend_matches_target_without_opening_output(self):
        for system, api in (('linux', 'LINUX_ALSA'), ('win32', 'WINDOWS_MM')):
            backend = Mock()
            backend.get_input_names.return_value = ['input']
            backend.get_output_names.return_value = ['output']
            with patch('sys.platform', system), patch('mido.Backend', return_value=backend) as create:
                self.assertEqual(enumerate_ports(), (backend, ['input'], ['output']))
                create.assert_called_once_with('mido.backends.rtmidi/' + api)
                backend.open_output.assert_not_called()

    def test_windows_atomic_file_failure_preserves_existing_data(self):
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / 'item.json'
            path.write_text('{"old": true}')
            with patch('sys.platform', 'win32'), patch('cubebaby_mod.collection.replace_write_through', side_effect=OSError('write-through failed')):
                with self.assertRaises(OSError):
                    atomic_json(path, {'new': True})
            self.assertEqual(json.loads(path.read_text()), {'old': True})
            self.assertEqual([p.name for p in Path(temporary).iterdir()], ['item.json'])

    def test_windows_backup_publication_failure_prevents_flash_erase(self):
        with tempfile.TemporaryDirectory() as temporary:
            pedal, clock = Pedal(), [0]
            writer = IRWriter(INFO, 1, ORIGINAL, slot_with_distance(ORIGINAL, 74),
                              lambda address, slot, data: save_backup(temporary, address, slot, data),
                              clock=lambda: clock[0])
            with patch('sys.platform', 'win32'), patch('cubebaby_mod.ir_writer.replace_write_through', side_effect=OSError('backup not durable')):
                with self.assertRaises(OSError):
                    run_writer(writer, pedal, clock)
            self.assertEqual(pedal.erase_count, 0)
            self.assertEqual(bytes(pedal.memory), SECTOR)
            self.assertEqual(list(Path(temporary).iterdir()), [])

    def test_windows_native_publish_requests_write_through_and_exclusive_backup(self):
        native = Mock(return_value=True)
        kernel = Mock()
        kernel.MoveFileExW = native
        with patch('cubebaby_mod.windows_io.ctypes.WinDLL', return_value=kernel, create=True):
            replace_write_through('source', 'target')
            self.assertEqual(native.call_args.args[2], 9)
            replace_write_through('source', 'target', replace=False)
            self.assertEqual(native.call_args.args[2], 8)

    @unittest.skipUnless(os.name == 'posix', 'Linux user integration is tested on Linux')
    def test_linux_install_round_trip_keeps_user_collection_and_handles_spaces(self):
        with tempfile.TemporaryDirectory() as temporary:
            base = Path(temporary) / 'data with spaces %'
            image = Path(temporary) / 'CubeBabyMOD.AppImage'
            image.write_bytes(b'appimage fixture')
            icon = Path(temporary) / 'icon.png'
            icon.write_bytes(b'icon fixture')
            with patch.dict(os.environ, {'XDG_DATA_HOME': str(base)}, clear=True), patch('sys.platform', 'linux'):
                result = install_user(image, icon)
                program = Path(result['program'])
                self.assertEqual(program.read_bytes(), image.read_bytes())
                self.assertTrue(os.access(program, os.X_OK))
                entry = Path(result['desktop_entry']).read_text()
                self.assertIn('Exec="', entry)
                self.assertIn('%%', entry)
                data = base / 'CubeBabyMOD/library_data/keep.json'
                data.parent.mkdir(parents=True)
                data.write_text('keep')
                install_user(program, icon)
                uninstall_user()
                self.assertFalse(program.exists())
                self.assertTrue(data.exists())
