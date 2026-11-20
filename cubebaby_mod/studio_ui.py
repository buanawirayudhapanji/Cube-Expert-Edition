"""Presentation only: reuse the existing controls, signals and MIDI jobs."""
from pathlib import Path
from shiboken6 import isValid

from PySide6.QtCore import Qt, QSize, QTimer, QCoreApplication, QSignalBlocker, QPropertyAnimation, QEasingCurve, QVariantAnimation
from PySide6.QtGui import QFont, QFontDatabase, QKeySequence, QShortcut, QIcon, QPixmap, QPainter, QPen, QColor
from PySide6.QtWidgets import (
    QWidget, QFrame, QLabel, QPushButton, QVBoxLayout, QHBoxLayout, QGridLayout, QBoxLayout,
    QTabWidget, QStackedWidget, QComboBox, QProgressBar, QToolButton, QInputDialog, QSizePolicy, QMenu, QWidgetAction, QListView, QAbstractItemView, QGraphicsOpacityEffect, QButtonGroup, QLineEdit, QAbstractSpinBox, QCheckBox, QMessageBox, QApplication, QProxyStyle, QStyle, QDialog,
)

from .adaptive_ui import AdaptiveViewport, ResizeObserver
from .accessibility_ui import SkipButton, StatusAnnouncer, describe_range, focusable_controls, set_focus_order
from .rendering_ui import ir_waveform_samples
from .ui_preferences import settings, reduced_motion
from .ui_states import LoadingSkeleton, PedalPreview, confirm_overwrite, highlight_value

from .studio_components import RADII, SPACE, CollectionItemDelegate, DropZone
from .ui_metrics import type_font

# Public style template retained; colors are compiled by ThemeController.
from .theme_styles import STYLE
from .theme_ui import ThemeController, AmbientBackground, GlassSurface, GlassLabel
from .theme_tokens import css, qc


def label(text, style='body', wrap=True):
    widget = QLabel(text); widget.setObjectName(style); widget.setWordWrap(wrap)
    widget.setTextFormat(Qt.PlainText)
    return widget


def move(layout, widget, stretch=0):
    layout.addWidget(widget, stretch); widget.show(); return widget


def row(*widgets):
    layout = QHBoxLayout(); layout.setSpacing(SPACE[1])
    for widget in widgets: move(layout, widget)
    return layout


def card(title=None, hint=None):
    frame = GlassSurface(); frame.setObjectName('card')
    layout = QVBoxLayout(frame); layout.setContentsMargins(SPACE[3], SPACE[3], SPACE[3], SPACE[3]); layout.setSpacing(SPACE[2])
    if title: layout.addWidget(label(title, 'cardTitle'))
    if hint: layout.addWidget(label(hint, 'muted'))
    return frame, layout


def glyph(kind, light=None):
    pixmap = QPixmap(22, 22); pixmap.fill(Qt.transparent)
    painter = QPainter(pixmap); painter.setRenderHint(QPainter.Antialiasing)
    painter.setPen(QPen(qc('accent_text', light), 1.6)); painter.setBrush(Qt.NoBrush)
    if kind == 0:
        for y, x in ((5,8),(11,15),(17,6)):
            painter.drawLine(3,y,19,y); painter.setBrush(qc('control', light)); painter.drawEllipse(x-2,y-2,4,4)
    elif kind == 1:
        for x in (3,12):
            for y in (3,12): painter.drawRoundedRect(x,y,7,7,1.5,1.5)
    elif kind == 2:
        painter.drawLine(10,2,10,20)
        for x,h in ((3,5),(6,11),(14,13),(18,7)): painter.drawLine(x,11-h//2,x,11+h//2)
    else:
        painter.drawRoundedRect(5,3,12,13,3,3); painter.drawLine(11,16,11,20); painter.drawLine(8,20,14,20)
        painter.drawLine(8,7,14,7); painter.drawLine(8,11,14,11)
    painter.end(); return QIcon(pixmap)


class TooltipStyle(QProxyStyle):
    def pixelMetric(self, metric, option=None, widget=None):
        if metric in (QStyle.PM_LayoutHorizontalSpacing, QStyle.PM_LayoutVerticalSpacing):
            return SPACE[1]
        if metric in (QStyle.PM_LayoutLeftMargin, QStyle.PM_LayoutTopMargin,
                      QStyle.PM_LayoutRightMargin, QStyle.PM_LayoutBottomMargin):
            return SPACE[4] if isinstance(widget, QDialog) else SPACE[2]
        return super().pixelMetric(metric, option, widget)

    def styleHint(self, hint, option=None, widget=None, returnData=None):
        if hint == QStyle.SH_ToolTip_WakeUpDelay:
            return 400
        return super().styleHint(hint, option, widget, returnData)


class StudioUI:
    PAGES = (
        ('Editor suara', 'Atur efek, coba kabinet, lalu simpan ke pedal.'),
        ('Koleksi', 'Preset, IR, dan bank milikmu. Tersimpan di laptop.'),
        ('Bandingkan IR', 'Dengarkan dua pilihan lewat pedal sebelum memutuskan.'),
        ('Perangkat', 'Koneksi, cadangan, dan alat bantu saat dibutuhkan.'),
    )

    def __init__(self, owner):
        self.owner = owner
        self.preferences = settings()
        self.theme = ThemeController(owner)
        self.theme_mode = self.theme.mode
        self.restoring_preferences = True
        app = QApplication.instance()
        if not hasattr(app, '_cubebaby_tooltip_style'):
            app._cubebaby_tooltip_style = TooltipStyle()
            app.setStyle(app._cubebaby_tooltip_style)
        old = owner.takeCentralWidget()
        root = AmbientBackground(); self.ambient = root; self.theme.root = root; root.setObjectName('shell'); owner.setCentralWidget(root)
        shell = QHBoxLayout(root); self.shell_layout = shell; shell.setContentsMargins(0,0,0,0); shell.setSpacing(0)
        sidebar = GlassSurface(level=1); self.sidebar = sidebar; sidebar.setObjectName('sidebar'); sidebar.setFixedWidth(220)
        side = QVBoxLayout(sidebar); side.setContentsMargins(16,24,16,24); side.setSpacing(8)
        brand_row = QHBoxLayout(); logo = label('CB', 'logo', False); logo.setAlignment(Qt.AlignCenter); logo.setFixedSize(43,43)
        brand_row.addWidget(logo)
        self.brand = label('CubeBaby MOD', 'brand')
        brand_row.addWidget(self.brand)
        side.addLayout(brand_row)
        self.sidebar_status = label('●  Pedal belum terhubung', 'sidebarStatus', False)
        side.addWidget(self.sidebar_status)
        side.addSpacing(SPACE[4])
        self.nav_title = label('Ruang kerja', 'eyebrow')
        side.addWidget(self.nav_title)
        self.nav = []
        for index, (title, _) in enumerate(self.PAGES):
            button = QPushButton(title); button.setObjectName('nav'); button.setCheckable(True)
            button.setIcon(glyph(index)); button.setIconSize(QSize(20,20))
            button.setAccessibleName(title); button.setToolTip(f'{title} · Alt+{index+1}')
            button.clicked.connect(lambda checked, i=index: self.navigate(i)); side.addWidget(button); self.nav.append(button)
        side.addStretch()
        collapse = QToolButton()
        collapse.setText('‹')
        collapse.setCheckable(True)
        collapse.setAccessibleName('Ringkas sidebar')
        collapse.setToolTip('Ringkas atau perluas sidebar')

        def toggle_sidebar(collapsed):
            collapsed = collapsed or 900 <= owner.width() < 1200
            sidebar.setFixedWidth(72 if collapsed else 220)
            collapse.setText('›' if collapsed else '‹')
            collapse.setAccessibleName('Perluas sidebar' if collapsed else 'Ringkas sidebar')
            for widget in (self.brand, self.nav_title, self.sidebar_status):
                widget.setVisible(not collapsed)
            for button, (title, _) in zip(self.nav, self.PAGES):
                button.setText('' if collapsed else title)

        help_button = QToolButton()
        help_button.setText('?')
        help_button.setAccessibleName('Bantuan pintasan')
        help_button.setToolTip('Pintasan dan kurangi animasi · ?')
        help_button.clicked.connect(self.shortcut_help)
        side.addWidget(help_button)
        self.update_sidebar = toggle_sidebar
        self.collapse_button = collapse
        collapse.toggled.connect(toggle_sidebar)
        collapse.toggled.connect(lambda value: self.preferences.setValue('sidebar/collapsed', value)
                                 if not self.restoring_preferences else None)
        side.addWidget(collapse)
        shell.addWidget(sidebar)
        workspace = QWidget(); workspace.setObjectName('workspace')
        self.workspace = workspace
        work = QVBoxLayout(workspace); self.workspace_layout = work; work.setContentsMargins(24,16,24,12); work.setSpacing(12)
        header = QHBoxLayout()
        header.setContentsMargins(12, 8, 12, 8)
        self.header_layout = header
        self.title = label('', 'pageTitle')
        self.subtitle = label('', 'subtitle')
        title_row = QVBoxLayout()
        title_row.setSpacing(4)
        title_row.addWidget(self.title)
        title_row.addWidget(self.subtitle)
        header.addLayout(title_row, 1)
        self.badge = QPushButton('●  Belum terhubung')
        self.badge.setObjectName('connectionPill')
        self.badge.setAccessibleName('Pengaturan koneksi MIDI')
        self.connection_pulse = QVariantAnimation(self.badge)
        self.connection_pulse.valueChanged.connect(self.paint_connection_pulse)
        self.connection_pulse.setDuration(1400)
        self.connection_pulse.setStartValue(1.0)
        self.connection_pulse.setKeyValueAt(.5,.60)
        self.connection_pulse.setEndValue(1.0)
        self.connection_pulse.setLoopCount(-1)
        port_menu = QMenu(self.badge)
        port_panel, port_layout = card('Input MIDI', 'Pilih port pedal, lalu klik Hubungkan.')
        owner.ports.setMinimumWidth(190)
        owner.ports.setMaximumWidth(280)
        owner.ports.setAccessibleName('Input MIDI')
        owner.ports.setToolTip('Pilih input MIDI pedal. Output dengan nama sama dipilih otomatis.')
        move(port_layout, owner.ports)
        owner.refresh_button.setText('Cari ulang perangkat')
        move(port_layout, owner.refresh_button)
        port_action = QWidgetAction(port_menu)
        port_action.setDefaultWidget(port_panel)
        port_menu.addAction(port_action)
        self.badge.setMenu(port_menu)
        self.connection_menu = port_menu
        connection_controls = QWidget()
        self.connection_controls = connection_controls
        connection_row = QHBoxLayout(connection_controls)
        connection_row.setContentsMargins(0, 0, 0, 0)
        connection_row.addWidget(self.badge)
        header.addWidget(connection_controls)
        owner.connect_button.setProperty('role', 'primary')
        owner.connect_button.setMinimumWidth(112)
        move(connection_row, owner.connect_button)
        self.appearance_button = QToolButton()
        self.appearance_button.setObjectName('appearanceControl')
        self.appearance_button.setText('◐')
        self.appearance_button.setAccessibleName('Pengaturan tampilan')
        self.appearance_button.setToolTip('Tema, efek kaca, dan aksesibilitas tampilan')
        self.appearance_button.setMinimumSize(40, 40)
        self.appearance_button.setMenu(self.appearance_menu())
        self.appearance_button.setPopupMode(QToolButton.InstantPopup)
        connection_row.addWidget(self.appearance_button)
        self.badge.setSizePolicy(QSizePolicy.Preferred, QSizePolicy.Fixed)
        work.addLayout(header)
        self.header_glass = GlassSurface(workspace,level=1)
        self.header_glass.setObjectName('topBarGlass')
        self.header_glass.setAttribute(Qt.WA_TransparentForMouseEvents)
        self.header_glass.show(); self.header_glass.lower()
        self.stack = QStackedWidget(); work.addWidget(self.stack, 1)
        self.pages = (self.editor(), self.collection(), self.comparison(), self.device())
        self.viewports = []
        for page in self.pages:
            viewport = AdaptiveViewport(page)
            self.viewports.append(viewport)
            self.stack.addWidget(viewport)
        self.progress = QProgressBar(); self.progress.setRange(0,0); self.progress.setTextVisible(False); self.progress.setFixedHeight(4)
        work.addWidget(self.progress)
        footer = QHBoxLayout(); self.footer_layout = footer; footer.setSpacing(12)
        footer.setContentsMargins(12, 4, 12, 4)
        self.activity = label('SIAP', 'eyebrow', False); footer.addWidget(self.activity)
        owner.status.setStyleSheet(''); owner.status.setObjectName('statusText'); owner.status.setFixedHeight(24)
        move(footer, owner.status, 1)
        self.feedback_detail = QPushButton('Detail error')
        self.feedback_detail.hide()
        self.feedback_detail.clicked.connect(self.open_error)
        footer.addWidget(self.feedback_detail)
        self.retry_button = QPushButton('Coba lagi')
        self.retry_button.hide()
        self.retry_button.clicked.connect(self.retry_error)
        footer.addWidget(self.retry_button)
        self.undo_delete = QPushButton('Urungkan hapus')
        self.undo_delete.hide()
        self.undo_delete.clicked.connect(owner.library_panel.undo_delete)
        footer.addWidget(self.undo_delete)
        self.error_message = ''
        self.last_read_action = None
        self.last_error_explicit = ''
        self.success_timer = QTimer(workspace)
        self.success_timer.setSingleShot(True)
        self.success_timer.timeout.connect(self.sync)
        self.dirty_label = label('', 'eyebrow', False)
        footer.addWidget(self.dirty_label)
        version = QCoreApplication.applicationVersion()
        if version:
            footer.addWidget(label(f'Versi {version}', 'muted', False))
        self.saved_presets = None
        self.toast = GlassLabel('')
        self.toast.setObjectName('toast'); self.toast.setWordWrap(True)
        self.toast.setTextFormat(Qt.PlainText)
        self.toast.setParent(workspace)
        self.toast.hide()
        opacity = QGraphicsOpacityEffect(self.toast)
        self.toast.setGraphicsEffect(opacity)
        self.toast_fade = QPropertyAnimation(opacity, b'opacity', self.toast)
        self.toast_fade.setDuration(180)
        self.toast_fade.setEasingCurve(QEasingCurve.OutCubic)
        self.toast_fade.setStartValue(0.0)
        self.toast_fade.setEndValue(1.0)
        self.toast_timeout = QTimer(workspace)
        self.toast_timeout.setSingleShot(True)
        self.toast_timeout.timeout.connect(self.toast.hide)
        self._last_status = owner.status.text()
        self.status_timer = QTimer(workspace)
        self.status_timer.timeout.connect(self.sync_feedback)
        self.status_timer.start(150)
        save_shortcut = QShortcut(QKeySequence.Save, owner)
        save_shortcut.activated.connect(lambda: owner.preset_save.click() if owner.preset_save.isEnabled() else None)
        owner.preset_save.clicked.disconnect()
        owner.preset_save.clicked.connect(self.confirm_save_presets)
        owner.save_button.clicked.disconnect()
        owner.save_button.clicked.connect(self.confirm_save_ir)
        self._connected = False
        work.addLayout(footer)
        self.footer_glass = GlassSurface(workspace,level=1)
        self.footer_glass.setObjectName('footerGlass')
        self.footer_glass.setAttribute(Qt.WA_TransparentForMouseEvents)
        self.footer_glass.show(); self.footer_glass.lower()
        shell.addWidget(workspace, 1)
        for widget in (owner.device_label, owner.ir_status, owner.edit_status):
            widget.setStyleSheet(''); widget.setObjectName('muted')
        families = QFontDatabase.families()
        owner.setFont(type_font('body', QFont('Inter' if 'Inter' in families else 'Noto Sans')))
        self.apply_theme()
        QApplication.instance().styleHints().colorSchemeChanged.connect(self.system_theme_changed)
        owner.setWindowTitle('CubeBabyMOD · Studio')
        owner.resize(1280, 900); owner.setMinimumSize(360, 480)
        self.navigate(0)
        for widget in (owner.status, owner.wav_label, owner.library_panel.description, *self.ab_names.values()):
            widget.setMinimumWidth(0)
            widget.setSizePolicy(QSizePolicy.Ignored, QSizePolicy.Preferred)
        old.deleteLater()
        self.page_opacity = QGraphicsOpacityEffect(self.stack)
        self.stack.setGraphicsEffect(self.page_opacity)
        self.page_fade = QPropertyAnimation(self.page_opacity, b'opacity', self.stack)
        self.page_fade.setDuration(180)
        self.page_fade.setEasingCurve(QEasingCurve.OutCubic)
        self.page_fade.setStartValue(.65)
        self.page_fade.setEndValue(1.0)
        self.scroll_views = {
            'collection': owner.library_panel.list,
            'wav': owner.wav_list,
            'midi': self.midi_log.console,
            'backups': self.backup_panel.list,
        }
        self.restore_preferences()
        self.install_shortcuts()
        for _, spin in owner.effect_controls.values():
            spin.valueChanged.connect(lambda value, control=spin: highlight_value(control))
        owner.distance.valueChanged.connect(lambda value: highlight_value(owner.distance))
        self.restoring_preferences = False
        owner.ports.activated.connect(lambda index: self.preferences.setValue('devices/midi', owner.ports.itemText(index)))
        owner.connect_button.clicked.connect(lambda: self.preferences.setValue('devices/midi', owner.ports.currentText())
                                            if owner.ports.currentText() else None)
        owner.refresh_button.clicked.connect(self.restore_device)
        self.sticky_actions = QWidget()
        sticky = QHBoxLayout(self.sticky_actions)
        sticky.setContentsMargins(8, 4, 8, 4)
        self.mobile_save = QPushButton('Simpan efek')
        self.mobile_save.setObjectName('touchAction')
        self.mobile_save.setProperty('role', 'primary')
        self.mobile_save.setMinimumHeight(44)
        self.mobile_save.clicked.connect(owner.preset_save.click)
        sticky.addWidget(self.mobile_save)
        self.mobile_ir = QPushButton('Simpan slot IR')
        self.mobile_ir.setObjectName('touchAction')
        self.mobile_ir.setMinimumHeight(44)
        self.mobile_ir.clicked.connect(owner.save_button.click)
        sticky.addWidget(self.mobile_ir)
        self.workspace_layout.addWidget(self.sticky_actions)
        self.sticky_actions.hide()
        self.bottom_navigation = QWidget()
        bottom = QHBoxLayout(self.bottom_navigation)
        bottom.setContentsMargins(4, 4, 4, 4)
        bottom.setSpacing(4)
        self.bottom_buttons = []
        for index, (title, _) in enumerate(self.PAGES):
            button = QToolButton()
            button.setObjectName('bottomNavigation')
            button.setIcon(glyph(index))
            button.setText(title)
            button.setToolTip(title)
            button.setAccessibleName(title)
            button.setMinimumSize(44, 44)
            button.setCheckable(True)
            button.setToolButtonStyle(Qt.ToolButtonTextUnderIcon)
            button.clicked.connect(lambda checked, i=index: self.navigate(i))
            bottom.addWidget(button, 1)
            self.bottom_buttons.append(button)
        self.shell_layout.addWidget(self.bottom_navigation)
        self.breakpoint = None
        self.resize_observer = ResizeObserver(owner, self.adapt_layout)
        self.adapt_layout(owner.width())
        self.install_accessibility()
        self.sync()

    def install_accessibility(self):
        o = self.owner
        self.announcer = StatusAnnouncer(o.status)
        o.status.setAccessibleName('Status proses terakhir')
        self.accessible_statuses = {
            self.audio_meter.status: self.audio_meter.status.text(),
            o.library_panel.errors: o.library_panel.errors.text(),
        }
        self.audio_meter.status.setAccessibleName('Status monitor gitar')
        o.library_panel.errors.setAccessibleName('Pesan impor koleksi')
        self.skip_navigation = SkipButton(self.workspace, self.focus_content)
        self.skip_navigation.show()
        names = {
            o.ir_slot: 'Slot IR di pedal', o.distance: 'Distance',
            o.distance_slider: 'Distance', o.wav_list: 'Daftar file WAV',
            o.library_panel.list: 'Item koleksi', o.library_panel.kind_filter: 'Jenis koleksi',
            o.library_panel.preset_target: 'Preset tujuan di pedal',
            o.library_panel.ir_target: 'Slot IR tujuan di pedal',
            self.backup_panel.list: 'Daftar cadangan IR', self.midi_log.console: 'Pesan log MIDI',
        }
        for widget, name in names.items():
            widget.setAccessibleName(name)
        for slider, spin in o.effect_controls.values():
            for control in (slider, spin):
                describe_range(control, control.accessibleName() or 'Parameter efek')
        for control in (o.distance, o.distance_slider):
            describe_range(control, 'Distance', 'persen')
        for page, (title, _) in zip(self.pages, self.PAGES):
            page.setAccessibleName(title)
            for tabs in page.findChildren(QTabWidget):
                tabs.setAccessibleName({
                    'effectTabs': 'Bagian efek', 'monitorTabs': 'Alat monitoring dan IR',
                    'editorDrawer': 'Panel Editor suara', 'collectionDrawer': 'Panel Koleksi',
                    'collectionTabs': 'Alat koleksi', 'deviceTabs': 'Pengaturan perangkat',
                }.get(tabs.objectName(), 'Bagian halaman'))
                tabs.tabBar().setAccessibleName(tabs.accessibleName())
                tabs.tabBar().setAccessibleDescription(tabs.accessibleName())
                for index in range(tabs.count()):
                    tabs.widget(index).setAccessibleName(tabs.tabText(index))
                tabs.currentChanged.connect(lambda: QTimer.singleShot(0, self.update_focus_order))
        self.update_focus_order()

    def update_focus_order(self):
        if not isValid(self.owner) or not hasattr(self, 'skip_navigation'):
            return
        order = [
            self.skip_navigation, *focusable_controls(self.sidebar),
            *focusable_controls(self.workspace), *focusable_controls(self.bottom_navigation),
        ]
        if order != getattr(self, 'focus_order', None):
            self.focus_order = set_focus_order(order)

    def focus_content(self):
        controls = focusable_controls(self.stack.currentWidget())
        if controls:
            controls[0].setFocus(Qt.ShortcutFocusReason)
            self.stack.currentWidget().ensureWidgetVisible(controls[0])

    def focus_navigation(self):
        buttons = self.nav if self.sidebar.isVisible() else self.bottom_buttons
        buttons[self.stack.currentIndex()].setFocus(Qt.ShortcutFocusReason)

    def system_theme_changed(self, *_):
        if self.theme_mode == 'system':
            self.apply_theme()

    def appearance_menu(self):
        from PySide6.QtGui import QActionGroup
        menu = QMenu(self.owner)
        themes = menu.addMenu('Tema')
        theme_group = QActionGroup(menu)
        for title, mode in (('Sistem', 'system'), ('Terang', 'light'), ('Gelap', 'dark')):
            action = themes.addAction(title)
            action.setCheckable(True); action.setChecked(self.theme_mode == mode)
            theme_group.addAction(action)
            action.triggered.connect(lambda checked, value=mode: self.change_theme(value))
        glass = menu.addMenu('Efek kaca')
        glass_group = QActionGroup(menu)
        for title, mode in (('Penuh', 'full'), ('Ringan', 'light'), ('Mati', 'off')):
            action = glass.addAction(title)
            action.setCheckable(True); action.setChecked(self.theme.glass_mode == mode)
            glass_group.addAction(action)
            action.triggered.connect(lambda checked, value=mode: self.theme.set_glass(value))
        status = glass.addAction('')
        status.setEnabled(False)
        menu.aboutToShow.connect(lambda: status.setText('Aktif: '+{'full':'Penuh','light':'Ringan','off':'Mati'}[self.theme.effective_glass]+(' (otomatis)' if self.theme.auto_light else '')))
        menu.addSeparator()
        reduced = menu.addAction('Kurangi transparansi')
        reduced.setCheckable(True); reduced.setChecked(self.theme.reduce_transparency)
        reduced.toggled.connect(self.theme.set_reduced_transparency)
        motion = menu.addAction('Kurangi gerakan animasi')
        motion.setCheckable(True); motion.setChecked(reduced_motion())
        motion.toggled.connect(self.set_reduced_motion)
        menu.aboutToShow.connect(lambda: [action.setChecked(self.theme_mode == mode)
            for action, mode in zip(theme_group.actions(), ('system', 'light', 'dark'))])
        menu.aboutToShow.connect(lambda: [action.setChecked(self.theme.glass_mode == mode)
            for action, mode in zip(glass_group.actions(), ('full', 'light', 'off'))])
        return menu

    def apply_theme(self):
        self.theme.mode = self.theme_mode
        self.theme.apply()
        light = self.theme.light
        panel = self.owner.library_panel
        if panel is not None:
            panel.list.setProperty('lightTheme', light)
            panel.kind_icons = {kind:glyph(index,light) for index,kind in enumerate(('preset','ir','bank','sound'))}
            panel.list.model().icons = panel.kind_icons
            panel.list.viewport().update()
        def set_icon(button, icon):
            button._unlocked_icon = icon
            button.setIcon(icon if button.isEnabled() else self.theme.lock_icon)
        for index, button in enumerate(self.nav):
            set_icon(button,glyph(index, light))
        for index, button in enumerate(getattr(self, 'bottom_buttons', [])):
            set_icon(button,glyph(index, light))
        if hasattr(self, 'pages'):
            for page in self.pages:
                for tabs in page.findChildren(QTabWidget):
                    for index in range(tabs.count()):
                        if not tabs.tabIcon(index).isNull():
                            tabs.setTabIcon(index, glyph(index % 4, light))
                        tabs.tabBar().setTabTextColor(index, qc('text_primary'))
        for button in (self.owner.folder_button, self.owner.folder_refresh,
                       self.owner.wav_button, self.owner.save_button):
            set_icon(button,glyph(1, light))
        if hasattr(self, 'audio_meter'):
            self.audio_meter.refresh_theme()
        if hasattr(self, 'midi_log'):
            self.midi_log.refresh_theme()
        if hasattr(self, 'appearance_button'):
            self.appearance_button.setMenu(self.appearance_menu())
        # Keep the logo and native title icon consistent with the same tokens.
        tile = QPixmap(48,48); tile.fill(qc('accent'))
        painter = QPainter(tile); painter.setPen(qc('on_accent'))
        painter.setFont(QFont(self.owner.font().family(),18,QFont.Bold))
        painter.drawText(tile.rect(),Qt.AlignCenter,'CB'); painter.end()
        self.owner.setWindowIcon(QIcon(tile))

    def adapt_layout(self, width):
        focused = QApplication.focusWidget()
        if focused is not None and focused.window() is self.owner:
            self._resize_focus = focused
        band = 3 if width >= 1200 else 2 if width >= 900 else 1 if width >= 600 else 0
        narrow = width < 900
        small = width < 600
        self.sidebar.setVisible(not narrow)
        self.bottom_navigation.setVisible(narrow)
        self.shell_layout.setDirection(QBoxLayout.TopToBottom if narrow else QBoxLayout.LeftToRight)
        self.update_sidebar(self.collapse_button.isChecked())
        self.header_layout.setDirection(QBoxLayout.TopToBottom if small else QBoxLayout.LeftToRight)
        compact = not narrow and width < 1200
        header_padding = SPACE[0] if compact else SPACE[1]
        self.header_layout.setContentsMargins(12, header_padding, 12, header_padding)
        self.subtitle.setVisible(width >= 1200)
        self.sticky_actions.setVisible(small and self.stack.currentIndex() == 0)
        margin = 8 if narrow else 16
        self.workspace_layout.setContentsMargins(margin, 8, margin, 8)
        self.workspace_layout.setSpacing(8 if width < 1200 else 12)
        self.footer_layout.setDirection(QBoxLayout.TopToBottom if small else QBoxLayout.LeftToRight)
        footer_padding = SPACE[0]
        self.footer_layout.setContentsMargins(12, footer_padding, 12, footer_padding)
        self.owner.status.setVisible(True)
        self.owner.status.setWordWrap(small)
        self.owner.status.setSizePolicy(QSizePolicy.Ignored, QSizePolicy.Fixed)
        self.owner.status.setFixedHeight(40 if small else 24)
        self.activity.setVisible(not small)
        self.badge.setMaximumWidth(16777215)
        self.badge.setMinimumWidth(160 if width >= 900 else 96)
        self.owner.connect_button.setMinimumHeight(44)
        self.workspace.setProperty('touchLayout', narrow)
        density = 'compact' if compact else 'normal'
        density_changed = self.workspace.property('density') != density
        self.workspace.setProperty('density', density)
        self.workspace.style().unpolish(self.workspace)
        self.workspace.style().polish(self.workspace)
        for page in self.pages:
            for frame in page.findChildren(QFrame):
                if frame.objectName() in ('card', 'meterCard', 'irCard', 'compareA', 'compareB', 'dangerZone') and frame.layout() is not None:
                    card_layout = frame.layout()
                    padding = SPACE[2] if compact else SPACE[3]
                    card_layout.setContentsMargins(padding, padding, padding, padding)
                    card_layout.setSpacing(SPACE[1] if compact else SPACE[2])
                elif frame.objectName() in ('module', 'presetHero') and frame.layout() is not None:
                    padding = SPACE[1] if compact else SPACE[2]
                    frame.layout().setContentsMargins(padding, padding, padding, padding)
                    frame.layout().setSpacing(SPACE[0] if compact else SPACE[1])
            for tabs in page.findChildren(QTabWidget):
                tabs.tabBar().setUsesScrollButtons(True)
                tabs.tabBar().setElideMode(Qt.ElideNone)
            for control in page.findChildren(QPushButton) + page.findChildren(QToolButton):
                control.setMinimumHeight(44 if narrow else 0)
                if narrow:
                    control.setMinimumWidth(44)
        for control in (self.audio_meter.inputs, self.owner.outputs, self.amp_select):
            control.setMinimumWidth(0)
            control.setSizeAdjustPolicy(QComboBox.AdjustToMinimumContentsLengthWithIcon)
        for button in self.bottom_buttons:
            button.setToolButtonStyle(Qt.ToolButtonIconOnly if small else Qt.ToolButtonTextUnderIcon)
            button.setIcon(glyph(self.bottom_buttons.index(button), self.owner.property('lightTheme')))
        for button in self.ab_switches.values():
            button.setMinimumHeight(44 if narrow else 0)
        for check in self.workspace.findChildren(QCheckBox):
            check.setMinimumHeight(44 if narrow else 0)
        self.comparison_columns.setDirection(QBoxLayout.TopToBottom if narrow else QBoxLayout.LeftToRight)
        for index, (toggle, hint) in enumerate(self.comparison_option_items):
            self.comparison_options_grid.addWidget(toggle, index * 2 if small else 0, 0 if small else index)
            self.comparison_options_grid.addWidget(hint, index * 2 + 1 if small else 1, 0 if small else index)
        if band != self.breakpoint:
            compact_editor = width < 1200
            self.reflow_pair(self.editor_columns, self.editor_drawer,
                             self.preset_card, self.monitor_tools, compact_editor,
                             'Efek & preset', 'Monitoring & IR')
            self.reflow_pair(self.collection_columns, self.collection_drawer,
                             self.collection_listing, self.collection_tabs, narrow,
                             'Koleksi', 'Detail & aksi')
            self.breakpoint = band
        for viewport in self.viewports:
            viewport.set_compact(narrow or self.owner.height() < 640)
            viewport.widget().setMaximumWidth(16777215)
        if not hasattr(self, 'adaptive_rows'):
            self.adaptive_rows = []
            for page in self.pages:
                for row_layout in page.findChildren(QHBoxLayout):
                    if row_layout not in (self.editor_columns, self.collection_columns, self.comparison_columns):
                        self.adaptive_rows.append(row_layout)
        for row_layout in self.adaptive_rows:
            row_layout.setDirection(QBoxLayout.TopToBottom if small else QBoxLayout.LeftToRight)
        self.preset_slots_row.setDirection(QBoxLayout.LeftToRight)
        self.comparison_switch_row.setDirection(QBoxLayout.LeftToRight)
        for widget in self.pages[1].findChildren(QLabel):
            if widget in (self.collection_preview, self.owner.library_panel.description):
                widget.setMaximumHeight(16777215 if narrow else (42 if widget is self.collection_preview else 58))
                widget.setMinimumHeight(0 if narrow else (42 if widget is self.collection_preview else 58))
                widget.setSizePolicy(QSizePolicy.Ignored, QSizePolicy.Preferred)
        for spin in self.workspace.findChildren(QAbstractSpinBox):
            spin.setMinimumHeight(44 if narrow else 0)
        for combo in self.workspace.findChildren(QComboBox):
            combo.setMinimumHeight(44 if narrow else 0)
        for slider in (*[control[0] for control in self.owner.effect_controls.values()], self.owner.distance_slider):
            slider.setMinimumHeight(44 if narrow else 24)
        for page in self.pages:
            for widget in reversed([page, *page.findChildren(QWidget)]):
                if density_changed:
                    widget.style().unpolish(widget)
                    widget.style().polish(widget)
                    widget.updateGeometry()
                if widget.layout() is not None:
                    widget.layout().invalidate()
                    widget.layout().activate()
            page.updateGeometry()
        self._resize_replacement_focus = QApplication.focusWidget()
        QTimer.singleShot(0, self.finish_adaptive_layout)

    def finish_adaptive_layout(self):
        if not isValid(self.owner):
            return
        self.header_glass.setGeometry(self.header_layout.geometry())
        self.footer_glass.setGeometry(self.footer_layout.geometry())
        for viewport in self.viewports:
            viewport.fit_width()
            viewport.set_compact(self.owner.width() < 900 or
                                 viewport.widget().minimumSizeHint().height() > viewport.viewport().height())
        # The A/B switch remains outside the scrollable comparison cards on narrow displays.
        if hasattr(self, 'ab_switch_bar'):
            self.ab_switch_bar.setVisible(self.stack.currentIndex() == 2)
        self.update_focus_order()
        focused = getattr(self, '_resize_focus', None)
        current = QApplication.focusWidget()
        replacement = getattr(self, '_resize_replacement_focus', None)
        if (focused is not None and focused.isVisible() and focused.isEnabled()
                and (current is None or current is replacement)):
            focused.setFocus(Qt.OtherFocusReason)
        self._resize_focus = None

    def reflow_pair(self, columns, tabs, first, second, compact, first_title, second_title):
        preferred = self.preferences.value('tabs/' + tabs.objectName(), 0, type=int)
        blocker = QSignalBlocker(tabs)
        if compact and tabs.count() == 0:
            columns.removeWidget(first)
            columns.removeWidget(second)
            tabs.addTab(first, first_title)
            tabs.addTab(second, second_title)
            tabs.setCurrentIndex(max(0, min(1, preferred)))
            tabs.show()
        elif not compact and tabs.count():
            while tabs.count():
                widget = tabs.widget(0)
                tabs.removeTab(0)
                widget.setParent(tabs.parentWidget())
            columns.insertWidget(0, first, 7)
            columns.insertWidget(1, second, 5)
            first.show()
            second.show()
            tabs.hide()
        blocker.unblock()

    def confirm_save_presets(self):
        o = self.owner
        if o.preset_save.isEnabled() and confirm_overwrite(
                o, 'Simpan efek ke pedal',
                'Simpan efek akan mengganti pengaturan tersimpan A/B/C dengan isi editor saat ini.'):
            o.save_presets()

    def confirm_save_ir(self):
        o = self.owner
        slot = o.ir_slot.currentIndex() + 1
        if o.save_button.isEnabled() and confirm_overwrite(
                o, f'Simpan slot IR {slot}',
                f'Isi slot IR {slot} akan diganti. Isi terbaru dicadangkan sebelum penulisan.'):
            o.save_ir()

    def report_error(self, message):
        self.last_error_explicit = message
        self.error_message = message
        self._last_status = None
        self.sync_feedback()

    def open_error(self):
        QMessageBox.warning(self.owner, 'Detail proses gagal',
                            self.error_message)

    def retry_error(self):
        o = self.owner
        if o.identity is None:
            o.refresh_button.click()
            self.badge.showMenu()
        elif self.last_read_action is not None and self.last_read_action.isEnabled():
            self.last_read_action.click()
        else:
            self.navigate(3)
            self.device_tabs.setCurrentIndex(1)
            o.status.setText('Periksa slot dan cadangan. Baca ulang sebelum mencoba operasi lagi.')

    def sync_feedback(self):
        o = self.owner
        self.sync_collection_undo()
        self.theme.set_meter_active(self.audio_meter.source is not None and self.audio_meter.bar.isVisible())
        for source, previous in getattr(self, 'accessible_statuses', {}).copy().items():
            text = source.text()
            if text != previous:
                self.accessible_statuses[source] = text
                urgent = any(term in text.casefold() for term in ('gagal', 'tidak dapat dibuka', 'clip', 'error'))
                self.announcer.announce(text, urgent=urgent)
        message = o.status.text()
        connection_changed = (o.identity is not None) != self._connected
        if message == self._last_status and not connection_changed:
            return
        self._last_status = message
        o.status.setToolTip(message)
        self.sync_connection()
        became_connected = o.identity is not None and not self._connected
        became_disconnected = o.identity is None and self._connected
        if became_connected:
            message = f'Terhubung ke {o.identity["name"]}. ' + message
        self._connected = o.identity is not None
        low = message.casefold()
        failed = message == self.last_error_explicit or any(term in low for term in ('gagal', 'terhenti', 'tidak ada respons', 'timeout', 'belum dapat dipastikan'))
        success = not failed and any(term in low for term in ('terverifikasi', 'berhasil', 'selesai', 'tersimpan', 'disimpan'))
        if hasattr(self, 'announcer') and (became_connected or became_disconnected or failed or success):
            spoken = ('Pedal terputus. ' if became_disconnected else '') + message
            self.announcer.announce(spoken, urgent=failed)
        if failed:
            self.error_message = message
        self.feedback_detail.setVisible(failed)
        self.retry_button.setVisible(failed)
        if success and o.memory_job is None and o.transfer is None:
            self.success_timer.start(1500)
            self.activity.setText('✓ Selesai')
            self.activity.setObjectName('activity'); self.activity.setProperty('state', 'success')
        parent = self.toast.parentWidget()
        if not message or parent is None or not parent.isVisible() or o.pending is not None and not became_connected:
            return
        self.toast.setProperty('state', 'error' if failed else 'success' if success else 'info')
        self.toast.style().unpolish(self.toast); self.toast.style().polish(self.toast)
        self.toast.setMaximumWidth(min(420, parent.width() - 32))
        self.toast.setText(('!  ' if failed else '✓  ' if success else 'i  ') + message)
        self.toast.adjustSize()
        self.toast.move(parent.width() - self.toast.width() - 16,
                        parent.height() - self.toast.height() - 49)
        self.toast.setAttribute(Qt.WA_TransparentForMouseEvents)
        self.toast.show()
        self.toast.raise_()
        self.toast_fade.stop()
        if reduced_motion():
            self.toast.graphicsEffect().setOpacity(1.0)
        else:
            self.toast_fade.start()
        self.toast_timeout.start(5000 if failed else 2700)

    def sync_collection_undo(self):
        available = bool(self.owner.library_panel.deleted_items)
        visible = available and self.stack.currentIndex() == 1
        changed = self.undo_delete.isHidden() == visible
        self.undo_delete.setEnabled(available)
        self.undo_delete.setVisible(visible)
        self.undo_delete.setToolTip('Kembalikan item yang terakhir dihapus selama sesi ini.')
        if changed:
            QTimer.singleShot(0, self.finish_adaptive_layout)

    def paint_connection_pulse(self, opacity):
        pixmap = QPixmap(18,18); pixmap.fill(Qt.transparent)
        painter = QPainter(pixmap); painter.setRenderHint(QPainter.Antialiasing)
        painter.setOpacity(float(opacity)); painter.setPen(Qt.NoPen)
        painter.setBrush(qc('warning')); painter.drawEllipse(4,4,10,10); painter.end()
        self.badge.setIcon(QIcon(pixmap))

    def sync_connection(self):
        o = self.owner
        connecting = o.output_port is not None and o.identity is None
        message = o.status.text().casefold()
        failed = message.startswith(('gagal', 'midi belum dapat diakses', 'tidak ada respons'))
        if connecting:
            state, text = 'busy', 'Menghubungkan…'
        elif o.identity is not None:
            name = o.ports.currentText()
            device = self.badge.fontMetrics().elidedText(name, Qt.ElideRight, 126)
            state, text = 'online', device or 'Pedal terhubung'
        elif failed:
            state, text = 'error', 'Koneksi gagal'
        else:
            state, text = 'offline', 'Belum terhubung'
        if connecting:
            o.connect_button.setText('Menghubungkan…')
            o.connect_button.setEnabled(False)
        elif o.output_port is not None:
            o.connect_button.setText('Putuskan')
        else:
            o.connect_button.setText('Hubungkan')
        symbol = {'online': '✓', 'busy': '◌', 'error': '!', 'offline': '○'}[state]
        status_text = {'online': 'Pedal terhubung', 'busy': 'Menghubungkan…',
                       'error': 'Koneksi gagal', 'offline': 'Pedal belum terhubung'}[state]
        self.badge.setText(symbol + '  ' + text)
        self.badge.setAccessibleDescription(status_text + '. ' + o.ports.currentText() + '. Buka untuk memilih perangkat.')
        self.sidebar_status.setText(symbol + '  ' + status_text)
        self.badge.setToolTip(o.ports.currentText() if state == 'online' else 'Pilih atau cari ulang perangkat MIDI')
        for widget in (self.badge, self.sidebar_status):
            if widget.property('state') != state:
                widget.setProperty('state', state)
                widget.style().unpolish(widget)
                widget.style().polish(widget)
        if connecting and not reduced_motion():
            if self.connection_pulse.state() != QPropertyAnimation.Running:
                self.connection_pulse.start()
        else:
            self.connection_pulse.stop()
            self.badge.setIcon(QIcon())

    def navigate(self, index):
        previous = self.pages[self.stack.currentIndex()] if hasattr(self, 'pages') else self.stack.currentWidget()
        focused = QApplication.focusWidget()
        focus_in_page = focused is not None and previous.isAncestorOf(focused)
        changed = self.stack.currentIndex() != index
        if changed and hasattr(self, 'scroll_views') and not self.restoring_preferences:
            for name, view in self.scroll_views.items():
                if view.isVisibleTo(previous):
                    self.preferences.setValue(f'scroll/{name}', view.verticalScrollBar().value())
        self.stack.setCurrentIndex(index)
        self.sync_collection_undo()
        if hasattr(self, 'bottom_buttons'):
            for i, button in enumerate(self.bottom_buttons):
                button.setChecked(i == index)
        if changed and hasattr(self, 'page_fade') and not reduced_motion():
            self.page_fade.stop()
            self.page_fade.start()
        elif hasattr(self, 'page_opacity'):
            self.page_opacity.setOpacity(1.0)
        if changed and hasattr(self, 'scroll_views'):
            QTimer.singleShot(0, self.restore_scroll_positions)
        if hasattr(self, 'ab_switch_bar'):
            self.ab_switch_bar.setVisible(index == 2)
        if hasattr(self, 'sticky_actions'):
            self.sticky_actions.setVisible(self.owner.width() < 600 and index == 0)
        for i, button in enumerate(self.nav): button.setChecked(i == index)
        self.title.setText(self.PAGES[index][0]); self.subtitle.setText(self.PAGES[index][1])
        self.title.setToolTip(self.PAGES[index][1])
        if not self.restoring_preferences:
            self.preferences.setValue('navigation/page', index)
        if hasattr(self, 'skip_navigation'):
            QTimer.singleShot(0, self.update_focus_order)
            if changed and focus_in_page:
                replacement = QApplication.focusWidget()
                def restore_page_focus():
                    if not isValid(self.owner):
                        return
                    current = QApplication.focusWidget()
                    if self.stack.currentIndex() == index and (current is None or current is replacement):
                        self.focus_content()
                QTimer.singleShot(0, restore_page_focus)

    def restore_scroll_positions(self):
        if not isValid(self.owner):
            return
        page = self.pages[self.stack.currentIndex()]
        for name, view in self.scroll_views.items():
            if view.isVisibleTo(page) and self.preferences.contains(f'scroll/{name}'):
                value = self.preferences.value(f'scroll/{name}', 0, type=int)
                view.verticalScrollBar().setValue(value)

    def save_preferences(self):
        for name, view in self.scroll_views.items():
            self.preferences.setValue(f'scroll/{name}', view.verticalScrollBar().value())
        self.preferences.sync()

    def restore_device(self):
        preferred = self.preferences.value('devices/midi', '', type=str)
        index = self.owner.ports.findText(preferred)
        if index >= 0 and self.owner.output_port is None:
            self.owner.ports.setCurrentIndex(index)

    def restore_preferences(self):
        self.restore_device()
        self.collapse_button.setChecked(self.preferences.value('sidebar/collapsed', False, type=bool))
        for tabs in self.stack.findChildren(QTabWidget):
            key = 'tabs/' + tabs.objectName()
            index = self.preferences.value(key, 0, type=int)
            tabs.setCurrentIndex(max(0, min(tabs.count() - 1, index)))
            tabs.currentChanged.connect(lambda value, k=key: self.preferences.setValue(k, value)
                                        if not self.restoring_preferences else None)
        self.collection_view.setChecked(self.preferences.value('collection/grid', True, type=bool))
        index = self.preferences.value('navigation/page', 0, type=int)
        self.navigate(max(0, min(3, index)))

    def install_shortcuts(self):
        def bind(key, callback):
            shortcut = QShortcut(QKeySequence(key), self.owner)
            shortcut.setAutoRepeat(False)
            shortcut.activated.connect(callback)

        def editing_text():
            return isinstance(QApplication.focusWidget(), (QLineEdit, QAbstractSpinBox))

        bind('F6', self.focus_content)
        bind('Shift+F6', self.focus_navigation)
        for index in range(4):
            bind(f'Alt+{index + 1}', lambda i=index: self.navigate(i))

        for index in range(3):
            bind(str(index+1), lambda i=index: self.preset_buttons[i].click()
                 if self.stack.currentIndex() == 0 and not editing_text() else None)
        bind('Ctrl+R', lambda: self.owner.preset_read.click())
        bind('Ctrl+Z', lambda: self.undo_button.click()
             if self.stack.currentIndex() == 0 and not editing_text() else None)
        bind('Space', lambda: self.audio_meter.toggle.click()
             if self.stack.currentIndex() == 0 and not editing_text() and
             not isinstance(QApplication.focusWidget(), (QPushButton, QToolButton, QCheckBox, QComboBox)) else None)
        bind('Ctrl+K', self.focus_collection_search)
        bind('?', self.shortcut_help)
        self.owner.preset_read.setToolTip('Baca ulang preset dari pedal · Ctrl+R')
        self.owner.preset_save.setToolTip('Simpan efek ke pedal · Ctrl+S')
        self.undo_button.setToolTip('Kembalikan slot ke nilai terakhir yang dibaca/disimpan · Ctrl+Z')
        self.audio_meter.toggle.setToolTip('Mulai atau hentikan monitor audio · Space')
        self.owner.library_panel.search.setToolTip('Cari koleksi · Ctrl+K')
        for index, button in enumerate(self.preset_buttons):
            button.setToolTip(f'Pilih preset {chr(65+index)} · {index+1}')

    def focus_collection_search(self):
        self.navigate(1)
        self.owner.library_panel.search.setFocus()
        self.owner.library_panel.search.selectAll()

    def shortcut_help(self):
        dialog = QMessageBox(self.owner)
        dialog.setWindowTitle('Pintasan dan aksesibilitas')
        dialog.setText('Tema dan pintasan desktop\n\n1 / 2 / 3 — Pilih slot A / B / C (Editor suara)\n'
                       'Ctrl+S — Simpan efek\nCtrl+R — Baca ulang preset\n'
                       'Ctrl+Z — Batalkan perubahan slot (Editor suara)\n'
                       'Space — Mulai/stop monitor (Editor suara)\n'
                       'Ctrl+K — Cari di Koleksi\nA / B — Dengarkan IR (Bandingkan IR)\n'
                       'Alt+1–4 — Pindah halaman\nF6 — Lewati navigasi ke konten\n'
                       'Shift+F6 — Kembali ke navigasi\nEsc — Tutup/batalkan dialog\n? — Bantuan ini')
        motion = QCheckBox('Kurangi gerakan animasi')
        motion.setChecked(reduced_motion())
        motion.toggled.connect(self.set_reduced_motion)
        dialog.setCheckBox(motion)
        themes = QMenu(dialog)
        for title, mode in (('Gelap', 'dark'), ('Terang', 'light'), ('Ikuti sistem', 'system')):
            action = themes.addAction(title)
            action.setCheckable(True)
            action.setChecked(self.theme_mode == mode)
            action.triggered.connect(lambda checked, value=mode: self.change_theme(value))
        theme_button = QPushButton('Pilih tema')
        theme_button.setMenu(themes)
        dialog.addButton(theme_button, QMessageBox.ActionRole)
        dialog.setStandardButtons(QMessageBox.Close)
        dialog.button(QMessageBox.Close).setText('Tutup')
        dialog.exec()

    def change_theme(self, mode):
        self.theme_mode = mode
        self.apply_theme()

    def set_reduced_motion(self, value):
        self.preferences.setValue('accessibility/reducedMotion', value)
        self.audio_meter.bar.set_motion_enabled(not value)
        self.ambient.configure(self.theme.effective_glass)
        if value:
            self.page_fade.stop()
            self.page_opacity.setOpacity(1.0)
            self.toast_fade.stop()
            self.toast.graphicsEffect().setOpacity(1.0)
        for skeleton in self.stack.findChildren(LoadingSkeleton):
            if value:
                skeleton.timer.stop()
            elif skeleton.isVisible():
                skeleton.timer.start()

    def start_from_guide(self):
        if self.owner.connect_button.isEnabled():
            self.owner.connect_button.click()
        else:
            self.owner.refresh_button.click()
            self.badge.showMenu()

    def select_preset(self, index):
        self.owner.preset_selector.setCurrentIndex(index)
        self.sync_preset()

    def sync_preset(self):
        selector = self.owner.preset_selector
        for index, button in enumerate(self.preset_buttons):
            button.setEnabled(selector.isEnabled())
            button.setChecked(selector.currentIndex() == index)
            raw = self.owner.preset_data
            dirty = self.saved_presets is not None and raw is not None and raw[index*16:index*16+13] != self.saved_presets[index*16:index*16+13]
            button.setText(chr(65 + index) + (' ●' if dirty else ''))
            button.setAccessibleDescription('Ada perubahan belum disimpan.' if dirty else 'Tidak ada perubahan belum disimpan.')

    def editor(self):
        o = self.owner
        page = QWidget(); page.setObjectName('page')
        columns = QHBoxLayout(page); columns.setContentsMargins(0,0,0,0); columns.setSpacing(SPACE[3]); columns.setAlignment(Qt.AlignTop)
        self.editor_columns = columns
        fx, body = card('Preset di pedal')
        self.preset_card = fx
        body.setSpacing(8)
        self.editor_hint = label('', 'muted')
        self.editor_hint.setMinimumHeight(20)
        self.offline_guide = QWidget()
        guide = QHBoxLayout(self.offline_guide)
        guide.setContentsMargins(0, 0, 0, 0)
        guide.setSpacing(SPACE[1])
        guide.addWidget(PedalPreview())
        self.offline_steps = label('1. Colok USB  2. Pilih perangkat  3. Hubungkan')
        guide.addWidget(self.offline_steps, 1)
        self.offline_connect = QPushButton('Hubungkan')
        self.offline_connect.setProperty('role', 'primary')
        self.offline_connect.clicked.connect(self.start_from_guide)
        guide.addWidget(self.offline_connect)
        body.addWidget(self.offline_guide)
        body.addWidget(self.editor_hint)
        self.preset_skeleton = LoadingSkeleton()
        body.addWidget(self.preset_skeleton)
        hero = QFrame()
        hero.setObjectName('presetHero')
        preset = QVBoxLayout(hero)
        preset.setContentsMargins(12, 12, 12, 12)
        preset.setSpacing(8)
        self.preset_buttons = []
        slots = QHBoxLayout()
        self.preset_slots_row = slots
        slots.setSpacing(SPACE[1])
        slots.addWidget(label('Slot', 'fieldLabel', False))
        for index, letter in enumerate('ABC'):
            button = QPushButton(letter)
            button.setObjectName('presetSlot')
            button.setCheckable(True)
            button.setAccessibleName(f'Pilih preset {letter}')
            button.clicked.connect(lambda checked, i=index: self.select_preset(i))
            slots.addWidget(button, 1)
            self.preset_buttons.append(button)
        preset.addLayout(slots)
        o.preset_selector.setParent(hero)
        o.preset_selector.hide()
        o.preset_read.setText('Baca ulang')
        for button in (o.preset_read, o.preset_save):
            button.setSizePolicy(QSizePolicy.Ignored, QSizePolicy.Preferred)
        o.preset_save.setText('Simpan efek')
        o.preset_save.setProperty('role', 'primary')
        self.undo_button = QPushButton('Batalkan')
        self.undo_button.setToolTip('Kembalikan pengaturan slot ini ke nilai terakhir yang dibaca atau disimpan.')
        self.undo_button.clicked.connect(self.undo_preset)
        preset.addLayout(row(o.preset_read, self.undo_button, o.preset_save))
        volume = QHBoxLayout()
        volume_label = label('Volume', 'fieldLabel', False)
        volume.addWidget(volume_label)
        slider, spin = o.effect_controls[5]
        spin.setFixedWidth(64)
        spin.setAccessibleName('Volume')
        slider.setAccessibleName('Volume')
        volume_label.setBuddy(spin)
        move(volume, slider, 1)
        move(volume, spin)
        preset.addLayout(volume)
        body.addWidget(hero)
        groups = (
            (12, 'Amp', 'amp', 'accent_text', (0, 1, 2)),
            (11, 'Delay', 'delay', 'accent_text', (8, 6, 4, 7)),
            (10, 'Kabinet', 'space', 'accent_text', (9, 3)),
        )
        names = {0:'Jenis amp', 1:'Gain', 2:'Tone', 3:'Reverb', 4:'Feedback',
                 6:'Waktu delay', 7:'Campuran delay', 8:'Modulasi', 9:'Kabinet IR'}
        modules = QTabWidget()
        modules.setObjectName("effectTabs")
        chain = QHBoxLayout()
        chain.setSpacing(4)
        chain.addWidget(label('Gitar  →', 'muted', False))
        self.chain_buttons = []
        for index, (_, title, _, _, _) in enumerate(groups):
            button = QPushButton(title)
            button.setObjectName('chainStep')
            button.setCheckable(True)
            button.setToolTip(f'Buka kontrol {title}')
            button.clicked.connect(lambda checked, i=index: modules.setCurrentIndex(i))
            chain.addWidget(button, 1)
            self.chain_buttons.append(button)
        chain.addWidget(label('→  Keluar', 'muted', False))
        body.addLayout(chain)
        body.addWidget(modules)
        modules.currentChanged.connect(self.sync_chain)
        self.effect_tabs = modules
        for offset, title, tone, color, fields in groups:
            frame = QFrame(); frame.setObjectName('module'); frame.setProperty('tone', tone); layout = QVBoxLayout(frame); layout.setSpacing(SPACE[1]); layout.setContentsMargins(12,8,12,8)
            check = o.effect_switches[offset]; check.setText({12: "Aktifkan Amp", 11: "Aktifkan Modulasi / Delay", 10: "Aktifkan Kabinet / Reverb"}[offset]); move(layout, check)
            grid = QGridLayout(); grid.setHorizontalSpacing(SPACE[1]); grid.setVerticalSpacing(4)
            for r, field in enumerate(fields):
                slider, spin = o.effect_controls[field]
                parameter = label(names[field], 'fieldLabel')
                grid.addWidget(parameter, r, 0)
                if field == 0:
                    slider.setParent(frame)
                    spin.setParent(frame)
                    slider.hide()
                    spin.hide()
                    self.amp_select = QComboBox()
                    self.amp_select.setAccessibleName('Jenis amp')
                    self.amp_select.setToolTip('Nomor model mengikuti urutan pedal. Nama model belum terverifikasi.')
                    for value in range(spin.minimum(), spin.maximum() + 1):
                        self.amp_select.addItem(f'Model amp {value + 1}', value)
                    self.amp_select.currentIndexChanged.connect(
                        lambda index, control=spin: control.setValue(self.amp_select.itemData(index)))
                    parameter.setBuddy(self.amp_select)
                    grid.addWidget(self.amp_select, r, 1, 1, 2)
                    continue
                slider.setMinimumWidth(65)
                spin.setFixedWidth(64)
                spin.setAccessibleName(names[field])
                slider.setAccessibleName(names[field])
                parameter.setBuddy(spin)
                grid.addWidget(slider, r, 1)
                grid.addWidget(spin, r, 2)
                slider.show()
                spin.show()
            grid.setColumnStretch(1,1); layout.addLayout(grid); tab_index = modules.addTab(frame, glyph((0, 2, 3)[modules.count()]), title)
            modules.tabBar().setTabTextColor(tab_index, qc(color))
        columns.addWidget(fx, 7, Qt.AlignTop)
        tools = QTabWidget()
        tools.setObjectName("monitorTabs")
        tools.setMinimumWidth(0)
        self.monitor_tools = tools
        from .audio_meter import AudioMeter
        meter_card, meter_layout = card()
        meter_card.setObjectName("meterCard")
        self.audio_meter = AudioMeter(o); meter_layout.addWidget(self.audio_meter); meter_layout.addStretch()
        files, ir = card('File WAV')
        files.setObjectName('irCard')
        self.wav_skeleton = LoadingSkeleton()
        ir.addWidget(self.wav_skeleton)
        self.wav_skeleton.hide()
        o.wav_button.setText('Pilih file WAV'); o.wav_button.setProperty('role','primary'); o.folder_button.setText('Buka folder')
        o.wav_button.clicked.disconnect()
        o.wav_button.clicked.connect(lambda: self.wav_skeleton.run(o.choose_wav))
        o.folder_refresh.clicked.disconnect()
        o.folder_refresh.clicked.connect(lambda: self.wav_skeleton.run(o.refresh_wavs))
        o.folder_refresh.setText('↻'); o.folder_refresh.setToolTip('Muat ulang daftar WAV'); o.folder_refresh.setAccessibleName('Muat ulang daftar WAV')
        o.folder_refresh.setFixedWidth(37)
        for button in (o.wav_button, o.folder_button, o.folder_refresh): button.setIcon(QIcon())
        ir.addLayout(row(o.wav_button, o.folder_button, o.folder_refresh))
        move(ir, o.wav_list, 1)
        self.wav_empty = DropZone({'.wav'})
        self.wav_empty.files_dropped.connect(o.show_wav_files)
        empty_box = QVBoxLayout(self.wav_empty)
        empty_text = label('Lepas file WAV di sini atau klik Pilih file WAV.')
        empty_text.setAlignment(Qt.AlignCenter)
        empty_box.addWidget(empty_text)
        ir.addWidget(self.wav_empty, 1)
        ir_card, ir = card('Coba & simpan IR')
        ir_card.setObjectName('irCard')
        ir.setSpacing(8)
        self.ir_skeleton = LoadingSkeleton()
        ir.addWidget(self.ir_skeleton)
        self.ir_skeleton.hide()
        move(ir,o.wav_label); o.wav_label.setObjectName('muted'); o.wav_label.setTextFormat(Qt.PlainText)
        o.waveform.setMinimumHeight(66); o.waveform.setMaximumHeight(78); move(ir,o.waveform)
        ir.addWidget(label('Jarak mikrofon · Distance', 'fieldLabel'))
        o.distance.setSuffix(' %'); o.distance.setFixedWidth(76)
        o.distance.setToolTip('Simulasi jarak mikrofon. Nilai 100 dapat membuat suara sangat kecil atau senyap.')
        ir.addLayout(row(o.distance_slider, o.distance))
        o.preview_button.setText('Coba IR di pedal'); o.preview_button.setToolTip('Coba suara melalui RAM pedal. Mainkan gitar untuk mendengar. Slot tersimpan tidak ditimpa.')
        move(ir,o.preview_button)
        ir_drop = DropZone({'.json'})
        ir_drop.files_dropped.connect(lambda paths: o.import_ir(paths[0]) if len(paths) == 1 else
                                      o.status.setText('Pilih satu file JSON untuk slot IR.'))
        import_row = QHBoxLayout(ir_drop)
        import_row.setContentsMargins(8, 4, 8, 4)
        pick_ir = QPushButton('Pilih file JSON')
        pick_ir.clicked.connect(lambda: o.import_ir())
        import_row.addWidget(label('Lepas satu JSON di sini.'))
        import_row.addWidget(pick_ir)
        self.ir_drop = ir_drop
        ir.addWidget(ir_drop)
        o.ir_button.setText('Baca slot'); ir.addLayout(row(label('Slot tujuan', 'fieldLabel'), o.ir_slot, o.ir_button))
        o.save_button.setProperty('role','primary'); move(ir,o.save_button)
        self.ir_hint = label('Hubungkan pedal untuk mencoba atau menyimpan IR.', 'muted'); ir.addWidget(self.ir_hint)
        ir.addStretch()
        tools.addTab(meter_card, 'Meter gitar')
        tools.addTab(files, 'File WAV')
        tools.addTab(ir_card, 'Slot IR')
        self.editor_tools = tools
        slots_button = QPushButton('Atur dan simpan ke slot IR →')
        slots_button.clicked.connect(self.open_ir_slots)
        files.layout().addWidget(slots_button)
        columns.addWidget(tools, 5)
        self.editor_drawer = QTabWidget()
        self.editor_drawer.setObjectName('editorDrawer')
        self.editor_drawer.setDocumentMode(True)
        self.editor_drawer.hide()
        self.editor_drawer.currentChanged.connect(lambda: QTimer.singleShot(0, self.finish_adaptive_layout))
        columns.addWidget(self.editor_drawer)
        return page

    def sync_chain(self, index):
        for i, button in enumerate(self.chain_buttons):
            button.setChecked(i == index)

    def undo_preset(self):
        o = self.owner
        if self.saved_presets is None or o.preset_data is None or not o.preset_selector.isEnabled():
            return
        start = o.preset_selector.currentIndex() * 16
        for offset in range(13):
            o.change_effect(offset, self.saved_presets[start + offset])
        o.show_preset()

    def open_ir_slots(self):
        self.navigate(0)
        self.editor_tools.setCurrentIndex(2)

    def collection(self):
        p = self.owner.library_panel
        # Transfer the old layout to a disposable host; retain the actual controls.
        self.library_old_host = QWidget(); self.library_old_host.setLayout(p.layout())
        p.setObjectName('page'); layout = QHBoxLayout(p); layout.setContentsMargins(0,0,0,0); layout.setSpacing(SPACE[3])
        listing, left = card()
        left.setSpacing(8)
        p.new_preset.setText('Buat preset'); p.new_preset.setProperty('role','primary')
        p.new_preset.clicked.disconnect(p.edit_preset)
        p.new_preset.clicked.connect(p.new_preset_dialog)
        p.new_bank.setText('Buat bank'); p.import_file.setText('Impor file')
        p.new_sound.setText('Paket preset + IR')
        create = QPushButton('Buat baru')
        create.setProperty('menuControl', True)
        menu = QMenu(create)
        for button in (p.new_bank, p.new_sound):
            button.setParent(p)
            button.hide()
            menu.addAction(button.text(), button.click)
        create.setMenu(menu)
        left.addLayout(row(p.new_preset, create, p.import_file))
        p.kind_filter = QComboBox(); p.kind_filter.addItem('Semua', None)
        for text,value in (('Preset','preset'),('IR','ir'),('Bank','bank'),('Paket','sound')): p.kind_filter.addItem(text,value)
        p.kind_filter.setParent(p)
        p.kind_filter.hide()
        chips = QButtonGroup(p)
        chip_row = QHBoxLayout()
        chip_row.setSpacing(4)
        for index in range(p.kind_filter.count()):
            chip = QPushButton(p.kind_filter.itemText(index))
            chip.setObjectName('filterChip')
            chip.setCheckable(True)
            chip.setChecked(index == 0)
            chips.addButton(chip, index)
            chip_row.addWidget(chip, 1)
        chips.idClicked.connect(p.kind_filter.setCurrentIndex)
        p.kind_filter.currentIndexChanged.connect(lambda index: chips.button(index).setChecked(True))
        p.kind_filter.currentIndexChanged.connect(p.render)
        p.sort_mode = QComboBox()
        p.sort_mode.setAccessibleName('Urutan koleksi')
        p.sort_mode.addItem('Nama A–Z', 'name')
        p.sort_mode.addItem('Terbaru', 'recent')
        p.sort_mode.setCurrentIndex(1)
        p.sort_mode.currentIndexChanged.connect(p.render)
        p.kind_icons = {kind: glyph(i) for i, kind in enumerate(('preset', 'bank', 'ir', 'sound'))}
        view = QToolButton()
        self.collection_view = view
        view.setText('Tampilan: Daftar')
        view.setCheckable(True)
        view.setAccessibleName('Tampilan kartu atau daftar')
        view.setToolTip('Beralih antara tampilan kartu dan daftar')
        view.toggled.connect(lambda checked: self.set_collection_view(checked, view))
        self.collection_skeleton = LoadingSkeleton()
        left.addWidget(self.collection_skeleton)
        self.collection_skeleton.hide()
        p.import_file.clicked.disconnect()
        p.import_file.clicked.connect(lambda: self.collection_skeleton.run(p.import_files))
        p.search.setPlaceholderText('Cari nama…')
        p.search.setAccessibleName('Cari item koleksi')
        p.search.setMinimumHeight(40)
        move(left, p.search)
        left.addLayout(chip_row)
        toolbar = QHBoxLayout()
        toolbar.addWidget(p.sort_mode, 1)
        toolbar.addWidget(view)
        left.addLayout(toolbar)
        p.list.setSelectionMode(QAbstractItemView.ExtendedSelection)
        p.list.setMouseTracking(True)
        p.list.setItemDelegate(CollectionItemDelegate(p.list))
        p.list.itemSelectionChanged.connect(p.selection_changed)
        p.list.setContextMenuPolicy(Qt.CustomContextMenu)
        p.list.customContextMenuRequested.connect(self.collection_actions)

        listing_drop = DropZone({'.json', '.wav'})
        listing_drop.files_dropped.connect(p.import_paths)
        listing_layout = QVBoxLayout(listing_drop)
        listing_layout.setContentsMargins(0, 0, 0, 0)
        move(listing_layout, p.list, 1)
        left.addWidget(listing_drop, 1)
        p.list.setMinimumHeight(90)
        self.listing_drop = listing_drop
        drop = DropZone({'.json', '.wav'})
        drop.files_dropped.connect(p.import_paths)
        drop_layout = QVBoxLayout(drop)
        self.collection_empty = label('Lepas JSON atau WAV di sini, atau klik Impor file.')
        self.collection_empty.setAlignment(Qt.AlignCenter)
        drop_layout.addStretch()
        empty_icon = QLabel()
        empty_icon.setPixmap(glyph(1).pixmap(32, 32))
        empty_icon.setAlignment(Qt.AlignCenter)
        drop_layout.addWidget(empty_icon)
        drop_layout.addWidget(self.collection_empty)
        empty_create = QPushButton('Buat preset')
        empty_create.clicked.connect(p.new_preset.click)
        empty_import = QPushButton('Impor file')
        empty_import.clicked.connect(p.import_file.click)
        self.collection_empty_actions = QWidget()
        empty_actions = QHBoxLayout(self.collection_empty_actions)
        empty_actions.setContentsMargins(0, 0, 0, 0)
        empty_actions.addWidget(empty_create)
        empty_actions.addWidget(empty_import)
        drop_layout.addWidget(self.collection_empty_actions, 0, Qt.AlignHCenter)
        drop_layout.addStretch()
        left.addWidget(drop, 1)
        self.collection_drop = drop
        bottom = QHBoxLayout(); self.collection_count = label('0 item'); bottom.addWidget(self.collection_count); bottom.addStretch()
        refresh = QPushButton('Muat ulang')
        refresh.setProperty('role', 'ghost')
        refresh.clicked.connect(lambda: self.collection_skeleton.run(p.refresh))
        bottom.addWidget(refresh)
        left.addLayout(bottom)
        left.addWidget(label('ⓘ  Membuat dan mengimpor koleksi tidak menulis pedal.', 'muted'))
        self.collection_columns = layout
        self.collection_listing = listing
        layout.addWidget(listing, 7)
        detail_tabs = QTabWidget()
        detail_tabs.setObjectName("collectionTabs")
        detail, right = card()
        right.setSpacing(8)
        detail_header = QHBoxLayout()
        self.collection_detail_title = label('Detail koleksi', 'cardTitle', False)
        self.collection_detail_title.setMinimumWidth(0)
        self.collection_detail_title.setSizePolicy(QSizePolicy.Ignored, QSizePolicy.Preferred)
        detail_header.addWidget(self.collection_detail_title, 1)
        self.collection_menu_button = QToolButton()
        self.collection_menu_button.setText('…')
        self.collection_menu_button.setAccessibleName('Aksi item koleksi')
        self.collection_menu_button.clicked.connect(lambda: self.collection_actions())
        detail_header.addWidget(self.collection_menu_button)
        right.addLayout(detail_header)
        self.collection_kind = label('', 'eyebrow', False)
        right.addWidget(self.collection_kind)
        p.description.setFixedHeight(58)
        p.description.setSizePolicy(QSizePolicy.Ignored, QSizePolicy.Fixed)
        move(right,p.description)
        self.collection_preview = label('', 'muted')
        self.collection_preview.setFixedHeight(42)
        right.addWidget(self.collection_preview)
        self.collection_target_title = label('TUJUAN DI PEDAL', 'eyebrow')
        right.addWidget(self.collection_target_title)
        self.preset_target_row = QWidget(); target_row = QHBoxLayout(self.preset_target_row); target_row.setContentsMargins(0,0,0,0)
        target_row.addWidget(label('Preset tujuan', 'fieldLabel')); move(target_row,p.preset_target)
        self.ir_target_row = QWidget(); target_row = QHBoxLayout(self.ir_target_row); target_row.setContentsMargins(0,0,0,0)
        target_row.addWidget(label('Slot IR tujuan', 'fieldLabel')); move(target_row,p.ir_target)
        right.addWidget(self.preset_target_row); right.addWidget(self.ir_target_row)
        p.send_button.setText('Kirim ke pedal…'); p.send_button.setProperty('role','primary'); move(right,p.send_button)
        p.stage_button.setText('Buka IR di editor'); move(right,p.stage_button)
        p.export_file.setText('Ekspor file JSON'); move(right,p.export_file)
        self.collection_assign = QWidget()
        assign = QHBoxLayout(self.collection_assign)
        assign.setContentsMargins(0, 0, 0, 0)
        self.collection_ab_buttons = []
        for side in ('A','B'):
            button = QPushButton(f'Jadikan IR {side}'); button.clicked.connect(lambda checked,s=side:p.set_ab(s)); assign.addWidget(button)
            self.collection_ab_buttons.append(button)
        right.addWidget(self.collection_assign)
        right.addStretch()
        detail_tabs.addTab(detail, glyph(1), 'Detail')
        detail_tabs.setTabToolTip(0, 'Lihat isi, kelola item, atau kirim ke pedal.')
        capture, captures = card('Ambil dari editor & pedal')
        p.capture_preset.setText('Simpan preset editor'); p.capture_ir.setText('Simpan IR editor'); p.capture_bank.setText('Salin seluruh bank pedal')
        for widget in (p.capture_preset,p.capture_ir,p.capture_bank): move(captures,widget)
        captures.addWidget(label('Koleksi laptop tetap tersedia saat pedal dilepas.', 'muted'))
        captures.addStretch()
        detail_tabs.addTab(capture, glyph(3), 'Ambil sumber')
        detail_tabs.setTabToolTip(1, 'Simpan preset atau IR editor dan salin bank pedal.')
        diagnostics, body = card('Pesan koleksi')
        move(body, p.errors)
        p.errors.setObjectName('muted')
        body.addStretch()
        detail_tabs.addTab(diagnostics, glyph(0), 'Pesan impor')
        detail_tabs.setTabToolTip(2, 'Lihat pesan tentang file koleksi yang gagal dibaca.')
        layout.addWidget(detail_tabs, 5)
        self.collection_drawer = QTabWidget()
        self.collection_drawer.setObjectName('collectionDrawer')
        self.collection_drawer.hide()
        self.collection_drawer.currentChanged.connect(lambda: QTimer.singleShot(0, self.finish_adaptive_layout))
        layout.addWidget(self.collection_drawer)
        self.collection_tabs = detail_tabs
        p.list.itemActivated.connect(self.open_collection_detail)
        delete = QShortcut(QKeySequence(Qt.Key_Delete), p.list)
        delete.setContext(Qt.WidgetShortcut)
        delete.activated.connect(p.delete_selected)
        p.render()
        return p

    def open_collection_detail(self, item):
        if self.collection_drawer.count():
            self.collection_drawer.setCurrentIndex(1)
        self.collection_tabs.setCurrentIndex(0)
        self.collection_menu_button.setFocus()

    def collection_actions(self, position=None):
        panel = self.owner.library_panel
        if position is not None:
            item = panel.list.itemAt(position)
            if item is None:
                return
            if not item.isSelected():
                panel.list.setCurrentItem(item)
            anchor = panel.list.viewport().mapToGlobal(position)
        else:
            button = self.collection_menu_button
            anchor = button.mapToGlobal(button.rect().bottomLeft())
        count = len(panel.list.selectedItems())
        if not count:
            return
        menu = QMenu(panel)
        rename = menu.addAction('Ganti nama…', panel.rename_selected)
        rename.setEnabled(count == 1)
        if count == 1 and panel.list.selectedItems()[0].data(Qt.UserRole + 1) == 'preset':
            menu.addAction('Edit salinan preset…', panel.edit_preset)
        menu.addAction('Duplikat', panel.duplicate_selected)
        menu.addAction('Ekspor file JSON', panel.export_selected)
        menu.addSeparator()
        menu.addAction('Hapus…', panel.delete_selected)
        menu.exec(anchor)
        menu.deleteLater()

    def set_collection_view(self, cards, button):
        listing = self.owner.library_panel.list
        listing.setViewMode(QListView.IconMode if cards else QListView.ListMode)
        listing.setMovement(QListView.Static)
        listing.setResizeMode(QListView.Adjust)
        listing.setFlow(QListView.LeftToRight if cards else QListView.TopToBottom)
        listing.setWrapping(cards)
        listing.setGridSize(QSize() if not cards else QSize(240, 112))
        listing.fit_card_columns()
        button.setText('Tampilan: Kartu' if cards else 'Tampilan: Daftar')
        if not self.restoring_preferences:
            self.preferences.setValue('collection/grid', cards)

    def comparison(self):
        p = self.owner.library_panel
        page = QWidget()
        page.setObjectName('page')
        layout = QVBoxLayout(page)
        layout.setContentsMargins(0, 0, 0, 0)
        layout.setSpacing(8)
        from .suite_gui import Waveform

        self.ab_empty = QWidget()
        empty_layout = QHBoxLayout(self.ab_empty)
        empty_layout.setContentsMargins(0, 0, 0, 0)
        empty_layout.addWidget(label('1. Pilih IR A   2. Pilih IR B   3. Dengarkan dan bandingkan.'), 1)
        choose = QPushButton('Pilih dari Koleksi')
        choose.clicked.connect(lambda: self.choose_ab('A', collection_only=True))
        empty_layout.addWidget(choose)
        layout.addWidget(self.ab_empty)

        columns = QHBoxLayout()
        columns.setSpacing(12)
        self.comparison_columns = columns
        self.ab_names = {}
        self.ab_waves = {}
        self.ab_indicators = {}
        self.ab_metadata = {}
        self.ab_switches = {}
        self.ab_requested = None
        self.ab_preview = None
        self.ab_wave_data = {}
        for side, capture, play in (('A', p.ab_set_a, p.ab_play_a), ('B', p.ab_set_b, p.ab_play_b)):
            frame, box = card(('◈  ' if side == 'A' else '≋  ') + f'Pilihan {side}')
            frame.setObjectName('compareA' if side == 'A' else 'compareB')
            box.setContentsMargins(16, 16, 16, 16)
            box.setSpacing(4)
            name = label('Belum ada IR', 'cardTitle')
            name.setMinimumHeight(20)
            name.setSizePolicy(QSizePolicy.Ignored, QSizePolicy.Fixed)
            self.ab_names[side] = name
            box.addWidget(name)
            metadata = label('Pilih IR untuk melihat metadata.', 'muted')
            metadata.setSizePolicy(QSizePolicy.Ignored, QSizePolicy.Preferred)
            self.ab_metadata[side] = metadata
            box.addWidget(metadata)
            wave = Waveform()
            wave.tone = 'accent_text' if side == 'A' else 'info_text'
            wave.setMinimumHeight(44)
            wave.setAccessibleName(f'Bentuk gelombang IR {side}')
            self.ab_waves[side] = wave
            box.addWidget(wave, 1)
            indicator = label('Pilih IR untuk mulai.')
            indicator.setFixedHeight(24)
            self.ab_indicators[side] = indicator
            box.addWidget(indicator)
            capture.setText('Pilih IR…')
            capture.clicked.disconnect()
            capture.clicked.connect(lambda checked, s=side: self.choose_ab(s))
            move(box, capture)
            play.setText(f'Dengarkan {side}')
            play.setMinimumHeight(26)
            play.setProperty('role', 'primary')
            play.clicked.disconnect()
            play.clicked.connect(lambda checked, s=side: self.listen_ab(s))
            move(box, play)
            columns.addWidget(frame, 1)
        layout.addLayout(columns, 1)

        switch_row = QHBoxLayout()
        switch_row.addWidget(label('Beralih cepat', 'fieldLabel', False))
        for side in ('A', 'B'):
            button = QPushButton(side)
            button.setObjectName('presetSlot')
            button.setCheckable(True)
            button.setAccessibleName(f'Dengarkan IR {side}')
            button.clicked.connect(lambda checked, s=side: self.listen_ab(s))
            self.ab_switches[side] = button
            switch_row.addWidget(button, 1)
            shortcut = QShortcut(QKeySequence(side), page)
            shortcut.setContext(Qt.WindowShortcut)
            shortcut.setAutoRepeat(False)
            shortcut.activated.connect(lambda s=side: self.shortcut_ab(s))
        switch_row.addWidget(label('Pintasan A / B', 'muted', False))
        self.comparison_switch_row = switch_row
        self.ab_switch_bar = QWidget()
        self.ab_switch_bar.setLayout(switch_row)
        self.workspace_layout.addWidget(self.ab_switch_bar)
        self.ab_switch_bar.hide()

        options, box = card('Perbandingan yang konsisten')
        box.setContentsMargins(12, 8, 12, 8)
        box.setSpacing(4)
        options_grid = QGridLayout()
        options_grid.setHorizontalSpacing(16)
        options_grid.setVerticalSpacing(4)
        self.comparison_option_items = []
        self.comparison_options_grid = options_grid
        p.same_distance.setText('Samakan jarak mikrofon')
        p.same_distance.setToolTip('Distance menyimulasikan jarak mikrofon. Kedua IR memakai nilai dari Editor suara saat dicoba.')
        p.same_peak.setText('Samakan level puncak')
        p.same_peak.setToolTip('Level puncak adalah amplitudo sampel tertinggi. Penyamaan membantu membandingkan karakter kabinet.')
        for column, control, hint in (
            (0, p.same_distance, 'Pakai nilai Distance dari Editor suara.'),
            (1, p.same_peak, 'Samakan amplitudo tertinggi kedua IR.'),
        ):
            control.show()
            hint_label = label(hint, 'muted')
            self.comparison_option_items.append((control, hint_label))
            options_grid.addWidget(control, 0, column)
            options_grid.addWidget(hint_label, 1, column)
        box.addLayout(options_grid)
        p.ab_status.setParent(options)
        p.ab_status.hide()
        self.ab_summary = label('Pilih dua IR untuk membandingkan datanya.')
        self.ab_summary.setFixedHeight(32)
        box.addWidget(self.ab_summary)
        chips = QHBoxLayout()
        self.ab_status_chips = {}
        for side in ('A', 'B'):
            chip = label(f'{side}: belum dipilih', 'badge', False)
            chip.setMinimumWidth(0)
            chip.setSizePolicy(QSizePolicy.Ignored, QSizePolicy.Preferred)
            self.ab_status_chips[side] = chip
            chips.addWidget(chip, 1)
        safe = label('✓  Slot IR di pedal tidak ditimpa', 'muted')
        safe.setToolTip('Dengarkan A/B mencoba IR melalui RAM pedal.')
        chips.addWidget(safe)
        box.addLayout(chips)
        layout.addWidget(options)
        self.library_old_host.deleteLater()
        return page

    def shortcut_ab(self, side):
        from PySide6.QtWidgets import QApplication

        if self.stack.currentIndex() != 2 or QApplication.activeModalWidget() is not None:
            return
        if isinstance(QApplication.focusWidget(), (QLineEdit, QAbstractSpinBox)):
            return
        self.listen_ab(side)

    def listen_ab(self, side):
        p = self.owner.library_panel
        if not self.owner.device_ready() or side not in p.ab:
            self.sync_comparison()
            return
        p.play_ab(side)
        self.ab_requested = side if self.owner.memory_job is not None else None
        self.sync_comparison()

    def choose_ab(self, side, collection_only=False):
        p = self.owner.library_panel
        try:
            entries, _ = p.store.entries(); irs = [item for _,item in entries if item['kind'] == 'ir']
            if collection_only and not irs:
                self.navigate(1)
                self.owner.library_panel.kind_filter.setCurrentIndex(2)
                self.owner.status.setText('Impor WAV atau JSON IR ke Koleksi, lalu jadikan IR A atau B.')
                return
            choices = [f'{i+1}. {item["name"]}' for i,item in enumerate(irs)]
            if not collection_only:
                choices.insert(0, 'IR yang sedang ada di editor')
            text, ok = QInputDialog.getItem(self.owner, f'IR pilihan {side}', 'Sumber IR', choices, 0, False)
            if not ok: return
            index = choices.index(text)
            if collection_only or index:
                from .collection import unpacked
                item = irs[index if collection_only else index-1]; source = (unpacked(item,'ir'),item['name'])
            else: source = (self.owner.desired_record(), self.owner.wav_label.text() or 'IR editor')
            p.set_ab(side, source=source)
        except (OSError, ValueError) as exc: p.warn(exc)

    def device(self):
        from .device_ui import BackupPanel, MidiLogPanel, confirm_reset

        o = self.owner
        page = QWidget()
        page.setObjectName('page')
        layout = QVBoxLayout(page)
        layout.setContentsMargins(0, 0, 0, 0)
        layout.setSpacing(8)
        tabs = QTabWidget()
        tabs.setObjectName("deviceTabs")
        self.device_tabs = tabs

        connection, body = card('Koneksi pedal')
        connection_group = QVBoxLayout()
        connection_group.setSpacing(SPACE[0])
        self.device_connection_state = label('Pedal belum terhubung', 'fieldLabel')
        device_state_row = QHBoxLayout()
        self.device_pedal_preview = PedalPreview()
        device_state_row.addWidget(self.device_pedal_preview)
        device_state_row.addWidget(self.device_connection_state, 1)
        connection_group.addLayout(device_state_row)
        move(connection_group, o.device_label)
        select_input = QPushButton('Buka pilihan perangkat')
        select_input.clicked.connect(self.badge.showMenu)
        select_input.setToolTip('Buka popover untuk memilih input MIDI dan mencari ulang perangkat.')
        connection_group.addWidget(select_input, 0, Qt.AlignLeft)
        body.addLayout(connection_group)
        output_group = QVBoxLayout()
        output_group.setSpacing(SPACE[0])
        o.outputs.setAccessibleName('Output MIDI')
        o.outputs.setMinimumContentsLength(10)
        o.outputs.setSizeAdjustPolicy(QComboBox.AdjustToMinimumContentsLengthWithIcon)
        output_group.addWidget(label('Output MIDI', 'fieldLabel'))
        move(output_group, o.outputs)
        output_group.addWidget(label('Pilih port output pedal yang berpasangan dengan input MIDI.', 'muted'))
        o.info_button.setText('Baca informasi')
        o.info_button.setToolTip('Baca data model dan kapasitas penyimpanan pedal lewat MIDI.')
        output_group.addWidget(o.info_button, 0, Qt.AlignLeft)
        o.info_button.show()
        body.addLayout(output_group)
        loopback_group = QVBoxLayout()
        loopback_group.setSpacing(SPACE[0])
        o.loopback.setText('USB Loopback')
        o.loopback.setToolTip('Aktifkan untuk mengembalikan audio USB dari komputer melalui pedal.')
        move(loopback_group, o.loopback)
        loopback_group.addWidget(label('Saat aktif, audio komputer ikut kembali melalui jalur audio USB pedal.', 'muted'))
        body.addLayout(loopback_group)
        help_group = QVBoxLayout()
        help_group.setSpacing(SPACE[0])
        help_title = label('Bantuan koneksi', 'fieldLabel')
        help_group.addWidget(help_title)
        help_text = label('Cek kabel USB data dan daya pedal. Periksa perangkat MIDI di sistem/driver. '
                          'Tutup aplikasi lain yang memakai MIDI, lalu cari ulang perangkat.', 'muted')
        help_text.setMaximumWidth(720)
        help_group.addWidget(help_text)
        body.addLayout(help_group)
        body.addStretch()
        tabs.addTab(connection, glyph(3), 'Koneksi')

        backup, body = card('Cadangan IR')
        body.setSpacing(8)
        self.backup_panel = BackupPanel(o)
        body.addWidget(self.backup_panel, 1)
        legacy = QHBoxLayout()
        o.ir_export_button.setText('Ekspor IR ke JSON')
        o.import_button.setText('Muat IR / cadangan JSON')
        move(legacy, o.ir_export_button)
        move(legacy, o.import_button)
        body.addLayout(legacy)
        for widget in (o.ir_status, o.edit_status):
            widget.setFixedHeight(34)
            widget.setSizePolicy(QSizePolicy.Ignored, QSizePolicy.Fixed)
            move(body, widget)
        tabs.addTab(backup, glyph(1), 'Cadangan IR')

        diagnostics, body = card('Log MIDI')
        self.midi_log = MidiLogPanel(o)
        body.addWidget(self.midi_log, 1)
        o.log.setParent(self.midi_log)
        o.log.hide()
        o.toggle.setText('Pantau MIDI pasif')
        move(body, o.toggle)
        tabs.addTab(diagnostics, glyph(2), 'Log MIDI')
        layout.addWidget(tabs, 1)

        reset, body = card()
        reset.setObjectName('dangerZone')
        body.setContentsMargins(12, 8, 12, 8)
        body.setSpacing(SPACE[1])
        header = QHBoxLayout()
        header.addWidget(label('Zona berbahaya', 'cardTitle'), 1)
        reveal = QToolButton()
        reveal.setText('Tampilkan pilihan reset')
        reveal.setCheckable(True)
        header.addWidget(reveal)
        body.addLayout(header)
        controls = QWidget()
        actions = QHBoxLayout(controls)
        actions.setContentsMargins(0, 0, 0, 0)
        actions.addWidget(label('Reset mengganti isi tersimpan dengan data bawaan.'), 1)
        for button, text, message, callback in (
            (o.factory_presets_button, 'Reset ketiga preset',
             'Ketiga preset A/B/C akan diganti dengan data bawaan.', o.reset_presets),
            (o.factory_ir_button, 'Reset delapan IR',
             'Seluruh slot IR 1–8 akan diganti dengan data bawaan.', o.reset_irs),
        ):
            button.setText(text)
            button.setProperty('role', 'danger')
            button.clicked.disconnect()
            button.clicked.connect(lambda checked, msg=message, action=callback:
                                   confirm_reset(o, msg, action))
            move(actions, button)
        body.addWidget(controls)
        controls.hide()
        reveal.toggled.connect(controls.setVisible)
        layout.addWidget(reset)
        tabs.currentChanged.connect(lambda index: self.backup_panel.refresh() if index == 1 else None)
        return page

    def sync_comparison(self):
        if not hasattr(self, 'ab_names'):
            return

        o = self.owner
        p = o.library_panel
        ready = o.device_ready()
        job = o.memory_job
        loading = job is not None and self.ab_requested is not None and self.ab_preview is None
        if job is None:
            self.ab_requested = None
        self.ab_empty.setVisible(not p.ab)
        for side, widget in self.ab_names.items():
            source = p.ab.get(side)
            name = source[1] if source else 'Belum ada IR'
            widget.setText(name)
            widget.setWordWrap(True)
            widget.setMaximumHeight(16777215)
            widget.setMinimumHeight(20)
            widget.setSizePolicy(QSizePolicy.Ignored, QSizePolicy.Preferred)
            widget.setToolTip(name)
            if self.ab_wave_data.get(side) != source:
                samples = ir_waveform_samples(bytes(source[0])) if source else ()
                self.ab_waves[side].set_values(samples)
                self.ab_wave_data[side] = source
            self.ab_metadata[side].setText('512 sampel · 48 kHz · 10,67 ms' if source else 'Pilih IR untuk melihat metadata.')
            self.ab_metadata[side].setToolTip('Format IR yang dikirim ke pedal setelah konversi.')
            active = source is not None and o.preview_active and self.ab_preview == (side, source)
            pending = loading and self.ab_requested == side
            play = p.ab_play_a if side == 'A' else p.ab_play_b
            capture = p.ab_set_a if side == 'A' else p.ab_set_b
            capture.setText('Ganti IR…' if source else 'Pilih IR…')
            play.setText(f'Memuat {side}…' if pending else f'●  Dengarkan {side} · aktif' if active else f'Dengarkan {side}')
            switch = self.ab_switches[side]
            switch.setEnabled(ready and source is not None)
            switch.setChecked(active)
            reason = ('Pilih IR terlebih dahulu.' if source is None else
                      'Hubungkan pedal untuk mendengarkan.' if o.identity is None else
                      'Tunggu proses pedal selesai.' if not ready else f'Dengarkan pilihan {side}.')
            play.setToolTip(reason)
            switch.setToolTip(reason)
            if pending:
                text = 'Mengirim dan memverifikasi IR…'
            elif source is None:
                text = 'Pilih IR untuk mulai.'
            elif active:
                text = '●  Terverifikasi di RAM · mainkan gitar'
            elif o.identity is None:
                text = 'Hubungkan pedal untuk mendengarkan.'
            else:
                text = 'Siap dibandingkan' if ready else 'Tunggu proses pedal selesai.'
            self.ab_indicators[side].setText(text)
            chip = self.ab_status_chips[side]
            full = f'{side}: {name if source else "belum dipilih"}'
            chip.setText(full)
            chip.setWordWrap(True)
            chip.setToolTip(full)
        if len(p.ab) == 2:
            identical = p.ab['A'][0] == p.ab['B'][0]
            peaks = f'Puncak sumber A {self.ab_waves["A"].peak:.3f} · B {self.ab_waves["B"].peak:.3f}'
            self.ab_summary.setText(('Data kedua IR identik. ' if identical else 'Dua kandidat siap dibandingkan. ') + peaks)
        else:
            self.ab_summary.setText('Pilih dua IR, lalu gunakan A / B untuk berganti saat bermain gitar.')

    def sync(self):
        o = self.owner
        if o.pending is not None and o.pending[0] in ('info', 'ir'):
            self.last_read_action = o.info_button if o.pending[0] == 'info' else o.ir_button
        elif o.memory_job is not None and o.memory_job.label == 'Membaca efek':
            self.last_read_action = o.preset_read
        elif o.memory_job is not None or o.ir_writer is not None or o.transfer is not None:
            self.last_read_action = None
        self.ir_skeleton.setVisible(o.ir_reader is not None or
                                    o.memory_job is not None and 'Membaca slot' in o.memory_job.label)
        busy = o.pending is not None or o.ir_writer is not None or o.memory_job is not None or o.transfer is not None or o.factory_queue is not None
        self.sync_preset()
        if hasattr(self, 'mobile_save'):
            self.mobile_save.setEnabled(o.preset_save.isEnabled())
            self.mobile_ir.setEnabled(o.save_button.isEnabled())
        self.backup_panel.sync()
        self.device_pedal_preview.setVisible(o.identity is None)
        self.device_connection_state.setText('●  Pedal terhubung' if o.identity else
                                             'Menghubungkan…' if o.output_port else
                                             '1. Colok USB  2. Pilih perangkat  3. Klik Hubungkan')
        for button in (o.factory_presets_button, o.factory_ir_button):
            button.setToolTip('Ketik RESET lalu konfirmasi untuk mengganti isi pedal.' if button.isEnabled()
                              else 'Hubungkan pedal yang didukung dan tunggu sampai siap.')
        self.sync_chain(self.effect_tabs.currentIndex())
        amp_spin = o.effect_controls[0][1]
        self.amp_select.setEnabled(amp_spin.isEnabled())
        with QSignalBlocker(self.amp_select):
            self.amp_select.setCurrentIndex(self.amp_select.findData(amp_spin.value()))
        self.sync_connection()
        if o.preset_data is None:
            self.saved_presets = None
        dirty = self.saved_presets is not None and o.preset_data != self.saved_presets
        self.dirty_label.setText('● belum disimpan' if dirty else '')
        start = o.preset_selector.currentIndex() * 16
        slot_dirty = dirty and o.preset_data[start:start+13] != self.saved_presets[start:start+13]
        self.undo_button.setEnabled(slot_dirty and o.preset_selector.isEnabled())
        connecting = o.output_port is not None and o.identity is None
        self.offline_guide.setVisible(o.identity is None and not connecting)
        self.editor_hint.setVisible(o.identity is not None or connecting)
        self.preset_skeleton.setVisible(connecting or (o.identity is not None and o.preset_data is None and busy))
        no_ports = o.ports.count() == 0
        self.offline_steps.setText('Perangkat belum ditemukan. Cek kabel USB data dan tutup aplikasi MIDI lain.' if no_ports else
                                   '1. Colok USB  2. Pilih perangkat  3. Klik Hubungkan')
        self.offline_connect.setText('Cari ulang' if no_ports else 'Hubungkan')
        if o.identity is None:
            self.editor_hint.setText('Menghubungkan pedal…')
        elif o.preset_data is None:
            reading = o.memory_job is not None and o.memory_job.label == 'Membaca efek'
            self.editor_hint.setText('Membaca preset dari pedal…' if reading else
                                     'Klik Baca ulang untuk memuat preset.')
        else:
            self.editor_hint.setText('Ada perubahan belum disimpan · Ctrl+S' if dirty else
                                     f'Mengedit preset {chr(65 + o.preset_selector.currentIndex())}')
        self.wav_empty.setEnabled(o.wav_button.isEnabled())
        self.wav_empty.setToolTip('Hubungkan pedal untuk mencoba file WAV.' if not o.identity else '')
        o.connect_button.setToolTip('Colok pedal USB dan cari ulang port MIDI.' if
                                    not o.connect_button.isEnabled() and o.identity is None else '')
        self.ir_drop.setEnabled(o.import_button.isEnabled())
        self.ir_drop.setToolTip('Baca slot IR terlebih dahulu untuk memuat file JSON.' if not o.import_button.isEnabled() else '')
        self.progress.setRange(0, 0 if busy else 1); self.progress.setValue(0)
        self.activity.setObjectName('activity')
        activity_state = 'success' if self.success_timer.isActive() and not busy else ''
        if self.activity.property('state') != activity_state:
            self.activity.setProperty('state', activity_state)
            self.activity.style().unpolish(self.activity); self.activity.style().polish(self.activity)
        self.activity.setText('Memproses…' if busy else '✓ Selesai' if self.success_timer.isActive() else 'Siap' if o.identity else 'Terputus')
        o.status.setToolTip(o.status.text())
        self.wav_empty.setVisible(o.wav_list.count() == 0)
        o.wav_list.setVisible(o.wav_list.count() > 0)
        o.save_button.setText(('Pulihkan' if o.imported_sector is not None else 'Simpan IR')+f' ke slot {o.ir_slot.currentIndex()+1}')
        if not o.identity: hint = 'Hubungkan pedal untuk mencoba dan menyimpan IR. Koleksi tetap bisa digunakan offline.'
        elif busy: hint = 'Proses sedang berjalan. Tunggu sampai selesai.'
        elif o.preview_active: hint = 'IR sudah dikirim untuk dicoba. Simpan ke slot jika ingin mempertahankannya.'
        else: hint = 'Coba IR hanya memakai RAM. Simpan IR akan mengganti slot tujuan.'
        self.ir_hint.setText(hint)
        p = o.library_panel
        self.collection_count.setText(f'{p.list.count()} item')
        empty = p.list.count() == 0
        p.list.setVisible(not empty); self.collection_empty.setVisible(empty)
        self.collection_drop.setVisible(empty)
        self.listing_drop.setVisible(not empty)
        p.send_button.setToolTip('Hubungkan pedal untuk mengirim item.' if not o.identity else 'Pilih satu item dan tentukan slot tujuan.')
        filtered = bool(p.search.text().strip()) or p.kind_filter.currentData() is not None
        self.collection_empty.setText('Tidak ada hasil. Coba nama atau jenis lain.' if filtered else 'Koleksi masih kosong. Buat preset atau lepas JSON/WAV di sini.')
        self.collection_empty_actions.setVisible(not filtered)
        self.collection_drop.setToolTip('Lepas file JSON atau WAV untuk mengimpor ke koleksi.')
        selection = p.list.selectedItems()
        selected = selection[0] if len(selection) == 1 else None
        kind = selected.data(Qt.UserRole+1) if selected is not None else None
        p.new_preset.setText('Buat preset')
        self.collection_menu_button.setVisible(bool(selection))
        self.collection_detail_title.setText('Detail koleksi')
        self.collection_kind.setVisible(kind is not None)
        self.collection_preview.setVisible(kind is not None)
        self.collection_target_title.setVisible(kind is not None)
        self.collection_assign.setVisible(kind == 'ir')
        p.send_button.setVisible(bool(selection))
        p.export_file.setVisible(bool(selection))
        for button, available, reason in (
            (p.capture_bank, o.device_ready(), 'Hubungkan pedal untuk menyalin bank.' if not o.identity else 'Tunggu sampai pedal siap.'),
            (p.capture_preset, p.capture_preset.isEnabled(), 'Baca preset dari pedal terlebih dahulu.' if o.preset_data is None else 'Tunggu sampai pedal siap.'),
            (p.capture_ir, p.capture_ir.isEnabled(), 'Muat IR di Editor suara terlebih dahulu.'),
            *((button, p.ab_set_a.isEnabled(), 'Tunggu proses pedal selesai.') for button in self.collection_ab_buttons),
        ):
            if button in self.collection_ab_buttons:
                button.setEnabled(available)
            button.setToolTip(reason if not available else '')
        if selected is not None:
            details = p.item_details
            if details is not None:
                name, badge, preview = details
                self.collection_detail_title.setText(name)
                self.collection_detail_title.setWordWrap(True)
                self.collection_detail_title.setToolTip(name)
                self.collection_kind.setText(badge)
                self.collection_preview.setText(preview)
                self.collection_preview.setToolTip(preview)
        else:
            self.collection_detail_title.setToolTip('')
        if not p.send_button.isEnabled() and o.identity is not None:
            p.send_button.setToolTip('Pilih satu item.' if len(selection) != 1 else
                                     'Tunggu proses selesai dan pastikan pedal siap menerima data.')
        if not selection: p.description.setText('Pilih item di kiri untuk melihat isinya.')
        self.preset_target_row.setVisible(kind in ('preset','sound'))
        self.ir_target_row.setVisible(kind in ('ir','sound'))
        p.stage_button.setVisible(kind == 'ir')
        p.description.setToolTip(p.description.text())
        self.sync_comparison()
        self.update_focus_order()
