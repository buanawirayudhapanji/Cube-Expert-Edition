"""Verify native semantics and keyboard behavior, without a physical pedal."""
import unittest
from unittest.mock import patch
from PySide6.QtCore import Qt, QTimer
from PySide6.QtGui import QAccessible
from PySide6.QtTest import QTest
from PySide6.QtWidgets import QApplication, QDialogButtonBox
import test_library_gui as library
from cubebaby_mod.device_ui import confirm_reset
from cubebaby_mod.library_gui import PresetEditor, SoundEditor, BankEditor


class AccessibilityTests(unittest.TestCase):
    setUpClass = library.LibraryGuiTests.__dict__['setUpClass']
    setUp = library.LibraryGuiTests.setUp
    tearDown = library.LibraryGuiTests.tearDown
    finish = library.LibraryGuiTests.finish

    def settle(self):
        for _ in range(5):
            self.app.processEvents()

    def test_native_slider_and_tab_roles_expose_real_values(self):
        ui = self.w.studio_ui
        self.w.show(); ui.navigate(0); self.settle()
        slider, spin = self.w.effect_controls[1]
        accessible = QAccessible.queryAccessibleInterface(slider)
        self.assertEqual(accessible.role(), QAccessible.Role.Slider)
        self.assertEqual(accessible.text(QAccessible.Text.Name), 'Gain')
        values = accessible.valueInterface()
        self.assertEqual(values.minimumValue(), slider.minimum())
        self.assertEqual(values.maximumValue(), slider.maximum())
        slider.setValue(slider.minimum())
        self.assertEqual(values.currentValue(), slider.value())
        self.assertIn(f'Gain: {slider.value()} nilai pedal', accessible.text(QAccessible.Text.Description))
        self.assertEqual(spin.value(), slider.value())
        tabs = QAccessible.queryAccessibleInterface(ui.effect_tabs.tabBar())
        self.assertEqual(tabs.role(), QAccessible.Role.PageTabList)
        self.assertEqual(tabs.child(0).role(), QAccessible.Role.PageTab)
        # Qt's tab-list name follows its current tab; the parent names the group.
        group = QAccessible.queryAccessibleInterface(ui.effect_tabs)
        self.assertEqual(group.text(QAccessible.Text.Name), 'Bagian efek')
        ui.effect_tabs.setCurrentIndex(1)
        self.assertTrue(tabs.child(1).state().selected)
        self.assertEqual(ui.effect_tabs.currentWidget().accessibleName(), 'Delay')

    def test_skip_navigation_tab_order_and_narrow_page_shortcuts(self):
        ui = self.w.studio_ui
        self.w.show(); self.w.activateWindow(); self.settle()
        before = list(self.backend.commands)
        ui.navigate(0); ui.nav[0].setFocus(); self.settle()
        QTest.keyClick(ui.nav[0], Qt.Key_F6); self.settle()
        self.assertTrue(ui.pages[0].isAncestorOf(QApplication.focusWidget()))
        QTest.keyClick(QApplication.focusWidget(), Qt.Key_F6, Qt.ShiftModifier)
        self.assertTrue(ui.nav[0].hasFocus())
        ui.skip_navigation.setFocus(); self.settle()
        self.assertGreaterEqual(ui.skip_navigation.height(), 44)
        QTest.keyClick(ui.skip_navigation, Qt.Key_Return); self.settle()
        self.assertTrue(ui.pages[0].isAncestorOf(QApplication.focusWidget()))
        slider, spin = self.w.effect_controls[1]
        slider.setFocus(); self.settle()
        QTest.keyClick(slider, Qt.Key_Tab)
        self.assertTrue(spin.hasFocus())
        self.w.resize(580, 720); self.settle()
        QTest.keyClick(QApplication.focusWidget(), Qt.Key_4, Qt.AltModifier); self.settle()
        self.assertEqual(ui.stack.currentIndex(), 3)
        QTest.keyClick(QApplication.focusWidget(), Qt.Key_F6, Qt.ShiftModifier)
        self.assertTrue(ui.bottom_buttons[3].hasFocus())
        self.assertEqual(self.backend.commands, before)

    def test_focus_survives_reparenting_and_moves_out_of_hidden_page(self):
        ui = self.w.studio_ui
        self.w.show(); self.w.activateWindow(); ui.navigate(0); self.settle()
        slider = self.w.effect_controls[5][0]
        slider.setFocus(); self.settle()
        self.assertTrue(slider.hasFocus())
        for width in (1000, 1400, 1000):
            self.w.resize(width, 900); self.settle()
            self.assertTrue(slider.hasFocus())
        ui.navigate(1); self.settle()
        focus = QApplication.focusWidget()
        self.assertIsNotNone(focus)
        self.assertTrue(ui.pages[1].isAncestorOf(focus))
        self.assertTrue(focus.isVisible())

    def test_status_announcements_are_coalesced_and_do_not_move_focus(self):
        ui = self.w.studio_ui
        self.w.show(); self.w.activateWindow(); ui.navigate(1); self.settle()
        ui.announcer.timer.stop(); ui.announcer.pending = None
        ui.announcer.last = None
        self.panel.search.setFocus(); self.settle()
        before = list(self.backend.commands)
        captured = []
        def record(event):
            captured.append((event.message(), event.politeness()))
        with patch('cubebaby_mod.accessibility_ui.QtGui.QAccessible.updateAccessibility', side_effect=record):
            ui._connected = False
            self.w.status.setText('Preset berhasil tersimpan.')
            ui.sync_feedback(); ui.announcer.deliver()
            self.assertEqual(captured[-1][1], QAccessible.AnnouncementPoliteness.Polite)
            self.assertIn('tersimpan', captured[-1][0])
            self.assertIn('Terhubung ke', captured[-1][0])
            count = len(captured)
            ui.sync_feedback(); ui.announcer.deliver()
            self.assertEqual(len(captured), count)
            self.w.status.setText('Penulisan gagal. Periksa koneksi.')
            ui.report_error(self.w.status.text())
            ui.announcer.announce('Proses selesai.')
            ui.announcer.deliver()
            self.assertEqual(captured[-1], ('Penulisan gagal. Periksa koneksi.',
                                          QAccessible.AnnouncementPoliteness.Assertive))
            self.w.stop(); ui.sync_feedback(); ui.announcer.deliver()
            self.assertIn('Pedal terputus', captured[-1][0])
            ui.audio_meter.status.setText('Input tidak dapat dibuka. Periksa perangkat audio.')
            ui.sync_feedback(); ui.announcer.deliver()
            self.assertEqual(captured[-1][1], QAccessible.AnnouncementPoliteness.Assertive)
            self.assertIn('Input tidak dapat dibuka', captured[-1][0])
        self.assertTrue(self.panel.search.hasFocus())
        self.assertEqual(self.backend.commands, before)

    def test_reset_dialog_traps_focus_defaults_to_cancel_and_escape_cancels(self):
        self.w.show(); self.w.activateWindow(); self.settle()
        observed = []
        actions = []
        def inspect_dialog():
            dialog = QApplication.activeModalWidget()
            if dialog is None:
                return
            try:
                # Activate the modal surface explicitly for the headless plugin.
                dialog.activateWindow(); self.settle()
                buttons = dialog.findChild(QDialogButtonBox)
                cancel = buttons.button(QDialogButtonBox.Cancel)
                observed.append(dialog.isModal() and cancel.hasFocus() and cancel.isDefault())
                for _ in range(10):
                    QTest.keyClick(QApplication.focusWidget(), Qt.Key_Tab)
                    observed.append(dialog.isAncestorOf(QApplication.focusWidget()))
                QTest.keyClick(QApplication.focusWidget(), Qt.Key_Escape)
            finally:
                dialog.reject()
        QTimer.singleShot(0, inspect_dialog)
        confirm_reset(self.w, 'Ketiga preset akan diganti.', lambda: actions.append('reset'))
        self.assertEqual(len(observed), 11)
        self.assertTrue(all(observed))
        self.assertEqual(actions, [])

    def test_collection_dialog_inputs_have_names_and_do_not_write_device(self):
        before = list(self.backend.commands)
        preset = PresetEditor(self.panel)
        bank = BankEditor(self.panel, [])
        sound = SoundEditor(self.panel, [])
        for editor in (preset, bank, sound):
            self.assertTrue(editor.accessibleName())
            self.assertTrue(editor.name.accessibleName())
        for control in preset.controls.values():
            interface = QAccessible.queryAccessibleInterface(control)
            self.assertTrue(interface.text(QAccessible.Text.Name))
        self.assertTrue(all(combo.accessibleName() for _, _, combo in bank.targets))
        self.assertEqual(sound.preset.accessibleName(), 'Sumber preset')
        self.assertEqual(sound.ir.accessibleName(), 'Sumber IR kabinet')
        for editor in (preset, bank, sound):
            editor.close()
        self.assertEqual(self.backend.commands, before)
