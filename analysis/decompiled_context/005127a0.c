
undefined4 __thiscall
FUN_005127a0(int param_1,int param_2,int param_3,int param_4,int param_5,uint param_6,
            QObject *param_7)

{
  uint *_Dst;
  void *pvVar1;
  uint *puVar2;
  char cVar3;
  uint uVar4;
  char *pcVar5;
  QEvent *pQVar6;
  QMessageLogger *this;
  int *piVar7;
  QMessageLogger *this_00;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  size_t _Size;
  QMessageLogger local_5c [20];
  void *local_48;
  int *local_44;
  uint *local_40;
  void *local_3c;
  int local_38;
  int *local_34;
  int *local_30;
  size_t local_2c;
  undefined4 local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0055f2f4;
  local_10 = ExceptionList;
  uVar4 = DAT_00759b24 ^ (uint)(local_5c + 0x58);
  ExceptionList = &local_10;
  local_8 = 0;
  local_28 = 0;
  uVar11 = 0;
  local_18 = 0;
  local_14 = 0;
  local_1c = param_1;
  if (param_3 - param_2 >> 1 != 0) {
LAB_005127f0:
    pcVar5 = (char *)QMessageLogger::QMessageLogger(local_5c,(char *)0x0,0,(char *)0x0);
    this = (QMessageLogger *)(uint)*(ushort *)(param_2 + local_18 * 2);
    QMessageLogger::debug(this,pcVar5,"Write file block=%d\n",this);
    cVar3 = FUN_005063a0(1,(uint)*(ushort *)(param_2 + local_18 * 2) * *(int *)(param_1 + 0x14) +
                           *(int *)(param_1 + 8));
    if (cVar3 == '\0') {
      local_28 = 9;
    }
    else {
      local_20 = 0;
      iVar9 = *(int *)(*(int *)(param_1 + 0x34) + 0x2ca68);
      if (*(int *)(param_1 + 0x1c) != 0) {
LAB_00512877:
        local_24 = *(uint *)(param_1 + 0x20);
        if (param_6 - local_14 <= *(uint *)(param_1 + 0x20)) {
          local_24 = param_6 - local_14;
        }
        local_2c = 0;
        uVar11 = local_24 % *(uint *)(param_1 + 0x30);
        if (uVar11 == 0) {
          piVar7 = (int *)(param_1 + 0x18);
          iVar8 = local_14 + param_5;
          local_38 = iVar8;
          local_34 = piVar7;
          do {
            local_2c = local_2c + 1;
            if (iVar9 == 0x28b9) {
LAB_00512a4f:
              cVar3 = FUN_00506590(1,(uint)*(ushort *)(param_2 + local_18 * 2) *
                                     *(int *)(local_1c + 0x14) + *piVar7 * local_20 +
                                     *(int *)(local_1c + 8),iVar8,local_24,0);
              uVar11 = (uint)(cVar3 != '\0');
              iVar8 = local_14 + param_5;
              piVar7 = (int *)(local_1c + 0x18);
            }
            else {
              piVar7 = local_34;
              iVar8 = local_38;
              if (iVar9 == 0x291d) goto LAB_00512a4f;
              if (iVar9 == 0x2981) goto LAB_00512a4f;
              if (iVar9 == 0x291e) goto LAB_00512a4f;
              if (iVar9 == 0x291f) goto LAB_00512a4f;
              if (iVar9 == 0x2921) goto LAB_00512a4f;
              local_30 = (int *)(local_1c + 0x18);
              iVar8 = local_14 + param_5;
              uVar11 = FUN_005066c0(1,*local_30 * local_20 +
                                      *(int *)(local_1c + 0x14) *
                                      (uint)*(ushort *)(param_2 + local_18 * 2) +
                                      *(int *)(local_1c + 8),iVar8,local_24,0);
              piVar7 = local_30;
            }
            if (uVar11 == 1) goto LAB_00512aaf;
            if (9 < (int)local_2c) {
              uVar10 = FUN_00513910(uVar11);
              local_28 = uVar10;
              goto LAB_00512d32;
            }
          } while( true );
        }
        local_2c = (local_24 - uVar11) + *(uint *)(param_1 + 0x30);
        local_48 = (void *)FUN_00519367(local_2c);
        FUN_004908a0(local_48,param_6);
        local_8 = CONCAT31(local_8._1_3_,1);
        memset(local_48,0,local_2c);
        memcpy(local_48,(void *)(local_14 + param_5),local_24);
        if ((((iVar9 == 0x28b9) || (iVar9 == 0x291d)) || (iVar9 == 0x2981)) ||
           (((iVar9 == 0x291e || (iVar9 == 0x291f)) || (iVar9 == 0x2921)))) {
          cVar3 = FUN_00506590(1,(uint)*(ushort *)(param_2 + local_18 * 2) *
                                 *(int *)(param_1 + 0x14) + *(int *)(param_1 + 0x18) * local_20 +
                                 *(int *)(param_1 + 8),local_48,local_2c,0);
          uVar11 = (uint)(cVar3 != '\0');
        }
        else {
          uVar11 = FUN_005066c0(1,(uint)*(ushort *)(param_2 + local_18 * 2) *
                                  *(int *)(param_1 + 0x14) + *(int *)(param_1 + 0x18) * local_20 +
                                  *(int *)(param_1 + 8),local_48,local_2c,0);
        }
        if (uVar11 == 1) {
          local_8._0_1_ = 3;
          if (local_44 != (int *)0x0) {
            LOCK();
            iVar8 = local_44[1] + -1;
            local_44[1] = iVar8;
            UNLOCK();
            if (iVar8 == 0) {
              (**(code **)(*local_44 + 4))();
              LOCK();
              iVar8 = local_44[2] + -1;
              local_44[2] = iVar8;
              UNLOCK();
              if (iVar8 == 0) {
                (**(code **)(*local_44 + 8))();
              }
            }
          }
          local_8 = (uint)local_8._1_3_ << 8;
          goto LAB_00512ab2;
        }
        local_8 = CONCAT31(local_8._1_3_,2);
        if (local_44 != (int *)0x0) {
          LOCK();
          iVar9 = local_44[1] + -1;
          local_44[1] = iVar9;
          UNLOCK();
          if (iVar9 == 0) {
            (**(code **)(*local_44 + 4))();
            LOCK();
            piVar7 = local_44 + 2;
            iVar9 = *piVar7;
            *piVar7 = *piVar7 + -1;
            UNLOCK();
            if (iVar9 == 1) {
              (**(code **)(*local_44 + 8))();
            }
          }
        }
        local_28 = 0;
        uVar10 = 0;
        goto LAB_00512d32;
      }
      if (uVar11 < param_6) goto LAB_00512b1f;
    }
  }
LAB_00512b8a:
  uVar11 = *(int *)(param_1 + 0x10) * 2;
  _Size = (uVar11 & 3) + uVar11;
  if ((uVar11 & 3) == 0) {
    _Size = uVar11;
  }
  local_48 = (void *)FUN_00519367(_Size,uVar4);
  FUN_004dd760(local_48,param_6);
  pvVar1 = local_48;
  local_8 = CONCAT31(local_8._1_3_,5);
  memset(local_48,0xff,_Size);
  uVar11 = 0;
  if (param_3 - param_2 >> 1 != 0) {
    do {
      *(undefined2 *)((int)pvVar1 + uVar11 * 2) = *(undefined2 *)(param_2 + uVar11 * 2);
      uVar11 = uVar11 + 1;
    } while (uVar11 < (uint)(param_3 - param_2 >> 1));
  }
  param_7 = *(QObject **)(param_1 + 0x38);
  if (*(uint *)(param_1 + 0x1c) <= param_7) {
    cVar3 = FUN_005063a0(1,*(int *)(param_1 + 0x14) * *(int *)(param_1 + 4) + *(int *)(param_1 + 8))
    ;
    if (cVar3 == '\0') {
      FUN_00490cd0();
      uVar10 = 9;
      goto LAB_00512d32;
    }
    param_7 = (QObject *)0x0;
  }
  local_40 = (uint *)FUN_00519367(_Size + 8);
  FUN_004908a0(local_40,param_6);
  puVar2 = local_40;
  local_8 = CONCAT31(local_8._1_3_,6);
  _Dst = local_40 + 1;
  *local_40 = param_6 / *(uint *)(param_1 + 0x30);
  memcpy(_Dst,local_48,_Size);
  uVar10 = FUN_00486e50(_Dst,_Size);
  iVar9 = local_1c;
  *(undefined4 *)(_Size + (int)_Dst) = uVar10;
  FUN_005063a0(1,*(int *)(local_1c + 0x18) * (int)param_7 +
                 *(int *)(local_1c + 4) * *(int *)(local_1c + 0x14) + *(int *)(local_1c + 8));
  cVar3 = FUN_00506590(1,*(int *)(iVar9 + 0x18) * (int)param_7 +
                         *(int *)(iVar9 + 0x14) * *(int *)(iVar9 + 4) + *(int *)(iVar9 + 8),puVar2,
                       _Size + 8,0);
  if (cVar3 == '\0') {
    uVar10 = 4;
  }
  else {
    *(uint *)(iVar9 + 0x3c) = param_6;
    FUN_004dd820(&local_48);
    *(QObject **)(iVar9 + 0x38) = param_7;
    pcVar5 = (char *)QMessageLogger::QMessageLogger(local_5c,(char *)0x0,0,(char *)0x0);
    QMessageLogger::debug(this_00,pcVar5,"File FAT Page=%d\n",param_7);
    uVar10 = local_28;
  }
  FUN_00490cd0();
  FUN_00490cd0();
LAB_00512d32:
  if (param_2 != 0) {
    uVar11 = param_4 - param_2 & 0xfffffffe;
    iVar9 = param_2;
    if (0xfff < uVar11) {
      iVar9 = *(int *)(param_2 + -4);
      uVar11 = uVar11 + 0x23;
      if (0x1f < (param_2 - iVar9) - 4U) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
    FUN_00519359(iVar9,uVar11);
  }
  ExceptionList = local_10;
  return uVar10;
LAB_00512aaf:
  param_1 = local_1c;
LAB_00512ab2:
  local_14 = local_14 + local_24;
  if (param_6 <= local_14) goto LAB_00512b8a;
  if (param_7 != (QObject *)0x0) {
    local_3c = operator_new(0x20);
    local_8._0_1_ = 4;
    pQVar6 = (QEvent *)FUN_0050fec0(0x3f0,local_14,param_6);
    local_8 = (uint)local_8._1_3_ << 8;
    QCoreApplication::postEvent(param_7,pQVar6,0);
    FUN_00487020();
  }
  local_20 = local_20 + 1;
  if (*(uint *)(param_1 + 0x1c) <= local_20) goto code_r0x00512b15;
  goto LAB_00512877;
code_r0x00512b15:
  uVar11 = local_14;
LAB_00512b1f:
  local_18 = local_18 + 1;
  if ((uint)(param_3 - param_2 >> 1) <= local_18) goto LAB_00512b8a;
  goto LAB_005127f0;
}


