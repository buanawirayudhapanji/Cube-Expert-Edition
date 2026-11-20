
undefined4 __thiscall FUN_00501270(QString *param_1,uint param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  int *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054bcdd;
  local_10 = ExceptionList;
  uVar5 = DAT_00759b24 ^ (int)register0x00000010 - 4U;
  if (*(uint *)(param_1 + 4) <= param_2) {
    return 0;
  }
  param_2 = param_2 * 0x80;
  uVar10 = *(int *)(*(int *)(param_1 + 0x8c) + 0x74 + param_2) + 100;
  ExceptionList = &local_10;
  if (*(void **)(param_1 + 0x98) == (void *)0x0) {
    uVar6 = FUN_00519367(uVar10,uVar5);
LAB_005012f5:
    *(uint *)(param_1 + 0x9c) = uVar10;
    *(undefined4 *)(param_1 + 0x98) = uVar6;
  }
  else if (*(uint *)(param_1 + 0x9c) < uVar10) {
    free(*(void **)(param_1 + 0x98));
    uVar6 = FUN_00519367(uVar10);
    goto LAB_005012f5;
  }
  uVar10 = *(uint *)(*(int *)(param_1 + 0x8c) + param_2 + 0x4c);
  iVar7 = FUN_00519367(uVar10,uVar5);
  FUN_004908a0(iVar7,param_2);
  local_8 = 0;
  iVar8 = FUN_00487040(param_1 + 8,*(undefined4 *)(*(int *)(param_1 + 0x8c) + param_2 + 0x70),uVar10
                       ,iVar7);
  uVar4 = s_YYYYYYYYYYYYYYYYUpdateFirmware_005926a0._12_4_;
  uVar3 = s_YYYYYYYYYYYYYYYYUpdateFirmware_005926a0._8_4_;
  uVar2 = s_YYYYYYYYYYYYYYYYUpdateFirmware_005926a0._4_4_;
  uVar6 = s_YYYYYYYYYYYYYYYYUpdateFirmware_005926a0._0_4_;
  if (iVar8 != 0) {
    uVar5 = 0;
    if (uVar10 != 0) {
      if (0x3f < uVar10) {
        puVar9 = (uint *)(iVar7 + 0x20);
        do {
          uVar5 = uVar5 + 0x40;
          puVar9[-8] = puVar9[-8] ^ uVar6;
          puVar9[-7] = puVar9[-7] ^ uVar2;
          puVar9[-6] = puVar9[-6] ^ uVar3;
          puVar9[-5] = puVar9[-5] ^ uVar4;
          puVar9[-4] = uVar6 ^ puVar9[-4];
          puVar9[-3] = uVar2 ^ puVar9[-3];
          puVar9[-2] = uVar3 ^ puVar9[-2];
          puVar9[-1] = uVar4 ^ puVar9[-1];
          *puVar9 = uVar6 ^ *puVar9;
          puVar9[1] = uVar2 ^ puVar9[1];
          puVar9[2] = uVar3 ^ puVar9[2];
          puVar9[3] = uVar4 ^ puVar9[3];
          puVar9[4] = puVar9[4] ^ uVar6;
          puVar9[5] = puVar9[5] ^ uVar2;
          puVar9[6] = puVar9[6] ^ uVar3;
          puVar9[7] = puVar9[7] ^ uVar4;
          puVar9 = puVar9 + 0x10;
        } while (uVar5 < (uVar10 & 0xffffffc0));
        if (uVar10 <= uVar5) goto LAB_005013be;
      }
      do {
        *(byte *)(iVar7 + uVar5) = *(byte *)(iVar7 + uVar5) ^ 0x59;
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar10);
    }
LAB_005013be:
    param_2 = *(uint *)(param_1 + 0x9c);
    iVar7 = FUN_00401000(*(undefined4 *)(param_1 + 0x98),&param_2,iVar7,uVar10);
    if (iVar7 == 0) {
      *param_3 = param_2;
      param_2 = *(uint *)(param_1 + 0x98);
      goto LAB_005013ee;
    }
    QString::operator=(param_1,"decode bin file failed");
  }
  param_2 = 0;
LAB_005013ee:
  local_8 = 1;
  if (local_18 != (int *)0x0) {
    LOCK();
    iVar7 = local_18[1] + -1;
    local_18[1] = iVar7;
    UNLOCK();
    if (iVar7 == 0) {
      (**(code **)(*local_18 + 4))();
      LOCK();
      piVar1 = local_18 + 2;
      iVar7 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar7 == 1) {
        (**(code **)(*local_18 + 8))();
      }
    }
  }
  ExceptionList = local_10;
  return param_2;
}


