
void __thiscall FUN_00484900(int param_1,int param_2)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  QMessageLogger *this;
  QMessageLogger local_18 [20];
  
  if (*(short *)(param_2 + 8) != 0x3f0) {
    return;
  }
  iVar3 = *(int *)(param_1 + 0x498);
  if (iVar3 == 0) {
    lVar2 = (ulonglong)*(uint *)(param_2 + 0x10) * 100;
    iVar3 = __aulldiv((int)lVar2,*(int *)(param_2 + 0x14) * 100 + (int)((ulonglong)lVar2 >> 0x20),
                      *(undefined4 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x1c));
  }
  else {
    if (iVar3 == 1) {
      lVar2 = (ulonglong)*(uint *)(param_2 + 0x10) * 100;
      iVar3 = __aulldiv((int)lVar2,*(int *)(param_2 + 0x14) * 100 + (int)((ulonglong)lVar2 >> 0x20),
                        *(undefined4 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x1c));
      iVar5 = QProgressBar::value(*(QProgressBar **)(param_1 + 0x28));
      if (iVar5 == iVar3) {
        return;
      }
      pcVar4 = (char *)QMessageLogger::QMessageLogger(local_18,(char *)0x0,0,(char *)0x0);
      QMessageLogger::debug
                (this,pcVar4,"nNewPos=%d Param1=%d, param2=%d",iVar3,*(undefined4 *)(param_2 + 0x10)
                 ,*(undefined4 *)(param_2 + 0x14),*(undefined4 *)(param_2 + 0x18),
                 *(undefined4 *)(param_2 + 0x1c));
      QProgressBar::setValue(*(QProgressBar **)(param_1 + 0x28),iVar3);
      return;
    }
    if (iVar3 != 2) {
      return;
    }
    uVar1 = *(uint *)(param_2 + 0x10);
    iVar3 = __aulldiv(uVar1 * 0x14,
                      (*(int *)(param_2 + 0x14) + (*(int *)(param_2 + 0x14) << 2 | uVar1 >> 0x1e) +
                      (uint)CARRY4(uVar1,uVar1 * 4)) * 4 | uVar1 * 5 >> 0x1e,
                      *(undefined4 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x1c));
    iVar3 = iVar3 + 0x50;
  }
  iVar5 = QProgressBar::value(*(QProgressBar **)(param_1 + 0x28));
  if (iVar5 != iVar3) {
    QProgressBar::setValue(*(QProgressBar **)(param_1 + 0x28),iVar3);
  }
  return;
}


