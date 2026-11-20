
QDialog * __thiscall
FUN_00496770(QDialog *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  QWidget *this;
  QString *pQVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00527282;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  QDialog::QDialog(param_1,param_3,param_4,DAT_00759b24 ^ (int)register0x00000010 - 4U);
  *(undefined ***)(param_1 + 8) = BaseDialog::vftable;
  *(undefined ***)param_1 = CabDlg::vftable;
  *(undefined ***)(param_1 + 8) = CabDlg::vftable;
  *(code **)(param_1 + 0x403c) = shared_null_exref;
  *(undefined4 *)(param_1 + 0x4064) = 0;
  *(undefined4 *)(param_1 + 0x4068) = 0;
  *(undefined4 *)(param_1 + 0x4074) = 0;
  *(undefined4 *)(param_1 + 0x4078) = 0;
  *(undefined4 *)(param_1 + 0x4080) = 0;
  local_8 = 2;
  FUN_00497b50(param_1);
  FUN_00497870();
  QWidget::setWindowFlags((QWidget *)param_1,*(uint *)(*(int *)(param_1 + 0x14) + 8) & 0xfffe7fff);
  QWidget::setWindowFlags((QWidget *)param_1,*(uint *)(*(int *)(param_1 + 0x14) + 8) | 0x100);
  *(undefined4 *)(param_1 + 0x4038) = param_2;
  FUN_00497450();
  QWidget::setAcceptDrops(*(QWidget **)(param_1 + 0x30),false);
  FUN_004894e0(1,100,1);
  QAbstractSlider::setValue(*(QAbstractSlider **)(param_1 + 0x28),0x32);
  this = *(QWidget **)(param_1 + 0x28);
  pQVar1 = (QString *)QString::asprintf((char *)&param_3,&DAT_005842a8,0x32);
  local_8 = CONCAT31(local_8._1_3_,3);
  QWidget::setToolTip(this,pQVar1);
  QString::~QString((QString *)&param_3);
  *(undefined4 *)(param_1 + 0x4084) = 0x10001;
  *(undefined2 *)(param_1 + 0x4094) = 0x12;
  *(undefined4 *)(param_1 + 0x4088) = 0xac44;
  *(undefined4 *)(param_1 + 0x4090) = 0x200004;
  *(undefined4 *)(param_1 + 0x408c) = 0x2b110;
  *(undefined4 *)(param_1 + 0x4034) = 0x424143;
  ExceptionList = local_10;
  return param_1;
}


