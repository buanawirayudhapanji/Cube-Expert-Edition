
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_0048b850(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 in_stack_00000018;
  uint in_stack_0000001c;
  undefined1 local_3c [16];
  undefined1 local_2c [24];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00523445;
  local_10 = ExceptionList;
  local_14 = DAT_00759b24 ^ (uint)(local_2c + 0x28);
  ExceptionList = &local_10;
  local_8 = 0;
  if (*(int *)(param_1 + 0x24) == 0) {
    if (param_2 == 0) {
      uVar1 = FUN_00489530(cerr_exref,10);
      puVar2 = &param_3;
      if (0xf < in_stack_0000001c) {
        puVar2 = param_3;
      }
      uVar1 = FUN_00489c20(uVar1,puVar2,in_stack_00000018,&DAT_00581670);
      FUN_004896f0(uVar1);
    }
    else if (param_2 != 1) {
      uVar1 = FUN_00489530(cerr_exref,10,&param_3,&DAT_00581670,local_14);
      uVar1 = FUN_00489510(uVar1);
      FUN_004896f0(uVar1);
      FUN_0048a650(&param_3,param_2);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_3c,(ThrowInfo *)&DAT_00705a38);
    }
  }
  else if (*(char *)(param_1 + 0x28) == '\0') {
    *(undefined1 *)(param_1 + 0x28) = 1;
    FUN_00489eb0(&param_3);
    local_8 = CONCAT31(local_8._1_3_,1);
    (**(code **)(param_1 + 0x24))(param_2,local_2c,*(undefined4 *)(param_1 + 0x2c));
    *(undefined1 *)(param_1 + 0x28) = 0;
    FUN_00483b20();
  }
  FUN_00483b20();
  ExceptionList = local_10;
  return;
}


