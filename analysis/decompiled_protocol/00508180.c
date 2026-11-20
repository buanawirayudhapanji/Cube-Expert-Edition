
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00508180(int param_1,uint param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  char cVar2;
  uint uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_8 = _DAT_00759b24 ^ (int)register0x00000010 - 4U;
  if ((param_3 == 1) || (param_3 == 2)) {
    cVar2 = FUN_00486810(param_2 >> 0x10,param_2 & 0xffff,param_4);
    if (cVar2 == '\0') {
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
    else {
      *(int *)(param_1 + 0xc844) = param_3;
      FUN_00486ad0(param_3 == 1);
    }
  }
  func_0x005195c6();
  return;
}


