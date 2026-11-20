
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005068b0(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [6];
  char acStack_36 [46];
  undefined4 uStack_8;
  
  uStack_8 = _DAT_00759b24 ^ (uint)(acStack_36 + 0x32);
  cVar1 = FUN_00507de0(0x11);
  if (cVar1 != '\0') {
    cVar1 = FUN_00507aa0(0x11,auStack_3c,0x22,auStack_40,param_3,0);
    if (cVar1 != '\0') {
      puVar2 = param_1;
      if (0xf < (uint)param_1[5]) {
        puVar2 = (undefined4 *)*param_1;
      }
      param_1[4] = 0;
      iVar3 = 0;
      *(undefined1 *)puVar2 = 0;
      do {
        func_0x005070a0(acStack_36[iVar3]);
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x10);
      puVar2 = param_2;
      if (0xf < (uint)param_2[5]) {
        puVar2 = (undefined4 *)*param_2;
      }
      param_2[4] = 0;
      iVar3 = 8;
      *(undefined1 *)puVar2 = 0;
      do {
        func_0x005070a0(acStack_36[iVar3] + '0');
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x13);
      func_0x005195c6();
      return;
    }
  }
  func_0x005195c6();
  return;
}


