
void __fastcall FUN_004fa9c0(int param_1)

{
  QLabel *pQVar1;
  QTypedArrayData<unsigned_short> *pQVar2;
  uint uVar3;
  int iVar4;
  uint3 uVar6;
  int iVar5;
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
  uVar3 = DAT_00759b24 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  iVar4 = QComboBox::currentIndex(*(QComboBox **)(param_1 + 0x420));
  bVar7 = iVar4 == 4;
  local_14 = (QTypedArrayData<unsigned_short> *)CONCAT31(local_14._1_3_,!bVar7);
  pQVar2 = local_14;
  (**(code **)(**(int **)(param_1 + 0x404) + 0x2c))(local_14,uVar3);
  (**(code **)(**(int **)(param_1 + 0x400) + 0x2c))(pQVar2);
  (**(code **)(**(int **)(param_1 + 0x41c) + 0x2c))(pQVar2);
  (**(code **)(**(int **)(param_1 + 0x414) + 0x2c))(pQVar2);
  (**(code **)(**(int **)(param_1 + 0x418) + 0x2c))(pQVar2);
  (**(code **)(**(int **)(param_1 + 0x3fc) + 0x2c))(pQVar2);
  (**(code **)(**(int **)(param_1 + 0x410) + 0x2c))(pQVar2);
  uVar6 = (uint3)((uint)**(int **)(param_1 + 0x408) >> 8);
  if ((iVar4 == 4) || (iVar4 == 0)) {
    iVar5 = (uint)uVar6 << 8;
  }
  else {
    iVar5 = CONCAT31(uVar6,1);
  }
  (**(code **)(**(int **)(param_1 + 0x408) + 0x2c))(iVar5);
  uVar6 = (uint3)((uint)**(int **)(param_1 + 0x40c) >> 8);
  if ((local_14._0_1_ == (QString)0x0) || (iVar4 == 0)) {
    iVar5 = (uint)uVar6 << 8;
  }
  else {
    iVar5 = CONCAT31(uVar6,1);
  }
  (**(code **)(**(int **)(param_1 + 0x40c) + 0x2c))(iVar5);
  (**(code **)(**(int **)(param_1 + 0x428) + 0x2c))(bVar7);
  (**(code **)(**(int **)(param_1 + 0x438) + 0x2c))(bVar7);
  if (local_14._0_1_ == (QString)0x0) {
LAB_004faaf0:
    if (iVar4 == 3) {
      pQVar1 = *(QLabel **)(param_1 + 0x414);
      local_14 = QString::fromAscii_helper("LSB",3);
      local_8 = 0;
      QLabel::setText(pQVar1,(QString *)&local_14);
      local_8 = 0xffffffff;
      QString::~QString((QString *)&local_14);
      pQVar1 = *(QLabel **)(param_1 + 0x3fc);
      local_14 = QString::fromAscii_helper("MSB",3);
      local_8 = 1;
      QLabel::setText(pQVar1,(QString *)&local_14);
      local_8 = 0xffffffff;
      QString::~QString((QString *)&local_14);
      pQVar1 = *(QLabel **)(param_1 + 0x408);
      local_14 = QString::fromAscii_helper("Program",7);
      local_8 = 2;
      QLabel::setText(pQVar1,(QString *)&local_14);
      local_8 = 0xffffffff;
      QString::~QString((QString *)&local_14);
      uVar8 = 0;
      goto LAB_004facf5;
    }
    if (iVar4 == 5) goto LAB_004fabb6;
    pQVar1 = *(QLabel **)(param_1 + 0x414);
    local_14 = QString::fromAscii_helper("CC",2);
    local_8 = 4;
    QLabel::setText(pQVar1,(QString *)&local_14);
    local_8 = 0xffffffff;
    QString::~QString((QString *)&local_14);
    pQVar1 = *(QLabel **)(param_1 + 0x3fc);
    local_14 = QString::fromAscii_helper("Value1",6);
    local_8 = 5;
    QLabel::setText(pQVar1,(QString *)&local_14);
    local_8 = 0xffffffff;
    QString::~QString((QString *)&local_14);
    pQVar1 = *(QLabel **)(param_1 + 0x408);
    local_18 = QString::fromAscii_helper("Value2",6);
    local_8 = 6;
    QLabel::setText(pQVar1,(QString *)&local_18);
    local_8 = 0xffffffff;
    QString::~QString((QString *)&local_18);
  }
  else {
    pQVar1 = *(QLabel **)(param_1 + 0x41c);
    iVar5 = QSpinBox::value(*(QSpinBox **)(param_1 + 0x418));
    if (iVar4 != 5) {
      QLabel::setText(pQVar1,(QString *)(&DAT_00764ad8 + iVar5 * 4));
      goto LAB_004faaf0;
    }
    QLabel::setText(pQVar1,(QString *)(&DAT_007648d8 + iVar5 * 4));
LAB_004fabb6:
    pQVar1 = *(QLabel **)(param_1 + 0x414);
    local_14 = QString::fromAscii_helper("Note",4);
    local_8 = 3;
    QLabel::setText(pQVar1,(QString *)&local_14);
    local_8 = 0xffffffff;
    QString::~QString((QString *)&local_14);
    (**(code **)(**(int **)(param_1 + 0x404) + 0x2c))(0);
    (**(code **)(**(int **)(param_1 + 0x3fc) + 0x2c))(0);
    (**(code **)(**(int **)(param_1 + 0x408) + 0x2c))(0);
    (**(code **)(**(int **)(param_1 + 0x400) + 0x2c))(0);
    (**(code **)(**(int **)(param_1 + 0x410) + 0x2c))(0);
    (**(code **)(**(int **)(param_1 + 0x40c) + 0x2c))(0);
  }
  uVar8 = 1;
LAB_004facf5:
  (**(code **)(**(int **)(param_1 + 0x41c) + 0x2c))(uVar8);
  ExceptionList = local_10;
  return;
}


