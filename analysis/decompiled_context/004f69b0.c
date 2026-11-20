
int * __thiscall FUN_004f69b0(int *param_1,void *param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  size_t _Size;
  void *_Dst;
  int iVar4;
  uint uVar5;
  
  uVar5 = (uint)param_3;
  uVar2 = param_1[5];
  if (param_3 <= uVar2) {
    param_3 = param_1;
    if (7 < uVar2) {
      param_3 = (int *)*param_1;
    }
    _Size = uVar5 * 2;
    param_1[4] = uVar5;
    memmove(param_3,param_2,_Size);
    *(undefined2 *)(_Size + (int)param_3) = 0;
    return param_1;
  }
  if (0x7ffffffe < param_3) {
                    /* WARNING: Subroutine does not return */
    FUN_004866c0();
  }
  uVar5 = (uint)param_3 | 7;
  if (uVar5 < 0x7fffffff) {
    if (0x7ffffffe - (uVar2 >> 1) < uVar2) {
      uVar5 = 0x7ffffffe;
    }
    else {
      uVar1 = (uVar2 >> 1) + uVar2;
      if (uVar5 < uVar1) {
        uVar5 = uVar1;
      }
    }
  }
  else {
    uVar5 = 0x7ffffffe;
  }
  _Dst = (void *)FUN_004dbb20(uVar5 + 1);
  param_1[5] = uVar5;
  param_1[4] = (int)param_3;
  memcpy(_Dst,param_2,(int)param_3 * 2);
  *(undefined2 *)((int)param_3 * 2 + (int)_Dst) = 0;
  if (7 < uVar2) {
    iVar3 = *param_1;
    uVar5 = uVar2 * 2 + 2;
    iVar4 = iVar3;
    if (0xfff < uVar5) {
      iVar4 = *(int *)(iVar3 + -4);
      uVar5 = uVar2 * 2 + 0x25;
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


