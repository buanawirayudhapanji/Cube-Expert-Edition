
void FUN_004f49c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  uint uVar2;
  undefined4 extraout_var;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0053191e;
  local_10 = ExceptionList;
  uVar2 = DAT_00759b24 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  cVar1 = FUN_00506590(param_1,param_2,param_3,param_4,0);
  if (cVar1 == '\0') {
    uVar3 = extraout_var;
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7c3c,(char *)&param_4,"Write data failed !",0);
    local_8 = 0;
    FUN_00486bb0(&param_4,uVar2,uVar3);
    QString::~QString((QString *)&param_4);
  }
  ExceptionList = local_10;
  return;
}


