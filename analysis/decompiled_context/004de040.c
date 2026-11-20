
/* WARNING: Switch with 1 destination removed at 0x004de2c8 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_004de040(int *param_1,int param_2,int param_3,int param_4,int param_5,uint param_6,
            QObject *param_7)

{
  int *piVar1;
  int *piVar2;
  uint *_Dst;
  void *pvVar3;
  char cVar4;
  uint uVar5;
  char *pcVar6;
  QEvent *pQVar7;
  QMessageLogger *this;
  QMessageLogger *this_00;
  uint uVar8;
  size_t sVar9;
  uint uVar10;
  undefined4 uVar11;
  int iVar12;
  QMessageLogger local_48 [20];
  uint *local_34;
  int *local_30;
  void *local_2c;
  void *local_28;
  uint *local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0053e244;
  local_10 = ExceptionList;
  uVar5 = DAT_00759b24 ^ (uint)(local_48 + 0x44);
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = 0;
  uVar8 = 0;
  local_18 = 0;
  local_1c = 0;
  if (param_3 - param_2 >> 1 != 0) {
    do {
      pcVar6 = (char *)QMessageLogger::QMessageLogger(local_48,(char *)0x0,0,(char *)0x0);
      this = (QMessageLogger *)(uint)*(ushort *)(param_2 + local_18 * 2);
      QMessageLogger::debug(this,pcVar6,"Write file block=%d\n",this);
      cVar4 = FUN_005063a0(1,param_1[4] * (uint)*(ushort *)(param_2 + local_18 * 2) + param_1[1]);
      if (cVar4 == '\0') {
        local_14 = 9;
        break;
      }
      local_20 = 0;
      if (param_1[6] == 0) {
        if (param_6 <= uVar8) break;
      }
      else {
        do {
          uVar10 = local_1c;
          local_24 = (uint *)param_1[7];
          if ((uint *)(param_6 - uVar8) <= (uint *)param_1[7]) {
            local_24 = (uint *)(param_6 - uVar8);
          }
          uVar8 = (uint)local_24 % (uint)param_1[0xb];
          iVar12 = 0;
          if (uVar8 == 0) {
            while( true ) {
              iVar12 = iVar12 + 1;
              cVar4 = FUN_00506590(1,(uint)*(ushort *)(param_2 + local_18 * 2) * param_1[4] +
                                     param_1[5] * local_20 + param_1[1],param_5 + uVar10,local_24,0)
              ;
              if (cVar4 != '\0') break;
              if (9 < iVar12) {
                local_14 = 4;
                uVar11 = 4;
                goto LAB_004de49c;
              }
            }
          }
          else {
            sVar9 = (param_1[0xb] - uVar8) + (int)local_24;
            local_34 = (uint *)FUN_00519367(sVar9);
            FUN_004908a0(local_34,param_6);
            _Dst = local_34;
            local_8._0_1_ = 1;
            memset(local_34,0,sVar9);
            memcpy(_Dst,(void *)(local_1c + param_5),(size_t)local_24);
            cVar4 = FUN_00506590(1,(uint)*(ushort *)(param_2 + local_18 * 2) * param_1[4] +
                                   param_1[5] * local_20 + param_1[1],_Dst,sVar9,0);
            piVar2 = local_30;
            if (cVar4 == '\0') {
              local_8 = CONCAT31(local_8._1_3_,2);
              if (local_30 != (int *)0x0) {
                LOCK();
                iVar12 = local_30[1] + -1;
                local_30[1] = iVar12;
                UNLOCK();
                if (iVar12 == 0) {
                  (**(code **)(*local_30 + 4))();
                  LOCK();
                  piVar2 = local_30 + 2;
                  iVar12 = *piVar2;
                  *piVar2 = *piVar2 + -1;
                  UNLOCK();
                  if (iVar12 == 1) {
                    (**(code **)(*local_30 + 8))();
                  }
                }
              }
              local_14 = 0;
              uVar11 = 0;
              goto LAB_004de49c;
            }
            local_8._0_1_ = 3;
            if (local_30 != (int *)0x0) {
              LOCK();
              iVar12 = local_30[1] + -1;
              local_30[1] = iVar12;
              UNLOCK();
              if (iVar12 == 0) {
                (**(code **)(*local_30 + 4))();
                LOCK();
                piVar1 = piVar2 + 2;
                iVar12 = *piVar1 + -1;
                *piVar1 = iVar12;
                UNLOCK();
                if (iVar12 == 0) {
                  (**(code **)(*piVar2 + 8))();
                }
              }
            }
            local_8 = (uint)local_8._1_3_ << 8;
            uVar10 = local_1c;
          }
          uVar8 = uVar10 + (int)local_24;
          local_1c = uVar8;
          if (param_6 <= uVar8) goto LAB_004de312;
          if (param_7 != (QObject *)0x0) {
            local_28 = operator_new(0x20);
            local_8._0_1_ = 4;
            pQVar7 = (QEvent *)FUN_0050fec0(0x3f0,uVar8,param_6);
            local_8 = (uint)local_8._1_3_ << 8;
            QCoreApplication::postEvent(param_7,pQVar7,0);
            FUN_00487020();
          }
          local_20 = local_20 + 1;
        } while (local_20 < (uint)param_1[6]);
      }
      local_18 = local_18 + 1;
    } while (local_18 < (uint)(param_3 - param_2 >> 1));
  }
LAB_004de312:
  sVar9 = param_1[3] * 2;
  local_2c = (void *)FUN_00519367(param_1[3] * 2,uVar5);
  FUN_004dd760(local_2c,param_6);
  pvVar3 = local_2c;
  local_8 = CONCAT31(local_8._1_3_,5);
  memset(local_2c,0xff,sVar9);
  uVar5 = 0;
  if (param_3 - param_2 >> 1 != 0) {
    do {
      *(undefined2 *)((int)pvVar3 + uVar5 * 2) = *(undefined2 *)(param_2 + uVar5 * 2);
      uVar5 = uVar5 + 1;
    } while (uVar5 < (uint)(param_3 - param_2 >> 1));
  }
  uVar5 = param_1[0xe] + 1;
  if ((uint)param_1[6] <= uVar5) {
    cVar4 = FUN_005063a0(1,param_1[4] * *param_1 + param_1[1]);
    if (cVar4 == '\0') {
      FUN_00490cd0();
      uVar11 = 9;
      goto LAB_004de49c;
    }
    uVar5 = 0;
  }
  param_7 = (QObject *)(sVar9 + 8);
  if ((*(byte *)(param_1 + 3) & 1) != 0) {
    param_7 = (QObject *)(sVar9 + 10);
  }
  local_34 = (uint *)FUN_00519367(param_7);
  FUN_004908a0(local_34,param_6);
  local_8 = CONCAT31(local_8._1_3_,6);
  *local_34 = param_6 / (uint)param_1[0xb];
  local_24 = local_34 + 1;
  memcpy(local_24,local_2c,sVar9);
  param_5 = sVar9 + 4;
  if ((*(byte *)(param_1 + 3) & 1) != 0) {
    param_5 = sVar9 + 6;
  }
  uVar11 = FUN_00486e50(local_24,sVar9);
  *(undefined4 *)((int)local_34 + param_5) = uVar11;
  cVar4 = FUN_00506590(1,param_1[5] * uVar5 + param_1[4] * *param_1 + param_1[1],local_34,param_7,0)
  ;
  if (cVar4 == '\0') {
    uVar11 = 4;
  }
  else {
    param_1[0xd] = param_6;
    FUN_004dd820(&local_2c);
    param_1[0xe] = uVar5;
    pcVar6 = (char *)QMessageLogger::QMessageLogger(local_48,(char *)0x0,0,(char *)0x0);
    QMessageLogger::debug(this_00,pcVar6,"File FAT Page=%d\n",uVar5);
    uVar11 = local_14;
  }
  FUN_00490cd0();
  FUN_00490cd0();
LAB_004de49c:
  if (param_2 != 0) {
    uVar5 = param_4 - param_2 & 0xfffffffe;
    iVar12 = param_2;
    if (0xfff < uVar5) {
      iVar12 = *(int *)(param_2 + -4);
      uVar5 = uVar5 + 0x23;
      if (0x1f < (param_2 - iVar12) - 4U) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
    FUN_00519359(iVar12,uVar5);
  }
  ExceptionList = local_10;
  return uVar11;
}


