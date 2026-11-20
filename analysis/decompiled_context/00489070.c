
void __thiscall FUN_00489070(QAbstractSlider *param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  QMessageLogger *this;
  QMessageLogger local_18 [20];
  
  pcVar1 = (char *)QMessageLogger::QMessageLogger(local_18,(char *)0x0,0,(char *)0x0);
  QMessageLogger::debug(this,pcVar1,"QParamDail::mousePressEvent");
  iVar2 = QAbstractSlider::minimum(param_1);
  iVar3 = QAbstractSlider::maximum(param_1);
  if (((iVar3 == iVar2) || (*(int *)(param_2 + 0x48) != 1)) || (*(int *)(param_2 + 0x4c) != 1)) {
    *(ushort *)(param_2 + 10) = *(ushort *)(param_2 + 10) & 0xfffb;
    return;
  }
  *(ushort *)(param_2 + 10) = *(ushort *)(param_2 + 10) | 4;
  QAbstractSlider::setSliderDown(param_1,true);
  return;
}


