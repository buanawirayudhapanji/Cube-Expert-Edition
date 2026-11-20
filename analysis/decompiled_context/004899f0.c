
undefined1 * __thiscall FUN_004899f0(int *param_1,void *param_2,undefined1 *param_3)

{
  int iVar1;
  uint uVar2;
  void *_Dst;
  undefined1 *puVar3;
  uint uVar4;
  
  iVar1 = *param_1;
  if (param_1[1] - iVar1 == 0x7fffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_0048b600();
  }
  uVar2 = (param_1[1] - iVar1) + 1;
  uVar4 = param_1[2] - iVar1;
  if (0x7fffffff - (uVar4 >> 1) < uVar4) {
    uVar4 = 0x7fffffff;
  }
  else {
    uVar4 = (uVar4 >> 1) + uVar4;
    if (uVar4 < uVar2) {
      uVar4 = uVar2;
    }
  }
  _Dst = (void *)FUN_00484800(uVar4);
  puVar3 = (undefined1 *)(((int)param_2 - iVar1) + (int)_Dst);
  *puVar3 = *param_3;
  if (param_2 == (void *)param_1[1]) {
    memmove(_Dst,(void *)*param_1,param_1[1] - *param_1);
  }
  else {
    memmove(_Dst,(void *)*param_1,(int)param_2 - *param_1);
    memmove(puVar3 + 1,param_2,param_1[1] - (int)param_2);
  }
  FUN_0048b5a0(_Dst,uVar2,uVar4);
  return puVar3;
}


