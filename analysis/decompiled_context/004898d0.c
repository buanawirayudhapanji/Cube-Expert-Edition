
void __thiscall FUN_004898d0(undefined4 *param_1,void *param_2,uint param_3)

{
  void *pvVar1;
  uint uVar2;
  uint _Size;
  size_t _Size_00;
  void *pvVar3;
  
  _Size = param_3 - (int)param_2;
  pvVar1 = (void *)*param_1;
  uVar2 = param_1[2] - (int)pvVar1;
  if (_Size <= uVar2) {
    uVar2 = param_1[1] - (int)pvVar1;
    if (uVar2 < _Size) {
      memmove(pvVar1,param_2,uVar2);
      pvVar1 = (void *)param_1[1];
      _Size_00 = param_3 - (int)(uVar2 + (int)param_2);
      memmove(pvVar1,(void *)(uVar2 + (int)param_2),_Size_00);
      param_1[1] = _Size_00 + (int)pvVar1;
      return;
    }
    memmove(pvVar1,param_2,_Size);
    param_1[1] = (int)pvVar1 + _Size;
    return;
  }
  if (0x7fffffff < _Size) {
                    /* WARNING: Subroutine does not return */
    FUN_0048b600();
  }
  if (0x7fffffff - (uVar2 >> 1) < uVar2) {
    param_3 = 0x7fffffff;
  }
  else {
    param_3 = (uVar2 >> 1) + uVar2;
    if (param_3 < _Size) {
      param_3 = _Size;
    }
  }
  if (pvVar1 != (void *)0x0) {
    pvVar3 = pvVar1;
    if (0xfff < uVar2) {
      pvVar3 = *(void **)((int)pvVar1 + -4);
      uVar2 = uVar2 + 0x23;
      if (0x1f < (uint)((int)pvVar1 + (-4 - (int)pvVar3))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
    FUN_00519359(pvVar3,uVar2);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  FUN_0048b520(param_3);
  pvVar1 = (void *)*param_1;
  memmove(pvVar1,param_2,_Size);
  param_1[1] = _Size + (int)pvVar1;
  return;
}


