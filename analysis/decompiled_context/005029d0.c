
void __fastcall FUN_005029d0(int param_1)

{
  char cVar1;
  uint uVar2;
  CheckState CVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  QString *pQVar7;
  undefined4 uVar8;
  char *pcVar9;
  code *pcVar10;
  QString local_2c [4];
  QString local_28 [4];
  QString local_24 [4];
  int local_20;
  undefined *local_1c;
  int local_18;
  char local_12;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054cb11;
  local_10 = ExceptionList;
  uVar2 = DAT_00759b24 ^ (uint)(local_24 + 0x20);
  if (*(int *)(param_1 + 0x50) != 3) {
    return;
  }
  local_11 = '\x01';
  ExceptionList = &local_10;
  local_20 = param_1;
  CVar3 = QCheckBox::checkState(*(QCheckBox **)(param_1 + 0x24));
  if (CVar3 == 2) {
    pcVar9 = (char *)local_24;
    piVar4 = (int *)QLineEdit::text(*(QLineEdit **)(param_1 + 0x20));
    iVar6 = *(int *)(*piVar4 + 4);
    QString::~QString(local_24);
    if (iVar6 != 0) {
      uVar5 = QLineEdit::text(*(QLineEdit **)(param_1 + 0x20));
      local_8 = 0;
      local_11 = FUN_00505530(uVar5,0);
      pQVar7 = local_24;
      goto LAB_00502c47;
    }
LAB_00502cef:
    FUN_00486c20(pcVar9);
  }
  else {
    iVar6 = QComboBox::currentIndex(*(QComboBox **)(param_1 + 0x2c));
    if (*(int *)(param_1 + 0x58) == *(int *)(param_1 + 0x5c)) {
      ExceptionList = local_10;
      return;
    }
    if (iVar6 == -1) {
      ExceptionList = local_10;
      return;
    }
    uVar5 = FUN_00486cd0(&local_1c,uVar2);
    local_8 = 1;
    pQVar7 = (QString *)FUN_004f68c0(local_24,uVar5,"~webfirmware.dat");
    local_8 = CONCAT31(local_8._1_3_,2);
    local_12 = QFile::exists(pQVar7);
    QString::~QString(local_24);
    local_8 = 0xffffffff;
    QString::~QString((QString *)&local_1c);
    if (local_12 == '\0') {
      QByteArray::QByteArray((QByteArray *)&local_18);
      local_1c = &DAT_007568dc;
      local_8 = 4;
      FUN_004f6850(local_24,&local_1c,*(int *)(param_1 + 0x58) + iVar6 * 4);
      local_8._0_1_ = 6;
      QString::~QString((QString *)&local_1c);
      FUN_00510a20();
      cVar1 = FUN_005108e0(local_24,&local_18);
      if (cVar1 == '\0') {
        FUN_00486c20("Download firmware failed !");
        local_11 = '\0';
      }
      else {
        uVar5 = *(undefined4 *)(local_18 + 4);
        pcVar9 = QByteArray::data((QByteArray *)&local_18);
        uVar8 = FUN_00486cd0(local_2c);
        local_8._0_1_ = 7;
        uVar8 = FUN_004f68c0(local_28,uVar8,"~webfirmware.dat");
        local_8._0_1_ = 8;
        iVar6 = FUN_00487330(uVar8,pcVar9,uVar5);
        QString::~QString(local_28);
        local_8._0_1_ = 6;
        QString::~QString(local_2c);
        if (iVar6 == 0) {
          param_1 = local_20;
        }
        else {
          uVar5 = FUN_00486cd0(local_28);
          local_8._0_1_ = 9;
          uVar5 = FUN_004f68c0(local_2c,uVar5,"~webfirmware.dat");
          param_1 = local_20;
          local_8._0_1_ = 10;
          local_11 = FUN_00505530(uVar5,0);
          QString::~QString(local_2c);
          QString::~QString(local_28);
        }
      }
      QString::~QString(local_24);
      local_8 = 0xffffffff;
      QByteArray::~QByteArray((QByteArray *)&local_18);
    }
    else {
      uVar5 = FUN_00486cd0(local_28);
      local_8 = 0xb;
      uVar5 = FUN_004f68c0(local_2c,uVar5,"~webfirmware.dat");
      local_8 = CONCAT31(local_8._1_3_,0xc);
      local_11 = FUN_00505530(uVar5,0);
      QString::~QString(local_2c);
      pQVar7 = local_28;
LAB_00502c47:
      local_8 = 0xffffffff;
      QString::~QString(pQVar7);
    }
    pcVar10 = hide_exref;
    if ((*(char *)(param_1 + 0x104) != '\0') && (*(char *)(param_1 + 0x105) != '\0')) {
      if (local_11 == '\0') {
        QWidget::hide(*(QWidget **)(param_1 + 0x40));
        QWidget::show(*(QWidget **)(param_1 + 0x3c));
      }
      else {
        QWidget::hide(*(QWidget **)(param_1 + 0x3c));
        QWidget::show(*(QWidget **)(param_1 + 0x40));
      }
      goto LAB_00502cfd;
    }
    if (local_11 != '\0') {
      FUN_005071f0();
      FUN_00505d00();
    }
    if (*(int *)(*(int *)(param_1 + 0x4c) + 0x2ca68) != 0x272a) {
      pcVar9 = "Successful!";
      if (local_11 == '\0') {
        pcVar9 = "Failed!";
      }
      goto LAB_00502cef;
    }
  }
  pcVar10 = hide_exref;
LAB_00502cfd:
  (*pcVar10)();
  *(undefined4 *)(param_1 + 0x50) = 3;
  ExceptionList = local_10;
  return;
}


