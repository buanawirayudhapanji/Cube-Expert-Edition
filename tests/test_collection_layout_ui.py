"""Card rows fill the collection panel; themed menu arrows stay centered."""
import unittest

from PySide6.QtCore import Qt
from PySide6.QtWidgets import QListView
import test_library_gui as library
from cubebaby_mod.collection import make_item
from cubebaby_mod.presets import FACTORY_PRESETS
from cubebaby_mod.theme_tokens import qc


class CollectionLayoutTests(unittest.TestCase):
    setUpClass = library.LibraryGuiTests.__dict__['setUpClass']
    setUp = library.LibraryGuiTests.setUp
    tearDown = library.LibraryGuiTests.tearDown
    finish = library.LibraryGuiTests.finish

    def settle(self):
        for _ in range(10):
            self.app.processEvents()

    def test_default_cards_fill_horizontal_rows_and_keep_selection_on_resize_and_toggle(self):
        ui = self.w.studio_ui
        ui.set_reduced_motion(True)
        for i in range(8):
            self.panel.store.save(make_item('preset', f'Preset {i + 1}', FACTORY_PRESETS[:16]))
        self.panel.refresh()
        ui.navigate(1)
        self.w.show()
        self.assertTrue(ui.collection_view.isChecked())
        self.assertEqual(self.panel.list.viewMode(), QListView.IconMode)
        before = list(self.backend.commands)
        view = self.panel.list
        view.item(0).setSelected(True)
        view.item(1).setSelected(True)
        selected = {item.data(Qt.UserRole) for item in view.selectedItems()}
        for width, columns in ((1440, 2), (1920, 3), (1000, 1), (1440, 2)):
            self.w.resize(width, 900)
            self.settle()
            rects = [view.visualItemRect(view.item(i)) for i in range(columns + 1)]
            self.assertEqual(len({rect.top() for rect in rects[:columns]}), 1)
            self.assertEqual(len({rect.left() for rect in rects[:columns]}), columns)
            self.assertGreater(rects[columns].top(), rects[0].top())
            self.assertGreater(sum(rect.width() for rect in rects[:columns]), view.viewport().width() - 24)
            self.assertEqual(view.horizontalScrollBar().maximum(), 0)
            self.assertEqual({item.data(Qt.UserRole) for item in view.selectedItems()}, selected)
        ui.collection_view.click()
        self.settle()
        self.assertEqual(view.viewMode(), QListView.ListMode)
        self.assertFalse(ui.preferences.value('collection/grid', True, type=bool))
        self.assertEqual({item.data(Qt.UserRole) for item in view.selectedItems()}, selected)
        ui.collection_view.click()
        self.settle()
        self.assertEqual(view.viewMode(), QListView.IconMode)
        self.assertEqual(self.backend.commands, before)

    def test_combo_and_appearance_chevrons_are_painted_at_vertical_center_in_both_themes(self):
        ui = self.w.studio_ui
        ui.set_reduced_motion(True)
        self.w.show()
        for theme in ('dark', 'light'):
            ui.change_theme(theme)
            self.settle()
            ink = qc('text_secondary')
            for control in (ui.amp_select, ui.appearance_button):
                shot = control.grab().toImage()
                middle = shot.height() // 2
                count = 0
                for x in range(shot.width() - 28, shot.width() - 8):
                    for y in range(middle - 5, middle + 6):
                        color = shot.pixelColor(x, y)
                        if max(abs(color.red() - ink.red()), abs(color.green() - ink.green()),
                               abs(color.blue() - ink.blue())) < 24:
                            count += 1
                self.assertGreaterEqual(count, 3, control.objectName() or control.accessibleName())
