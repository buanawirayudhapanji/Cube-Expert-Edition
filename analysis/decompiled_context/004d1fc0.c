
void __fastcall FUN_004d1fc0(int *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  char *_Memory;
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
  puStack_c = &LAB_00539df8;
  local_10 = ExceptionList;
  uVar2 = DAT_00759b24 ^ (uint)(local_24 + 0x20);
  ExceptionList = &local_10;
  local_18 = QString::fromAscii_helper("/Config/SmcMixerImportDir",0x19);
  local_8 = 0;
  FUN_00487910(local_24,&local_18);
  local_8._0_1_ = 2;
  QString::~QString((QString *)&local_18);
  local_20 = QString::fromAscii_helper("AIBX File(*.aibx)",0x11);
  local_8._0_1_ = 3;
  local_1c = QString::fromAscii_helper("Import all Preset",0x11);
  local_8._0_1_ = 4;
  QFileDialog::getOpenFileName(&local_14,*param_1,&local_1c,local_24,&local_20,0,0);
  QString::~QString((QString *)&local_1c);
  local_8._0_1_ = 7;
  QString::~QString((QString *)&local_20);
  if (*(int *)(local_14 + 4) != 0) {
    QFile::QFile(local_2c);
    local_8._0_1_ = 8;
    iVar3 = FUN_00486ef0(local_2c,&local_14,1,1);
    if (iVar3 != 0) {
      uVar4 = FUN_004876a0(&local_1c,&local_14);
      local_8._0_1_ = 9;
      local_20 = QString::fromAscii_helper("/Config/SmcMixerImportDir",0x19);
      local_8._0_1_ = 10;
      FUN_00487b10(&local_20,uVar4);
      QString::~QString((QString *)&local_20);
      local_8 = CONCAT31(local_8._1_3_,8);
      QString::~QString((QString *)&local_1c);
      _Memory = (char *)FUN_00519367(0x40000);
      QIODevice::read((QIODevice *)local_2c,_Memory,(ulonglong)uVar2 << 0x20);
      QFileDevice::close((QFileDevice *)local_2c);
      iVar3 = 0x70000000;
      do {
        cVar1 = FUN_005063a0(5,iVar3);
        if (cVar1 == '\0') {
          QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7250,(char *)&local_20,"Failed to erase data!"
                          ,0);
          local_8._0_1_ = 0xb;
          FUN_00486bb0(&local_20);
          QString::~QString((QString *)&local_20);
          free(_Memory);
          goto LAB_004d2259;
        }
        iVar3 = iVar3 + 0x1000;
      } while (iVar3 < 0x70040000);
      (**(code **)(**(int **)(*param_1 + 0x21c) + 0x2c))(1);
      cVar1 = FUN_00506590(5,0x70000000,_Memory,0x40000,*param_1);
      if (cVar1 == '\0') {
        QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7250,(char *)&local_20,"Failed to write data!",0
                       );
        local_8._0_1_ = 0xc;
        FUN_00486bb0(&local_20);
        local_8._0_1_ = 8;
        QString::~QString((QString *)&local_20);
        free(_Memory);
        (**(code **)(**(int **)(*param_1 + 0x21c) + 0x2c))(0);
      }
      else {
        free(_Memory);
        FUN_004d8cc0();
        FUN_004d41e0();
        (**(code **)(**(int **)(*param_1 + 0x21c) + 0x2c))(0);
        QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7250,(char *)&local_20,"Import success!",0);
        local_8._0_1_ = 0xd;
        FUN_00486bb0(&local_20);
        QString::~QString((QString *)&local_20);
      }
    }
LAB_004d2259:
    QFile::~QFile(local_2c);
  }
  QString::~QString((QString *)&local_14);
  QString::~QString(local_24);
  ExceptionList = local_10;
  return;
}


