
QWidget * __thiscall
FUN_00498590(QWidget *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  QWidget *this;
  QString *pQVar1;
  QColor aQStack_3e [2];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0052818e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  QDialog::QDialog();
  *(undefined ***)(param_1 + 8) = BaseDialog::vftable;
  *(undefined ***)param_1 = CCubeBabyCAIREditDlg::vftable;
  *(undefined ***)(param_1 + 8) = CCubeBabyCAIREditDlg::vftable;
  *(code **)(param_1 + 0xf8) = shared_null_exref;
  local_8 = 1;
  FUN_0050a570();
  *(undefined4 *)(param_1 + 0x124) = 0;
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  *(undefined4 *)(param_1 + 0x130) = 0;
  *(undefined4 *)(param_1 + 0x134) = 0;
  *(undefined4 *)(param_1 + 0x138) = 0;
  local_8._0_1_ = 4;
  *(undefined4 *)(param_1 + 0x1b4) = 1;
  memset(param_1 + 500,0,0x98c);
  FUN_0049aec0();
  FUN_0049aa10();
  QWidget::setWindowFlags(param_1);
  QWidget::setWindowFlags(param_1);
  *(undefined4 *)(param_1 + 0xf4) = param_2;
  FUN_00499bd0();
  FUN_004994e0();
  FUN_00499610();
  QColor::QColor(aQStack_3e + -6,0x33,0xea,0xb8,0xff);
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


