
QWidget * __thiscall
FUN_004fad20(QWidget *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  QColor aQStack_3e [2];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00549aee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  QDialog::QDialog();
  *(undefined ***)(param_1 + 8) = BaseDialog::vftable;
  *(undefined ***)param_1 = CSpeakerIREditDlg::vftable;
  *(undefined ***)(param_1 + 8) = CSpeakerIREditDlg::vftable;
  *(code **)(param_1 + 0x120) = shared_null_exref;
  local_8 = 1;
  FUN_0050a570();
  *(undefined4 *)(param_1 + 0x14c) = 0;
  *(undefined4 *)(param_1 + 0x150) = 0;
  *(undefined4 *)(param_1 + 0x154) = 0;
  *(undefined4 *)(param_1 + 0x158) = 0;
  *(undefined4 *)(param_1 + 0x15c) = 0;
  *(undefined4 *)(param_1 + 0x160) = 0;
  local_8._0_1_ = 4;
  *(undefined4 *)(param_1 + 0x200) = 1;
  memset(param_1 + 0x240,0,0xf70);
  FUN_004fd450();
  FUN_0049aa10();
  QWidget::setWindowFlags(param_1);
  QWidget::setWindowFlags(param_1);
  *(undefined4 *)(param_1 + 0x11c) = param_2;
  FUN_004fc410();
  FUN_004fbcc0();
  FUN_004fbe30();
  QColor::QColor(aQStack_3e + -6,0x33,0xea,0xb8,0xff);
  FUN_0050cd30();
  FUN_00519367();
  FUN_005063f0(0);
  FUN_0050cd50();
  QWidget::setAcceptDrops(*(QWidget **)(param_1 + 0x30),false);
  FUN_004894e0();
  QAbstractSlider::setValue(*(QAbstractSlider **)(param_1 + 0x28),0x32);
  QString::QString((QString *)&param_3);
  local_8 = CONCAT31(local_8._1_3_,5);
  QString::asprintf((char *)&param_2);
  QString::~QString((QString *)&param_2);
  QWidget::setToolTip(*(QWidget **)(param_1 + 0x28),(QString *)&param_3);
  QString::~QString((QString *)&param_3);
  ExceptionList = local_10;
  return param_1;
}


