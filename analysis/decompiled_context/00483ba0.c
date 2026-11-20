
void __fastcall FUN_00483ba0(int *param_1)

{
  QString *pQVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  QString *this;
  
  this = (QString *)*param_1;
  if (this != (QString *)0x0) {
    pQVar1 = (QString *)param_1[1];
    for (; this != pQVar1; this = this + 4) {
      QString::~QString(this);
    }
    iVar2 = *param_1;
    uVar4 = param_1[2] - iVar2 & 0xfffffffc;
    iVar3 = iVar2;
    if (0xfff < uVar4) {
      iVar3 = *(int *)(iVar2 + -4);
      uVar4 = uVar4 + 0x23;
      if (0x1f < (iVar2 - iVar3) - 4U) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
    FUN_00519359(iVar3,uVar4);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}


