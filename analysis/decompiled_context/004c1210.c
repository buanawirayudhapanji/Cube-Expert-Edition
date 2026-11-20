
void __thiscall FUN_004c1210(QObject *param_1,QObject param_2)

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
  if (pQVar3 == *(QObject **)(param_1 + 0x90c)) {
    param_1[0x98e] = param_2;
    cVar1 = FUN_00506590(4,2,param_1 + 0x98e,1,param_1);
    if (cVar1 == '\0') {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f83b0,(char *)&param_2,"Write data failed !",0);
      local_8 = 0;
      FUN_00486bb0(&param_2,uVar2);
      QString::~QString((QString *)&param_2);
      ExceptionList = local_10;
      return;
    }
  }
  else {
    if (pQVar3 == *(QObject **)(param_1 + 0x918)) {
      pQVar3 = param_1 + 0x990;
      uVar4 = 4;
    }
    else if (pQVar3 == *(QObject **)(param_1 + 0x920)) {
      pQVar3 = param_1 + 0x992;
      uVar4 = 6;
    }
    else if (pQVar3 == *(QObject **)(param_1 + 0x924)) {
      pQVar3 = param_1 + 0x994;
      uVar4 = 8;
    }
    else if (pQVar3 == *(QObject **)(param_1 + 0x92c)) {
      pQVar3 = param_1 + 0x996;
      uVar4 = 10;
    }
    else if (pQVar3 == *(QObject **)(param_1 + 0x958)) {
      pQVar3 = param_1 + 0x10be;
      uVar4 = 0x732;
    }
    else if (pQVar3 == *(QObject **)(param_1 + 0x964)) {
      pQVar3 = param_1 + 0x10c2;
      uVar4 = 0x736;
    }
    else if (pQVar3 == *(QObject **)(param_1 + 0x96c)) {
      pQVar3 = param_1 + 0x10c6;
      uVar4 = 0x73a;
    }
    else {
      if (pQVar3 != *(QObject **)(param_1 + 0x970)) {
        ExceptionList = local_10;
        return;
      }
      pQVar3 = param_1 + 0x10ca;
      uVar4 = 0x73e;
    }
    *pQVar3 = param_2;
    FUN_004c6750(uVar4,pQVar3,1,param_1);
  }
  ExceptionList = local_10;
  return;
}


