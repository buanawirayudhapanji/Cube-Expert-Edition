
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_004a3ed0(int param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *unaff_FS_OFFSET;
  undefined4 uStack_28;
  int *piStack_24;
  uint uStack_20;
  undefined4 *puStack_1c;
  int iStack_18;
  uint uStack_14;
  int iStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &UNK_0052666d;
  iStack_10 = *unaff_FS_OFFSET;
  uVar4 = _DAT_00759b24 ^ (int)register0x00000010 - 4U;
  *unaff_FS_OFFSET = (int)&iStack_10;
  if (*(int *)(param_1 + 0x80) == *(int *)(param_1 + 0x84)) {
    iVar5 = func_0x00486c20(&UNK_00584504);
    *unaff_FS_OFFSET = iStack_10;
    return iVar5;
  }
  _setDisabled_QWidget__QAEX_N_Z(1,uVar4);
  uStack_14 = _currentIndex_QComboBox__QBEHXZ();
  uStack_28 = 0;
  func_0x004908a0(0,uStack_20);
  uStack_8 = 0;
  iVar5 = FUN_004a4070(&uStack_28,&iStack_18);
  if ((char)iVar5 != '\0') {
    iVar2 = *(int *)(*(int *)(param_1 + 0x44) + 0x2ca74);
    iVar6 = func_0x00488eb0(*(undefined4 *)(*(int *)(param_1 + 0x44) + 0x2ca68));
    iVar5 = 0;
    if (iVar6 != 0) {
      puStack_1c = *(undefined4 **)(iVar6 + 0x48);
      uVar4 = uStack_14 * 0x1000 + iVar2;
      uStack_20 = iStack_18 + uVar4;
      uStack_14 = uVar4;
      if (uVar4 < uStack_20) {
        do {
          cVar3 = func_0x005063a0(*puStack_1c,uVar4);
          if (cVar3 == '\0') {
            iVar5 = func_0x00486c20(&UNK_00584528,uVar4);
            goto LAB_004a401d;
          }
          func_0x004872d0(100);
          uVar4 = uVar4 + puStack_1c[1];
        } while (uVar4 < uStack_20);
      }
      _show_QWidget__QAEXXZ();
      func_0x004a5930(*puStack_1c,uStack_14,uStack_28,iStack_18);
      _hide_QWidget__QAEXXZ();
      iVar5 = _setDisabled_QWidget__QAEX_N_Z(0);
    }
  }
LAB_004a401d:
  uStack_8 = 1;
  if (piStack_24 != (int *)0x0) {
    LOCK();
    piVar1 = piStack_24 + 1;
    iVar2 = *piVar1;
    iVar5 = *piVar1;
    *piVar1 = iVar2 + -1;
    UNLOCK();
    if (iVar2 + -1 == 0) {
      iVar5 = (**(code **)(*piStack_24 + 4))();
      LOCK();
      piVar1 = piStack_24 + 2;
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        iVar5 = (**(code **)(*piStack_24 + 8))();
      }
    }
  }
  *unaff_FS_OFFSET = iStack_10;
  return iVar5;
}


