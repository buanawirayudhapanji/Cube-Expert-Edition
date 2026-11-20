
void FUN_00486bb0(undefined4 param_1)

{
  undefined *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0051d2de;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = &DAT_0075459c;
  local_8 = 0;
  QMessageBox::information(0,&local_14,param_1,0x400,0,DAT_00759b24 ^ (int)register0x00000010 - 4U);
  QString::~QString((QString *)&local_14);
  ExceptionList = local_10;
  return;
}


