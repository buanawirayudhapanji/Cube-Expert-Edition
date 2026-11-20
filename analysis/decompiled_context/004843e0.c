
void FUN_004843e0(void)

{
  uint uVar1;
  StandardButton SVar2;
  char *pcVar3;
  undefined4 uVar4;
  QTypedArrayData<unsigned_short> *local_18;
  undefined *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0051b557;
  local_10 = ExceptionList;
  uVar1 = DAT_00759b24 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  uVar4 = 0x3d;
  pcVar3 = "Are you sure you want to format the data? This is irrevocable";
  local_18 = QString::fromAscii_helper
                       ("Are you sure you want to format the data? This is irrevocable",0x3d);
  local_14 = &DAT_007542b0;
  local_8 = 1;
  SVar2 = QMessageBox::information(0,&local_14,&local_18,0x14000,0,pcVar3,uVar4,uVar1);
  QString::~QString((QString *)&local_14);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_18);
  if (SVar2 == 0x4000) {
    uVar4 = FUN_005119e0();
    FUN_00484ce0(uVar4);
    FUN_00511b40();
  }
  ExceptionList = local_10;
  return;
}


