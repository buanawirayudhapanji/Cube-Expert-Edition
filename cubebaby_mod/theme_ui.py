"""Native cached glass, ambient background, preferences and theme transitions."""
import math
import os
import time
from collections import deque
from pathlib import Path
from tempfile import TemporaryDirectory
from shiboken6 import isValid
from PySide6.QtCore import QObject, QEvent, QPoint, QRectF, QTimer, Qt, QPropertyAnimation, QCoreApplication
from PySide6.QtGui import QImage, QPixmap, QPainter, QPainterPath, QRadialGradient, QLinearGradient, QPen, QPalette, QColor, QIcon
from PySide6.QtWidgets import (
    QApplication, QWidget, QFrame, QDialog, QMenu, QGraphicsScene,
    QGraphicsBlurEffect, QLabel, QGraphicsOpacityEffect,
    QAbstractButton, QPushButton, QToolButton, QFileDialog, QScrollArea, QStackedWidget, QTabWidget,
)
from .theme_tokens import palette, qc, css, set_active_theme
from .theme_styles import stylesheet
from .ui_preferences import settings, reduced_motion, accessibility_hints


def theme_root(widget):
    current = widget
    while current is not None:
        if isinstance(current, AmbientBackground):
            return current
        if isinstance(current, DialogBackdrop):
            return current.ambient
        current = current.parentWidget()
    owner = widget.window()
    return getattr(getattr(owner, 'studio_ui', None), 'ambient', None)


class AmbientBackground(QWidget):
    """Only the static ambient texture is blurred, never the content subtree."""
    def __init__(self, parent=None, blur_radius=20):
        super().__init__(parent)
        self.blur_radius = blur_radius
        self.cache = None
        self.blurred = None
        self.mode = 'full'
        self.blur_available = True
        self.generation = 0
        self.offset = QPoint(0, 0)
        self.started = time.monotonic()
        self.rebuild_timer = QTimer(self)
        self.rebuild_timer.setSingleShot(True)
        self.rebuild_timer.timeout.connect(self.rebuild)
        self.drift = QTimer(self)
        self.drift.setInterval(250)
        self.drift.timeout.connect(self.advance)
        self.setAttribute(Qt.WA_OpaquePaintEvent)

    def configure(self, mode):
        self.mode = mode
        self.cache = self.blurred = None
        if mode == 'full' and not reduced_motion():
            self.drift.start()
        else:
            self.drift.stop()
            self.offset = QPoint(0, 0)
        self.update()

    def advance(self):
        # A 60 s cycle, reusing pixels. No gradient/blur work happens on frames.
        phase = (time.monotonic() - self.started) / 60 * math.tau
        self.offset = QPoint(round(12 * math.sin(phase)), round(8 * math.cos(phase)))
        if self.isVisible():
            self.update()
            for surface in self.findChildren(GlassSurface):
                if surface.isVisible():
                    surface.update()

    def resizeEvent(self, event):
        super().resizeEvent(event)
        self.rebuild_timer.start(150)

    def rebuild(self):
        if self.width() < 1 or self.height() < 1:
            return
        width, height = self.width() + 64, self.height() + 64
        image = QImage(width, height, QImage.Format_ARGB32_Premultiplied)
        image.fill(qc('bg_base'))
        painter = QPainter(image)
        if self.mode != 'off':
            for cx,cy,radius,token in ((.12,.12,.67,'bg_glow_1'),(.91,.85,.59,'bg_glow_2'),(.50,.40,.48,'bg_glow_3')):
                gradient = QRadialGradient(width*cx, height*cy, max(width,height)*radius)
                gradient.setColorAt(0, qc(token))
                clear = qc(token); clear.setAlpha(0)
                gradient.setColorAt(1, clear)
                painter.fillRect(image.rect(), gradient)
        painter.end()
        self.cache = QPixmap.fromImage(image)
        self.blurred = self.cache
        if self.mode != 'off' and self.blur_available:
            try:
                scene = QGraphicsScene()
                item = scene.addPixmap(self.cache)
                blur = QGraphicsBlurEffect()
                blur.setBlurRadius(self.blur_radius if self.mode == 'full' else 16)
                blur.setBlurHints(QGraphicsBlurEffect.PerformanceHint)
                item.setGraphicsEffect(blur)
                output = QImage(image.size(), QImage.Format_ARGB32_Premultiplied)
                output.fill(qc('bg_base'))
                target = QPainter(output)
                scene.render(target, QRectF(output.rect()), QRectF(image.rect()))
                target.end()
                self.blurred = QPixmap.fromImage(output)
            except (RuntimeError, MemoryError):
                self.blur_available = False
                self.mode = 'off'
                self.drift.stop()
        self.generation += 1
        self.update()

    def paintEvent(self, event):
        if self.cache is None:
            self.rebuild()
        painter = QPainter(self)
        painter.fillRect(self.rect(), qc('bg_base'))
        if self.cache is not None:
            source = QRectF(32+self.offset.x(),32+self.offset.y(),self.width(),self.height())
            painter.drawPixmap(QRectF(self.rect()),self.cache,source)


class GlassSurface(QFrame):
    def __init__(self, parent=None, level=2):
        super().__init__(parent)
        self.glass_level = level
        self.setAttribute(Qt.WA_TranslucentBackground)

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.setRenderHint(QPainter.Antialiasing)
        rect = QRectF(self.rect()).adjusted(.5,.5,-.5,-.5)
        radius = 0 if self.objectName() == 'sidebar' else 16
        path = QPainterPath(); path.addRoundedRect(rect,radius,radius)
        root = theme_root(self)
        mode = root.mode if root is not None else 'off'
        level = self.glass_level
        # A nested card gets a tonal surface, never another blur pass.
        ancestor = self.parentWidget()
        nested = False
        while ancestor is not None and ancestor is not root:
            if isinstance(ancestor,GlassSurface) and ancestor.glass_level >= 2:
                nested = True; break
            ancestor = ancestor.parentWidget()
        painter.setClipPath(path)
        if mode != 'off' and root is not None and not nested and root.blur_available:
            if root.blurred is None:
                root.rebuild()
            position = root.mapFromGlobal(self.mapToGlobal(QPoint(0,0)))
            if root.blurred is not None:
                source = QRectF(position.x()+32+root.offset.x(),position.y()+32+root.offset.y(),self.width(),self.height())
                painter.drawPixmap(rect,root.blurred,source)
            painter.fillPath(path,qc(f'glass_{level}'))
        else:
            painter.fillPath(path,qc(f'surface_solid_{level}'))
        if level >= 2:
            shadow = QLinearGradient(0,self.height()-10,0,self.height())
            clear = qc('shadow'); clear.setAlpha(0)
            shadow.setColorAt(0,clear); shadow.setColorAt(1,qc('shadow'))
            painter.fillRect(0,self.height()-10,self.width(),10,shadow)
        painter.setClipping(False)
        pen = QPen(qc('glass_border'),1)
        if self.objectName() == 'compareA': pen.setColor(qc('accent'))
        if self.objectName() == 'compareB': pen.setColor(qc('info'))
        if self.objectName() == 'dangerZone': pen.setColor(qc('danger'))
        painter.setPen(pen); painter.setBrush(Qt.NoBrush); painter.drawPath(path)
        painter.setPen(QPen(qc('glass_highlight'),1))
        painter.drawLine(16,1,max(16,self.width()-16),1)
        # Cheap local shadow, without QGraphicsEffect on a live content subtree.
        painter.setPen(QPen(qc('shadow'),1))
        painter.drawLine(16,self.height()-2,max(16,self.width()-16),self.height()-2)


class DialogBackdrop(QWidget):
    def __init__(self, dialog):
        super().__init__(dialog)
        self.setAttribute(Qt.WA_TransparentForMouseEvents)
        self.ambient = AmbientBackground(self,blur_radius=28)
        self.surface = GlassSurface(self,3)
        self.setGeometry(dialog.rect())
        self.ambient.setGeometry(self.rect())
        self.surface.setGeometry(self.rect())
        self.show(); self.lower()

    def configure(self, mode):
        self.ambient.configure(mode)
        self.surface.update()

    def resizeEvent(self, event):
        super().resizeEvent(event)
        self.ambient.setGeometry(self.rect()); self.surface.setGeometry(self.rect())


class GlassLabel(QLabel):
    glass_level = 3

    def paintEvent(self,event):
        GlassSurface.paintEvent(self,event)
        super().paintEvent(event)


class ControlHalo(QWidget):
    def __init__(self):
        super().__init__()
        self.setAttribute(Qt.WA_TransparentForMouseEvents)
        self.setFocusPolicy(Qt.NoFocus)
        self.hover = False
        self.target = None

    def follow(self, target, hover=False):
        if self.target is not None:
            self.target.removeEventFilter(self)
        self.target = target
        target.installEventFilter(self)
        self.hover = hover
        parent = target.parentWidget()
        self.setParent(parent)
        position = parent.mapFromGlobal(target.mapToGlobal(QPoint(0,0)))
        self.setGeometry(position.x()-4,position.y()-4,target.width()+8,target.height()+8)
        self.show(); self.raise_()

    def eventFilter(self, watched, event):
        if event.type() in (QEvent.Move, QEvent.Resize, QEvent.Hide, QEvent.ParentChange):
            self.hide()
        return False

    def paintEvent(self,event):
        painter=QPainter(self); painter.setRenderHint(QPainter.Antialiasing)
        painter.setBrush(Qt.NoBrush)
        if self.hover:
            for inset in (1,2,3):
                color=qc('accent'); color.setAlphaF(.30/(4-inset))
                painter.setPen(QPen(color,1))
                painter.drawRoundedRect(self.rect().adjusted(inset,inset,-inset,-inset),10,10)
        else:
            painter.setPen(QPen(qc('accent'),1))
            painter.drawRoundedRect(self.rect().adjusted(1,1,-1,-1),11,11)
            painter.setPen(QPen(qc('focus_ring'),2))
            painter.drawRoundedRect(self.rect().adjusted(3,3,-3,-3),9,9)


class ThemeController(QObject):
    def __init__(self, owner):
        super().__init__(owner)
        self.owner = owner
        self.preferences = settings()
        self.mode = self.preferences.value('appearance/theme','system',type=str)
        self.glass_mode = self.preferences.value('appearance/glass','full',type=str)
        if self.mode not in ('system','dark','light'): self.mode = 'system'
        if self.glass_mode not in ('full','light','off'): self.glass_mode = 'full'
        self.reduce_transparency = self.preferences.value('appearance/reducedTransparency',False,type=bool)
        self.auto_light = False
        self.root = None
        app = QApplication.instance()
        if not hasattr(app,'_theme_assets'):
            app._theme_assets = TemporaryDirectory(prefix='cubebaby-theme-')
        self.assets = app._theme_assets
        self.frame_samples = deque(maxlen=90)
        self.frame_timer = QTimer(self)
        self.frame_timer.setTimerType(Qt.PreciseTimer)
        self.frame_timer.setInterval(16)
        self.frame_timer.timeout.connect(self.sample_frame)
        self.last_frame = None
        self.focus_halo = None
        self.hover_halo = None
        QApplication.instance().installEventFilter(self)
        QApplication.instance().focusChanged.connect(self.focus_changed)
        hints = accessibility_hints()
        if hints is not None:
            hints.motionPreferenceChanged.connect(self.accessibility_changed)
            hints.contrastPreferenceChanged.connect(self.accessibility_changed)
        QApplication.setAttribute(Qt.AA_DontUseNativeDialogs,False)
        self.apply(animate=False)

    @property
    def light(self):
        return self.mode == 'light' or (self.mode == 'system' and
            QApplication.instance().styleHints().colorScheme() == Qt.ColorScheme.Light)

    @property
    def effective_glass(self):
        hints = accessibility_hints()
        if hints is not None and hints.contrastPreference() == Qt.ContrastPreference.HighContrast:
            return 'off'
        if self.root is not None and not self.root.blur_available:
            return 'off'
        if self.reduce_transparency or os.environ.get('CUBEBABY_REDUCED_TRANSPARENCY') == '1':
            return 'off'
        return 'light' if self.auto_light and self.glass_mode == 'full' else self.glass_mode

    def apply(self, animate=True):
        old = self.owner.grab() if animate and self.owner.isVisible() and not reduced_motion() else None
        set_active_theme('light' if self.light else 'dark')
        check = Path(self.assets.name) / ('check-light.svg' if self.light else 'check-dark.svg')
        check.write_text('<svg xmlns="http://www.w3.org/2000/svg" width="18" height="18"><path d="m4 9 3.2 3.2L14 5.5" fill="none" stroke="'+css('on_accent')+'" stroke-width="2.2" stroke-linecap="round" stroke-linejoin="round"/></svg>')
        lock = Path(self.assets.name) / ('lock-light.svg' if self.light else 'lock-dark.svg')
        lock.write_text('<svg xmlns="http://www.w3.org/2000/svg" width="18" height="18"><g fill="none" stroke="'+css('text_disabled')+'" stroke-width="1.8"><rect x="4" y="8" width="10" height="8" rx="2"/><path d="M6 8V5a3 3 0 0 1 6 0v3"/></g></svg>')
        self.lock_icon = QIcon(str(lock))
        chevron = Path(self.assets.name) / ('chevron-light.svg' if self.light else 'chevron-dark.svg')
        chevron.write_text('<svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 16 16"><path d="m3.5 6 4.5 4 4.5-4" fill="none" stroke="'+css('text_secondary')+'" stroke-width="1.5" stroke-linecap="round" stroke-linejoin="round"/></svg>')
        app = QApplication.instance()
        colors = app.palette()
        for role,token in ((QPalette.Window,'surface_solid_3'),(QPalette.WindowText,'text_primary'),
                           (QPalette.Base,'control'),(QPalette.AlternateBase,'surface_solid_2'),
                           (QPalette.Text,'text_primary'),(QPalette.Button,'control'),
                           (QPalette.ButtonText,'text_primary'),(QPalette.ToolTipBase,'surface_solid_3'),
                           (QPalette.ToolTipText,'text_primary'),(QPalette.Highlight,'accent'),
                           (QPalette.HighlightedText,'on_accent'),(QPalette.Link,'accent_text')):
            colors.setColor(role,qc(token))
        colors.setColor(QPalette.Disabled,QPalette.Text,qc('text_disabled'))
        colors.setColor(QPalette.Disabled,QPalette.ButtonText,qc('text_disabled'))
        if app.palette() != colors:
            app.setPalette(colors)
        style = stylesheet(check.as_posix(),lock.as_posix(),chevron.as_posix())
        if app.styleSheet() != style:
            app.setStyleSheet(style)
        self.owner.setStyleSheet('')
        self.owner.setProperty('lightTheme',self.light)
        if self.root is not None:
            self.root.configure(self.effective_glass)
        for widget in self.owner.findChildren(QWidget):
            if isinstance(widget,DialogBackdrop): widget.configure(self.effective_glass)
            widget.update()
            if isinstance(widget,(QPushButton,QToolButton)):
                self.disabled_icon(widget)
        self.preferences.setValue('appearance/theme',self.mode)
        self.preferences.setValue('appearance/glass',self.glass_mode)
        self.preferences.setValue('appearance/reducedTransparency',self.reduce_transparency)
        if old is not None:
            self.fade(old)

    def accessibility_changed(self, *_):
        self.apply(animate=False)
        studio = getattr(self.owner,'studio_ui',None)
        if studio is not None:
            studio.audio_meter.bar.set_motion_enabled(not reduced_motion())
            if reduced_motion():
                studio.page_fade.stop(); studio.page_opacity.setOpacity(1.0)
                studio.toast_fade.stop(); studio.toast.graphicsEffect().setOpacity(1.0)

    def fade(self, snapshot):
        overlay = QLabel(self.owner)
        overlay.setPixmap(snapshot)
        overlay.setGeometry(self.owner.rect())
        overlay.setAttribute(Qt.WA_TransparentForMouseEvents)
        effect = QGraphicsOpacityEffect(overlay); overlay.setGraphicsEffect(effect)
        animation = QPropertyAnimation(effect,b'opacity',overlay)
        animation.setDuration(180); animation.setStartValue(1.0); animation.setEndValue(0.0)
        animation.finished.connect(overlay.deleteLater)
        overlay._animation = animation
        overlay.show(); overlay.raise_(); animation.start()

    def set_glass(self, mode):
        if mode in ('full','light','off'):
            self.glass_mode = mode; self.auto_light = False
            self.apply()

    def set_reduced_transparency(self, enabled):
        self.reduce_transparency = enabled
        self.apply()

    def disabled_icon(self, widget):
        if isinstance(widget.window(), QFileDialog):
            return
        if not hasattr(widget,'_unlocked_icon'):
            widget._unlocked_icon = widget.icon()
        widget.setIcon(widget._unlocked_icon if widget.isEnabled() else self.lock_icon)

    def focus_changed(self, old, target):
        if self.focus_halo is not None:
            self.focus_halo.hide()
        if (target is None or isinstance(target, (QScrollArea, QStackedWidget, QTabWidget))
                or isinstance(target.window(), QFileDialog)
                or not self.owner.isAncestorOf(target)
                or target.property('lastFocusReason') == Qt.MouseFocusReason.value):
            return
        if self.focus_halo is None:
            self.focus_halo = ControlHalo()
        self.focus_halo.follow(target)

    def set_meter_active(self, active):
        active = active and self.effective_glass == 'full'
        if active and not self.frame_timer.isActive():
            self.last_frame = time.monotonic(); self.frame_timer.start()
        elif not active:
            self.frame_timer.stop(); self.last_frame = None; self.frame_samples.clear()

    def sample_frame(self):
        now = time.monotonic()
        if self.last_frame is not None:
            self.record_frame_interval(now-self.last_frame)
        self.last_frame = now

    def record_frame_interval(self, seconds):
        self.frame_samples.append(seconds)
        if len(self.frame_samples) >= 30 and sum(value > .032 for value in self.frame_samples) >= 12:
            self.auto_light = True
            self.frame_timer.stop()
            if self.root is not None: self.root.configure(self.effective_glass)
            self.owner.setProperty('glassFallback','Efek kaca Ringan otomatis: frame UI terlambat.')
            for backdrop in self.owner.findChildren(DialogBackdrop):
                backdrop.configure(self.effective_glass)

    def eventFilter(self, watched, event):
        if not isValid(self.owner):
            return False
        if isinstance(watched, QWidget):
            parent = watched
            while parent is not None and parent is not self.owner:
                parent = parent.parentWidget()
            if parent is None:
                return False
        if isinstance(watched, QWidget) and isinstance(watched.window(), QFileDialog):
            return False
        if event.type() == QEvent.FocusIn and isinstance(watched,QWidget):
            watched.setProperty('lastFocusReason',event.reason().value)
        if isinstance(watched,(QPushButton,QToolButton)) and hasattr(self,'lock_icon'):
            if event.type() == QEvent.EnabledChange:
                self.disabled_icon(watched)
            elif event.type() == QEvent.Enter and watched.property('role') == 'primary' and watched.isEnabled():
                if self.hover_halo is None: self.hover_halo = ControlHalo()
                self.hover_halo.follow(watched,hover=True)
            elif event.type() == QEvent.Leave and self.hover_halo is not None:
                self.hover_halo.hide()
        # QMenu paints its actions itself: a child backdrop would cover the text.
        if isinstance(watched,QDialog):
            if event.type() == QEvent.Show and not hasattr(watched,'_theme_backdrop'):
                watched._theme_backdrop = DialogBackdrop(watched)
                watched._theme_backdrop.configure(self.effective_glass)
            elif event.type() == QEvent.Resize and hasattr(watched,'_theme_backdrop'):
                watched._theme_backdrop.setGeometry(watched.rect())
        return False
