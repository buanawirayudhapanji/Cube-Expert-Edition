
undefined4 FUN_005063a0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int local_8;
  
  local_8 = 2;
  cVar1 = FUN_00507d60(param_1,param_2);
  if (cVar1 != '\0') {
    cVar1 = FUN_00507b30(&local_8,30000);
    if ((cVar1 != '\0') && (local_8 == 0)) {
      return 1;
    }
  }
  return 0;
}


