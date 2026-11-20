"""Read-only input level meter. No MIDI, audio output, recording or file writes."""
import math
import struct
from .ui_preferences import settings
from .theme_tokens import qc
from .rendering_ui import AnimatedLevelBar as LevelBar
from PySide6.QtCore import QTimer, Qt, QIODevice, QBuffer
from PySide6.QtGui import QColor, QFont
from PySide6.QtWidgets import QWidget, QVBoxLayout, QHBoxLayout, QLabel, QComboBox, QPushButton


def dbfs(value):
    return 20*math.log10(value) if value > 0 else -math.inf


def same_audio_enum(value, expected):
    # QAudio compatibility aliases and QtAudio can be distinct Python enums.
    return getattr(value, 'value', value) == getattr(expected, 'value', expected)


class PCMLevels:
    """Streaming native-endian PCM; max per-channel RMS avoids stereo cancellation."""
    FORMATS = {'u8': ('B',1,128.), 's16': ('h',2,32768.), 's32': ('i',4,2147483648.), 'f32': ('f',4,1.)}

    def __init__(self, sample_format, channels):
        if sample_format not in self.FORMATS or type(channels) is not int or not 1 <= channels <= 32:
            raise ValueError('Format audio input tidak didukung')
        self.code,self.width,self.scale=self.FORMATS[sample_format]
        self.channels=channels; self.pending=b''
        self.reset()

    def reset(self):
        self.sums=[0.]*self.channels; self.frames=0; self.peak=0.; self.clipped=False

    def feed(self, data):
        data=self.pending+bytes(data); frame_size=self.channels*self.width
        size=len(data)//frame_size*frame_size
        self.pending=data[size:]
        if not size: return
        values=struct.iter_unpack('='+self.code, data[:size])
        for i,(sample,) in enumerate(values):
            value=(sample-128)/128. if self.code=='B' else sample/self.scale
            if not math.isfinite(value): raise ValueError('Input audio berisi sampel nonfinite')
            # Flag either integer rail, including positive PCM maximum below 1.0.
            rail=(self.scale-1)/self.scale if self.code in ('h','i','B') else 1.
            self.clipped |= value <= -1. or value >= rail
            self.peak=max(self.peak,abs(value)); self.sums[i%self.channels]+=value*value
        self.frames+=size//frame_size

    def take(self):
        rms=math.sqrt(max(self.sums)/self.frames) if self.frames else 0.
        result=(dbfs(self.peak),dbfs(rms),self.clipped,self.frames)
        self.reset(); return result


class AudioInputBuffer(QBuffer):
    """RAM destination; drain every meter tick, never record to disk."""
    def __init__(self, parent=None):
        super().__init__(parent)
        self.open(QIODevice.WriteOnly)

    def take(self):
        if self.size() > 1024*1024:
            raise ValueError('Buffer audio melampaui batas; monitor dihentikan.')
        result=bytes(self.data())
        self.buffer().clear()
        self.seek(0)
        return result


class AudioMeter(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.source=None; self.stream=None; self.levels=None; self.peak_hold=-math.inf
        self.clip_hold=False; self.stopping=False; self.api=None
        layout=QVBoxLayout(self); layout.setContentsMargins(0,0,0,0); layout.setSpacing(8)
        title=QLabel('Level gitar · dB relatif'); title.setObjectName('cardTitle'); layout.addWidget(title)
        hint=QLabel('Pilih input audio Cube Baby / interface. MIDI tidak membawa suara.'); hint.setWordWrap(True); hint.setObjectName('muted'); layout.addWidget(hint)
        controls=QHBoxLayout(); self.inputs=QComboBox(); self.inputs.setMinimumWidth(0)
        self.inputs.setPlaceholderText('Pilih input…')
        self.inputs.setAccessibleName('Pilih input audio')
        self.inputs.setMinimumContentsLength(7); self.inputs.setSizeAdjustPolicy(QComboBox.AdjustToMinimumContentsLengthWithIcon)
        self.inputs.activated.connect(self.remember_input)
        self.inputs.setToolTip('Pilih input audio, bukan port MIDI. Hindari mikrofon laptop bila ingin mengukur output pedal.')
        controls.addWidget(self.inputs,1)
        self.refresh=QPushButton('Cari input'); self.refresh.clicked.connect(self.refresh_inputs); controls.addWidget(self.refresh)
        self.toggle=QPushButton('Mulai monitor'); self.toggle.clicked.connect(self.toggle_monitor); layout.addLayout(controls)
        layout.addWidget(self.toggle)
        self.bar=LevelBar(); self.bar.setRange(0,1200); self.bar.setValue(0); self.bar.setTextVisible(False)
        self.bar.fill_limit = 870  # 0 dBFS remains +27 dB relative, even on the wider scale.
        self.bar.setFixedHeight(18)
        self.bar.setStyleSheet('QProgressBar {max-height:18px;}')
        self.bar.setAccessibleName('Level puncak input, skala relatif minus 60 sampai plus 60 dB'); layout.addWidget(self.bar)
        scale = QHBoxLayout()
        ticks = (-60, -40, -20, 0, 20, 40, 60)
        for index, tick in enumerate(ticks):
            if index:
                scale.addStretch(tick - ticks[index - 1])
            scale.addWidget(QLabel(f'{tick:+g}' if tick else '0'))
        layout.addLayout(scale)
        self.bar.setToolTip('Skala −60 sampai +60 dB relatif. 0 dB relatif = −27 dBFS; input mencapai clipping pada +27 dB relatif. Bukan ukuran dB SPL atau penguatan audio.')
        self.clip_badge = QLabel('! CLIP'); self.clip_badge.setObjectName('clipBadge')
        self.clip_badge.hide(); layout.addWidget(self.clip_badge)
        numbers=QHBoxLayout(); self.reading=QLabel('Peak —   RMS —   Hold — dB rel.'); self.reading.setWordWrap(True); numbers.addWidget(self.reading,1)
        readings_font = QFont('monospace'); readings_font.setStyleHint(QFont.Monospace)
        self.reading.setFont(readings_font)
        self.reading.setObjectName('meterReading')
        reset=QPushButton('Reset peak'); reset.clicked.connect(self.reset_peak); numbers.addWidget(reset); layout.addLayout(numbers)
        self.status=QLabel('Monitor mati. Tidak ada audio yang direkam ke file.'); self.status.setWordWrap(True); self.status.setTextFormat(Qt.PlainText); self.status.setObjectName('muted'); layout.addWidget(self.status)
        self.timer=QTimer(self); self.timer.setInterval(50); self.timer.timeout.connect(self.tick)
        self.silence_ticks=0
        self.toggle.setEnabled(False)
        self.status.setText('Klik Cari input untuk memilih sumber audio. Monitor belum aktif.')

    def remember_input(self, *_):
        device = self.inputs.currentData()
        if device is not None:
            settings().setValue('devices/audio', bytes(device.id()).hex())

    def refresh_inputs(self):
        if self.api is None:
            try:
                from PySide6.QtMultimedia import QAudioSource, QMediaDevices, QAudioFormat, QAudio
                self.media=QMediaDevices(self); self.media.audioInputsChanged.connect(self.refresh_inputs)
                self.api=(QAudioSource,QMediaDevices,QAudioFormat,QAudio)
            except (ImportError,OSError,RuntimeError) as exc:
                self.toggle.setEnabled(False)
                self.status.setText(f'Audio belum tersedia: {exc}. Fitur editor tetap dapat digunakan.')
                return
        old=self.inputs.currentData()
        selected_id=bytes(old.id()) if old is not None else None
        try: devices=self.api[1].audioInputs()
        except (RuntimeError,OSError) as exc:
            self.stop(); self.toggle.setEnabled(False); self.status.setText(f'Gagal mencari input audio: {exc}'); return
        ids=[bytes(device.id()) for device in devices]
        if self.source is not None and selected_id not in ids:
            self.stop(); self.status.setText('Input audio terputus. Pilih perangkat lalu mulai lagi.')
        self.inputs.clear()
        for device in devices: self.inputs.addItem(device.description(),device)
        if devices:
            preferred = settings().value('devices/audio', '', type=str)
            if selected_id not in ids:
                selected_id = next((device_id for device_id in ids if device_id.hex() == preferred), None)
            self.inputs.setCurrentIndex(ids.index(selected_id) if selected_id in ids else 0)
        self.toggle.setEnabled(bool(devices))
        if not devices: self.status.setText('Belum ada input audio. Hubungkan audio pedal/interface lalu periksa pengaturan audio sistem.')

    def toggle_monitor(self):
        if self.source is not None: self.stop(); return
        if self.api is None: return
        source_type,_,format_type,audio=self.api
        device=self.inputs.currentData()
        if device is None: return
        try:
            settings().setValue('devices/audio', bytes(device.id()).hex())
            fmt=device.preferredFormat()
            formats={format_type.UInt8:'u8',format_type.Int16:'s16',format_type.Int32:'s32',format_type.Float:'f32'}
            if not fmt.isValid() or fmt.sampleFormat() not in formats or not device.isFormatSupported(fmt):
                raise ValueError('Format input audio tidak didukung')
            self.levels=PCMLevels(formats[fmt.sampleFormat()],fmt.channelCount())
            self.source=source_type(device,fmt,self)
            self.source.stateChanged.connect(self.audio_state)
            # Supply our own destination: the no-argument overload can return
            # no stream even while the backend reports NoError.
            self.stream=AudioInputBuffer(self)
            self.source.start(self.stream)
            error=self.source.error()
            if not same_audio_enum(error,audio.NoError):
                code=getattr(error,'name',str(error))
                raise RuntimeError(
                    f'Input tidak dapat dibuka: {device.description()} · {code} · '
                    f'{fmt.sampleRate()} Hz / {fmt.channelCount()} kanal. '
                    'Periksa input di Pengaturan Sistem → Suara dan layanan PipeWire/PulseAudio. '
                    'Jika aplikasi berjalan dalam sandbox, periksa juga izin mikrofon. '
                    'Kode ini belum memastikan penyebabnya adalah izin.')
            self.reset_peak(); self.silence_ticks=0
            self.toggle.setText('Hentikan'); self.inputs.setEnabled(False); self.refresh.setEnabled(False)
            self.status.setText(f'Mendengarkan {device.description()} · {fmt.sampleRate()} Hz · {fmt.channelCount()} kanal. Tidak merekam file.')
            self.timer.start()
        except (ValueError,RuntimeError,OSError) as exc:
            self.stop(); self.status.setText(str(exc))

    def audio_state(self, state):
        if self.stopping or self.source is None or not self.timer.isActive(): return
        audio=self.api[3]
        if not same_audio_enum(state,audio.StoppedState): return
        error=self.source.error()
        if not same_audio_enum(error,audio.NoError):
            error=getattr(error,'name',str(error))
            self.stop(); self.status.setText(f'Monitor dihentikan: {error}. Periksa input audio lalu mulai lagi.')

    def tick(self):
        if self.stream is None: return
        try:
            raw=self.stream.take()
            if len(raw)>1024*1024: raise ValueError('Buffer audio melampaui batas; monitor dihentikan.')
            self.levels.feed(raw)
            peak,rms,clipped,frames=self.levels.take()
            self.peak_hold=max(self.peak_hold,peak); self.clip_hold |= clipped
            self.render(peak,rms)
            self.silence_ticks = self.silence_ticks+1 if not frames or peak < -90 else 0
            if self.clip_hold: self.status.setText('CLIP terdeteksi pada input. Turunkan level sumber; Reset peak menghapus indikator.')
            elif self.silence_ticks >= 60: self.status.setText('Belum ada sinyal. Genjreng gitar atau periksa input, kabel, mute, dan volume audio sistem.')
            elif frames: self.status.setText('Monitor aktif · peak / RMS per kanal tertinggi · tanpa rekaman file.')
        except (ValueError,RuntimeError,OSError) as exc:
            self.stop(); self.status.setText(str(exc))

    def render(self, peak=-math.inf, rms=-math.inf):
        def number(value): return f'{value:+.1f}' if math.isfinite(value) else '−∞'
        self.reading.setText(f'Peak {number(peak+27)}   RMS {number(rms+27)}   Hold {number(self.peak_hold+27)} dB rel.')
        self.bar.setValue(round((max(-60,min(60,peak+27))+60)*10))
        self.bar.hold = round((max(-60, min(60, self.peak_hold+27))+60)*10) if math.isfinite(self.peak_hold) else None
        self.bar.update()
        self.clip_badge.setVisible(self.clip_hold)
        state = 'clip' if self.clip_hold else 'warning' if peak>-6 else ''
        if self.reading.property('state') != state:
            self.reading.setProperty('state',state)
            self.reading.style().unpolish(self.reading); self.reading.style().polish(self.reading)

    def refresh_theme(self):
        self.reading.style().unpolish(self.reading); self.reading.style().polish(self.reading)
        self.bar._fill_key = None
        self.bar.update()
        self.clip_badge.update()

    def reset_peak(self):
        self.peak_hold=-math.inf; self.clip_hold=False
        self.render()
        self.bar.finish_motion()
        if self.source is not None: self.status.setText('Peak direset. Monitor aktif.')

    def stop(self):
        self.timer.stop(); self.stopping=True
        try:
            source,self.source=self.source,None
            stream,self.stream=self.stream,None
            self.levels=None
            if source is not None:
                source.stop(); source.deleteLater()
            if stream is not None:
                stream.close(); stream.deleteLater()
        finally: self.stopping=False
        self.inputs.setEnabled(True); self.refresh.setEnabled(True); self.toggle.setText('Mulai monitor')
        self.bar.hold = None; self.bar.setValue(0); self.bar.update(); self.clip_badge.hide(); self.status.setText('Monitor mati. Tidak ada audio yang direkam ke file.')
        self.bar.finish_motion()
