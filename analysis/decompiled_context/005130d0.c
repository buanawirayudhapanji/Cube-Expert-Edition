
undefined4 __thiscall FUN_005130d0(int *param_1,int param_2,uint param_3,QObject *param_4)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  char *pcVar4;
  uint uVar5;
  QEvent *pQVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  QMessageLogger local_3c [20];
  void *local_28;
  int *local_24;
  void *local_20;
  uint local_1c;
  ushort *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0055fe7c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (**(code **)(*param_1 + 4))(DAT_00759b24 ^ (uint)(local_3c + 0x38));
  if (param_3 < local_14) {
    ExceptionList = local_10;
    return 6;
  }
  local_28 = (void *)FUN_00519367(param_1[8]);
  FUN_004908a0(local_28,param_4);
  local_8 = 0;
  local_1c = (**(code **)(*param_1 + 0xc))();
  uVar8 = 0;
  param_3 = 0;
  if (local_1c != 0) {
    do {
      pcVar4 = (char *)QMessageLogger::QMessageLogger(local_3c,(char *)0x0,0,(char *)0x0);
      local_18 = (ushort *)((int)param_1 + (param_3 + 0x24) * 2);
      QMessageLogger::debug
                ((QMessageLogger *)(uint)*local_18,pcVar4,"Read file block=%d\n",
                 (QMessageLogger *)(uint)*local_18);
      uVar5 = param_1[7];
      uVar10 = 0;
      if (uVar5 != 0) {
        do {
          uVar7 = uVar10;
          if ((param_3 == 0) && (uVar7 = uVar5 - 1, uVar10 != 0)) {
            uVar7 = uVar10 - 1;
          }
          cVar3 = FUN_005063f0(1,(uint)*local_18 * param_1[5] + param_1[6] * uVar7 + param_1[2],
                               local_28,param_1[8],0);
          if (cVar3 == '\0') {
            uVar9 = 3;
            goto LAB_00513261;
          }
          if (local_14 - uVar8 <= (uint)param_1[8]) {
            memcpy((void *)(param_2 + uVar8),local_28,local_14 - uVar8);
            goto LAB_0051325f;
          }
          memcpy((void *)(param_2 + uVar8),local_28,param_1[8]);
          uVar8 = uVar8 + param_1[8];
          if (param_4 != (QObject *)0x0) {
            local_20 = operator_new(0x20);
            local_8._0_1_ = 1;
            pQVar6 = (QEvent *)FUN_0050fec0(0x3f0,uVar8,local_14);
            local_8 = (uint)local_8._1_3_ << 8;
            QCoreApplication::postEvent(param_4,pQVar6,0);
            FUN_00487020();
          }
          uVar5 = param_1[7];
          uVar10 = uVar10 + 1;
        } while (uVar10 < uVar5);
      }
    } while ((uVar8 < local_14) && (param_3 = param_3 + 1, param_3 < local_1c));
  }
LAB_0051325f:
  uVar9 = 0;
LAB_00513261:
  local_8 = 2;
  if (local_24 != (int *)0x0) {
    LOCK();
    iVar2 = local_24[1] + -1;
    local_24[1] = iVar2;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)(*local_24 + 4))();
      LOCK();
      piVar1 = local_24 + 2;
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (**(code **)(*local_24 + 8))();
      }
    }
  }
  ExceptionList = local_10;
  return uVar9;
}


