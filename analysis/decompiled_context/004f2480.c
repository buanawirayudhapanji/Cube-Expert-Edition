
void __thiscall FUN_004f2480(int param_1,QColor param_2)

{
  byte bVar1;
  int iVar2;
  QWidget *this;
  int iVar3;
  char cVar4;
  void **ppvVar5;
  QString *pQVar6;
  uint uVar7;
  QChar aQStack_4a [2];
  QString local_3c [4];
  QString local_38 [4];
  QString local_34 [8];
  int local_2c;
  QTypedArrayData<unsigned_short> *local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005457e2;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = param_1;
  QObject::blockSignals(*(QObject **)(param_1 + 0x134c),true);
  bVar1 = *(byte *)(param_1 + 0x18);
  if ((-(uint)(bVar1 != 0) & (uint)bVar1) < 7) {
    uVar7 = -(uint)(bVar1 != 0) & (uint)bVar1;
  }
  else {
    uVar7 = 7;
  }
  QColor::getRgb(&param_2,&local_1c,&local_20,&local_24,(int *)0x0);
  local_2c = uVar7 * 0x1da;
  *(undefined1 *)(local_2c + *(int *)(param_1 + 0xf38) * 8 + 0x181 + param_1) = (undefined1)local_1c
  ;
  *(undefined1 *)(local_2c + *(int *)(param_1 + 0xf38) * 8 + 0x182 + param_1) = (undefined1)local_20
  ;
  *(undefined1 *)(local_2c + *(int *)(param_1 + 0xf38) * 8 + 0x183 + param_1) = (undefined1)local_24
  ;
  iVar2 = *(int *)(param_1 + 0xf38);
  if ((**(int **)(param_1 + 0x1354) != 1) && (**(int **)(param_1 + 0x1354) != 0)) {
    FUN_004f2bd0();
  }
  ppvVar5 = QListData::at((QListData *)(param_1 + 0x1354),iVar2);
  this = *(QWidget **)((int)*ppvVar5 + 0x30);
  local_28 = QString::fromAscii_helper("QPushButton{background-color:rgb(%1,%2,%3)}",0x2b);
  local_14 = CONCAT31(local_14._1_3_,0x20);
  local_8 = 0;
  QChar::QChar(aQStack_4a + -6,local_14);
  pQVar6 = (QString *)QString::arg((QString *)&local_28,local_3c,local_1c,0,10);
  local_14 = CONCAT31(local_14._1_3_,0x20);
  local_8._0_1_ = 1;
  QChar::QChar(aQStack_4a + -6,local_14);
  pQVar6 = (QString *)QString::arg(pQVar6,local_38,local_20,0,10);
  local_14 = CONCAT31(local_14._1_3_,0x20);
  local_8._0_1_ = 2;
  QChar::QChar(aQStack_4a + -6,local_14);
  pQVar6 = (QString *)QString::arg(pQVar6,local_34,local_24,0,10);
  local_8 = CONCAT31(local_8._1_3_,3);
  QWidget::setStyleSheet(this,pQVar6);
  QString::~QString(local_34);
  QString::~QString(local_38);
  QString::~QString(local_3c);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_28);
  iVar3 = local_18;
  iVar2 = local_2c + *(int *)(local_18 + 0xf38) * 8;
  cVar4 = FUN_00506590(5,iVar2 + 0x155,local_18 + 0x181 + iVar2,3);
  if (cVar4 == '\0') {
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7c3c,(char *)&local_18,"Write data failed !",0);
    local_8 = 4;
    FUN_00486bb0();
    QString::~QString((QString *)&local_18);
  }
  QObject::blockSignals(*(QObject **)(iVar3 + 0x134c),false);
  ExceptionList = local_10;
  return;
}


