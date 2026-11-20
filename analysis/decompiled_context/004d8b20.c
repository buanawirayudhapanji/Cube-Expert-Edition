
void __thiscall FUN_004d8b20(QObject *param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  QObject *pQVar3;
  undefined1 *puVar4;
  QObject *pQVar5;
  uint uVar6;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0053b747;
  local_10 = ExceptionList;
  uVar2 = DAT_00759b24 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  pQVar3 = QObject::sender(param_1);
  uVar6 = 0;
  pQVar5 = param_1 + 0x240;
  while (pQVar3 != *(QObject **)pQVar5) {
    uVar6 = uVar6 + 1;
    pQVar5 = pQVar5 + 4;
    if (8 < uVar6) {
      ExceptionList = local_10;
      return;
    }
  }
  if (uVar6 == 0) {
    *(undefined2 *)(param_1 + 0x1ece) = (undefined2)param_2;
    cVar1 = FUN_00506590(5,0x1c26,param_1 + 0x1ece,2,param_1);
    if (cVar1 == '\0') {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7250,(char *)&param_2,"Write data failed !",0);
      local_8 = 0;
LAB_004d8bbc:
      FUN_00486bb0(&param_2,uVar2);
      local_8 = 0xffffffff;
      QString::~QString((QString *)&param_2);
    }
  }
  else {
    if (uVar6 != 1) {
      if (uVar6 == 7) {
        *(undefined2 *)(param_1 + 0x1eca) = (undefined2)param_2;
        FUN_004d5590(0x1c22,param_1 + 0x1eca,2,param_1);
        param_2._3_1_ = 2;
        puVar4 = (undefined1 *)((int)&param_2 + 3);
      }
      else if (uVar6 == 8) {
        *(undefined2 *)(param_1 + 0x1ecc) = (undefined2)param_2;
        FUN_004d5590(0x1c24,param_1 + 0x1ecc,2,param_1);
        param_2._3_1_ = 2;
        puVar4 = (undefined1 *)((int)&param_2 + 3);
      }
      else {
        *(undefined2 *)(param_1 + uVar6 * 2 + 0x1eba) = (undefined2)param_2;
        FUN_004d5590(uVar6 * 2 + 0x1c12,param_1 + uVar6 * 2 + 0x1eba,2,param_1);
        local_11 = 2;
        puVar4 = &local_11;
      }
      goto LAB_004d8c92;
    }
    *(undefined2 *)(param_1 + 0x1ec8) = (undefined2)param_2;
    cVar1 = FUN_00506590(5,0x1c20,param_1 + 0x1ec8,2,param_1);
    if (cVar1 == '\0') {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7250,(char *)&param_2,"Write data failed !",0);
      local_8 = 1;
      goto LAB_004d8bbc;
    }
  }
  param_2._3_1_ = 2;
  puVar4 = (undefined1 *)((int)&param_2 + 3);
LAB_004d8c92:
  FUN_00506590(5,0xa0000000,puVar4,1,0);
  FUN_004d91a0();
  ExceptionList = local_10;
  return;
}


