
uint __fastcall FUN_00501450(int param_1)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  QTypedArrayData<unsigned_short> *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0051d2de;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pcVar1 = (char *)(param_1 + 0x2c);
  if (pcVar1 == (char *)0x0) {
    iVar4 = -1;
  }
  else {
    pcVar3 = pcVar1;
    do {
      cVar2 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar2 != '\0');
    iVar4 = (int)pcVar3 - (param_1 + 0x2d);
  }
  local_14 = (QTypedArrayData<unsigned_short> *)param_1;
  local_14 = QString::fromAscii_helper(pcVar1,iVar4);
  local_8 = 0;
  uVar5 = QString::toUInt((QString *)&local_14,(bool *)0x0,10);
  QString::~QString((QString *)&local_14);
  ExceptionList = local_10;
  return uVar5;
}


