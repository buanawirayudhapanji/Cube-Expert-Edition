"""Qt stylesheet generated exclusively from named theme tokens."""
import re
from .theme_tokens import css
from .ui_metrics import TYPE, type_stylesheet

STYLE = '''
QWidget { color:@text_primary; font-size:@body_size; selection-background-color:@accent_soft; selection-color:@text_primary; }
QMainWindow { background:@bg_base; }
QWidget#shell, QWidget#workspace, QWidget#page, QScrollArea, QStackedWidget { background:transparent; border:0; }
QFrame#card, QFrame#meterCard, QFrame#irCard, QFrame#compareA, QFrame#compareB, QFrame#dangerZone { background:transparent; border:0; border-radius:16px; }
QFrame#module, QFrame#presetHero { background:@control; border:1px solid @glass_border; border-radius:12px; }
QWidget#sidebar { background:transparent; border:0; }
QLabel { background:transparent; border:0; }
QLabel#logo { background:@accent; color:@on_accent; border-radius:11px;  }
QLabel#muted, QLabel#statusText, QLabel#subtitle, QLabel#eyebrow { color:@text_secondary; }
QLabel#badge { color:@text_secondary; background:@control; border:1px solid @glass_border; border-radius:12px; padding:4px 8px; }
QPushButton, QToolButton { background:@control; color:@text_primary; border:1px solid @glass_border; border-radius:8px; padding:8px 12px; font-weight:500; min-height:18px; }
QPushButton:hover, QToolButton:hover { background:@accent_soft; border-color:@accent; }
QPushButton:pressed, QToolButton:pressed { background:@control_hover; border-color:@accent_press; }
QPushButton[role="primary"] { background:@accent; color:@on_accent; border-color:@accent; font-weight:700; }
QPushButton[role="primary"]:hover { background:@accent_hover; border-color:@accent_hover; }
QPushButton[role="primary"]:pressed { background:@accent_press; color:@on_accent; }
QPushButton[role="danger"] { color:@danger_text; background:@control; border-color:@danger; }
QPushButton[role="danger"]:hover { background:@danger; color:@on_danger; border-color:@danger; }
QPushButton:disabled, QToolButton:disabled, QPushButton[role="primary"]:disabled { color:@text_disabled; background:@control_disabled; border-color:@glass_border; }
QPushButton#nav { text-align:left; background:transparent; color:@text_secondary; border:0; border-left:3px solid transparent; padding:12px; border-radius:9px; }
QPushButton#nav:hover { background:@glass_2; color:@text_primary; }
QPushButton#nav:checked { background:@accent_soft; color:@accent_text; border-left:3px solid @accent; }
QPushButton#presetSlot { background:@control; color:@text_primary; border:1px solid @glass_border; padding:4px 12px; min-height:24px; font-size:@title_size; }
QPushButton#presetSlot:checked { background:@accent_soft; color:@text_primary; border-color:@accent; font-weight:600; }
QPushButton#chainStep { min-height:14px; padding:4px 8px; border-radius:7px; }
QPushButton#chainStep:checked { background:@accent_soft; color:@accent_text; border-color:@accent; }
QPushButton#filterChip { padding:4px 8px; border-radius:8px; }
QPushButton#filterChip:checked { background:@accent_soft; color:@accent_text; border-color:@accent; }
QPushButton[role="ghost"] { background:transparent; border-color:transparent; color:@text_secondary; }
QPushButton[role="ghost"]:hover { background:@accent_soft; }
QComboBox, QLineEdit, QSpinBox, QDoubleSpinBox { background:@control; color:@text_primary; border:1px solid @glass_border; border-radius:7px; padding:8px 12px; min-height:18px; selection-background-color:@accent_soft; selection-color:@text_primary; }
QComboBox:disabled, QLineEdit:disabled, QSpinBox:disabled, QDoubleSpinBox:disabled { color:@text_disabled; background:@control_disabled; }
QComboBox { padding-right:40px; }
QComboBox::drop-down { subcontrol-origin:padding; subcontrol-position:top right; width:32px; border:0; background:transparent; }
QComboBox::down-arrow { image:url("@chevron_icon"); width:12px; height:12px; }
QComboBox::down-arrow:disabled { image:url("@lock_icon"); width:16px; height:16px; }
QComboBox QAbstractItemView { background:@surface_solid_3; color:@text_primary; border:1px solid @glass_border; selection-background-color:@accent_soft; selection-color:@text_primary; }
QSpinBox, QDoubleSpinBox { padding:8px; font-size:@body_size; }
QListView { background:@control; border:1px solid @glass_border; border-radius:9px; padding:4px; outline:0; }
QListView::item { border-radius:6px; padding:8px 12px; color:@text_primary; }
QListView#collectionItems::item { padding:0; }
QListView::item:hover, QListView::item:selected { background:@accent_soft; color:@text_primary; }
QPlainTextEdit, QTextEdit { background:@control; color:@text_primary; border:1px solid @glass_border; border-radius:8px; padding:12px; font-family:monospace; font-size:@caption_size; }
QSlider { min-height:24px; }
QSlider::groove:horizontal { height:8px; background:@meter_track; border-radius:4px; }
QSlider::sub-page:horizontal { background:@accent; border-radius:4px; }
QSlider::handle:horizontal { width:20px; height:20px; margin:-7px 0; background:@accent; border:2px solid @on_accent; border-radius:11px; }
QSlider::sub-page:horizontal:disabled, QSlider::handle:horizontal:disabled { background:@text_disabled; border-color:@control; }
QCheckBox { spacing:8px; background:transparent; font-weight:500; }
QCheckBox:disabled { color:@text_disabled; }
QCheckBox::indicator { width:18px; height:18px; border:1px solid @text_disabled; border-radius:5px; background:@control; }
QCheckBox::indicator:checked { background:@accent; border-color:@accent; image:url("@check_icon"); }
QCheckBox::indicator:disabled { background:@control_disabled; image:url("@lock_icon"); }
QPushButton::menu-indicator, QToolButton::menu-indicator { image:url("@chevron_icon"); width:12px; height:12px; subcontrol-origin:padding; subcontrol-position:right center; right:8px; }
QPushButton[menuControl="true"], QToolButton#appearanceControl { padding-right:28px; }
QProgressBar { background:@meter_track; border:0; border-radius:2px; max-height:4px; }
QProgressBar::chunk { background:@accent; border-radius:2px; }
QTabWidget::pane { border:0; background:transparent; }
QTabBar { background:transparent; }
QTabBar::tab { background:transparent; color:@text_secondary; padding:8px 12px; margin:0 4px 4px 0; border:0; border-bottom:2px solid transparent; }
QTabBar::tab:selected { color:@text_primary; border-bottom:2px solid @accent; background:@glass_1; }
QTabBar::tab:hover { color:@accent_text; background:@accent_soft; }
QTabBar::tab:disabled { color:@text_disabled; }
QFrame#dropZone { border:1px dashed @glass_border; border-radius:12px; background:@control; }
QDialog, QMessageBox, QMenu { background:@surface_solid_3; color:@text_primary; border:1px solid @glass_border; }
QMenu { padding:8px; }
QMenu::item { padding:8px 16px; border-radius:5px; }
QMenu::item:selected { background:@accent_soft; color:@text_primary; }
QMenu::item:disabled { color:@text_disabled; }
QMenu::separator { height:1px; background:@glass_border; margin:8px; }
QToolTip { color:@text_primary; background:@surface_solid_3; border:1px solid @glass_border; padding:8px; }
QPushButton#connectionPill { min-height:26px; border-radius:16px; padding:8px 28px 8px 12px; background:@control; }
QPushButton#connectionPill[state="online"], QLabel#sidebarStatus[state="online"] { color:@success_text; }
QPushButton#connectionPill[state="busy"], QLabel#sidebarStatus[state="busy"] { color:@warning_text; }
QPushButton#connectionPill[state="error"], QLabel#sidebarStatus[state="error"] { color:@danger_text; }
QLabel#toast { color:@text_primary; background:transparent; border:1px solid @glass_border; border-left:3px solid @info; border-radius:12px; padding:12px 16px; }
QLabel#toast[state="success"] { border-left-color:@success; }
QLabel#toast[state="error"] { border-left-color:@danger; color:@danger_text; }
QLabel#activity[state="success"] { color:@success_text; }
QFrame#dangerZone QLabel#cardTitle { color:@danger_text; }
QLabel#clipBadge { color:@danger_text; font-weight:700; }
QLabel#meterReading { color:@success_text; }
QLabel#meterReading[state="warning"] { color:@warning_text; }
QLabel#meterReading[state="clip"] { color:@danger_text; }
QScrollBar:vertical { background:transparent; width:9px; margin:2px; }
QScrollBar::handle:vertical { background:@glass_border; min-height:30px; border-radius:3px; }
QScrollBar::handle:vertical:hover { background:@accent; }
QScrollBar[emptyRange="true"]::handle:vertical { background:transparent; }
QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { height:0; }
QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical { background:transparent; }
QPushButton:focus, QToolButton:focus, QComboBox:focus, QLineEdit:focus,
QSpinBox:focus, QDoubleSpinBox:focus, QCheckBox:focus, QListView:focus,
QSlider:focus, QTabBar::tab:focus { border:2px solid @focus_ring; }
QPushButton#nav:focus { border:2px solid @focus_ring; }
QPushButton#touchAction, QToolButton#bottomNavigation { min-height:28px; }
QToolButton#bottomNavigation:checked { background:@accent_soft; border-color:@accent; }
QPushButton#skipNavigation { min-height:0; padding:0; border:0; background:transparent; color:transparent; }
QPushButton#skipNavigation:focus { background:@surface_solid_3; color:@text_primary; border:2px solid @focus_ring; }
QSpinBox[editedValue="true"], QDoubleSpinBox[editedValue="true"] { color:@accent_text; border-color:@accent; background:@accent_soft; }
QGroupBox { border:1px solid @glass_border; border-radius:10px; margin-top:16px; padding:12px; }
QGroupBox::title { subcontrol-origin:margin; left:12px; color:@accent_text; }
''' + type_stylesheet() + '''
QWidget[density="compact"] QPushButton, QWidget[density="compact"] QToolButton { padding:4px 12px; }
QWidget[density="compact"] QComboBox, QWidget[density="compact"] QLineEdit { padding:4px 12px; }
QWidget[density="compact"] QComboBox { padding-right:40px; }
QWidget[density="compact"] QPushButton[menuControl="true"] { padding-right:28px; }
QWidget[density="compact"] QSpinBox, QWidget[density="compact"] QDoubleSpinBox { padding:4px 8px; }
QWidget[density="compact"] QTabBar::tab { padding:4px 12px; }
'''


def stylesheet(check_icon='',lock_icon='',chevron_icon=''):
    source = STYLE.replace('@check_icon', check_icon).replace('@lock_icon',lock_icon).replace('@chevron_icon',chevron_icon)
    for token, role in (('body_size', 'body'), ('title_size', 'cardTitle'), ('caption_size', 'muted')):
        source = source.replace('@' + token, str(TYPE[role][0]) + 'px')
    return re.sub(r'@([a-z0-9_]+)', lambda match: css(match.group(1)), source)
