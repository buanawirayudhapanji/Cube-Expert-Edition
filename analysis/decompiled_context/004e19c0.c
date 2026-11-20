
void __thiscall FUN_004e19c0(int param_1,QString param_2)

{
  char cVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0051b48e;
  local_10 = ExceptionList;
  uVar2 = DAT_00759b24 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  *(char *)(param_1 + 0x47) = (char)param_2 + -1;
  cVar1 = FUN_00506590(4,3,(char *)(param_1 + 0x47),1,param_1);
  if (cVar1 == '\0') {
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7e58,(char *)&param_2,"Write data failed !",0);
    local_8 = 0;
    FUN_00486bb0(&param_2,uVar2,param_1);
    QString::~QString(&param_2);
  }
  ExceptionList = local_10;
  return;
}


