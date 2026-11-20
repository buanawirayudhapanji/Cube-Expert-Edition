"""Windows file publication with explicit write-through before reporting success."""
import ctypes
from pathlib import Path


def replace_write_through(source, destination, *, replace=True):
    from ctypes import wintypes

    kernel = ctypes.WinDLL('kernel32', use_last_error=True)
    move = kernel.MoveFileExW
    move.argtypes = (wintypes.LPCWSTR, wintypes.LPCWSTR, wintypes.DWORD)
    move.restype = wintypes.BOOL
    flags = 0x8 | (0x1 if replace else 0)  # WRITE_THROUGH; optionally REPLACE_EXISTING.
    if not move(str(Path(source).resolve()), str(Path(destination).resolve()), flags):
        raise ctypes.WinError(ctypes.get_last_error())
