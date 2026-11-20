
void __thiscall FUN_004bd840(int param_1,QString param_2)

{
  byte bVar1;
  uint uVar2;
  QListWidget *this;
  char cVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  QString *pQVar10;
  QString local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00532a97;
  local_10 = ExceptionList;
  uVar4 = DAT_00759b24 ^ (uint)(local_14 + 0x10);
  ExceptionList = &local_10;
  iVar9 = 0;
  QListWidget::clear(*(QListWidget **)(param_1 + 0x9f8));
  puVar5 = (uint *)(param_1 + 0xa45);
  iVar7 = 0;
  iVar8 = param_1 + 0xa47;
  do {
    uVar2 = *(uint *)(iVar8 + -2);
    bVar1 = *(byte *)(iVar8 + 2);
    if ((char)uVar2 != '\0') {
      if (iVar9 != iVar7) {
        *puVar5 = uVar2;
        *(byte *)(puVar5 + 1) = bVar1;
        *(undefined4 *)(iVar8 + -2) = 0;
        *(undefined1 *)(iVar8 + 2) = 0;
      }
      puVar5 = (uint *)((int)puVar5 + 5);
      iVar9 = iVar9 + 1;
      QString::asprintf((char *)local_14,"[%d]  %d  %d  %d ~ %d",iVar9,(uVar2 >> 8 & 0xff) + 1,
                        uVar2 >> 0x10 & 0xff,uVar2 >> 0x18,(uint)bVar1,uVar4);
      local_8 = 0;
      this = *(QListWidget **)(param_1 + 0x9f8);
      pQVar10 = local_14;
      iVar6 = QListWidget::count(this);
      QListWidget::insertItem(this,iVar6,pQVar10);
      local_8 = 0xffffffff;
      QString::~QString(local_14);
    }
    iVar7 = iVar7 + 1;
    iVar8 = iVar8 + 5;
  } while (iVar7 < 0x10);
  if (param_2 != (QString)0x0) {
    cVar3 = FUN_00506590(4,0xd,param_1 + 0xa45,0x50,param_1);
    if (cVar3 == '\0') {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f6f40,(char *)&param_2,"Write data failed !",0);
      local_8 = 1;
      FUN_00486bb0(&param_2);
      QString::~QString(&param_2);
    }
  }
  ExceptionList = local_10;
  return;
}


