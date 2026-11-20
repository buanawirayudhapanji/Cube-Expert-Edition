"""Layout ownership and navigation must not change pedal behavior."""
from pathlib import Path
import unittest
from unittest.mock import patch
from PySide6.QtCore import QCoreApplication, QEvent, Qt
from PySide6.QtTest import QTest
from PySide6.QtWidgets import QFileDialog, QMessageBox, QScrollArea, QTabWidget
from cubebaby_mod.collection import load_item, make_item
from cubebaby_mod.presets import FACTORY_PRESETS
import test_library_gui as library
from test_library_gui import ir_item


class StudioTests(unittest.TestCase):
    setUpClass = library.LibraryGuiTests.__dict__['setUpClass']
    setUp = library.LibraryGuiTests.setUp
    tearDown = library.LibraryGuiTests.tearDown
    finish = library.LibraryGuiTests.finish

    def test_resize_round_trip_keeps_controls_and_device_data(self):
        ui = self.w.studio_ui
        controls = dict(self.w.effect_controls)
        before = list(self.backend.commands)
        self.w.show()
        for width, height in ((1400, 900), (1000, 680), (800, 700), (580, 720),
                              (360, 640), (1000, 680), (1400, 900)):
            self.w.resize(width, height)
            for page in range(4):
                ui.navigate(page)
                for _ in range(5):
                    self.app.processEvents()
                viewport = ui.viewports[page]
                self.assertEqual(self.w.width(), width)
                self.assertLessEqual(viewport.widget().minimumSizeHint().width(), viewport.viewport().width())
                self.assertEqual(viewport.horizontalScrollBar().maximum(), 0)
                if width >= 1000:
                    self.assertEqual(viewport.verticalScrollBar().maximum(), 0, (width, page))
            self.assertEqual(ui.bottom_navigation.isVisible(), width < 900)
            self.assertEqual(ui.sidebar.isVisible(), width >= 900)
            self.assertEqual(ui.editor_drawer.count(), 2 if width < 1200 else 0)
            self.assertEqual(ui.collection_drawer.count(), 2 if width < 900 else 0)
        self.assertEqual(self.w.effect_controls, controls)
        self.assertEqual(self.backend.commands, before)

    def test_touch_actions_and_theme_preserve_handlers_without_midi(self):
        ui = self.w.studio_ui
        self.w.show(); self.w.resize(360, 640); ui.navigate(0)
        for _ in range(5):
            self.app.processEvents()
        self.assertTrue(ui.sticky_actions.isVisible())
        for button in [*ui.bottom_buttons, ui.mobile_save, ui.mobile_ir]:
            self.assertGreaterEqual(button.height(), 44, button.text())
        self.assertTrue(self.w.status.isVisible())
        before = list(self.backend.commands)
        for theme in ('light', 'system', 'dark'):
            ui.change_theme(theme)
            self.assertEqual(ui.preferences.value('appearance/theme'), theme)
        ui.change_theme('light')
        self.assertTrue(self.w.property('lightTheme'))
        self.assertTrue(self.panel.list.property('lightTheme'))
        ui.mobile_save.setEnabled(True)
        with patch('cubebaby_mod.studio_ui.confirm_overwrite', return_value=False) as confirm:
            ui.mobile_save.click()
            confirm.assert_called_once()
        self.assertEqual(self.backend.commands, before)

    def test_controls_survive_layout_replacement_and_all_pages_are_read_only(self):
        self.w.show()
        QCoreApplication.sendPostedEvents(None, QEvent.DeferredDelete)
        self.app.processEvents()
        before = list(self.backend.commands)
        ui = self.w.studio_ui
        for i, button in enumerate(ui.nav):
            button.click(); self.app.processEvents()
            self.assertEqual(ui.stack.currentIndex(), i)
            self.assertTrue(button.isChecked())
        self.w.resize(1000, 680); self.app.processEvents()
        for i in range(4):
            ui.navigate(i); self.app.processEvents()
            viewport = ui.stack.currentWidget()
            page = viewport.widget()
            self.assertEqual(viewport.horizontalScrollBarPolicy(), Qt.ScrollBarAlwaysOff)
            self.assertEqual((self.w.width(), self.w.height()), (1000, 680))
            self.assertLessEqual(page.minimumSizeHint().width(), page.width())
            self.assertLessEqual(page.minimumSizeHint().height(), page.height())
            for tabs in page.findChildren(QTabWidget):
                for index in range(tabs.count()):
                    tabs.setCurrentIndex(index)
                    self.app.processEvents()
                    panel = tabs.currentWidget()
                    self.assertLessEqual(panel.minimumSizeHint().height(), panel.height())
                    self.assertLessEqual(panel.minimumSizeHint().width(), panel.width())
        self.assertEqual(self.backend.commands, before)
        self.assertEqual(self.w.preset_selector.count(), 3)
        self.assertEqual(self.w.ir_slot.count(), 8)
        self.assertTrue(self.w.preset_save.isEnabled())
        self.assertTrue(self.w.factory_presets_button.parentWidget().isHidden())

    def test_preset_buttons_select_existing_slots_after_old_layout_is_deleted(self):
        QCoreApplication.sendPostedEvents(None, QEvent.DeferredDelete)
        ui = self.w.studio_ui
        for index, button in enumerate(ui.preset_buttons):
            button.click()
            self.assertEqual(self.w.preset_selector.currentIndex(), index)
            self.assertEqual([b.isChecked() for b in ui.preset_buttons],
                             [i == index for i in range(3)])

    def test_undo_uses_live_edit_without_writing_preset_storage(self):
        ui = self.w.studio_ui
        slider, _ = self.w.effect_controls[5]
        original = slider.value()
        slider.setValue(original - 1)
        self.finish()
        self.assertTrue(ui.undo_button.isEnabled())
        self.assertIn('belum disimpan', ui.dirty_label.text())
        before = len(self.backend.commands)
        ui.undo_button.click()
        self.finish()
        self.assertEqual(slider.value(), original)
        self.assertFalse(ui.undo_button.isEnabled())
        self.assertEqual(ui.dirty_label.text(), '')
        writes = [(region, address) for op, region, address, _ in self.backend.commands[before:] if op == 0x22]
        self.assertEqual(writes, [(5, 0x80000005)])

    def test_collection_multi_select_preserves_selection_and_disables_transfer(self):
        panel = self.panel
        panel.store.save(ir_item('A kabinet'))
        panel.store.save(ir_item('B kabinet'))
        panel.refresh()
        for i in range(panel.list.count()):
            panel.list.item(i).setSelected(True)
        self.assertEqual(len(panel.list.selectedItems()), 2)
        self.assertTrue(panel.export_file.isEnabled())
        self.assertFalse(panel.send_button.isEnabled())
        panel.sort_mode.setCurrentIndex(1)
        self.assertEqual(len(panel.list.selectedItems()), 2)

    def test_volume_drag_preserves_position_and_focus_during_midi_updates(self):
        self.w.resize(1000, 680)
        self.w.show()
        self.app.processEvents()
        slider, spin = self.w.effect_controls[5]
        slider.setFocus()
        position = slider.mapTo(self.w, slider.rect().topLeft())
        slider.setSliderDown(True)
        start = slider.value()
        for delta in (1, 2, 3):
            slider.setValue(start + delta if start < slider.maximum()-3 else start-delta)
            self.finish()
            self.app.processEvents()
            self.assertTrue(slider.isSliderDown())
            self.assertTrue(slider.hasFocus())
            self.assertEqual(slider.mapTo(self.w, slider.rect().topLeft()), position)
        slider.setSliderDown(False)

    def test_collection_rename_duplicate_and_delete_keep_item_payload_and_never_write_midi(self):
        panel = self.panel
        item = ir_item('Kabinet uji')
        path = panel.store.save(item)
        panel.refresh()
        self.w.studio_ui.navigate(1)
        self.w.show()
        self.app.processEvents()
        panel.list.setCurrentRow(0)
        before = list(self.backend.commands)
        with patch('cubebaby_mod.library_gui.QInputDialog.getText', return_value=('Kabinet baru', True)):
            panel.rename_selected()
        renamed = {**item, 'name': 'Kabinet baru'}
        self.assertEqual(load_item(path), renamed)
        self.assertEqual(panel.selected(), renamed)
        self.assertTrue(self.w.studio_ui.collection_assign.isVisible())

        panel.duplicate_selected()
        entries, _ = panel.store.entries()
        self.assertEqual([entry for _, entry in entries], [renamed, renamed])
        panel.list.setFocus()
        self.app.processEvents()
        with patch('cubebaby_mod.library_gui.confirm_question', return_value=QMessageBox.No) as confirm:
            QTest.keyClick(panel.list, Qt.Key_Delete)
            confirm.assert_called_once()
        self.assertTrue(path.exists())
        with patch('cubebaby_mod.library_gui.confirm_question', return_value=QMessageBox.Yes):
            QTest.keyClick(panel.list, Qt.Key_Delete)
        self.assertFalse(path.exists())
        self.assertEqual(len(panel.store.entries()[0]), 1)
        self.assertEqual(self.backend.commands, before)

    def test_shortcuts_respect_typing_and_focus_collection(self):
        ui = self.w.studio_ui
        self.w.show()
        ui.navigate(0)
        self.app.processEvents()
        slider, spin = self.w.effect_controls[5]
        slider.setFocus()
        QTest.keyClick(slider, Qt.Key_2)
        self.assertEqual(self.w.preset_selector.currentIndex(), 1)
        spin.setFocus()
        spin.selectAll()
        QTest.keyClick(spin, Qt.Key_1)
        self.assertEqual(self.w.preset_selector.currentIndex(), 1)
        self.finish()
        QTest.keyClick(slider, Qt.Key_K, Qt.ControlModifier)
        self.app.processEvents()
        self.assertEqual(ui.stack.currentIndex(), 1)
        self.assertTrue(self.panel.search.hasFocus())

    def test_ui_preferences_restore_without_device_io(self):
        ui = self.w.studio_ui
        ui.collapse_button.setChecked(True)
        ui.effect_tabs.setCurrentIndex(1)
        ui.editor_tools.setCurrentIndex(2)
        ui.collection_view.setChecked(True)
        ui.navigate(1)
        ui.save_preferences()
        before = list(self.backend.commands)
        from cubebaby_mod.suite_gui import SuiteWindow
        second = SuiteWindow()
        try:
            restored = second.studio_ui
            self.assertTrue(restored.collapse_button.isChecked())
            self.assertEqual(restored.effect_tabs.currentIndex(), 1)
            self.assertEqual(restored.editor_tools.currentIndex(), 2)
            self.assertTrue(restored.collection_view.isChecked())
            self.assertEqual(restored.stack.currentIndex(), 1)
            self.assertEqual(self.backend.commands, before)
            restored.set_reduced_motion(True)
            restored.navigate(2)
            self.assertEqual(restored.page_opacity.opacity(), 1.0)
            self.assertFalse(restored.page_fade.state().value)
        finally:
            second.close()

    def test_error_feedback_displays_details_and_retry_without_automatic_write(self):
        ui = self.w.studio_ui
        self.w.show()
        self.app.processEvents()
        before = list(self.backend.commands)
        self.w.fail('Pembacaan gagal pada slot uji.')
        self.assertTrue(ui.feedback_detail.isVisible())
        self.assertTrue(ui.retry_button.isVisible())
        self.assertIn('gagal', ui.error_message)
        self.assertEqual(self.backend.commands, before)
        ui.navigate(1)
        self.assertFalse(ui.offline_guide.isVisible())
        self.assertTrue(self.panel.new_preset.isEnabled())

    def test_confirmation_defaults_to_cancel(self):
        from PySide6.QtCore import QTimer
        from cubebaby_mod.ui_states import confirm_overwrite
        def cancel():
            dialog = self.app.activeModalWidget()
            self.assertEqual(dialog.defaultButton().text(), 'Batal')
            dialog.defaultButton().click()
        QTimer.singleShot(0, cancel)
        self.assertFalse(confirm_overwrite(self.w, 'Slot uji', 'Isi slot uji akan diganti.'))

    def test_dirty_slot_and_ctrl_s_cancel_does_not_write(self):
        ui = self.w.studio_ui
        self.w.show()
        self.app.processEvents()
        slider, _ = self.w.effect_controls[5]
        slider.setValue(slider.value() - 1)
        self.finish()
        self.assertIn('●', ui.preset_buttons[0].text())
        self.assertNotIn('●', ui.preset_buttons[1].text())
        before = list(self.backend.commands)
        slider.setFocus()
        with patch('cubebaby_mod.studio_ui.confirm_overwrite', return_value=False) as confirm:
            QTest.keyClick(slider, Qt.Key_S, Qt.ControlModifier)
            confirm.assert_called_once()
        self.assertEqual(self.backend.commands, before)

    def test_delete_undo_restores_original_file_payload(self):
        from cubebaby_mod.collection import load_item
        item = ir_item('IR original')
        path = self.panel.store.save(item)
        self.panel.refresh()
        self.panel.list.setCurrentRow(0)
        before = list(self.backend.commands)
        with patch('cubebaby_mod.library_gui.confirm_question', return_value=QMessageBox.Yes):
            self.panel.delete_selected()
        self.assertFalse(path.exists())
        self.panel.undo_delete()
        self.assertEqual(load_item(path), item)
        self.assertEqual(self.backend.commands, before)

    def test_comparison_switch_shortcuts_and_ram_preview_states(self):
        ui = self.w.studio_ui
        p = self.panel
        a, b = ir_item('A kabinet'), ir_item('B kabinet', .25)
        from cubebaby_mod.collection import unpacked
        p.set_ab('A', (unpacked(a, 'ir'), a['name']))
        p.set_ab('B', (unpacked(b, 'ir'), b['name']))
        ui.navigate(2)
        self.w.show()
        self.app.processEvents()
        ui.ab_switches['A'].setFocus()
        before = len(self.backend.commands)
        QTest.keyClick(ui.ab_switches['A'], Qt.Key_A)
        self.assertIn('Memuat A', p.ab_play_a.text())
        self.finish()
        self.assertTrue(ui.ab_switches['A'].isChecked())
        self.assertIn('48 kHz', ui.ab_metadata['A'].text())
        QTest.keyClick(ui.ab_switches['A'], Qt.Key_B)
        self.finish()
        self.assertTrue(ui.ab_switches['B'].isChecked())
        self.assertFalse(ui.ab_switches['A'].isChecked())
        self.assertTrue(all(op != 0x21 and (op != 0x22 or region == 4)
                            for op, region, _, _ in self.backend.commands[before:]))
        ui.navigate(1)
        self.app.processEvents()
        before = len(self.backend.commands)
        QTest.keyClick(p.search, Qt.Key_A)
        self.assertEqual(self.backend.commands[before:], [])

    def test_collection_filters_and_empty_states_do_not_write_device_or_files(self):
        p = self.panel; ui = self.w.studio_ui
        p.store.save(make_item('preset', 'Clean', FACTORY_PRESETS[:16]))
        p.store.save(ir_item('Cabinet'))
        p.refresh()
        before = list(self.backend.commands)
        original = {path: path.read_bytes() for path, _ in p.store.entries()[0]}
        p.kind_filter.setCurrentIndex(1)
        self.assertEqual(p.list.count(), 1)
        self.assertEqual(p.list.item(0).data(Qt.UserRole+1), 'preset')
        p.search.setText('missing')
        self.assertTrue(ui.collection_empty.isVisibleTo(p))
        self.assertIn('Tidak ada hasil', ui.collection_empty.text())
        p.search.clear(); p.kind_filter.setCurrentIndex(0)
        self.assertEqual(p.list.count(), 2)
        self.assertEqual({path: path.read_bytes() for path in original}, original)
        self.assertEqual(self.backend.commands, before)

    def test_adding_wav_reveals_file_list_without_a_device_write(self):
        before = list(self.backend.commands)
        with patch.object(QFileDialog, 'getOpenFileNames', return_value=(['/tmp/example.wav'], '')):
            self.w.choose_wav()
        self.assertFalse(self.w.wav_list.isHidden())
        self.assertTrue(self.w.studio_ui.wav_empty.isHidden())
        self.assertEqual(self.backend.commands, before)
        self.w.wav_folder = None
        self.w.refresh_wavs()
        self.assertTrue(self.w.wav_list.isHidden())

    def test_preset_save_control_still_sends_verified_job_after_reparenting(self):
        QCoreApplication.sendPostedEvents(None, QEvent.DeferredDelete)
        with patch('cubebaby_mod.studio_ui.confirm_overwrite', return_value=True):
            self.w.preset_save.click(); self.finish()
        self.assertTrue(any(op == 0x22 and region == 5 for op, region, _, _ in self.backend.commands))
