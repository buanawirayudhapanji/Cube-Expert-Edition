
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0049e630(int param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined8 *puVar4;
  int iVar5;
  int *unaff_FS_OFFSET;
  undefined8 uStack_18;
  int iStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &UNK_005265be;
  iStack_10 = *unaff_FS_OFFSET;
  uVar2 = _DAT_00759b24 ^ (int)register0x00000010 - 4U;
  *unaff_FS_OFFSET = (int)&iStack_10;
  uVar3 = _text_QListWidgetItem__QBE_AVQString__XZ((int)&uStack_18 + 4,uVar2);
  uStack_8 = 0;
  cVar1 = func_0x0050a930(uVar3);
  uStack_8 = 0xffffffff;
  __1QString__QAE_XZ();
  if (cVar1 != '\0') {
    func_0x0050b2c0((int *)(param_1 + 0x138),0x200);
    puVar4 = *(undefined8 **)(param_1 + 0x13c);
    iVar5 = (int)puVar4 - *(int *)(param_1 + 0x138) >> 3;
    if (iVar5 < 0x200) {
      iVar5 = 0x200 - iVar5;
      do {
        uStack_18 = 0;
        if (puVar4 == *(undefined8 **)(param_1 + 0x140)) {
          func_0x00490930(puVar4,&uStack_18);
          puVar4 = *(undefined8 **)(param_1 + 0x13c);
        }
        else {
          *puVar4 = 0;
          puVar4 = puVar4 + 1;
          *(undefined8 **)(param_1 + 0x13c) = puVar4;
        }
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    func_0x004a0120();
  }
  *unaff_FS_OFFSET = iStack_10;
  return;
}


