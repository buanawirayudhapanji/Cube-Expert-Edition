
void __thiscall FUN_00485b60(int param_1,int param_2)

{
  QListWidget *pQVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  uint uVar5;
  QString *pQVar6;
  int iVar7;
  QListWidgetItem *pQVar8;
  QString local_20 [4];
  QString local_1c [4];
  uint local_18;
  QString local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0051b9ec;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  QString::QString(local_14);
  local_8 = 0;
  QListWidget::clear(*(QListWidget **)(param_1 + 0x18));
  uVar5 = *(int *)(param_1 + 0x74) - *(int *)(param_1 + 0x70) >> 2;
  local_18 = 0;
  if (uVar5 != 0) {
    do {
      uVar2 = local_18;
      pQVar6 = (QString *)FUN_00511a50(local_1c,local_18);
      QString::operator=(local_14,pQVar6);
      QString::~QString(local_1c);
      iVar7 = FUN_00511b10(uVar2);
      if (iVar7 == 0) {
        local_18 = uVar2 + 1;
        pQVar6 = (QString *)QString::asprintf((char *)local_20,"Song %.3d -- %s",local_18,"(Empty)")
        ;
        QString::operator=(local_14,pQVar6);
        QString::~QString(local_20);
        pQVar1 = *(QListWidget **)(param_1 + 0x18);
        pQVar8 = operator_new(0x18);
        local_8._0_1_ = 2;
        QListWidgetItem::QListWidgetItem
                  (pQVar8,(QIcon *)(param_1 + 0x4a4),local_14,(QListWidget *)0x0,0);
        *(undefined ***)pQVar8 = QListWidgetItem::vftable;
        local_8 = (uint)local_8._1_3_ << 8;
        iVar7 = QListWidget::count(pQVar1);
        QListWidget::insertItem(pQVar1,iVar7,pQVar8);
      }
      else {
        pQVar1 = *(QListWidget **)(param_1 + 0x18);
        pQVar8 = operator_new(0x18);
        local_8._0_1_ = 1;
        QListWidgetItem::QListWidgetItem
                  (pQVar8,(QIcon *)(param_1 + 0x4a0),local_14,(QListWidget *)0x0,0);
        *(undefined ***)pQVar8 = QListWidgetItem::vftable;
        local_8 = (uint)local_8._1_3_ << 8;
        iVar7 = QListWidget::count(pQVar1);
        QListWidget::insertItem(pQVar1,iVar7,pQVar8);
        local_18 = local_18 + 1;
      }
    } while (local_18 < uVar5);
  }
  if (param_2 != -1) {
    pQVar8 = QListWidget::item(*(QListWidget **)(param_1 + 0x18),param_2);
    QListWidget::setCurrentItem(*(QListWidget **)(param_1 + 0x18),pQVar8);
    *(int *)(param_1 + 0x49c) = param_2;
    if ((((*(int *)(*(int *)(param_1 + 0x2c) + 0xc844) == 3) ||
         (cVar3 = FUN_005069b0(), cVar3 == '\0')) || (*(int *)(param_1 + 0x49c) == -1)) ||
       (iVar7 = FUN_00511b10(*(undefined4 *)(param_1 + 0x49c)), iVar7 == 0)) {
      bVar4 = false;
    }
    else {
      bVar4 = true;
    }
    QWidget::setEnabled(*(QWidget **)(param_1 + 0x20),bVar4);
    QWidget::setEnabled(*(QWidget **)(param_1 + 0x1c),bVar4);
  }
  QString::~QString(local_14);
  ExceptionList = local_10;
  return;
}


