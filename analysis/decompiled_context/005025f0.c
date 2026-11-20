
void __thiscall FUN_005025f0(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  bool local_8;
  
  FUN_00505d00();
  iVar2 = *(int *)(*(int *)(param_1 + 0x4c) + 0xc844);
  cVar1 = FUN_005069b0();
  if ((iVar2 == 3) || (local_8 = true, cVar1 == '\0')) {
    local_8 = false;
  }
  QWidget::setEnabled(*(QWidget **)(param_1 + 0x48),local_8);
  iVar2 = QComboBox::count(*(QComboBox **)(param_1 + 0x2c));
  if (iVar2 == 0) {
    FUN_005035c0();
  }
  if (param_2 == 0) {
    QWidget::hide(*(QWidget **)(param_1 + 0x3c));
    QWidget::hide(*(QWidget **)(param_1 + 0x40));
  }
  else {
    cVar1 = FUN_005069b0();
    if (cVar1 == '\0') {
      FUN_005071b0(1);
      thunk_FUN_00508160();
    }
    if ((*(char *)(param_1 + 0x104) != '\0') && (*(char *)(param_1 + 0x105) != '\0')) {
      cVar1 = FUN_005069b0();
      if (cVar1 != '\0') {
        *(undefined4 *)(param_1 + 0x108) = 1;
      }
    }
  }
  cVar1 = FUN_005069b0();
  if (cVar1 != '\0') {
    if (*(int *)(*(int *)(param_1 + 0x4c) + 0x2ca68) == 0x1fff0) {
      FUN_00505b60();
    }
  }
  return;
}


