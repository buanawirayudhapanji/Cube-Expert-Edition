
void __thiscall FUN_0048c490(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint in_stack_0000001c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_005235ac;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (*(undefined4 **)(param_1 + 4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 4))(1,DAT_00759b24 ^ (int)register0x00000010 - 4U);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  if (param_2 == 4) {
    operator_new(0x30);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00489eb0(&param_3);
    uVar1 = FUN_0048a3c0();
    *(undefined4 *)(param_1 + 4) = uVar1;
  }
  if (0xf < in_stack_0000001c) {
    uVar2 = in_stack_0000001c + 1;
    iVar3 = param_3;
    if (0xfff < uVar2) {
      iVar3 = *(int *)(param_3 + -4);
      uVar2 = in_stack_0000001c + 0x24;
      if (0x1f < (param_3 - iVar3) - 4U) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
    FUN_00519359(iVar3,uVar2);
  }
  ExceptionList = local_10;
  return;
}


