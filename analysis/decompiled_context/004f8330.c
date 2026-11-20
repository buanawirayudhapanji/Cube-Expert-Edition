
void __fastcall FUN_004f8330(int param_1)

{
  QLabel *pQVar1;
  int iVar2;
  QTypedArrayData<unsigned_short> *local_18;
  QTypedArrayData<unsigned_short> *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00548d99;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar2 = QComboBox::currentIndex(*(QComboBox **)(param_1 + 0x89c8));
  pQVar1 = *(QLabel **)(param_1 + 0x89bc);
  local_14 = QString::fromAscii_helper("Min",3);
  local_8 = 0;
  QLabel::setText(pQVar1,(QString *)&local_14);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_14);
  pQVar1 = *(QLabel **)(param_1 + 0x89a0);
  local_14 = QString::fromAscii_helper("Max",3);
  local_8 = 1;
  QLabel::setText(pQVar1,(QString *)&local_14);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_14);
  if (iVar2 == 0) {
    QWidget::setEnabled(*(QWidget **)(param_1 + 0x89cc),true);
    (**(code **)(**(int **)(param_1 + 0x89ac) + 0x2c))(1);
    pQVar1 = *(QLabel **)(param_1 + 0x89ac);
    iVar2 = QSpinBox::value(*(QSpinBox **)(param_1 + 0x89cc));
    QLabel::setText(pQVar1,(QString *)(&DAT_007646d8 + iVar2 * 4));
    ExceptionList = local_10;
    return;
  }
  if ((iVar2 == 1) || (iVar2 == 2)) {
    QWidget::setEnabled(*(QWidget **)(param_1 + 0x89cc),false);
    (**(code **)(**(int **)(param_1 + 0x89ac) + 0x2c))(0);
    ExceptionList = local_10;
    return;
  }
  if (iVar2 == 3) {
    QWidget::setEnabled(*(QWidget **)(param_1 + 0x89cc),true);
    (**(code **)(**(int **)(param_1 + 0x89ac) + 0x2c))(1);
    pQVar1 = *(QLabel **)(param_1 + 0x89ac);
    iVar2 = QSpinBox::value(*(QSpinBox **)(param_1 + 0x89cc));
    QLabel::setText(pQVar1,(QString *)(&DAT_007646d8 + iVar2 * 4));
    pQVar1 = *(QLabel **)(param_1 + 0x89bc);
    local_14 = QString::fromAscii_helper("Left",4);
    local_8 = 2;
    QLabel::setText(pQVar1,(QString *)&local_14);
    local_8 = 0xffffffff;
    QString::~QString((QString *)&local_14);
    pQVar1 = *(QLabel **)(param_1 + 0x89a0);
    local_18 = QString::fromAscii_helper("Right",5);
    local_8 = 3;
    QLabel::setText(pQVar1,(QString *)&local_18);
    QString::~QString((QString *)&local_18);
  }
  ExceptionList = local_10;
  return;
}


