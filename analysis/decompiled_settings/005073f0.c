
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * __thiscall
FUN_005073f0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  code *pcVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined *puVar4;
  undefined4 uVar5;
  undefined4 *****pppppuVar6;
  uint uVar7;
  uint extraout_ECX;
  uint uVar8;
  undefined4 *****pppppuVar9;
  undefined4 *****extraout_EDX;
  int *unaff_FS_OFFSET;
  undefined4 *****in_stack_0000001c;
  uint in_stack_00000020;
  uint uStack_84;
  undefined4 *****pppppuStack_68;
  int iStack_64;
  undefined4 *****pppppuStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 *****apppppuStack_48 [4];
  undefined4 uStack_38;
  uint uStack_34;
  undefined4 *****pppppuStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined8 uStack_20;
  uint uStack_18;
  undefined1 *puStack_14;
  int iStack_10;
  undefined *puStack_c;
  undefined4 ****ppppuStack_8;
  
  puStack_c = &UNK_0054e1cd;
  iStack_10 = *unaff_FS_OFFSET;
  uStack_84 = _DAT_00759b24 ^ (uint)(apppppuStack_48 + 0x11);
  puStack_14 = (undefined1 *)&uStack_84;
  *unaff_FS_OFFSET = (int)&iStack_10;
  *(undefined4 *)(param_1 + 0x2ca68) = param_2;
  *(undefined4 *)(param_1 + 0x2caa0) = 0;
  ppppuStack_8 = (undefined4 ****)0x0;
  _DAT_00756ac8 = param_3;
  _DAT_00756acc = param_3;
  iStack_64 = param_1;
  uStack_18 = uStack_84;
  pppppuStack_68 = (undefined4 *****)func_0x00506230(&UNK_00593534,0);
  uVar5 = 1;
  uStack_20._4_4_ = 0xf;
  uStack_20._0_4_ = 0;
  uStack_20 = 0xf00000000;
  pppppuStack_30 = (undefined4 *****)0x0;
  ppppuStack_8._0_1_ = 1;
  if (pppppuStack_68 != (undefined4 *****)0xffffffff) {
    ppppuStack_8._0_1_ = 2;
    pppppuVar9 = pppppuStack_68;
    if (in_stack_0000001c < pppppuStack_68) {
      pppppuVar9 = in_stack_0000001c;
    }
    puVar2 = &param_4;
    if (0xf < in_stack_00000020) {
      puVar2 = param_4;
    }
    pppppuStack_60 = (undefined4 *****)0x0;
    uStack_50 = 0;
    uStack_4c = 0xf;
    func_0x004866d0(puVar2,pppppuVar9);
    pppppuVar9 = (undefined4 *****)((int)pppppuStack_68 + 1);
    uStack_38 = 0;
    uStack_34 = 0xf;
    apppppuStack_48[0] = (undefined4 *****)0x0;
    pppppuStack_30 = pppppuStack_60;
    uStack_2c = uStack_5c;
    uStack_28 = uStack_58;
    uStack_24 = uStack_54;
    uStack_20 = CONCAT44(uStack_4c,uStack_50);
    if (in_stack_0000001c < pppppuVar9) {
      func_0x00506090();
    }
    else {
      pppppuVar6 = in_stack_0000001c;
      if ((undefined4 *****)((int)in_stack_0000001c - (int)pppppuVar9) < in_stack_0000001c) {
        pppppuVar6 = (undefined4 *****)((int)in_stack_0000001c - (int)pppppuVar9);
      }
      puVar2 = &param_4;
      if (0xf < in_stack_00000020) {
        puVar2 = param_4;
      }
      func_0x004866d0((int)puVar2 + (int)pppppuVar9,pppppuVar6);
      ppppuStack_8._0_1_ = 3;
      piVar3 = (int *)_errno();
      pppppuVar9 = apppppuStack_48;
      if (0xf < uStack_34) {
        pppppuVar9 = apppppuStack_48[0];
      }
      *piVar3 = 0;
      uVar5 = strtol(pppppuVar9,&pppppuStack_68,10);
      if (pppppuVar9 != pppppuStack_68) {
        if (*piVar3 == 0x22) goto LAB_0050766f;
        if (0xf < uStack_34) {
          uVar7 = uStack_34 + 1;
          pppppuVar9 = apppppuStack_48[0];
          if (0xfff < uVar7) {
            pppppuVar9 = (undefined4 *****)apppppuStack_48[0][-1];
            uVar7 = uStack_34 + 0x24;
            if (0x1f < (uint)((int)apppppuStack_48[0] + (-4 - (int)pppppuVar9))) {
              _invalid_parameter_noinfo_noreturn();
              uVar7 = extraout_ECX;
              pppppuVar9 = extraout_EDX;
            }
          }
          func_0x00519359(pppppuVar9,uVar7);
        }
        goto LAB_00507589;
      }
    }
    func_0x0051920e(&UNK_00593410);
LAB_0050766f:
    func_0x005191e4(&UNK_00593428);
    pcVar1 = (code *)swi(3);
    puVar4 = (undefined *)(*pcVar1)();
    return puVar4;
  }
LAB_00507589:
  *(undefined4 *)(iStack_64 + 0x2ca64) = uVar5;
  uVar8 = 0;
  uVar7 = uStack_20._4_4_;
  if ((uint)uStack_20 != 0) {
    do {
      pppppuVar9 = &pppppuStack_30;
      if (0xf < uVar7) {
        pppppuVar9 = pppppuStack_30;
      }
      *(undefined1 *)(iStack_64 + 0x2ca78 + uVar8) = *(undefined1 *)((int)pppppuVar9 + uVar8);
      uVar8 = uVar8 + 1;
      uVar7 = uStack_20._4_4_;
    } while (uVar8 < (uint)uStack_20);
  }
  *(undefined1 *)(iStack_64 + 0x2ca78 + uVar8) = 0;
  if (0xf < uVar7) {
    uVar8 = uVar7 + 1;
    pppppuVar9 = pppppuStack_30;
    if (0xfff < uVar8) {
      pppppuVar9 = (undefined4 *****)pppppuStack_30[-1];
      uVar8 = uVar7 + 0x24;
      if (0x1f < (uint)((int)pppppuStack_30 + (-4 - (int)pppppuVar9))) goto LAB_00507618;
    }
    func_0x00519359(pppppuVar9,uVar8);
  }
  if (0xf < in_stack_00000020) {
    uVar7 = in_stack_00000020 + 1;
    puVar2 = param_4;
    if (0xfff < uVar7) {
      puVar2 = (undefined4 *)param_4[-1];
      uVar7 = in_stack_00000020 + 0x24;
      if (0x1f < (uint)((int)param_4 + (-4 - (int)puVar2))) {
LAB_00507618:
        _invalid_parameter_noinfo_noreturn();
        return &UNK_00507624;
      }
    }
    func_0x00519359(puVar2,uVar7);
  }
  *unaff_FS_OFFSET = iStack_10;
  puVar4 = (undefined *)func_0x005195c6();
  return puVar4;
}


