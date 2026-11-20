
void ** __thiscall FUN_004af0e0(QListData *param_1,int param_2,int param_3)

{
  int iVar1;
  void **ppvVar2;
  Data *pDVar3;
  void **ppvVar4;
  void **ppvVar5;
  Data *this;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005308d0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  ppvVar2 = QListData::begin(param_1);
  pDVar3 = QListData::detach_grow(param_1,&param_2,param_3);
  local_8 = 0;
  ppvVar4 = QListData::begin(param_1);
  ppvVar4 = ppvVar4 + param_2;
  ppvVar5 = QListData::begin(param_1);
  FUN_004878e0(ppvVar5,ppvVar4,ppvVar2);
  local_8 = 2;
  ppvVar2 = ppvVar2 + param_2;
  ppvVar4 = QListData::end(param_1);
  ppvVar5 = QListData::begin(param_1);
  FUN_004878e0(ppvVar5 + param_2 + param_3,ppvVar4,ppvVar2);
  local_8 = 0xffffffff;
  if (*(int *)pDVar3 != 0) {
    if (*(int *)pDVar3 == -1) goto LAB_004af1de;
    LOCK();
    iVar1 = *(int *)pDVar3;
    *(int *)pDVar3 = *(int *)pDVar3 + -1;
    UNLOCK();
    if (iVar1 != 1) goto LAB_004af1de;
  }
  iVar1 = *(int *)(pDVar3 + 8);
  this = pDVar3 + (*(int *)(pDVar3 + 0xc) + 4) * 4;
  while (this != pDVar3 + (iVar1 + 4) * 4) {
    this = this + -4;
    QString::~QString((QString *)this);
  }
  QListData::dispose(pDVar3);
LAB_004af1de:
  ppvVar4 = QListData::begin(param_1);
  ExceptionList = local_10;
  return ppvVar4 + param_2;
}


