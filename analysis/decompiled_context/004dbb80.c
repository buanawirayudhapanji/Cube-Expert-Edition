
byte __thiscall FUN_004dbb80(int param_1,uint param_2,int *param_3)

{
  undefined2 *puVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  QMessageLogger *this;
  QMessageLogger *this_00;
  uint uVar6;
  QMessageLogger *this_01;
  QMessageLogger *this_02;
  QMessageLogger *this_03;
  uint uVar7;
  QMessageLogger local_24 [20];
  uint local_10;
  uint local_c;
  int local_8;
  
  uVar5 = *(int *)(param_1 + 0x440) * *(int *)(param_1 + 0x43c);
  uVar2 = param_2 / uVar5;
  uVar3 = uVar2 + 1;
  if (param_2 % uVar5 == 0) {
    uVar3 = uVar2;
  }
  if (*(uint *)(param_1 + 0x430) < uVar3) {
    return 7;
  }
  if (*param_3 != param_3[1]) {
    param_3[1] = *param_3;
  }
  local_8 = param_1;
  pcVar4 = (char *)QMessageLogger::QMessageLogger(local_24,(char *)0x0,0,(char *)0x0);
  QMessageLogger::debug(this,pcVar4,"Searched blocks:");
  uVar2 = FUN_00487800();
  uVar2 = uVar2 % *(uint *)(param_1 + 0x42c);
  uVar5 = 0;
  local_c = uVar2;
  if (uVar2 < *(uint *)(param_1 + 0x42c)) {
    do {
      if (uVar5 == uVar3) goto LAB_004dbda6;
      local_10 = local_8 + 0x40;
      if (7999 < uVar2) goto LAB_004dbdcf;
      uVar7 = 1 << (uVar2 & 0x1f);
      uVar6 = 0;
      if (0x1f < (uVar2 & 0x3f)) {
        uVar6 = uVar7;
      }
      uVar7 = uVar7 ^ uVar6;
      if (0x3f < (uVar2 & 0x3f)) {
        uVar6 = uVar7;
      }
      if ((uVar7 & *(uint *)(local_10 + (uVar2 >> 6) * 8)) == 0 &&
          (uVar6 & *(uint *)(local_8 + 0x44 + (uVar2 >> 6) * 8)) == 0) {
        local_10 = uVar2 & 0xffff;
        puVar1 = (undefined2 *)param_3[1];
        if (puVar1 == (undefined2 *)param_3[2]) {
          FUN_004dacb0(puVar1,&local_10);
        }
        else {
          *puVar1 = (short)uVar2;
          param_3[1] = param_3[1] + 2;
        }
        uVar5 = uVar5 + 1;
        pcVar4 = (char *)QMessageLogger::QMessageLogger(local_24,(char *)0x0,0,(char *)0x0);
        QMessageLogger::debug(this_00,pcVar4,&DAT_0058ec78,uVar2);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(local_8 + 0x42c));
  }
  if ((uVar5 < uVar3) && (uVar2 = 0, local_c != 0)) {
    do {
      if (uVar5 == uVar3) {
LAB_004dbda6:
        pcVar4 = (char *)QMessageLogger::QMessageLogger(local_24,(char *)0x0,0,(char *)0x0);
        QMessageLogger::debug(this_03,pcVar4,&DAT_005825c8);
        return 0;
      }
      local_10 = local_8 + 0x40;
      if (7999 < uVar2) {
LAB_004dbdcf:
                    /* WARNING: Subroutine does not return */
        FUN_004dbb10();
      }
      uVar7 = 1 << (uVar2 & 0x1f);
      uVar6 = 0;
      if (0x1f < (uVar2 & 0x3f)) {
        uVar6 = uVar7;
      }
      uVar7 = uVar7 ^ uVar6;
      if (0x3f < (uVar2 & 0x3f)) {
        uVar6 = uVar7;
      }
      if ((uVar7 & *(uint *)(local_10 + (uVar2 >> 6) * 8)) == 0 &&
          (uVar6 & *(uint *)(local_8 + 0x44 + (uVar2 >> 6) * 8)) == 0) {
        local_10 = uVar2 & 0xffff;
        puVar1 = (undefined2 *)param_3[1];
        if (puVar1 == (undefined2 *)param_3[2]) {
          FUN_004dacb0(puVar1,&local_10);
        }
        else {
          *puVar1 = (short)uVar2;
          param_3[1] = param_3[1] + 2;
        }
        uVar5 = uVar5 + 1;
        pcVar4 = (char *)QMessageLogger::QMessageLogger(local_24,(char *)0x0,0,(char *)0x0);
        QMessageLogger::debug(this_01,pcVar4,&DAT_0058ec78,uVar2);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < local_c);
  }
  pcVar4 = (char *)QMessageLogger::QMessageLogger(local_24,(char *)0x0,0,(char *)0x0);
  QMessageLogger::debug(this_02,pcVar4,&DAT_005825c8);
  return -(uVar5 < uVar3) & 6;
}


