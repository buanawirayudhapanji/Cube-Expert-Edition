
void __fastcall FUN_004ae2e0(int param_1)

{
  QListData *this;
  byte bVar1;
  byte bVar2;
  QLabel *pQVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  QString *pQVar8;
  undefined4 uVar9;
  QString local_18 [4];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00530847;
  local_10 = ExceptionList;
  uVar5 = DAT_00759b24 ^ (uint)(local_18 + 0x14);
  ExceptionList = &local_10;
  local_14 = param_1;
  if (*(char *)(param_1 + 0xa38) == '\x03') {
    iVar6 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x868));
    bVar1 = *(byte *)(param_1 + 0x6690);
    iVar7 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x864));
    *(char *)(iVar7 * 0x1a1 + 0xa95 + (uint)bVar1 * 0x684 + param_1) = (char)iVar6;
    bVar1 = *(byte *)(param_1 + 0x6690);
    pQVar3 = *(QLabel **)(param_1 + 0x8d4);
    iVar6 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x864));
    pQVar8 = (QString *)
             QListData::at((QListData *)(param_1 + 0x66a4),
                           (uint)*(byte *)(iVar6 * 0x1a1 + 0xa95 + (uint)bVar1 * 0x684 + param_1));
    QLabel::setText(pQVar3,pQVar8);
    bVar1 = *(byte *)(param_1 + 0x6690);
    iVar6 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x864));
    if (((*(char *)(iVar6 * 0x1a1 + 0xa95 + (uint)bVar1 * 0x684 + param_1) == '\x01') ||
        (bVar1 = *(byte *)(param_1 + 0x6690),
        iVar6 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x864)),
        *(char *)(iVar6 * 0x1a1 + 0xa95 + (uint)bVar1 * 0x684 + param_1) == '\x02')) ||
       (bVar1 = *(byte *)(param_1 + 0x6690),
       iVar6 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x864)),
       *(char *)(iVar6 * 0x1a1 + 0xa95 + (uint)bVar1 * 0x684 + param_1) == '\x04')) {
      uVar9 = 1;
    }
    else {
      uVar9 = 0;
    }
    (**(code **)(**(int **)(param_1 + 0x904) + 0x2c))(uVar9);
    bVar1 = *(byte *)(param_1 + 0x6690);
    iVar6 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x864));
    bVar2 = *(byte *)(param_1 + 0x6690);
    iVar7 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x864));
    cVar4 = FUN_00506590(4,iVar7 * 0x1a1 + (uint)bVar2 * 0x684 + 0x5d,
                         (uint)bVar1 * 0x684 + 0xa95 + param_1 + iVar6 * 0x1a1,1,param_1);
    if (cVar4 != '\0') {
      ExceptionList = local_10;
      return;
    }
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f6f40,(char *)&local_14,"Write data failed !",0);
    local_8 = 0;
    FUN_00486bb0(&local_14);
    pQVar8 = (QString *)&local_14;
  }
  else {
    iVar6 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x868));
    *(char *)((*(int *)(param_1 + 0x68cc) + (uint)*(byte *)(param_1 + 0x6695) * 4) * 0x1a6 + 0x3f02
             + param_1) = (char)iVar6;
    pQVar3 = *(QLabel **)(param_1 + 0x8d4);
    this = (QListData *)(local_14 + 0x66a4);
    iVar6 = QButtonGroup::checkedId(*(QButtonGroup **)(local_14 + 0x868));
    pQVar8 = (QString *)QListData::at(this,iVar6);
    QLabel::setText(pQVar3,pQVar8);
    iVar6 = local_14;
    cVar4 = *(char *)((*(int *)(local_14 + 0x68cc) + (uint)*(byte *)(local_14 + 0x6695) * 4) * 0x1a6
                      + 0x3f02 + local_14);
    if (((cVar4 == '\x01') || (cVar4 == '\x02')) || (cVar4 == '\x04')) {
      uVar9 = 1;
    }
    else {
      uVar9 = 0;
    }
    (**(code **)(**(int **)(local_14 + 0x904) + 0x2c))(uVar9,uVar5);
    iVar7 = (*(int *)(iVar6 + 0x68cc) + (uint)*(byte *)(iVar6 + 0x6695) * 4) * 0x1a6;
    cVar4 = FUN_00506590(4,iVar7 + 0x34ca,iVar6 + 0x3f02 + iVar7,1,iVar6);
    if (cVar4 != '\0') {
      ExceptionList = local_10;
      return;
    }
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f6f40,(char *)local_18,"Write data failed !",0);
    local_8 = 1;
    FUN_00486bb0(local_18);
    pQVar8 = local_18;
  }
  QString::~QString(pQVar8);
  ExceptionList = local_10;
  return;
}


