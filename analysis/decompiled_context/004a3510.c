
QDialog * __thiscall
FUN_004a3510(QDialog *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  QWidget *this;
  QString *pQVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0052ab05;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  QDialog::QDialog(param_1,param_3,param_4,DAT_00759b24 ^ (int)register0x00000010 - 4U);
  *(undefined ***)(param_1 + 8) = BaseDialog::vftable;
  *(undefined ***)param_1 = CCubeBabyIREditDlg::vftable;
  *(undefined ***)(param_1 + 8) = CCubeBabyIREditDlg::vftable;
  *(code **)(param_1 + 0x48) = shared_null_exref;
  local_8 = 1;
  FUN_0050a570();
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  local_8._0_1_ = 4;
  memset(param_1 + 0x8c,0,0xf70);
  FUN_004a4cc0(param_1);
  FUN_004a4910();
  QWidget::setWindowFlags((QWidget *)param_1,*(uint *)(*(int *)(param_1 + 0x14) + 8) & 0xfffe7fff);
  QWidget::setWindowFlags((QWidget *)param_1,*(uint *)(*(int *)(param_1 + 0x14) + 8) | 0x100);
  *(undefined4 *)(param_1 + 0x44) = param_2;
  FUN_004a42c0();
  QWidget::setAcceptDrops(*(QWidget **)(param_1 + 0x30),false);
  FUN_004894e0(1,100,1);
  QAbstractSlider::setValue(*(QAbstractSlider **)(param_1 + 0x28),0x32);
  this = *(QWidget **)(param_1 + 0x28);
  pQVar1 = (QString *)QString::asprintf((char *)&param_3,&DAT_005842a8,0x32);
  local_8 = CONCAT31(local_8._1_3_,5);
  QWidget::setToolTip(this,pQVar1);
  QString::~QString((QString *)&param_3);
  ExceptionList = local_10;
  return param_1;
}


