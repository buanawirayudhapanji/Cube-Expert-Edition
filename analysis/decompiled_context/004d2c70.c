
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_004d2c70(int *param_1)

{
  char cVar1;
  int iVar2;
  QString *pQVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  QChar aQStack_92 [2];
  QString local_78 [4];
  QString local_74 [4];
  QComboBox *local_70;
  int local_6c;
  QString local_68 [4];
  QString local_64 [4];
  undefined1 *local_60;
  undefined1 *local_5c;
  code *local_58;
  int *local_54;
  int local_50;
  undefined1 local_49;
  QTypedArrayData<unsigned_short> *local_48;
  QDialog local_44 [24];
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined1 local_1c;
  QComboBox *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00539ed0;
  local_10 = ExceptionList;
  local_14 = DAT_00759b24 ^ (uint)(local_44 + 0x40);
  ExceptionList = &local_10;
  local_58 = shared_null_exref;
  iVar5 = 0;
  local_8 = 0;
  local_54 = param_1;
  iVar2 = QComboBox::count(*(QComboBox **)(*param_1 + 0x13c));
  if (0 < iVar2) {
    do {
      QComboBox::itemText(*(QComboBox **)(*param_1 + 0x13c),(int)&local_48);
      local_8._0_1_ = 1;
      FUN_004ad520();
      local_8 = (uint)local_8._1_3_ << 8;
      QString::~QString((QString *)&local_48);
      iVar5 = iVar5 + 1;
      iVar2 = QComboBox::count(*(QComboBox **)(*param_1 + 0x13c));
    } while (iVar5 < iVar2);
  }
  local_48 = (QTypedArrayData<unsigned_short> *)
             QComboBox::currentIndex(*(QComboBox **)(*param_1 + 0x13c));
  pQVar3 = (QString *)QComboBox::currentText(*(QComboBox **)(*param_1 + 0x13c));
  local_8._0_1_ = 2;
  piVar4 = (int *)QComboBox::currentText(*(QComboBox **)(*local_54 + 0x13c));
  local_8._0_1_ = 3;
  uVar6 = *(undefined4 *)(*piVar4 + 4);
  iVar2 = QComboBox::currentIndex(*(QComboBox **)(*local_54 + 0x13c));
  local_50 = (8 < iVar2) + 6;
  local_60 = aQStack_92 + -6;
  local_5c = aQStack_92 + -6;
  FUN_004d0830();
  local_8._0_1_ = 4;
  QString::mid(pQVar3,(int)(aQStack_92 + -0xe),local_50);
  local_8._0_1_ = 3;
  FUN_004d08f0(uVar6);
  QString::~QString(local_64);
  local_8._0_1_ = 7;
  QString::~QString(local_68);
  iVar2 = QDialog::exec(local_44);
  piVar4 = local_54;
  if (iVar2 == 1) {
    iVar2 = *local_54;
    *(undefined4 *)(iVar2 + 0x2a8) = local_2c;
    *(undefined4 *)(iVar2 + 0x2ac) = uStack_28;
    *(undefined4 *)(iVar2 + 0x2b0) = uStack_24;
    *(undefined4 *)(iVar2 + 0x2b4) = uStack_20;
    *(undefined1 *)(iVar2 + 0x2b8) = local_1c;
    iVar2 = QComboBox::currentIndex(local_18);
    local_49 = 0;
    local_70 = *(QComboBox **)(*piVar4 + 0x13c);
    local_6c = iVar2;
    local_48 = QString::fromAscii_helper("(%1) - %2",9);
    local_50._0_1_ = 0x20;
    local_8._0_1_ = 8;
    QChar::QChar(aQStack_92 + -6);
    pQVar3 = (QString *)QString::arg((QString *)&local_48,&local_60,iVar2 + 1);
    QString::QString((QString *)&local_5c);
    local_8._0_1_ = 10;
    QString::fromUtf8((char *)local_78,*piVar4 + 0x2a8);
    local_50 = CONCAT31(local_50._1_3_,0x20);
    local_8._0_1_ = 0xb;
    QChar::QChar(aQStack_92 + -6);
    pQVar3 = (QString *)QString::arg(pQVar3,local_74);
    iVar5 = local_6c;
    local_8._0_1_ = 0xc;
    QComboBox::setItemText(local_70,local_6c,pQVar3);
    QString::~QString(local_74);
    QString::~QString(local_78);
    QString::~QString((QString *)&local_5c);
    QString::~QString((QString *)&local_60);
    local_8._0_1_ = 7;
    QString::~QString((QString *)&local_48);
    iVar2 = *local_54;
    *(undefined4 *)(iVar2 + 699) = s_patch_0058ce70._0_4_;
    *(char *)(iVar2 + 0x2bf) = s_patch_0058ce70[4];
    cVar1 = FUN_00506590(5,0);
    if (cVar1 == '\0') {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7250,(char *)&local_48,"Data write failure!",0);
      local_8._0_1_ = 0xd;
    }
    else {
      cVar1 = FUN_00506590(5,iVar5 + -0xfffff00);
      if (cVar1 == '\0') {
        QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7250,(char *)&local_48,"Data write failure!",0);
        local_8._0_1_ = 0xe;
      }
      else {
        QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7250,(char *)&local_48,"Save successfully!",0);
        local_8._0_1_ = 0xf;
      }
    }
    FUN_00486bb0();
    QString::~QString((QString *)&local_48);
  }
  QDialog::~QDialog(local_44);
  FUN_00486b10();
  ExceptionList = local_10;
  return;
}


