
void __fastcall FUN_00500dd0(QString *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (*(void **)(param_1 + 0x98) != (void *)0x0) {
    free(*(void **)(param_1 + 0x98));
  }
  iVar1 = *(int *)(param_1 + 0x8c);
  if (iVar1 != 0) {
    uVar3 = *(int *)(param_1 + 0x94) - iVar1 & 0xffffff80;
    iVar2 = iVar1;
    if (0xfff < uVar3) {
      iVar2 = *(int *)(iVar1 + -4);
      uVar3 = uVar3 + 0x23;
      if (0x1f < (iVar1 - iVar2) - 4U) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
    FUN_00519359(iVar2,uVar3);
    *(undefined4 *)(param_1 + 0x8c) = 0;
    *(undefined4 *)(param_1 + 0x90) = 0;
    *(undefined4 *)(param_1 + 0x94) = 0;
  }
  QString::~QString(param_1 + 8);
                    /* WARNING: Could not recover jumptable at 0x00500e49. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  QString::~QString(param_1);
  return;
}


