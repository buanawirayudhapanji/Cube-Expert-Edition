
undefined4 __thiscall FUN_005011c0(int param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (*(uint *)(param_1 + 4) <= param_2) {
    return 0;
  }
  iVar4 = param_2 * 0x80;
  uVar1 = *(uint *)(*(int *)(param_1 + 0x8c) + 0x44 + iVar4);
  if (*(void **)(param_1 + 0x98) == (void *)0x0) {
    uVar2 = FUN_00519367(uVar1);
  }
  else {
    if (uVar1 <= *(uint *)(param_1 + 0x9c)) goto LAB_00501219;
    free(*(void **)(param_1 + 0x98));
    uVar2 = FUN_00519367(uVar1);
  }
  *(uint *)(param_1 + 0x9c) = uVar1;
  *(undefined4 *)(param_1 + 0x98) = uVar2;
LAB_00501219:
  iVar3 = FUN_00487040(param_1 + 8,*(undefined4 *)(*(int *)(param_1 + 0x8c) + 0x40 + iVar4),
                       *(undefined4 *)(*(int *)(param_1 + 0x8c) + 0x44 + iVar4),
                       *(undefined4 *)(param_1 + 0x98));
  if (iVar3 == 0) {
    return 0;
  }
  *param_3 = *(undefined4 *)(*(int *)(param_1 + 0x8c) + 0x44 + iVar4);
  return *(undefined4 *)(param_1 + 0x98);
}


