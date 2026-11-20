
void FUN_00483f60(int param_1)

{
  uint uVar1;
  undefined4 extraout_var;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0051b48e;
  local_10 = ExceptionList;
  uVar1 = DAT_00759b24 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  if (param_1 != 0) {
    QMetaObject::tr((QMetaObject *)&DAT_007598e8,(char *)&param_1,"Device Disconnection !",0);
    local_8 = 0;
    FUN_00486bb0(&param_1,uVar1,extraout_var);
    QString::~QString((QString *)&param_1);
  }
  ExceptionList = local_10;
  return;
}


