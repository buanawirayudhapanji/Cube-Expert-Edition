"""Verify token contrast against conservative ambient/glass composites."""
import sys
from pathlib import Path
sys.path.insert(0,str(Path(__file__).resolve().parent.parent))
from cubebaby_mod.theme_tokens import contrast_report


def report():
    rows = contrast_report()
    text = ['# Kontras tema kuning–hitam', '',
            'Latar efektif: seluruh kombinasi puncak tiga glow, satu/dua lapisan kaca,',
            'seleksi accent-soft dan permukaan solid. Alpha dihitung sebelum luminansi WCAG.',
            'Dua lapisan adalah batas maksimum; marker memakai outline kontras.', '',
            '| Tema | Pasangan | Rasio terburuk | Minimum | Hasil |',
            '| --- | --- | ---: | ---: | --- |']
    for row in rows:
        passed = row['ratio'] >= row['minimum']
        text.append(f"| {row['theme']} | {row['pair']} | {row['ratio']:.2f}:1 | {row['minimum']}:1 | {'Lulus' if passed else 'Gagal'} |")
    return '\n'.join(text)+'\n', all(row['ratio'] >= row['minimum'] for row in rows)


if __name__ == '__main__':
    text, passed = report()
    if len(sys.argv)>1:
        Path(sys.argv[1]).write_text(text)
    else:
        print(text)
    raise SystemExit(0 if passed else 1)
