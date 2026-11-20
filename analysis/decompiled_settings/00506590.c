
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00506590(undefined4 param_1,int param_2,int param_3,uint param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int *unaff_FS_OFFSET;
  int iStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &UNK_0054e0d4;
  iStack_10 = *unaff_FS_OFFSET;
  uVar4 = _DAT_00759b24 ^ (int)register0x00000010 - 4U;
  *unaff_FS_OFFSET = (int)&iStack_10;
  uVar1 = _DAT_00756acc;
  uVar9 = 0;
  uVar6 = (uint)(param_4 % _DAT_00756acc != 0) + param_4 / _DAT_00756acc;
  uVar7 = param_4;
  if (uVar6 != 0) {
    do {
      param_4 = 1;
      uVar8 = uVar7;
      if (uVar1 < uVar7) {
        uVar8 = uVar1;
      }
      cVar3 = func_0x00507cd0(param_1,param_2,param_3,uVar8,uVar4);
      if (((cVar3 == '\0') ||
          (cVar3 = func_0x00507b30(&param_4,10000), iVar2 = param_5, cVar3 == '\0')) ||
         (param_4 != 0)) {
        *unaff_FS_OFFSET = iStack_10;
        return 0;
      }
      param_3 = param_3 + uVar8;
      uVar7 = uVar7 - uVar8;
      param_2 = param_2 + uVar8;
      if (param_5 != 0) {
        func_0x00519329(0x20);
        uStack_8 = 0;
        uVar5 = func_0x0050fec0(0x3f0,uVar9 + 1,uVar6);
        uStack_8 = 0xffffffff;
        _postEvent_QCoreApplication__SAXPAVQObject__PAVQEvent__H_Z(iVar2,uVar5,0);
      }
      uVar9 = uVar9 + 1;
      func_0x00487020();
    } while (uVar9 < uVar6);
  }
  *unaff_FS_OFFSET = iStack_10;
  return 1;
}


