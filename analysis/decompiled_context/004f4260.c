
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_004f4260(QObject *param_1)

{
  char cVar1;
  QObject *pQVar2;
  int iVar3;
  int iVar4;
  void **ppvVar5;
  QObject *pQVar6;
  int iVar7;
  QObject *pQVar8;
  uint uVar9;
  QListData *this;
  bool bVar10;
  QTextEdit **ppQVar11;
  QTextEdit *pQStack_8c;
  QString local_68 [4];
  int local_64;
  QObject *local_60;
  int local_5c;
  int local_58;
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  int local_48;
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  int local_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int local_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  QObject local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054597e;
  local_10 = ExceptionList;
  local_14 = DAT_00759b24 ^ (uint)(local_68 + 100);
  ExceptionList = &local_10;
  local_60 = param_1;
  pQVar2 = QObject::sender(param_1);
  iVar3 = QComboBox::currentIndex(*(QComboBox **)(param_1 + 0x11f4));
  this = (QListData *)(param_1 + 0x135c);
  iVar7 = 0;
  local_5c = 0;
  iVar4 = QListData::size(this);
  if (0 < iVar4) {
    local_64 = 0;
    do {
      if ((**(int **)this != 1) && (**(int **)this != 0)) {
        pQStack_8c = (QTextEdit *)0x4f42de;
        FUN_004f2bd0();
      }
      pQStack_8c = (QTextEdit *)0x4f42e7;
      ppvVar5 = QListData::at(this,iVar7);
      if (*(QObject **)((int)*ppvVar5 + 0x30) == pQVar2) {
        iVar7 = local_64 + iVar3 * 0x1da;
        pQVar8 = local_60 + iVar7 + 0x4f;
        local_58 = *(int *)pQVar8;
        iStack_54 = *(int *)(pQVar8 + 4);
        iStack_50 = *(int *)(pQVar8 + 8);
        iStack_4c = *(int *)(pQVar8 + 0xc);
        local_18 = pQVar8[0x40];
        local_48 = *(int *)(pQVar8 + 0x10);
        iStack_44 = *(int *)(pQVar8 + 0x14);
        iStack_40 = *(int *)(pQVar8 + 0x18);
        iStack_3c = *(int *)(pQVar8 + 0x1c);
        local_38 = *(int *)(pQVar8 + 0x20);
        iStack_34 = *(int *)(pQVar8 + 0x24);
        iStack_30 = *(int *)(pQVar8 + 0x28);
        iStack_2c = *(int *)(pQVar8 + 0x2c);
        local_28 = *(int *)(pQVar8 + 0x30);
        iStack_24 = *(int *)(pQVar8 + 0x34);
        iStack_20 = *(int *)(pQVar8 + 0x38);
        iStack_1c = *(int *)(pQVar8 + 0x3c);
        if ((**(int **)this != 1) && (**(int **)this != 0)) {
          pQStack_8c = (QTextEdit *)0x4f434a;
          FUN_004f2bd0();
        }
        pQStack_8c = (QTextEdit *)0x4f4355;
        ppvVar5 = QListData::at(this,local_5c);
        pQStack_8c = *(QTextEdit **)((int)*ppvVar5 + 0x30);
        ppQVar11 = &pQStack_8c;
        QTextEdit::toPlainText(pQStack_8c);
        FUN_004f47d0(ppQVar11);
        pQVar6 = (QObject *)&local_58;
        uVar9 = 0x3d;
        do {
          if (*(int *)pQVar6 != *(int *)pQVar8) goto LAB_004f438c;
          pQVar6 = pQVar6 + 4;
          pQVar8 = pQVar8 + 4;
          bVar10 = 3 < uVar9;
          uVar9 = uVar9 - 4;
        } while (bVar10);
        if (*pQVar6 != *pQVar8) {
LAB_004f438c:
          pQStack_8c = (QTextEdit *)0x0;
          cVar1 = FUN_00506590(5,iVar7 + 0x23,local_60 + iVar7 + 0x4f,0x41);
          if (cVar1 == '\0') {
            pQStack_8c = (QTextEdit *)0xffffffff;
            QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7c3c,(char *)local_68,"Write data failed !",
                            0);
            pQStack_8c = (QTextEdit *)local_68;
            local_8 = 0;
            FUN_00486bb0();
            local_8 = 0xffffffff;
            pQStack_8c = (QTextEdit *)0x4f43ec;
            QString::~QString(local_68);
          }
        }
        iVar7 = local_5c;
      }
      local_64 = local_64 + 0x46;
      iVar7 = iVar7 + 1;
      local_5c = iVar7;
      iVar4 = QListData::size(this);
    } while (iVar7 < iVar4);
  }
  ExceptionList = local_10;
  return;
}


