
void __thiscall FUN_004d37c0(QObject *param_1,undefined8 param_2)

{
  char cVar1;
  uint uVar2;
  QObject *pQVar3;
  undefined1 *puVar4;
  QObject *pQVar5;
  QObject QVar6;
  uint uVar7;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0053abc9;
  local_10 = ExceptionList;
  uVar2 = DAT_00759b24 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  pQVar3 = QObject::sender(param_1);
  pQVar5 = param_1 + 0x22c;
  uVar7 = 0;
  do {
    if (pQVar3 == *(QObject **)pQVar5) {
      param_1[uVar7 + 0x1eb1] =
           SUB41((int)((double)CONCAT17(param_2._7_1_,(undefined7)param_2) * DAT_00581060),0);
      cVar1 = FUN_00506590(5,uVar7 + 0x1c09,param_1 + uVar7 + 0x1eb1,1,param_1);
      if (cVar1 != '\0') goto LAB_004d39b8;
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7250,(char *)((int)&param_2 + 4),
                      "Write data failed !",0);
      local_8 = 0;
      goto LAB_004d399c;
    }
    uVar7 = uVar7 + 1;
    pQVar5 = pQVar5 + 4;
  } while (uVar7 < 5);
  uVar7 = 0;
  pQVar5 = param_1 + 0x264;
  while (pQVar3 != *(QObject **)pQVar5) {
    uVar7 = uVar7 + 1;
    pQVar5 = pQVar5 + 4;
    if (6 < uVar7) {
      ExceptionList = local_10;
      return;
    }
  }
  QVar6 = SUB41((int)((double)CONCAT17(param_2._7_1_,(undefined7)param_2) * DAT_00581060),0);
  if (uVar7 == 0) {
    param_1[0x1ebb] = QVar6;
    cVar1 = FUN_00506590(5,0x1c13,param_1 + 0x1ebb,1,param_1);
    if (cVar1 == '\0') {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7250,(char *)((int)&param_2 + 4),
                      "Write data failed !",0);
      local_8 = 1;
LAB_004d399c:
      FUN_00486bb0((int)&param_2 + 4,uVar2);
      local_8 = 0xffffffff;
      QString::~QString((QString *)((int)&param_2 + 4));
    }
  }
  else {
    if (uVar7 != 6) {
      param_1[uVar7 + 0x1eb5] = QVar6;
      cVar1 = FUN_00506590(5,uVar7 + 0x1c0d,param_1 + uVar7 + 0x1eb5,1,param_1);
      if (cVar1 == '\0') {
        QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7250,(char *)((int)&param_2 + 4),
                        "Write data failed !",0);
        local_8 = 3;
        FUN_00486bb0((int)&param_2 + 4,uVar2);
        local_8 = 0xffffffff;
        QString::~QString((QString *)((int)&param_2 + 4));
      }
      local_11 = 2;
      puVar4 = &local_11;
      goto LAB_004d39bf;
    }
    param_1[0x1ebc] = QVar6;
    cVar1 = FUN_00506590(5,0x1c14,param_1 + 0x1ebc,1,param_1);
    if (cVar1 == '\0') {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7250,(char *)((int)&param_2 + 4),
                      "Write data failed !",0);
      local_8 = 2;
      goto LAB_004d399c;
    }
  }
LAB_004d39b8:
  puVar4 = (undefined1 *)((int)&param_2 + 7);
  param_2._7_1_ = 2;
LAB_004d39bf:
  FUN_00506590(5,0xa0000000,puVar4,1,0);
  FUN_004d91a0();
  ExceptionList = local_10;
  return;
}


