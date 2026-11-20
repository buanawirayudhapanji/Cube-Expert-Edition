
void __fastcall FUN_004d2690(int *param_1)

{
  char cVar1;
  uint uVar2;
  QString local_18 [7];
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00539e2e;
  local_10 = ExceptionList;
  uVar2 = DAT_00759b24 ^ (uint)(local_18 + 0x14);
  ExceptionList = &local_10;
  *(undefined1 *)(*param_1 + 0x1ea8) = 0;
  *(undefined1 *)(*param_1 + 0x1ea9) = 0;
  *(undefined1 *)(*param_1 + 0x1eaa) = 0;
  *(undefined1 *)(*param_1 + 0x1eab) = 0;
  *(undefined1 *)(*param_1 + 0x1eac) = 0;
  *(undefined1 *)(*param_1 + 0x1ead) = 0;
  *(undefined1 *)(*param_1 + 0x1eae) = 0;
  *(undefined1 *)(*param_1 + 0x1eaf) = 0;
  *(undefined1 *)(*param_1 + 0x1eb0) = 0;
  *(undefined2 *)(*param_1 + 0x1ece) = 0x1e;
  *(undefined2 *)(*param_1 + 0x1ec8) = 0x50;
  *(undefined1 *)(*param_1 + 0x1ebb) = 0;
  *(undefined2 *)(*param_1 + 0x1ebe) = 100;
  *(undefined1 *)(*param_1 + 0x1eb6) = 0;
  *(undefined1 *)(*param_1 + 0x1eb1) = 5;
  *(undefined2 *)(*param_1 + 0x1ec0) = 400;
  *(undefined1 *)(*param_1 + 0x1eb7) = 0;
  *(undefined1 *)(*param_1 + 0x1eb2) = 5;
  *(undefined2 *)(*param_1 + 0x1ec2) = 1000;
  *(undefined1 *)(*param_1 + 0x1eb8) = 0;
  *(undefined1 *)(*param_1 + 0x1eb3) = 5;
  *(undefined2 *)(*param_1 + 0x1ec4) = 2000;
  *(undefined1 *)(*param_1 + 0x1eb9) = 0;
  *(undefined1 *)(*param_1 + 0x1eb4) = 5;
  *(undefined2 *)(*param_1 + 0x1ec6) = 4000;
  *(undefined1 *)(*param_1 + 0x1eba) = 0;
  *(undefined1 *)(*param_1 + 0x1eb5) = 5;
  *(undefined2 *)(*param_1 + 0x1eca) = 12000;
  *(undefined1 *)(*param_1 + 0x1ebc) = 0;
  *(undefined2 *)(*param_1 + 0x1ecc) = 18000;
  cVar1 = FUN_00506590(5,0x1c00,*param_1 + 0x1ea8,0x28,*param_1);
  if (cVar1 == '\0') {
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7250,(char *)local_18,"Write data failed !",0);
    local_8 = 0;
    FUN_00486bb0(local_18,uVar2);
    local_8 = 0xffffffff;
    QString::~QString(local_18);
  }
  local_11 = 2;
  FUN_00506590(5,0xa0000000,&local_11,1,0);
  FUN_004d91a0();
  ExceptionList = local_10;
  return;
}


