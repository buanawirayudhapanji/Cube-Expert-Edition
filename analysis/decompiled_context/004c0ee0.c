
void __fastcall FUN_004c0ee0(int param_1)

{
  QLabel *this;
  code *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  QString *pQVar5;
  undefined4 uVar6;
  QString local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005265be;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar3 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x864));
  iVar4 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x860));
  *(char *)(iVar4 * 0xa1 + 0x999 + param_1) = (char)iVar3;
  this = *(QLabel **)(param_1 + 0x8e0);
  iVar3 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x860));
  pQVar5 = (QString *)
           QListData::at((QListData *)(param_1 + 0x10dc),
                         (uint)*(byte *)(iVar3 * 0xa1 + 0x999 + param_1));
  QLabel::setText(this,pQVar5);
  pcVar1 = *(code **)(**(int **)(param_1 + 0x8f4) + 0x2c);
  iVar3 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x864));
  if (iVar3 != 0) {
    iVar3 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x864));
    if (iVar3 != 3) {
      uVar6 = 1;
      goto LAB_004c0f9a;
    }
  }
  uVar6 = 0;
LAB_004c0f9a:
  (*pcVar1)(uVar6);
  iVar3 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x860));
  iVar4 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x860));
  cVar2 = FUN_00506590(4,iVar4 * 0xa1 + 0xd,iVar3 * 0xa1 + 0x999 + param_1,1,param_1);
  if (cVar2 == '\0') {
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f83b0,(char *)local_14,"Write data failed !",0);
    local_8 = 0;
    FUN_00486bb0(local_14);
    QString::~QString(local_14);
  }
  ExceptionList = local_10;
  return;
}


