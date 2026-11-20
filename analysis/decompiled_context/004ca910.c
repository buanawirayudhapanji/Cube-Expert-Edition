
QDialog * __thiscall
FUN_004ca910(QDialog *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  QAbstractSlider *this;
  QSpinBox *this_00;
  QDialog *pQVar1;
  QString local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00536d3e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  QDialog::QDialog(param_1,param_3,param_4,DAT_00759b24 ^ (uint)(local_14 + 0x10));
  *(undefined ***)(param_1 + 8) = BaseDialog::vftable;
  *(undefined ***)param_1 = CH8JunIREditDlg::vftable;
  *(undefined ***)(param_1 + 8) = CH8JunIREditDlg::vftable;
  *(code **)(param_1 + 0xcc) = shared_null_exref;
  local_8 = 1;
  FUN_0050a570();
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 0xfc) = 0;
  *(undefined4 *)(param_1 + 0x100) = 0;
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined4 *)(param_1 + 0x10c) = 0;
  local_8 = CONCAT31(local_8._1_3_,4);
  *(undefined4 *)(param_1 + 0x110) = 10;
  *(undefined4 *)(param_1 + 0x18c) = 1;
  memset(param_1 + 500,0,0xf70);
  FUN_004cc5e0(param_1);
  FUN_0049aa10();
  QWidget::setWindowFlags((QWidget *)param_1,*(uint *)(*(int *)(param_1 + 0x14) + 8) & 0xfffe7fff);
  QWidget::setWindowFlags((QWidget *)param_1,*(uint *)(*(int *)(param_1 + 0x14) + 8) | 0x100);
  pQVar1 = param_1 + 0x13c;
  *(undefined4 *)(param_1 + 200) = param_2;
  *(undefined4 *)(param_1 + 0x164) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(param_1 + 0x168) = *(undefined4 *)(param_1 + 0xa4);
  *(undefined4 *)(param_1 + 0x16c) = *(undefined4 *)(param_1 + 0xa8);
  *(undefined4 *)(param_1 + 0x170) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(param_1 + 0x174) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined4 *)(param_1 + 0x178) = *(undefined4 *)(param_1 + 0xb4);
  *(undefined4 *)(param_1 + 0x17c) = *(undefined4 *)(param_1 + 0xb8);
  *(undefined4 *)(param_1 + 0x180) = *(undefined4 *)(param_1 + 0xbc);
  *(undefined4 *)(param_1 + 0x184) = *(undefined4 *)(param_1 + 0xc0);
  *(undefined4 *)(param_1 + 0x188) = *(undefined4 *)(param_1 + 0xc4);
  *(undefined4 *)pQVar1 = *(undefined4 *)(param_1 + 0x70);
  *(undefined4 *)(param_1 + 0x140) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(param_1 + 0x144) = *(undefined4 *)(param_1 + 0x78);
  *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(param_1 + 0x88);
  *(undefined4 *)(param_1 + 0x14c) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(param_1 + 0x150) = *(undefined4 *)(param_1 + 0x90);
  *(undefined4 *)(param_1 + 0x154) = *(undefined4 *)(param_1 + 0x94);
  *(undefined4 *)(param_1 + 0x158) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(param_1 + 0x15c) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(param_1 + 0x160) = *(undefined4 *)(param_1 + 0x4c);
  param_3 = 0;
  if (0 < *(int *)(param_1 + 0x110)) {
    do {
      this = *(QAbstractSlider **)pQVar1;
      this_00 = *(QSpinBox **)(pQVar1 + 0x28);
      QAbstractSlider::setMinimum(this,0);
      QAbstractSlider::setMaximum(this,10);
      QAbstractSlider::setSingleStep(this,1);
      QAbstractSlider::setPageStep(this,1);
      QSpinBox::setMinimum(this_00,0);
      QSpinBox::setMaximum(this_00,10);
      QSpinBox::setSingleStep(this_00,1);
      pQVar1 = pQVar1 + 4;
      param_3 = param_3 + 1;
    } while (param_3 < *(int *)(param_1 + 0x110));
  }
  FUN_004cb8b0();
  FUN_004cb980();
  QWidget::setAcceptDrops(*(QWidget **)(param_1 + 0x30),false);
  FUN_004894e0(1,100,1);
  QAbstractSlider::setValue(*(QAbstractSlider **)(param_1 + 0x28),0x32);
  QString::QString(local_14);
  local_8 = CONCAT31(local_8._1_3_,5);
  QString::asprintf((char *)&param_3,&DAT_005842a8,0x32);
  QString::~QString((QString *)&param_3);
  QWidget::setToolTip(*(QWidget **)(param_1 + 0x28),local_14);
  QString::~QString(local_14);
  ExceptionList = local_10;
  return param_1;
}


