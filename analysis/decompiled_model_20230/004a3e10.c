
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a3e10(void)

{
  uint uVar1;
  int iVar2;
  int *unaff_FS_OFFSET;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  puStack_c = &UNK_0051b557;
  iStack_10 = *unaff_FS_OFFSET;
  uVar1 = _DAT_00759b24 ^ (int)register0x00000010 - 4U;
  *unaff_FS_OFFSET = (int)&iStack_10;
  uStack_18 = 0x755994;
  uStack_14 = 0x755970;
  uStack_8 = 1;
  iVar2 = _information_QMessageBox__SA_AW4StandardButton_1_PAVQWidget__ABVQString__1V__QFlags_W4StandardButton_QMessageBox____W421__Z
                    (0,&uStack_14,&uStack_18,0x14000,0,uVar1);
  __1QString__QAE_XZ();
  uStack_8 = 0xffffffff;
  __1QString__QAE_XZ();
  if (iVar2 == 0x4000) {
    func_0x004a5930(0,_DAT_0075596c,&UNK_00584b94,0x30);
  }
  *unaff_FS_OFFSET = iStack_10;
  return;
}


