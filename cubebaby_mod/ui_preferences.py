"""Desktop UI preferences, independent of pedal and collection data."""
import os
from PySide6.QtCore import QSettings, Qt
from PySide6.QtWidgets import QApplication


def settings():
    path = os.environ.get('CUBEBABY_UI_SETTINGS')
    return QSettings(path, QSettings.IniFormat) if path else QSettings('CubeBabyMOD', 'Studio')


def accessibility_hints():
    app = QApplication.instance()
    if app is None:
        return None
    if not hasattr(app,'_native_style_hints'):
        app._native_style_hints = app.styleHints()
    if not hasattr(app,'_native_accessibility_hints'):
        app._native_accessibility_hints = (app._native_style_hints.accessibility()
            if hasattr(app._native_style_hints,'accessibility') else None)
    return app._native_accessibility_hints


def reduced_motion():
    saved = settings()
    app = QApplication.instance()
    hints = accessibility_hints()
    if hints is not None:
        if hints.motionPreference() == Qt.MotionPreference.ReducedMotion:
            return True
    if saved.contains('accessibility/reducedMotion'):
        return saved.value('accessibility/reducedMotion', False, type=bool)
    return app is not None and not app.isEffectEnabled(Qt.UI_General)
