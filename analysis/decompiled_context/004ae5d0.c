
void __fastcall FUN_004ae5d0(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  QString local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005307be;
  local_10 = ExceptionList;
  uVar2 = DAT_00759b24 ^ (uint)(local_14 + 0x10);
  ExceptionList = &local_10;
  iVar3 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x858));
  *(undefined1 *)(param_1 + 0xa39) = (char)iVar3;
  cVar1 = FUN_00506590(4,1,(undefined1 *)(param_1 + 0xa39),1,param_1);
  if (cVar1 == '\0') {
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f6f40,(char *)local_14,"Write data failed !",0);
    local_8 = 0;
    FUN_00486bb0(local_14,uVar2);
    QString::~QString(local_14);
  }
  ExceptionList = local_10;
  return;
}


