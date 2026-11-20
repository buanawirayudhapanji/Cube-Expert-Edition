
void __thiscall FUN_0050b260(int param_1,undefined4 param_2,uint param_3,char param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = (uint)*(ushort *)(param_1 + 0x20);
  if (param_4 == '\0') {
    if (*(int *)(param_1 + 0xc) != 0) {
      func_0x00519370(*(int *)(param_1 + 0xc));
    }
    *(undefined4 *)(param_1 + 0xc) = param_2;
    *(uint *)(param_1 + 0x10) = param_3;
    *(uint *)(param_1 + 8) = uVar2;
    return;
  }
  iVar4 = *(int *)(param_1 + 0xc);
  if (iVar4 == 0) {
    iVar4 = 0;
    if (param_3 != 0) {
      iVar4 = func_0x00519367(param_3 * uVar2);
    }
    if (*(int *)(param_1 + 0xc) != 0) {
      func_0x00519370(*(int *)(param_1 + 0xc));
    }
    *(int *)(param_1 + 0xc) = iVar4;
    *(uint *)(param_1 + 0x10) = param_3;
    *(uint *)(param_1 + 8) = uVar2;
  }
  uVar1 = *(uint *)(param_1 + 0x10);
  uVar3 = param_3;
  if (uVar1 < param_3) {
    uVar3 = uVar1;
  }
  if (uVar3 * uVar2 != 0) {
    func_0x0051a5b8(iVar4,0,*(int *)(param_1 + 8) * uVar1);
    if (*(uint *)(param_1 + 0x10) < param_3) {
      param_3 = *(uint *)(param_1 + 0x10);
    }
    func_0x0051a5a0(*(undefined4 *)(param_1 + 0xc),param_2,param_3 * uVar2);
  }
  return;
}


