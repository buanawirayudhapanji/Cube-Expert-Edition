
void FUN_004d3b80(int param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  char cVar3;
  QString local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar2 = param_2;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0052652e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 == 0) {
    if (param_2 != 0) {
      FUN_00519359(param_2,0xc,DAT_00759b24 ^ (uint)(local_14 + 0x10));
    }
  }
  else if (param_1 == 1) {
    uVar1 = **(undefined4 **)(param_4 + 4);
    QObject::blockSignals(*(QObject **)(*(int *)(param_2 + 8) + 500),true);
    *(char *)(*(int *)(iVar2 + 8) + 0x2d3) = (char)uVar1;
    cVar3 = FUN_00506590(5,0x2b,*(int *)(iVar2 + 8) + 0x2d3,1,*(int *)(iVar2 + 8));
    if (cVar3 == '\0') {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7250,(char *)local_14,"Write data failed !",0);
      local_8 = 0;
      FUN_00486bb0(local_14);
      local_8 = 0xffffffff;
      QString::~QString(local_14);
    }
    param_1 = CONCAT13(3,(undefined3)param_1);
    FUN_00506590(5,0xa0000000,(int)&param_1 + 3,1,0);
    QObject::blockSignals(*(QObject **)(*(int *)(iVar2 + 8) + 500),false);
    ExceptionList = local_10;
    return;
  }
  ExceptionList = local_10;
  return;
}


