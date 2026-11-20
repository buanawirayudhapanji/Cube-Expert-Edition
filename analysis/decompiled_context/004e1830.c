
void __thiscall FUN_004e1830(QObject *param_1,QObject param_2)

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
  if (pQVar3 == *(QObject **)(param_1 + 0x1c)) {
    param_1[0x44] = param_2;
    cVar1 = FUN_00506590(4,0,param_1 + 0x44,1,param_1);
    if (cVar1 == '\0') {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7e58,(char *)&param_2,"Write data failed !",0);
      local_8 = 0;
      FUN_00486bb0(&param_2,uVar2);
      QString::~QString((QString *)&param_2);
      ExceptionList = local_10;
      return;
    }
  }
  else {
    if (pQVar3 == *(QObject **)(param_1 + 0x20)) {
      pQVar3 = param_1 + 0x45;
      uVar4 = 1;
    }
    else {
      if (pQVar3 != *(QObject **)(param_1 + 0x24)) {
        ExceptionList = local_10;
        return;
      }
      pQVar3 = param_1 + 0x46;
      uVar4 = 2;
    }
    *pQVar3 = param_2;
    FUN_004e1a50(uVar4,pQVar3,1,param_1);
  }
  ExceptionList = local_10;
  return;
}


