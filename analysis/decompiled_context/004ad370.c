
void __fastcall FUN_004ad370(int param_1)

{
  undefined1 uVar1;
  QListWidget *this;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  QString *pQVar10;
  code *local_1c;
  QString local_18 [4];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00530727;
  local_10 = ExceptionList;
  uVar3 = DAT_00759b24 ^ (uint)(local_18 + 0x14);
  uVar7 = 0;
  pcVar4 = (char *)(param_1 + 0xa45);
  do {
    if (*pcVar4 == '\0') {
      iVar9 = param_1 + uVar7 * 4;
      local_14 = 0;
      ExceptionList = &local_10;
      *(undefined4 *)(uVar7 + 0xa45 + iVar9) = 1;
      *(undefined1 *)(uVar7 + 0xa49 + iVar9) = 0;
      QListWidget::clear(*(QListWidget **)(param_1 + 0x9f8));
      puVar5 = (uint *)(param_1 + 0xa45);
      local_1c = asprintf_exref;
      iVar9 = param_1 + 0xa47;
      iVar8 = 0;
      do {
        uVar7 = *(uint *)(iVar9 + -2);
        uVar1 = *(undefined1 *)(iVar9 + 2);
        if ((char)uVar7 != '\0') {
          if (local_14 != iVar8) {
            *puVar5 = uVar7;
            *(undefined1 *)(puVar5 + 1) = uVar1;
            *(undefined4 *)(iVar9 + -2) = 0;
            *(undefined1 *)(iVar9 + 2) = 0;
          }
          local_14 = local_14 + 1;
          puVar5 = (uint *)((int)puVar5 + 5);
          (*local_1c)(local_18,"[%d]  %d  %d  %d ~ %d",local_14,(uVar7 >> 8 & 0xff) + 1,
                      uVar7 >> 0x10 & 0xff,uVar7 >> 0x18,uVar1,uVar3);
          this = *(QListWidget **)(param_1 + 0x9f8);
          pQVar10 = local_18;
          local_8 = 0;
          iVar6 = QListWidget::count(this);
          QListWidget::insertItem(this,iVar6,pQVar10);
          local_8 = 0xffffffff;
          QString::~QString(local_18);
        }
        iVar8 = iVar8 + 1;
        iVar9 = iVar9 + 5;
      } while (iVar8 < 0x10);
      cVar2 = FUN_00506590(4,0xd,param_1 + 0xa45,0x50,param_1);
      if (cVar2 == '\0') {
        QMetaObject::tr((QMetaObject *)&PTR_DAT_006f6f40,(char *)&local_1c,"Write data failed !",0);
        local_8 = 1;
        FUN_00486bb0(&local_1c);
        QString::~QString((QString *)&local_1c);
      }
      ExceptionList = local_10;
      return;
    }
    uVar7 = uVar7 + 1;
    pcVar4 = pcVar4 + 5;
  } while (uVar7 < 0x10);
  return;
}


