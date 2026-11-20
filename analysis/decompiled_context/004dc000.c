
void __fastcall FUN_004dc000(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  QMessageLogger *this;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined8 local_1c;
  undefined *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0051b667;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(*(int *)(param_1 + 0x2c) + 0xc844) != 3) {
    cVar1 = FUN_005069b0(DAT_00759b24 ^ (int)register0x00000010 - 4U);
    if (cVar1 != '\0') {
      iVar3 = *(int *)(param_1 + 0x2c);
      uStack_28 = *(undefined4 *)(iVar3 + 0x2ca78);
      uStack_24 = *(undefined4 *)(iVar3 + 0x2ca7c);
      uStack_20 = *(undefined4 *)(iVar3 + 0x2ca80);
      local_1c = *(undefined8 *)(iVar3 + 0x2ca84);
      piVar2 = (int *)FUN_00488eb0(*(undefined4 *)(iVar3 + 0x2ca68));
      if (((piVar2 != (int *)0x0) && (*piVar2 != -1)) && (piVar2[0xf] != 0)) {
        iVar3 = FUN_004dc100();
        if (iVar3 == 0) {
          QString::QString((QString *)&local_14);
          local_8 = 0;
          pcVar4 = (char *)QMessageLogger::QMessageLogger
                                     ((QMessageLogger *)&uStack_28,(char *)0x0,0,(char *)0x0);
          QMessageLogger::debug(this,pcVar4,"InitTreeFromMicData\n");
          FUN_004dd2e0(0);
        }
        else {
          local_14 = &DAT_00755eb8;
          local_8 = 1;
          FUN_00486bb0(&local_14);
        }
        QString::~QString((QString *)&local_14);
      }
    }
  }
  ExceptionList = local_10;
  return;
}


