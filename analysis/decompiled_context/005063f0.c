
undefined4 __thiscall
FUN_005063f0(undefined4 param_1,uint param_2,uint param_3,int param_4,uint param_5,QObject *param_6)

{
  QObject *pQVar1;
  char cVar2;
  uint uVar3;
  QEvent *pQVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054e094;
  local_10 = ExceptionList;
  uVar3 = DAT_00759b24 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  local_1c = DAT_00756ac8 - 0xf;
  uVar7 = 0;
  local_18 = (uint)(param_5 % local_1c != 0) + param_5 / local_1c;
  if (local_18 != 0) {
    uVar5 = param_3;
    local_14 = param_1;
    do {
      uVar6 = param_5;
      if (local_1c < param_5) {
        uVar6 = local_1c;
      }
      cVar2 = FUN_00507e60(param_2,uVar5,uVar6);
      if ((((cVar2 == '\0') ||
           (cVar2 = FUN_00507ba0(param_4,uVar6,&param_3,&local_20,&local_24,2000), pQVar1 = param_6,
           cVar2 == '\0')) || (param_3 != param_2)) || ((local_20 != uVar5 || (local_24 != uVar6))))
      {
        ExceptionList = local_10;
        return 0;
      }
      param_5 = param_5 - uVar6;
      uVar5 = uVar5 + local_24;
      param_4 = param_4 + local_24;
      if (param_6 != (QObject *)0x0) {
        operator_new(0x20);
        local_8 = 0;
        pQVar4 = (QEvent *)FUN_0050fec0(0x3f0,uVar7 + 1,local_18);
        local_8 = 0xffffffff;
        QCoreApplication::postEvent(pQVar1,pQVar4,0);
      }
      uVar7 = uVar7 + 1;
      FUN_00487020(uVar3);
    } while (uVar7 < local_18);
  }
  ExceptionList = local_10;
  return 1;
}


