
void __fastcall FUN_004d18c0(int *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  QFile local_30 [8];
  QString local_28 [4];
  QTypedArrayData<unsigned_short> *local_24;
  QTypedArrayData<unsigned_short> *local_20;
  QTypedArrayData<unsigned_short> *local_1c;
  int local_18;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00539ca6;
  local_10 = ExceptionList;
  uVar1 = DAT_00759b24 ^ (uint)(local_28 + 0x24);
  ExceptionList = &local_10;
  local_1c = QString::fromAscii_helper("/Config/SmcMixerImportDir",0x19);
  local_8 = 0;
  FUN_00487910(local_28,&local_1c);
  local_8._0_1_ = 2;
  QString::~QString((QString *)&local_1c);
  local_24 = QString::fromAscii_helper("IBX File(*.ibx)",0xf);
  local_8._0_1_ = 3;
  local_20 = QString::fromAscii_helper("Import preset",0xd);
  local_8._0_1_ = 4;
  QFileDialog::getOpenFileName(&local_18,*param_1,&local_20,local_28,&local_24,0,0);
  QString::~QString((QString *)&local_20);
  local_8._0_1_ = 7;
  QString::~QString((QString *)&local_24);
  if (*(int *)(local_18 + 4) != 0) {
    QFile::QFile(local_30);
    local_8._0_1_ = 8;
    iVar2 = FUN_00486ef0(local_30,&local_18,1,1);
    if (iVar2 != 0) {
      uVar3 = FUN_004876a0(&local_20,&local_18);
      local_8._0_1_ = 9;
      local_24 = QString::fromAscii_helper("/Config/SmcMixerImportDir",0x19);
      local_8._0_1_ = 10;
      FUN_00487b10(&local_24,uVar3);
      QString::~QString((QString *)&local_24);
      local_8._0_1_ = 8;
      QString::~QString((QString *)&local_20);
      QIODevice::read((QIODevice *)local_30,(char *)(*param_1 + 0x2a8),(ulonglong)uVar1 << 0x20);
      QFileDevice::close((QFileDevice *)local_30);
      FUN_004d5590(0,*param_1 + 0x2a8,0x1c28,*param_1);
      FUN_004872d0(100);
      local_11 = 1;
      FUN_00506590(5,0xa0000000,&local_11,1,0);
      FUN_004872d0(100);
      FUN_004d8cc0();
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7250,(char *)&local_24,"Import success!",0);
      local_8._0_1_ = 0xb;
      FUN_00486bb0(&local_24);
      QString::~QString((QString *)&local_24);
    }
    QFile::~QFile(local_30);
  }
  QString::~QString((QString *)&local_18);
  QString::~QString(local_28);
  ExceptionList = local_10;
  return;
}


