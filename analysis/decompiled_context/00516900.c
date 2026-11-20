
void FUN_00516900(undefined4 param_1,int param_2,int param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_004de9b0(*(undefined4 *)param_4[1]);
      return;
    }
    if (param_3 == 1) {
      FUN_004de750(*(undefined4 *)param_4[1]);
      return;
    }
  }
  else if (param_2 == 0xc) {
    if (param_3 != 1) {
      *(undefined4 *)*param_4 = 0xffffffff;
      return;
    }
    if (*(int *)param_4[1] != 0) {
      *(undefined4 *)*param_4 = 0xffffffff;
      return;
    }
    uVar1 = FUN_00516830();
    *(undefined4 *)*param_4 = uVar1;
  }
  return;
}


