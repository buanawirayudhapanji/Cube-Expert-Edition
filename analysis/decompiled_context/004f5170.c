
void __thiscall FUN_004f5170(QObject *param_1,QObject param_2)

{
  char cVar1;
  uint uVar2;
  QObject *pQVar3;
  undefined4 uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0052c59e;
  local_10 = ExceptionList;
  uVar2 = DAT_00759b24 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  pQVar3 = QObject::sender(param_1);
  if (pQVar3 == *(QObject **)(param_1 + 0x117c)) {
    param_1[0x24] = param_2;
    cVar1 = FUN_00506590(4,0xc,param_1 + 0x24,1,0);
    if (cVar1 == '\0') {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7c3c,(char *)&param_2,"Write data failed !",0);
      local_8 = 0;
      FUN_00486bb0(&param_2,uVar2);
      QString::~QString((QString *)&param_2);
      ExceptionList = local_10;
      return;
    }
  }
  else {
    if (pQVar3 == *(QObject **)(param_1 + 0x1178)) {
      param_1 = param_1 + 0x26;
      uVar4 = 0xe;
    }
    else {
      if (pQVar3 != *(QObject **)(param_1 + 0x11c0)) {
        ExceptionList = local_10;
        return;
      }
      param_1 = param_1 + 0x1c;
      uVar4 = 4;
    }
    *param_1 = param_2;
    FUN_004f49c0(4,uVar4,param_1,1);
  }
  ExceptionList = local_10;
  return;
}


