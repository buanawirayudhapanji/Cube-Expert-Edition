
void __fastcall FUN_004ad7b0(int param_1)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  QString *this;
  int iVar5;
  int iVar6;
  size_t _Size;
  QString local_18 [4];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00530787;
  local_10 = ExceptionList;
  uVar3 = DAT_00759b24 ^ (uint)(local_18 + 0x14);
  ExceptionList = &local_10;
  local_14 = param_1;
  QListWidget::clear(*(QListWidget **)(param_1 + 0x90c));
  _Size = 0x50;
  iVar6 = 0;
  if (*(char *)(param_1 + 0xa38) == '\x03') {
    bVar1 = *(byte *)(param_1 + 0x6690);
    iVar4 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x864));
    memset((void *)(iVar4 * 0x1a1 + (uint)bVar1 * 0x684 + 0xae6 + param_1),iVar6,_Size);
    bVar1 = *(byte *)(param_1 + 0x6690);
    iVar6 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x864));
    iVar5 = local_14 + (uint)*(byte *)(local_14 + 0x6690) * 0x684;
    iVar4 = QButtonGroup::checkedId(*(QButtonGroup **)(local_14 + 0x864));
    cVar2 = FUN_00506590(4,iVar4 * 0x1a1 + (iVar5 - local_14) + 0xae,
                         param_1 + (uint)bVar1 * 0x684 + 0xae6 + iVar6 * 0x1a1,0x50,local_14);
    if (cVar2 != '\0') {
      ExceptionList = local_10;
      return;
    }
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f6f40,(char *)&local_14,"Write data failed !",0);
    local_8 = 0;
    FUN_00486bb0(&local_14);
    this = (QString *)&local_14;
  }
  else {
    memset((void *)((*(int *)(param_1 + 0x68cc) + (uint)*(byte *)(param_1 + 0x6695) * 4) * 0x1a6 +
                    0x3f53 + param_1),0,0x50);
    iVar6 = (*(int *)(param_1 + 0x68cc) + (uint)*(byte *)(param_1 + 0x6695) * 4) * 0x1a6;
    cVar2 = FUN_00506590(4,iVar6 + 0x351b,param_1 + 0x3f53 + iVar6,0x50,param_1);
    if (cVar2 != '\0') {
      ExceptionList = local_10;
      return;
    }
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f6f40,(char *)local_18,"Write data failed !",0);
    local_8 = 1;
    FUN_00486bb0(local_18,uVar3);
    this = local_18;
  }
  QString::~QString(this);
  ExceptionList = local_10;
  return;
}


