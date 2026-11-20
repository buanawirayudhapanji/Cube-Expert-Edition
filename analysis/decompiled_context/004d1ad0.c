
undefined4 __fastcall FUN_004d1ad0(int *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  QString local_18 [4];
  QString local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00539ce7;
  local_10 = ExceptionList;
  uVar2 = DAT_00759b24 ^ (uint)(local_14 + 0x10);
  ExceptionList = &local_10;
  iVar3 = 0x70000000;
  do {
    cVar1 = FUN_005063a0(5,iVar3);
    if (cVar1 == '\0') {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7250,(char *)local_18,"Failed to erase data!",0);
      local_8 = 0;
      FUN_00486bb0(local_18,uVar2);
      QString::~QString(local_18);
      free(*(void **)param_1[1]);
      ExceptionList = local_10;
      return 0;
    }
    iVar3 = iVar3 + 0x1000;
  } while (iVar3 < 0x70040000);
  (**(code **)(**(int **)(*param_1 + 0x21c) + 0x2c))(1);
  cVar1 = FUN_00506590(5,0x70000000,*(undefined4 *)param_1[1],0x40000,*param_1);
  if (cVar1 == '\0') {
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7250,(char *)local_14,"Failed to write data!",0);
    local_8 = 1;
    FUN_00486bb0(local_14);
    local_8 = 0xffffffff;
    QString::~QString(local_14);
    free(*(void **)param_1[1]);
    (**(code **)(**(int **)(*param_1 + 0x21c) + 0x2c))(0);
    ExceptionList = local_10;
    return 0;
  }
  free(*(void **)param_1[1]);
  iVar3 = *param_1;
  FUN_005063f0(5,0,iVar3 + 0x2a8,0x1c28,0);
  FUN_0050cd50(*(char *)(iVar3 + 0x2b9) != '\0');
  FUN_0050cd50(*(char *)(iVar3 + 0x2ba) != '\0');
  FUN_004d8d80();
  FUN_004d41e0();
  (**(code **)(**(int **)(*param_1 + 0x21c) + 0x2c))(0);
  ExceptionList = local_10;
  return 1;
}


