
void __fastcall FUN_004bdd50(QObject *param_1)

{
  QObject QVar1;
  char cVar2;
  uint uVar3;
  QObject *this;
  undefined4 uVar4;
  QObject *pQVar5;
  QString local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005307be;
  local_10 = ExceptionList;
  uVar3 = DAT_00759b24 ^ (uint)(local_14 + 0x10);
  ExceptionList = &local_10;
  this = QObject::sender(param_1);
  if (this == *(QObject **)(param_1 + 0x980)) {
    QVar1 = (QObject)QAbstractButton::isChecked((QAbstractButton *)this);
    param_1[0xa3b] = QVar1;
    cVar2 = FUN_00506590(4,3,param_1 + 0xa3b,1,param_1);
    if (cVar2 == '\0') {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f6f40,(char *)local_14,"Write data failed !",0);
      local_8 = 0;
      FUN_00486bb0(local_14,uVar3);
      QString::~QString(local_14);
      ExceptionList = local_10;
      return;
    }
  }
  else {
    if (this == *(QObject **)(param_1 + 0x98c)) {
      pQVar5 = param_1 + 0xa3d;
      QVar1 = (QObject)QAbstractButton::isChecked((QAbstractButton *)this);
      uVar4 = 5;
    }
    else if (this == *(QObject **)(param_1 + 0x994)) {
      pQVar5 = param_1 + 0xa3f;
      QVar1 = (QObject)QAbstractButton::isChecked((QAbstractButton *)this);
      uVar4 = 7;
    }
    else if (this == *(QObject **)(param_1 + 0x99c)) {
      pQVar5 = param_1 + 0xa41;
      QVar1 = (QObject)QAbstractButton::isChecked((QAbstractButton *)this);
      uVar4 = 9;
    }
    else if (this == *(QObject **)(param_1 + 0xa04)) {
      pQVar5 = param_1 + 0x6692;
      QVar1 = (QObject)QAbstractButton::isChecked((QAbstractButton *)this);
      uVar4 = 0x5c5a;
    }
    else if (this == *(QObject **)(param_1 + 0xa10)) {
      pQVar5 = param_1 + 0x6693;
      QVar1 = (QObject)QAbstractButton::isChecked((QAbstractButton *)this);
      uVar4 = 0x5c5b;
    }
    else {
      if (this != *(QObject **)(param_1 + 0xa34)) {
        ExceptionList = local_10;
        return;
      }
      pQVar5 = param_1 + 0x6694;
      QVar1 = (QObject)QAbstractButton::isChecked((QAbstractButton *)this);
      uVar4 = 0x5c5c;
    }
    *pQVar5 = QVar1;
    FUN_004b6c90(uVar4,pQVar5,1,param_1);
  }
  ExceptionList = local_10;
  return;
}


