
bool FUN_00487330(undefined4 param_1,char *param_2)

{
  uint uVar1;
  int iVar2;
  QFile local_1c [12];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0051d39e;
  local_10 = ExceptionList;
  uVar1 = DAT_00759b24 ^ (uint)(local_1c + 0x18);
  ExceptionList = &local_10;
  QFile::QFile(local_1c);
  local_8 = 0;
  iVar2 = FUN_00486ef0(local_1c,param_1,2,1);
  if (iVar2 != 0) {
    QIODevice::write((QIODevice *)local_1c,param_2,(ulonglong)uVar1 << 0x20);
    QFileDevice::close((QFileDevice *)local_1c);
  }
  QFile::~QFile(local_1c);
  ExceptionList = local_10;
  return iVar2 != 0;
}


