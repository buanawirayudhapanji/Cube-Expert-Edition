"""Theme contrast, state, lifecycle and cached glass without pedal changes."""
import os
from pathlib import Path
import re
import unittest
from unittest.mock import patch
from PySide6.QtCore import Qt
from PySide6.QtGui import QPalette
from PySide6.QtWidgets import QApplication, QDialog, QFileDialog, QPushButton, QStyle
import test_library_gui as library
from cubebaby_mod.theme_tokens import contrast_report, palette, qc
from cubebaby_mod.theme_ui import GlassSurface
from cubebaby_mod.ui_preferences import accessibility_hints, reduced_motion


class ThemeTests(unittest.TestCase):
    setUpClass = library.LibraryGuiTests.__dict__['setUpClass']
    setUp = library.LibraryGuiTests.setUp
    tearDown = library.LibraryGuiTests.tearDown
    finish = library.LibraryGuiTests.finish

    def test_native_accessibility_hints_remain_alive_for_repeated_theme_updates(self):
        import gc
        from shiboken6 import isValid
        hints = accessibility_hints()
        if hints is None:
            self.skipTest('Qt ini belum mengekspos accessibility hints')
        for _ in range(3):
            gc.collect()
            self.assertTrue(isValid(hints))
            self.assertIs(accessibility_hints(),hints)
            self.assertIsInstance(reduced_motion(),bool)

    def settle(self):
        for _ in range(5):self.app.processEvents()

    def test_all_required_contrast_pairs_pass_effective_worst_case(self):
        rows = contrast_report()
        self.assertEqual(len(rows),28)
        for row in rows:
            self.assertGreaterEqual(row['ratio'],row['minimum'],row)

    def test_ui_colors_are_only_in_token_module(self):
        root = Path(__file__).resolve().parent.parent/'cubebaby_mod'
        for path in root.rglob('*.py'):
            if path.name == 'theme_tokens.py':continue
            self.assertIsNone(re.search(r'#[0-9a-fA-F]{3,8}\b|rgba?\(\s*\d',path.read_text()),path)
        self.assertNotIn('#',(root/'assets/ui/check.svg').read_text())

    def test_theme_switch_updates_all_pages_icons_palette_and_log_without_device_write(self):
        ui = self.w.studio_ui
        self.w.show(); self.settle()
        self.w.records.append({'direction':'in','timestamp':'12:00','message':'Pesan uji'})
        ui.midi_log.update_log()
        log = ui.midi_log.console.toPlainText()
        ui.midi_log.pause.setChecked(True)
        before = list(self.backend.commands)
        for mode in ('light','dark','system'):
            ui.change_theme(mode); self.settle()
            self.assertEqual(ui.preferences.value('appearance/theme'),mode)
            self.assertEqual(self.app.palette().color(QPalette.Text),qc('text_primary'))
            self.assertEqual(ui.midi_log.console.toPlainText(),log)
            self.assertTrue(ui.midi_log.pause.isChecked())
            for page in range(4):
                ui.navigate(page); self.settle()
                self.assertEqual(self.w.lightTheme if hasattr(self.w,'lightTheme') else self.w.property('lightTheme'),ui.theme.light)
        self.assertEqual(self.backend.commands,before)

    def test_glass_modes_reduced_transparency_and_native_fallback(self):
        ui = self.w.studio_ui
        self.w.show(); self.settle()
        for mode in ('full','light','off'):
            ui.theme.set_glass(mode); self.settle()
            self.assertEqual(ui.ambient.mode,mode)
            ui.ambient.grab()
        ui.theme.set_glass('full')
        ui.theme.set_reduced_transparency(True); self.settle()
        self.assertEqual(ui.ambient.mode,'off')
        self.assertFalse(ui.ambient.drift.isActive())
        ui.theme.set_reduced_transparency(False)
        with patch.dict(os.environ,{'CUBEBABY_REDUCED_TRANSPARENCY':'1'}):
            ui.theme.apply(animate=False)
            self.assertEqual(ui.ambient.mode,'off')
        ui.theme.apply(animate=False)
        ui.ambient.blur_available = False
        ui.preset_card.grab()  # Opaque fallback is still paintable.
        self.assertFalse(ui.ambient.blur_available)

    def test_glass_cache_is_not_rebuilt_on_meter_frames_and_auto_light_is_session_only(self):
        ui = self.w.studio_ui
        ui.theme.set_glass('full')
        self.w.show(); self.settle()
        ui.ambient.grab()
        generation = ui.ambient.generation
        for _ in range(5):
            ui.audio_meter.render(-18,-24)
            ui.audio_meter.bar.animate_fill(.5)
            ui.audio_meter.bar.grab()
        self.assertEqual(ui.ambient.generation,generation)
        for _ in range(30):ui.theme.record_frame_interval(.05)
        self.assertEqual(ui.theme.effective_glass,'light')
        self.assertEqual(ui.ambient.mode,'light')
        self.assertEqual(ui.preferences.value('appearance/glass'),'full')
        ui.set_reduced_motion(True)
        self.assertFalse(ui.ambient.drift.isActive())

    def test_dialog_and_popover_receive_glass_without_changing_dialog_semantics(self):
        ui = self.w.studio_ui
        self.w.show(); self.settle()
        dialog = QDialog(self.w)
        dialog.setModal(True); dialog.show(); self.settle()
        self.assertTrue(dialog.isModal())
        self.assertTrue(hasattr(dialog,'_theme_backdrop'))
        self.assertIsInstance(dialog._theme_backdrop.surface,GlassSurface)
        ui.change_theme('light'); self.settle()
        self.assertEqual(dialog.palette().color(QPalette.WindowText),qc('text_primary'))
        dialog.reject(); dialog.deleteLater()
        before = list(self.backend.commands)
        menu = ui.appearance_button.menu()
        labels = [action.text() for action in menu.actions()]
        self.assertIn('Tema',labels);self.assertIn('Efek kaca',labels)
        self.assertIn('Kurangi transparansi',labels)
        self.assertEqual(self.backend.commands,before)

    def test_file_picker_allows_native_dialogs_and_fallback_keeps_its_own_controls(self):
        ui = self.w.studio_ui
        self.assertFalse(QApplication.testAttribute(Qt.AA_DontUseNativeDialogs))
        before = list(self.backend.commands)
        dialog = QFileDialog(self.w, 'Pilih IR', self.tmp.name)
        dialog.setOption(QFileDialog.DontUseNativeDialog, True)  # Exercise fallback under offscreen Qt.
        button = QPushButton('Kontrol pemilih file', dialog)
        button.setIcon(dialog.style().standardIcon(QStyle.SP_DirIcon))
        icon = button.icon().cacheKey()
        try:
            dialog.show()
            self.settle()
            button.setEnabled(False)
            for theme in ('light', 'dark'):
                ui.change_theme(theme)
                self.settle()
                self.assertFalse(QApplication.testAttribute(Qt.AA_DontUseNativeDialogs))
                self.assertFalse(hasattr(dialog, '_theme_backdrop'))
                self.assertFalse(hasattr(button, '_unlocked_icon'))
                self.assertEqual(button.icon().cacheKey(), icon)
            self.assertEqual(self.backend.commands, before)
        finally:
            dialog.reject()
            dialog.deleteLater()
        platform_dialog = QDialog()
        try:
            platform_dialog.show()
            self.settle()
            self.assertFalse(hasattr(platform_dialog, '_theme_backdrop'))
        finally:
            platform_dialog.close()
            platform_dialog.deleteLater()
