
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00508080(int param_1,undefined4 param_2,int param_3,int *param_4,char param_5)

{
  uint uVar1;
  int iVar2;
  uint uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_8 = _DAT_00759b24 ^ (int)register0x00000010 - 4U;
  if (*(int *)(param_1 + 0xc844) != 3) {
    if (param_5 != '\0') {
      func_0x004867c0();
    }
    if ((*(int *)(param_1 + 0xc844) == 1) || (*(int *)(param_1 + 0xc844) == 2)) {
      iVar2 = FUN_00486af0(param_2,param_3);
      *param_4 = iVar2;
    }
    if (*param_4 == param_3) {
      func_0x005195c6();
      return;
    }
    func_0x00489eb0(param_1 + 0xc828);
    if ((uint *)(param_1 + 0xc848) != &uStack_20) {
      func_0x00483b20();
      uVar1 = uStack_20;
      uStack_20 = uStack_20 & 0xffffff00;
      *(uint *)(param_1 + 0xc848) = uVar1;
      *(undefined4 *)(param_1 + 0xc84c) = uStack_1c;
      *(undefined4 *)(param_1 + 0xc850) = uStack_18;
      *(undefined4 *)(param_1 + 0xc854) = uStack_14;
      *(ulonglong *)(param_1 + 0xc858) = CONCAT44(uStack_c,uStack_10);
      uStack_10 = 0;
      uStack_c = 0xf;
    }
    func_0x00483b20();
  }
  func_0x005195c6();
  return;
}


