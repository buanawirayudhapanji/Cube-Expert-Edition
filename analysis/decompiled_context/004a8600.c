
QDialog * __thiscall
FUN_004a8600(QDialog *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void **ppvVar1;
  QDialog *pQVar2;
  undefined4 *puVar3;
  code *local_24;
  undefined4 local_20;
  code *local_1c;
  undefined4 local_18;
  QDialog *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0052cc3b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = param_1;
  QDialog::QDialog(param_1,param_3,param_4,DAT_00759b24 ^ (int)register0x00000010 - 4U);
  *(undefined ***)(param_1 + 8) = BaseDialog::vftable;
  *(undefined ***)param_1 = DigAmp::vftable;
  *(undefined ***)(param_1 + 8) = DigAmp::vftable;
  *(code **)(param_1 + 0xf064) = shared_null_exref;
  local_8 = 1;
  FUN_004a9350(param_1);
  QWidget::setWindowFlags((QWidget *)param_1,*(uint *)(*(int *)(param_1 + 0x14) + 8) & 0xfffe7fff);
  QWidget::setWindowFlags((QWidget *)param_1,*(uint *)(*(int *)(param_1 + 0x14) + 8) | 0x100);
  *(undefined4 *)(param_1 + 0x34) = param_2;
  ppvVar1 = *(void ***)(param_1 + 0x1c);
  local_1c = clicked_exref;
  local_18 = 0;
  puVar3 = operator_new(0xc);
  *puVar3 = 1;
  puVar3[1] = FUN_004a8f00;
  puVar3[2] = local_14;
  QObject::connectImpl
            ((QObject *)&param_3,ppvVar1,(QObject *)&local_1c,(void **)local_14,
             (QSlotObjectBase *)0x0,(ConnectionType)puVar3,(int *)0x0,(QMetaObject *)0x0);
  QMetaObject::Connection::~Connection((Connection *)&param_3);
  ppvVar1 = *(void ***)(local_14 + 0x28);
  local_1c = itemClicked_exref;
  local_18 = 0;
  puVar3 = operator_new(0xc);
  *puVar3 = 1;
  puVar3[1] = FUN_004a8e90;
  puVar3[2] = local_14;
  QObject::connectImpl
            ((QObject *)&param_3,ppvVar1,(QObject *)&local_1c,(void **)local_14,
             (QSlotObjectBase *)0x0,(ConnectionType)puVar3,(int *)0x0,(QMetaObject *)0x0);
  QMetaObject::Connection::~Connection((Connection *)&param_3);
  local_20 = 0;
  ppvVar1 = *(void ***)(local_14 + 0x2c);
  local_24 = clicked_exref;
  puVar3 = operator_new(0xc);
  pQVar2 = local_14;
  *puVar3 = 1;
  puVar3[1] = FUN_004a8ed0;
  puVar3[2] = local_14;
  QObject::connectImpl
            ((QObject *)&param_3,ppvVar1,(QObject *)&local_24,(void **)local_14,
             (QSlotObjectBase *)0x0,(ConnectionType)puVar3,(int *)0x0,(QMetaObject *)0x0);
  QMetaObject::Connection::~Connection((Connection *)&param_3);
  *(undefined4 *)(pQVar2 + 0x38) = 0x504d41;
  *(undefined4 *)(pQVar2 + 0x3c39) = 0x45544147;
  pQVar2[0x3c3d] = (QDialog)0x0;
  QWidget::hide(*(QWidget **)(pQVar2 + 0x18));
  ExceptionList = local_10;
  return pQVar2;
}


