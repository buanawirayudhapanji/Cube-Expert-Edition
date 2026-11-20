
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * __thiscall FUN_0050a9c0(int param_1,ushort *param_2,uint param_3,undefined2 *param_4)

{
  ushort uVar1;
  int iVar2;
  undefined2 *puVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  int *piVar10;
  uint uVar11;
  int *unaff_FS_OFFSET;
  longlong lVar12;
  longlong lVar13;
  int iVar14;
  int iVar15;
  int *piStack_38;
  undefined1 uStack_32;
  uint uStack_18;
  int iStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  puVar3 = param_4;
  iVar15 = param_3;
  uStack_8 = 0xffffffff;
  puStack_c = &UNK_005532dd;
  iStack_10 = *unaff_FS_OFFSET;
  uVar4 = _DAT_00759b24 ^ (int)register0x00000010 - 4U;
  *unaff_FS_OFFSET = (int)&iStack_10;
  uVar4 = func_0x0050b710(uVar4);
  piVar5 = (int *)func_0x00519367(-(uint)((int)((ulonglong)uVar4 * 8 >> 0x20) != 0) |
                                  (uint)((ulonglong)uVar4 * 8));
  func_0x0050a4e0(piVar5,param_2);
  uStack_8 = 0;
  iVar6 = func_0x0050b700();
  switch(*(undefined2 *)(param_1 + 0x20)) {
  case 2:
    param_2 = (ushort *)0x0;
    if (uVar4 == 0) {
code_r0x0050adee:
      uVar11 = 0;
      if (uVar4 == 0) goto code_r0x0050ae20;
    }
    else {
      do {
        piVar5[(int)param_2 * 2] =
             (uint)CONCAT11(*(undefined1 *)(iVar6 + 1 + (int)param_2 * 2),
                            *(undefined1 *)(iVar6 + (int)param_2 * 2)) << 8;
        piVar5[(int)param_2 * 2 + 1] = 0;
        param_2 = (ushort *)((int)param_2 + 1);
      } while (param_2 < uVar4);
      uVar11 = 0;
    }
    break;
  case 3:
    uStack_18 = 0;
    if (uVar4 == 0) goto code_r0x0050adee;
    param_2 = (ushort *)(iVar6 + 1);
    do {
      piVar5[uStack_18 * 2] = (uint)CONCAT21(*param_2,*(undefined1 *)((int)param_2 + -1));
      piVar5[uStack_18 * 2 + 1] = 0;
      param_2 = (ushort *)((int)param_2 + 3);
      uStack_18 = uStack_18 + 1;
    } while (uStack_18 < uVar4);
    uVar11 = 0;
    break;
  case 4:
    uStack_18 = 0;
    if (uVar4 == 0) goto code_r0x0050adee;
    if ((char)param_2 == '\0') {
      param_2 = (ushort *)(iVar6 + 2);
      uStack_18 = 0;
      do {
        piVar5[uStack_18 * 2] = (uint)*param_2 << 8;
        piVar5[uStack_18 * 2 + 1] = 0;
        param_2 = param_2 + 2;
        uStack_18 = uStack_18 + 1;
      } while (uStack_18 < uVar4);
      uVar11 = 0;
    }
    else {
      do {
        piVar5[uStack_18 * 2] =
             (uint)CONCAT11(*(undefined1 *)(iVar6 + 1 + uStack_18 * 4),
                            *(undefined1 *)(iVar6 + uStack_18 * 4)) << 8;
        piVar5[uStack_18 * 2 + 1] = 0;
        uStack_18 = uStack_18 + 1;
      } while (uStack_18 < uVar4);
      uVar11 = 0;
    }
    break;
  default:
code_r0x0050af71:
    param_2 = param_4;
code_r0x0050af74:
    uStack_8 = 1;
    if (piStack_38 != (int *)0x0) {
      LOCK();
      iVar15 = piStack_38[1] + -1;
      piStack_38[1] = iVar15;
      UNLOCK();
      if (iVar15 == 0) {
        (**(code **)(*piStack_38 + 4))();
        LOCK();
        piVar5 = piStack_38 + 2;
        iVar15 = *piVar5;
        *piVar5 = *piVar5 + -1;
        UNLOCK();
        if (iVar15 == 1) {
          (**(code **)(*piStack_38 + 8))();
        }
        *unaff_FS_OFFSET = iStack_10;
        return param_2;
      }
    }
    *unaff_FS_OFFSET = iStack_10;
    return param_2;
  case 6:
    uStack_18 = 0;
    if (uVar4 == 0) goto code_r0x0050adee;
    if ((char)param_2 == '\0') {
      param_2 = (ushort *)(iVar6 + 4);
      uStack_18 = 0;
      do {
        piVar5[uStack_18 * 2] = (uint)CONCAT21(*param_2,*(undefined1 *)((int)param_2 + -1));
        piVar5[uStack_18 * 2 + 1] = 0;
        param_2 = param_2 + 3;
        uStack_18 = uStack_18 + 1;
      } while (uStack_18 < uVar4);
      uVar11 = 0;
    }
    else {
      param_2 = (ushort *)(iVar6 + 1);
      do {
        piVar5[uStack_18 * 2] = (uint)CONCAT21(*param_2,*(undefined1 *)((int)param_2 + -1));
        piVar5[uStack_18 * 2 + 1] = 0;
        param_2 = param_2 + 3;
        uStack_18 = uStack_18 + 1;
      } while (uStack_18 < uVar4);
      uVar11 = 0;
    }
    break;
  case 8:
    if (*(short *)(param_1 + 0x14) == 3) {
      if (uVar4 == 0) goto code_r0x0050adee;
      if ((char)param_2 == '\0') {
        uVar11 = 0;
        do {
          iVar6 = func_0x00519c60();
          piVar5[uVar11 * 2] = iVar6 << 8;
          piVar5[uVar11 * 2 + 1] = 0;
          uVar11 = uVar11 + 1;
        } while (uVar11 < uVar4);
        uVar11 = 0;
      }
      else {
        piVar10 = piVar5;
        uVar11 = uVar4;
        do {
          iVar6 = func_0x00519c60();
          *piVar10 = iVar6 << 8;
          piVar10[1] = 0;
          uVar11 = uVar11 - 1;
          piVar10 = piVar10 + 2;
        } while (uVar11 != 0);
        uVar11 = 0;
      }
    }
    else {
      uStack_18 = 0;
      if (uVar4 == 0) goto code_r0x0050adee;
      if ((char)param_2 == '\0') {
        param_2 = (ushort *)(iVar6 + 6);
        uStack_18 = 0;
        do {
          piVar5[uStack_18 * 2] = (uint)CONCAT21(*param_2,*(undefined1 *)((int)param_2 + -1));
          piVar5[uStack_18 * 2 + 1] = 0;
          param_2 = param_2 + 4;
          uStack_18 = uStack_18 + 1;
        } while (uStack_18 < uVar4);
        uVar11 = 0;
      }
      else {
        param_2 = (ushort *)(iVar6 + 2);
        do {
          piVar5[uStack_18 * 2] = (uint)CONCAT21(*param_2,*(undefined1 *)((int)param_2 + -1));
          piVar5[uStack_18 * 2 + 1] = 0;
          param_2 = param_2 + 4;
          uStack_18 = uStack_18 + 1;
        } while (uStack_18 < uVar4);
        uVar11 = 0;
      }
    }
  }
  do {
    if ((piVar5[uVar11 * 2] & 0x800000U) != 0) {
      piVar5[uVar11 * 2] = piVar5[uVar11 * 2] | 0xff000000;
      piVar5[uVar11 * 2 + 1] = -1;
    }
    uVar11 = uVar11 + 1;
  } while (uVar11 < uVar4);
code_r0x0050ae20:
  iVar6 = piVar5[1];
  uVar1 = *(ushort *)(param_3 + 0xc);
  iVar2 = *piVar5;
  *param_4 = (short)iVar2;
  uStack_32 = (undefined1)((uint)iVar2 >> 0x10);
  *(undefined1 *)(param_4 + 1) = uStack_32;
  param_3 = 0;
  uVar11 = *(uint *)(iVar15 + 4);
  param_4 = (undefined2 *)uVar11;
  if ((int)*(uint *)(param_1 + 0x18) % (int)uVar11 != 0) {
    uVar7 = *(uint *)(param_1 + 0x18);
    do {
      uVar9 = (uint)param_4;
      param_4 = (undefined2 *)((int)uVar7 % (int)uVar9);
      uVar7 = uVar9;
    } while ((int)uVar9 % (int)param_4 != 0);
  }
  uVar11 = uVar11 / (uint)param_4;
  uVar7 = *(uint *)(param_1 + 0x18) / (uint)param_4;
  param_4 = (undefined2 *)0;
  param_2 = puVar3;
  do {
    param_2 = (ushort *)((uint)uVar1 + (int)param_2);
    param_4 = (undefined2 *)((int)param_4 + uVar7);
    if (uVar11 <= param_4) {
      do {
        param_3 = param_3 + 1;
        param_4 = (undefined2 *)((int)param_4 - uVar11);
        if (uVar4 - 1 <= param_3) {
          if (uVar11 >> 1 <= param_4) goto code_r0x0050af74;
          uStack_32 = (undefined1)((uint)piVar5[param_3 * 2] >> 0x10);
          *param_2 = (short)piVar5[param_3 * 2];
          *(undefined1 *)(param_2 + 1) = uStack_32;
          param_4 = (undefined2 *)((int)param_2 + (uint)uVar1);
          goto code_r0x0050af71;
        }
      } while (uVar11 <= param_4);
    }
    if (param_3 == 0) {
      lVar12 = func_0x00519b60(uVar11 - (int)param_4,0,iVar2,iVar6);
      iVar15 = piVar5[1];
      iVar14 = *piVar5;
    }
    else {
      lVar12 = func_0x00519b60(piVar5[param_3 * 2 + -2],piVar5[param_3 * 2 + -1],
                               uVar11 - (int)param_4,0);
      iVar15 = piVar5[param_3 * 2 + 1];
      iVar14 = piVar5[param_3 * 2];
    }
    lVar13 = func_0x00519b60(param_4,0,iVar14,iVar15);
    uVar8 = func_0x00519ab0(lVar12 + lVar13,uVar11,0);
    *param_2 = (short)uVar8;
    uStack_32 = (undefined1)((uint)uVar8 >> 0x10);
    *(undefined1 *)(param_2 + 1) = uStack_32;
  } while( true );
}


