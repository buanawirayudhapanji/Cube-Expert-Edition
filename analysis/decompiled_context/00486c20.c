
void FUN_00486c20(char *param_1)

{
  uint uVar1;
  QString *pQVar2;
  undefined *local_18;
  QString local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0051d317;
  local_10 = ExceptionList;
  uVar1 = DAT_00759b24 ^ (uint)(local_14 + 0x10);
  ExceptionList = &local_10;
  QString::QString(local_14);
  local_8 = 0;
  pQVar2 = (QString *)QString::vasprintf((char *)&local_18,param_1);
  QString::operator=(local_14,pQVar2);
  QString::~QString((QString *)&local_18);
  local_18 = &DAT_0075457c;
  local_8 = CONCAT31(local_8._1_3_,1);
  QMessageBox::information(0,&local_18,local_14,0x400,0,uVar1);
  QString::~QString((QString *)&local_18);
  QString::~QString(local_14);
  ExceptionList = local_10;
  return;
}


