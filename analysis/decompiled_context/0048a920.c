
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0048aa01) */
/* WARNING: Removing unreachable block (ram,0x0048aa06) */
/* WARNING: Removing unreachable block (ram,0x0048aa2f) */
/* WARNING: Removing unreachable block (ram,0x0048aa33) */
/* WARNING: Removing unreachable block (ram,0x0048aa4b) */
/* WARNING: Removing unreachable block (ram,0x0048aa57) */
/* WARNING: Removing unreachable block (ram,0x0048aa5a) */
/* WARNING: Removing unreachable block (ram,0x0048aa3e) */
/* WARNING: Removing unreachable block (ram,0x0048aa7f) */
/* WARNING: Removing unreachable block (ram,0x0048aaa3) */
/* WARNING: Removing unreachable block (ram,0x0048aac7) */
/* WARNING: Removing unreachable block (ram,0x0048aad9) */
/* WARNING: Removing unreachable block (ram,0x0048aae9) */

undefined4 * __thiscall FUN_0048a920(undefined4 *param_1,int param_2,int param_3)

{
  uint uVar1;
  basic_ostream<char,std::char_traits<char>_> *this;
  uint uVar2;
  int iVar3;
  undefined4 in_stack_00000018;
  uint in_stack_0000001c;
  undefined4 in_stack_ffffff5c;
  undefined4 in_stack_ffffff60;
  undefined4 in_stack_ffffff64;
  undefined4 in_stack_ffffff68;
  undefined4 in_stack_ffffff6c;
  undefined4 in_stack_ffffff70;
  undefined4 local_58;
  undefined1 local_54 [40];
  undefined1 local_2c [24];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined1 auStack_7 [3];
  
  puStack_c = &LAB_00522815;
  local_10 = ExceptionList;
  uVar1 = DAT_00759b24 ^ (uint)(auStack_7 + 3);
  ExceptionList = &local_10;
  param_1[1] = 0;
  local_8 = 1;
  auStack_7 = (undefined1  [3])0x0;
  *param_1 = RtMidiOut::vftable;
  local_14 = uVar1;
  if (param_2 != 0) {
    FUN_00489eb0(&param_3);
    FUN_0048c490(param_2,in_stack_ffffff5c,in_stack_ffffff60,in_stack_ffffff64,in_stack_ffffff68,
                 in_stack_ffffff6c,in_stack_ffffff70);
    if (param_1[1] != 0) goto LAB_0048aaf3;
    this = (basic_ostream<char,std::char_traits<char>_> *)
           FUN_004896f0(cerr_exref,
                        "\nRtMidiOut: no compiled support for specified API argument!\n\n");
    std::basic_ostream<char,std::char_traits<char>_>::operator<<(this,FUN_00489dc0);
  }
  local_8 = 3;
  local_58 = 4;
  FUN_00489ac0(0,&local_58);
  local_8 = 2;
  local_58 = 0;
  if (param_1[1] == 0) {
    FUN_00489f40("RtMidiOut: no compiled API support found ... critical error!!");
    _local_8 = CONCAT31(auStack_7,4);
    FUN_0048a650(local_2c,2);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_54,(ThrowInfo *)&DAT_00705a38);
  }
LAB_0048aaf3:
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
    FUN_00519359(iVar3,uVar2,uVar1);
  }
  ExceptionList = local_10;
  return param_1;
}


