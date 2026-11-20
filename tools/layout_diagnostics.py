"""Dump simulated page geometry for packaging failures; never uses a real pedal."""
from pathlib import Path
import sys
sys.path[:0] = [str(Path(__file__).resolve().parent.parent), str(Path(__file__).resolve().parent.parent / 'tests')]
from test_studio_ui import StudioTests
from PySide6.QtWidgets import QWidget, QTabWidget

StudioTests.setUpClass()
test = StudioTests()
test.setUp()
overflow = []
try:
    window, app = test.w, test.app
    ui = window.studio_ui
    ui.set_reduced_motion(True)
    window.show()
    for button in ui.nav:
        button.click()
        app.processEvents()
    window.resize(1000, 680)
    for page in range(4):
        ui.navigate(page)
        for _ in range(10):
            app.processEvents()
        root = ui.pages[page]
        print('PAGE', page, root.size().toTuple(), root.minimumSizeHint().toTuple())
        if root.minimumSizeHint().width() > root.width() or root.minimumSizeHint().height() > root.height():
            overflow.append(page)
        if page == 1:
            for button in (test.panel.new_preset, ui.collection_create, test.panel.import_file):
                print('TOOLBAR', button.text(), button.size().toTuple(), button.minimumSizeHint().toTuple(),
                      button.font().pixelSize(), button.fontMetrics().horizontalAdvance(button.text()))
        for widget in [root, *root.findChildren(QWidget)]:
            if widget.layout() is not None or isinstance(widget, QTabWidget):
                print(widget.metaObject().className(), widget.objectName(),
                      widget.size().toTuple(), widget.minimumSizeHint().toTuple())
finally:
    test.tearDown()
if overflow:
    raise SystemExit('Page layout overflow: ' + repr(overflow))
