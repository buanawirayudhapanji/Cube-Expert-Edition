
QWidget * __thiscall
FUN_004d9410(QWidget *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void **ppvVar1;
  QWidget *pQVar2;
  QArrayData *pQVar3;
  QTypedArrayData<unsigned_short> *pQVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  code *local_24;
  undefined4 local_20;
  code *local_1c;
  undefined4 local_18;
  QWidget *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0053b885;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = param_1;
  QDialog::QDialog((QDialog *)param_1,param_3,param_4,DAT_00759b24 ^ (int)register0x00000010 - 4U);
  *(undefined ***)(param_1 + 8) = BaseDialog::vftable;
  local_8 = 0;
  *(undefined ***)param_1 = EditDrum::vftable;
  *(undefined ***)(param_1 + 8) = EditDrum::vftable;
  *(undefined4 *)(param_1 + 0x18) = 0x200;
  *(undefined4 *)(param_1 + 0x1c) = 0x20;
  *(undefined4 *)(param_1 + 0x20) = 0x10;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x42c) = 0x28;
  *(undefined4 *)(param_1 + 0x430) = 0;
  param_1[0x434] = (QWidget)0x0;
  pQVar3 = QArrayData::sharedNull();
  *(QArrayData **)(param_1 + 0x438) = pQVar3;
  local_8._0_1_ = 1;
  pQVar4 = QString::fromAscii_helper("Crash 01",8);
  *(QTypedArrayData<unsigned_short> **)(param_1 + 0x43c) = pQVar4;
  local_8._0_1_ = 2;
  pQVar4 = QString::fromAscii_helper("Crash 02",8);
  *(QTypedArrayData<unsigned_short> **)(param_1 + 0x440) = pQVar4;
  local_8._0_1_ = 3;
  pQVar4 = QString::fromAscii_helper("Ride 01",7);
  *(QTypedArrayData<unsigned_short> **)(param_1 + 0x444) = pQVar4;
  local_8._0_1_ = 4;
  pQVar4 = QString::fromAscii_helper("Ride 02",7);
  *(QTypedArrayData<unsigned_short> **)(param_1 + 0x448) = pQVar4;
  local_8._0_1_ = 5;
  pQVar4 = QString::fromAscii_helper("Hihat open",10);
  *(QTypedArrayData<unsigned_short> **)(param_1 + 0x44c) = pQVar4;
  local_8._0_1_ = 6;
  pQVar4 = QString::fromAscii_helper("Hihat 01",8);
  *(QTypedArrayData<unsigned_short> **)(param_1 + 0x450) = pQVar4;
  local_8._0_1_ = 7;
  pQVar4 = QString::fromAscii_helper("Hihat 02",8);
  *(QTypedArrayData<unsigned_short> **)(param_1 + 0x454) = pQVar4;
  local_8._0_1_ = 8;
  pQVar4 = QString::fromAscii_helper("Snare 01",8);
  *(QTypedArrayData<unsigned_short> **)(param_1 + 0x458) = pQVar4;
  local_8._0_1_ = 9;
  pQVar4 = QString::fromAscii_helper("Snare 02",8);
  *(QTypedArrayData<unsigned_short> **)(param_1 + 0x45c) = pQVar4;
  local_8._0_1_ = 10;
  pQVar4 = QString::fromAscii_helper("Snare 03",8);
  *(QTypedArrayData<unsigned_short> **)(param_1 + 0x460) = pQVar4;
  local_8._0_1_ = 0xb;
  pQVar4 = QString::fromAscii_helper("Snare Side",10);
  *(QTypedArrayData<unsigned_short> **)(param_1 + 0x464) = pQVar4;
  local_8._0_1_ = 0xc;
  pQVar4 = QString::fromAscii_helper("Tom 01",6);
  *(QTypedArrayData<unsigned_short> **)(param_1 + 0x468) = pQVar4;
  local_8._0_1_ = 0xd;
  pQVar4 = QString::fromAscii_helper("Tom 02",6);
  *(QTypedArrayData<unsigned_short> **)(param_1 + 0x46c) = pQVar4;
  local_8._0_1_ = 0xe;
  pQVar4 = QString::fromAscii_helper("Tom 03",6);
  *(QTypedArrayData<unsigned_short> **)(param_1 + 0x470) = pQVar4;
  local_8._0_1_ = 0xf;
  pQVar4 = QString::fromAscii_helper("Kick 01",7);
  *(QTypedArrayData<unsigned_short> **)(param_1 + 0x474) = pQVar4;
  local_8._0_1_ = 0x10;
  pQVar4 = QString::fromAscii_helper("Kick 02",7);
  *(QTypedArrayData<unsigned_short> **)(param_1 + 0x478) = pQVar4;
  local_8 = CONCAT31(local_8._1_3_,0x11);
  QColor::QColor((QColor *)(param_1 + 0x47c),0xb,0xf4,0xf4,0xff);
  QColor::QColor((QColor *)(param_1 + 0x48c),0xf4,0xf4,2,0xff);
  FUN_004da270(param_1);
  QWidget::setWindowFlags(param_1,*(uint *)(*(int *)(param_1 + 0x14) + 8) & 0xffff7fff);
  iVar5 = QWidget::height(param_1);
  iVar6 = QWidget::width(param_1);
  QWidget::setFixedSize(param_1,iVar6,iVar5);
  *(undefined4 *)(param_1 + 0x4b8) = param_2;
  FUN_004d9b30();
  ppvVar1 = *(void ***)(param_1 + 0x4a4);
  local_1c = currentIndexChanged_exref;
  local_18 = 0;
  puVar7 = operator_new(0xc);
  *puVar7 = 1;
  puVar7[1] = FUN_004d9ab0;
  puVar7[2] = local_14;
  QObject::connectImpl
            ((QObject *)&param_3,ppvVar1,(QObject *)&local_1c,(void **)local_14,
             (QSlotObjectBase *)0x0,(ConnectionType)puVar7,(int *)0x0,(QMetaObject *)0x0);
  QMetaObject::Connection::~Connection((Connection *)&param_3);
  local_18 = 0;
  ppvVar1 = *(void ***)(local_14 + 0x4a8);
  local_1c = currentIndexChanged_exref;
  puVar7 = operator_new(0xc);
  *puVar7 = 1;
  puVar7[1] = FUN_004d99f0;
  puVar7[2] = local_14;
  QObject::connectImpl
            ((QObject *)&param_3,ppvVar1,(QObject *)&local_1c,(void **)local_14,
             (QSlotObjectBase *)0x0,(ConnectionType)puVar7,(int *)0x0,(QMetaObject *)0x0);
  QMetaObject::Connection::~Connection((Connection *)&param_3);
  ppvVar1 = *(void ***)(local_14 + 0x4ac);
  local_24 = clicked_exref;
  local_20 = 0;
  puVar7 = operator_new(0xc);
  pQVar2 = local_14;
  *puVar7 = 1;
  puVar7[1] = FUN_004d9960;
  puVar7[2] = local_14;
  QObject::connectImpl
            ((QObject *)&param_3,ppvVar1,(QObject *)&local_24,(void **)local_14,
             (QSlotObjectBase *)0x0,(ConnectionType)puVar7,(int *)0x0,(QMetaObject *)0x0);
  QMetaObject::Connection::~Connection((Connection *)&param_3);
  FUN_005063f0(6,0,pQVar2 + 0x28,0x200,0);
  *(undefined4 *)(pQVar2 + 0x24) = 0;
  FUN_005063f0(6,*(undefined4 *)(pQVar2 + 0x18),pQVar2 + 0x228,0x200,0);
  FUN_004dac10();
  QScrollArea::setWidgetResizable(*(QScrollArea **)(pQVar2 + 0x49c),true);
  ExceptionList = local_10;
  return pQVar2;
}


