"""Rendered type hierarchy and density stay consistent across Studio pages."""
import unittest

from PySide6.QtWidgets import QLabel, QFrame
import test_library_gui as library
from cubebaby_mod.library_gui import PresetEditor, BankEditor, SoundEditor


class MetricsTests(unittest.TestCase):
    setUpClass = library.LibraryGuiTests.__dict__['setUpClass']
    setUp = library.LibraryGuiTests.setUp
    tearDown = library.LibraryGuiTests.tearDown
    finish = library.LibraryGuiTests.finish

    def settle(self):
        for _ in range(6):
            self.app.processEvents()

    def test_rendered_type_roles_are_consistent_across_pages_themes_and_density(self):
        ui = self.w.studio_ui
        ui.set_reduced_motion(True)
        self.w.show()
        before = list(self.backend.commands)
        for theme in ('dark', 'light'):
            ui.change_theme(theme)
            for width in (1440, 1000, 1440):
                self.w.resize(width, 900)
                self.settle()
                self.assertGreater(ui.title.font().pixelSize(), 16)
                self.assertGreater(ui.title.font().weight(), ui.subtitle.font().weight())
                for page in ui.pages:
                    for title in page.findChildren(QLabel, 'cardTitle'):
                        self.assertEqual(title.font().pixelSize(), 16)
                        self.assertGreater(title.font().weight(), ui.subtitle.font().weight())
                    for caption in page.findChildren(QLabel, 'muted'):
                        self.assertEqual(caption.font().pixelSize(), 12)
                    for field in page.findChildren(QLabel, 'fieldLabel'):
                        self.assertEqual(field.font().pixelSize(), 14)
        self.assertEqual(self.backend.commands, before)

    def test_panel_insets_remain_uniform_in_each_density_after_reflow(self):
        ui = self.w.studio_ui
        ui.set_reduced_motion(True)
        self.w.show()
        before = list(self.backend.commands)
        panels = ('card', 'meterCard', 'irCard', 'compareA', 'compareB', 'dangerZone')
        for width, padding, gap in ((1440, 16, 12), (1000, 12, 8), (1440, 16, 12)):
            self.w.resize(width, 900)
            self.settle()
            for page in ui.pages:
                for frame in page.findChildren(QFrame):
                    if frame.objectName() not in panels or frame.layout() is None:
                        continue
                    margins = frame.layout().contentsMargins()
                    self.assertEqual((margins.left(), margins.top(), margins.right(), margins.bottom()),
                                     (padding,) * 4, frame.objectName())
                    self.assertEqual(frame.layout().spacing(), gap)
        self.assertEqual(self.backend.commands, before)

    def test_form_dialogs_fit_desktop_height_and_numeric_values_fit_their_fields(self):
        self.w.show()
        self.settle()
        before = list(self.backend.commands)
        for constructor, args in ((PresetEditor, ()), (BankEditor, ([],)), (SoundEditor, ([],))):
            dialog = constructor(self.panel, *args)
            try:
                dialog.show()
                self.settle()
                self.assertLessEqual(dialog.height(), 640)
                self.assertLessEqual(dialog.minimumSizeHint().height(), dialog.height())
            finally:
                dialog.close()
        for _, spin in self.w.effect_controls.values():
            if not spin.isVisible():
                continue
            edit = spin.lineEdit()
            self.assertGreaterEqual(edit.contentsRect().width(),
                                    edit.fontMetrics().horizontalAdvance(str(spin.maximum())))
        self.assertEqual(self.backend.commands, before)
