
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050a660(int *param_1)

{
  code *pcVar1;
  code *pcVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int *unaff_FS_OFFSET;
  longlong lVar7;
  undefined *puVar8;
  undefined1 auStack_54 [4];
  undefined1 auStack_50 [4];
  undefined1 auStack_4c [4];
  int iStack_48;
  uint uStack_44;
  int iStack_40;
  int *piStack_3c;
  char cStack_35;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined2 uStack_24;
  undefined8 uStack_20;
  undefined2 uStack_18;
  uint uStack_14;
  int iStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &UNK_0055326d;
  iStack_10 = *unaff_FS_OFFSET;
  uStack_14 = _DAT_00759b24 ^ (uint)(auStack_4c + 0x48);
  *unaff_FS_OFFSET = (int)&iStack_10;
  piStack_3c = param_1;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_18 = 0;
  _read_QIODevice__QAE_JPAD_J_Z(&uStack_20,4,0,uStack_14);
  if ((int)uStack_20 == 0x46464952) {
    _read_QIODevice__QAE_JPAD_J_Z(auStack_54,4,0);
    _read_QIODevice__QAE_JPAD_J_Z(&uStack_20,4,0);
    if ((int)uStack_20 == 0x45564157) {
      cStack_35 = '\0';
      lVar7 = _read_QIODevice__QAE_JPAD_J_Z(&iStack_48,8,0);
      if (lVar7 != 0) {
        do {
          if (iStack_48 == 0x61746164) {
            if (cStack_35 == '\0') goto LAB_0050a8bd;
            *(short *)(iStack_40 + 0x14) = (short)uStack_34;
            *(undefined2 *)(iStack_40 + 0x16) = uStack_34._2_2_;
            *(undefined2 *)(iStack_40 + 0x18) = (undefined2)uStack_30;
            *(undefined2 *)(iStack_40 + 0x1a) = uStack_30._2_2_;
            *(undefined2 *)(iStack_40 + 0x1c) = (undefined2)uStack_2c;
            *(undefined2 *)(iStack_40 + 0x1e) = uStack_2c._2_2_;
            *(undefined2 *)(iStack_40 + 0x20) = (undefined2)uStack_28;
            *(undefined2 *)(iStack_40 + 0x22) = uStack_28._2_2_;
            *(undefined2 *)(iStack_40 + 0x24) = uStack_24;
            func_0x0050b750(uStack_44 / (uStack_28 & 0xffff),uStack_28 & 0xffff);
            uVar4 = func_0x0050b700(uStack_44,0);
            _read_QIODevice__QAE_JPAD_J_Z(uVar4);
            goto LAB_0050a90b;
          }
          pcVar1 = *(code **)(*param_1 + 0x38);
          if (iStack_48 == 0x20746d66) {
            cStack_35 = '\x01';
            iVar5 = (*pcVar1)();
            iVar5 = uStack_44 + iVar5;
            uVar6 = uStack_44;
            if (0x12 < uStack_44) {
              uVar6 = 0x12;
            }
            _read_QIODevice__QAE_JPAD_J_Z(&uStack_34,uVar6,0);
            (**(code **)(*param_1 + 0x40))(iVar5,0);
            if ((short)uStack_34 != 1) goto LAB_0050a90b;
          }
          else {
            pcVar2 = *(code **)(*param_1 + 0x40);
            lVar7 = (*pcVar1)();
            cVar3 = (*pcVar2)(lVar7 + (ulonglong)uStack_44);
            if (cVar3 == '\0') break;
          }
          lVar7 = _read_QIODevice__QAE_JPAD_J_Z(&iStack_48,8,0);
        } while (lVar7 != 0);
        if (cStack_35 != '\0') {
          (**(code **)(*param_1 + 0x6c))(auStack_50);
          uStack_8 = 6;
          _toLatin1_QString__QHAE_AVQByteArray__XZ(auStack_4c);
          uStack_8 = CONCAT31(uStack_8._1_3_,7);
          uVar4 = _data_QByteArray__QAEPADXZ();
          func_0x00486c20(&UNK_005936b8,uVar4);
          __1QByteArray__QAE_XZ();
          goto LAB_0050a903;
        }
      }
LAB_0050a8bd:
      (**(code **)(*param_1 + 0x6c))(&piStack_3c);
      uStack_8 = 4;
      _toLatin1_QString__QHAE_AVQByteArray__XZ(&iStack_40);
      uStack_8 = CONCAT31(uStack_8._1_3_,5);
      uVar4 = _data_QByteArray__QAEPADXZ();
      puVar8 = &UNK_00593694;
    }
    else {
      (**(code **)(*param_1 + 0x6c))(&piStack_3c);
      uStack_8 = 2;
      _toLatin1_QString__QHAE_AVQByteArray__XZ(&iStack_40);
      uStack_8 = CONCAT31(uStack_8._1_3_,3);
      uVar4 = _data_QByteArray__QAEPADXZ();
      puVar8 = &UNK_00593674;
    }
    func_0x00486c20(puVar8,uVar4);
    __1QByteArray__QAE_XZ();
  }
  else {
    (**(code **)(*param_1 + 0x6c))(&iStack_40);
    uStack_8 = 0;
    _toLatin1_QString__QHAE_AVQByteArray__XZ(&piStack_3c);
    uStack_8 = CONCAT31(uStack_8._1_3_,1);
    uVar4 = _data_QByteArray__QAEPADXZ();
    func_0x00486c20(&UNK_00593654,uVar4);
    __1QByteArray__QAE_XZ();
  }
LAB_0050a903:
  __1QString__QAE_XZ();
LAB_0050a90b:
  *unaff_FS_OFFSET = iStack_10;
  func_0x005195c6();
  return;
}


