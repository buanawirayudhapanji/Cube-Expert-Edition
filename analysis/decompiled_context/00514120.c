
undefined4 __thiscall
FUN_00514120(int param_1,int param_2,int param_3,int param_4,int param_5,uint param_6,
            QObject *param_7)

{
  int *piVar1;
  undefined2 *puVar2;
  int *piVar3;
  undefined2 *puVar4;
  void *pvVar5;
  char cVar6;
  undefined2 uVar7;
  uint uVar8;
  char *pcVar9;
  uint uVar10;
  QEvent *pQVar11;
  QMessageLogger *this;
  int iVar12;
  uint uVar13;
  undefined4 uVar14;
  uint uVar15;
  size_t sVar16;
  QMessageLogger local_50 [20];
  undefined2 *local_3c;
  int *local_38;
  void *local_34;
  int *local_30;
  uint local_2c;
  int local_28;
  undefined4 local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00561634;
  local_10 = ExceptionList;
  uVar8 = DAT_00759b24 ^ (uint)(local_50 + 0x4c);
  ExceptionList = &local_10;
  local_8 = 0;
  local_24 = 0;
  uVar15 = 0;
  local_1c = 0;
  local_20 = 0;
  if (param_3 - param_2 >> 1 != 0) {
    while( true ) {
      pcVar9 = (char *)QMessageLogger::QMessageLogger(local_50,(char *)0x0,0,(char *)0x0);
      iVar12 = local_1c * 2;
      local_28 = iVar12;
      QMessageLogger::debug
                ((QMessageLogger *)(uint)*(ushort *)(iVar12 + param_2),pcVar9,
                 "Write file block=%d\n",(QMessageLogger *)(uint)*(ushort *)(iVar12 + param_2));
      cVar6 = FUN_005063a0(1,(uint)*(ushort *)(iVar12 + param_2) * *(int *)(param_1 + 0x14) +
                             *(int *)(param_1 + 8));
      if (cVar6 == '\0') break;
      uVar10 = *(uint *)(param_1 + 0x1c);
      uVar13 = 0;
      if (uVar10 != 0) {
        do {
          local_18 = uVar13;
          if (local_1c == 0) {
            if (uVar13 == 0) {
              local_18 = uVar10;
            }
            local_18 = local_18 - 1;
          }
          local_2c = *(uint *)(param_1 + 0x20);
          if (param_6 - uVar15 <= *(uint *)(param_1 + 0x20)) {
            local_2c = param_6 - uVar15;
          }
          local_14 = *(uint *)(param_1 + 0x30);
          if (local_2c % local_14 == 0) {
            cVar6 = FUN_00506590(1,(uint)*(ushort *)(local_28 + param_2) * *(int *)(param_1 + 0x14)
                                   + *(int *)(param_1 + 0x18) * local_18 + *(int *)(param_1 + 8),
                                 param_5 + uVar15,local_2c,0);
            if (cVar6 == '\0') goto LAB_0051438f;
          }
          else {
            sVar16 = (local_14 - local_2c % local_14) + local_2c;
            local_14 = sVar16;
            local_3c = (undefined2 *)FUN_00519367(sVar16);
            FUN_004908a0(local_3c,param_6);
            puVar2 = local_3c;
            local_8._0_1_ = 1;
            memset(local_3c,0,sVar16);
            memcpy(puVar2,(void *)(local_20 + param_5),local_2c);
            cVar6 = FUN_00506590(1,(uint)*(ushort *)(local_28 + param_2) * *(int *)(param_1 + 0x14)
                                   + *(int *)(param_1 + 0x18) * local_18 + *(int *)(param_1 + 8),
                                 puVar2,local_14,0);
            piVar1 = local_38;
            if (cVar6 == '\0') {
              local_8 = CONCAT31(local_8._1_3_,2);
              if (local_38 != (int *)0x0) {
                LOCK();
                iVar12 = local_38[1] + -1;
                local_38[1] = iVar12;
                UNLOCK();
                if (iVar12 == 0) {
                  (**(code **)(*local_38 + 4))();
                  LOCK();
                  piVar1 = local_38 + 2;
                  iVar12 = *piVar1;
                  *piVar1 = *piVar1 + -1;
                  UNLOCK();
                  if (iVar12 == 1) {
                    (**(code **)(*local_38 + 8))();
                  }
                }
              }
LAB_0051438f:
              uVar14 = 4;
              goto LAB_005145e0;
            }
            local_8._0_1_ = 3;
            if (local_38 != (int *)0x0) {
              LOCK();
              iVar12 = local_38[1] + -1;
              local_38[1] = iVar12;
              UNLOCK();
              if (iVar12 == 0) {
                (**(code **)(*local_38 + 4))();
                LOCK();
                piVar3 = piVar1 + 2;
                iVar12 = *piVar3 + -1;
                *piVar3 = iVar12;
                UNLOCK();
                if (iVar12 == 0) {
                  (**(code **)(*piVar1 + 8))();
                }
              }
            }
            local_8 = (uint)local_8._1_3_ << 8;
            uVar15 = local_20;
          }
          uVar15 = uVar15 + local_2c;
          local_20 = uVar15;
          if (param_6 <= uVar15) break;
          uVar10 = *(uint *)(param_1 + 0x1c);
          uVar13 = uVar13 + 1;
        } while (uVar13 < uVar10);
      }
      if (param_7 != (QObject *)0x0) {
        local_30 = operator_new(0x20);
        local_8._0_1_ = 4;
        pQVar11 = (QEvent *)FUN_0050fec0(0x3f0,uVar15,param_6);
        local_8 = (uint)local_8._1_3_ << 8;
        QCoreApplication::postEvent(param_7,pQVar11,0);
        FUN_00487020();
      }
      if ((param_6 <= uVar15) ||
         (local_1c = local_1c + 1, (uint)(param_3 - param_2 >> 1) <= local_1c)) goto LAB_005143a3;
    }
    local_24 = 9;
  }
LAB_005143a3:
  uVar15 = *(int *)(param_1 + 0x10) * 2;
  sVar16 = (uVar15 & 3) + uVar15;
  if ((uVar15 & 3) == 0) {
    sVar16 = uVar15;
  }
  local_34 = (void *)FUN_00519367(sVar16,uVar8);
  FUN_004dd760(local_34,param_6);
  pvVar5 = local_34;
  local_8._0_1_ = 5;
  memset(local_34,0xff,sVar16);
  uVar15 = 0;
  if (param_3 - param_2 >> 1 != 0) {
    do {
      *(undefined2 *)((int)pvVar5 + uVar15 * 2) = *(undefined2 *)(param_2 + uVar15 * 2);
      uVar15 = uVar15 + 1;
    } while (uVar15 < (uint)(param_3 - param_2 >> 1));
  }
  param_7 = (QObject *)(*(int *)(param_1 + 0x38) + 1);
  if (*(uint *)(param_1 + 0x1c) <= param_7) {
    cVar6 = FUN_005063a0(1,*(int *)(param_1 + 0x14) * *(int *)(param_1 + 4) + *(int *)(param_1 + 8))
    ;
    piVar1 = local_30;
    if (cVar6 == '\0') {
      local_8 = CONCAT31(local_8._1_3_,6);
      if (local_30 != (int *)0x0) {
        LOCK();
        iVar12 = local_30[1] + -1;
        local_30[1] = iVar12;
        UNLOCK();
        if (iVar12 == 0) {
          (**(code **)(*local_30 + 4))();
          LOCK();
          piVar3 = piVar1 + 2;
          iVar12 = *piVar3;
          *piVar3 = *piVar3 + -1;
          UNLOCK();
          if (iVar12 == 1) {
            (**(code **)(*piVar1 + 8))();
          }
        }
      }
      uVar14 = 9;
      goto LAB_005145e0;
    }
    param_7 = (QObject *)0x0;
  }
  local_3c = (undefined2 *)FUN_00519367(sVar16 + 9);
  FUN_004908a0(local_3c,param_6);
  puVar4 = local_3c;
  puVar2 = local_3c + 1;
  local_8 = CONCAT31(local_8._1_3_,7);
  *local_3c = 0x4448;
  *(undefined1 *)puVar2 = 0xff;
  *(uint *)((int)local_3c + 3) = param_6 / *(uint *)(param_1 + 0x30);
  memcpy((void *)((int)local_3c + 7),local_34,sVar16);
  uVar7 = FUN_00486d80(puVar2,sVar16 + 5);
  *(undefined2 *)((int)puVar4 + sVar16 + 7) = uVar7;
  cVar6 = FUN_00506590(1,*(int *)(param_1 + 0x18) * (int)param_7 +
                         *(int *)(param_1 + 0x14) * *(int *)(param_1 + 4) + *(int *)(param_1 + 8),
                       puVar4,sVar16 + 9,0);
  piVar1 = local_30;
  if (cVar6 == '\0') {
    local_24 = 4;
  }
  else {
    *(uint *)(param_1 + 0x40) = param_6;
    *(undefined1 *)(param_1 + 0x3c) = 0xff;
    *(void **)(param_1 + 0x44) = local_34;
    if (local_30 != *(int **)(param_1 + 0x48)) {
      if (local_30 != (int *)0x0) {
        LOCK();
        local_30[1] = local_30[1] + 1;
        UNLOCK();
      }
      piVar3 = *(int **)(param_1 + 0x48);
      if (piVar3 != (int *)0x0) {
        LOCK();
        iVar12 = piVar3[1] + -1;
        piVar3[1] = iVar12;
        UNLOCK();
        if (iVar12 == 0) {
          (**(code **)(*piVar3 + 4))();
          LOCK();
          iVar12 = piVar3[2] + -1;
          piVar3[2] = iVar12;
          UNLOCK();
          if (iVar12 == 0) {
            (**(code **)(*piVar3 + 8))();
          }
        }
      }
      *(int **)(param_1 + 0x48) = piVar1;
    }
    *(QObject **)(param_1 + 0x38) = param_7;
    pcVar9 = (char *)QMessageLogger::QMessageLogger(local_50,(char *)0x0,0,(char *)0x0);
    QMessageLogger::debug(this,pcVar9,"File FAT Page=%d\n",param_7);
  }
  local_8._0_1_ = 8;
  if (local_38 != (int *)0x0) {
    LOCK();
    iVar12 = local_38[1] + -1;
    local_38[1] = iVar12;
    UNLOCK();
    if (iVar12 == 0) {
      (**(code **)(*local_38 + 4))();
      LOCK();
      iVar12 = local_38[2] + -1;
      local_38[2] = iVar12;
      UNLOCK();
      if (iVar12 == 0) {
        (**(code **)(*local_38 + 8))();
      }
    }
  }
  local_8 = CONCAT31(local_8._1_3_,9);
  if (piVar1 != (int *)0x0) {
    LOCK();
    iVar12 = piVar1[1] + -1;
    piVar1[1] = iVar12;
    UNLOCK();
    if (iVar12 == 0) {
      (**(code **)(*piVar1 + 4))();
      LOCK();
      piVar3 = piVar1 + 2;
      iVar12 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
      if (iVar12 == 1) {
        (**(code **)(*piVar1 + 8))();
      }
    }
  }
  uVar14 = local_24;
LAB_005145e0:
  if (param_2 != 0) {
    uVar15 = param_4 - param_2 & 0xfffffffe;
    iVar12 = param_2;
    if (0xfff < uVar15) {
      iVar12 = *(int *)(param_2 + -4);
      uVar15 = uVar15 + 0x23;
      if (0x1f < (param_2 - iVar12) - 4U) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
    FUN_00519359(iVar12,uVar15);
  }
  ExceptionList = local_10;
  return uVar14;
}


