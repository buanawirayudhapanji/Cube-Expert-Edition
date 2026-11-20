"""Single source of UI colors. Alpha colors are RGBA tuples, never web CSS."""

DARK = {
    'bg_base': '#0B0A07', 'bg_glow_1': (255,214,10,.18),
    'bg_glow_2': (255,159,28,.12), 'bg_glow_3': (255,255,255,.04),
    'glass_1': (255,248,225,.04), 'glass_2': (255,248,225,.07),
    'glass_3': (28,24,14,.80), 'glass_border': (255,236,160,.20),
    'glass_highlight': (255,255,255,.15),
    'text_primary': '#F6F1E3', 'text_secondary': '#F1E8D5', 'text_disabled': '#D0C4A8',
    'accent': '#FFD60A', 'accent_hover': '#FFE24D', 'accent_press': '#E6B800',
    'accent_soft': (255,214,10,.16), 'accent_text': '#FFF2AC', 'on_accent': '#14110A',
    'focus_ring': '#FFD60A', 'success': '#3DDC84', 'success_text': '#D9FFE7',
    'warning': '#FF9F1C', 'warning_text': '#FFF0D7',
    'danger': '#FF5A4F', 'danger_text': '#FFE1DC', 'on_danger': '#14110A',
    'info': '#5EC8E5', 'info_text': '#D9F7FF', 'shadow': (0,0,0,.45),
    'control': '#242016', 'control_hover': '#342D1C', 'control_disabled': '#242219',
    'surface_solid_1': '#17150F', 'surface_solid_2': '#201C13', 'surface_solid_3': '#242015',
    'meter_track': '#27251D', 'meter_marker': '#FFFCEF', 'meter_marker_outline': '#14110A', 'wave_grid': '#4A4434',
    'transparent': (0,0,0,0),
}
LIGHT = {
    'bg_base': '#FBF6E6', 'bg_glow_1': (255,199,0,.35),
    'bg_glow_2': (255,159,28,.20), 'bg_glow_3': (255,255,255,.80),
    'glass_1': (255,255,255,.45), 'glass_2': (255,255,255,.62),
    'glass_3': (255,252,240,.88), 'glass_border': (60,45,0,.20),
    'glass_highlight': (255,255,255,.90),
    'text_primary': '#1A1608', 'text_secondary': '#5C5333', 'text_disabled': '#766B50',
    'accent': '#FFC700', 'accent_hover': '#FFD633', 'accent_press': '#E0AD00',
    'accent_soft': (255,199,0,.24), 'accent_text': '#705000', 'on_accent': '#1A1608',
    'focus_ring': '#1A1608', 'success': '#1B7F4B', 'success_text': '#17643B',
    'warning': '#B85C00', 'warning_text': '#914800',
    'danger': '#C62828', 'danger_text': '#A12020', 'on_danger': '#FFFFFF',
    'info': '#0B6B8A', 'info_text': '#085570', 'shadow': (90,65,0,.14),
    'control': '#FFFBEF', 'control_hover': '#F4E9C8', 'control_disabled': '#E9E2CE',
    'surface_solid_1': '#F5EFDC', 'surface_solid_2': '#FFFBEE', 'surface_solid_3': '#FFFCEF',
    'meter_track': '#E0D7BB', 'meter_marker': '#1A1608', 'meter_marker_outline': '#FFFBEE', 'wave_grid': '#BFB38E',
    'transparent': (0,0,0,0),
}
THEMES = {'dark': DARK, 'light': LIGHT}
_active = 'dark'


def set_active_theme(name):
    global _active
    _active = name if name in THEMES else 'dark'


def palette(light=None):
    return THEMES[('light' if light else 'dark') if light is not None else _active]


def rgba(value):
    if isinstance(value, tuple):
        return value
    return tuple(int(value[index:index+2],16) for index in (1,3,5)) + (1.0,)


def composite(foreground, background):
    r,g,b,a = rgba(foreground)
    br,bg,bb,_ = rgba(background)
    return (r*a+br*(1-a), g*a+bg*(1-a), b*a+bb*(1-a), 1.0)


def luminance(value):
    def linear(channel):
        channel /= 255
        return channel / 12.92 if channel <= .04045 else ((channel+.055)/1.055)**2.4
    return sum(weight*linear(channel) for weight,channel in zip((.2126,.7152,.0722), rgba(value)[:3]))


def contrast(first, second):
    a,b = sorted((luminance(first),luminance(second)))
    return (b+.05)/(a+.05)


def css(name, light=None):
    value = palette(light)[name]
    if isinstance(value, tuple):
        r,g,b,a = value
        return f'rgba({r}, {g}, {b}, {round(a*255)})'
    return value


def qc(name, light=None):
    from PySide6.QtGui import QColor
    value = palette(light)[name]
    return QColor.fromRgbF(*(channel/255 for channel in value[:3]), value[3]) if isinstance(value,tuple) else QColor(value)


def effective_backgrounds(theme):
    """Conservative: every combination of maximum blob opacities and glass layers."""
    p = THEMES[theme]
    ambients = []
    for mask in range(8):
        bg = rgba(p['bg_base'])
        for index in range(3):
            if mask & (1 << index):
                bg = composite(p[f'bg_glow_{index+1}'], bg)
        ambients.append(bg)
    result = list(ambients)
    for bg in ambients:
        for first in ('glass_1','glass_2','glass_3'):
            surface = composite(p[first],bg)
            result.append(surface)
            for second in ('glass_1','glass_2','glass_3','accent_soft'):
                result.append(composite(p[second],surface))
    result.extend(rgba(p[key]) for key in ('control','control_hover','control_disabled',
                                           'surface_solid_1','surface_solid_2','surface_solid_3'))
    return result


def contrast_report():
    rows = []
    for theme,p in THEMES.items():
        backgrounds = effective_backgrounds(theme)
        for token in ('text_primary','text_secondary','text_disabled','accent_text',
                      'success_text','warning_text','danger_text','info_text','focus_ring'):
            rows.append({'theme':theme,'pair':f'{token} / permukaan efektif terburuk',
                         'ratio':min(contrast(p[token],bg) for bg in backgrounds),
                         'minimum':3.0 if token in ('text_disabled','focus_ring') else 4.5})
        for fill in ('accent','accent_hover','accent_press'):
            rows.append({'theme':theme,'pair':f'on_accent / {fill}',
                         'ratio':contrast(p['on_accent'],p[fill]),'minimum':4.5})
        rows.append({'theme':theme,'pair':'on_danger / danger',
                     'ratio':contrast(p['on_danger'],p['danger']),'minimum':4.5})
        rows.append({'theme':theme,'pair':'meter_marker / outline',
                     'ratio':contrast(p['meter_marker'],p['meter_marker_outline']),'minimum':3.0})
    return rows
