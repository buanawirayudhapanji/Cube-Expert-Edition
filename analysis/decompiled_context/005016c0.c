
undefined4 * __thiscall FUN_005016c0(int *param_1,void *param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  void *pvVar6;
  uint uVar7;
  uint uVar8;
  void *_Dst;
  
  iVar3 = *param_1;
  iVar5 = param_1[1] - iVar3 >> 3;
  if (iVar5 == 0x1fffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_0048b600();
  }
  uVar1 = iVar5 + 1;
  uVar7 = param_1[2] - iVar3 >> 3;
  if (0x1fffffff - (uVar7 >> 1) < uVar7) {
LAB_00501810:
                    /* WARNING: Subroutine does not return */
    FUN_004847e0();
  }
  uVar7 = (uVar7 >> 1) + uVar7;
  uVar8 = uVar1;
  if (uVar1 <= uVar7) {
    uVar8 = uVar7;
  }
  if (0x1fffffff < uVar8) goto LAB_00501810;
  uVar8 = uVar8 * 8;
  if (uVar8 < 0x1000) {
    if (uVar8 == 0) {
      _Dst = (void *)0x0;
    }
    else {
      _Dst = operator_new(uVar8);
    }
  }
  else {
    if (uVar8 + 0x23 <= uVar8) goto LAB_00501810;
    pvVar6 = operator_new(uVar8 + 0x23);
    if (pvVar6 == (void *)0x0) goto LAB_0050180a;
    _Dst = (void *)((int)pvVar6 + 0x23U & 0xffffffe0);
    *(void **)((int)_Dst - 4) = pvVar6;
  }
  puVar2 = (undefined4 *)((int)_Dst + ((int)param_2 - iVar3 >> 3) * 8);
  uVar4 = param_3[1];
  *puVar2 = *param_3;
  puVar2[1] = uVar4;
  pvVar6 = (void *)*param_1;
  if (param_2 == (void *)param_1[1]) {
    memmove(_Dst,pvVar6,param_1[1] - (int)pvVar6);
  }
  else {
    memmove(_Dst,pvVar6,(int)param_2 - (int)pvVar6);
    memmove(puVar2 + 2,param_2,param_1[1] - (int)param_2);
  }
  iVar3 = *param_1;
  if (iVar3 != 0) {
    uVar7 = param_1[2] - iVar3 & 0xfffffff8;
    iVar5 = iVar3;
    if (0xfff < uVar7) {
      iVar5 = *(int *)(iVar3 + -4);
      uVar7 = uVar7 + 0x23;
      if (0x1f < (iVar3 - iVar5) - 4U) {
LAB_0050180a:
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
    FUN_00519359(iVar5,uVar7);
  }
  *param_1 = (int)_Dst;
  param_1[1] = (int)((int)_Dst + uVar1 * 8);
  param_1[2] = (int)(uVar8 + (int)_Dst);
  return puVar2;
}


