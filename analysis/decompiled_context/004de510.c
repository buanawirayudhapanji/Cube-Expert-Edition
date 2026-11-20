
QDialog * __thiscall FUN_004de510(QDialog *param_1,void *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0053e29b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  QDialog::QDialog(param_1,param_2,param_3,DAT_00759b24 ^ (int)register0x00000010 - 4U);
  *(undefined ***)param_1 = CMainDialog::vftable;
  *(undefined ***)(param_1 + 8) = CMainDialog::vftable;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  local_8 = 1;
  *(undefined4 *)(param_1 + 0x50) = 0;
  FUN_004e04b0(param_1);
  FUN_004dff60();
  param_2 = operator_new(0x2caa8);
  local_8._0_1_ = 2;
  uVar1 = FUN_00505fb0();
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  local_8 = CONCAT31(local_8._1_3_,1);
  QWidget::setWindowFlags((QWidget *)param_1,*(uint *)(*(int *)(param_1 + 0x14) + 8) & 0xffff7fff);
  QWidget::setWindowFlags((QWidget *)param_1,*(uint *)(*(int *)(param_1 + 0x14) + 8) | 0x4100);
  QWidget::hide(*(QWidget **)(param_1 + 0x20));
  QObject::connect((QObject *)&param_2,*(char **)(param_1 + 0x18),
                   (QObject *)"2itemClicked(QListWidgetItem*)",(char *)param_1,0x58f2c4);
  QMetaObject::Connection::~Connection((Connection *)&param_2);
  FUN_004e1420();
  FUN_004e0d10();
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x2c))(*(int *)(*(int *)(param_1 + 0x28) + 0xc844) == 3)
  ;
  FUN_004e01a0();
  ExceptionList = local_10;
  return param_1;
}


