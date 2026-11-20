
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_004d41e0(int param_1)

{
  QString *pQVar1;
  undefined4 uVar2;
  QIcon *pQVar3;
  int iVar4;
  undefined4 *puVar5;
  QChar aQStack_7e [10];
  QVariant local_6c [20];
  QString local_58 [4];
  QString local_54 [4];
  QString local_50 [4];
  QString local_4c [4];
  QIcon local_48 [4];
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  undefined4 *local_38;
  QTypedArrayData<unsigned_short> *local_34;
  QComboBox *local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined1 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0053ac74;
  local_10 = ExceptionList;
  local_14 = DAT_00759b24 ^ (uint)(local_48 + 0x44);
  ExceptionList = &local_10;
  local_3c = param_1;
  FUN_005063f0(5,0);
  puVar5 = (undefined4 *)(param_1 + 0x1ee2);
  local_38 = puVar5;
  FUN_005063f0(5,0x80000000);
  QComboBox::clear(*(QComboBox **)(param_1 + 0x13c));
  FUN_0050cd50();
  FUN_0050cd50();
  local_40 = CONCAT31(local_40._1_3_,0x20);
  local_2c = 0;
  local_44 = CONCAT31(local_44._1_3_,0x20);
  do {
    local_18 = *(undefined1 *)(puVar5 + 4);
    local_28 = *puVar5;
    uStack_24 = puVar5[1];
    uStack_20 = puVar5[2];
    uStack_1c = puVar5[3];
    local_30 = *(QComboBox **)(param_1 + 0x13c);
    QVariant::QVariant(local_6c,local_2c);
    local_8 = 0;
    local_34 = QString::fromAscii_helper("(%1) - %2",9);
    local_8._0_1_ = 1;
    iVar4 = local_2c + 1;
    local_2c = iVar4;
    QChar::QChar(aQStack_7e + -6,local_40);
    pQVar1 = (QString *)QString::arg((QString *)&local_34,local_58,iVar4,0,10);
    QString::QString(local_54);
    local_8._0_1_ = 3;
    uVar2 = QString::fromUtf8((char *)local_50,(int)&local_28);
    local_8._0_1_ = 4;
    QChar::QChar(aQStack_7e + -6,local_44);
    pQVar1 = (QString *)QString::arg(pQVar1,local_4c,uVar2,0);
    local_8._0_1_ = 5;
    iVar4 = QComboBox::count(local_30);
    pQVar3 = (QIcon *)QIcon::QIcon(local_48);
    local_8 = CONCAT31(local_8._1_3_,6);
    QComboBox::insertItem(local_30,iVar4,pQVar3,pQVar1,local_6c);
    QIcon::~QIcon(local_48);
    QString::~QString(local_4c);
    QString::~QString(local_50);
    QString::~QString(local_54);
    QString::~QString(local_58);
    QString::~QString((QString *)&local_34);
    local_8 = 0xffffffff;
    QVariant::~QVariant(local_6c);
    puVar5 = (undefined4 *)((int)local_38 + 0x11);
    param_1 = local_3c;
    local_38 = puVar5;
  } while (local_2c < 0x20);
  FUN_004d8d80();
  ExceptionList = local_10;
  return;
}


