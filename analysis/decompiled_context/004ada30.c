
void __fastcall FUN_004ada30(QObject *param_1)

{
  QLabel *pQVar1;
  QObject QVar2;
  uint uVar3;
  QObject *pQVar4;
  undefined4 uVar5;
  QString *pQVar6;
  int *piVar7;
  int iVar8;
  undefined4 uVar9;
  QString local_20 [4];
  QString local_1c [4];
  QString local_18 [4];
  QComboBox *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00530809;
  local_10 = ExceptionList;
  uVar3 = DAT_00759b24 ^ (uint)(local_18 + 0x14);
  ExceptionList = &local_10;
  pQVar4 = QObject::sender(param_1);
  if (pQVar4 == *(QObject **)(param_1 + 0x9ac)) {
    piVar7 = *(int **)(param_1 + 0x9ec);
  }
  else {
    if (pQVar4 == *(QObject **)(param_1 + 0x9b4)) {
      *(undefined4 *)(param_1 + 0x68c8) = 0;
      QVar2 = param_1[(uint)(byte)param_1[0x6691] * 0xc + 0x3eb5];
      iVar8 = (byte)QVar2 - 0x3e;
      if (((QVar2 == (QObject)0x0) || (iVar8 < 1)) || (iVar8 < 4)) {
        if ((QVar2 == (QObject)0x0) || (iVar8 < 1)) {
          iVar8 = 0;
        }
      }
      else {
        iVar8 = 4;
      }
      QComboBox::setCurrentIndex(*(QComboBox **)(param_1 + 0x9cc),iVar8);
      QVar2 = param_1[(*(int *)(param_1 + 0x68c8) + (uint)(byte)param_1[0x6691] * 4) * 3 + 0x3eb6];
      iVar8 = (byte)QVar2 - 0x3e;
      if (((QVar2 == (QObject)0x0) || (iVar8 < 1)) || (iVar8 < 4)) {
        if ((QVar2 == (QObject)0x0) || (iVar8 < 1)) {
          iVar8 = 0;
        }
      }
      else {
        iVar8 = 4;
      }
      QComboBox::setCurrentIndex(*(QComboBox **)(param_1 + 0x9d0),iVar8);
      local_14 = *(QComboBox **)(param_1 + 0x9d4);
      QVar2 = param_1[(*(int *)(param_1 + 0x68c8) + (uint)(byte)param_1[0x6691] * 4) * 3 + 0x3eb7];
      iVar8 = QListData::size((QListData *)(param_1 + 0x68d0));
      if ((int)(-(uint)(QVar2 != (QObject)0x0) & (uint)(byte)QVar2) < iVar8 + -1) {
        uVar3 = -(uint)(param_1[(*(int *)(param_1 + 0x68c8) + (uint)(byte)param_1[0x6691] * 4) * 3 +
                                0x3eb7] != (QObject)0x0) &
                (uint)(byte)param_1[(*(int *)(param_1 + 0x68c8) + (uint)(byte)param_1[0x6691] * 4) *
                                    3 + 0x3eb7];
      }
      else {
        iVar8 = QListData::size((QListData *)(param_1 + 0x68d0));
        uVar3 = iVar8 - 1;
      }
      QComboBox::setCurrentIndex(local_14,uVar3);
      (**(code **)(**(int **)(param_1 + 0x9c8) + 0x2c))
                (~(byte)(*(uint *)((*(int **)(param_1 + 0x9c8))[5] + 4) >> 0xf) & 1);
      ExceptionList = local_10;
      return;
    }
    if (pQVar4 == *(QObject **)(param_1 + 0x9b8)) {
      *(undefined4 *)(param_1 + 0x68c8) = 1;
      QVar2 = param_1[((byte)param_1[0x6691] + 0x53a) * 0xc];
      iVar8 = (byte)QVar2 - 0x3e;
      if (((QVar2 == (QObject)0x0) || (iVar8 < 1)) || (iVar8 < 4)) {
        if ((QVar2 == (QObject)0x0) || (iVar8 < 1)) {
          iVar8 = 0;
        }
      }
      else {
        iVar8 = 4;
      }
      QComboBox::setCurrentIndex(*(QComboBox **)(param_1 + 0x9cc),iVar8);
      QVar2 = param_1[(*(int *)(param_1 + 0x68c8) + (uint)(byte)param_1[0x6691] * 4) * 3 + 0x3eb6];
      iVar8 = (byte)QVar2 - 0x3e;
      if (((QVar2 == (QObject)0x0) || (iVar8 < 1)) || (iVar8 < 4)) {
        if ((QVar2 == (QObject)0x0) || (iVar8 < 1)) {
          iVar8 = 0;
        }
      }
      else {
        iVar8 = 4;
      }
      QComboBox::setCurrentIndex(*(QComboBox **)(param_1 + 0x9d0),iVar8);
      local_14 = *(QComboBox **)(param_1 + 0x9d4);
      QVar2 = param_1[(*(int *)(param_1 + 0x68c8) + (uint)(byte)param_1[0x6691] * 4) * 3 + 0x3eb7];
      iVar8 = QListData::size((QListData *)(param_1 + 0x68d0));
      if ((int)(-(uint)(QVar2 != (QObject)0x0) & (uint)(byte)QVar2) < iVar8 + -1) {
        uVar3 = -(uint)(param_1[(*(int *)(param_1 + 0x68c8) + (uint)(byte)param_1[0x6691] * 4) * 3 +
                                0x3eb7] != (QObject)0x0) &
                (uint)(byte)param_1[(*(int *)(param_1 + 0x68c8) + (uint)(byte)param_1[0x6691] * 4) *
                                    3 + 0x3eb7];
      }
      else {
        iVar8 = QListData::size((QListData *)(param_1 + 0x68d0));
        uVar3 = iVar8 - 1;
      }
      QComboBox::setCurrentIndex(local_14,uVar3);
      (**(code **)(**(int **)(param_1 + 0x9c8) + 0x2c))
                (~(byte)(*(uint *)((*(int **)(param_1 + 0x9c8))[5] + 4) >> 0xf) & 1);
      ExceptionList = local_10;
      return;
    }
    if (pQVar4 == *(QObject **)(param_1 + 0x9bc)) {
      *(undefined4 *)(param_1 + 0x68c8) = 2;
      QVar2 = param_1[(uint)(byte)param_1[0x6691] * 0xc + 0x3ebb];
      iVar8 = (byte)QVar2 - 0x3e;
      if (((QVar2 == (QObject)0x0) || (iVar8 < 1)) || (iVar8 < 4)) {
        if ((QVar2 == (QObject)0x0) || (iVar8 < 1)) {
          iVar8 = 0;
        }
      }
      else {
        iVar8 = 4;
      }
      QComboBox::setCurrentIndex(*(QComboBox **)(param_1 + 0x9cc),iVar8);
      QVar2 = param_1[(*(int *)(param_1 + 0x68c8) + (uint)(byte)param_1[0x6691] * 4) * 3 + 0x3eb6];
      iVar8 = (byte)QVar2 - 0x3e;
      if (((QVar2 == (QObject)0x0) || (iVar8 < 1)) || (iVar8 < 4)) {
        if ((QVar2 == (QObject)0x0) || (iVar8 < 1)) {
          iVar8 = 0;
        }
      }
      else {
        iVar8 = 4;
      }
      QComboBox::setCurrentIndex(*(QComboBox **)(param_1 + 0x9d0),iVar8);
      local_14 = *(QComboBox **)(param_1 + 0x9d4);
      QVar2 = param_1[(*(int *)(param_1 + 0x68c8) + (uint)(byte)param_1[0x6691] * 4) * 3 + 0x3eb7];
      iVar8 = QListData::size((QListData *)(param_1 + 0x68d0));
      if ((int)(-(uint)(QVar2 != (QObject)0x0) & (uint)(byte)QVar2) < iVar8 + -1) {
        uVar3 = -(uint)(param_1[(*(int *)(param_1 + 0x68c8) + (uint)(byte)param_1[0x6691] * 4) * 3 +
                                0x3eb7] != (QObject)0x0) &
                (uint)(byte)param_1[(*(int *)(param_1 + 0x68c8) + (uint)(byte)param_1[0x6691] * 4) *
                                    3 + 0x3eb7];
      }
      else {
        iVar8 = QListData::size((QListData *)(param_1 + 0x68d0));
        uVar3 = iVar8 - 1;
      }
      QComboBox::setCurrentIndex(local_14,uVar3);
      (**(code **)(**(int **)(param_1 + 0x9c8) + 0x2c))
                (~(byte)(*(uint *)((*(int **)(param_1 + 0x9c8))[5] + 4) >> 0xf) & 1);
      ExceptionList = local_10;
      return;
    }
    if (pQVar4 != *(QObject **)(param_1 + 0x9c4)) {
      if (pQVar4 == *(QObject **)(param_1 + 0xa20)) {
        *(undefined4 *)(param_1 + 0x68cc) = 0;
        FUN_004bd9b0();
        ExceptionList = local_10;
        return;
      }
      if (pQVar4 == *(QObject **)(param_1 + 0xa24)) {
        *(undefined4 *)(param_1 + 0x68cc) = 1;
        FUN_004bd9b0();
        ExceptionList = local_10;
        return;
      }
      if (pQVar4 == *(QObject **)(param_1 + 0xa28)) {
        *(undefined4 *)(param_1 + 0x68cc) = 2;
        FUN_004bd9b0();
        ExceptionList = local_10;
        return;
      }
      if (pQVar4 == *(QObject **)(param_1 + 0xa30)) {
        *(undefined4 *)(param_1 + 0x68cc) = 3;
        FUN_004bd9b0();
        ExceptionList = local_10;
        return;
      }
      if (pQVar4 == *(QObject **)(param_1 + 0x9a4)) {
        if (param_1[0xa3a] != (QObject)0x0) {
          pQVar1 = *(QLabel **)(param_1 + 0x9a0);
          QVar2 = (QObject)((char)param_1[0xa3a] - 1);
          param_1[0xa3a] = QVar2;
          iVar8 = (byte)QVar2 + 1;
          uVar9 = 10;
          pQVar6 = local_18;
          uVar5 = QString::number((int)pQVar6,iVar8);
          local_8 = 0;
          pQVar6 = (QString *)
                   FUN_004aca10(&local_14,"Send on MIDI Channel:",uVar5,pQVar6,iVar8,uVar9);
          local_8 = CONCAT31(local_8._1_3_,1);
          QLabel::setText(pQVar1,pQVar6);
          QString::~QString((QString *)&local_14);
          pQVar6 = local_18;
LAB_004ae158:
          local_8 = 0xffffffff;
          QString::~QString(pQVar6);
          FUN_004b6c90(2,param_1 + 0xa3a,1,param_1);
          ExceptionList = local_10;
          return;
        }
      }
      else if (pQVar4 == *(QObject **)(param_1 + 0x9a8)) {
        if (param_1[0xa3a] != (QObject)0xf) {
          pQVar1 = *(QLabel **)(param_1 + 0x9a0);
          QVar2 = (QObject)((char)param_1[0xa3a] + 1);
          param_1[0xa3a] = QVar2;
          iVar8 = (byte)QVar2 + 1;
          uVar9 = 10;
          pQVar6 = local_20;
          uVar5 = QString::number((int)pQVar6,iVar8);
          local_8 = 2;
          pQVar6 = (QString *)
                   FUN_004aca10(local_1c,"Send on MIDI Channel:",uVar5,pQVar6,iVar8,uVar9);
          local_8 = CONCAT31(local_8._1_3_,3);
          QLabel::setText(pQVar1,pQVar6);
          QString::~QString(local_1c);
          pQVar6 = local_20;
          goto LAB_004ae158;
        }
      }
      else if (pQVar4 == *(QObject **)(param_1 + 0x9e8)) {
        (**(code **)(**(int **)(param_1 + 0x9c8) + 0x2c))(0,uVar3);
      }
      ExceptionList = local_10;
      return;
    }
    *(undefined4 *)(param_1 + 0x68c8) = 3;
    QVar2 = param_1[(uint)(byte)param_1[0x6691] * 0xc + 0x3ebe];
    iVar8 = (byte)QVar2 - 0x3e;
    if (((QVar2 == (QObject)0x0) || (iVar8 < 1)) || (iVar8 < 4)) {
      if ((QVar2 == (QObject)0x0) || (iVar8 < 1)) {
        iVar8 = 0;
      }
    }
    else {
      iVar8 = 4;
    }
    QComboBox::setCurrentIndex(*(QComboBox **)(param_1 + 0x9cc),iVar8);
    QVar2 = param_1[(*(int *)(param_1 + 0x68c8) + (uint)(byte)param_1[0x6691] * 4) * 3 + 0x3eb6];
    iVar8 = (byte)QVar2 - 0x3e;
    if (((QVar2 == (QObject)0x0) || (iVar8 < 1)) || (iVar8 < 4)) {
      if ((QVar2 == (QObject)0x0) || (iVar8 < 1)) {
        iVar8 = 0;
      }
    }
    else {
      iVar8 = 4;
    }
    QComboBox::setCurrentIndex(*(QComboBox **)(param_1 + 0x9d0),iVar8);
    local_14 = *(QComboBox **)(param_1 + 0x9d4);
    QVar2 = param_1[(*(int *)(param_1 + 0x68c8) + (uint)(byte)param_1[0x6691] * 4) * 3 + 0x3eb7];
    iVar8 = QListData::size((QListData *)(param_1 + 0x68d0));
    if ((int)(-(uint)(QVar2 != (QObject)0x0) & (uint)(byte)QVar2) < iVar8 + -1) {
      uVar3 = -(uint)(param_1[(*(int *)(param_1 + 0x68c8) + (uint)(byte)param_1[0x6691] * 4) * 3 +
                              0x3eb7] != (QObject)0x0) &
              (uint)(byte)param_1[(*(int *)(param_1 + 0x68c8) + (uint)(byte)param_1[0x6691] * 4) * 3
                                  + 0x3eb7];
    }
    else {
      iVar8 = QListData::size((QListData *)(param_1 + 0x68d0));
      uVar3 = iVar8 - 1;
    }
    QComboBox::setCurrentIndex(local_14,uVar3);
    piVar7 = *(int **)(param_1 + 0x9c8);
  }
  (**(code **)(*piVar7 + 0x2c))(~(byte)(*(uint *)(piVar7[5] + 4) >> 0xf) & 1);
  ExceptionList = local_10;
  return;
}


