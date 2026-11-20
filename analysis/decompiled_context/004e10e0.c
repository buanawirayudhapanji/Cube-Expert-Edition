
/* WARNING: Removing unreachable block (ram,0x004e1173) */
/* WARNING: Removing unreachable block (ram,0x004e115f) */
/* WARNING: Removing unreachable block (ram,0x004e1341) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e10e0(undefined1 *param_1,char *param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  char *pcVar3;
  int *piVar4;
  uint uVar5;
  QMessageLogger *this;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  longlong lVar10;
  ulonglong uVar11;
  int iVar12;
  undefined4 in_stack_ffffff68;
  undefined4 in_stack_ffffff6c;
  undefined4 in_stack_ffffff70;
  undefined4 uVar13;
  uint uVar14;
  QMessageLogger local_78 [20];
  double local_64;
  int *local_5c;
  undefined8 *local_58;
  uint local_54;
  int local_50;
  undefined1 *local_4c;
  undefined4 local_48;
  char *local_44;
  int *local_40;
  undefined8 *local_38;
  void *local_34;
  undefined8 local_30;
  uint local_28;
  undefined8 local_24;
  int local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00540104;
  local_10 = ExceptionList;
  local_14 = DAT_00759b24 ^ (uint)(local_78 + 0x74);
  ExceptionList = &local_10;
  local_4c = param_1;
  local_44 = param_2;
  local_40 = operator_new(8);
  local_8 = 0;
  iVar12 = 0;
  local_30._4_4_ = 0xf;
  local_38 = (undefined8 *)0x16;
  local_28 = 0x1f;
  local_34 = local_40;
  pcVar3 = (char *)FUN_00484800(0x20);
  uVar2 = s_RtMidi_Output_Client_00580f8c._12_4_;
  uVar8 = s_RtMidi_Output_Client_00580f8c._8_4_;
  uVar7 = s_RtMidi_Output_Client_00580f8c._4_4_;
  uVar13 = 0x14;
  *(undefined4 *)pcVar3 = s_RtMidi_Output_Client_00580f8c._0_4_;
  *(undefined4 *)(pcVar3 + 4) = uVar7;
  *(undefined4 *)(pcVar3 + 8) = uVar8;
  *(undefined4 *)(pcVar3 + 0xc) = uVar2;
  *(undefined4 *)(pcVar3 + 0x10) = s_RtMidi_Output_Client_00580f8c._16_4_;
  pcVar3[0x14] = '\0';
  uVar14 = local_28;
  if (0xf < local_30._4_4_) {
    uVar5 = local_30._4_4_ + 1;
    iVar6 = iVar12;
    if (0xfff < uVar5) {
      iVar6 = *(int *)(iVar12 + -4);
      uVar5 = local_30._4_4_ + 0x24;
      if (0x1f < (iVar12 - iVar6) - 4U) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
    FUN_00519359(iVar6,uVar5);
  }
  piVar4 = (int *)FUN_0048a920(0,pcVar3,in_stack_ffffff68,in_stack_ffffff6c,in_stack_ffffff70,uVar13
                               ,uVar14);
  local_8 = 1;
  local_40 = piVar4;
  local_58 = operator_new(0x10);
  *local_58 = 0;
  *(undefined4 *)(local_58 + 1) = 0;
  *(undefined4 *)((int)local_58 + 4) = 1;
  *(undefined4 *)(local_58 + 1) = 1;
  *(undefined ***)local_58 = std::_Ref_count<RtMidiOut>::vftable;
  *(int **)((int)local_58 + 0xc) = piVar4;
  uVar7 = SUB84(_DAT_0058f548,0);
  uVar8 = (undefined4)((ulonglong)_DAT_0058f548 >> 0x20);
  local_8 = 2;
  local_64 = _DAT_0058f548;
  local_5c = piVar4;
  local_38 = local_58;
  do {
    if (*local_44 != '\0') {
      *local_44 = '\0';
      DAT_00762cb0 = 0;
    }
    FUN_004e14e0(&local_54);
    if ((local_50 < 0x7fffffff) || (local_54 < 0xf4143dff)) {
      local_28 = local_54 + 200000000;
      local_34 = (void *)(local_50 + (uint)(0xf4143dff < local_54));
      uVar14 = local_28;
    }
    else {
      local_28 = 0xffffffff;
      local_34 = (void *)0x7fffffff;
      uVar14 = local_28;
    }
    while( true ) {
      uVar9 = _Query_perf_frequency();
      iVar12 = (int)((ulonglong)uVar9 >> 0x20);
      local_28 = (uint)uVar9;
      lVar10 = _Query_perf_counter();
      if ((local_28 == 10000000) && (iVar12 == 0)) {
        lVar1 = lVar10 * 100;
      }
      else {
        local_30 = lVar10;
        uVar9 = __allrem(lVar10,local_28,iVar12);
        uVar9 = __allmul(uVar9,1000000000,0);
        uVar9 = __alldiv(uVar9,local_28,iVar12);
        local_38 = (undefined8 *)((ulonglong)uVar9 >> 0x20);
        local_48 = (undefined4)uVar9;
        uVar11 = __alldiv(local_30,local_28,iVar12);
        lVar10 = (uVar11 & 0xffffffff) * 1000000000 +
                 CONCAT44((int)(uVar11 >> 0x20) * 1000000000,local_48);
        lVar1 = CONCAT44((int)local_38 + (int)((ulonglong)lVar10 >> 0x20),(int)lVar10);
        lVar10 = local_30;
      }
      local_30._4_4_ = (uint)((ulonglong)lVar10 >> 0x20);
      if (CONCAT44(local_34,uVar14) <= lVar1) break;
      local_30._0_4_ = uVar14 - (uint)lVar1;
      local_28 = (int)local_34 + (-(uint)(uVar14 < (uint)lVar1) - (int)((ulonglong)lVar1 >> 0x20));
      uVar9 = _Xtime_get_ticks();
      uVar9 = __allmul(uVar9,100,0);
      local_38 = (undefined8 *)((ulonglong)uVar9 >> 0x20);
      uVar5 = (uint)uVar9;
      local_30._4_4_ = (uint)local_38;
      FUN_00519d80();
      if ((double)CONCAT44(uVar8,uVar7) < local_64 || (double)CONCAT44(uVar8,uVar7) == local_64) {
        iVar6 = uVar5 + (uint)local_30;
        iVar12 = local_28 + local_30._4_4_ + (uint)CARRY4(uVar5,(uint)local_30);
      }
      else {
        iVar6 = uVar5 + 0xad160000;
        iVar12 = local_30._4_4_ + 0x311cd + (uint)(0x52e9ffff < uVar5);
      }
      uVar9 = __alldiv(iVar6,iVar12,1000000000,0);
      local_24 = uVar9;
      uVar9 = __allmul(uVar9,1000000000,0);
      local_38 = (undefined8 *)((ulonglong)uVar9 >> 0x20);
      local_1c = iVar6 - (int)uVar9;
      _Thrd_sleep(&local_24);
    }
    local_30 = lVar10;
    iVar12 = (**(code **)(*local_40 + 8))();
    if (DAT_00762cb0 != iVar12) {
      pcVar3 = (char *)QMessageLogger::QMessageLogger(local_78,(char *)0x0,0,(char *)0x0);
      QMessageLogger::debug(this,pcVar3,"Thread detect MIDI out dev changed ....");
      DAT_00762cb0 = iVar12;
      *local_4c = 1;
    }
  } while( true );
}


