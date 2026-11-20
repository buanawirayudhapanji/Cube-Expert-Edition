
void __thiscall
FUN_004fa290(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  char cVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0053191e;
  local_10 = ExceptionList;
  uVar2 = DAT_00759b24 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  if (*(char *)(param_1 + 0x9c) != '\0') {
    cVar1 = FUN_00506590(param_2,param_3,param_4,param_5,0);
    if (cVar1 == '\0') {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7710,(char *)&param_5,"Write data failed !",0);
      local_8 = 0;
      FUN_00486bb0(&param_5,uVar2,param_1);
      QString::~QString((QString *)&param_5);
    }
  }
  ExceptionList = local_10;
  return;
}


