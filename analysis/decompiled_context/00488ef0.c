
QDial * __thiscall FUN_00488ef0(QDial *param_1,QWidget *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00521a0e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  QDial::QDial(param_1,param_2);
  local_8 = 0;
  *(undefined ***)param_1 = QParamDail::vftable;
  *(undefined ***)(param_1 + 8) = QParamDail::vftable;
  QPixmap::QPixmap((QPixmap *)(param_1 + 0x18));
  ExceptionList = local_10;
  return param_1;
}


