
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0049e350(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  int *unaff_FS_OFFSET;
  undefined1 auStack_2c [8];
  undefined4 uStack_24;
  int iStack_20;
  int *piStack_1c;
  int iStack_18;
  undefined1 auStack_14 [4];
  int iStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  puStack_c = &UNK_0052a10c;
  iStack_10 = *unaff_FS_OFFSET;
  uVar5 = _DAT_00759b24 ^ (uint)(auStack_14 + 0x10);
  *unaff_FS_OFFSET = (int)&iStack_10;
  uStack_24 = 0x755904;
  piStack_1c = (int *)0x7558d8;
  uStack_8 = 1;
  iStack_18 = param_1;
  iVar6 = _information_QMessageBox__SA_AW4StandardButton_1_PAVQWidget__ABVQString__1V__QFlags_W4StandardButton_QMessageBox____W421__Z
                    (0,&piStack_1c,&uStack_24,0x14000,0,uVar5);
  __1QString__QAE_XZ();
  uStack_8 = 0xffffffff;
  __1QString__QAE_XZ();
  if (iVar6 == 0x4000) {
    iVar6 = *(int *)(param_1 + 0xf8);
    uVar5 = *(uint *)(iVar6 + 0x2ca74);
    iVar7 = *(int *)(iVar6 + 0x2ca68);
    iVar6 = func_0x00488eb0(*(undefined4 *)(iVar6 + 0x2ca68));
    func_0x00486cd0(auStack_14);
    uStack_8._0_1_ = 2;
    uStack_8._1_3_ = 0;
    if (iVar6 != 0) {
      if (iVar7 == 0x4f09) {
        _tr_QMetaObject__QBE_AVQString__PBD0H_Z(&uStack_24,&UNK_00584b74,0,0xffffffff);
        uStack_8._0_1_ = 3;
      }
      else {
        _tr_QMetaObject__QBE_AVQString__PBD0H_Z(&uStack_24,&UNK_00584b88,0,0xffffffff);
        uStack_8._0_1_ = 4;
      }
      _append_QString__QAEAAV1_ABV1__Z(&uStack_24);
      uStack_8._0_1_ = 2;
      __1QString__QAE_XZ();
      __0QFile__QAE_XZ();
      uStack_8._0_1_ = 5;
      iVar7 = func_0x00486ef0(auStack_2c,auStack_14,1,1);
      if (iVar7 != 0) {
        uVar8 = _size_QFile__UBE_JXZ();
        iStack_20 = func_0x00519367(uVar8);
        func_0x004908a0(iStack_20,uStack_24);
        uStack_8._0_1_ = 6;
        _read_QIODevice__QAE_JPAD_J_Z(iStack_20,uVar8,0);
        _close_QFileDevice__UAEXXZ();
        puVar2 = *(undefined4 **)(iVar6 + 0x48);
        if ((uint)(puVar2[3] + puVar2[2]) < uVar5 + 0x8000) {
          _tr_QMetaObject__QBE_AVQString__PBD0H_Z(&uStack_24,&UNK_00584550,0,0xffffffff);
          uStack_8._0_1_ = 7;
          func_0x00486bb0(&uStack_24);
          __1QString__QAE_XZ();
LAB_0049e62a:
          uStack_8._0_1_ = 8;
        }
        else {
          uVar9 = uVar5;
          if (uVar5 < uVar5 + 0x8000) {
            do {
              cVar4 = func_0x005063a0(*puVar2,uVar9);
              if (cVar4 == '\0') {
                func_0x00486c20(&UNK_00584528,uVar9);
                goto LAB_0049e62a;
              }
              uVar9 = uVar9 + puVar2[1];
            } while (uVar9 < uVar5 + 0x8000);
          }
          _show_QWidget__QAEXXZ();
          _setDisabled_QWidget__QAEX_N_Z(1);
          func_0x004a3330(*puVar2,uVar5,iStack_20 + 0x9000,0x8000);
          _hide_QWidget__QAEXXZ();
          _setDisabled_QWidget__QAEX_N_Z(0);
          uStack_8._0_1_ = 9;
        }
        piVar3 = piStack_1c;
        if (piStack_1c != (int *)0x0) {
          LOCK();
          iVar6 = piStack_1c[1] + -1;
          piStack_1c[1] = iVar6;
          UNLOCK();
          if (iVar6 == 0) {
            (**(code **)(*piStack_1c + 4))();
            LOCK();
            piVar1 = piVar3 + 2;
            iVar6 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar6 == 1) {
              (**(code **)(*piVar3 + 8))();
            }
          }
        }
      }
      __1QFile__UAE_XZ();
    }
    __1QString__QAE_XZ();
  }
  *unaff_FS_OFFSET = iStack_10;
  return;
}


