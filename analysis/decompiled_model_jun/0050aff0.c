
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0050aff0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint3 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  bool bVar8;
  double dVar9;
  int iVar10;
  undefined8 uStack_24;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int iStack_14;
  uint uStack_10;
  undefined2 uStack_c;
  undefined4 uStack_8;
  
  uStack_8 = _DAT_00759b24 ^ (int)register0x00000010 - 4U;
  iVar10 = param_1 + 4;
  iVar2 = func_0x0050b710();
  if (iVar2 != 0) {
    func_0x00487880(param_2,param_3,param_4,&uStack_1c);
    piVar5 = &uStack_1c;
    uVar7 = 0xe;
    piVar6 = (int *)(param_1 + 0x14);
    do {
      if (*piVar5 != *piVar6) goto LAB_0050b05d;
      piVar5 = piVar5 + 1;
      piVar6 = piVar6 + 1;
      bVar8 = 3 < uVar7;
      uVar7 = uVar7 - 4;
    } while (bVar8);
    if ((short)*piVar5 != (short)*piVar6) {
LAB_0050b05d:
      dVar9 = ((double)iStack_14 + *(double *)(&UNK_005810c0 + (iStack_14 >> 0x1f) * -8)) /
              ((double)*(int *)(param_1 + 0x1c) +
              *(double *)(&UNK_005810c0 + (*(int *)(param_1 + 0x1c) >> 0x1f) * -8)) + _DAT_005937f8;
      func_0x0050b710();
      uVar3 = func_0x00519cd0();
      iVar2 = func_0x00519367(uVar3);
      uStack_24._5_3_ = (uint3)((ulonglong)dVar9 >> 0x28);
      uVar1 = uStack_24._5_3_;
      if (uStack_1c._2_2_ == 1) {
        uStack_24 = CONCAT35(uStack_24._5_3_,0x100000000);
        iVar4 = iVar2;
      }
      else {
        FUN_0050a9c0(1,&uStack_1c,iVar2,uVar3);
        iVar4 = (uStack_10 >> 0x13) + iVar2;
        uStack_24 = (ulonglong)uStack_24._5_3_ << 0x28;
        if (*(ushort *)(param_1 + 0x16) < 2) {
          uStack_24 = CONCAT35(uVar1,0x100000000);
        }
      }
      iVar4 = FUN_0050a9c0(uStack_24._4_4_,&uStack_1c,iVar4,uVar3);
      *(int *)(param_1 + 0x14) = uStack_1c;
      *(undefined4 *)(param_1 + 0x18) = uStack_18;
      *(int *)(param_1 + 0x1c) = iStack_14;
      *(uint *)(param_1 + 0x20) = uStack_10;
      *(undefined2 *)(param_1 + 0x24) = uStack_c;
      func_0x0050b720(iVar2,(iVar4 - iVar2) / (int)(uint)*(ushort *)(param_1 + 0x20),
                      (uint)*(ushort *)(param_1 + 0x20));
    }
  }
  func_0x005195c6(iVar10);
  return;
}


