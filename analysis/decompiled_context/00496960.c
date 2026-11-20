
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00496960(QObject *param_1,Data *param_2)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  QObject *this;
  QString *pQVar4;
  QListData *pQVar5;
  int iVar6;
  void *_Memory;
  Data *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00527dee;
  local_10 = ExceptionList;
  uVar3 = DAT_00759b24 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  this = QObject::sender(param_1);
  pQVar4 = (QString *)QString::asprintf((char *)&param_2,&DAT_005842a8,param_2,uVar3);
  local_8 = 0;
  QWidget::setToolTip((QWidget *)this,pQVar4);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar5 = (QListData *)QListWidget::selectedItems(*(QListWidget **)(param_1 + 0x30));
  QListData::size(pQVar5);
  local_8 = 1;
  if (*(int *)param_2 == 0) {
LAB_00496a0a:
    QListData::dispose(param_2);
  }
  else if (*(int *)param_2 != -1) {
    LOCK();
    iVar6 = *(int *)param_2;
    *(int *)param_2 = *(int *)param_2 + -1;
    UNLOCK();
    if (iVar6 == 1) goto LAB_00496a0a;
  }
  local_8 = 0xffffffff;
  pQVar5 = (QListData *)QListWidget::selectedItems(*(QListWidget **)(param_1 + 0x30));
  iVar6 = QListData::size(pQVar5);
  bVar1 = 0 < iVar6;
  local_8 = 2;
  param_2._3_1_ = bVar1;
  if (*(int *)local_14 != 0) {
    if (*(int *)local_14 == -1) goto LAB_00496a60;
    LOCK();
    iVar6 = *(int *)local_14;
    *(int *)local_14 = *(int *)local_14 + -1;
    UNLOCK();
    if (iVar6 != 1) goto LAB_00496a60;
  }
  QListData::dispose(local_14);
LAB_00496a60:
  local_8 = 0xffffffff;
  if (param_2._3_1_ != '\0') {
    QObject::blockSignals(*(QObject **)(param_1 + 0x28),true);
    if (*(int *)(*(int *)(param_1 + 0x4038) + 0xc844) != 3) {
      iVar6 = QAbstractSlider::value(*(QAbstractSlider **)(param_1 + 0x28));
      FUN_00508bd0(param_1 + 0x3c,(double)(100 - iVar6) / _PTR_00584578);
      memcpy(param_1 + 0x2038,param_1 + 0x3c,0x1ffc);
      cVar2 = FUN_00506590(4,0,param_1 + 0x2038,0x2000,0);
      if (cVar2 == '\0') {
        FUN_00486c20();
        ExceptionList = local_10;
        return;
      }
      _Memory = (void *)FUN_00519367();
      cVar2 = FUN_00506590(4,0x10000000,_Memory,1,0);
      if (cVar2 == '\0') {
        FUN_00486c20();
      }
      free(_Memory);
      FUN_004872d0(100);
      QObject::blockSignals(*(QObject **)(param_1 + 0x28),false);
    }
  }
  ExceptionList = local_10;
  return;
}


