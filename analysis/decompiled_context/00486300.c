
/* WARNING: Removing unreachable block (ram,0x004863f2) */
/* WARNING: Removing unreachable block (ram,0x00486429) */
/* WARNING: Removing unreachable block (ram,0x00486402) */
/* WARNING: Removing unreachable block (ram,0x00486389) */
/* WARNING: Removing unreachable block (ram,0x0048639a) */
/* WARNING: Removing unreachable block (ram,0x004863e5) */
/* WARNING: Removing unreachable block (ram,0x00486404) */
/* WARNING: Removing unreachable block (ram,0x00486465) */

undefined4 __thiscall FUN_00486300(int param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 local_58 [3];
  uint local_4c;
  undefined4 local_48;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_0051c6b4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (*(int **)(param_1 + 0xc81c) == (int *)0x0) {
    local_48 = 0x48634c;
    operator_new(8);
    local_8 = CONCAT31(local_8._1_3_,1);
    local_48 = 0xf;
    local_4c = 0;
    pcVar4 = (char *)FUN_00484800(0x20);
    uVar3 = s_RtMidi_Input_Client_00580f78._12_4_;
    uVar2 = s_RtMidi_Input_Client_00580f78._8_4_;
    uVar5 = s_RtMidi_Input_Client_00580f78._4_4_;
    *(undefined4 *)pcVar4 = s_RtMidi_Input_Client_00580f78._0_4_;
    *(undefined4 *)(pcVar4 + 4) = uVar5;
    *(undefined4 *)(pcVar4 + 8) = uVar2;
    *(undefined4 *)(pcVar4 + 0xc) = uVar3;
    *(undefined2 *)(pcVar4 + 0x10) = s_RtMidi_Input_Client_00580f78._16_2_;
    pcVar4[0x12] = s_RtMidi_Input_Client_00580f78[0x12];
    pcVar4[0x13] = '\0';
    local_48 = 0x1f;
    local_4c = 0x13;
    uVar5 = FUN_0048a6b0(0,pcVar4);
    local_8 = local_8 & 0xffffff00;
    *(undefined4 *)(param_1 + 0xc81c) = uVar5;
  }
  else {
    (**(code **)(**(int **)(param_1 + 0xc81c) + 0x10))();
  }
  local_58[0] = 0;
  pcVar1 = *(code **)**(undefined4 **)(param_1 + 0xc81c);
  local_48 = 0xc;
  memmove(local_58,"RtMidi Input",0xc);
  local_4c = local_4c & 0xffffff00;
  (*pcVar1)(param_2);
  FUN_0048d230(FUN_004867e0,param_1);
  ExceptionList = local_10;
  return 1;
}


