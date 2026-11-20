
int * __thiscall FUN_004866d0(int *param_1,void *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  void *_Dst;
  int iVar4;
  int *_Dst_00;
  uint uVar5;
  
  uVar2 = param_1[5];
  if (param_3 <= uVar2) {
    _Dst_00 = param_1;
    if (0xf < uVar2) {
      _Dst_00 = (int *)*param_1;
    }
    param_1[4] = param_3;
    memmove(_Dst_00,param_2,param_3);
    *(undefined1 *)((int)_Dst_00 + param_3) = 0;
    return param_1;
  }
  if (0x7fffffff < param_3) {
                    /* WARNING: Subroutine does not return */
    FUN_004866c0();
  }
  uVar5 = param_3 | 0xf;
  if (uVar5 < 0x80000000) {
    if (0x7fffffff - (uVar2 >> 1) < uVar2) {
      uVar5 = 0x7fffffff;
    }
    else {
      uVar1 = (uVar2 >> 1) + uVar2;
      if (uVar5 < uVar1) {
        uVar5 = uVar1;
      }
    }
  }
  else {
    uVar5 = 0x7fffffff;
  }
  _Dst = (void *)FUN_00484800(uVar5 + 1);
  param_1[4] = param_3;
  param_1[5] = uVar5;
  memcpy(_Dst,param_2,param_3);
  *(undefined1 *)((int)_Dst + param_3) = 0;
  if (0xf < uVar2) {
    uVar5 = uVar2 + 1;
    iVar3 = *param_1;
    iVar4 = iVar3;
    if (0xfff < uVar5) {
      iVar4 = *(int *)(iVar3 + -4);
      uVar5 = uVar2 + 0x24;
      if (0x1f < (iVar3 - iVar4) - 4U) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
    FUN_00519359(iVar4,uVar5);
  }
  *param_1 = (int)_Dst;
  return param_1;
}


