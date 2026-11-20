
void __fastcall FUN_004c0cd0(int param_1)

{
  char *_Dst;
  char cVar1;
  uint uVar2;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0052652e;
  local_10 = ExceptionList;
  uVar2 = DAT_00759b24 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  _Dst = (char *)(param_1 + 0xc1e);
  if ((*(char *)(param_1 + 0xc20) != '\x04') || (*_Dst == '\0')) {
    local_14 = param_1;
    QListWidget::clear(*(QListWidget **)(param_1 + 0x988));
    memset(_Dst,0,0x50);
    cVar1 = FUN_00506590(4,0x292,_Dst,0x50,param_1);
    if (cVar1 == '\0') {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f83b0,(char *)&local_14,"Write data failed !",0);
      local_8 = 0;
      FUN_00486bb0(&local_14,uVar2);
      QString::~QString((QString *)&local_14);
    }
  }
  ExceptionList = local_10;
  return;
}


