
void __thiscall FUN_004d35a0(QObject *param_1,QObject param_2)

{
  char cVar1;
  uint uVar2;
  QObject *pQVar3;
  QObject *pQVar4;
  QObject *pQVar5;
  int local_20;
  QString local_18 [7];
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0053ab2e;
  local_10 = ExceptionList;
  uVar2 = DAT_00759b24 ^ (uint)(local_18 + 0x14);
  ExceptionList = &local_10;
  pQVar3 = QObject::sender(param_1);
  pQVar4 = param_1 + 0x1ea8;
  pQVar5 = param_1 + 0x280;
  local_20 = 9;
  do {
    if (pQVar3 == *(QObject **)pQVar5) {
      *pQVar4 = param_2;
      cVar1 = FUN_00506590(5,pQVar4 + (-0x2a8 - (int)param_1),pQVar4,1,param_1);
      if (cVar1 == '\0') {
        QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7250,(char *)local_18,"Write data failed !",0);
        local_8 = 0;
        FUN_00486bb0(local_18,uVar2);
        local_8 = 0xffffffff;
        QString::~QString(local_18);
      }
      local_11 = 2;
      FUN_00506590(5,0xa0000000,&local_11,1,0);
      FUN_004d91a0();
    }
    pQVar5 = pQVar5 + 4;
    pQVar4 = pQVar4 + 1;
    local_20 = local_20 + -1;
  } while (local_20 != 0);
  ExceptionList = local_10;
  return;
}


