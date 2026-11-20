
void __thiscall FUN_004f4cf0(int param_1,int param_2)

{
  QListData *this;
  QWidget *this_00;
  int iVar1;
  void **ppvVar2;
  QString *pQVar3;
  int local_1c;
  QTypedArrayData<unsigned_short> *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00545a4e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this = (QListData *)(param_1 + 0x1350);
  local_1c = 0;
  local_14 = param_1;
  iVar1 = QListData::size(this);
  if (0 < iVar1) {
    do {
      if ((**(int **)this != 1) && (**(int **)this != 0)) {
        FUN_004f2a30(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar2 = QListData::at(this,local_1c);
      this_00 = *ppvVar2;
      local_18 = QString::fromAscii_helper("",0);
      local_8 = 0;
      QWidget::setStyleSheet(this_00,(QString *)&local_18);
      local_8 = 0xffffffff;
      QString::~QString((QString *)&local_18);
      local_1c = local_1c + 1;
      iVar1 = QListData::size(this);
    } while (local_1c < iVar1);
    param_1 = local_14;
  }
  if (param_2 == 0) {
    iVar1 = 0;
    pQVar3 = (QString *)(local_14 + 0x1368);
    do {
      if ((**(int **)this != 1) && (**(int **)this != 0)) {
        FUN_004f2a30(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar2 = QListData::at(this,iVar1);
      QWidget::setStyleSheet(*ppvVar2,pQVar3);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 4);
    ExceptionList = local_10;
    return;
  }
  if (param_2 == 2) {
    iVar1 = 0;
    pQVar3 = (QString *)(local_14 + 0x136c);
    do {
      if ((**(int **)this != 1) && (**(int **)this != 0)) {
        FUN_004f2a30(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar2 = QListData::at(this,iVar1);
      QWidget::setStyleSheet(*ppvVar2,pQVar3);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 4);
    ExceptionList = local_10;
    return;
  }
  if (param_2 == 1) {
    iVar1 = 4;
    pQVar3 = (QString *)(local_14 + 0x1368);
    do {
      if ((**(int **)this != 1) && (**(int **)this != 0)) {
        FUN_004f2a30(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar2 = QListData::at(this,iVar1);
      QWidget::setStyleSheet(*ppvVar2,pQVar3);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 8);
    ExceptionList = local_10;
    return;
  }
  if (param_2 == 3) {
    iVar1 = 4;
    pQVar3 = (QString *)(local_14 + 0x136c);
    do {
      if ((**(int **)this != 1) && (**(int **)this != 0)) {
        FUN_004f2a30(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar2 = QListData::at(this,iVar1);
      QWidget::setStyleSheet(*ppvVar2,pQVar3);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 8);
    ExceptionList = local_10;
    return;
  }
  if (param_2 == 4) {
    if ((**(int **)this != 1) && (**(int **)this != 0)) {
      FUN_004f2a30(*(undefined4 *)(*(int *)this + 4));
    }
    ppvVar2 = QListData::at(this,0x15);
    QWidget::setStyleSheet(*ppvVar2,(QString *)(param_1 + 0x1368));
    ExceptionList = local_10;
    return;
  }
  if (param_2 == 5) {
    iVar1 = 8;
    pQVar3 = (QString *)(local_14 + 0x1368);
    do {
      if ((**(int **)this != 1) && (**(int **)this != 0)) {
        FUN_004f2a30(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar2 = QListData::at(this,iVar1);
      QWidget::setStyleSheet(*ppvVar2,pQVar3);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0xc);
    ExceptionList = local_10;
    return;
  }
  if (param_2 == 7) {
    iVar1 = 8;
    pQVar3 = (QString *)(local_14 + 0x136c);
    do {
      if ((**(int **)this != 1) && (**(int **)this != 0)) {
        FUN_004f2a30(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar2 = QListData::at(this,iVar1);
      QWidget::setStyleSheet(*ppvVar2,pQVar3);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0xc);
    ExceptionList = local_10;
    return;
  }
  if (param_2 == 6) {
    iVar1 = 0xc;
    pQVar3 = (QString *)(local_14 + 0x1368);
    do {
      if ((**(int **)this != 1) && (**(int **)this != 0)) {
        FUN_004f2a30(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar2 = QListData::at(this,iVar1);
      QWidget::setStyleSheet(*ppvVar2,pQVar3);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x10);
    ExceptionList = local_10;
    return;
  }
  if (param_2 == 8) {
    iVar1 = 0xc;
    pQVar3 = (QString *)(local_14 + 0x136c);
    do {
      if ((**(int **)this != 1) && (**(int **)this != 0)) {
        FUN_004f2a30(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar2 = QListData::at(this,iVar1);
      QWidget::setStyleSheet(*ppvVar2,pQVar3);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x10);
    ExceptionList = local_10;
    return;
  }
  if (param_2 == 9) {
    iVar1 = 0x13;
    pQVar3 = (QString *)(local_14 + 0x1368);
    do {
      if ((**(int **)this != 1) && (**(int **)this != 0)) {
        FUN_004f2a30(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar2 = QListData::at(this,iVar1);
      QWidget::setStyleSheet(*ppvVar2,pQVar3);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x15);
    ExceptionList = local_10;
    return;
  }
  if (param_2 == 10) {
    iVar1 = 0x10;
    pQVar3 = (QString *)(local_14 + 0x1368);
    do {
      if ((**(int **)this != 1) && (**(int **)this != 0)) {
        FUN_004f2a30(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar2 = QListData::at(this,iVar1);
      QWidget::setStyleSheet(*ppvVar2,pQVar3);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x13);
  }
  ExceptionList = local_10;
  return;
}


