
void __fastcall FUN_004c0bb0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  size_t _Size;
  QString local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0053087e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar2 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x860));
  if ((*(char *)(iVar2 * 0xa1 + 0x9ec + param_1) == '\x04') &&
     (iVar2 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x860)),
     *(char *)(iVar2 * 0xa1 + 0x9ea + param_1) != '\0')) {
    ExceptionList = local_10;
    return;
  }
  QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x860));
  QListWidget::clear(*(QListWidget **)(param_1 + 0x8fc));
  _Size = 0x50;
  iVar3 = 0;
  iVar2 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x860));
  memset((void *)(iVar2 * 0xa1 + 0x9ea + param_1),iVar3,_Size);
  iVar2 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x860));
  iVar3 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x860));
  cVar1 = FUN_00506590(4,iVar3 * 0xa1 + 0x5e,iVar2 * 0xa1 + 0x9ea + param_1,0x50,param_1);
  if (cVar1 == '\0') {
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f83b0,(char *)local_14,"Write data failed !",0);
    local_8 = 0;
    FUN_00486bb0(local_14);
    QString::~QString(local_14);
  }
  ExceptionList = local_10;
  return;
}


