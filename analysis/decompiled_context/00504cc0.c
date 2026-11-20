
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00504cc0(QObject *param_1,uint param_2)

{
  QMessageLogger *this;
  void *pvVar1;
  char cVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  QVariant *this_00;
  char *pcVar5;
  CheckState CVar6;
  int *piVar7;
  int iVar8;
  QString *pQVar9;
  undefined4 uVar10;
  QMessageLogger *this_01;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  QMessageLogger local_40 [4];
  QVariant local_3c [16];
  QString local_2c [4];
  QString local_28 [4];
  QString local_24 [4];
  QObject *local_20;
  QTypedArrayData<unsigned_short> *local_1c;
  int local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pvVar1 = ExceptionList;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054d0b5;
  local_10 = ExceptionList;
  iVar8 = *(int *)(param_2 + 0xc);
  local_20 = param_1;
  if (*(int *)(param_1 + 0x10c) == iVar8) {
    if (*(int *)(param_1 + 0x108) != 0) {
      ExceptionList = &local_10;
      *(undefined4 *)(param_1 + 0x108) = 0;
      if (param_1[0x105] != (QObject)0x0) {
        FUN_005029d0();
        ExceptionList = local_10;
        return;
      }
    }
    ExceptionList = pvVar1;
    return;
  }
  if (*(int *)(param_1 + 0x110) != iVar8) {
    if (*(int *)(param_1 + 0x114) != iVar8) {
      return;
    }
    if (DAT_007628ac == '\0') {
      return;
    }
    if (*(int *)(*(int *)(param_1 + 0x4c) + 0xc844) != 3) {
      DAT_007628ac = '\0';
      ExceptionList = &local_10;
      cVar2 = FUN_005060a0();
      if (cVar2 == '\0') {
        thunk_FUN_00508160();
        FUN_004872d0(10);
        _DAT_007628a8 = 0;
        (**(code **)(*(int *)param_1 + 200))(0);
        pcVar5 = (char *)QMessageLogger::QMessageLogger
                                   ((QMessageLogger *)&uStack_54,(char *)0x0,0,(char *)0x0);
        QMessageLogger::debug(this_01,pcVar5,"CDevBaseDlg::connected=FALSE\n");
        ExceptionList = local_10;
        return;
      }
      ExceptionList = local_10;
      return;
    }
    ExceptionList = &local_10;
    cVar2 = FUN_00502d20(DAT_00759b24 ^ (uint)(local_24 + 0x20));
    if ((cVar2 != '\0') ||
       (iVar8 = *(int *)(param_1 + 0x118), *(int *)(param_1 + 0x118) = iVar8 + 1, 2 < iVar8 + 1)) {
      DAT_007628ac = '\0';
      *(undefined4 *)(param_1 + 0x118) = 0;
    }
    if (*(int *)(*(int *)(param_1 + 0x4c) + 0xc844) == 3) {
      ExceptionList = local_10;
      return;
    }
    (**(code **)(*(int *)param_1 + 200))(1);
    pcVar5 = (char *)QMessageLogger::QMessageLogger(local_40,(char *)0x0,0,(char *)0x0);
    this = *(QMessageLogger **)(param_1 + 0x4c);
    uStack_54 = *(undefined4 *)(this + 0x2ca78);
    uStack_50 = *(undefined4 *)(this + 0x2ca7c);
    uStack_4c = *(undefined4 *)(this + 0x2ca80);
    local_48 = *(undefined8 *)(this + 0x2ca84);
    QMessageLogger::debug
              (this,pcVar5,"CDevBaseDlg::connected=TRUE %d\n",*(undefined4 *)(this + 0x2ca68));
    ExceptionList = local_10;
    return;
  }
  ExceptionList = &local_10;
  QObject::killTimer(param_1,*(int *)(param_1 + 0x110));
  *(undefined4 *)(param_1 + 0x110) = 0xffffffff;
  if (*(int *)(param_1 + 0x124) != 1) {
    if (*(int *)(param_1 + 0x124) != 2) {
      ExceptionList = local_10;
      return;
    }
    uVar4 = QVariant::QVariant((QVariant *)&uStack_50);
    local_8 = 0xd;
    local_1c = QString::fromAscii_helper("/Config/UpdateNotFinishedPath",0x1d);
    local_8._0_1_ = 0xe;
    this_00 = (QVariant *)FUN_00487a10(local_3c,&local_1c,uVar4);
    local_8._0_1_ = 0xf;
    QVariant::toString(this_00);
    QVariant::~QVariant(local_3c);
    QString::~QString((QString *)&local_1c);
    local_8 = CONCAT31(local_8._1_3_,0x13);
    QVariant::~QVariant((QVariant *)&uStack_50);
    cVar2 = FUN_004878d0(&local_18);
    if (cVar2 == '\0') {
      FUN_00486c20(
                  "The last updating file is inexist, you need select a local update file, if you do not have, please contact the sales!"
                  );
      QString::~QString((QString *)&local_18);
      ExceptionList = local_10;
      return;
    }
    cVar2 = FUN_00505530(&local_18,1);
    param_2._3_1_ = cVar2;
    if (cVar2 != '\0') {
      FUN_005071f0();
      FUN_00505d00();
    }
    pcVar5 = "Successful!";
    if (param_2._3_1_ == '\0') {
      pcVar5 = "Failed!";
    }
    FUN_00486c20(pcVar5);
    QWidget::hide(*(QWidget **)(param_1 + 0x34));
    *(undefined4 *)(param_1 + 0x50) = 3;
    QString::~QString((QString *)&local_18);
    ExceptionList = local_10;
    return;
  }
  if (*(int *)(param_1 + 0x58) == *(int *)(param_1 + 0x5c)) {
    ExceptionList = local_10;
    return;
  }
  if (*(int *)(param_1 + 0x50) != 3) {
    ExceptionList = local_10;
    return;
  }
  param_2 = CONCAT13(1,(undefined3)param_2);
  CVar6 = QCheckBox::checkState(*(QCheckBox **)(param_1 + 0x24));
  if (CVar6 == 2) {
    pcVar5 = (char *)&param_2;
    piVar7 = (int *)QLineEdit::text(*(QLineEdit **)(param_1 + 0x20));
    iVar8 = *(int *)(*piVar7 + 4);
    QString::~QString((QString *)&param_2);
    if (iVar8 != 0) {
      uVar4 = QLineEdit::text(*(QLineEdit **)(param_1 + 0x20));
      local_8 = 0;
      uVar3 = FUN_00505530(uVar4,0);
      param_2 = CONCAT13(uVar3,(undefined3)param_2);
      pQVar9 = local_24;
      goto LAB_005050cc;
    }
  }
  else {
    iVar8 = QComboBox::currentIndex(*(QComboBox **)(param_1 + 0x2c));
    if (*(int *)(param_1 + 0x58) == *(int *)(param_1 + 0x5c)) {
      ExceptionList = local_10;
      return;
    }
    if (iVar8 == -1) {
      ExceptionList = local_10;
      return;
    }
    uVar4 = FUN_00486cd0(&local_1c);
    local_8 = 1;
    pQVar9 = (QString *)FUN_004f68c0(local_24,uVar4,"~webfirmware.dat");
    local_8 = CONCAT31(local_8._1_3_,2);
    local_11 = QFile::exists(pQVar9);
    QString::~QString(local_24);
    local_8 = 0xffffffff;
    QString::~QString((QString *)&local_1c);
    if (local_11 == '\0') {
      QByteArray::QByteArray((QByteArray *)&local_18);
      local_1c = (QTypedArrayData<unsigned_short> *)&DAT_007568dc;
      local_8 = 4;
      FUN_004f6850(local_24,&local_1c,*(int *)(param_1 + 0x58) + iVar8 * 4);
      local_8._0_1_ = 6;
      QString::~QString((QString *)&local_1c);
      FUN_00510a20();
      cVar2 = FUN_005108e0(local_24,&local_18);
      if (cVar2 == '\0') {
        FUN_00486c20("Download firmware failed !");
        param_2 = param_2 & 0xffffff;
      }
      else {
        uVar4 = *(undefined4 *)(local_18 + 4);
        pcVar5 = QByteArray::data((QByteArray *)&local_18);
        uVar10 = FUN_00486cd0(local_2c);
        local_8._0_1_ = 7;
        uVar10 = FUN_004f68c0(local_28,uVar10,"~webfirmware.dat");
        local_8._0_1_ = 8;
        iVar8 = FUN_00487330(uVar10,pcVar5,uVar4);
        QString::~QString(local_28);
        local_8._0_1_ = 6;
        QString::~QString(local_2c);
        if (iVar8 == 0) {
          param_1 = local_20;
        }
        else {
          uVar4 = FUN_00486cd0(local_28);
          local_8._0_1_ = 9;
          uVar4 = FUN_004f68c0(local_2c,uVar4,"~webfirmware.dat");
          param_1 = local_20;
          local_8._0_1_ = 10;
          uVar3 = FUN_00505530(uVar4,0);
          param_2 = CONCAT13(uVar3,(undefined3)param_2);
          QString::~QString(local_2c);
          QString::~QString(local_28);
        }
      }
      QString::~QString(local_24);
      local_8 = 0xffffffff;
      QByteArray::~QByteArray((QByteArray *)&local_18);
    }
    else {
      uVar4 = FUN_00486cd0(local_28);
      local_8 = 0xb;
      uVar4 = FUN_004f68c0(local_2c,uVar4,"~webfirmware.dat");
      local_8 = CONCAT31(local_8._1_3_,0xc);
      uVar3 = FUN_00505530(uVar4,0);
      param_2 = CONCAT13(uVar3,(undefined3)param_2);
      QString::~QString(local_2c);
      pQVar9 = local_28;
LAB_005050cc:
      local_8 = 0xffffffff;
      QString::~QString(pQVar9);
    }
    if ((param_1[0x104] != (QObject)0x0) && (param_1[0x105] != (QObject)0x0)) {
      if (param_2._3_1_ == '\0') {
        QWidget::hide(*(QWidget **)(param_1 + 0x40));
        QWidget::show(*(QWidget **)(param_1 + 0x3c));
        QWidget::hide(*(QWidget **)(param_1 + 0x34));
        *(undefined4 *)(param_1 + 0x50) = 3;
        ExceptionList = local_10;
        return;
      }
      QWidget::hide(*(QWidget **)(param_1 + 0x3c));
      QWidget::show(*(QWidget **)(param_1 + 0x40));
      QWidget::hide(*(QWidget **)(param_1 + 0x34));
      *(undefined4 *)(param_1 + 0x50) = 3;
      ExceptionList = local_10;
      return;
    }
    cVar2 = '\0';
    if (param_2._3_1_ != '\0') {
      FUN_005071f0();
      FUN_00505d00();
      cVar2 = param_2._3_1_;
    }
    iVar8 = *(int *)(param_1 + 0x4c);
    uStack_54 = *(undefined4 *)(iVar8 + 0x2ca78);
    uStack_50 = *(undefined4 *)(iVar8 + 0x2ca7c);
    uStack_4c = *(undefined4 *)(iVar8 + 0x2ca80);
    local_48 = *(undefined8 *)(iVar8 + 0x2ca84);
    if (*(int *)(iVar8 + 0x2ca68) == 0x272a) goto LAB_005051b6;
    pcVar5 = "Successful!";
    if (cVar2 == '\0') {
      pcVar5 = "Failed!";
    }
  }
  FUN_00486c20(pcVar5);
LAB_005051b6:
  QWidget::hide(*(QWidget **)(param_1 + 0x34));
  *(undefined4 *)(param_1 + 0x50) = 3;
  ExceptionList = local_10;
  return;
}


