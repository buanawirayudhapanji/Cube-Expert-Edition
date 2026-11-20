
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_005066c0(undefined4 param_1,undefined4 param_2,int param_3,byte *param_4,uint param_5,
            int param_6)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  ushort uVar10;
  uint uVar11;
  int *unaff_FS_OFFSET;
  int iStack_20;
  undefined4 uStack_1c;
  uint uStack_18;
  int iStack_14;
  int iStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  pbVar1 = param_4;
  uStack_8 = 0xffffffff;
  puStack_c = &UNK_0054e114;
  iStack_10 = *unaff_FS_OFFSET;
  uVar5 = _DAT_00759b24 ^ (int)register0x00000010 - 4U;
  *unaff_FS_OFFSET = (int)&iStack_10;
  uVar7 = _DAT_00756acc;
  iStack_14 = param_3;
  uStack_18 = param_5;
  uVar8 = (uint)(param_5 % _DAT_00756acc != 0) + param_5 / _DAT_00756acc;
  uVar9 = 0;
  uStack_1c = param_1;
  if (uVar8 != 0) {
    do {
      uVar11 = uStack_18;
      if (uVar7 < uStack_18) {
        uVar11 = uVar7;
      }
      iStack_20 = 1;
      cVar4 = FUN_00507cd0(param_2,iStack_14,param_4,uVar11,uVar5);
      if (((cVar4 == '\0') ||
          (cVar4 = FUN_00507b30(&iStack_20,10000), iVar3 = param_6, cVar4 == '\0')) ||
         (iStack_20 != 0)) {
        *unaff_FS_OFFSET = iStack_10;
        return 0;
      }
      uStack_18 = uStack_18 - uVar11;
      param_4 = param_4 + uVar11;
      iStack_14 = iStack_14 + uVar11;
      if (param_6 != 0) {
        func_0x00519329(0x20);
        uStack_8 = 0;
        uVar6 = func_0x0050fec0(0x3f0,uVar9 + 1,uVar8);
        uStack_8 = 0xffffffff;
        _postEvent_QCoreApplication__SAXPAVQObject__PAVQEvent__H_Z(iVar3,uVar6,0);
      }
      uVar9 = uVar9 + 1;
      func_0x00487020();
    } while (uVar9 < uVar8);
  }
  param_4 = (byte *)0x0;
  param_4._0_2_ = 0;
  uVar10 = (ushort)param_4;
  for (uVar7 = param_5; uVar7 != 0; uVar7 = uVar7 - 1) {
    bVar2 = *pbVar1;
    pbVar1 = pbVar1 + 1;
    uVar10 = uVar10 + bVar2;
  }
  cVar4 = FUN_00507d20(param_2,param_3,param_5);
  if ((cVar4 == '\0') ||
     (cVar4 = func_0x005079c0(&param_4,&param_2,&param_3,&param_5,30000), cVar4 == '\0')) {
    *unaff_FS_OFFSET = iStack_10;
    return 4;
  }
  if (uVar10 == param_5) {
    *unaff_FS_OFFSET = iStack_10;
    return 1;
  }
  *unaff_FS_OFFSET = iStack_10;
  return 3;
}


