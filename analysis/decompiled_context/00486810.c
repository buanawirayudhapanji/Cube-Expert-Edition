
undefined4 FUN_00486810(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_004864f0(param_1,param_3);
  if (iVar1 != 0) {
    iVar1 = FUN_00486300(param_2,param_3);
    if (iVar1 != 0) {
      FUN_0050fe00();
      return 1;
    }
  }
  FUN_00486270();
  FUN_004861e0();
  return 0;
}


