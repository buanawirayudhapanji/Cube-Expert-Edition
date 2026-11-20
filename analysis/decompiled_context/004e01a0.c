
void __fastcall FUN_004e01a0(QWidget *param_1)

{
  byte bVar1;
  QListWidget *pQVar2;
  QString *pQVar3;
  uint uVar4;
  void *pvVar5;
  uint uVar6;
  QWidget *this;
  QListWidgetItem *pQVar7;
  QSize *pQVar8;
  int iVar9;
  byte *pbVar10;
  char *pcVar11;
  bool bVar12;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined8 local_40;
  undefined1 local_38 [8];
  QSize local_30 [8];
  QListWidgetItem *local_28;
  void *local_24;
  QWidget *local_20;
  uint local_1c;
  QSize local_18 [4];
  QString *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0053f39b;
  local_10 = ExceptionList;
  uVar4 = DAT_00759b24 ^ (uint)(local_18 + 0x14);
  ExceptionList = &local_10;
  local_24 = (void *)0x0;
  local_20 = param_1;
  QListWidget::clear(*(QListWidget **)(param_1 + 0x18));
  (**(code **)(**(int **)(param_1 + 0x24) + 0x2c))(0,uVar4);
  iVar9 = *(int *)(param_1 + 0x28);
  if (*(int *)(iVar9 + 0xc844) != 3) {
    uVar4 = *(uint *)(iVar9 + 0x2ca64);
    local_1c = *(int *)(iVar9 + 0x2ca68);
    uStack_4c = *(undefined4 *)(iVar9 + 0x2ca78);
    uStack_48 = *(undefined4 *)(iVar9 + 0x2ca7c);
    uStack_44 = *(undefined4 *)(iVar9 + 0x2ca80);
    local_40 = *(undefined8 *)(iVar9 + 0x2ca84);
    pvVar5 = (void *)FUN_00488eb0(local_1c);
    pbVar10 = (byte *)&uStack_4c;
    local_24 = pvVar5;
    pcVar11 = "Micphone";
    do {
      bVar1 = *pbVar10;
      bVar12 = bVar1 < (byte)*pcVar11;
      if (bVar1 != *pcVar11) {
LAB_004e0260:
        uVar6 = -(uint)bVar12 | 1;
        goto LAB_004e0265;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar10[1];
      bVar12 = bVar1 < (byte)pcVar11[1];
      if (bVar1 != pcVar11[1]) goto LAB_004e0260;
      pbVar10 = pbVar10 + 2;
      pcVar11 = pcVar11 + 2;
    } while (bVar1 != 0);
    uVar6 = 0;
LAB_004e0265:
    if (uVar6 == 0) {
      if (*(int *)(param_1 + 0x50) == 0) {
        QWidget::setHidden(param_1,true);
        local_24 = operator_new(0x54);
        local_8 = 0;
        this = (QWidget *)FUN_004e1590(*(undefined4 *)(param_1 + 0x28),0,0);
        local_8 = 0xffffffff;
        *(QWidget **)(param_1 + 0x50) = this;
        QWidget::setAttribute(this,0x37,true);
        QWidget::show(*(QWidget **)(param_1 + 0x50));
        ExceptionList = local_10;
        return;
      }
    }
    else if (pvVar5 != (void *)0x0) {
      QFont::setPixelSize((QFont *)&DAT_007626a0,0x1e);
      if (local_1c == 19000) {
        if (uVar4 < 0xe) {
LAB_004e03ef:
          (**(code **)(**(int **)(param_1 + 0x24) + 0x2c))(1);
          ExceptionList = local_10;
          return;
        }
      }
      else if (((local_1c == 0x291e) && (uVar4 == 5)) || ((local_1c == 0x291f && (uVar4 < 0x15))))
      goto LAB_004e03ef;
      (**(code **)(**(int **)(param_1 + 0x24) + 0x2c))(0);
      if (*(int *)(*(int *)(param_1 + 0x28) + 0x2caa0) == 0) {
        local_1c = 1;
        local_14 = (QString *)&DAT_0075c438;
        do {
          pQVar3 = local_14;
          if ((*(uint *)((int)pvVar5 + 0x38) & local_1c) != 0) {
            pQVar7 = operator_new(0x18);
            local_8 = 1;
            local_28 = pQVar7;
            QListWidgetItem::QListWidgetItem(pQVar7,pQVar3,(QListWidget *)0x0,0);
            *(undefined ***)pQVar7 = QListWidgetItem::vftable;
            local_8 = 0xffffffff;
            pQVar8 = (QSize *)QSize::QSize(local_30,200,100);
            QListWidgetItem::setSizeHint(pQVar7,pQVar8);
            QListWidgetItem::setFont(pQVar7,(QFont *)&DAT_007626a0);
            pQVar2 = *(QListWidget **)(local_20 + 0x18);
            iVar9 = QListWidget::count(pQVar2);
            QListWidget::insertItem(pQVar2,iVar9,pQVar7);
            pvVar5 = local_24;
          }
          local_14 = local_14 + 4;
          local_1c = local_1c << 1 | (uint)((int)local_1c < 0);
        } while ((int)local_14 < 0x75c48c);
        ExceptionList = local_10;
        return;
      }
      pQVar7 = operator_new(0x18);
      local_8 = 2;
      local_28 = pQVar7;
      iVar9 = FUN_004e0160(local_38);
      local_8 = CONCAT31(local_8._1_3_,3);
      local_24 = (void *)0x1;
      QListWidgetItem::QListWidgetItem(pQVar7,(QString *)(iVar9 + 8),(QListWidget *)0x0,0);
      *(undefined ***)pQVar7 = QListWidgetItem::vftable;
      local_8 = 0xffffffff;
      FUN_004de650();
      pQVar8 = (QSize *)QSize::QSize(local_18,200,100);
      QListWidgetItem::setSizeHint(pQVar7,pQVar8);
      QListWidgetItem::setFont(pQVar7,(QFont *)&DAT_007626a0);
      pQVar2 = *(QListWidget **)(param_1 + 0x18);
      iVar9 = QListWidget::count(pQVar2);
      QListWidget::insertItem(pQVar2,iVar9,pQVar7);
    }
  }
  ExceptionList = local_10;
  return;
}


