
void __thiscall FUN_00483fd0(QWidget *param_1,int param_2)

{
  bool bVar1;
  char cVar2;
  bool bVar3;
  int *piVar4;
  QWidget *this;
  
  FUN_00485d60();
  if (*(int *)(*(int *)(param_1 + 0x2c) + 0xc844) != 3) {
    cVar2 = FUN_005069b0();
    if (cVar2 != '\0') {
      bVar3 = true;
      goto LAB_00483ffb;
    }
  }
  bVar3 = false;
LAB_00483ffb:
  piVar4 = (int *)FUN_00488eb0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x2ca68));
  if (((piVar4 == (int *)0x0) || (*piVar4 == -1)) || (piVar4[0xf] == 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((!bVar3) || (bVar1)) {
    QWidget::setEnabled(*(QWidget **)(param_1 + 0x24),false);
    if ((!bVar3) || (bVar1)) {
      QWidget::setEnabled(*(QWidget **)(param_1 + 0x1c),false);
      this = *(QWidget **)(param_1 + 0x20);
      if ((!bVar3) || (bVar1)) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
    }
    else {
      QWidget::setEnabled(*(QWidget **)(param_1 + 0x1c),true);
      this = *(QWidget **)(param_1 + 0x20);
      bVar3 = true;
    }
  }
  else {
    QWidget::setEnabled(*(QWidget **)(param_1 + 0x24),true);
    QWidget::setEnabled(*(QWidget **)(param_1 + 0x1c),true);
    this = *(QWidget **)(param_1 + 0x20);
    bVar3 = true;
  }
  QWidget::setEnabled(this,bVar3);
  if (param_2 == 0) {
    QWidget::close(param_1);
    return;
  }
  cVar2 = FUN_005069b0();
  if (cVar2 == '\0') {
    FUN_005071b0(1);
    thunk_FUN_00508160();
    return;
  }
  FUN_00484ad0();
  return;
}


