"""Reproducible UI illustrations using a temporary simulated pedal, never hardware."""
from pathlib import Path
import sys
sys.path.insert(0,str(Path(__file__).resolve().parent.parent))
sys.path.insert(0,str(Path(__file__).resolve().parent.parent/'tests'))
from test_studio_ui import StudioTests
from PySide6.QtCore import QTimer
from PySide6.QtWidgets import QApplication
from cubebaby_mod.device_ui import confirm_reset
from test_library_gui import ir_item
from cubebaby_mod.collection import make_item, unpacked
from cubebaby_mod.presets import FACTORY_PRESETS

StudioTests.setUpClass()
test = StudioTests(); test.setUp()
try:
    ui = test.w.studio_ui
    ui.set_reduced_motion(True)
    ui.theme.set_glass('full')
    test.w.resize(1440,960); test.w.show()
    for name in ('Contoh · Clean vintage','Contoh · Lead hangat'):
        test.panel.store.save(make_item('preset',name,FACTORY_PRESETS[:16]))
    sample_a, sample_b = ir_item('IR uji A',.25),ir_item('IR uji B',.125)
    test.panel.store.save(sample_a);test.panel.store.save(sample_b);test.panel.refresh()
    test.panel.set_ab('A',(unpacked(sample_a,'ir'),sample_a['name']))
    test.panel.set_ab('B',(unpacked(sample_b,'ir'),sample_b['name']))
    output=Path(__file__).resolve().parent.parent/'analysis/theme-screenshots'
    output.mkdir(parents=True,exist_ok=True)
    ui.effect_tabs.setCurrentIndex(0);ui.editor_tools.setCurrentIndex(0)
    ui.device_tabs.setCurrentIndex(0)
    for mode in ('dark','light'):
        ui.change_theme(mode)
        for index,name in enumerate(('editor','koleksi','bandingkan-ir','perangkat')):
            ui.navigate(index)
            ui.nav[index].setFocus()
            if index==1:test.panel.list.setCurrentRow(0)
            for _ in range(8):test.app.processEvents()
            ui.audio_meter.peak_hold=-15
            ui.audio_meter.render(-30,-36)
            ui.audio_meter.status.setText('Contoh visual meter · bukan input audio langsung.')
            ui.toast.hide()
            if ui.theme.focus_halo is not None:ui.theme.focus_halo.hide()
            test.w.grab().save(str(output/f'{mode}-{name}.png'))
        menu=ui.appearance_button.menu()
        menu.popup(ui.appearance_button.mapToGlobal(ui.appearance_button.rect().bottomLeft()))
        for _ in range(4):test.app.processEvents()
        menu.grab().save(str(output/f'{mode}-popover.png'));menu.close()
        test.w.status.setText('Contoh: pengaturan berhasil disimpan.')
        ui.sync_feedback()
        for _ in range(3):test.app.processEvents()
        ui.toast.grab().save(str(output/f'{mode}-toast.png'))
        def capture_dialog():
            dialog=QApplication.activeModalWidget()
            if dialog is not None:
                dialog.activateWindow()
                for _ in range(3):test.app.processEvents()
                dialog.grab().save(str(output/f'{mode}-dialog-reset.png'))
                dialog.reject()
        QTimer.singleShot(20,capture_dialog)
        confirm_reset(test.w,'Contoh konfirmasi: preset akan diganti. Tidak ada reset dijalankan saat membuat screenshot.',lambda:None)
    print(output)
finally:
    test.tearDown()
