
void __thiscall FUN_004f6090(int param_1,int param_2)

{
  QListData *this;
  bool bVar1;
  void **ppvVar2;
  uint3 uVar6;
  int iVar3;
  int iVar4;
  QString *pQVar5;
  QLabel *pQVar7;
  bool bVar8;
  undefined4 uVar9;
  QTypedArrayData<unsigned_short> *local_24;
  QTypedArrayData<unsigned_short> *local_20;
  QTypedArrayData<unsigned_short> *local_1c;
  QTypedArrayData<unsigned_short> *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00545ba4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this = (QListData *)(param_1 + 0x135c);
  if ((**(int **)(param_1 + 0x135c) != 1) && (**(int **)(param_1 + 0x135c) != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,param_2);
  local_14 = QComboBox::currentIndex(*(QComboBox **)((int)*ppvVar2 + 0x1c));
  bVar8 = local_14 == 4;
  bVar1 = !bVar8;
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,param_2);
  (**(code **)(**(int **)((int)*ppvVar2 + 4) + 0x2c))(bVar1);
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,param_2);
  (**(code **)(**(int **)((int)*ppvVar2 + 0x20) + 0x2c))(bVar1);
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,param_2);
  (**(code **)(**(int **)((int)*ppvVar2 + 8) + 0x2c))(bVar1);
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,param_2);
  (**(code **)(**(int **)((int)*ppvVar2 + 0x24) + 0x2c))(bVar1);
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,param_2);
  (**(code **)(**(int **)((int)*ppvVar2 + 0xc) + 0x2c))(bVar1);
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,param_2);
  (**(code **)(**(int **)((int)*ppvVar2 + 0x28) + 0x2c))(bVar1);
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,param_2);
  uVar6 = (uint3)((uint)**(int **)((int)*ppvVar2 + 0x10) >> 8);
  if ((bVar1) && (local_14 != 0)) {
    iVar4 = CONCAT31(uVar6,1);
  }
  else {
    iVar4 = (uint)uVar6 << 8;
  }
  (**(code **)(**(int **)((int)*ppvVar2 + 0x10) + 0x2c))(iVar4);
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,param_2);
  uVar6 = (uint3)((uint)**(int **)((int)*ppvVar2 + 0x2c) >> 8);
  if ((bVar1) && (local_14 != 0)) {
    iVar4 = CONCAT31(uVar6,1);
  }
  else {
    iVar4 = (uint)uVar6 << 8;
  }
  (**(code **)(**(int **)((int)*ppvVar2 + 0x2c) + 0x2c))(iVar4);
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,param_2);
  (**(code **)(**(int **)((int)*ppvVar2 + 0x18) + 0x2c))(bVar1);
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,param_2);
  (**(code **)(**(int **)((int)*ppvVar2 + 0x14) + 0x2c))(bVar8);
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar2 = QListData::at(this,param_2);
  (**(code **)(**(int **)((int)*ppvVar2 + 0x30) + 0x2c))(bVar8);
  if (bVar1) {
    if ((**(int **)this != 1) && (**(int **)this != 0)) {
      FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
    }
    ppvVar2 = QListData::at(this,param_2);
    iVar3 = QComboBox::currentIndex(*(QComboBox **)((int)*ppvVar2 + 0x1c));
    iVar4 = **(int **)this;
    if (iVar3 == 5) {
      if ((iVar4 != 1) && (iVar4 != 0)) {
        FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar2 = QListData::at(this,param_2);
      pQVar7 = *(QLabel **)((int)*ppvVar2 + 0x18);
      if ((**(int **)this != 1) && (**(int **)this != 0)) {
        FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar2 = QListData::at(this,param_2);
      iVar4 = QSpinBox::value(*(QSpinBox **)((int)*ppvVar2 + 0x24));
      pQVar5 = (QString *)(&DAT_007634d8 + iVar4 * 4);
    }
    else {
      if ((iVar4 != 1) && (iVar4 != 0)) {
        FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar2 = QListData::at(this,param_2);
      pQVar7 = *(QLabel **)((int)*ppvVar2 + 0x18);
      if ((**(int **)this != 1) && (**(int **)this != 0)) {
        FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar2 = QListData::at(this,param_2);
      iVar4 = QSpinBox::value(*(QSpinBox **)((int)*ppvVar2 + 0x24));
      pQVar5 = (QString *)(&DAT_007636d8 + iVar4 * 4);
    }
    QLabel::setText(pQVar7,pQVar5);
  }
  iVar4 = **(int **)this;
  if (local_14 == 3) {
    if ((iVar4 != 1) && (iVar4 != 0)) {
      FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
    }
    ppvVar2 = QListData::at(this,param_2);
    pQVar7 = *(QLabel **)((int)*ppvVar2 + 8);
    local_18 = QString::fromAscii_helper("LSB",3);
    local_8 = 0;
    QLabel::setText(pQVar7,(QString *)&local_18);
    local_8 = 0xffffffff;
    QString::~QString((QString *)&local_18);
    if ((**(int **)this != 1) && (**(int **)this != 0)) {
      FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
    }
    ppvVar2 = QListData::at(this,param_2);
    pQVar7 = *(QLabel **)((int)*ppvVar2 + 0xc);
    local_1c = QString::fromAscii_helper("MSB",3);
    local_8 = 1;
    QLabel::setText(pQVar7,(QString *)&local_1c);
    local_8 = 0xffffffff;
    QString::~QString((QString *)&local_1c);
    if ((**(int **)this != 1) && (**(int **)this != 0)) {
      FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
    }
    ppvVar2 = QListData::at(this,param_2);
    pQVar7 = *(QLabel **)((int)*ppvVar2 + 0x10);
    local_20 = QString::fromAscii_helper("Program",7);
    local_8 = 2;
    QLabel::setText(pQVar7,(QString *)&local_20);
    local_8 = 0xffffffff;
    QString::~QString((QString *)&local_20);
    if ((**(int **)this != 1) && (**(int **)this != 0)) {
      FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
    }
    ppvVar2 = QListData::at(this,param_2);
    uVar9 = 0;
  }
  else {
    if (local_14 == 5) {
      if ((iVar4 != 1) && (iVar4 != 0)) {
        FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar2 = QListData::at(this,param_2);
      pQVar7 = *(QLabel **)((int)*ppvVar2 + 8);
      local_20 = QString::fromAscii_helper("Note",4);
      local_8 = 3;
      QLabel::setText(pQVar7,(QString *)&local_20);
      local_8 = 0xffffffff;
      QString::~QString((QString *)&local_20);
      if ((**(int **)this != 1) && (**(int **)this != 0)) {
        FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar2 = QListData::at(this,param_2);
      (**(code **)(**(int **)((int)*ppvVar2 + 4) + 0x2c))(0);
      if ((**(int **)this != 1) && (**(int **)this != 0)) {
        FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar2 = QListData::at(this,param_2);
      (**(code **)(**(int **)((int)*ppvVar2 + 0xc) + 0x2c))(0);
      if ((**(int **)this != 1) && (**(int **)this != 0)) {
        FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar2 = QListData::at(this,param_2);
      (**(code **)(**(int **)((int)*ppvVar2 + 0x10) + 0x2c))(0);
      if ((**(int **)this != 1) && (**(int **)this != 0)) {
        FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar2 = QListData::at(this,param_2);
      (**(code **)(**(int **)((int)*ppvVar2 + 0x20) + 0x2c))(0);
      if ((**(int **)this != 1) && (**(int **)this != 0)) {
        FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar2 = QListData::at(this,param_2);
      (**(code **)(**(int **)((int)*ppvVar2 + 0x28) + 0x2c))(0);
      if ((**(int **)this != 1) && (**(int **)this != 0)) {
        FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar2 = QListData::at(this,param_2);
      (**(code **)(**(int **)((int)*ppvVar2 + 0x2c) + 0x2c))(0);
    }
    else {
      if ((iVar4 != 1) && (iVar4 != 0)) {
        FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar2 = QListData::at(this,param_2);
      pQVar7 = *(QLabel **)((int)*ppvVar2 + 8);
      local_20 = QString::fromAscii_helper("CC",2);
      local_8 = 4;
      QLabel::setText(pQVar7,(QString *)&local_20);
      local_8 = 0xffffffff;
      QString::~QString((QString *)&local_20);
      if ((**(int **)this != 1) && (**(int **)this != 0)) {
        FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar2 = QListData::at(this,param_2);
      pQVar7 = *(QLabel **)((int)*ppvVar2 + 0xc);
      local_1c = QString::fromAscii_helper("Value1",6);
      local_8 = 5;
      QLabel::setText(pQVar7,(QString *)&local_1c);
      local_8 = 0xffffffff;
      QString::~QString((QString *)&local_1c);
      if ((**(int **)this != 1) && (**(int **)this != 0)) {
        FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar2 = QListData::at(this,param_2);
      pQVar7 = *(QLabel **)((int)*ppvVar2 + 0x10);
      local_24 = QString::fromAscii_helper("Value2",6);
      local_8 = 6;
      QLabel::setText(pQVar7,(QString *)&local_24);
      local_8 = 0xffffffff;
      QString::~QString((QString *)&local_24);
    }
    if ((**(int **)this != 1) && (**(int **)this != 0)) {
      FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
    }
    ppvVar2 = QListData::at(this,param_2);
    uVar9 = 1;
  }
  (**(code **)(**(int **)((int)*ppvVar2 + 0x18) + 0x2c))(uVar9);
  ExceptionList = local_10;
  return;
}


