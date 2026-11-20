
void __thiscall
FUN_004ca340(int param_1,int param_2,undefined4 *param_3,QListWidget *param_4,QString param_5)

{
  undefined1 uVar1;
  code *pcVar2;
  char cVar3;
  uint uVar4;
  QString *pQVar5;
  undefined4 uVar6;
  QByteArray *this;
  char *pcVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  byte bStack_67;
  byte bStack_66;
  byte bStack_65;
  QByteArray local_58 [4];
  QString local_54 [4];
  uint local_50;
  code *local_4c;
  QString local_48 [4];
  QString local_44 [4];
  code *local_40;
  QString local_3c [4];
  uint local_38;
  code *local_34;
  code *local_30;
  undefined4 *local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 *local_20;
  code *local_1c;
  QString local_18 [4];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00536cc6;
  local_10 = ExceptionList;
  uVar4 = DAT_00759b24 ^ (uint)(local_18 + 0x14);
  ExceptionList = &local_10;
  local_14 = 0;
  QListWidget::clear(param_4);
  local_34 = asprintf_exref;
  local_30 = append_exref;
  local_4c = operator=_exref;
  local_2c = param_3;
  local_20 = param_3;
  local_38 = (int)param_3 + 3;
  local_28 = 0;
  local_1c = checkedId_exref;
  local_40 = fromAscii_helper_exref;
  do {
    uVar10 = local_38;
    uVar6 = *(undefined4 *)(local_38 - 3);
    uVar1 = *(undefined1 *)(local_38 + 1);
    param_3 = (undefined4 *)CONCAT13(uVar1,param_3._0_3_);
    if ((char)uVar6 != '\0') {
      if (local_14 != local_28) {
        *local_20 = uVar6;
        *(undefined1 *)(local_20 + 1) = uVar1;
        *(undefined4 *)(local_38 - 3) = 0;
        *(undefined1 *)(local_38 + 1) = 0;
      }
      local_14 = local_14 + 1;
      local_20 = (undefined4 *)((int)local_20 + 5);
      QString::QString(local_18);
      local_8 = 0;
      bStack_66 = (byte)((uint)uVar6 >> 0x10);
      bStack_65 = (byte)((uint)uVar6 >> 0x18);
      bStack_67 = (byte)((uint)uVar6 >> 8);
      if (param_2 == 2) {
        pQVar5 = (QString *)
                 (*local_34)(local_3c,"[%d]  %d  %d  %d ~ %d",local_14,bStack_67 + 1,bStack_66,
                             bStack_65,param_3._3_1_);
        QString::operator=(local_18,pQVar5);
        QString::~QString(local_3c);
      }
      else if (*(char *)(uVar10 - 1) == '\x04') {
        local_24 = (*local_40)("Send:",5,uVar4);
        local_8._0_1_ = 1;
        if (param_2 == 0) {
          iVar8 = (*local_1c)();
          uVar6 = FUN_004c4ae0(local_44,iVar8 * 0x80 + 0xcbe + param_1);
          local_8 = CONCAT31(local_8._1_3_,2);
          (*local_30)(uVar6);
          pQVar5 = local_44;
LAB_004ca4e6:
          local_8._0_1_ = 1;
          QString::~QString(pQVar5);
        }
        else if (param_2 == 1) {
          iVar8 = (*local_1c)();
          uVar6 = FUN_004c4ae0(local_48,iVar8 * 0x80 + 0xebe + param_1);
          local_8 = CONCAT31(local_8._1_3_,3);
          (*local_30)(uVar6);
          pQVar5 = local_48;
          goto LAB_004ca4e6;
        }
        (*local_4c)(&local_24);
        pcVar2 = local_1c;
        iVar8 = 5;
        do {
          iVar9 = (*pcVar2)();
          iVar9 = iVar9 * 0xa1 + iVar8;
          iVar8 = iVar8 + 5;
          *(undefined1 *)(iVar9 + 0x99a + param_1) = 0;
        } while (iVar8 < 0x50);
        local_8 = (uint)local_8._1_3_ << 8;
        QString::~QString((QString *)&local_24);
        uVar10 = local_38;
      }
      else {
        local_38 = (uint)param_3._3_1_;
        local_50 = (uint)bStack_65;
        param_3 = (undefined4 *)(uint)bStack_66;
        if ((undefined4 *)0x3 < param_3) {
          param_3 = (undefined4 *)0x3;
        }
        if ((**(int **)(param_1 + 0x10d8) != 1) && (**(int **)(param_1 + 0x10d8) != 0)) {
          FUN_004875a0(*(undefined4 *)(*(int *)(param_1 + 0x10d8) + 4));
        }
        pQVar5 = (QString *)QListData::at((QListData *)(param_1 + 0x10d8),(int)param_3);
        this = (QByteArray *)QString::toUtf8(pQVar5);
        local_8._0_1_ = 4;
        uVar11 = local_50;
        uVar12 = local_38;
        pcVar7 = QByteArray::data(this);
        pQVar5 = (QString *)
                 (*local_34)(local_54,"[%d]  %d  %s  %d  %d",local_14,bStack_67 + 1,pcVar7,uVar11,
                             uVar12);
        QString::operator=(local_18,pQVar5);
        QString::~QString(local_54);
        local_8 = (uint)local_8._1_3_ << 8;
        QByteArray::~QByteArray(local_58);
      }
      pQVar5 = local_18;
      iVar8 = QListWidget::count(param_4);
      QListWidget::insertItem(param_4,iVar8,pQVar5);
      local_8 = 0xffffffff;
      QString::~QString(local_18);
    }
    local_38 = uVar10 + 5;
    local_28 = local_28 + 1;
    if (0xf < local_28) {
      if (param_5 != (QString)0x0) {
        if (param_2 == 0) {
          cVar3 = FUN_00506590(4,(int)local_2c + (-0x98c - param_1),local_2c,0x50,param_1);
          if (cVar3 == '\0') {
            QMetaObject::tr((QMetaObject *)&PTR_DAT_006f83b0,(char *)&param_5,"Write data failed !",
                            0);
            local_8 = 5;
            FUN_00486bb0(&param_5);
            local_8 = 0xffffffff;
            QString::~QString(&param_5);
          }
          pcVar2 = local_1c;
          iVar8 = (*local_1c)();
          iVar9 = (*pcVar2)();
          cVar3 = FUN_00506590(4,iVar9 * 0x80 + 0x332,param_1 + 0xcbe + iVar8 * 0x80,0x80,param_1);
          if (cVar3 == '\0') {
            QMetaObject::tr((QMetaObject *)&PTR_DAT_006f83b0,(char *)&param_2,"Write data failed !",
                            0);
            local_8 = 6;
            FUN_00486bb0(&param_2);
            QString::~QString((QString *)&param_2);
            ExceptionList = local_10;
            return;
          }
        }
        else if (param_2 == 1) {
          cVar3 = FUN_00506590(4,(int)local_2c + (-0x98c - param_1),local_2c,0x50,param_1);
          if (cVar3 == '\0') {
            QMetaObject::tr((QMetaObject *)&PTR_DAT_006f83b0,(char *)&param_5,"Write data failed !",
                            0);
            local_8 = 7;
            FUN_00486bb0(&param_5);
            local_8 = 0xffffffff;
            QString::~QString(&param_5);
          }
          pcVar2 = local_1c;
          iVar8 = (*local_1c)();
          iVar9 = (*pcVar2)();
          cVar3 = FUN_00506590(4,iVar9 * 0x80 + 0x532,param_1 + 0xebe + iVar8 * 0x80,0x80,param_1);
          if (cVar3 == '\0') {
            QMetaObject::tr((QMetaObject *)&PTR_DAT_006f83b0,(char *)&param_4,"Write data failed !",
                            0);
            local_8 = 8;
            FUN_00486bb0(&param_4);
            QString::~QString((QString *)&param_4);
            ExceptionList = local_10;
            return;
          }
        }
        else if (param_2 == 2) {
          FUN_004c6750((int)local_2c + (-0x98c - param_1),local_2c,0x50,param_1);
        }
      }
      ExceptionList = local_10;
      return;
    }
  } while( true );
}


