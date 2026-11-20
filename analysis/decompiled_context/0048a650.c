
undefined4 * __thiscall FUN_0048a650(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_0051bae0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined8 *)(param_1 + 1) = 0;
  *param_1 = RtMidiError::vftable;
  FUN_00489eb0(param_2);
  param_1[9] = param_3;
  ExceptionList = local_10;
  return param_1;
}


