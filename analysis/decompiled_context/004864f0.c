
/* WARNING: Removing unreachable block (ram,0x004865d6) */
/* WARNING: Removing unreachable block (ram,0x0048660d) */
/* WARNING: Removing unreachable block (ram,0x004865e6) */
/* WARNING: Removing unreachable block (ram,0x00486577) */
/* WARNING: Removing unreachable block (ram,0x00486588) */
/* WARNING: Removing unreachable block (ram,0x004865c9) */
/* WARNING: Removing unreachable block (ram,0x004865e8) */
/* WARNING: Removing unreachable block (ram,0x00486646) */

undefined4 __thiscall FUN_004864f0(int param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *local_58 [3];
  undefined1 local_4b;
  undefined4 local_48;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_0051c6f4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (*(int **)(param_1 + 0xc818) == (int *)0x0) {
    local_48 = 0x48653c;
    operator_new(8);
    local_8 = CONCAT31(local_8._1_3_,1);
    local_58[0] = (char *)0x0;
    local_48 = 0;
    local_58[0] = (char *)FUN_00484800(0x20);
    uVar3 = s_RtMidi_Output_Client_00580f8c._12_4_;
    uVar2 = s_RtMidi_Output_Client_00580f8c._8_4_;
    uVar4 = s_RtMidi_Output_Client_00580f8c._4_4_;
    *(undefined4 *)local_58[0] = s_RtMidi_Output_Client_00580f8c._0_4_;
    *(undefined4 *)(local_58[0] + 4) = uVar4;
    *(undefined4 *)(local_58[0] + 8) = uVar2;
    *(undefined4 *)(local_58[0] + 0xc) = uVar3;
    *(undefined4 *)(local_58[0] + 0x10) = s_RtMidi_Output_Client_00580f8c._16_4_;
    local_58[0][0x14] = '\0';
    local_48 = 0x14;
    uVar4 = FUN_0048a920(0);
    local_8 = local_8 & 0xffffff00;
    *(undefined4 *)(param_1 + 0xc818) = uVar4;
  }
  else {
    (**(code **)(**(int **)(param_1 + 0xc818) + 0x10))();
  }
  local_58[0] = (char *)0x0;
  pcVar1 = *(code **)**(undefined4 **)(param_1 + 0xc818);
  local_48 = 0xd;
  memmove(local_58,"RtMidi Output",0xd);
  local_4b = 0;
  (*pcVar1)(param_2);
  ExceptionList = local_10;
  return 1;
}


