
QWidget * __thiscall
FUN_00490a90(QWidget *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  QWidget *this;
  QString *pQVar1;
  QColor aQStack_3e [2];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005259be;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  QDialog::QDialog();
  *(undefined ***)(param_1 + 8) = BaseDialog::vftable;
  *(undefined ***)param_1 = BabyBassDlg::vftable;
  *(undefined ***)(param_1 + 8) = BabyBassDlg::vftable;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0x1e653c;
  *(undefined4 *)(param_1 + 0x20) = 0xf043207;
  *(undefined4 *)(param_1 + 0x24) = 0x1010132;
  *(undefined4 *)(param_1 + 0x28) = 1;
  *(undefined4 *)(param_1 + 0x2c) = 0x553a3c;
  *(undefined4 *)(param_1 + 0x30) = 0xf023207;
  *(undefined4 *)(param_1 + 0x34) = 0x1010245;
  *(undefined4 *)(param_1 + 0x38) = 1;
  *(undefined4 *)(param_1 + 0x3c) = 0xc1f3c;
  *(undefined4 *)(param_1 + 0x40) = 0xf073205;
  *(undefined4 *)(param_1 + 0x44) = 0x101085e;
  *(undefined4 *)(param_1 + 0x48) = 1;
  *(code **)(param_1 + 300) = shared_null_exref;
  local_8 = 1;
  FUN_0050a570();
  *(undefined4 *)(param_1 + 0x158) = 0;
  *(undefined4 *)(param_1 + 0x15c) = 0;
  *(undefined4 *)(param_1 + 0x160) = 0;
  *(undefined4 *)(param_1 + 0x164) = 0;
  *(undefined4 *)(param_1 + 0x168) = 0;
  *(undefined4 *)(param_1 + 0x16c) = 0;
  local_8._0_1_ = 4;
  *(undefined4 *)(param_1 + 0x1e8) = 1;
  memset(param_1 + 0x228,0,0x988);
  FUN_00493750();
  FUN_004932b0();
  QWidget::setWindowFlags(param_1);
  QWidget::setWindowFlags(param_1);
  *(undefined4 *)(param_1 + 0x128) = param_2;
  FUN_00492440();
  FUN_00491d40();
  FUN_00491e80();
  QColor::QColor(aQStack_3e + -6,0x33,0xea,0xb8,0xff);
  FUN_0050cd30();
  FUN_00519367();
  FUN_005063f0(0);
  FUN_0050cd50();
  QWidget::setAcceptDrops(*(QWidget **)(param_1 + 100),false);
  FUN_004894e0();
  QAbstractSlider::setValue(*(QAbstractSlider **)(param_1 + 0x5c),100);
  this = *(QWidget **)(param_1 + 0x5c);
  pQVar1 = (QString *)QString::asprintf((char *)&param_3);
  local_8 = CONCAT31(local_8._1_3_,5);
  QWidget::setToolTip(this,pQVar1);
  QString::~QString((QString *)&param_3);
  ExceptionList = local_10;
  return param_1;
}


