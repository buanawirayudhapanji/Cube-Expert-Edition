"""Short offscreen animation probe. Simulation, not display-vsync or USB latency."""
import json
import math
import sys
import time
from pathlib import Path
sys.path.insert(0,str(Path(__file__).resolve().parent.parent))
sys.path.insert(0,str(Path(__file__).resolve().parent.parent/'tests'))
from test_studio_ui import StudioTests
from PySide6.QtCore import QObject, QEvent, QTimer, QEventLoop, Qt
from PySide6.QtTest import QTest

StudioTests.setUpClass(); test=StudioTests();test.setUp()
try:
    ui=test.w.studio_ui
    ui.preferences.setValue('accessibility/reducedMotion',False)
    ui.audio_meter.bar.set_motion_enabled(True)
    ui.theme.set_glass('full');test.w.show();ui.navigate(0);ui.editor_tools.setCurrentIndex(0)
    for _ in range(5):test.app.processEvents()
    class Counter(QObject):
        def __init__(self):super().__init__();self.values=[]
        def eventFilter(self,widget,event):
            if event.type()==QEvent.Paint:self.values.append(round(widget.display_level,6))
            return False
    counter=Counter();ui.audio_meter.bar.installEventFilter(counter)
    timer=QTimer();timer.setInterval(50);steps=[0]
    def feed():
        steps[0]+=1;ui.audio_meter.render(-40+25*math.sin(steps[0]/4),-45)
    timer.timeout.connect(feed);timer.start()
    loop=QEventLoop(); stopper=QTimer(); stopper.setTimerType(Qt.PreciseTimer); stopper.setSingleShot(True); stopper.timeout.connect(loop.quit); stopper.start(2000)
    start=time.perf_counter();loop.exec();elapsed=time.perf_counter()-start;timer.stop()
    changed=sum(value!=previous for previous,value in zip(counter.values,counter.values[1:]))
    result={'environment':'Qt offscreen, data meter simulasi; bukan FPS layar fisik',
            'seconds':round(elapsed,3),'glass':ui.theme.effective_glass,
            'paint_calls':len(counter.values),'visible_fill_changes':changed,
            'fill_updates_per_second':round(changed/elapsed,2),
            'ambient_cache_generations':ui.ambient.generation}
    if len(sys.argv)>1:Path(sys.argv[1]).write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(result,indent=2))
finally:test.tearDown()
