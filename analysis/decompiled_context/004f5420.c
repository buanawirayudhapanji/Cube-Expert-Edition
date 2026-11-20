
void __thiscall FUN_004f5420(int param_1,QLabel *param_2)

{
  QListData *this;
  QLabel *pQVar1;
  void **ppvVar2;
  int iVar3;
  int iVar4;
  QTypedArrayData<unsigned_short> *local_1c;
  QTypedArrayData<unsigned_short> *local_18;
  QTypedArrayData<unsigned_short> *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00545a99;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this = (QListData *)(param_1 + 0x1358);
  if ((**(int **)(param_1 + 0x1358) != 1) && (**(int **)(param_1 + 0x1358) != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  iVar4 = (int)param_2;
  ppvVar2 = QListData::at(this,(int)param_2);
  iVar3 = QComboBox::currentIndex(*(QComboBox **)((int)*ppvVar2 + 0x1c));
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,iVar4);
  pQVar1 = *(QLabel **)((int)*ppvVar2 + 0x10);
  param_2 = (QLabel *)QString::fromAscii_helper("Min",3);
  local_8 = 0;
  QLabel::setText(pQVar1,(QString *)&param_2);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,iVar4);
  pQVar1 = *(QLabel **)((int)*ppvVar2 + 0x14);
  local_14 = QString::fromAscii_helper("Max",3);
  local_8 = 1;
  QLabel::setText(pQVar1,(QString *)&local_14);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_14);
  if (iVar3 != 0) {
    if ((iVar3 != 1) && (iVar3 != 2)) {
      if (iVar3 == 3) {
        iVar3 = FUN_004f1760(iVar4);
        (**(code **)(**(int **)(iVar3 + 0xc) + 0x2c))(1);
        iVar3 = FUN_004f1760(iVar4);
        (**(code **)(**(int **)(iVar3 + 0x28) + 0x2c))(1);
        iVar3 = FUN_004f1760(iVar4);
        (**(code **)(**(int **)(iVar3 + 0x18) + 0x2c))(1);
        iVar3 = FUN_004f1760(iVar4);
        pQVar1 = *(QLabel **)(iVar3 + 0x18);
        iVar3 = FUN_004f1760(iVar4);
        iVar3 = QSpinBox::value(*(QSpinBox **)(iVar3 + 0x28));
        QLabel::setText(pQVar1,(QString *)(&DAT_007636d8 + iVar3 * 4));
        iVar3 = FUN_004f1760(iVar4);
        pQVar1 = *(QLabel **)(iVar3 + 0x10);
        local_18 = QString::fromAscii_helper("Left",4);
        local_8 = 2;
        QLabel::setText(pQVar1,(QString *)&local_18);
        local_8 = 0xffffffff;
        QString::~QString((QString *)&local_18);
        iVar4 = FUN_004f1760(iVar4);
        pQVar1 = *(QLabel **)(iVar4 + 0x14);
        local_1c = QString::fromAscii_helper("Right",5);
        local_8 = 3;
        QLabel::setText(pQVar1,(QString *)&local_1c);
        QString::~QString((QString *)&local_1c);
      }
      ExceptionList = local_10;
      return;
    }
    if ((**(int **)this != 1) && (**(int **)this != 0)) {
      FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
    }
    ppvVar2 = QListData::at(this,iVar4);
    (**(code **)(**(int **)((int)*ppvVar2 + 0xc) + 0x2c))(0);
    if ((**(int **)this != 1) && (**(int **)this != 0)) {
      FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
    }
    ppvVar2 = QListData::at(this,iVar4);
    (**(code **)(**(int **)((int)*ppvVar2 + 0x28) + 0x2c))(0);
    if ((**(int **)this != 1) && (**(int **)this != 0)) {
      FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
    }
    ppvVar2 = QListData::at(this,iVar4);
    (**(code **)(**(int **)((int)*ppvVar2 + 0x18) + 0x2c))(0);
    ExceptionList = local_10;
    return;
  }
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,iVar4);
  (**(code **)(**(int **)((int)*ppvVar2 + 0xc) + 0x2c))(1);
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,iVar4);
  (**(code **)(**(int **)((int)*ppvVar2 + 0x28) + 0x2c))(1);
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
  iVar4 = QSpinBox::value(*(QSpinBox **)((int)*ppvVar2 + 0x28));
  QLabel::setText(param_2,(QString *)(&DAT_007636d8 + iVar4 * 4));
  ExceptionList = local_10;
  return;
}


