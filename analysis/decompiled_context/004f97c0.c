
void __fastcall FUN_004f97c0(QObject *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  uint uVar5;
  QObject *pQVar6;
  StandardButton SVar7;
  int iVar8;
  char *pcVar9;
  QObject *pQVar10;
  QFile local_28 [8];
  undefined *local_20;
  undefined *local_1c;
  QString local_18 [4];
  QObject *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00549a14;
  local_10 = ExceptionList;
  uVar5 = DAT_00759b24 ^ (uint)(local_18 + 0x14);
  ExceptionList = &local_10;
  local_14 = param_1;
  pQVar6 = QObject::sender(param_1);
  if (pQVar6 == *(QObject **)(param_1 + 0x448)) {
    cVar4 = FUN_00506540(5,0);
    if (cVar4 == '\0') {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7710,(char *)&local_14,"Write data failed !",0);
      local_8 = 0;
      FUN_00486bb0(&local_14);
      local_8 = 0xffffffff;
      QString::~QString((QString *)&local_14);
    }
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7710,(char *)&local_14,"Save Config Succeed!",0);
    local_8 = 1;
    FUN_00486bb0(&local_14);
    QString::~QString((QString *)&local_14);
    ExceptionList = local_10;
    return;
  }
  if (pQVar6 == *(QObject **)(param_1 + 0x440)) {
    QPlainTextEdit::clear(*(QPlainTextEdit **)(param_1 + 0x444));
    ExceptionList = local_10;
    return;
  }
  if (pQVar6 == *(QObject **)(param_1 + 0x44c)) {
    local_20 = &DAT_00756700;
    local_1c = &DAT_007566cc;
    local_8 = 3;
    SVar7 = QMessageBox::information(0,&local_1c,&local_20,0x14000,0);
    QString::~QString((QString *)&local_1c);
    local_8 = 0xffffffff;
    QString::~QString((QString *)&local_20);
    if (SVar7 == 0x4000) {
      FUN_00486cd0(local_18);
      local_8 = 4;
      QString::operator+=(local_18,"bin/MMKB.bin");
      QFile::QFile(local_28);
      local_8._0_1_ = 5;
      iVar8 = FUN_00486ef0(local_28,local_18,1,1);
      if (iVar8 != 0) {
        pcVar9 = (char *)FUN_00519367(0x96);
        QIODevice::read((QIODevice *)local_28,pcVar9,(ulonglong)uVar5 << 0x20);
        uVar1 = *(undefined4 *)(pcVar9 + 4);
        uVar2 = *(undefined4 *)(pcVar9 + 8);
        uVar3 = *(undefined4 *)(pcVar9 + 0xc);
        *(undefined4 *)(local_14 + 0x18) = *(undefined4 *)pcVar9;
        *(undefined4 *)(local_14 + 0x1c) = uVar1;
        *(undefined4 *)(local_14 + 0x20) = uVar2;
        *(undefined4 *)(local_14 + 0x24) = uVar3;
        pQVar6 = (QObject *)(pcVar9 + 0x10);
        pQVar10 = local_14 + 0x28;
        for (iVar8 = 0x17; iVar8 != 0; iVar8 = iVar8 + -1) {
          *(undefined4 *)pQVar10 = *(undefined4 *)pQVar6;
          pQVar6 = pQVar6 + 4;
          pQVar10 = pQVar10 + 4;
        }
        *pQVar10 = *pQVar6;
        QFileDevice::close((QFileDevice *)local_28);
        pQVar6 = local_14;
        FUN_004fa290(4,0,local_14 + 0x18,0x10);
        FUN_004fa290(5,0,pQVar6 + 0x28,0x5d);
        FUN_004f9af0();
        FUN_004fa170();
        QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7710,(char *)&local_20,
                        "The configuration has been restored to factory Settings but has not been persisted. Click Save Config to persist"
                        ,0);
        local_8._0_1_ = 6;
        FUN_00486bb0(&local_20);
        QString::~QString((QString *)&local_20);
      }
      QFile::~QFile(local_28);
      QString::~QString(local_18);
      ExceptionList = local_10;
      return;
    }
  }
  else if (pQVar6 == *(QObject **)(param_1 + 0x434)) {
    param_1[0x9c] = (QObject)0x0;
    *(undefined4 *)(param_1 + 0x81) = 0x7f004000;
    param_1[0x80] = (QObject)0x0;
    QComboBox::setCurrentIndex(*(QComboBox **)(param_1 + 0x3e0),0);
    QComboBox::setCurrentIndex(*(QComboBox **)(local_14 + 0x39c),(uint)(byte)local_14[0x81]);
    QSpinBox::setValue(*(QSpinBox **)(local_14 + 0x3ac),(uint)(byte)local_14[0x82]);
    QSpinBox::setValue(*(QSpinBox **)(local_14 + 0x3a8),(uint)(byte)local_14[0x83]);
    QSpinBox::setValue(*(QSpinBox **)(local_14 + 0x3bc),(uint)(byte)local_14[0x84]);
    local_14[0x9c] = (QObject)0x1;
    FUN_004fa290(5,0x58,param_1 + 0x80,5);
  }
  ExceptionList = local_10;
  return;
}


