"""Page containers do not leak focus halos; collection undo follows live state."""
import unittest
from unittest.mock import patch

from PySide6.QtCore import Qt
from PySide6.QtWidgets import QMessageBox
import test_library_gui as library
from test_library_gui import ir_item
from cubebaby_mod.collection import load_item


class FeedbackTests(unittest.TestCase):
    setUpClass = library.LibraryGuiTests.__dict__['setUpClass']
    setUp = library.LibraryGuiTests.setUp
    tearDown = library.LibraryGuiTests.tearDown
    finish = library.LibraryGuiTests.finish

    def settle(self):
        for _ in range(8):
            self.app.processEvents()

    def show_window(self):
        self.w.studio_ui.set_reduced_motion(True)
        self.w.resize(1000, 680)
        self.w.show()
        self.w.activateWindow()
        self.settle()

    def test_page_container_focus_does_not_draw_clipped_halo_and_slider_focus_remains_visible(self):
        ui = self.w.studio_ui
        self.show_window()
        ui.navigate(0)
        before = list(self.backend.commands)
        slider = self.w.effect_controls[5][0]
        slider.setFocus(Qt.TabFocusReason)
        self.settle()
        self.assertTrue(slider.hasFocus())
        self.assertTrue(ui.theme.focus_halo.isVisible())
        viewport = ui.viewports[0]
        viewport.setFocus(Qt.OtherFocusReason)
        self.settle()
        self.assertTrue(viewport.hasFocus())
        self.assertFalse(ui.theme.focus_halo.isVisible())
        slider.setFocus(Qt.TabFocusReason)
        self.settle()
        self.assertTrue(ui.theme.focus_halo.isVisible())
        self.assertEqual(self.backend.commands, before)

    def test_undo_is_available_in_collection_only_and_still_restores_original_item(self):
        ui = self.w.studio_ui
        item = ir_item('IR untuk dipulihkan')
        path = self.panel.store.save(item)
        self.panel.refresh()
        self.show_window()
        ui.navigate(1)
        self.panel.list.setCurrentRow(0)
        before = list(self.backend.commands)
        self.assertFalse(ui.undo_delete.isVisible())
        with patch('cubebaby_mod.library_gui.confirm_question', return_value=QMessageBox.Yes):
            self.panel.delete_selected()
        ui.sync_feedback()
        self.settle()
        self.assertTrue(ui.undo_delete.isVisible())
        self.assertEqual(ui.footer_glass.geometry(), ui.footer_layout.geometry())
        self.assertTrue(ui.footer_glass.geometry().contains(ui.undo_delete.geometry()))
        self.w.status.setText('Tiga preset dan USB Loopback berhasil dibaca.')
        ui.sync_feedback()
        for page in (0, 2, 3):
            ui.navigate(page)
            self.settle()
            self.assertFalse(ui.undo_delete.isVisible())
            self.assertTrue(self.panel.deleted_items)
            self.assertFalse(path.exists())
        ui.navigate(1)
        self.settle()
        self.assertTrue(ui.undo_delete.isVisible())
        ui.undo_delete.click()
        ui.sync_feedback()
        self.settle()
        self.assertFalse(ui.undo_delete.isVisible())
        self.assertFalse(ui.undo_delete.isEnabled())
        self.assertEqual(load_item(path), item)
        self.assertEqual(ui.footer_glass.geometry(), ui.footer_layout.geometry())
        self.assertEqual(self.backend.commands, before)

    def test_undo_visibility_updates_even_when_status_message_does_not_change(self):
        ui = self.w.studio_ui
        self.show_window()
        ui.navigate(1)
        self.panel.deleted_items = [(self.panel.store.root / 'missing.json', ir_item())]
        ui.sync_feedback()
        self.settle()
        self.assertTrue(ui.undo_delete.isVisible())
        message = self.w.status.text()
        self.panel.deleted_items = []
        ui.sync_feedback()
        self.settle()
        self.assertEqual(self.w.status.text(), message)
        self.assertFalse(ui.undo_delete.isVisible())
