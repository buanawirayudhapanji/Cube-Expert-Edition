
undefined4 * __thiscall FUN_00489eb0(undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  void *_Dst;
  uint uVar5;
  
  *param_1 = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  uVar1 = param_2[4];
  if (0xf < (uint)param_2[5]) {
    param_2 = (undefined4 *)*param_2;
  }
  if (uVar1 < 0x10) {
    uVar2 = param_2[1];
    uVar3 = param_2[2];
    uVar4 = param_2[3];
    *param_1 = *param_2;
    param_1[1] = uVar2;
    param_1[2] = uVar3;
    param_1[3] = uVar4;
    param_1[4] = uVar1;
    param_1[5] = 0xf;
    return param_1;
  }
  uVar5 = uVar1 | 0xf;
  if (0x7fffffff < uVar5) {
    uVar5 = 0x7fffffff;
  }
  _Dst = (void *)FUN_00484800(uVar5 + 1);
  *param_1 = _Dst;
  memcpy(_Dst,param_2,uVar1 + 1);
  param_1[4] = uVar1;
  param_1[5] = uVar5;
  return param_1;
}


