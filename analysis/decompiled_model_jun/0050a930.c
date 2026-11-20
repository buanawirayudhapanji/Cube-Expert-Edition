
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_0050a930(undefined4 param_1)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  int *unaff_FS_OFFSET;
  undefined1 auStack_1c [12];
  int iStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &UNK_005532ae;
  iStack_10 = *unaff_FS_OFFSET;
  uVar2 = _DAT_00759b24 ^ (uint)(auStack_1c + 0x18);
  *unaff_FS_OFFSET = (int)&iStack_10;
  uVar1 = 0;
  __0QFile__QAE_XZ(uVar2);
  uStack_8 = 0;
  iVar3 = func_0x00486ef0(auStack_1c,param_1,1,1);
  if (iVar3 != 0) {
    uVar1 = FUN_0050a660(auStack_1c);
    _close_QFileDevice__UAEXXZ();
  }
  __1QFile__UAE_XZ();
  *unaff_FS_OFFSET = iStack_10;
  return uVar1;
}


