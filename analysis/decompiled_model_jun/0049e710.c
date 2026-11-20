
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0049e710(int param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  int *piVar6;
  int *unaff_FS_OFFSET;
  undefined1 auStack_4c [16];
  undefined1 auStack_3c [16];
  undefined1 auStack_2c [4];
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [4];
  int iStack_20;
  undefined1 auStack_1c [4];
  undefined4 uStack_18;
  undefined1 auStack_14 [4];
  int iStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &UNK_00526636;
  iStack_10 = *unaff_FS_OFFSET;
  uVar4 = _DAT_00759b24 ^ (uint)(auStack_14 + 0x10);
  *unaff_FS_OFFSET = (int)&iStack_10;
  _tr_QMetaObject__QBE_AVQString__PBD0H_Z(auStack_1c,&UNK_00584464,0,0xffffffff,uVar4);
  uStack_8 = 0;
  uVar5 = __0QVariant__QAE_XZ();
  uStack_8._0_1_ = 1;
  uStack_18 = _fromAscii_helper_QString__CAPAU__QTypedArrayData_G__PBDH_Z(&UNK_00584478,0x11);
  uStack_8._0_1_ = 2;
  func_0x00487a10(auStack_4c,&uStack_18,uVar5);
  uStack_8._0_1_ = 3;
  uVar5 = _toString_QVariant__QBE_AVQString__XZ(auStack_28);
  uStack_8._0_1_ = 4;
  _tr_QMetaObject__QBE_AVQString__PBD0H_Z(auStack_14,&UNK_0058448c,0,0xffffffff);
  uStack_8 = CONCAT31(uStack_8._1_3_,5);
  piVar6 = (int *)_getOpenFileNames_QFileDialog__SA_AVQStringList__PAVQWidget__ABVQString__11PAV4_V__QFlags_W4Option_QFileDialog_____Z
                            (auStack_24,param_1,auStack_14,uVar5,auStack_1c,0,0);
  piVar1 = (int *)(param_1 + 0xfc);
  iVar2 = *piVar6;
  *piVar6 = (int)_shared_null_QListData__2UData_1_B_exref;
  iStack_20 = *piVar1;
  *piVar1 = iVar2;
  func_0x00486b10();
  func_0x00486b10();
  __1QString__QAE_XZ();
  __1QString__QAE_XZ();
  __1QVariant__QAE_XZ();
  __1QString__QAE_XZ();
  __1QVariant__QAE_XZ();
  uStack_8 = 0xffffffff;
  __1QString__QAE_XZ();
  cVar3 = _isEmpty_QListData__QBE_NXZ();
  if (cVar3 == '\0') {
    if ((*(int *)*piVar1 != 1) && (*(int *)*piVar1 != 0)) {
      func_0x004875a0(*(undefined4 *)(*piVar1 + 4));
    }
    uVar5 = _at_QListData__QBEPAPAXH_Z(0);
    uVar5 = func_0x004876a0(auStack_2c,uVar5);
    uStack_8 = 6;
    __0QVariant__QAE_ABVQString___Z(uVar5);
    uStack_8._0_1_ = 7;
    iStack_20 = _fromAscii_helper_QString__CAPAU__QTypedArrayData_G__PBDH_Z(&UNK_00584478,0x11);
    uStack_8 = CONCAT31(uStack_8._1_3_,8);
    func_0x00487c00(&iStack_20,auStack_3c);
    __1QString__QAE_XZ();
    __1QVariant__QAE_XZ();
    uStack_8 = 0xffffffff;
    __1QString__QAE_XZ();
    _clear_QListWidget__QAEXXZ();
    uVar5 = _count_QListWidget__QBEHXZ(piVar1);
    _insertItems_QListWidget__QAEXHABVQStringList___Z(uVar5);
  }
  *unaff_FS_OFFSET = iStack_10;
  return;
}


