
void __fastcall FUN_004a02e0(int param_1)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  
  _setChecked_QAbstractButton__QAEX_N_Z(**(char **)(param_1 + 500) != '\0');
  _setChecked_QAbstractButton__QAEX_N_Z(**(char **)(param_1 + 0x1f8) != '\0');
  _setChecked_QAbstractButton__QAEX_N_Z(**(char **)(param_1 + 0x1fc) != '\0');
  uVar3 = 0;
  iVar2 = param_1 + 0x170;
  do {
    _setValue_QAbstractSlider__QAEXH_Z(**(undefined1 **)(iVar2 + -0x28));
    _setValue_QSpinBox__QAEXH_Z(**(undefined1 **)(iVar2 + -0x28));
    if (uVar3 != 0) {
      if (uVar3 < 3) {
        _setEnabled_QWidget__QAEX_N_Z(**(char **)(param_1 + 0x1fc) != '\0');
        pcVar1 = *(char **)(param_1 + 0x1fc);
      }
      else if (uVar3 < 7) {
        _setEnabled_QWidget__QAEX_N_Z(**(char **)(param_1 + 0x1f8) != '\0');
        pcVar1 = *(char **)(param_1 + 0x1f8);
      }
      else {
        if (9 < uVar3) goto LAB_004a03e7;
        _setEnabled_QWidget__QAEX_N_Z(**(char **)(param_1 + 500) != '\0');
        pcVar1 = *(char **)(param_1 + 500);
      }
      _setEnabled_QWidget__QAEX_N_Z(*pcVar1 != '\0');
    }
LAB_004a03e7:
    uVar3 = uVar3 + 1;
    iVar2 = iVar2 + 4;
    if (9 < (int)uVar3) {
      return;
    }
  } while( true );
}


