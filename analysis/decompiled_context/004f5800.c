
void __thiscall FUN_004f5800(int param_1,QLabel *param_2)

{
  QListData *this;
  QLabel *pQVar1;
  void **ppvVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  QTypedArrayData<unsigned_short> *local_24;
  QTypedArrayData<unsigned_short> *local_20;
  QTypedArrayData<unsigned_short> *local_1c;
  QTypedArrayData<unsigned_short> *local_18;
  QListData *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00545b3a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this = (QListData *)(param_1 + 0x1354);
  local_14 = this;
  if ((**(int **)(param_1 + 0x1354) != 1) && (**(int **)(param_1 + 0x1354) != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  iVar4 = (int)param_2;
  ppvVar2 = QListData::at(this,(int)param_2);
  iVar3 = QComboBox::currentIndex(*(QComboBox **)((int)*ppvVar2 + 0x1c));
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,iVar4);
  (**(code **)(**(int **)((int)*ppvVar2 + 4) + 0x2c))(1);
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,iVar4);
  (**(code **)(**(int **)((int)*ppvVar2 + 0xc) + 0x2c))(1);
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,iVar4);
  (**(code **)(**(int **)((int)*ppvVar2 + 0x10) + 0x2c))(1);
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,iVar4);
  (**(code **)(**(int **)((int)*ppvVar2 + 0x28) + 0x2c))(1);
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,iVar4);
  (**(code **)(**(int **)((int)*ppvVar2 + 0x20) + 0x2c))(1);
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,iVar4);
  (**(code **)(**(int **)((int)*ppvVar2 + 0x2c) + 0x2c))(1);
  if (iVar3 == 0) {
    if ((**(int **)this != 1) && (**(int **)this != 0)) {
      FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
    }
    ppvVar2 = QListData::at(this,iVar4);
    pQVar1 = *(QLabel **)((int)*ppvVar2 + 8);
    param_2 = (QLabel *)QString::fromAscii_helper("Note",4);
    local_8 = 0;
    QLabel::setText(pQVar1,(QString *)&param_2);
    local_8 = 0xffffffff;
    QString::~QString((QString *)&param_2);
    if ((**(int **)this != 1) && (**(int **)this != 0)) {
      FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
    }
    ppvVar2 = QListData::at(this,iVar4);
    pQVar1 = *(QLabel **)((int)*ppvVar2 + 0xc);
    local_18 = QString::fromAscii_helper("MinVel",6);
    local_8 = 1;
    QLabel::setText(pQVar1,(QString *)&local_18);
    local_8 = 0xffffffff;
    QString::~QString((QString *)&local_18);
    if ((**(int **)this != 1) && (**(int **)this != 0)) {
      FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
    }
    ppvVar2 = QListData::at(this,iVar4);
    pQVar1 = *(QLabel **)((int)*ppvVar2 + 0x10);
    local_1c = QString::fromAscii_helper("MaxVel",6);
    local_8 = 2;
    QLabel::setText(pQVar1,(QString *)&local_1c);
    local_8 = 0xffffffff;
    QString::~QString((QString *)&local_1c);
    if ((**(int **)this != 1) && (**(int **)this != 0)) {
      FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
    }
    ppvVar2 = QListData::at(this,iVar4);
    (**(code **)(**(int **)((int)*ppvVar2 + 0x18) + 0x2c))(1);
    if ((**(int **)this != 1) && (**(int **)this != 0)) {
      FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
    }
    ppvVar2 = QListData::at(this,iVar4);
    param_2 = *(QLabel **)((int)*ppvVar2 + 0x18);
    if ((**(int **)this != 1) && (**(int **)this != 0)) {
      FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
    }
    ppvVar2 = QListData::at(this,iVar4);
    iVar4 = QSpinBox::value(*(QSpinBox **)((int)*ppvVar2 + 0x24));
    QLabel::setText(param_2,(QString *)(&DAT_007634d8 + iVar4 * 4));
    ExceptionList = local_10;
    return;
  }
  if (iVar3 == 1) {
    if ((**(int **)this != 1) && (**(int **)this != 0)) {
      FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
    }
    ppvVar2 = QListData::at(this,iVar4);
    pQVar1 = *(QLabel **)((int)*ppvVar2 + 8);
    param_2 = (QLabel *)QString::fromAscii_helper("CC",2);
    local_8 = 3;
    QLabel::setText(pQVar1,(QString *)&param_2);
    local_8 = 0xffffffff;
    QString::~QString((QString *)&param_2);
    if ((**(int **)this != 1) && (**(int **)this != 0)) {
      FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
    }
    ppvVar2 = QListData::at(this,iVar4);
    pQVar1 = *(QLabel **)((int)*ppvVar2 + 0xc);
    local_1c = QString::fromAscii_helper("Value1",6);
    local_8 = 4;
    QLabel::setText(pQVar1,(QString *)&local_1c);
    local_8 = 0xffffffff;
    QString::~QString((QString *)&local_1c);
    if ((**(int **)this != 1) && (**(int **)this != 0)) {
      FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
    }
    ppvVar2 = QListData::at(this,iVar4);
    pQVar1 = *(QLabel **)((int)*ppvVar2 + 0x10);
    local_18 = QString::fromAscii_helper("Value2",6);
    local_8 = 5;
    QLabel::setText(pQVar1,(QString *)&local_18);
    local_8 = 0xffffffff;
    QString::~QString((QString *)&local_18);
    if ((**(int **)this != 1) && (**(int **)this != 0)) {
      FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
    }
    ppvVar2 = QListData::at(this,iVar4);
    (**(code **)(**(int **)((int)*ppvVar2 + 0x18) + 0x2c))(1);
    if ((**(int **)this != 1) && (**(int **)this != 0)) {
      FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
    }
    ppvVar2 = QListData::at(this,iVar4);
    param_2 = *(QLabel **)((int)*ppvVar2 + 0x18);
    if ((**(int **)this != 1) && (**(int **)this != 0)) {
      FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
    }
    ppvVar2 = QListData::at(this,iVar4);
    iVar4 = QSpinBox::value(*(QSpinBox **)((int)*ppvVar2 + 0x24));
    QLabel::setText(param_2,(QString *)(&DAT_007636d8 + iVar4 * 4));
    ExceptionList = local_10;
    return;
  }
  if (iVar3 != 2) {
    if (iVar3 == 3) {
      iVar4 = FUN_004f1760(iVar4);
      pQVar1 = *(QLabel **)(iVar4 + 8);
      local_1c = QString::fromAscii_helper("LSB",3);
      local_8 = 9;
      QLabel::setText(pQVar1,(QString *)&local_1c);
      local_8 = 0xffffffff;
      QString::~QString((QString *)&local_1c);
      iVar4 = FUN_004f1760(param_2);
      pQVar1 = *(QLabel **)(iVar4 + 0xc);
      local_18 = QString::fromAscii_helper("MSB",3);
      local_8 = 10;
      QLabel::setText(pQVar1,(QString *)&local_18);
      local_8 = 0xffffffff;
      QString::~QString((QString *)&local_18);
      iVar4 = FUN_004f1760(param_2);
      pQVar1 = *(QLabel **)(iVar4 + 0x10);
      local_20 = QString::fromAscii_helper("Program",7);
      local_8 = 0xb;
      QLabel::setText(pQVar1,(QString *)&local_20);
      local_8 = 0xffffffff;
      QString::~QString((QString *)&local_20);
      iVar4 = FUN_004f1760(param_2);
      uVar5 = 0;
    }
    else {
      if (iVar3 != 4) {
        ExceptionList = local_10;
        return;
      }
      iVar3 = FUN_004f1760(iVar4);
      (**(code **)(**(int **)(iVar3 + 4) + 0x2c))(0);
      iVar3 = FUN_004f1760(iVar4);
      pQVar1 = *(QLabel **)(iVar3 + 8);
      local_24 = QString::fromAscii_helper("Note",4);
      local_8 = 0xc;
      QLabel::setText(pQVar1,(QString *)&local_24);
      local_8 = 0xffffffff;
      QString::~QString((QString *)&local_24);
      iVar3 = FUN_004f1760(iVar4);
      (**(code **)(**(int **)(iVar3 + 0xc) + 0x2c))(0);
      iVar3 = FUN_004f1760(iVar4);
      (**(code **)(**(int **)(iVar3 + 0x10) + 0x2c))(0);
      iVar3 = FUN_004f1760(iVar4);
      (**(code **)(**(int **)(iVar3 + 0x28) + 0x2c))(0);
      iVar3 = FUN_004f1760(iVar4);
      (**(code **)(**(int **)(iVar3 + 0x20) + 0x2c))(0);
      iVar3 = FUN_004f1760(iVar4);
      (**(code **)(**(int **)(iVar3 + 0x2c) + 0x2c))(0);
      iVar4 = FUN_004f1760(iVar4);
      uVar5 = 1;
    }
    (**(code **)(**(int **)(iVar4 + 0x18) + 0x2c))(uVar5);
    ExceptionList = local_10;
    return;
  }
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,iVar4);
  pQVar1 = *(QLabel **)((int)*ppvVar2 + 8);
  param_2 = (QLabel *)QString::fromAscii_helper("CC",2);
  local_8 = 6;
  QLabel::setText(pQVar1,(QString *)&param_2);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,iVar4);
  pQVar1 = *(QLabel **)((int)*ppvVar2 + 0xc);
  local_1c = QString::fromAscii_helper("Up",2);
  local_8 = 7;
  QLabel::setText(pQVar1,(QString *)&local_1c);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_1c);
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,iVar4);
  pQVar1 = *(QLabel **)((int)*ppvVar2 + 0x10);
  local_18 = QString::fromAscii_helper("Down",4);
  local_8 = 8;
  QLabel::setText(pQVar1,(QString *)&local_18);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_18);
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,iVar4);
  (**(code **)(**(int **)((int)*ppvVar2 + 0x18) + 0x2c))(1);
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,iVar4);
  param_2 = *(QLabel **)((int)*ppvVar2 + 0x18);
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,iVar4);
  iVar4 = QSpinBox::value(*(QSpinBox **)((int)*ppvVar2 + 0x24));
  QLabel::setText(param_2,(QString *)(&DAT_007636d8 + iVar4 * 4));
  ExceptionList = local_10;
  return;
}


