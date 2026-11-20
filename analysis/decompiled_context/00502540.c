
void FUN_00502540(void)

{
  QString *pQVar1;
  QString local_20 [4];
  QString local_1c [4];
  undefined4 local_18;
  QString local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054c991;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = 0;
  pQVar1 = (QString *)FUN_00486cd0(local_20,DAT_00759b24 ^ (uint)(local_14 + 0x10));
  local_8 = 1;
  QString::QString(local_14,pQVar1);
  local_18 = 1;
  pQVar1 = (QString *)QString::fromUtf8((char *)local_1c,0x593228);
  local_8._0_1_ = 2;
  QString::append(local_14,pQVar1);
  local_8 = CONCAT31(local_8._1_3_,1);
  QString::~QString(local_1c);
  FUN_00487af0(local_14);
  QString::~QString(local_14);
  QString::~QString(local_20);
  ExceptionList = local_10;
  return;
}


