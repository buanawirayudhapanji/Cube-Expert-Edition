
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004a42c0(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int *unaff_FS_OFFSET;
  int iStack_2c;
  undefined1 auStack_28 [8];
  undefined4 uStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &UNK_00527f09;
  iStack_10 = *unaff_FS_OFFSET;
  uVar2 = _DAT_00759b24 ^ (uint)(auStack_28 + 0x24);
  *unaff_FS_OFFSET = (int)&iStack_10;
  iStack_1c = param_1;
  _hide_QWidget__QAEXXZ(uVar2);
  uStack_20 = CONCAT31(uStack_20._1_3_,0x20);
  iVar7 = 0;
  do {
    uStack_14 = *(undefined4 *)(param_1 + 0x1c);
    uVar3 = __0QVariant__QAE_XZ();
    uStack_8 = 0;
    uStack_18 = _fromAscii_helper_QString__CAPAU__QTypedArrayData_G__PBDH_Z(&UNK_00580d28,2);
    uStack_8._0_1_ = 1;
    iStack_2c = iVar7 + 1;
    __0QChar__QAE_UQLatin1Char___Z(uStack_20);
    uVar4 = _arg_QString__QBE_AV1_HHHVQChar___Z(auStack_28,iVar7 + 1,0,10);
    uStack_8._0_1_ = 2;
    uVar5 = _count_QComboBox__QBEHXZ();
    uVar6 = __0QIcon__QAE_XZ();
    uStack_8 = CONCAT31(uStack_8._1_3_,3);
    _insertItem_QComboBox__QAEXHABVQIcon__ABVQString__ABVQVariant___Z(uVar5,uVar6,uVar4,uVar3);
    __1QIcon__QAE_XZ();
    __1QString__QAE_XZ();
    __1QString__QAE_XZ();
    uStack_8 = 0xffffffff;
    __1QVariant__QAE_XZ();
    iVar1 = iStack_1c;
    param_1 = iStack_1c;
    iVar7 = iStack_2c;
  } while (iStack_2c < 8);
  _connect_QObject__SA_AVConnection_QMetaObject__PBV1_PBD01W4ConnectionType_Qt___Z
            (&iStack_2c,*(undefined4 *)(iStack_1c + 0x24),&UNK_00580e20,iStack_1c,&UNK_00584344,0);
  __1Connection_QMetaObject__QAE_XZ();
  _connect_QObject__SA_AVConnection_QMetaObject__PBV1_PBD01W4ConnectionType_Qt___Z
            (&iStack_2c,*(undefined4 *)(iVar1 + 0x34),&UNK_00580e20,iVar1,&UNK_00584354,0);
  __1Connection_QMetaObject__QAE_XZ();
  _connect_QObject__SA_AVConnection_QMetaObject__PBV1_PBD01W4ConnectionType_Qt___Z
            (&iStack_2c,*(undefined4 *)(iVar1 + 0x40),&UNK_00580e20,iVar1,&UNK_00584360,0);
  __1Connection_QMetaObject__QAE_XZ();
  _connect_QObject__SA_AVConnection_QMetaObject__PBV1_PBD01W4ConnectionType_Qt___Z
            (&iStack_2c,*(undefined4 *)(iVar1 + 0x3c),&UNK_00580e20,iVar1,&UNK_00584370,0);
  __1Connection_QMetaObject__QAE_XZ();
  _connect_QObject__SA_AVConnection_QMetaObject__PBV1_PBD01W4ConnectionType_Qt___Z
            (&iStack_2c,*(undefined4 *)(iVar1 + 0x30),&UNK_005843a4,iVar1,&UNK_00584380,0);
  __1Connection_QMetaObject__QAE_XZ();
  _connect_QObject__SA_AVConnection_QMetaObject__PBV1_PBD01W4ConnectionType_Qt___Z
            (&iStack_2c,*(undefined4 *)(iVar1 + 0x28),&UNK_005843d8,iVar1,&UNK_005843c4,0);
  __1Connection_QMetaObject__QAE_XZ();
  _connect_QObject__SA_AVConnection_QMetaObject__PBV1_PBD01W4ConnectionType_Qt___Z
            (auStack_28,*(undefined4 *)(iVar1 + 0x28),&UNK_00584400,iVar1,&UNK_005843ec,0);
  __1Connection_QMetaObject__QAE_XZ();
  *unaff_FS_OFFSET = iStack_10;
  return;
}


