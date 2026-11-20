
void __fastcall FUN_0050d540(QWidget *param_1)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_0051c740;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined ***)param_1 = EQPic::vftable;
  *(undefined ***)(param_1 + 8) = EQPic::vftable;
  QString::~QString((QString *)(param_1 + 0x32c));
  QString::~QString((QString *)(param_1 + 0x2f8));
  QString::~QString((QString *)(param_1 + 0x2c4));
  QString::~QString((QString *)(param_1 + 0x290));
  piVar2 = *(int **)(param_1 + 0x27c);
  if (*piVar2 == 0) {
LAB_0050d5cc:
    FUN_0050da10(*(undefined4 *)(param_1 + 0x27c));
  }
  else if (*piVar2 != -1) {
    LOCK();
    iVar1 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar1 == 1) goto LAB_0050d5cc;
  }
  piVar2 = *(int **)(param_1 + 0x278);
  if (*piVar2 == 0) {
LAB_0050d5f8:
    FUN_0050da10(*(undefined4 *)(param_1 + 0x278));
  }
  else if (*piVar2 != -1) {
    LOCK();
    iVar1 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar1 == 1) goto LAB_0050d5f8;
  }
  _eh_vector_destructor_iterator_(param_1 + 0x240,4,0xe,~QString_exref);
  _eh_vector_destructor_iterator_(param_1 + 0x1a8,4,10,~QString_exref);
  piVar2 = *(int **)(param_1 + 0x154);
  if (*piVar2 == 0) {
LAB_0050d650:
    QArrayData::deallocate(*(QArrayData **)(param_1 + 0x154),0x10,4);
  }
  else if (*piVar2 != -1) {
    LOCK();
    iVar1 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar1 == 1) goto LAB_0050d650;
  }
  piVar2 = *(int **)(param_1 + 0x150);
  if (*piVar2 == 0) {
LAB_0050d67e:
    QArrayData::deallocate(*(QArrayData **)(param_1 + 0x150),0x10,4);
  }
  else if (*piVar2 != -1) {
    LOCK();
    iVar1 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar1 == 1) goto LAB_0050d67e;
  }
  piVar2 = *(int **)(param_1 + 0x14c);
  if (*piVar2 == 0) {
LAB_0050d6ac:
    QArrayData::deallocate(*(QArrayData **)(param_1 + 0x14c),0x10,4);
  }
  else if (*piVar2 != -1) {
    LOCK();
    iVar1 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar1 == 1) goto LAB_0050d6ac;
  }
  piVar2 = *(int **)(param_1 + 0x148);
  if (*piVar2 == 0) {
LAB_0050d6da:
    QArrayData::deallocate(*(QArrayData **)(param_1 + 0x148),0x10,4);
  }
  else if (*piVar2 != -1) {
    LOCK();
    iVar1 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar1 == 1) goto LAB_0050d6da;
  }
  piVar2 = *(int **)(param_1 + 0x144);
  if (*piVar2 == 0) {
LAB_0050d708:
    QArrayData::deallocate(*(QArrayData **)(param_1 + 0x144),0x10,4);
  }
  else if (*piVar2 != -1) {
    LOCK();
    iVar1 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar1 == 1) goto LAB_0050d708;
  }
  piVar2 = *(int **)(param_1 + 0x140);
  if (*piVar2 != 0) {
    if (*piVar2 == -1) goto LAB_0050d743;
    LOCK();
    iVar1 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar1 != 1) goto LAB_0050d743;
  }
  QArrayData::deallocate(*(QArrayData **)(param_1 + 0x140),0x10,4);
LAB_0050d743:
  QVector<QPoint>::~QVector<QPoint>((QVector<QPoint> *)(param_1 + 0xdc));
  QWidget::~QWidget(param_1);
  ExceptionList = local_10;
  return;
}


