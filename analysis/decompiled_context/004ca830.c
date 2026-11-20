
void __fastcall FUN_004ca830(QObject *param_1)

{
  QObject QVar1;
  char cVar2;
  uint uVar3;
  QObject *this;
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
  if (this == *(QObject **)(param_1 + 0x934)) {
    QVar1 = (QObject)QAbstractButton::isChecked((QAbstractButton *)this);
    param_1[0x98f] = QVar1;
    cVar2 = FUN_00506590(4,3,param_1 + 0x98f,1,param_1);
    if (cVar2 == '\0') {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f83b0,(char *)local_14,"Write data failed !",0);
      local_8 = 0;
      FUN_00486bb0(local_14,uVar3);
      QString::~QString(local_14);
      ExceptionList = local_10;
      return;
    }
  }
  else if (this == *(QObject **)(param_1 + 0x940)) {
    QVar1 = (QObject)QAbstractButton::isChecked((QAbstractButton *)this);
    param_1[0x991] = QVar1;
    FUN_004c6750(5,param_1 + 0x991,1,param_1);
  }
  ExceptionList = local_10;
  return;
}


