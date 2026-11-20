
undefined4 __thiscall FUN_00513e90(int *param_1,int param_2,uint param_3,QObject *param_4)

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
  QMessageLogger local_38 [20];
  void *local_24;
  int *local_20;
  void *local_1c;
  uint local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0053e1cc;
  local_10 = ExceptionList;
  if (param_3 < (uint)param_1[0x10]) {
    return 6;
  }
  ExceptionList = &local_10;
  local_24 = (void *)FUN_00519367(param_1[8],DAT_00759b24 ^ (uint)(local_38 + 0x34));
  FUN_004908a0(local_24,param_4);
  local_8 = 0;
  local_18 = (**(code **)(*param_1 + 0xc))();
  uVar8 = 0;
  param_3 = 0;
  if (local_18 != 0) {
    do {
      pcVar4 = (char *)QMessageLogger::QMessageLogger(local_38,(char *)0x0,0,(char *)0x0);
      local_14 = param_3 * 2;
      QMessageLogger::debug
                ((QMessageLogger *)(uint)*(ushort *)(param_1[0x11] + local_14),pcVar4,
                 "Read file block=%d\n",
                 (QMessageLogger *)(uint)*(ushort *)(param_1[0x11] + local_14));
      uVar5 = param_1[7];
      uVar10 = 0;
      if (uVar5 != 0) {
        do {
          uVar7 = uVar10;
          if ((param_3 == 0) && (uVar7 = uVar5 - 1, uVar10 != 0)) {
            uVar7 = uVar10 - 1;
          }
          cVar3 = FUN_005063f0(1,(uint)*(ushort *)(param_1[0x11] + local_14) * param_1[5] +
                                 param_1[6] * uVar7 + param_1[2],local_24,param_1[8],0);
          if (cVar3 == '\0') {
            uVar9 = 3;
            goto LAB_0051401d;
          }
          if (param_1[0x10] - uVar8 <= (uint)param_1[8]) {
            memcpy((void *)(param_2 + uVar8),local_24,param_1[0x10] - uVar8);
            goto LAB_0051401b;
          }
          memcpy((void *)(param_2 + uVar8),local_24,param_1[8]);
          uVar8 = uVar8 + param_1[8];
          if (param_4 != (QObject *)0x0) {
            local_1c = operator_new(0x20);
            local_8._0_1_ = 1;
            pQVar6 = (QEvent *)FUN_0050fec0(0x3f0,uVar8,param_1[0x10]);
            local_8 = (uint)local_8._1_3_ << 8;
            QCoreApplication::postEvent(param_4,pQVar6,0);
            FUN_00487020();
          }
          uVar5 = param_1[7];
          uVar10 = uVar10 + 1;
        } while (uVar10 < uVar5);
      }
      if ((uint)param_1[0x10] <= uVar8) break;
      param_3 = param_3 + 1;
    } while (param_3 < local_18);
  }
LAB_0051401b:
  uVar9 = 0;
LAB_0051401d:
  local_8 = 2;
  if (local_20 != (int *)0x0) {
    LOCK();
    iVar2 = local_20[1] + -1;
    local_20[1] = iVar2;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)(*local_20 + 4))();
      LOCK();
      piVar1 = local_20 + 2;
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (**(code **)(*local_20 + 8))();
      }
    }
  }
  ExceptionList = local_10;
  return uVar9;
}


