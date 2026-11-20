
undefined1 __thiscall FUN_005071b0(int param_1,int param_2)

{
  char cVar1;
  undefined1 uVar2;
  
  if (*(int *)(param_1 + 0xc844) == 3) {
    return 0;
  }
  uVar2 = 0;
  if (*(int *)(param_1 + 0x2caa4) != param_2) {
    cVar1 = FUN_00507da0();
    if (cVar1 != '\0') {
      *(int *)(param_1 + 0x2caa4) = param_2;
      uVar2 = 1;
    }
  }
  return uVar2;
}


