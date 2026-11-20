
undefined4 * FUN_00488eb0(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar1 = 0;
  do {
    if (param_1 == *(int *)((int)&DAT_007548e0 + uVar1)) {
      puVar2 = &DAT_007548e0 + iVar3 * 0x15;
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = &DAT_007548e0;
      }
      return puVar2;
    }
    uVar1 = uVar1 + 0x54;
    iVar3 = iVar3 + 1;
  } while (uVar1 < 0xdc8);
  return &DAT_007548e0;
}


