
void __thiscall
FUN_0049dc20(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5
            )

{
  char cVar1;
  QString *this;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005271d7;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_5 == 0) {
    FUN_00506590(5,param_2,param_3,param_4,param_1);
    ExceptionList = local_10;
    return;
  }
  cVar1 = FUN_00506590(5,param_2,param_3,param_4,param_1);
  if (cVar1 == '\0') {
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f8948,(char *)&param_3,"Write data failed !",0);
    local_8 = 1;
    FUN_00486bb0(&param_3);
    this = (QString *)&param_3;
  }
  else {
    FUN_004994e0();
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f8948,(char *)&param_4,"Successful!",0);
    local_8 = 0;
    FUN_00486bb0(&param_4);
    this = (QString *)&param_4;
  }
  QString::~QString(this);
  ExceptionList = local_10;
  return;
}


