"""Bounded presentation caches and native animation; no audio/MIDI processing."""
from functools import lru_cache
from PySide6.QtCore import QVariantAnimation, QRectF, Qt
from PySide6.QtGui import QColor, QPainter, QPainterPath, QPen, QPixmap, QLinearGradient
from PySide6.QtWidgets import QProgressBar, QWidget
from .protocol import parse_ir_slot
from .ui_preferences import reduced_motion
from .theme_tokens import qc, palette


class AnimatedLevelBar(QProgressBar):
    """The accessible value stays exact; only the painted fill is interpolated."""
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setAttribute(Qt.WA_OpaquePaintEvent)
        self.hold = None
        self.display_level = 0.0
        self.tone = 'success'
        self.fill_limit = None
        self._fill_cache = None
        self._fill_key = None
        self.motion_enabled = not reduced_motion()
        self.animation = QVariantAnimation(self)
        self.animation.setDuration(50)
        self.animation.valueChanged.connect(self.animate_fill)
        self.valueChanged.connect(self.target_changed)

    def setValue(self, value):
        # QProgressBar normally repaints synchronously on every measurement.
        # Preserve its value/accessible event, but coalesce painting with animation.
        enabled = self.updatesEnabled()
        self.setUpdatesEnabled(False)
        super().setValue(value)
        self.setUpdatesEnabled(enabled)

    def ratio(self, value):
        span = self.maximum() - self.minimum()
        return min(1.0, max(0.0, (value - self.minimum()) / span)) if span else 0.0

    def target_changed(self, value):
        target = self.ratio(value)
        if not self.isVisible() or not self.motion_enabled:
            self.animation.stop()
            self.display_level = target
            self.update()
            return
        running = self.animation.state() == QVariantAnimation.Running
        start = self.display_level
        self.animation.setStartValue(start)
        self.animation.setEndValue(target)
        self.animation.setCurrentTime(0)
        if not running:
            self.animation.start()

    def animate_fill(self, value):
        self.display_level = float(value)
        self.update()

    def finish_motion(self):
        self.animation.stop()
        self.display_level = self.ratio(self.value())
        self.update()

    def hideEvent(self, event):
        self.finish_motion()
        super().hideEvent(event)

    def set_motion_enabled(self, enabled):
        self.motion_enabled = enabled
        if not enabled:
            self.finish_motion()

    def paintEvent(self, event):
        # No widget geometry, stylesheet, labels or editor state changes per frame.
        painter = QPainter(self)
        painter.fillRect(self.rect(), qc('meter_track'))
        painter.save()
        painter.scale(self.display_level, 1.0)
        key = (self.width(),self.height(),palette()['accent'],self.fill_limit)
        if key != self._fill_key:
            self._fill_key = key
            self._fill_cache = QPixmap(self.size())
            fill = QPainter(self._fill_cache)
            gradient = QLinearGradient(0,0,self.width(),0)
            limit = self.ratio(self.fill_limit) if self.fill_limit is not None else 1.0
            for stop, token in ((0,'success'),(.68,'accent'),(.86,'warning'),(1,'danger')):
                gradient.setColorAt(stop * limit,qc(token))
            gradient.setColorAt(1,qc('danger'))
            fill.fillRect(self.rect(),gradient); fill.end()
        source = QRectF(0,0,self.width()*self.display_level,self.height())
        painter.drawPixmap(QRectF(self.rect()),self._fill_cache,source)
        painter.restore()
        if self.hold is not None:
            x = round(self.ratio(self.hold) * (self.width() - 3))
            painter.fillRect(x-1, 0, 5, self.height(), qc('meter_marker_outline'))
            painter.fillRect(x, 1, 3, self.height() - 2, qc('meter_marker'))


@lru_cache(maxsize=32)
def waveform_geometry(samples):
    """Cache immutable sample content, independent of window dimensions."""
    path = QPainterPath()
    peak = max((abs(value) for value in samples), default=0.0)
    if len(samples) >= 2:
        scale = max(1.0, peak)
        path.moveTo(0, -samples[0] / scale)
        for index in range(1, len(samples)):
            path.lineTo(index / (len(samples) - 1), -samples[index] / scale)
    return path, peak


@lru_cache(maxsize=32)
def ir_waveform_samples(raw):
    """Reuse the existing parser result for display only; never rewrite raw IR."""
    return tuple(parse_ir_slot(raw, 0, 0).get('coefficients', ()))


class Waveform(QWidget):
    def __init__(self):
        super().__init__()
        self.values = []
        self._samples = ()
        self._path, self.peak = waveform_geometry(())
        self.setMinimumHeight(115)

    def set_values(self, values):
        samples = tuple(values)
        if samples == self._samples:
            return
        self._samples = samples
        self.values = list(samples)
        self._path, self.peak = waveform_geometry(samples)
        self.update()

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.fillRect(self.rect(), qc('control'))
        painter.setPen(qc('wave_grid'))
        for index in range(1, 4):
            painter.drawLine(0, self.height()*index//4, self.width(), self.height()*index//4)
        if len(self._samples) < 2:
            return
        painter.translate(0, self.height() / 2)
        painter.scale(max(1, self.width() - 1), max(1, self.height() / 2 - 4))
        pen = QPen(qc(getattr(self, 'tone', 'accent_text')))
        pen.setCosmetic(True)
        painter.setPen(pen)
        painter.drawPath(self._path)
