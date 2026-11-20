
undefined4 __thiscall FUN_00518050(undefined4 param_1,byte *param_2)

{
  byte bVar1;
  char *pcVar2;
  uint uVar3;
  undefined4 uVar4;
  byte *pbVar5;
  bool bVar6;
  
  if (param_2 == (byte *)0x0) {
    return 0;
  }
  pcVar2 = s_CCubeBabyIREditDlg_0075973c;
  pbVar5 = param_2;
  do {
    bVar1 = *pbVar5;
    bVar6 = bVar1 < (byte)*pcVar2;
    if (bVar1 != *pcVar2) {
LAB_00518090:
      uVar3 = -(uint)bVar6 | 1;
      goto LAB_00518095;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar5[1];
    bVar6 = bVar1 < (byte)pcVar2[1];
    if (bVar1 != pcVar2[1]) goto LAB_00518090;
    pbVar5 = pbVar5 + 2;
    pcVar2 = pcVar2 + 2;
  } while (bVar1 != 0);
  uVar3 = 0;
LAB_00518095:
  if (uVar3 == 0) {
    return param_1;
  }
  uVar4 = FUN_005182c0(param_2);
  return uVar4;
}


