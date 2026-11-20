
void __fastcall FUN_00503dd0(int param_1)

{
  QAbstractButton *pQVar1;
  undefined2 *puVar2;
  QString *pQVar3;
  QChar aQStack_46 [2];
  QString local_30 [4];
  undefined4 local_2c;
  undefined4 local_28;
  QTypedArrayData<unsigned_short> *local_24;
  QTypedArrayData<unsigned_short> *local_20;
  QString local_1c [4];
  undefined4 local_18;
  QChar local_12 [2];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054cde6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_24 = (QTypedArrayData<unsigned_short> *)0x0;
  QFont::setPixelSize((QFont *)&DAT_007626a0,0xe);
  local_20 = QString::fromAscii_helper("%1",2);
  local_8 = 0;
  puVar2 = (undefined2 *)QChar::QChar(local_12,0xf1c6);
  local_24 = (QTypedArrayData<unsigned_short> *)CONCAT31(local_24._1_3_,0x20);
  local_18 = CONCAT22(local_18._2_2_,*puVar2);
  QChar::QChar(aQStack_46 + -6,local_24);
  QString::arg((QString *)&local_20,local_1c,local_18,0);
  QString::~QString((QString *)&local_20);
  pQVar1 = *(QAbstractButton **)(param_1 + 0x30);
  local_8._0_1_ = 3;
  QString::QString((QString *)&local_18,local_1c);
  local_24 = (QTypedArrayData<unsigned_short> *)0x1;
  pQVar3 = (QString *)QString::fromUtf8((char *)&local_28,0x593144);
  local_8._0_1_ = 4;
  QString::append((QString *)&local_18,pQVar3);
  local_8._0_1_ = 3;
  QString::~QString((QString *)&local_28);
  QAbstractButton::setText(pQVar1,(QString *)&local_18);
  local_8._0_1_ = 2;
  QString::~QString((QString *)&local_18);
  QWidget::setFont(*(QWidget **)(param_1 + 0x30),(QFont *)&DAT_007626a0);
  QFont::setPixelSize((QFont *)&DAT_007626a0,0x17);
  local_24 = QString::fromAscii_helper("%1",2);
  local_8._0_1_ = 5;
  puVar2 = (undefined2 *)QChar::QChar((QChar *)((int)&local_18 + 2),0xf093);
  local_28 = CONCAT31(local_28._1_3_,0x20);
  local_2c = CONCAT22(local_2c._2_2_,*puVar2);
  QChar::QChar(aQStack_46 + -6,local_28);
  pQVar3 = (QString *)QString::arg((QString *)&local_24,local_30,local_2c,0);
  QString::operator=(local_1c,pQVar3);
  QString::~QString(local_30);
  QString::~QString((QString *)&local_24);
  pQVar1 = *(QAbstractButton **)(param_1 + 0x48);
  local_8._0_1_ = 6;
  QString::QString((QString *)&local_18,local_1c);
  local_24 = (QTypedArrayData<unsigned_short> *)0x2;
  pQVar3 = (QString *)QString::fromUtf8((char *)local_30,0x59315c);
  local_8._0_1_ = 7;
  QString::append((QString *)&local_18,pQVar3);
  local_8._0_1_ = 6;
  QString::~QString(local_30);
  QAbstractButton::setText(pQVar1,(QString *)&local_18);
  local_8 = CONCAT31(local_8._1_3_,2);
  QString::~QString((QString *)&local_18);
  QWidget::setFont(*(QWidget **)(param_1 + 0x48),(QFont *)&DAT_007626a0);
  QString::~QString(local_1c);
  ExceptionList = local_10;
  return;
}


