
void __fastcall FUN_00486b10(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  Data *pDVar3;
  void **ppvVar4;
  Data *this;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  local_10 = ExceptionList;
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_0051c740;
  piVar2 = (int *)*param_1;
  ppvVar4 = &local_10;
  if (*piVar2 != 0) {
    if (*piVar2 == -1) {
      return;
    }
    LOCK();
    iVar1 = *piVar2;
    ExceptionList = &local_10;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    ppvVar4 = ExceptionList;
    if (iVar1 != 1) {
      ExceptionList = local_10;
      return;
    }
  }
  ExceptionList = ppvVar4;
  pDVar3 = (Data *)*param_1;
  iVar1 = *(int *)(pDVar3 + 8);
  this = pDVar3 + (*(int *)(pDVar3 + 0xc) + 4) * 4;
  while (this != pDVar3 + (iVar1 + 4) * 4) {
    this = this + -4;
    QString::~QString((QString *)this);
  }
  QListData::dispose(pDVar3);
  ExceptionList = local_10;
  return;
}


