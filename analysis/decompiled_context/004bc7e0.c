
void __thiscall FUN_004bc7e0(int param_1,QString param_2)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  QString *pQVar5;
  QByteArray *pQVar6;
  char *pcVar7;
  undefined4 uVar8;
  code *pcVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint local_50;
  uint local_4c;
  code *local_48;
  code *local_44;
  uint local_40;
  code *local_3c;
  code *local_38;
  code *local_34;
  int local_30;
  code *local_2c;
  int local_28;
  uint local_24;
  int local_20;
  QString local_1c [4];
  code *local_18;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00532a5d;
  local_10 = ExceptionList;
  uVar3 = DAT_00759b24 ^ (uint)(local_1c + 0x18);
  ExceptionList = &local_10;
  local_20 = 0;
  local_3c = clear_exref;
  QListWidget::clear(*(QListWidget **)(param_1 + 0x900));
  if (*(char *)(param_1 + 0xa38) != '\x03') {
    local_44 = asprintf_exref;
    local_2c = insertItem_exref;
    local_28 = 0;
    local_38 = (code *)0x0;
    local_30 = 0;
    local_34 = count_exref;
LAB_004bcbf0:
    pcVar9 = local_38;
    iVar4 = (*(int *)(param_1 + 0x68cc) + (uint)*(byte *)(param_1 + 0x6695) * 4) * 0x1a6;
    uVar11 = *(uint *)(local_38 + param_1 + iVar4 + 0x3f03);
    local_11 = local_38[param_1 + iVar4 + 0x3f07];
    local_50 = uVar11;
    if ((char)uVar11 == '\0') goto LAB_004bcd8c;
    if (local_20 != local_28) {
      *(uint *)(local_30 + iVar4 + 0x3f03 + param_1) = uVar11;
      *(code *)(local_30 + iVar4 + 0x3f07 + param_1) = local_11;
      iVar4 = *(int *)(param_1 + 0x68cc) + (uint)*(byte *)(param_1 + 0x6695) * 4;
      *(undefined4 *)(local_38 + param_1 + iVar4 * 0x1a6 + 0x3f03) = 0;
      local_38[param_1 + iVar4 * 0x1a6 + 0x3f07] = (code)0x0;
    }
    local_30 = local_30 + 5;
    local_20 = local_20 + 1;
    QString::QString((QString *)&local_24);
    local_8 = 4;
    if (pcVar9[param_1 + (*(int *)(param_1 + 0x68cc) + (uint)*(byte *)(param_1 + 0x6695) * 4) *
                         0x1a6 + 0x3f05] != (code)0x4) {
      local_4c = (uint)(byte)local_11;
      local_48 = (code *)(uVar11 >> 0x18);
      local_50 = uVar11 >> 0x10 & 0xff;
      if (3 < local_50) {
        local_50 = 3;
      }
      if ((**(int **)(param_1 + 0x66a0) != 1) && (**(int **)(param_1 + 0x66a0) != 0)) {
        FUN_004875a0(*(undefined4 *)(*(int *)(param_1 + 0x66a0) + 4));
      }
      pQVar5 = (QString *)QListData::at((QListData *)(param_1 + 0x66a0),local_50);
      pQVar6 = (QByteArray *)QString::toUtf8(pQVar5);
      local_8._0_1_ = 6;
      pcVar9 = local_48;
      uVar12 = local_4c;
      pcVar7 = QByteArray::data(pQVar6);
      pQVar5 = (QString *)
               (*local_44)(&local_40,"[%d]  %d  %s  %d  %d",local_20,(uVar11 >> 8 & 0xff) + 1,pcVar7
                           ,pcVar9,uVar12);
      QString::operator=((QString *)&local_24,pQVar5);
      QString::~QString((QString *)&local_40);
      local_8 = CONCAT31(local_8._1_3_,4);
      QByteArray::~QByteArray((QByteArray *)&local_18);
      uVar8 = (*local_34)(&local_24);
      (*local_2c)(uVar8);
      local_8 = 0xffffffff;
      QString::~QString((QString *)&local_24);
      goto LAB_004bcd8c;
    }
    (*local_3c)(uVar3);
    QString::operator=((QString *)&local_24,"Send:");
    pQVar5 = (QString *)
             FUN_004b4620(&local_44,
                          (*(int *)(param_1 + 0x68cc) + (uint)*(byte *)(param_1 + 0x6695) * 4) *
                          0x1a6 + 0x3fa3 + param_1,0x80);
    local_8._0_1_ = 5;
    QString::append((QString *)&local_24,pQVar5);
    local_8 = CONCAT31(local_8._1_3_,4);
    QString::~QString((QString *)&local_44);
    uVar8 = (*local_34)(&local_24);
    (*local_2c)(uVar8);
    iVar4 = 5;
    *(undefined1 *)
     ((*(int *)(param_1 + 0x68cc) + (uint)*(byte *)(param_1 + 0x6695) * 4) * 0x1a6 + 0x3f03 +
     param_1) = 1;
    *(undefined1 *)
     ((*(int *)(param_1 + 0x68cc) + (uint)*(byte *)(param_1 + 0x6695) * 4) * 0x1a6 + 0x3f05 +
     param_1) = 4;
    do {
      *(undefined1 *)
       ((*(int *)(param_1 + 0x68cc) + (uint)*(byte *)(param_1 + 0x6695) * 4) * 0x1a6 + iVar4 +
        0x3f03 + param_1) = 0;
      *(undefined1 *)
       ((*(int *)(param_1 + 0x68cc) + (uint)*(byte *)(param_1 + 0x6695) * 4) * 0x1a6 + iVar4 +
        0x3f08 + param_1) = 0;
      *(undefined1 *)
       ((*(int *)(param_1 + 0x68cc) + (uint)*(byte *)(param_1 + 0x6695) * 4) * 0x1a6 + iVar4 +
        0x3f0d + param_1) = 0;
      *(undefined1 *)
       ((*(int *)(param_1 + 0x68cc) + (uint)*(byte *)(param_1 + 0x6695) * 4) * 0x1a6 + iVar4 +
        0x3f12 + param_1) = 0;
      iVar10 = (*(int *)(param_1 + 0x68cc) + (uint)*(byte *)(param_1 + 0x6695) * 4) * 0x1a6 + iVar4;
      iVar4 = iVar4 + 0x19;
      *(undefined1 *)(iVar10 + 0x3f17 + param_1) = 0;
    } while (iVar4 < 0x50);
    local_8 = 0xffffffff;
    QString::~QString((QString *)&local_24);
LAB_004bcf1c:
    if (param_2 == (QString)0x0) {
      ExceptionList = local_10;
      return;
    }
    cVar2 = FUN_00506590(4,0x34c5,param_1 + 0x3efd,0x2790,param_1);
    if (cVar2 != '\0') {
      ExceptionList = local_10;
      return;
    }
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f6f40,(char *)&local_34,"Write data failed !",0);
    local_8 = 7;
    FUN_00486bb0(&local_34);
    pQVar5 = (QString *)&local_34;
    goto LAB_004bcf70;
  }
  local_48 = asprintf_exref;
  local_38 = insertItem_exref;
  local_30 = 0;
  local_28 = 0;
  local_2c = (code *)0x0;
  local_18 = checkedId_exref;
  local_34 = count_exref;
  do {
    iVar10 = (uint)*(byte *)(param_1 + 0x6690) * 0x684 + param_1;
    iVar4 = (*local_18)();
    iVar4 = iVar4 * 0x1a1 + local_28;
    uVar3 = *(uint *)(iVar4 + 0xa96 + iVar10);
    local_11 = *(code *)(iVar4 + 0xa9a + iVar10);
    local_24 = uVar3;
    if ((char)uVar3 != '\0') {
      if (local_20 != local_30) {
        iVar10 = (uint)*(byte *)(param_1 + 0x6690) * 0x684 + param_1;
        iVar4 = (*local_18)();
        *(uint *)(local_2c + iVar10 + iVar4 * 0x1a1 + 0xa96) = local_24;
        local_2c[iVar10 + iVar4 * 0x1a1 + 0xa9a] = local_11;
        iVar10 = (uint)*(byte *)(param_1 + 0x6690) * 0x684 + param_1;
        iVar4 = (*local_18)();
        iVar4 = iVar4 * 0x1a1 + local_28;
        *(undefined4 *)(iVar4 + 0xa96 + iVar10) = 0;
        *(undefined1 *)(iVar4 + 0xa9a + iVar10) = 0;
      }
      local_2c = local_2c + 5;
      local_20 = local_20 + 1;
      QString::QString(local_1c);
      bVar1 = *(byte *)(param_1 + 0x6690);
      local_8 = 0;
      iVar4 = (*local_18)();
      if (*(char *)(iVar4 * 0x1a1 + local_28 + 0xa98 + (uint)bVar1 * 0x684 + param_1) == '\x04') {
        (*local_3c)();
        QString::operator=(local_1c,"Send:");
        bVar1 = *(byte *)(param_1 + 0x6690);
        uVar8 = 0x80;
        iVar4 = (*local_18)(0x80);
        pQVar5 = (QString *)
                 FUN_004b4620(&local_48,iVar4 * 0x1a1 + (uint)bVar1 * 0x684 + 0xb36 + param_1,uVar8)
        ;
        local_8._0_1_ = 1;
        QString::append(local_1c,pQVar5);
        local_8 = (uint)local_8._1_3_ << 8;
        QString::~QString((QString *)&local_48);
        uVar8 = (*local_34)(local_1c);
        (*local_38)(uVar8);
        bVar1 = *(byte *)(param_1 + 0x6690);
        iVar4 = (*local_18)();
        *(undefined1 *)(iVar4 * 0x1a1 + 0xa96 + (uint)bVar1 * 0x684 + param_1) = 1;
        bVar1 = *(byte *)(param_1 + 0x6690);
        iVar4 = (*local_18)();
        local_38 = (code *)0x5;
        *(undefined1 *)(iVar4 * 0x1a1 + 0xa98 + (uint)bVar1 * 0x684 + param_1) = 4;
        do {
          bVar1 = *(byte *)(param_1 + 0x6690);
          iVar4 = (*local_18)();
          pcVar9 = local_38 + 5;
          local_38[(uint)bVar1 * 0x684 + param_1 + iVar4 * 0x1a1 + 0xa96] = (code)0x0;
          local_38 = pcVar9;
        } while ((int)pcVar9 < 0x50);
        local_8 = 0xffffffff;
        QString::~QString(local_1c);
LAB_004bcb66:
        if ((param_2 != (QString)0x0) &&
           (cVar2 = FUN_00506590(4,0x5d,param_1 + 0xa95,0x3420,param_1), cVar2 == '\0')) {
          QMetaObject::tr((QMetaObject *)&PTR_DAT_006f6f40,(char *)&param_2,"Write data failed !",0)
          ;
          local_8 = 3;
          FUN_00486bb0(&param_2);
          pQVar5 = &param_2;
LAB_004bcf70:
          QString::~QString(pQVar5);
        }
        ExceptionList = local_10;
        return;
      }
      local_40 = (uint)(byte)local_11;
      local_44 = (code *)(uVar3 >> 0x18);
      local_24 = uVar3 >> 0x10 & 0xff;
      if (3 < local_24) {
        local_24 = 3;
      }
      if ((**(int **)(param_1 + 0x66a0) != 1) && (**(int **)(param_1 + 0x66a0) != 0)) {
        FUN_004875a0(*(undefined4 *)(*(int *)(param_1 + 0x66a0) + 4));
      }
      pQVar5 = (QString *)QListData::at((QListData *)(param_1 + 0x66a0),local_24);
      pQVar6 = (QByteArray *)QString::toUtf8(pQVar5);
      local_8._0_1_ = 2;
      pcVar9 = local_44;
      uVar11 = local_40;
      pcVar7 = QByteArray::data(pQVar6);
      pQVar5 = (QString *)
               (*local_48)(&local_4c,"[%d]  %d  %s  %d  %d",local_20,(uVar3 >> 8 & 0xff) + 1,pcVar7,
                           pcVar9,uVar11);
      QString::operator=(local_1c,pQVar5);
      QString::~QString((QString *)&local_4c);
      local_8 = (uint)local_8._1_3_ << 8;
      QByteArray::~QByteArray((QByteArray *)&local_50);
      uVar8 = (*local_34)(local_1c);
      (*local_38)(uVar8);
      local_8 = 0xffffffff;
      QString::~QString(local_1c);
    }
    local_30 = local_30 + 1;
    local_28 = local_28 + 5;
    if (0x4f < local_28) goto LAB_004bcb66;
  } while( true );
LAB_004bcd8c:
  local_38 = local_38 + 5;
  local_28 = local_28 + 1;
  if (0x4f < (int)local_38) goto LAB_004bcf1c;
  goto LAB_004bcbf0;
}


