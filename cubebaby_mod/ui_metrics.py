"""Material-inspired type roles and a 4 px spacing grid for Qt logical pixels."""
from PySide6.QtGui import QFont

SPACE = (4, 8, 12, 16, 24, 32)
RADII = (8, 12, 16)
TYPE = {
    'pageTitle': (28, 700),
    'cardTitle': (16, 700),
    'fieldLabel': (14, 500),
    'body': (14, 400),
    'subtitle': (14, 400),
    'muted': (12, 400),
    'statusText': (12, 400),
    'eyebrow': (12, 500),
    'badge': (12, 500),
    'brand': (20, 700),
    'logo': (20, 700),
    'button': (14, 500),
}


def type_font(role, base=None):
    font = QFont(base) if base is not None else QFont()
    size, weight = TYPE[role]
    font.setPixelSize(size)
    font.setWeight(QFont.Weight(weight))
    return font


def type_stylesheet():
    return '\n'.join(
        f'QLabel#{role} {{ font-size:{size}px; font-weight:{weight}; }}'
        for role, (size, weight) in TYPE.items() if role != 'button'
    )
