
void __fastcall FUN_004ae750(int param_1)

{
  char *pcVar1;
  byte bVar2;
  QLabel *pQVar3;
  char cVar4;
  uint uVar5;
  QString *pQVar6;
  int iVar7;
  QAbstractButton *this;
  undefined4 uVar8;
  QString local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0053087e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pcVar1 = (char *)(param_1 + 0xa38);
  uVar5 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x860));
  pQVar3 = *(QLabel **)(param_1 + 0x8a0);
  *pcVar1 = (char)uVar5;
  pQVar6 = (QString *)QListData::at((QListData *)(param_1 + 0x669c),uVar5 & 0xff);
  QLabel::setText(pQVar3,pQVar6);
  cVar4 = FUN_00506590(4,0,pcVar1,1,param_1);
  if (cVar4 == '\0') {
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f6f40,(char *)local_14,"Write data failed !",0);
    local_8 = 0;
    FUN_00486bb0(local_14);
    local_8 = 0xffffffff;
    QString::~QString(local_14);
  }
  cVar4 = *pcVar1;
  uVar5 = CONCAT31((int3)((uint)**(int **)(param_1 + 0x950) >> 8),cVar4);
  if ((cVar4 == '\x03') ||
     ((cVar4 == '\v' &&
      (uVar5 = (*(int *)(param_1 + 0x68cc) + (uint)*(byte *)(param_1 + 0x6695) * 4) * 0x1a6,
      *(char *)(uVar5 + 0x3efd + param_1) == '\0')))) {
    uVar5 = uVar5 & 0xffffff00;
  }
  else {
    uVar5 = CONCAT31((int3)(uVar5 >> 8),1);
  }
  (**(code **)(**(int **)(param_1 + 0x950) + 0x2c))(uVar5);
  (**(code **)(**(int **)(param_1 + 0x954) + 0x2c))(*pcVar1 == '\x02');
  (**(code **)(**(int **)(param_1 + 0x9b0) + 0x2c))(*pcVar1 == '\n');
  (**(code **)(**(int **)(param_1 + 0xa1c) + 0x2c))(*pcVar1 == '\v');
  (**(code **)(**(int **)(param_1 + 0xa34) + 0x2c))(*pcVar1 == '\0');
  if (*pcVar1 != '\x03') {
    if (*pcVar1 == '\v') {
      FUN_004bd9b0();
    }
    else {
      (**(code **)(**(int **)(param_1 + 0x950) + 0x2c))(1);
    }
    goto LAB_004aea3e;
  }
  bVar2 = *(byte *)(param_1 + 0x6690);
  iVar7 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x864));
  if (*(char *)(iVar7 * 0x1a1 + 0xa95 + (uint)bVar2 * 0x684 + param_1) == '\x01') {
LAB_004ae91c:
    uVar8 = 1;
  }
  else {
    bVar2 = *(byte *)(param_1 + 0x6690);
    iVar7 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x864));
    if (*(char *)(iVar7 * 0x1a1 + 0xa95 + (uint)bVar2 * 0x684 + param_1) == '\x02')
    goto LAB_004ae91c;
    bVar2 = *(byte *)(param_1 + 0x6690);
    iVar7 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x864));
    if (*(char *)(iVar7 * 0x1a1 + 0xa95 + (uint)bVar2 * 0x684 + param_1) == '\x04')
    goto LAB_004ae91c;
    uVar8 = 0;
  }
  (**(code **)(**(int **)(param_1 + 0x904) + 0x2c))(uVar8);
  (**(code **)(**(int **)(param_1 + 0x940) + 0x2c))(0);
  (**(code **)(**(int **)(param_1 + 0x938) + 0x2c))(0);
  (**(code **)(**(int **)(param_1 + 0x918) + 0x2c))(0);
  (**(code **)(**(int **)(param_1 + 0x914) + 0x2c))(1);
  (**(code **)(**(int **)(param_1 + 0x8bc) + 0x2c))(1);
  (**(code **)(**(int **)(param_1 + 0x8c0) + 0x2c))(1);
  (**(code **)(**(int **)(param_1 + 0x8c4) + 0x2c))(1);
  (**(code **)(**(int **)(param_1 + 0x8c8) + 0x2c))(1);
  (**(code **)(**(int **)(param_1 + 0x950) + 0x2c))(0);
  (**(code **)(**(int **)(param_1 + 0x8f4) + 0x2c))(1);
  (**(code **)(**(int **)(param_1 + 0x904) + 0x2c))(1);
  (**(code **)(**(int **)(param_1 + 0x8cc) + 0x2c))(1);
  this = QButtonGroup::button
                   (*(QButtonGroup **)(param_1 + 0x868),
                    (uint)*(byte *)((uint)*(byte *)(param_1 + 0x6690) * 0x684 + 0xa95 + param_1));
  QAbstractButton::setChecked(this,true);
  pQVar3 = *(QLabel **)(param_1 + 0x8d4);
  pQVar6 = (QString *)
           QListData::at((QListData *)(param_1 + 0x66a4),
                         (uint)*(byte *)((uint)*(byte *)(param_1 + 0x6690) * 0x684 + 0xa95 + param_1
                                        ));
  QLabel::setText(pQVar3,pQVar6);
LAB_004aea3e:
  FUN_004bd740();
  FUN_004bc7e0(0);
  FUN_004bcf90(0);
  ExceptionList = local_10;
  return;
}


