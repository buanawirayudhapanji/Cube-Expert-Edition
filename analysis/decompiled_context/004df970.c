
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x004dfb57) */
/* WARNING: Removing unreachable block (ram,0x004dfb16) */
/* WARNING: Removing unreachable block (ram,0x004dfa45) */
/* WARNING: Removing unreachable block (ram,0x004df9fd) */
/* WARNING: Removing unreachable block (ram,0x004df9ec) */
/* WARNING: Removing unreachable block (ram,0x004dfa50) */
/* WARNING: Removing unreachable block (ram,0x004dfa64) */
/* WARNING: Removing unreachable block (ram,0x004dfa66) */
/* WARNING: Removing unreachable block (ram,0x004dfb05) */
/* WARNING: Removing unreachable block (ram,0x004dfb64) */
/* WARNING: Removing unreachable block (ram,0x004dfb78) */
/* WARNING: Removing unreachable block (ram,0x004dfb7a) */

undefined4 FUN_004df970(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char cVar6;
  char *pcVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  byte ******ppppppbVar16;
  byte ******ppppppbVar17;
  uint uVar18;
  bool bVar19;
  undefined4 in_stack_ffffff58;
  uint uStack_90;
  byte ******local_48 [4];
  uint local_38;
  uint local_34;
  byte ******local_30 [4];
  uint local_20;
  uint local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  byte *****local_8;
  
  puStack_c = &LAB_0053f2b3;
  local_10 = ExceptionList;
  uStack_90 = DAT_00759b24 ^ (uint)(local_30 + 0xb);
  local_14 = (undefined1 *)&uStack_90;
  ExceptionList = &local_10;
  local_8 = (byte *****)0x0;
  local_18 = uStack_90;
  operator_new(8);
  local_8._0_1_ = 1;
  pcVar7 = (char *)FUN_00484800(0x20);
  uVar5 = s_RtMidi_Input_Client_00580f78._12_4_;
  uVar4 = s_RtMidi_Input_Client_00580f78._8_4_;
  uVar3 = s_RtMidi_Input_Client_00580f78._4_4_;
  *(undefined4 *)pcVar7 = s_RtMidi_Input_Client_00580f78._0_4_;
  *(undefined4 *)(pcVar7 + 4) = uVar3;
  *(undefined4 *)(pcVar7 + 8) = uVar4;
  *(undefined4 *)(pcVar7 + 0xc) = uVar5;
  *(undefined2 *)(pcVar7 + 0x10) = s_RtMidi_Input_Client_00580f78._16_2_;
  pcVar7[0x12] = s_RtMidi_Input_Client_00580f78[0x12];
  pcVar7[0x13] = '\0';
  piVar8 = (int *)FUN_0048a6b0(0,pcVar7,in_stack_ffffff58);
  local_8._0_1_ = 2;
  piVar9 = operator_new(0x10);
  piVar9[1] = 1;
  piVar9[2] = 1;
  *piVar9 = (int)std::_Ref_count<RtMidiIn>::vftable;
  piVar9[3] = (int)piVar8;
  local_8._0_1_ = 3;
  operator_new(8);
  local_8._0_1_ = 4;
  pcVar7 = (char *)FUN_00484800(0x20);
  uVar5 = s_RtMidi_Output_Client_00580f8c._12_4_;
  uVar4 = s_RtMidi_Output_Client_00580f8c._8_4_;
  uVar3 = s_RtMidi_Output_Client_00580f8c._4_4_;
  *(undefined4 *)pcVar7 = s_RtMidi_Output_Client_00580f8c._0_4_;
  *(undefined4 *)(pcVar7 + 4) = uVar3;
  *(undefined4 *)(pcVar7 + 8) = uVar4;
  *(undefined4 *)(pcVar7 + 0xc) = uVar5;
  *(undefined4 *)(pcVar7 + 0x10) = s_RtMidi_Output_Client_00580f8c._16_4_;
  pcVar7[0x14] = '\0';
  piVar10 = (int *)FUN_0048a920(0,pcVar7);
  local_8._0_1_ = 5;
  piVar11 = operator_new(0x10);
  piVar11[1] = 1;
  piVar11[2] = 1;
  *piVar11 = (int)std::_Ref_count<RtMidiOut>::vftable;
  piVar11[3] = (int)piVar10;
  local_8 = (byte *****)CONCAT31(local_8._1_3_,6);
  uVar12 = (**(code **)(*piVar8 + 8))();
  uVar13 = (**(code **)(*piVar10 + 8))();
  uVar15 = 0;
  do {
    if (uVar12 <= uVar15) {
      if (piVar11 != (int *)0x0) {
        LOCK();
        iVar1 = piVar11[1] + -1;
        piVar11[1] = iVar1;
        UNLOCK();
        if (iVar1 == 0) {
          (**(code **)*piVar11)();
          LOCK();
          iVar1 = piVar11[2] + -1;
          piVar11[2] = iVar1;
          UNLOCK();
          if (iVar1 == 0) {
            (**(code **)(*piVar11 + 4))();
          }
        }
      }
      if (piVar9 != (int *)0x0) {
        LOCK();
        iVar1 = piVar9[1] + -1;
        piVar9[1] = iVar1;
        UNLOCK();
        if (iVar1 == 0) {
          (**(code **)*piVar9)();
          LOCK();
          piVar8 = piVar9 + 2;
          iVar1 = *piVar8;
          *piVar8 = *piVar8 + -1;
          UNLOCK();
          if (iVar1 == 1) {
            (**(code **)(*piVar9 + 4))();
          }
        }
      }
      ExceptionList = local_10;
      return 0;
    }
    (**(code **)(*piVar8 + 0xc))(local_48,uVar15);
    local_8._0_1_ = 7;
    for (uVar18 = 0; uVar18 < uVar13; uVar18 = uVar18 + 1) {
      (**(code **)(*piVar10 + 0xc))(local_30,uVar18);
      ppppppbVar16 = (byte ******)local_30;
      if (0xf < local_1c) {
        ppppppbVar16 = local_30[0];
      }
      local_8._0_1_ = 8;
      ppppppbVar17 = (byte ******)local_48;
      if (0xf < local_34) {
        ppppppbVar17 = local_48[0];
      }
      uVar14 = local_38;
      if (local_38 == local_20) {
        while (uVar2 = uVar14 - 4, 3 < uVar14) {
          if (*ppppppbVar17 != *ppppppbVar16) goto LAB_004dfc76;
          ppppppbVar17 = ppppppbVar17 + 1;
          ppppppbVar16 = ppppppbVar16 + 1;
          uVar14 = uVar2;
        }
        if (uVar2 == 0xfffffffc) {
LAB_004dfcaa:
          uVar14 = 0;
        }
        else {
LAB_004dfc76:
          bVar19 = *(byte *)ppppppbVar17 < *(byte *)ppppppbVar16;
          if ((*(byte *)ppppppbVar17 == *(byte *)ppppppbVar16) &&
             ((uVar2 == 0xfffffffd ||
              ((bVar19 = *(byte *)((int)ppppppbVar17 + 1) < *(byte *)((int)ppppppbVar16 + 1),
               *(byte *)((int)ppppppbVar17 + 1) == *(byte *)((int)ppppppbVar16 + 1) &&
               ((uVar2 == 0xfffffffe ||
                ((bVar19 = *(byte *)((int)ppppppbVar17 + 2) < *(byte *)((int)ppppppbVar16 + 2),
                 *(byte *)((int)ppppppbVar17 + 2) == *(byte *)((int)ppppppbVar16 + 2) &&
                 ((uVar2 == 0xffffffff ||
                  (bVar19 = *(byte *)((int)ppppppbVar17 + 3) < *(byte *)((int)ppppppbVar16 + 3),
                  *(byte *)((int)ppppppbVar17 + 3) == *(byte *)((int)ppppppbVar16 + 3)))))))))))))
          goto LAB_004dfcaa;
          uVar14 = -(uint)bVar19 | 1;
        }
        if ((uVar14 == 0) &&
           (cVar6 = FUN_005069d0(uVar18 << 0x10 | uVar15 & 0xffff,1), cVar6 != '\0')) {
          if (0xf < local_1c) {
            uVar12 = local_1c + 1;
            ppppppbVar16 = local_30[0];
            if (0xfff < uVar12) {
              ppppppbVar16 = (byte ******)local_30[0][-1];
              uVar12 = local_1c + 0x24;
              if ((byte *)0x1f < (byte *)((int)local_30[0] + (-4 - (int)ppppppbVar16)))
              goto LAB_004dfded;
            }
            FUN_00519359(ppppppbVar16,uVar12);
          }
          local_20 = 0;
          local_1c = 0xf;
          local_30[0] = (byte ******)((uint)local_30[0] & 0xffffff00);
          if (0xf < local_34) {
            uVar12 = local_34 + 1;
            ppppppbVar16 = local_48[0];
            if (0xfff < uVar12) {
              ppppppbVar16 = (byte ******)local_48[0][-1];
              uVar12 = local_34 + 0x24;
              if ((byte *)0x1f < (byte *)((int)local_48[0] + (-4 - (int)ppppppbVar16)))
              goto LAB_004dfded;
            }
            FUN_00519359(ppppppbVar16,uVar12);
          }
          local_38 = 0;
          local_34 = 0xf;
          local_48[0] = (byte ******)((uint)local_48[0] & 0xffffff00);
          if (piVar11 != (int *)0x0) {
            LOCK();
            iVar1 = piVar11[1] + -1;
            piVar11[1] = iVar1;
            UNLOCK();
            if (iVar1 == 0) {
              (**(code **)*piVar11)();
              LOCK();
              iVar1 = piVar11[2] + -1;
              piVar11[2] = iVar1;
              UNLOCK();
              if (iVar1 == 0) {
                (**(code **)(*piVar11 + 4))();
              }
            }
          }
          if (piVar9 != (int *)0x0) {
            LOCK();
            iVar1 = piVar9[1] + -1;
            piVar9[1] = iVar1;
            UNLOCK();
            if (iVar1 == 0) {
              (**(code **)*piVar9)();
              LOCK();
              piVar8 = piVar9 + 2;
              iVar1 = *piVar8;
              *piVar8 = *piVar8 + -1;
              UNLOCK();
              if (iVar1 == 1) {
                (**(code **)(*piVar9 + 4))();
              }
            }
          }
          ExceptionList = local_10;
          return 1;
        }
      }
      local_8._0_1_ = 7;
      if (0xf < local_1c) {
        uVar14 = local_1c + 1;
        if (uVar14 < 0x1000) {
          ppppppbVar16 = local_30[0];
        }
        else {
          uVar14 = local_1c + 0x24;
          ppppppbVar16 = (byte ******)local_30[0][-1];
          if ((byte *)0x1f < (byte *)((int)local_30[0] + (-4 - (int)local_30[0][-1]))) {
LAB_004dfded:
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
        }
        FUN_00519359(ppppppbVar16,uVar14);
      }
    }
    local_8 = (byte *****)CONCAT31(local_8._1_3_,6);
    if (0xf < local_34) {
      uVar18 = local_34 + 1;
      ppppppbVar16 = local_48[0];
      if (0xfff < uVar18) {
        ppppppbVar16 = (byte ******)local_48[0][-1];
        uVar18 = local_34 + 0x24;
        if ((byte *)0x1f < (byte *)((int)local_48[0] + (-4 - (int)ppppppbVar16))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
      }
      FUN_00519359(ppppppbVar16,uVar18);
    }
    uVar15 = uVar15 + 1;
  } while( true );
}


