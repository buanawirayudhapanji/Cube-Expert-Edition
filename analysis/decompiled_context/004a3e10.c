
void FUN_004a3e10(void)

{
  StandardButton SVar1;
  undefined *local_18;
  undefined *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0051b557;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = &DAT_00755994;
  local_14 = &DAT_00755970;
  local_8 = 1;
  SVar1 = QMessageBox::information
                    (0,&local_14,&local_18,0x14000,0,DAT_00759b24 ^ (int)register0x00000010 - 4U);
  QString::~QString((QString *)&local_14);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_18);
  if (SVar1 == 0x4000) {
    FUN_004a5930(0,DAT_0075596c,&DAT_00584b94,0x30);
  }
  ExceptionList = local_10;
  return;
}


