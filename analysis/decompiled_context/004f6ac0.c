
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_004f6ac0(QWidget *param_1)

{
  short sVar1;
  bool bVar2;
  char cVar3;
  int *piVar4;
  QString *pQVar5;
  uint uVar6;
  QTypedArrayData<unsigned_short> *pQVar7;
  short *psVar8;
  int iVar9;
  short *psVar10;
  QTypedArrayData<unsigned_short> *pQVar11;
  undefined4 uVar12;
  undefined4 auStack_c4 [3];
  undefined4 uStack_b8;
  QChar aQStack_9e [6];
  QString local_8c [4];
  undefined *local_88;
  undefined1 *local_84;
  int local_80;
  QString local_7c [4];
  QString local_78 [4];
  QString local_74 [4];
  QString local_70 [4];
  QByteArray local_6c [4];
  code *local_68;
  QString local_64 [4];
  QString local_60 [4];
  QDir local_5c [4];
  QTypedArrayData<unsigned_short> *local_58;
  QWidget *local_54;
  QTypedArrayData<unsigned_short> *local_50;
  QTypedArrayData<unsigned_short> *local_4c;
  QTypedArrayData<unsigned_short> *local_48;
  int local_44;
  uint local_30;
  uint local_2c;
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00547f20;
  local_10 = ExceptionList;
  local_14 = DAT_00759b24 ^ (uint)(local_5c + 0x58);
  ExceptionList = &local_10;
  local_58 = (QTypedArrayData<unsigned_short> *)0x0;
  local_54 = param_1;
  (**(code **)(**(int **)(param_1 + 0x44) + 0x2c))();
  FUN_004870e0();
  local_8 = 0;
  if (*(int *)(local_80 + 4) == 0) {
    local_50 = QString::fromAscii_helper("Please connect the device first!",0x20);
    local_8._0_1_ = 1;
    local_58 = QString::fromAscii_helper("error",5);
    local_8._0_1_ = 2;
    uStack_b8 = 0x4f6b60;
    QMessageBox::critical();
    QString::~QString((QString *)&local_58);
    pQVar5 = (QString *)&local_50;
    goto LAB_004f714e;
  }
  QString::QString(local_70);
  local_8._0_1_ = 3;
  bVar2 = QAbstractButton::isChecked(*(QAbstractButton **)(param_1 + 0x30));
  if (bVar2) {
    piVar4 = (int *)QLineEdit::text(*(QLineEdit **)(param_1 + 0x34));
    iVar9 = *(int *)(*piVar4 + 4);
    QString::~QString((QString *)&local_48);
    if (iVar9 != 0) {
      pQVar5 = (QString *)QLineEdit::text(*(QLineEdit **)(param_1 + 0x34));
      QString::operator=(local_70,pQVar5);
      QString::~QString((QString *)&local_48);
      goto LAB_004f6e8b;
    }
    FUN_00486c20();
  }
  else {
    QComboBox::currentText(*(QComboBox **)(param_1 + 0x28));
    local_8._0_1_ = 4;
    FUN_00486cd0();
    local_8._0_1_ = 5;
    uStack_b8 = 0x4f6c1b;
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7308,(char *)&local_58,"bin/up/",0);
    local_8._0_1_ = 6;
    QString::append(local_60,(QString *)&local_58);
    local_8._0_1_ = 5;
    QString::~QString((QString *)&local_58);
    QDir::QDir(local_5c,local_60);
    local_8 = CONCAT31(local_8._1_3_,7);
    QDir::mkdir(local_5c,local_60);
    local_50 = (QTypedArrayData<unsigned_short> *)0x0;
    uVar6 = QDir::count(local_5c);
    if (uVar6 != 0) {
      do {
        pQVar5 = (QString *)QDir::operator[](local_5c,(int)&local_68);
        local_8._0_1_ = 8;
        piVar4 = (int *)QDir::operator[](local_5c,(int)&local_84);
        local_8._0_1_ = 9;
        iVar9 = *(int *)(*piVar4 + 4);
        piVar4 = (int *)QDir::operator[](local_5c,(int)local_8c);
        local_8._0_1_ = 10;
        pQVar5 = QString::remove(pQVar5,*(int *)(*piVar4 + 4) + -6,iVar9 + -1);
        QString::QString(local_7c,pQVar5);
        QString::~QString(local_8c);
        QString::~QString((QString *)&local_84);
        QString::~QString((QString *)&local_68);
        bVar2 = operator==(local_64,local_7c);
        if (!bVar2) {
          local_4c = (QTypedArrayData<unsigned_short> *)&DAT_007565e8;
          local_88 = &DAT_007565a0;
          local_8._0_1_ = 0x11;
          QString::QString(local_74,(QString *)&local_88);
          local_58 = (QTypedArrayData<unsigned_short> *)0x14;
          QString::append(local_74,(QString *)&local_4c);
          FUN_004f6850();
          QString::~QString(local_74);
          QString::~QString((QString *)&local_88);
          QString::~QString((QString *)&local_4c);
          QByteArray::QByteArray(local_6c);
          local_8._0_1_ = 0x16;
          FUN_00510a20();
          cVar3 = FUN_005108e0();
          if (cVar3 == '\0') {
            FUN_00486c20();
          }
          else {
            QByteArray::data(local_6c);
            local_8._0_1_ = 0x17;
            QString::QString(local_78,local_60);
            local_58 = (QTypedArrayData<unsigned_short> *)0x18;
            QString::append(local_78,local_64);
            FUN_00487330();
            QString::~QString(local_78);
          }
          QByteArray::~QByteArray(local_6c);
          QString::~QString((QString *)&local_48);
        }
        local_8 = CONCAT31(local_8._1_3_,7);
        QString::~QString(local_7c);
        pQVar11 = local_50 + 1;
        local_50 = pQVar11;
        pQVar7 = (QTypedArrayData<unsigned_short> *)QDir::count(local_5c);
      } while (pQVar11 < pQVar7);
    }
    local_8._0_1_ = 0x18;
    QString::QString((QString *)&local_50,local_60);
    local_58 = (QTypedArrayData<unsigned_short> *)0x11;
    QString::append((QString *)&local_50,local_64);
    QString::operator=(local_70,(QString *)&local_50);
    QString::~QString((QString *)&local_50);
    QDir::~QDir(local_5c);
    QString::~QString(local_60);
    local_8._0_1_ = 3;
    QString::~QString(local_64);
    param_1 = local_54;
LAB_004f6e8b:
    QWidget::setEnabled(*(QWidget **)(param_1 + 0x20),false);
    QCoreApplication::processEvents();
    local_68 = *(code **)(param_1 + 100);
    local_54 = (QWidget *)QWidget::winId(param_1);
    psVar8 = (short *)QString::toStdWString((QString *)&local_80);
    local_8._0_1_ = 0x19;
    if (7 < *(uint *)(psVar8 + 10)) {
      psVar8 = *(short **)psVar8;
    }
    local_84 = (undefined1 *)auStack_c4;
    auStack_c4[0] = 0;
    psVar10 = psVar8;
    do {
      sVar1 = *psVar10;
      psVar10 = psVar10 + 1;
    } while (sVar1 != 0);
    FUN_004f69b0(psVar8,(int)psVar10 - (int)(psVar8 + 1) >> 1);
    local_8._0_1_ = 0x1a;
    psVar8 = (short *)QString::toStdWString(local_70);
    local_8._0_1_ = 0x1b;
    if (7 < *(uint *)(psVar8 + 10)) {
      psVar8 = *(short **)psVar8;
    }
    uVar12 = 0;
    psVar10 = psVar8;
    do {
      sVar1 = *psVar10;
      psVar10 = psVar10 + 1;
    } while (sVar1 != 0);
    FUN_004f69b0(psVar8,(int)psVar10 - (int)(psVar8 + 1) >> 1);
    local_8._0_1_ = 0x1c;
    iVar9 = (*local_68)(local_54,9999,uVar12);
    local_8._0_1_ = 0x19;
    if (7 < local_18) {
      if (0xfff < local_18 * 2 + 2) {
        if (0x1f < (local_2c - *(int *)(local_2c - 4)) - 4) goto LAB_004f6fff;
      }
      FUN_00519359();
    }
    local_1c = 0;
    local_18 = 7;
    local_2c = local_2c & 0xffff0000;
    local_8._0_1_ = 3;
    if (7 < local_30) {
      if (0xfff < local_30 * 2 + 2) {
        if (0x1f < (local_44 - *(int *)(local_44 + -4)) - 4U) {
LAB_004f6fff:
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
      }
      FUN_00519359();
    }
    if (iVar9 == 0) {
      QWidget::setEnabled(*(QWidget **)(param_1 + 0x20),true);
      (**(code **)(**(int **)(param_1 + 0x44) + 0x2c))();
      local_4c = QString::fromAscii_helper("Update successful!",0x12);
      local_8._0_1_ = 0x1d;
      local_48 = QString::fromAscii_helper("hint",4);
      local_8._0_1_ = 0x1e;
      uStack_b8 = 0x4f706a;
      QMessageBox::information();
    }
    else {
      local_4c = QString::fromAscii_helper("%1",2);
      local_54 = (QWidget *)CONCAT31(local_54._1_3_,0x20);
      local_8._0_1_ = 0x1f;
      QChar::QChar(aQStack_9e + -6);
      uStack_b8 = 0x4f70a9;
      QString::arg((QString *)&local_4c);
      local_8._0_1_ = 0x20;
      local_48 = QString::fromAscii_helper("error",5);
      local_8._0_1_ = 0x21;
      uStack_b8 = 0x4f70db;
      QMessageBox::critical();
      QString::~QString((QString *)&local_48);
      QString::~QString((QString *)&local_68);
      local_8._0_1_ = 3;
      QString::~QString((QString *)&local_4c);
      local_4c = QString::fromAscii_helper("Update failed!",0xe);
      local_8._0_1_ = 0x22;
      local_48 = QString::fromAscii_helper("error",5);
      local_8._0_1_ = 0x23;
      uStack_b8 = 0x4f7136;
      QMessageBox::critical();
    }
    QString::~QString((QString *)&local_48);
    QString::~QString((QString *)&local_4c);
  }
  pQVar5 = local_70;
LAB_004f714e:
  QString::~QString(pQVar5);
  QString::~QString((QString *)&local_80);
  ExceptionList = local_10;
  return;
}


