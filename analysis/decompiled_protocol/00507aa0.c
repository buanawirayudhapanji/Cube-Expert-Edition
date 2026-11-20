
undefined4 FUN_00507aa0(uint param_1,int param_2,int param_3,int *param_4,uint param_5)

{
  char cVar1;
  
  cVar1 = func_0x00507fc0(param_2,param_3,param_4,param_5);
  if ((cVar1 != '\0') && (*param_4 == param_3)) {
    if (*(byte *)(param_2 + 2) == param_1) {
      param_5 = (uint)*(uint3 *)(param_2 + 3);
      cVar1 = FUN_00507970(param_2 + 6,param_5,*(undefined1 *)(param_5 + 6 + param_2));
      if (cVar1 != '\0') {
        return 1;
      }
    }
    else {
      func_0x00486c20(&UNK_00593610);
    }
  }
  return 0;
}


