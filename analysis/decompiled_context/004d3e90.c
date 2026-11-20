
void FUN_004d3e90(int param_1,int param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0052c59e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 == 0) {
    if (param_2 != 0) {
      FUN_00519359(param_2,0xc,DAT_00759b24 ^ (int)register0x00000010 - 4U);
    }
  }
  else if (param_1 == 1) {
    *(undefined4 *)(*(int *)(param_2 + 8) + 0x2120) = **(undefined4 **)(param_4 + 4);
    piVar2 = (int *)(*(int *)(param_2 + 8) + 0x2120);
    cVar1 = FUN_00506590(4,*piVar2 + -0x20000000,piVar2,1,0);
    if (cVar1 == '\0') {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7250,(char *)&param_1,"Data write failure!",0);
      local_8 = 0;
      FUN_00486bb0(&param_1);
      local_8 = 0xffffffff;
      QString::~QString((QString *)&param_1);
    }
    FUN_004872d0(200);
    FUN_004d8cc0();
    ExceptionList = local_10;
    return;
  }
  ExceptionList = local_10;
  return;
}


