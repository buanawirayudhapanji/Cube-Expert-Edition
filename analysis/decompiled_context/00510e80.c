
void __fastcall FUN_00510e80(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0055cee0;
  local_10 = ExceptionList;
  uVar4 = DAT_00759b24 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  piVar2 = *(int **)(param_1 + 0x19c);
  local_8 = 0;
  if (piVar2 != (int *)0x0) {
    LOCK();
    iVar3 = piVar2[1] + -1;
    piVar2[1] = iVar3;
    UNLOCK();
    if (iVar3 == 0) {
      (**(code **)(*piVar2 + 4))(uVar4);
      LOCK();
      piVar1 = piVar2 + 2;
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        (**(code **)(*piVar2 + 8))();
      }
    }
  }
  QString::~QString((QString *)(param_1 + 0x194));
  FUN_0048daa0();
  ExceptionList = local_10;
  return;
}


