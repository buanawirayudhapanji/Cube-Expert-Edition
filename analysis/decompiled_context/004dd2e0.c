
void __thiscall FUN_004dd2e0(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  QListWidgetItem *pQVar5;
  QString *pQVar6;
  QIcon *pQVar7;
  QListWidget *pQVar8;
  QString local_28 [4];
  QString local_24 [4];
  QListWidget *local_20;
  uint local_1c;
  QTypedArrayData<unsigned_short> *local_18;
  QString local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0053d565;
  local_10 = ExceptionList;
  uVar1 = DAT_00759b24 ^ (uint)(local_14 + 0x10);
  ExceptionList = &local_10;
  QString::QString(local_14);
  local_8 = 0;
  QListWidget::clear(*(QListWidget **)(param_1 + 0x28));
  uVar2 = *(int *)(param_1 + 0x458) - *(int *)(param_1 + 0x454) >> 2;
  local_20 = (QListWidget *)0x0;
  if (uVar2 != 0) {
    do {
      pQVar8 = local_20;
      QString::QString(local_24);
      local_8._0_1_ = 1;
      iVar3 = FUN_00488eb0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x2ca68),uVar1);
      if (iVar3 == 0) {
        local_18 = QString::fromAscii_helper("",0);
        local_8 = (uint)local_8._1_3_ << 8;
        QString::~QString(local_24);
        local_1c = (int)pQVar8 + 1;
      }
      else {
        iVar3 = *(int *)(iVar3 + 0x44);
        uVar4 = *(uint *)(*(int *)(*(int *)(param_1 + 0x454) + (int)pQVar8 * 4) + 0x34) /
                ((*(uint *)(iVar3 + 0x24) >> 3) * *(int *)(iVar3 + 0x20) * *(int *)(iVar3 + 0x1c));
        local_1c = (int)local_20 + 1;
        QString::asprintf((char *)&local_18,"Song %.3d -- %.2d:%.2d",local_1c,uVar4 / 0x3c,
                          uVar4 % 0x3c);
        local_8 = (uint)local_8._1_3_ << 8;
        QString::~QString(local_24);
        pQVar8 = local_20;
      }
      QString::operator=(local_14,(QString *)&local_18);
      QString::~QString((QString *)&local_18);
      if ((pQVar8 < (uint)(*(int *)(param_1 + 0x458) - *(int *)(param_1 + 0x454) >> 2)) &&
         (*(int *)(*(int *)(*(int *)(param_1 + 0x454) + (int)pQVar8 * 4) + 0x34) != 0)) {
        local_20 = *(QListWidget **)(param_1 + 0x28);
        pQVar5 = operator_new(0x18);
        local_8._0_1_ = 2;
        pQVar7 = (QIcon *)(param_1 + 0x494);
      }
      else {
        pQVar6 = (QString *)QString::asprintf((char *)local_28,"Song %.3d -- %s",local_1c,"(Empty)")
        ;
        QString::operator=(local_14,pQVar6);
        QString::~QString(local_28);
        local_20 = *(QListWidget **)(param_1 + 0x28);
        pQVar5 = operator_new(0x18);
        local_8._0_1_ = 3;
        pQVar7 = (QIcon *)(param_1 + 0x498);
      }
      QListWidgetItem::QListWidgetItem(pQVar5,pQVar7,local_14,(QListWidget *)0x0,0);
      *(undefined ***)pQVar5 = QListWidgetItem::vftable;
      local_8 = (uint)local_8._1_3_ << 8;
      iVar3 = QListWidget::count(local_20);
      QListWidget::insertItem(local_20,iVar3,pQVar5);
      local_20 = (QListWidget *)local_1c;
    } while (local_1c < uVar2);
  }
  if (param_2 != -1) {
    pQVar5 = QListWidget::item(*(QListWidget **)(param_1 + 0x28),param_2);
    QListWidget::setCurrentItem(*(QListWidget **)(param_1 + 0x28),pQVar5);
    FUN_004dc6e0(param_2);
  }
  QString::~QString(local_14);
  ExceptionList = local_10;
  return;
}


