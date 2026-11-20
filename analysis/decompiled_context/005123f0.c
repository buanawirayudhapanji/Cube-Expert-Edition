
undefined4 __thiscall FUN_005123f0(int *param_1,int param_2,uint param_3,QObject *param_4)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  char *pcVar4;
  uint uVar5;
  QEvent *pQVar6;
  QMessageLogger *this;
  QMessageLogger local_40 [20];
  void *local_2c;
  int *local_28;
  void *local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0055f29c;
  local_10 = ExceptionList;
  if (param_3 < (uint)param_1[0xf]) {
    return 6;
  }
  ExceptionList = &local_10;
  local_2c = (void *)FUN_00519367(param_1[8],DAT_00759b24 ^ (uint)(local_40 + 0x3c));
  FUN_004908a0(local_2c,param_4);
  local_8 = 0;
  local_20 = (**(code **)(*param_1 + 0xc))();
  local_14 = 0;
  param_3 = 0;
  iVar2 = *(int *)(param_1[0xd] + 0x2ca68);
  if (local_20 != 0) {
    do {
      pcVar4 = (char *)QMessageLogger::QMessageLogger(local_40,(char *)0x0,0,(char *)0x0);
      this = (QMessageLogger *)(uint)*(ushort *)(param_1[0x10] + param_3 * 2);
      QMessageLogger::debug(this,pcVar4,"Read file block=%d\n",this);
      local_18 = 0;
      if (param_1[7] != 0) {
        do {
          cVar3 = FUN_005063f0(1,(uint)*(ushort *)(param_1[0x10] + param_3 * 2) * param_1[5] +
                                 param_1[6] * local_18 + param_1[2],local_2c,param_1[8],0);
          if (cVar3 == '\0') {
            param_4 = (QObject *)0x3;
            goto LAB_00512693;
          }
          if (((((iVar2 != 0x28b9) && (iVar2 != 0x291d)) && (iVar2 != 0x2981)) &&
              ((iVar2 != 0x291e && (iVar2 != 0x291f)))) && (iVar2 != 0x2921)) {
            cVar3 = FUN_00506350(1,(uint)*(ushort *)(param_1[0x10] + param_3 * 2) * param_1[5] +
                                   param_1[6] * local_18 + param_1[2],param_1[8],&local_1c);
            if (cVar3 == '\0') {
              FUN_00486c20("Get checksum failed");
            }
            else {
              uVar5 = FUN_00486d80(local_2c,param_1[8]);
              if ((uVar5 & 0xffff) != local_1c) {
                pcVar4 = (char *)QMessageLogger::QMessageLogger(local_40,(char *)0x0,0,(char *)0x0);
                QMessageLogger::debug
                          ((QMessageLogger *)(param_1[6] * local_18),pcVar4,
                           "NAND Checksum failed 0x%.8X\n",
                           (QMessageLogger *)(param_1[6] * local_18) +
                           param_1[2] + (uint)*(ushort *)(param_1[0x10] + param_3 * 2) * param_1[5])
                ;
                FUN_00486c20("NAND Checksum failed");
              }
            }
          }
          if (param_1[0xf] - local_14 <= (uint)param_1[8]) {
            memcpy((void *)(local_14 + param_2),local_2c,param_1[0xf] - local_14);
            goto LAB_0051268c;
          }
          memcpy((void *)(local_14 + param_2),local_2c,param_1[8]);
          local_14 = local_14 + param_1[8];
          if (param_4 != (QObject *)0x0) {
            local_24 = operator_new(0x20);
            local_8._0_1_ = 1;
            pQVar6 = (QEvent *)FUN_0050fec0(0x3f0,local_14,param_1[0xf]);
            local_8 = (uint)local_8._1_3_ << 8;
            QCoreApplication::postEvent(param_4,pQVar6,0);
            FUN_00487020();
          }
          local_18 = local_18 + 1;
        } while (local_18 < (uint)param_1[7]);
      }
    } while ((local_14 < (uint)param_1[0xf]) && (param_3 = param_3 + 1, param_3 < local_20));
  }
LAB_0051268c:
  param_4 = (QObject *)0x0;
LAB_00512693:
  local_8 = 2;
  if (local_28 != (int *)0x0) {
    LOCK();
    iVar2 = local_28[1] + -1;
    local_28[1] = iVar2;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)(*local_28 + 4))();
      LOCK();
      piVar1 = local_28 + 2;
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (**(code **)(*local_28 + 8))();
      }
    }
  }
  ExceptionList = local_10;
  return param_4;
}


