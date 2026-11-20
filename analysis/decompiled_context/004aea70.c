
void __thiscall FUN_004aea70(QObject *param_1,uint param_2)

{
  QButtonGroup *this;
  QLabel *this_00;
  char cVar1;
  QObject QVar2;
  uint uVar3;
  QObject *pQVar4;
  QAbstractButton *this_01;
  QString *pQVar5;
  QObject *this_02;
  QObject QVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  uVar7 = param_2;
  local_8 = 0xffffffff;
  puStack_c = &LAB_005308ae;
  local_10 = ExceptionList;
  uVar3 = DAT_00759b24 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  pQVar4 = QObject::sender(param_1);
  QVar6 = SUB41(uVar7,0);
  if (pQVar4 == *(QObject **)(param_1 + 0x958)) {
    param_1[0xa3c] = QVar6;
    cVar1 = FUN_00506590(4,4,param_1 + 0xa3c,1,param_1);
    if (cVar1 == '\0') {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f6f40,(char *)&param_2,"Write data failed !",0);
      local_8 = 0;
      FUN_00486bb0(&param_2);
      QString::~QString((QString *)&param_2);
      ExceptionList = local_10;
      return;
    }
    ExceptionList = local_10;
    return;
  }
  if (pQVar4 == *(QObject **)(param_1 + 0x964)) {
    pQVar4 = param_1 + 0xa3e;
    *pQVar4 = QVar6;
    iVar8 = 6;
  }
  else if (pQVar4 == *(QObject **)(param_1 + 0x96c)) {
    pQVar4 = param_1 + 0xa40;
    *pQVar4 = QVar6;
    iVar8 = 8;
  }
  else if (pQVar4 == *(QObject **)(param_1 + 0x970)) {
    pQVar4 = param_1 + 0xa42;
    *pQVar4 = QVar6;
    iVar8 = 10;
  }
  else if (pQVar4 == *(QObject **)(param_1 + 0x978)) {
    pQVar4 = param_1 + 0xa44;
    *pQVar4 = QVar6;
    iVar8 = 0xc;
  }
  else if (pQVar4 == *(QObject **)(param_1 + 0x9c0)) {
    pQVar4 = param_1 + 0x6691;
    *pQVar4 = QVar6;
    iVar8 = 0x5c59;
  }
  else if (pQVar4 == *(QObject **)(param_1 + 0xa2c)) {
    pQVar4 = param_1 + 0x6695;
    *pQVar4 = QVar6;
    FUN_004bd9b0(uVar3);
    iVar8 = 0x5c5d;
  }
  else {
    this_02 = *(QObject **)(param_1 + 0x9cc);
    if (pQVar4 == this_02) {
      pQVar4 = param_1 + 0x6691;
      if (uVar7 == 0) {
        iVar8 = *(int *)(param_1 + 0x68c8);
        QVar2 = param_1[0x6691];
      }
      else {
        if ((uint)(byte)param_1[(*(int *)(param_1 + 0x68c8) + (uint)(byte)*pQVar4 * 4) * 3 + 0x3eb6]
            == uVar7 + 0x3e) {
LAB_004aebf9:
          QComboBox::setCurrentIndex((QComboBox *)this_02,0);
          ExceptionList = local_10;
          return;
        }
        QVar2 = *pQVar4;
        iVar8 = *(int *)(param_1 + 0x68c8);
        if (uVar7 != 0) {
          uVar7 = (uint)(byte)((char)QVar6 + 0x3e);
        }
      }
      param_1[((uint)(byte)QVar2 * 4 + 0x14e7 + iVar8) * 3] = SUB41(uVar7,0);
      iVar8 = (*(int *)(param_1 + 0x68c8) + (uint)(byte)*pQVar4 * 4) * 3;
      pQVar4 = param_1 + iVar8 + 0x3eb5;
      iVar8 = iVar8 + 0x347d;
    }
    else {
      this_02 = *(QObject **)(param_1 + 0x9d0);
      if (pQVar4 == this_02) {
        pQVar4 = param_1 + 0x6691;
        if (uVar7 == 0) {
          iVar8 = *(int *)(param_1 + 0x68c8);
          QVar2 = param_1[0x6691];
        }
        else {
          if ((uint)(byte)param_1[((uint)(byte)*pQVar4 * 4 + 0x14e7 + *(int *)(param_1 + 0x68c8)) *
                                  3] == uVar7 + 0x3e) goto LAB_004aebf9;
          QVar2 = *pQVar4;
          iVar8 = *(int *)(param_1 + 0x68c8);
          if (uVar7 != 0) {
            uVar7 = (uint)(byte)((char)QVar6 + 0x3e);
          }
        }
        param_1[(iVar8 + (uint)(byte)QVar2 * 4) * 3 + 0x3eb6] = SUB41(uVar7,0);
        iVar8 = (*(int *)(param_1 + 0x68c8) + (uint)(byte)*pQVar4 * 4) * 3;
        pQVar4 = param_1 + iVar8 + 0x3eb6;
        iVar8 = iVar8 + 0x347e;
      }
      else if (pQVar4 == *(QObject **)(param_1 + 0x9d4)) {
        param_1[(*(int *)(param_1 + 0x68c8) + (uint)(byte)param_1[0x6691] * 4) * 3 + 0x3eb7] = QVar6
        ;
        iVar8 = (*(int *)(param_1 + 0x68c8) + (uint)(byte)param_1[0x6691] * 4) * 3;
        pQVar4 = param_1 + iVar8 + 0x3eb7;
        iVar8 = iVar8 + 0x347f;
      }
      else {
        this_02 = *(QObject **)(param_1 + 0x91c);
        if (pQVar4 == this_02) {
          pQVar4 = param_1 + 0x6695;
          if (uVar7 == 0) {
            iVar8 = *(int *)(param_1 + 0x68cc);
            QVar2 = param_1[0x6695];
          }
          else {
            if ((uint)(byte)param_1[(*(int *)(param_1 + 0x68cc) + (uint)(byte)*pQVar4 * 4) * 0x1a6 +
                                    0x3f00] == uVar7 + 0x3e) goto LAB_004aebf9;
            QVar2 = *pQVar4;
            iVar8 = *(int *)(param_1 + 0x68cc);
            if (uVar7 != 0) {
              uVar7 = (uint)(byte)((char)QVar6 + 0x3e);
            }
          }
          param_1[(iVar8 + (uint)(byte)QVar2 * 4) * 0x1a6 + 0x3eff] = SUB41(uVar7,0);
          iVar8 = (*(int *)(param_1 + 0x68cc) + (uint)(byte)*pQVar4 * 4) * 0x1a6;
          pQVar4 = param_1 + iVar8 + 0x3eff;
          iVar8 = iVar8 + 0x34c7;
        }
        else {
          this_02 = *(QObject **)(param_1 + 0x920);
          if (pQVar4 == this_02) {
            pQVar4 = param_1 + 0x6695;
            if (uVar7 == 0) {
              iVar8 = *(int *)(param_1 + 0x68cc);
              QVar2 = param_1[0x6695];
            }
            else {
              if ((uint)(byte)param_1[(*(int *)(param_1 + 0x68cc) + (uint)(byte)*pQVar4 * 4) * 0x1a6
                                      + 0x3eff] == uVar7 + 0x3e) goto LAB_004aebf9;
              QVar2 = *pQVar4;
              iVar8 = *(int *)(param_1 + 0x68cc);
              if (uVar7 != 0) {
                uVar7 = (uint)(byte)((char)QVar6 + 0x3e);
              }
            }
            param_1[(iVar8 + (uint)(byte)QVar2 * 4) * 0x1a6 + 0x3f00] = SUB41(uVar7,0);
            iVar8 = (*(int *)(param_1 + 0x68cc) + (uint)(byte)*pQVar4 * 4) * 0x1a6;
            pQVar4 = param_1 + iVar8 + 0x3f00;
            iVar8 = iVar8 + 0x34c8;
          }
          else if (pQVar4 == *(QObject **)(param_1 + 0x924)) {
            param_1[(*(int *)(param_1 + 0x68cc) + (uint)(byte)param_1[0x6695] * 4) * 0x1a6 + 0x3f01]
                 = QVar6;
            iVar8 = (*(int *)(param_1 + 0x68cc) + (uint)(byte)param_1[0x6695] * 4) * 0x1a6;
            pQVar4 = param_1 + iVar8 + 0x3f01;
            iVar8 = iVar8 + 0x34c9;
          }
          else if (pQVar4 == *(QObject **)(param_1 + 0x914)) {
            this = *(QButtonGroup **)(param_1 + 0x868);
            param_1[0x6690] = QVar6;
            iVar8 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x864));
            this_01 = QButtonGroup::button
                                (this,(uint)(byte)param_1[(uVar7 & 0xff) * 0x684 + iVar8 * 0x1a1 +
                                                          0xa95]);
            QAbstractButton::setChecked(this_01,true);
            this_00 = *(QLabel **)(param_1 + 0x8d4);
            iVar8 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x868));
            pQVar5 = (QString *)QListData::at((QListData *)(param_1 + 0x66a4),iVar8);
            QLabel::setText(this_00,pQVar5);
            QVar6 = param_1[0x6690];
            pQVar4 = param_1 + 0x6690;
            iVar8 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x864));
            if (((param_1[iVar8 * 0x1a1 + 0xa95 + (uint)(byte)QVar6 * 0x684] == (QObject)0x1) ||
                (QVar6 = *pQVar4,
                iVar8 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x864)),
                param_1[iVar8 * 0x1a1 + 0xa95 + (uint)(byte)QVar6 * 0x684] == (QObject)0x2)) ||
               (QVar6 = *pQVar4,
               iVar8 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x864)),
               param_1[iVar8 * 0x1a1 + 0xa95 + (uint)(byte)QVar6 * 0x684] == (QObject)0x4)) {
              uVar9 = 1;
            }
            else {
              uVar9 = 0;
            }
            (**(code **)(**(int **)(param_1 + 0x904) + 0x2c))(uVar9);
            FUN_004bc7e0(0);
            FUN_004bcf90(0);
            iVar8 = 0x5c58;
          }
          else if (pQVar4 == *(QObject **)(param_1 + 0xa0c)) {
            if (param_1[0xa38] == (QObject)0x0) {
              pQVar4 = param_1 + 0x668d;
              *pQVar4 = QVar6;
              iVar8 = 0x5c55;
            }
            else {
              if (param_1[0xa38] != (QObject)0x1) {
                ExceptionList = local_10;
                return;
              }
              pQVar4 = param_1 + 0x668e;
              *pQVar4 = QVar6;
              iVar8 = 0x5c56;
            }
          }
          else if (pQVar4 == *(QObject **)(param_1 + 0xa18)) {
            pQVar4 = param_1 + 0x668f;
            *pQVar4 = QVar6;
            iVar8 = 0x5c57;
          }
          else {
            if (pQVar4 != *(QObject **)(param_1 + 0x93c)) {
              ExceptionList = local_10;
              return;
            }
            param_1[(*(int *)(param_1 + 0x68cc) + (uint)(byte)param_1[0x6695] * 4) * 0x1a6 + 0x3efe]
                 = QVar6;
            iVar8 = (*(int *)(param_1 + 0x68cc) + (uint)(byte)param_1[0x6695] * 4) * 0x1a6;
            pQVar4 = param_1 + iVar8 + 0x3efe;
            iVar8 = iVar8 + 0x34c6;
          }
        }
      }
    }
  }
  FUN_004b6c90(iVar8,pQVar4,1,param_1);
  ExceptionList = local_10;
  return;
}


