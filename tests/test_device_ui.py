"""Device panels reuse validated backup and reset paths."""
from pathlib import Path
from unittest.mock import patch
from PySide6.QtCore import QTimer
from PySide6.QtWidgets import QDialog, QDialogButtonBox, QLineEdit, QMessageBox
from cubebaby_mod.device_ui import confirm_reset
import test_library_gui as library


class DeviceTests(library.unittest.TestCase):
    setUpClass = library.LibraryGuiTests.__dict__['setUpClass']
    setUp = library.LibraryGuiTests.setUp
    tearDown = library.LibraryGuiTests.tearDown
    finish = library.LibraryGuiTests.finish

    def test_backup_read_only_then_restore_verified_sector(self):
        panel = self.w.studio_ui.backup_panel
        panel.directory = Path(self.tmp.name) / 'device-backups'
        panel.refresh()
        slot = panel.slot.currentIndex()
        address = 0x69000 + slot * 4096
        original = bytes(self.backend.flash[address:address+4096])
        before = len(self.backend.commands)
        panel.create.click()
        self.finish()
        self.assertTrue(all(op == 0x23 for op, _, _, _ in self.backend.commands[before:]))
        self.assertEqual(panel.list.count(), 1)
        self.backend.flash[address:address+4096] = b'\xff' * 4096
        panel.list.setCurrentRow(0)
        with patch('cubebaby_mod.device_ui.confirm_question', return_value=QMessageBox.Yes):
            panel.restore.click()
        self.finish()
        self.assertEqual(bytes(self.backend.flash[address:address+4096]), original)
        self.assertIn('terverifi', self.w.status.text())


    def test_log_filters_pause_clear_preserve_session_records(self):
        panel = self.w.studio_ui.midi_log
        panel.clear()
        self.w.append_record({'timestamp': 't1', 'direction': 'in', 'message': '<input>'})
        panel.update_log()
        self.assertIn('IN', panel.console.toPlainText())
        self.assertIn('<input>', panel.console.toPlainText())
        panel.pause.setChecked(True)
        self.w.append_record({'timestamp': 't2', 'direction': 'out', 'message': 'output'})
        panel.update_log()
        self.assertNotIn('output', panel.console.toPlainText())
        panel.filter.setCurrentIndex(2)
        panel.pause.setChecked(False)
        self.assertIn('output', panel.console.toPlainText())
        self.assertNotIn('<input>', panel.console.toPlainText())
        records = list(self.w.records)
        panel.clear()
        self.assertEqual(panel.console.toPlainText(), '')
        self.assertEqual(self.w.records, records)


    def test_reset_requires_exact_text_and_preserves_original_confirmation(self):
        called = []
        def complete():
            dialog = self.app.activeModalWidget()
            self.assertIsInstance(dialog, QDialog)
            button = dialog.findChild(QDialogButtonBox).button(QDialogButtonBox.Ok)
            entry = dialog.findChild(QLineEdit)
            self.assertFalse(button.isEnabled())
            entry.setText('reset')
            self.assertFalse(button.isEnabled())
            entry.setText('RESET')
            self.assertTrue(button.isEnabled())
            button.click()
        QTimer.singleShot(0, complete)
        confirm_reset(self.w, 'Reset pengujian', lambda: called.append(True))
        self.assertEqual(called, [True])

        before = bytes(self.backend.presets)
        QTimer.singleShot(0, complete)
        with patch('cubebaby_mod.suite_gui.confirm_question', return_value=QMessageBox.No) as question:
            self.w.factory_presets_button.click()
        self.assertEqual(question.call_count, 1)
        self.assertEqual(bytes(self.backend.presets), before)

