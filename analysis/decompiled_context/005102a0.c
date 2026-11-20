
int __thiscall FUN_005102a0(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar2 = param_1[1] - *param_1;
  iVar1 = iVar2 >> 0x1f;
  iVar2 = iVar2 / 0xc + iVar1;
  iVar4 = 0;
  uVar5 = 0;
  uVar6 = 0;
  if (iVar2 != iVar1) {
    piVar3 = (int *)(*param_1 + 8);
    do {
      uVar5 = uVar5 + *piVar3;
      iVar4 = iVar4 + 1;
      if (param_2 <= uVar5) {
        return iVar4;
      }
      uVar6 = uVar6 + 1;
      piVar3 = piVar3 + 3;
    } while (uVar6 < (uint)(iVar2 - iVar1));
  }
  return iVar4;
}


