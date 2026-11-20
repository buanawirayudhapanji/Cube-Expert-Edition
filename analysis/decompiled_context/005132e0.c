
undefined4 __thiscall
FUN_005132e0(int param_1,int param_2,int param_3,int param_4,int param_5,uint param_6,
            QObject *param_7)

{
  QObject *pQVar1;
  char cVar2;
  uint uVar3;
  QMessageLogger *this;
  int *piVar4;
  int iVar5;
  QEvent *pQVar6;
  char *pcVar7;
  QMessageLogger *this_00;
  QMessageLogger *this_01;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  size_t _Size;
  int *piVar11;
  undefined4 *puVar12;
  QMessageLogger local_4c [20];
  char *local_38;
  int *local_34;
  void *local_30;
  size_t local_2c;
  int *local_28;
  int *local_24;
  undefined4 local_20;
  int *local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0055fed4;
  local_10 = ExceptionList;
  uVar3 = DAT_00759b24 ^ (uint)(local_4c + 0x48);
  ExceptionList = &local_10;
  local_8 = 0;
  local_20 = 0;
  uVar10 = 0;
  local_14 = 0;
  local_18 = 0;
  if (param_3 - param_2 >> 1 != 0) {
    while( true ) {
      uVar8 = local_18;
      this = (QMessageLogger *)QMessageLogger::QMessageLogger(local_4c,(char *)0x0,0,(char *)0x0);
      QMessageLogger::debug
                (this,(char *)this,"Write file block=%d\n",(uint)*(ushort *)(param_2 + uVar8 * 2),
                 uVar3);
      cVar2 = FUN_005063a0(1,(uint)*(ushort *)(param_2 + uVar8 * 2) * *(int *)(param_1 + 0x14) +
                             *(int *)(param_1 + 8));
      if (cVar2 == '\0') break;
      piVar4 = *(int **)(param_1 + 0x1c);
      local_28 = (int *)0x0;
      if (piVar4 != (int *)0x0) {
        do {
          piVar11 = local_28;
          local_1c = local_28;
          if (local_18 == 0) {
            if (local_28 == (int *)0x0) {
              local_1c = (int *)((int)piVar4 + -1);
            }
            else {
              local_1c = (int *)((int)local_28 + -1);
            }
          }
          piVar4 = *(int **)(param_1 + 0x20);
          if ((int *)(param_6 - uVar10) <= *(int **)(param_1 + 0x20)) {
            piVar4 = (int *)(param_6 - uVar10);
          }
          uVar10 = (uint)piVar4 % *(uint *)(param_1 + 0x30);
          local_24 = piVar4;
          if (uVar10 == 0) {
            iVar5 = FUN_005066c0(1,*(int *)(param_1 + 0x18) * (int)local_1c +
                                   *(int *)(param_1 + 0x14) *
                                   (uint)*(ushort *)(param_2 + local_18 * 2) + *(int *)(param_1 + 8)
                                 ,local_14 + param_5,piVar4,0);
            if (iVar5 != 1) goto LAB_0051355f;
          }
          else {
            _Size = (int)piVar4 + (*(uint *)(param_1 + 0x30) - uVar10);
            local_2c = _Size;
            local_38 = (char *)FUN_00519367(_Size);
            FUN_004908a0(local_38,param_6);
            pcVar7 = local_38;
            local_8._0_1_ = 1;
            memset(local_38,0,_Size);
            memcpy(pcVar7,(void *)(local_14 + param_5),(size_t)local_24);
            iVar5 = FUN_005066c0(1,*(int *)(param_1 + 0x18) * (int)local_1c +
                                   *(int *)(param_1 + 0x14) *
                                   (uint)*(ushort *)(param_2 + local_18 * 2) + *(int *)(param_1 + 8)
                                 ,pcVar7,local_2c,0);
            piVar4 = local_34;
            if (iVar5 != 1) {
              local_8 = CONCAT31(local_8._1_3_,2);
              if (local_34 != (int *)0x0) {
                LOCK();
                iVar5 = local_34[1] + -1;
                local_34[1] = iVar5;
                UNLOCK();
                if (iVar5 == 0) {
                  (**(code **)(*local_34 + 4))();
                  LOCK();
                  piVar11 = piVar4 + 2;
                  iVar5 = *piVar11;
                  *piVar11 = *piVar11 + -1;
                  UNLOCK();
                  if (iVar5 == 1) {
                    (**(code **)(*piVar4 + 8))();
                  }
                }
              }
LAB_0051355f:
              uVar9 = 4;
              goto LAB_005137f0;
            }
            local_8._0_1_ = 3;
            if (local_34 != (int *)0x0) {
              LOCK();
              iVar5 = local_34[1] + -1;
              local_34[1] = iVar5;
              UNLOCK();
              if (iVar5 == 0) {
                (**(code **)(*local_34 + 4))();
                LOCK();
                iVar5 = piVar4[2] + -1;
                piVar4[2] = iVar5;
                UNLOCK();
                if (iVar5 == 0) {
                  (**(code **)(*piVar4 + 8))();
                }
              }
            }
            local_8 = (uint)local_8._1_3_ << 8;
            piVar4 = local_24;
            piVar11 = local_28;
          }
          uVar10 = local_14 + (int)piVar4;
          local_14 = uVar10;
          if (param_6 <= uVar10) break;
          piVar4 = *(int **)(param_1 + 0x1c);
          local_28 = (int *)((int)piVar11 + 1);
        } while (local_28 < piVar4);
      }
      pQVar1 = param_7;
      if (param_7 != (QObject *)0x0) {
        local_30 = operator_new(0x20);
        local_8._0_1_ = 4;
        pQVar6 = (QEvent *)FUN_0050fec0(0x3f0,uVar10,param_6);
        local_8 = (uint)local_8._1_3_ << 8;
        QCoreApplication::postEvent(pQVar1,pQVar6,0);
        FUN_00487020();
      }
      if ((param_6 <= uVar10) ||
         (local_18 = local_18 + 1, (uint)(param_3 - param_2 >> 1) <= local_18)) goto LAB_00513570;
    }
    local_20 = 9;
  }
LAB_00513570:
  pcVar7 = operator_new(0xa40);
  local_8._0_1_ = 5;
  local_34 = operator_new(0x10);
  local_34[0] = 0;
  local_34[1] = 0;
  param_7 = (QObject *)(local_34 + 1);
  local_34[2] = 0;
  *(int *)param_7 = 1;
  local_24 = local_34 + 2;
  *local_24 = 1;
  *local_34 = (int)std::_Ref_count<CLooperSongOld::SOldLoopSongData>::vftable;
  local_34[3] = (int)pcVar7;
  local_38 = pcVar7;
  local_28 = local_34;
  FUN_00519359(0,0xa40);
  local_8 = CONCAT31(local_8._1_3_,6);
  memset(pcVar7,0xff,0xa40);
  *(undefined4 *)pcVar7 = s_looper_005941fc._0_4_;
  *(undefined2 *)(pcVar7 + 4) = s_looper_005941fc._4_2_;
  pcVar7[6] = s_looper_005941fc[6];
  *(undefined4 *)(pcVar7 + 0xa38) = s_looper_005941fc._0_4_;
  *(undefined2 *)(pcVar7 + 0xa3c) = s_looper_005941fc._4_2_;
  pcVar7[0xa3e] = s_looper_005941fc[6];
  pcVar7[8] = '\x01';
  pcVar7[10] = '\0';
  pcVar7[0xb] = '\0';
  uVar3 = *(uint *)(param_1 + 0x30);
  uVar10 = param_6 / uVar3 + 1;
  if (param_6 % uVar3 == 0) {
    uVar10 = param_6 / uVar3;
  }
  uVar8 = uVar10 - 1;
  if (uVar10 == 0) {
    uVar8 = 0;
  }
  uVar3 = *(uint *)(param_1 + 0x20) / uVar3;
  uVar10 = *(int *)(param_1 + 0x1c) * uVar3;
  *(short *)(pcVar7 + 0xc) = (short)(uVar8 / uVar10);
  uVar8 = uVar8 % uVar10;
  pcVar7[0xe] = (char)(uVar8 / uVar3);
  uVar10 = 0;
  pcVar7[0xf] = (char)(uVar8 % uVar3);
  if (param_3 - param_2 >> 1 != 0) {
    do {
      *(undefined2 *)(pcVar7 + uVar10 * 2 + 0x10) = *(undefined2 *)(param_2 + uVar10 * 2);
      uVar10 = uVar10 + 1;
    } while (uVar10 < (uint)(param_3 - param_2 >> 1));
  }
  param_6 = *(int *)(param_1 + 0xa78) + 2;
  if (*(uint *)(param_1 + 0x1c) <= param_6) {
    cVar2 = FUN_005063a0(1,*(int *)(param_1 + 0x14) * *(int *)(param_1 + 4) + *(int *)(param_1 + 8))
    ;
    piVar4 = local_28;
    if (cVar2 == '\0') {
      LOCK();
      iVar5 = *(int *)param_7;
      *(int *)param_7 = iVar5 + -1;
      UNLOCK();
      if (iVar5 + -1 == 0) {
        (**(code **)*local_28)();
        LOCK();
        iVar5 = *local_24;
        *local_24 = *local_24 + -1;
        UNLOCK();
        if (iVar5 == 1) {
          (**(code **)(*piVar4 + 4))();
        }
      }
      uVar9 = 9;
      goto LAB_005137f0;
    }
    param_6 = 0;
  }
  cVar2 = FUN_00506590(1,*(int *)(param_1 + 0x18) * param_6 +
                         *(int *)(param_1 + 4) * *(int *)(param_1 + 0x14) + *(int *)(param_1 + 8),
                       pcVar7,0xa40,0);
  uVar3 = param_6;
  if (cVar2 == '\0') {
    local_20 = 4;
  }
  else {
    puVar12 = (undefined4 *)(param_1 + 0x38);
    for (iVar5 = 0x290; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar12 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      puVar12 = puVar12 + 1;
    }
    *(uint *)(param_1 + 0xa78) = param_6;
    pcVar7 = (char *)QMessageLogger::QMessageLogger(local_4c,(char *)0x0,0,(char *)0x0);
    QMessageLogger::debug(this_00,pcVar7,"File FAT Page=%d\n",uVar3);
  }
  piVar4 = local_28;
  local_8 = local_8 & 0xffffff00;
  LOCK();
  iVar5 = *(int *)param_7;
  *(int *)param_7 = iVar5 + -1;
  UNLOCK();
  if (iVar5 + -1 == 0) {
    (**(code **)*local_28)();
    LOCK();
    iVar5 = *local_24;
    *local_24 = *local_24 + -1;
    UNLOCK();
    if (iVar5 == 1) {
      (**(code **)(*piVar4 + 4))();
    }
  }
  param_6 = 0;
  uVar3 = 0x10000;
  do {
    cVar2 = FUN_005063a0(0,uVar3);
    if (cVar2 == '\0') {
      pcVar7 = (char *)QMessageLogger::QMessageLogger(local_4c,(char *)0x0,0,(char *)0x0);
      QMessageLogger::debug(this_01,pcVar7,"write_song_file_flag erase failed,Addr=0x%.8x",uVar3);
      goto LAB_0051383e;
    }
    uVar3 = uVar3 + 0x800;
  } while (uVar3 < 0x18000);
  cVar2 = FUN_00506590(0,0x10000,&param_6,2,0);
  if (cVar2 == '\0') {
LAB_0051383e:
    uVar9 = 0xb;
  }
  else {
    uVar9 = local_20;
  }
LAB_005137f0:
  if (param_2 != 0) {
    uVar3 = param_4 - param_2 & 0xfffffffe;
    iVar5 = param_2;
    if (0xfff < uVar3) {
      iVar5 = *(int *)(param_2 + -4);
      uVar3 = uVar3 + 0x23;
      if (0x1f < (param_2 - iVar5) - 4U) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
    FUN_00519359(iVar5,uVar3);
  }
  ExceptionList = local_10;
  return uVar9;
}


