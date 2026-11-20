"""Work bounds and cache correctness, rather than machine-dependent FPS claims."""
from pathlib import Path
import unittest
from unittest.mock import patch
from PySide6.QtCore import Qt, QAbstractAnimation, QAbstractListModel, qInstallMessageHandler
from PySide6.QtTest import QAbstractItemModelTester, QTest
from PySide6.QtWidgets import QAbstractItemView, QListView
import test_library_gui as library
from cubebaby_mod.collection import atomic_json, load_item, make_item, unpacked
from cubebaby_mod.presets import FACTORY_PRESETS
from cubebaby_mod.rendering_ui import Waveform, waveform_geometry, ir_waveform_samples
from cubebaby_mod.studio_components import CollectionItemDelegate
from cubebaby_mod.library_gui import item_summary


class RenderingTests(unittest.TestCase):
    setUpClass = library.LibraryGuiTests.__dict__['setUpClass']
    setUp = library.LibraryGuiTests.setUp
    tearDown = library.LibraryGuiTests.tearDown
    finish = library.LibraryGuiTests.finish

    def settle(self, count=5):
        for _ in range(count):
            self.app.processEvents()

    def test_meter_animation_keeps_snapshot_exact_and_never_syncs_editor(self):
        ui = self.w.studio_ui
        self.w.resize(1400, 900); self.w.show(); ui.navigate(0)
        ui.editor_tools.setCurrentIndex(0); self.settle()
        meter = ui.audio_meter
        meter.bar.set_motion_enabled(True)
        meter.bar.setValue(0); meter.bar.finish_motion()
        self.assertTrue(meter.bar.isVisible())
        self.assertEqual(meter.timer.interval(), 50)
        before = list(self.backend.commands)
        with patch.object(ui, 'sync') as sync, patch.object(self.w, 'change_effect') as change:
            meter.peak_hold = -30
            meter.render(-30, -36)
            exact = meter.bar.value()
            self.assertEqual(exact, 570)
            meter.bar.animation.setCurrentTime(25)
            self.assertGreater(meter.bar.display_level, 0)
            self.assertLess(meter.bar.display_level, meter.bar.ratio(exact))
            self.assertEqual(meter.bar.value(), exact)
            self.assertIn('Peak -3.0', meter.reading.text())
            self.assertIn('RMS -9.0', meter.reading.text())
            meter.bar.grab()
            sync.assert_not_called(); change.assert_not_called()
        ui.navigate(1); self.settle()
        self.assertEqual(meter.bar.animation.state(), QAbstractAnimation.Stopped)
        self.assertEqual(meter.bar.display_level, meter.bar.ratio(exact))
        self.assertEqual(self.backend.commands, before)

    def test_reduced_motion_and_reset_snap_without_changing_readings(self):
        ui = self.w.studio_ui
        self.w.show(); ui.navigate(0); self.settle()
        meter = ui.audio_meter
        ui.set_reduced_motion(True)
        meter.render(-6, -12)
        self.assertEqual(meter.bar.animation.state(), QAbstractAnimation.Stopped)
        self.assertEqual(meter.bar.display_level, meter.bar.ratio(meter.bar.value()))
        meter.reset_peak()
        self.assertIsNone(meter.bar.hold)
        self.assertEqual(meter.bar.value(), 0)
        self.assertEqual(meter.bar.display_level, 0)

    def test_waveform_cache_reuses_geometry_across_sizes_and_preserves_coordinates(self):
        waveform_geometry.cache_clear()
        samples = (.5, -2., 1., 0.)
        first, second = Waveform(), Waveform()
        first.set_values(samples); second.set_values(samples)
        self.assertIs(first._path, second._path)
        self.assertEqual(first.peak, 2.)
        before = waveform_geometry.cache_info()
        for width, height in ((220, 100), (480, 200), (800, 150)):
            first.resize(width, height)
            first.grab()
            for index, value in enumerate(samples):
                point = first._path.elementAt(index)
                self.assertAlmostEqual(point.x * (width - 1), index * (width - 1) / 3)
                self.assertAlmostEqual(point.y * (height / 2 - 4) + height / 2,
                                       height / 2 - value / 2 * (height / 2 - 4))
        self.assertEqual(waveform_geometry.cache_info(), before)
        first.set_values(samples)
        self.assertEqual(waveform_geometry.cache_info(), before)
        first.set_values((.25, -.25))
        self.assertIsNot(first._path, second._path)
        for index in range(40):
            first.set_values((0., index / 40))
        self.assertLessEqual(waveform_geometry.cache_info().currsize, 32)
        first.close(); second.close()

    def test_ir_display_cache_invalidates_on_content_and_reuses_previous_source(self):
        from cubebaby_mod.protocol import parse_ir_slot
        ir_waveform_samples.cache_clear()
        a = unpacked(library.ir_item('A', .25), 'ir')
        b = unpacked(library.ir_item('B', .5), 'ir')
        before = list(self.backend.commands)
        with patch('cubebaby_mod.rendering_ui.parse_ir_slot', wraps=parse_ir_slot) as parse:
            first = ir_waveform_samples(a)
            second = ir_waveform_samples(b)
            self.assertNotEqual(first, second)
            self.assertIs(first, ir_waveform_samples(a))
            self.assertEqual(parse.call_count, 2)
        self.assertEqual(self.backend.commands, before)

    def test_collection_metadata_cache_survives_filter_and_refresh_invalidates_it(self):
        panel = self.panel
        item = make_item('preset', 'Cached item', FACTORY_PRESETS[:16])
        path = panel.store.save(item); panel.refresh(); panel.display_cache.clear()
        stat = Path.stat
        with patch('cubebaby_mod.library_gui.item_summary', wraps=item_summary) as summary:
            with patch.object(Path, 'stat', autospec=True, side_effect=stat) as disk_stat:
                panel.render()
                self.assertEqual(summary.call_count, 0)
                panel.list.item(0).data(Qt.UserRole + 2)
                calls = disk_stat.call_count
                self.assertEqual(summary.call_count, 1)
                panel.search.setText('Cached')
                panel.sort_mode.setCurrentIndex(panel.sort_mode.findData('name'))
                panel.render()
                panel.list.item(0).data(Qt.UserRole + 2)
                self.assertEqual(disk_stat.call_count, calls)
                self.assertEqual(summary.call_count, 1)
        raw = bytearray(FACTORY_PRESETS[:16]); raw[1] = 1
        atomic_json(path, make_item('preset', 'Cached item', raw))
        panel.refresh()
        details = panel.list.item(0).data(Qt.UserRole + 2)
        self.assertIn('Gain 1', details[2])
        self.assertEqual(panel.list.item(0).data(Qt.UserRole), str(path))

    def test_large_collection_paints_viewport_and_keeps_last_item_actions_available(self):
        class CountingDelegate(CollectionItemDelegate):
            def __init__(self, parent):
                super().__init__(parent); self.rows = set()
            def paint(self, painter, option, index):
                self.rows.add(index.row())
                super().paint(painter, option, index)
        panel = self.panel
        shared = make_item('preset', 'Item virtual', FACTORY_PRESETS[:16])
        target = make_item('preset', 'ZZZ terakhir', FACTORY_PRESETS[:16])
        target_path = panel.store.save(target)
        panel.sort_mode.setCurrentIndex(panel.sort_mode.findData('name'))
        panel.entries = [(Path(self.tmp.name) / f'virtual-{i}.json', shared) for i in range(5000)]
        panel.entries.append((target_path, target))
        delegate = CountingDelegate(panel.list)
        panel.list.setItemDelegate(delegate)
        before = list(self.backend.commands)
        panel.render()
        self.w.resize(1400, 900); self.w.show(); self.w.studio_ui.navigate(1)
        self.settle(60); panel.list.viewport().grab()
        self.assertEqual(panel.list.count(), 5001)
        self.assertTrue(panel.list.uniformItemSizes())
        self.assertEqual(panel.list.layoutMode(), QListView.Batched)
        self.assertGreater(len(delegate.rows), 0)
        self.assertLess(len(delegate.rows), 500)
        last = panel.list.item(5000)
        panel.list.scrollToItem(last, QAbstractItemView.PositionAtBottom)
        self.settle(60)
        panel.list.setCurrentItem(last); self.settle()
        self.assertEqual(last.data(Qt.UserRole), str(target_path))
        self.assertTrue(panel.list.visualItemRect(last).intersects(panel.list.viewport().rect()))
        self.assertEqual(panel.selected()['name'], target['name'])
        self.assertTrue(panel.export_file.isEnabled())
        destination = Path(self.tmp.name) / 'last-export.json'
        with patch('cubebaby_mod.library_gui.QFileDialog.getSaveFileName',
                   return_value=(str(destination), 'JSON (*.json)')):
            panel.export_selected()
        self.assertEqual(load_item(destination), target)
        self.assertEqual(self.backend.commands, before)

    def test_virtual_model_defers_metadata_and_bounds_its_cache(self):
        panel = self.panel
        panel.sort_mode.setCurrentIndex(panel.sort_mode.findData('name'))
        shared = make_item('preset', 'Suara virtual', FACTORY_PRESETS[:16])
        panel.entries = [(Path(self.tmp.name) / f'virtual-{i}.json', shared) for i in range(10000)]
        before = list(self.backend.commands)
        with patch('cubebaby_mod.library_gui.item_summary', wraps=item_summary) as summary:
            panel.render()
            self.assertIsInstance(panel.list.model(), QAbstractListModel)
            self.assertEqual(panel.list.count(), 10000)
            self.assertEqual(summary.call_count, 0)
            self.assertEqual(len(panel.display_cache), 0)
            for index in range(640):
                panel.list.item(index).data(Qt.UserRole + 2)
            self.assertEqual(summary.call_count, 640)
            self.assertEqual(len(panel.display_cache), 512)
            panel.list.item(639).data(Qt.UserRole + 2)
            self.assertEqual(summary.call_count, 640)
            panel.list.item(0).data(Qt.UserRole + 2)
            self.assertEqual(summary.call_count, 641)
            self.assertEqual(len(panel.display_cache), 512)
        self.assertEqual(self.backend.commands, before)

    def test_virtual_model_keeps_keyboard_multiselect_filter_grid_and_activation(self):
        panel = self.panel; ui = self.w.studio_ui
        for name in ('Suara A', 'Suara B', 'Suara C'):
            panel.store.save(make_item('preset', name, FACTORY_PRESETS[:16]))
        panel.sort_mode.setCurrentIndex(panel.sort_mode.findData('name'))
        panel.refresh()
        failures = []
        def messages(kind, context, message):
            if context.category == 'qt.modeltest':
                failures.append(message)
        previous = qInstallMessageHandler(messages)
        tester = QAbstractItemModelTester(panel.list.model(), QAbstractItemModelTester.Warning)
        try:
            self.w.show(); self.w.activateWindow(); ui.navigate(1); self.settle()
            ui.collection_view.setChecked(False)
            before = list(self.backend.commands)
            panel.list.setFocus()
            QTest.keyClick(panel.list, Qt.Key_End)
            QTest.keyClick(panel.list, Qt.Key_Up, Qt.ShiftModifier)
            self.assertEqual(len(panel.list.selectedItems()), 2)
            selected = {item.data(Qt.UserRole) for item in panel.list.selectedItems()}
            old = panel.list.currentItem()
            panel.search.setText('Suara')
            self.assertEqual({item.data(Qt.UserRole) for item in panel.list.selectedItems()}, selected)
            self.assertIsNone(old.data(Qt.UserRole))
            old.setSelected(True)
            self.assertEqual(len(panel.list.selectedItems()), 2)
            ui.collection_view.click()
            self.assertEqual(panel.list.viewMode(), QListView.IconMode)
            self.w.resize(580, 720); self.settle()
            ui.collection_drawer.setCurrentIndex(0); panel.list.setFocus(); self.settle()
            QTest.keyClick(panel.list, Qt.Key_End)
            self.assertEqual(panel.selected()['name'], 'Suara C')
            QTest.keyClick(panel.list, Qt.Key_Return); self.settle()
            self.assertEqual(ui.collection_drawer.currentIndex(), 1)
            self.assertTrue(ui.collection_menu_button.hasFocus())
            self.assertEqual(self.backend.commands, before)
            self.assertEqual(failures, [])
        finally:
            tester.deleteLater()
            qInstallMessageHandler(previous)
