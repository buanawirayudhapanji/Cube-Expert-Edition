
QWidget * __thiscall
FUN_0049dee0(QWidget *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  QWidget *this;
  QString *pQVar1;
  QColor aQStack_42 [2];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0052952e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  QDialog::QDialog();
  *(undefined ***)(param_1 + 8) = BaseDialog::vftable;
  *(undefined ***)param_1 = CCubeBabyJunIREditDlg::vftable;
  *(undefined ***)(param_1 + 8) = CCubeBabyJunIREditDlg::vftable;
  *(code **)(param_1 + 0xfc) = shared_null_exref;
  local_8 = 1;
  param_1[0x100] = (QWidget)0x1;
  FUN_0050a570();
  *(undefined4 *)(param_1 + 300) = 0;
  *(undefined4 *)(param_1 + 0x130) = 0;
  *(undefined4 *)(param_1 + 0x134) = 0;
  *(undefined4 *)(param_1 + 0x138) = 0;
  *(undefined4 *)(param_1 + 0x13c) = 0;
  *(undefined4 *)(param_1 + 0x140) = 0;
  local_8._0_1_ = 4;
  *(undefined4 *)(param_1 + 0x1c0) = 1;
  memset(param_1 + 0x200,0,0xf70);
  FUN_004a0400();
  FUN_0049aa10();
  QWidget::setWindowFlags(param_1);
  QWidget::setWindowFlags(param_1);
  *(undefined4 *)(param_1 + 0xf8) = param_2;
  (**(code **)(**(int **)(param_1 + 0xf4) + 0x2c))();
  FUN_0049f590();
  FUN_0049eea0();
  FUN_0049efd0();
  QColor::QColor(aQStack_42 + -6,0x33,0xea,0xb8,0xff);
  FUN_0050cd30();
  FUN_00519367();
  FUN_005063f0(0);
  FUN_0050cd50();
  QWidget::setAcceptDrops(*(QWidget **)(param_1 + 0x30),false);
  FUN_004894e0();
  QAbstractSlider::setValue(*(QAbstractSlider **)(param_1 + 0x28),0x32);
  this = *(QWidget **)(param_1 + 0x28);
  pQVar1 = (QString *)QString::asprintf((char *)&param_3);
  local_8 = CONCAT31(local_8._1_3_,5);
  QWidget::setToolTip(this,pQVar1);
  QString::~QString((QString *)&param_3);
  ExceptionList = local_10;
  return param_1;
}


