
undefined4 __thiscall FUN_00505320(int param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  QString *this;
  uint uVar5;
  int *local_28;
  uint local_1c;
  QString local_18 [8];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054d111;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_005100e0(DAT_00759b24 ^ (uint)(local_18 + 0x14));
  local_8 = 0;
  cVar3 = FUN_005102f0(param_2);
  uVar5 = param_4;
  if (cVar3 == '\0') {
    QString::QString((QString *)&param_3,local_18);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00486bb0(&param_3);
    QString::~QString((QString *)&param_3);
    FUN_00510180();
    ExceptionList = local_10;
    return 0;
  }
  if (local_1c < param_4) {
    FUN_00486c20("Space not enough !");
    FUN_00510180();
    ExceptionList = local_10;
    return 0;
  }
  local_8 = 0xffffffff;
  param_4 = local_28[1];
  uVar1 = local_28[2];
  param_2 = *local_28;
  FUN_00510180();
  iVar2 = param_4;
  if ((param_2 == 1) || (uVar5 <= uVar1)) {
LAB_00505412:
    iVar4 = FUN_005066c0(param_2,iVar2,param_3,uVar5,param_1);
  }
  else {
    iVar4 = FUN_005066c0(param_2,uVar1 + param_4,param_3 + uVar1,uVar5 - uVar1,param_1);
    if (iVar4 == 1) {
      uVar5 = uVar1;
      goto LAB_00505412;
    }
  }
  switch(iVar4) {
  case 0:
    QProgressBar::setValue(*(QProgressBar **)(param_1 + 0x34),100);
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7458,(char *)&param_3,"Write data failed !",0);
    local_8 = 2;
    FUN_00486bb0(&param_3);
    this = (QString *)&param_3;
    break;
  case 1:
    QProgressBar::setValue(*(QProgressBar **)(param_1 + 0x34),100);
    ExceptionList = local_10;
    return 1;
  default:
    goto switchD_0050542a_caseD_2;
  case 3:
    QProgressBar::setValue(*(QProgressBar **)(param_1 + 0x34),100);
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7458,(char *)&param_3,"Verify data failed",0);
    local_8 = 3;
    FUN_00486bb0(&param_3);
    this = (QString *)&param_3;
    break;
  case 4:
    QProgressBar::setValue(*(QProgressBar **)(param_1 + 0x34),100);
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7458,(char *)&param_2,"Write data timeout !",0);
    local_8 = 4;
    FUN_00486bb0(&param_2);
    this = (QString *)&param_2;
  }
  QString::~QString(this);
switchD_0050542a_caseD_2:
  ExceptionList = local_10;
  return 0;
}


