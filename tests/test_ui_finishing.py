"""Regression checks for shell alignment, popup painting and meter limits."""
import unittest

from PySide6.QtCore import Qt
from PySide6.QtGui import QPalette
from PySide6.QtTest import QTest
from PySide6.QtWidgets import QMenu, QTabWidget

import test_library_gui as library
from cubebaby_mod.theme_tokens import qc


class FinishingTests(unittest.TestCase):
    setUpClass = library.LibraryGuiTests.__dict__['setUpClass']
    setUp = library.LibraryGuiTests.setUp
    tearDown = library.LibraryGuiTests.tearDown
    finish = library.LibraryGuiTests.finish

    def settle(self):
        for _ in range(8):
            self.app.processEvents()

    def test_sidebar_stays_at_left_edge_and_workspace_uses_wide_window(self):
        ui = self.w.studio_ui
        ui.set_reduced_motion(True)
        self.w.show()
        before = list(self.backend.commands)
        for width in (1920, 1000, 2560, 1280):
            self.w.resize(width, 900)
            self.settle()
            self.assertEqual(ui.sidebar.geometry().left(), 0)
            self.assertEqual(ui.workspace.geometry().right(), ui.ambient.width() - 1)
            self.assertEqual(ui.workspace.geometry().left(), ui.sidebar.geometry().right() + 1)
        self.assertEqual(self.backend.commands, before)

    def test_amp_dropdown_paints_items_and_preserves_original_value_handler(self):
        ui = self.w.studio_ui
        ui.set_reduced_motion(True)
        self.w.show()
        self.settle()
        combo = ui.amp_select
        combo.showPopup()
        self.settle()
        view = combo.view()
        self.assertTrue(view.isVisible())
        index = combo.model().index(1, 0)
        rect = view.visualRect(index)
        self.assertFalse(rect.isEmpty())
        shot = view.viewport().grab().toImage()
        ink = view.palette().color(QPalette.Text).rgb()
        self.assertGreater(sum(shot.pixelColor(x, y).rgb() == ink
                               for x in range(rect.left() + 8, min(rect.right(), 130))
                               for y in range(rect.top() + 2, rect.bottom() - 2)), 5)
        QTest.mouseClick(view.viewport(), Qt.LeftButton, pos=rect.center())
        self.finish()
        self.assertEqual(combo.currentIndex(), 1)
        slider, spin = self.w.effect_controls[0]
        self.assertEqual(spin.value(), combo.itemData(1))
        self.assertEqual(slider.value(), spin.value())

    def test_menu_action_text_is_painted_in_both_themes_and_remains_clickable(self):
        ui = self.w.studio_ui
        ui.set_reduced_motion(True)
        self.w.show()
        menu = ui.appearance_button.menu()
        before = list(self.backend.commands)
        for theme in ('dark', 'light'):
            ui.change_theme(theme)
            menu = ui.appearance_button.menu()
            menu.popup(ui.appearance_button.mapToGlobal(ui.appearance_button.rect().bottomLeft()))
            self.settle()
            self.assertFalse(hasattr(menu, '_theme_backdrop'))
            shot = menu.grab().toImage()
            ink = menu.palette().color(QPalette.WindowText).rgb()
            for action in menu.actions():
                if action.isSeparator():
                    continue
                rect = menu.actionGeometry(action).adjusted(30, 4, -30, -4)
                pixels = sum(shot.pixelColor(x, y).rgb() == ink
                             for x in range(rect.left(), rect.right() + 1)
                             for y in range(rect.top(), rect.bottom() + 1))
                self.assertGreater(pixels, 5, action.text())
            menu.close()
        theme_menu = next(action.menu() for action in menu.actions() if action.text() == 'Tema')
        self.assertIsInstance(theme_menu, QMenu)
        theme_menu.actions()[0].trigger()
        self.assertEqual(ui.theme.mode, theme_menu.actions()[0].data() or 'system')
        self.assertEqual(self.backend.commands, before)

    def test_all_desktop_tabs_fit_after_padding_changes(self):
        ui = self.w.studio_ui
        ui.set_reduced_motion(True)
        self.w.resize(1000, 680)
        self.w.show()
        self.settle()
        for offline in (False, True):
            if offline:
                self.w.stop()
            for index in range(4):
                ui.navigate(index)
                self.settle()
                viewport = ui.viewports[index]
                self.assertEqual(viewport.verticalScrollBar().maximum(), 0, (offline, index))
                for tabs in viewport.widget().findChildren(QTabWidget):
                    for tab in range(tabs.count()):
                        tabs.setCurrentIndex(tab)
                        self.settle()
                        panel = tabs.currentWidget()
                        self.assertLessEqual(panel.minimumSizeHint().height(), panel.height())
                        self.assertLessEqual(panel.minimumSizeHint().width(), panel.width())
                        self.assertEqual(viewport.verticalScrollBar().maximum(), 0)
        header = ui.header_layout.geometry()
        self.assertGreater(ui.title.geometry().left(), header.left())
        footer = ui.footer_layout.geometry()
        self.assertGreater(self.w.status.geometry().left(), footer.left())

    def test_meter_extends_to_plus_60_without_changing_reading_reference(self):
        self.w.show()
        self.settle()
        meter = self.w.studio_ui.audio_meter
        self.assertEqual(meter.bar.maximum(), 1200)
        before = list(self.backend.commands)
        for peak, expected in ((-100, 0), (-30, 570), (0, 870), (33, 1200), (40, 1200)):
            meter.peak_hold = peak
            meter.render(peak, peak - 6)
            self.assertEqual(meter.bar.value(), expected)
            self.assertEqual(meter.bar.hold, expected)
            self.assertIn(f'Peak {peak + 27:+.1f}', meter.reading.text())
        meter.bar.finish_motion()
        shot = meter.bar.grab().toImage()
        self.assertEqual(shot.pixelColor(round(shot.width() * .9), shot.height() // 2), qc('danger'))
        meter.reset_peak()
        self.assertEqual(meter.bar.value(), 0)
        self.assertIsNone(meter.bar.hold)
        self.assertEqual(self.backend.commands, before)
