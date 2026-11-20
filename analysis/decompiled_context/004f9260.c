
void __fastcall FUN_004f9260(int param_1)

{
  QLabel *pQVar1;
  QTypedArrayData<unsigned_short> *pQVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  undefined4 uVar8;
  QTypedArrayData<unsigned_short> *local_18;
  QTypedArrayData<unsigned_short> *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00548d44;
  local_10 = ExceptionList;
  uVar4 = DAT_00759b24 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  iVar5 = QComboBox::currentIndex(*(QComboBox **)(param_1 + 0x8a08));
  bVar7 = iVar5 == 4;
  bVar3 = !bVar7;
  local_14 = (QTypedArrayData<unsigned_short> *)CONCAT31(local_14._1_3_,bVar3);
  pQVar2 = local_14;
  (**(code **)(**(int **)(param_1 + 0x8a14) + 0x2c))(local_14,uVar4);
  QWidget::setEnabled(*(QWidget **)(param_1 + 0x8a10),bVar3);
  (**(code **)(**(int **)(param_1 + 0x8a30) + 0x2c))(pQVar2);
  (**(code **)(**(int **)(param_1 + 0x8a1c) + 0x2c))(pQVar2);
  (**(code **)(**(int **)(param_1 + 0x8a10) + 0x2c))(pQVar2);
  (**(code **)(**(int **)(param_1 + 0x8a2c) + 0x2c))(pQVar2);
  (**(code **)(**(int **)(param_1 + 0x8a20) + 0x2c))(pQVar2);
  QWidget::setEnabled(*(QWidget **)(param_1 + 0x8a28),bVar3);
  (**(code **)(**(int **)(param_1 + 0x8a24) + 0x2c))(pQVar2);
  if ((iVar5 == 4) || (iVar5 == 0)) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  QWidget::setEnabled(*(QWidget **)(param_1 + 0x8a18),bVar3);
  (**(code **)(**(int **)(param_1 + 0x8a0c) + 0x2c))(bVar7);
  (**(code **)(**(int **)(param_1 + 0x8a34) + 0x2c))(bVar7);
  if (local_14._0_1_ == (QString)0x0) {
LAB_004f938b:
    if (iVar5 == 3) {
      pQVar1 = *(QLabel **)(param_1 + 0x8a1c);
      local_14 = QString::fromAscii_helper("LSB",3);
      local_8 = 0;
      QLabel::setText(pQVar1,(QString *)&local_14);
      local_8 = 0xffffffff;
      QString::~QString((QString *)&local_14);
      pQVar1 = *(QLabel **)(param_1 + 0x8a20);
      local_14 = QString::fromAscii_helper("MSB",3);
      local_8 = 1;
      QLabel::setText(pQVar1,(QString *)&local_14);
      local_8 = 0xffffffff;
      QString::~QString((QString *)&local_14);
      pQVar1 = *(QLabel **)(param_1 + 0x8a24);
      local_14 = QString::fromAscii_helper("Program",7);
      local_8 = 2;
      QLabel::setText(pQVar1,(QString *)&local_14);
      local_8 = 0xffffffff;
      QString::~QString((QString *)&local_14);
      uVar8 = 0;
      goto LAB_004f9562;
    }
    if (iVar5 == 5) goto LAB_004f944d;
    pQVar1 = *(QLabel **)(param_1 + 0x8a1c);
    local_14 = QString::fromAscii_helper("CC",2);
    local_8 = 4;
    QLabel::setText(pQVar1,(QString *)&local_14);
    local_8 = 0xffffffff;
    QString::~QString((QString *)&local_14);
    pQVar1 = *(QLabel **)(param_1 + 0x8a20);
    local_14 = QString::fromAscii_helper("Value1",6);
    local_8 = 5;
    QLabel::setText(pQVar1,(QString *)&local_14);
    local_8 = 0xffffffff;
    QString::~QString((QString *)&local_14);
    pQVar1 = *(QLabel **)(param_1 + 0x8a24);
    local_18 = QString::fromAscii_helper("Value2",6);
    local_8 = 6;
    QLabel::setText(pQVar1,(QString *)&local_18);
    local_8 = 0xffffffff;
    QString::~QString((QString *)&local_18);
  }
  else {
    pQVar1 = *(QLabel **)(param_1 + 0x8a30);
    iVar6 = QSpinBox::value(*(QSpinBox **)(param_1 + 0x8a2c));
    if (iVar5 != 5) {
      QLabel::setText(pQVar1,(QString *)(&DAT_007646d8 + iVar6 * 4));
      goto LAB_004f938b;
    }
    QLabel::setText(pQVar1,(QString *)(&DAT_007644d8 + iVar6 * 4));
LAB_004f944d:
    pQVar1 = *(QLabel **)(param_1 + 0x8a1c);
    local_14 = QString::fromAscii_helper("Note",4);
    local_8 = 3;
    QLabel::setText(pQVar1,(QString *)&local_14);
    local_8 = 0xffffffff;
    QString::~QString((QString *)&local_14);
    QWidget::setEnabled(*(QWidget **)(param_1 + 0x8a10),false);
    QWidget::setEnabled(*(QWidget **)(param_1 + 0x8a28),false);
    QWidget::setEnabled(*(QWidget **)(param_1 + 0x8a18),false);
  }
  uVar8 = 1;
LAB_004f9562:
  (**(code **)(**(int **)(param_1 + 0x8a30) + 0x2c))(uVar8);
  ExceptionList = local_10;
  return;
}


