
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004e0c10(int param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  QMessageLogger *this;
  QMessageLogger *this_00;
  QMessageLogger local_18 [20];
  
  if (*(int *)(param_1 + 0x38) == *(int *)(param_2 + 0xc)) {
    FUN_004e01a0();
    if (DAT_007628ac != '\0') {
      pcVar2 = (char *)QMessageLogger::QMessageLogger(local_18,(char *)0x0,0,(char *)0x0);
      QMessageLogger::debug(this,pcVar2,"timerEvent");
      if (*(int *)(*(int *)(param_1 + 0x28) + 0xc844) == 3) {
        cVar1 = FUN_004df970();
        if ((cVar1 != '\0') ||
           (iVar3 = *(int *)(param_1 + 0x3c) + 1, *(int *)(param_1 + 0x3c) = iVar3, 2 < iVar3)) {
          DAT_007628ac = '\0';
          *(undefined4 *)(param_1 + 0x3c) = 0;
        }
        if (*(int *)(*(int *)(param_1 + 0x28) + 0xc844) != 3) {
          FUN_004de710(1);
        }
      }
      else {
        DAT_007628ac = '\0';
        cVar1 = FUN_005060a0();
        if (cVar1 == '\0') {
          thunk_FUN_00508160();
          FUN_004872d0(10);
          _DAT_007628a8 = 0;
          FUN_004de710(0);
          pcVar2 = (char *)QMessageLogger::QMessageLogger(local_18,(char *)0x0,0,(char *)0x0);
          QMessageLogger::debug(this_00,pcVar2,"CDevBaseDlg::connected=FALSE\n");
          return;
        }
      }
    }
  }
  return;
}


