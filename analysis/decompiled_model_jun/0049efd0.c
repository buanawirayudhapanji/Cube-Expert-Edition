
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0049efd0(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  int *unaff_FS_OFFSET;
  int iStack_2c;
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [4];
  undefined4 uStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  int iStack_14;
  int iStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &UNK_0052673a;
  iStack_10 = *unaff_FS_OFFSET;
  uVar1 = _DAT_00759b24 ^ (uint)(auStack_24 + 0x20);
  *unaff_FS_OFFSET = (int)&iStack_10;
  iStack_14 = param_1;
  _hide_QWidget__QAEXXZ(uVar1);
  uStack_20 = CONCAT31(uStack_20._1_3_,0x20);
  iVar6 = 0;
  do {
    uStack_18 = *(undefined4 *)(param_1 + 0x1c);
    uVar2 = __0QVariant__QAE_XZ();
    uStack_8 = 0;
    iStack_1c = _fromAscii_helper_QString__CAPAU__QTypedArrayData_G__PBDH_Z(&UNK_00580d28,2);
    uStack_8._0_1_ = 1;
    iStack_2c = iVar6 + 1;
    __0QChar__QAE_UQLatin1Char___Z(uStack_20);
    uVar3 = _arg_QString__QBE_AV1_HHHVQChar___Z(auStack_28,iVar6 + 1,0,10);
    uStack_8._0_1_ = 2;
    uVar4 = _count_QComboBox__QBEHXZ();
    uVar5 = __0QIcon__QAE_XZ();
    uStack_8 = CONCAT31(uStack_8._1_3_,3);
    _insertItem_QComboBox__QAEXHABVQIcon__ABVQString__ABVQVariant___Z(uVar4,uVar5,uVar3,uVar2);
    __1QIcon__QAE_XZ();
    __1QString__QAE_XZ();
    __1QString__QAE_XZ();
    __1QVariant__QAE_XZ();
    param_1 = iStack_14;
    iVar6 = iStack_2c;
  } while (iStack_2c < 8);
  uVar2 = __0QVariant__QAE_XZ();
  uStack_8 = 4;
  iStack_1c = _fromAscii_helper_QString__CAPAU__QTypedArrayData_G__PBDH_Z(&UNK_005842d0,1);
  uStack_8._0_1_ = 5;
  uVar3 = _count_QComboBox__QBEHXZ();
  uVar4 = __0QIcon__QAE_XZ();
  uStack_8 = CONCAT31(uStack_8._1_3_,6);
  _insertItem_QComboBox__QAEXHABVQIcon__ABVQString__ABVQVariant___Z(uVar3,uVar4,&iStack_1c,uVar2);
  __1QIcon__QAE_XZ();
  __1QString__QAE_XZ();
  __1QVariant__QAE_XZ();
  uVar2 = __0QVariant__QAE_XZ();
  uStack_8 = 7;
  iStack_1c = _fromAscii_helper_QString__CAPAU__QTypedArrayData_G__PBDH_Z(&UNK_005842d4,1);
  uStack_8._0_1_ = 8;
  uVar3 = _count_QComboBox__QBEHXZ();
  uVar4 = __0QIcon__QAE_XZ();
  uStack_8 = CONCAT31(uStack_8._1_3_,9);
  _insertItem_QComboBox__QAEXHABVQIcon__ABVQString__ABVQVariant___Z(uVar3,uVar4,&iStack_1c,uVar2);
  __1QIcon__QAE_XZ();
  __1QString__QAE_XZ();
  __1QVariant__QAE_XZ();
  uVar2 = __0QVariant__QAE_XZ();
  uStack_8 = 10;
  iStack_1c = _fromAscii_helper_QString__CAPAU__QTypedArrayData_G__PBDH_Z(&UNK_0058263c,1);
  uStack_8._0_1_ = 0xb;
  uVar3 = _count_QComboBox__QBEHXZ();
  uVar4 = __0QIcon__QAE_XZ();
  uStack_8 = CONCAT31(uStack_8._1_3_,0xc);
  _insertItem_QComboBox__QAEXHABVQIcon__ABVQString__ABVQVariant___Z(uVar3,uVar4,&iStack_1c,uVar2);
  __1QIcon__QAE_XZ();
  __1QString__QAE_XZ();
  uStack_8 = 0xffffffff;
  __1QVariant__QAE_XZ();
  iVar6 = iStack_14;
  _connect_QObject__SA_AVConnection_QMetaObject__PBV1_PBD01W4ConnectionType_Qt___Z
            (&iStack_2c,*(undefined4 *)(iStack_14 + 0x48),&UNK_005842f0,iStack_14,&UNK_005842d8,0);
  __1Connection_QMetaObject__QAE_XZ();
  _connect_QObject__SA_AVConnection_QMetaObject__PBV1_PBD01W4ConnectionType_Qt___Z
            (&iStack_2c,*(undefined4 *)(iVar6 + 0x9c),&UNK_00580e20,iVar6,&UNK_0058430c,0);
  __1Connection_QMetaObject__QAE_XZ();
  _connect_QObject__SA_AVConnection_QMetaObject__PBV1_PBD01W4ConnectionType_Qt___Z
            (&iStack_2c,*(undefined4 *)(iVar6 + 0xec),&UNK_00584334,iVar6,&UNK_0058431c,0);
  __1Connection_QMetaObject__QAE_XZ();
  _connect_QObject__SA_AVConnection_QMetaObject__PBV1_PBD01W4ConnectionType_Qt___Z
            (&iStack_2c,*(undefined4 *)(iVar6 + 0x24),&UNK_00580e20,iVar6,&UNK_00584344,0);
  __1Connection_QMetaObject__QAE_XZ();
  _connect_QObject__SA_AVConnection_QMetaObject__PBV1_PBD01W4ConnectionType_Qt___Z
            (&iStack_2c,*(undefined4 *)(iVar6 + 0x34),&UNK_00580e20,iVar6,&UNK_00584354,0);
  __1Connection_QMetaObject__QAE_XZ();
  _connect_QObject__SA_AVConnection_QMetaObject__PBV1_PBD01W4ConnectionType_Qt___Z
            (&iStack_2c,*(undefined4 *)(iVar6 + 0x40),&UNK_00580e20,iVar6,&UNK_00584360,0);
  __1Connection_QMetaObject__QAE_XZ();
  _connect_QObject__SA_AVConnection_QMetaObject__PBV1_PBD01W4ConnectionType_Qt___Z
            (&iStack_2c,*(undefined4 *)(iVar6 + 0x3c),&UNK_00580e20,iVar6,&UNK_00584370,0);
  __1Connection_QMetaObject__QAE_XZ();
  _connect_QObject__SA_AVConnection_QMetaObject__PBV1_PBD01W4ConnectionType_Qt___Z
            (&iStack_2c,*(undefined4 *)(iVar6 + 0x30),&UNK_005843a4,iVar6,&UNK_00584380,0);
  __1Connection_QMetaObject__QAE_XZ();
  _connect_QObject__SA_AVConnection_QMetaObject__PBV1_PBD01W4ConnectionType_Qt___Z
            (&iStack_2c,*(undefined4 *)(iVar6 + 0x28),&UNK_005843d8,iVar6,&UNK_005843c4,0);
  __1Connection_QMetaObject__QAE_XZ();
  _connect_QObject__SA_AVConnection_QMetaObject__PBV1_PBD01W4ConnectionType_Qt___Z
            (&iStack_2c,*(undefined4 *)(iVar6 + 0x28),&UNK_00584400,iVar6,&UNK_005843ec,0);
  __1Connection_QMetaObject__QAE_XZ();
  _connect_QObject__SA_AVConnection_QMetaObject__PBV1_PBD01W4ConnectionType_Qt___Z
            (&iStack_2c,*(undefined4 *)(iVar6 + 200),&UNK_00580e20,iVar6,&UNK_00584414,0);
  __1Connection_QMetaObject__QAE_XZ();
  _connect_QObject__SA_AVConnection_QMetaObject__PBV1_PBD01W4ConnectionType_Qt___Z
            (&iStack_2c,*(undefined4 *)(iVar6 + 0xdc),&UNK_00580e20,iVar6,&UNK_00584420,0);
  __1Connection_QMetaObject__QAE_XZ();
  _connect_QObject__SA_AVConnection_QMetaObject__PBV1_PBD01W4ConnectionType_Qt___Z
            (&iStack_2c,*(undefined4 *)(iVar6 + 0xe0),&UNK_00580e20,iVar6,&UNK_0058442c,0);
  __1Connection_QMetaObject__QAE_XZ();
  puVar7 = (undefined4 *)(iVar6 + 0x170);
  iStack_1c = 10;
  do {
    _connect_QObject__SA_AVConnection_QMetaObject__PBV1_PBD01W4ConnectionType_Qt___Z
              (&iStack_2c,*puVar7,&UNK_005843d8,puVar7[10],&UNK_00584438,0);
    __1Connection_QMetaObject__QAE_XZ();
    _connect_QObject__SA_AVConnection_QMetaObject__PBV1_PBD01W4ConnectionType_Qt___Z
              (auStack_28,puVar7[10],&UNK_005843d8,*puVar7,&UNK_00584438,0);
    __1Connection_QMetaObject__QAE_XZ();
    _connect_QObject__SA_AVConnection_QMetaObject__PBV1_PBD01W4ConnectionType_Qt___Z
              (auStack_24,*puVar7,&UNK_005843d8,iStack_14,&UNK_00584448,0);
    __1Connection_QMetaObject__QAE_XZ();
    iStack_1c = iStack_1c + -1;
    puVar7 = puVar7 + 1;
  } while (iStack_1c != 0);
  *unaff_FS_OFFSET = iStack_10;
  return;
}


