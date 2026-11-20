
undefined4 __thiscall FUN_004ddd80(int param_1,int param_2,uint param_3,QObject *param_4)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  char *pcVar5;
  uint _Size;
  QEvent *pQVar6;
  QMessageLogger *this;
  undefined4 uVar7;
  uint uVar8;
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
  if (param_3 < *(uint *)(param_1 + 0x34)) {
    return 6;
  }
  ExceptionList = &local_10;
  local_24 = (void *)FUN_00519367(*(undefined4 *)(param_1 + 0x1c),
                                  DAT_00759b24 ^ (uint)(local_38 + 0x34));
  FUN_004908a0(local_24,param_4);
  uVar8 = *(int *)(param_1 + 0x1c) * *(int *)(param_1 + 0x18);
  local_8 = 0;
  uVar4 = *(uint *)(param_1 + 0x34) / uVar8;
  local_18 = uVar4 + 1;
  if (*(uint *)(param_1 + 0x34) % uVar8 == 0) {
    local_18 = uVar4;
  }
  uVar4 = 0;
  param_3 = 0;
  if (local_18 != 0) {
    do {
      pcVar5 = (char *)QMessageLogger::QMessageLogger(local_38,(char *)0x0,0,(char *)0x0);
      local_14 = param_3 * 2;
      this = (QMessageLogger *)(uint)*(ushort *)(*(int *)(param_1 + 0x3c) + local_14);
      QMessageLogger::debug(this,pcVar5,"Read file block=%d\n",this);
      uVar8 = 0;
      if (*(int *)(param_1 + 0x18) != 0) {
        do {
          cVar3 = FUN_005063f0(1,(uint)*(ushort *)(*(int *)(param_1 + 0x3c) + local_14) *
                                 *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x14) * uVar8 +
                                 *(int *)(param_1 + 4),local_24,*(undefined4 *)(param_1 + 0x1c),0);
          if (cVar3 == '\0') {
            uVar7 = 3;
            goto LAB_004ddf10;
          }
          _Size = *(int *)(param_1 + 0x34) - uVar4;
          if (_Size <= *(uint *)(param_1 + 0x1c)) {
            memcpy((void *)(param_2 + uVar4),local_24,_Size);
            goto LAB_004ddf0e;
          }
          memcpy((void *)(param_2 + uVar4),local_24,*(uint *)(param_1 + 0x1c));
          uVar4 = uVar4 + *(int *)(param_1 + 0x1c);
          if (param_4 != (QObject *)0x0) {
            local_1c = operator_new(0x20);
            local_8._0_1_ = 1;
            pQVar6 = (QEvent *)FUN_0050fec0(0x3f0,uVar4,*(undefined4 *)(param_1 + 0x34));
            local_8 = (uint)local_8._1_3_ << 8;
            QCoreApplication::postEvent(param_4,pQVar6,0);
            FUN_00487020();
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 < *(uint *)(param_1 + 0x18));
      }
      if (*(uint *)(param_1 + 0x34) <= uVar4) break;
      param_3 = param_3 + 1;
    } while (param_3 < local_18);
  }
LAB_004ddf0e:
  uVar7 = 0;
LAB_004ddf10:
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
  return uVar7;
}


