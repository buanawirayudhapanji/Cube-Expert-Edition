
void __fastcall FUN_004f17d0(QObject *param_1)

{
  QObject QVar1;
  char cVar2;
  uint uVar3;
  QObject *pQVar4;
  int iVar5;
  undefined4 uVar6;
  StandardButton SVar7;
  QFile *this;
  QString *this_00;
  uint uVar8;
  QFile local_34 [8];
  QString local_2c [4];
  QTypedArrayData<unsigned_short> *local_28;
  QFile local_24 [4];
  QTypedArrayData<unsigned_short> *local_20;
  QTypedArrayData<unsigned_short> *local_1c;
  QString local_18 [4];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005456f6;
  local_10 = ExceptionList;
  uVar3 = DAT_00759b24 ^ (uint)(local_18 + 0x14);
  ExceptionList = &local_10;
  pQVar4 = QObject::sender(param_1);
  if (pQVar4 == *(QObject **)(param_1 + 0x11d8)) {
    cVar2 = FUN_00506540(5,0);
    if (cVar2 == '\0') {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7c3c,(char *)local_18,"Write data failed !",0);
      local_8 = 0;
      FUN_00486bb0(local_18);
      local_8 = 0xffffffff;
      QString::~QString(local_18);
    }
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7c3c,(char *)local_18,"Save Config Succeed!",0);
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_00486bb0(local_18);
    this_00 = local_18;
    goto LAB_004f1d3f;
  }
  if (pQVar4 == *(QObject **)(param_1 + 0x1338)) {
    QPlainTextEdit::clear(*(QPlainTextEdit **)(param_1 + 0x133c));
    ExceptionList = local_10;
    return;
  }
  if (pQVar4 == *(QObject **)(param_1 + 0x11dc)) {
    QVar1 = param_1[0x18];
    if ((-(uint)(QVar1 != (QObject)0x0) & (uint)(byte)QVar1) < 7) {
      uVar8 = -(uint)(QVar1 != (QObject)0x0) & (uint)(byte)QVar1;
    }
    else {
      uVar8 = 7;
    }
    local_20 = QString::fromAscii_helper("/Config/MidiKeyboardExportDir",0x1d);
    local_8 = 2;
    FUN_00487910(local_18,&local_20);
    local_8._0_1_ = 4;
    QString::~QString((QString *)&local_20);
    local_28 = QString::fromAscii_helper("MKC Files(*.mkc)",0x10);
    local_8._0_1_ = 5;
    local_1c = QString::fromAscii_helper("Save config",0xb);
    local_8._0_1_ = 6;
    QFileDialog::getSaveFileName(&local_14,param_1,&local_1c,local_18,&local_28,0,0);
    QString::~QString((QString *)&local_1c);
    local_8._0_1_ = 9;
    QString::~QString((QString *)&local_28);
    if (*(int *)(local_14 + 4) != 0) {
      QFile::QFile(local_24);
      local_8._0_1_ = 10;
      iVar5 = FUN_00486ef0(local_24,&local_14,2,1);
      if (iVar5 != 0) {
        uVar6 = FUN_004876a0(local_2c,&local_14);
        local_8._0_1_ = 0xb;
        local_28 = QString::fromAscii_helper("/Config/MidiKeyboardExportDir",0x1d);
        local_8._0_1_ = 0xc;
        FUN_00487b10(&local_28,uVar6);
        QString::~QString((QString *)&local_28);
        local_8._0_1_ = 10;
        QString::~QString(local_2c);
        QIODevice::write((QIODevice *)local_24,(char *)(param_1 + uVar8 * 0x1da + 0x2c),
                         (ulonglong)uVar3 << 0x20);
        QFileDevice::close((QFileDevice *)local_24);
        QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7c3c,(char *)&local_28,"Export success!",0);
        local_8._0_1_ = 0xd;
        FUN_00486bb0(&local_28);
        QString::~QString((QString *)&local_28);
      }
      this = local_24;
LAB_004f1a45:
      QFile::~QFile(this);
    }
  }
  else {
    if (pQVar4 != *(QObject **)(param_1 + 0x11e0)) {
      if (pQVar4 != *(QObject **)(param_1 + 0x11f8)) {
        ExceptionList = local_10;
        return;
      }
      local_20 = (QTypedArrayData<unsigned_short> *)&DAT_007564a8;
      local_28 = (QTypedArrayData<unsigned_short> *)&DAT_00756474;
      local_8 = 0x1b;
      SVar7 = QMessageBox::information(0,&local_28,&local_20,0x14000,0);
      QString::~QString((QString *)&local_28);
      local_8 = 0xffffffff;
      QString::~QString((QString *)&local_20);
      if (SVar7 != 0x4000) {
        ExceptionList = local_10;
        return;
      }
      FUN_00486cd0(&local_1c);
      local_8 = 0x1c;
      QString::operator+=((QString *)&local_1c,"bin/MKB.bin");
      QFile::QFile(local_34);
      local_8._0_1_ = 0x1d;
      iVar5 = FUN_00486ef0(local_34,&local_1c,1,1);
      if (iVar5 != 0) {
        QIODevice::read((QIODevice *)local_34,(char *)(param_1 + 0x2c),(ulonglong)uVar3 << 0x20);
        QFileDevice::close((QFileDevice *)local_34);
        FUN_004f49c0(5,0,param_1 + 0x2c,0xed0);
        FUN_004f1d60(param_1[0x18]);
        QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7c3c,(char *)local_2c,
                        "The configuration has been restored to factory Settings but has not been persisted. Click Save Config to persist"
                        ,0);
        local_8._0_1_ = 0x1e;
        FUN_00486bb0(local_2c);
        QString::~QString(local_2c);
      }
      QFile::~QFile(local_34);
      this_00 = (QString *)&local_1c;
      goto LAB_004f1d3f;
    }
    QVar1 = param_1[0x18];
    if ((-(uint)(QVar1 != (QObject)0x0) & (uint)(byte)QVar1) < 7) {
      uVar8 = -(uint)(QVar1 != (QObject)0x0) & (uint)(byte)QVar1;
    }
    else {
      uVar8 = 7;
    }
    local_28 = QString::fromAscii_helper("/Config/MidiKeyboardImportDir",0x1d);
    local_8 = 0xe;
    FUN_00487910(local_18,&local_28);
    local_8._0_1_ = 0x10;
    QString::~QString((QString *)&local_28);
    local_1c = QString::fromAscii_helper("MKC Files(*.mkc)",0x10);
    local_8._0_1_ = 0x11;
    local_20 = QString::fromAscii_helper("Open config",0xb);
    local_8._0_1_ = 0x12;
    QFileDialog::getOpenFileName(&local_14,param_1,&local_20,local_18,&local_1c,0,0);
    QString::~QString((QString *)&local_20);
    local_8._0_1_ = 0x15;
    QString::~QString((QString *)&local_1c);
    if (*(int *)(local_14 + 4) != 0) {
      QFile::QFile(local_34);
      local_8._0_1_ = 0x16;
      iVar5 = FUN_00486ef0(local_34,&local_14,1,1);
      if (iVar5 != 0) {
        uVar6 = FUN_004876a0(local_2c,&local_14);
        local_8._0_1_ = 0x17;
        local_28 = QString::fromAscii_helper("/Config/MidiKeyboardImportDir",0x1d);
        local_8._0_1_ = 0x18;
        FUN_00487b10(&local_28,uVar6);
        QString::~QString((QString *)&local_28);
        local_8._0_1_ = 0x16;
        QString::~QString(local_2c);
        QIODevice::read((QIODevice *)local_34,(char *)(param_1 + uVar8 * 0x1da + 0x2c),
                        (ulonglong)uVar3 << 0x20);
        QFileDevice::close((QFileDevice *)local_34);
        FUN_004f49c0(5,uVar8 * 0x1da,param_1 + uVar8 * 0x1da + 0x2c,0x1da);
        FUN_004f1d60(param_1[0x18]);
        QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7c3c,(char *)&local_28,"Import success!",0);
        local_8._0_1_ = 0x19;
        FUN_00486bb0(&local_28);
        QString::~QString((QString *)&local_28);
      }
      this = local_34;
      goto LAB_004f1a45;
    }
  }
  QString::~QString((QString *)&local_14);
  this_00 = local_18;
LAB_004f1d3f:
  QString::~QString(this_00);
  ExceptionList = local_10;
  return;
}


