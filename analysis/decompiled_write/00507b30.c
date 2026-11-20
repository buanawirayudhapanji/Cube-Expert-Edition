
undefined4 __thiscall FUN_00507b30(int param_1,uint *param_2,undefined4 param_3)

{
  char cVar1;
  int iStack_8;
  
  iStack_8 = 0;
  cVar1 = func_0x00507fc0(param_1 + 0xc864,8,&iStack_8,param_3);
  if (cVar1 != '\0') {
    if (iStack_8 == 8) {
      if (*(char *)(param_1 + 0xc866) == '\0') {
        *param_2 = (uint)*(byte *)(param_1 + 0xc86a);
        return 1;
      }
    }
    else {
      func_0x00486c20(&UNK_005935e4,8,iStack_8);
    }
  }
  return 0;
}


