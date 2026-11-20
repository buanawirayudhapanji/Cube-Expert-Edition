
void __fastcall FUN_004acc40(int *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  QFile local_2c [8];
  QString local_24 [4];
  QTypedArrayData<unsigned_short> *local_20;
  QTypedArrayData<unsigned_short> *local_1c;
  QTypedArrayData<unsigned_short> *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0052fb96;
  local_10 = ExceptionList;
  uVar1 = DAT_00759b24 ^ (uint)(local_24 + 0x20);
  ExceptionList = &local_10;
  local_18 = QString::fromAscii_helper("/Config/SmcMixerImportDir",0x19);
  local_8 = 0;
  FUN_00487910(local_24,&local_18);
  local_8._0_1_ = 2;
  QString::~QString((QString *)&local_18);
  local_20 = QString::fromAscii_helper("FCP File(*.fcp)",0xf);
  local_8._0_1_ = 3;
  local_1c = QString::fromAscii_helper("Import preset",0xd);
  local_8._0_1_ = 4;
  QFileDialog::getOpenFileName(&local_14,*param_1,&local_1c,local_24,&local_20,0,0);
  QString::~QString((QString *)&local_1c);
  local_8._0_1_ = 7;
  QString::~QString((QString *)&local_20);
  if (*(int *)(local_14 + 4) != 0) {
    QFile::QFile(local_2c);
    local_8._0_1_ = 8;
    iVar2 = FUN_00486ef0(local_2c,&local_14,1,1);
    if (iVar2 != 0) {
      uVar3 = FUN_004876a0(&local_1c,&local_14);
      local_8._0_1_ = 9;
      local_20 = QString::fromAscii_helper("/Config/SmcMixerImportDir",0x19);
      local_8._0_1_ = 10;
      FUN_00487b10(&local_20,uVar3);
      QString::~QString((QString *)&local_20);
      local_8._0_1_ = 8;
      QString::~QString((QString *)&local_1c);
      QIODevice::read((QIODevice *)local_2c,(char *)(*param_1 + 0xa38),(ulonglong)uVar1 << 0x20);
      QFileDevice::close((QFileDevice *)local_2c);
      FUN_004b6c90(0,*param_1 + 0xa38,0x5c5e,*param_1);
      FUN_004b3db0();
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f6f40,(char *)&local_20,"Import success!",0);
      local_8._0_1_ = 0xb;
      FUN_00486bb0(&local_20);
      QString::~QString((QString *)&local_20);
    }
    QFile::~QFile(local_2c);
  }
  QString::~QString((QString *)&local_14);
  QString::~QString(local_24);
  ExceptionList = local_10;
  return;
}


