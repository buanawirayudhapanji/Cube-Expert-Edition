
void FUN_004d40a0(int param_1,int param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  QString local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0051d2de;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 == 0) {
    if (param_2 != 0) {
      FUN_00519359(param_2,0xc,DAT_00759b24 ^ (uint)(local_14 + 0x10));
    }
  }
  else if (param_1 == 1) {
    *(undefined1 *)(*(int *)(param_2 + 8) + 0x2b9) = **(undefined1 **)(param_4 + 4);
    cVar1 = FUN_00506590(5,0x11,*(int *)(param_2 + 8) + 0x2b9,1,*(int *)(param_2 + 8));
    if (cVar1 == '\0') {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7250,(char *)local_14,"Write data failed !",0);
      local_8 = 0;
      FUN_00486bb0(local_14);
      local_8 = 0xffffffff;
      QString::~QString(local_14);
    }
    param_1 = CONCAT13(1,(undefined3)param_1);
    FUN_00506590(5,0xa0000000,(int)&param_1 + 3,1,0);
    ExceptionList = local_10;
    return;
  }
  ExceptionList = local_10;
  return;
}


