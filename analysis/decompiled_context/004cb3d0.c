
void __fastcall FUN_004cb3d0(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  QString *this;
  QString local_18 [4];
  QString local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005378b7;
  local_10 = ExceptionList;
  uVar2 = DAT_00759b24 ^ (uint)(local_14 + 0x10);
  ExceptionList = &local_10;
  cVar1 = FUN_00506590(5,0,&DAT_00589b98,100,param_1);
  if (cVar1 == '\0') {
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f8264,(char *)local_18,"Write data failed !",0);
    local_8 = 1;
    FUN_00486bb0(local_18,uVar2);
    this = local_18;
  }
  else {
    FUN_004cb8b0();
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f8264,(char *)local_14,"Successful!",0);
    local_8 = 0;
    FUN_00486bb0(local_14,uVar2);
    this = local_14;
  }
  QString::~QString(this);
  ExceptionList = local_10;
  return;
}


