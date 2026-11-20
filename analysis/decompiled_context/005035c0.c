
void __fastcall FUN_005035c0(int param_1)

{
  QComboBox *this;
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  int iVar4;
  QByteArray *this_00;
  QString *pQVar5;
  QIcon *pQVar6;
  int *piVar7;
  int iVar8;
  QString *this_01;
  int *piVar9;
  QChar aQStackY_2c0 [128];
  QVariant local_5c [16];
  int *local_4c;
  QIcon local_48 [4];
  QString local_44 [4];
  QString local_40 [4];
  QComboBox *local_3c;
  QString local_38 [4];
  QString local_34 [4];
  int *local_30;
  undefined4 local_2c;
  QByteArray local_28 [4];
  int local_24;
  int *local_20;
  QString local_1c [4];
  QString local_18 [4];
  QVariant *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054cc94;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_24 = param_1;
  cVar3 = FUN_005069b0();
  if (cVar3 == '\0') {
    QComboBox::clear(*(QComboBox **)(param_1 + 0x2c));
    ExceptionList = local_10;
    return;
  }
  QByteArray::QByteArray(local_28);
  local_14 = (QVariant *)&DAT_00756994;
  local_20 = (int *)&DAT_0075694c;
  local_8 = 2;
  FUN_004f6850();
  QString::~QString((QString *)&local_20);
  local_8._0_1_ = 5;
  QString::~QString((QString *)&local_14);
  FUN_00510a20();
  cVar3 = FUN_005108e0();
  if (cVar3 != '\0') {
    iVar4 = FUN_00488eb0();
    if (iVar4 == 0) {
      QCheckBox::setCheckState(*(QCheckBox **)(param_1 + 0x24),2);
      FUN_00505b00();
    }
    else {
      FUN_00510d50();
      local_8._0_1_ = 6;
      cVar3 = FUN_00511190();
      if (cVar3 == '\0') {
        FUN_00486c20();
        FUN_00510e80();
      }
      else {
        local_30 = (int *)0x0;
        local_2c = 0;
        local_30 = operator_new(0x20);
        *local_30 = (int)local_30;
        local_30[1] = (int)local_30;
        local_8._0_1_ = 7;
        QString::asprintf((char *)local_34);
        local_8._0_1_ = 8;
        this_00 = (QByteArray *)QString::toLatin1(local_34);
        local_8 = CONCAT31(local_8._1_3_,9);
        QByteArray::data(this_00);
        FUN_00510f10();
        QByteArray::~QByteArray((QByteArray *)&local_14);
        pQVar5 = *(QString **)(param_1 + 0x5c);
        local_20 = (int *)(param_1 + 0x58);
        this_01 = (QString *)*local_20;
        if (this_01 != pQVar5) {
          do {
            QString::~QString(this_01);
            this_01 = this_01 + 4;
          } while (this_01 != pQVar5);
          local_20[1] = *local_20;
        }
        QString::QString(local_1c);
        QString::QString(local_18);
        local_8._0_1_ = 0xb;
        piVar9 = (int *)*local_30;
        if (piVar9 != local_30) {
          do {
            local_4c = piVar9 + 2;
            piVar7 = local_4c;
            if (0xf < (uint)piVar9[7]) {
              piVar7 = (int *)*local_4c;
            }
            pQVar5 = (QString *)QString::fromLocal8Bit((char *)&local_20,(int)piVar7);
            QString::operator=(local_18,pQVar5);
            QString::~QString((QString *)&local_20);
            QChar::QChar(aQStackY_2c0 + 0x84,0x2f);
            iVar4 = QString::lastIndexOf(local_18);
            if (iVar4 != -1) {
              pQVar5 = (QString *)QString::mid(local_18,(int)local_44,iVar4 + 1);
              QString::operator=(local_18,pQVar5);
              QString::~QString(local_44);
            }
            this = *(QComboBox **)(local_24 + 0x2c);
            local_3c = this;
            local_14 = (QVariant *)QVariant::QVariant(local_5c);
            local_8._0_1_ = 0xc;
            iVar4 = QComboBox::count(this);
            pQVar6 = (QIcon *)QIcon::QIcon(local_48);
            local_8._0_1_ = 0xd;
            QComboBox::insertItem(local_3c,iVar4,pQVar6,local_18,local_14);
            QIcon::~QIcon(local_48);
            local_8._0_1_ = 0xb;
            QVariant::~QVariant(local_5c);
            local_14 = (QVariant *)&DAT_007569ec;
            QString::operator=(local_1c,(QString *)&local_14);
            QString::~QString((QString *)&local_14);
            piVar7 = local_4c;
            if (0xf < (uint)local_4c[5]) {
              piVar7 = (int *)*local_4c;
            }
            pQVar5 = (QString *)QString::fromLocal8Bit((char *)local_40,(int)piVar7);
            local_8._0_1_ = 0xe;
            QString::append(local_1c,pQVar5);
            QString::~QString(local_40);
            local_14 = (QVariant *)&DAT_00756a34;
            local_8._0_1_ = 0xf;
            QString::append(local_1c,(QString *)&local_14);
            local_8._0_1_ = 0xb;
            QString::~QString((QString *)&local_14);
            iVar4 = local_24;
            if (*(QString **)(local_24 + 0x5c) == *(QString **)(local_24 + 0x60)) {
              FUN_00501510();
            }
            else {
              QString::QString(*(QString **)(local_24 + 0x5c),local_1c);
              *(int *)(iVar4 + 0x5c) = *(int *)(iVar4 + 0x5c) + 4;
            }
            piVar9 = (int *)*piVar9;
          } while (piVar9 != local_30);
        }
        iVar4 = local_24;
        iVar8 = QComboBox::count(*(QComboBox **)(local_24 + 0x2c));
        if (0 < iVar8) {
          QComboBox::setCurrentIndex(*(QComboBox **)(iVar4 + 0x2c),0);
        }
        QString::~QString(local_18);
        QString::~QString(local_1c);
        QString::~QString(local_34);
        *(undefined4 *)local_30[1] = 0;
        puVar2 = (undefined4 *)*local_30;
        while (puVar2 != (undefined4 *)0x0) {
          puVar1 = (undefined4 *)*puVar2;
          if (0xf < (uint)puVar2[7]) {
            if ((0xfff < puVar2[7] + 1) && (0x1f < (puVar2[2] - *(int *)(puVar2[2] + -4)) - 4U)) {
                    /* WARNING: Subroutine does not return */
              _invalid_parameter_noinfo_noreturn();
            }
            FUN_00519359();
          }
          puVar2[6] = 0;
          puVar2[7] = 0xf;
          *(undefined1 *)(puVar2 + 2) = 0;
          FUN_00519359();
          puVar2 = puVar1;
        }
        FUN_00519359();
        FUN_00510e80();
      }
    }
  }
  QString::~QString(local_38);
  QByteArray::~QByteArray(local_28);
  ExceptionList = local_10;
  return;
}


