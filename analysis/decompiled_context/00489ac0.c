
undefined4 * __thiscall FUN_00489ac0(int *param_1,void *param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  uint uVar6;
  uint uVar7;
  void *_Dst;
  
  iVar3 = *param_1;
  iVar4 = param_1[1] - iVar3 >> 2;
  if (iVar4 == 0x3fffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_0048b600();
  }
  uVar1 = iVar4 + 1;
  uVar6 = param_1[2] - iVar3 >> 2;
  if (0x3fffffff - (uVar6 >> 1) < uVar6) {
LAB_00489c0a:
                    /* WARNING: Subroutine does not return */
    FUN_004847e0();
  }
  uVar6 = (uVar6 >> 1) + uVar6;
  uVar7 = uVar1;
  if (uVar1 <= uVar6) {
    uVar7 = uVar6;
  }
  if (0x3fffffff < uVar7) goto LAB_00489c0a;
  uVar7 = uVar7 * 4;
  if (uVar7 < 0x1000) {
    if (uVar7 == 0) {
      _Dst = (void *)0x0;
    }
    else {
      _Dst = operator_new(uVar7);
    }
  }
  else {
    if (uVar7 + 0x23 <= uVar7) goto LAB_00489c0a;
    pvVar5 = operator_new(uVar7 + 0x23);
    if (pvVar5 == (void *)0x0) goto LAB_00489c04;
    _Dst = (void *)((int)pvVar5 + 0x23U & 0xffffffe0);
    *(void **)((int)_Dst - 4) = pvVar5;
  }
  puVar2 = (undefined4 *)((int)_Dst + ((int)param_2 - iVar3 >> 2) * 4);
  *puVar2 = *param_3;
  pvVar5 = (void *)*param_1;
  if (param_2 == (void *)param_1[1]) {
    memmove(_Dst,pvVar5,param_1[1] - (int)pvVar5);
  }
  else {
    memmove(_Dst,pvVar5,(int)param_2 - (int)pvVar5);
    memmove(puVar2 + 1,param_2,param_1[1] - (int)param_2);
  }
  iVar3 = *param_1;
  if (iVar3 != 0) {
    uVar6 = param_1[2] - iVar3 & 0xfffffffc;
    iVar4 = iVar3;
    if (0xfff < uVar6) {
      iVar4 = *(int *)(iVar3 + -4);
      uVar6 = uVar6 + 0x23;
      if (0x1f < (iVar3 - iVar4) - 4U) {
LAB_00489c04:
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
    FUN_00519359(iVar4,uVar6);
  }
  *param_1 = (int)_Dst;
  param_1[1] = (int)((int)_Dst + uVar1 * 4);
  param_1[2] = (int)(uVar7 + (int)_Dst);
  return puVar2;
}


