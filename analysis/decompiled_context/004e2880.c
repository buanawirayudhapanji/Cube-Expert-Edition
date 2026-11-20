
void __fastcall FUN_004e2880(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  QVariant *this;
  QString *pQVar3;
  int iVar4;
  char *pcVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  __int64 _Var8;
  QVariant local_68 [16];
  QVariant local_58 [16];
  QVariant local_48 [4];
  undefined8 local_44;
  QFile local_38 [8];
  QString local_30 [4];
  QString local_2c [4];
  int local_28;
  QTypedArrayData<unsigned_short> *local_24;
  undefined *local_20;
  QTypedArrayData<unsigned_short> *local_1c;
  undefined *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00541b08;
  local_10 = ExceptionList;
  uVar1 = DAT_00759b24 ^ (uint)(local_2c + 0x28);
  ExceptionList = &local_10;
  local_20 = &DAT_0075639c;
  local_8 = 0;
  local_28 = param_1;
  uVar2 = QVariant::QVariant(local_68);
  local_8._0_1_ = 1;
  local_1c = QString::fromAscii_helper("/Config/MidiCfgDir",0x12);
  local_8._0_1_ = 2;
  this = (QVariant *)FUN_00487a10(local_58,&local_1c,uVar2);
  local_8._0_1_ = 3;
  uVar2 = QVariant::toString(this);
  local_18 = &DAT_00756360;
  local_8._0_1_ = 5;
  QFileDialog::getOpenFileName(&local_14,param_1,&local_18,uVar2,&local_20,0,0);
  QString::~QString((QString *)&local_18);
  QString::~QString(local_2c);
  QVariant::~QVariant(local_58);
  QString::~QString((QString *)&local_1c);
  QVariant::~QVariant(local_68);
  local_8._0_1_ = 0xc;
  QString::~QString((QString *)&local_20);
  if (*(int *)(local_14 + 4) != 0) {
    pQVar3 = (QString *)FUN_004876a0(local_30,&local_14);
    local_8._0_1_ = 0xd;
    QVariant::QVariant(local_48,pQVar3);
    local_8._0_1_ = 0xe;
    local_24 = QString::fromAscii_helper("/Config/MidiCfgDir",0x12);
    local_8._0_1_ = 0xf;
    FUN_00487c00(&local_24,local_48);
    QString::~QString((QString *)&local_24);
    QVariant::~QVariant(local_48);
    local_8._0_1_ = 0xc;
    QString::~QString(local_30);
    QFile::QFile(local_38);
    local_8._0_1_ = 0x10;
    iVar4 = FUN_00486ef0(local_38,&local_14,1,1);
    if (iVar4 == 0) {
      FUN_00486c20("Open file failed !");
    }
    else {
      _Var8 = QFile::size(local_38);
      pcVar5 = (char *)FUN_00519367((int)_Var8);
      _Var8 = QFile::size(local_38);
      QIODevice::read((QIODevice *)local_38,pcVar5,CONCAT44(uVar1,(int)((ulonglong)_Var8 >> 0x20)));
      QFileDevice::close((QFileDevice *)local_38);
      local_44 = *(undefined8 *)pcVar5;
      if ((int)local_44 == 0x4d444346) {
        iVar4 = FUN_00486d80(pcVar5 + 0xc,0x96f);
        if (iVar4 == local_44._4_4_) {
          pcVar5 = pcVar5 + 0xc;
          puVar7 = (undefined4 *)(param_1 + 0x288);
          for (iVar4 = 0x25b; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar7 = *(undefined4 *)pcVar5;
            pcVar5 = pcVar5 + 4;
            puVar7 = puVar7 + 1;
          }
          *(undefined2 *)puVar7 = *(undefined2 *)pcVar5;
          *(char *)((int)puVar7 + 2) = pcVar5[2];
          iVar4 = 0;
          puVar7 = (undefined4 *)(param_1 + 0x1c4);
          pbVar6 = (byte *)(param_1 + 0x3c8);
          do {
            QComboBox::setCurrentIndex((QComboBox *)puVar7[7],(uint)*pbVar6);
            QListWidget::setCurrentRow((QListWidget *)*puVar7,0);
            FUN_004e3fa0(iVar4);
            FUN_004f16c0();
            iVar4 = iVar4 + 1;
            puVar7 = puVar7 + 1;
            pbVar6 = pbVar6 + 0x159;
          } while (iVar4 < 7);
        }
      }
    }
    QFile::~QFile(local_38);
  }
  QString::~QString((QString *)&local_14);
  ExceptionList = local_10;
  return;
}


