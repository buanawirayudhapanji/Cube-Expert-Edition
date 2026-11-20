
void __fastcall FUN_004c10d0(int param_1)

{
  char *pcVar1;
  QLabel *this;
  code *pcVar2;
  char cVar3;
  uint uVar4;
  QString *pQVar5;
  int iVar6;
  undefined4 uVar7;
  QString local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0053087e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar4 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x85c));
  this = *(QLabel **)(param_1 + 0x8a0);
  *(char *)(param_1 + 0x98c) = (char)uVar4;
  pQVar5 = (QString *)QListData::at((QListData *)(param_1 + 0x10d4),uVar4 & 0xff);
  QLabel::setText(this,pQVar5);
  pcVar1 = (char *)(param_1 + 0x98c);
  cVar3 = FUN_00506590(4,0,pcVar1,1,param_1);
  if (cVar3 == '\0') {
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f83b0,(char *)local_14,"Write data failed !",0);
    local_8 = 0;
    FUN_00486bb0(local_14);
    local_8 = 0xffffffff;
    QString::~QString(local_14);
  }
  (**(code **)(**(int **)(param_1 + 0x904) + 0x2c))(*pcVar1 != '\t');
  (**(code **)(**(int **)(param_1 + 0x908) + 0x2c))(*pcVar1 == '\a');
  (**(code **)(**(int **)(param_1 + 0x954) + 0x2c))(*pcVar1 == '\n');
  pcVar2 = *(code **)(**(int **)(param_1 + 0x8f4) + 0x2c);
  iVar6 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x864));
  if (iVar6 != 0) {
    iVar6 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x864));
    if (iVar6 != 3) {
      uVar7 = 1;
      goto LAB_004c11f1;
    }
  }
  uVar7 = 0;
LAB_004c11f1:
  (*pcVar2)(uVar7);
  ExceptionList = local_10;
  return;
}


