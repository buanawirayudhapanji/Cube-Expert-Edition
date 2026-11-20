
int __thiscall FUN_0049e0f0(int param_1,byte param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *(int *)(param_1 + 0x138);
  if (iVar3 != 0) {
    uVar4 = *(int *)(param_1 + 0x140) - iVar3 & 0xfffffff8;
    iVar2 = iVar3;
    if (0xfff < uVar4) {
      iVar2 = *(int *)(iVar3 + -4);
      uVar4 = uVar4 + 0x23;
      if (0x1f < (iVar3 - iVar2) - 4U) goto LAB_0049e1e1;
    }
    func_0x00519359(iVar2,uVar4);
    *(undefined4 *)(param_1 + 0x138) = 0;
    *(undefined4 *)(param_1 + 0x13c) = 0;
    *(undefined4 *)(param_1 + 0x140) = 0;
  }
  iVar3 = *(int *)(param_1 + 300);
  if (iVar3 != 0) {
    uVar4 = *(int *)(param_1 + 0x134) - iVar3 & 0xfffffffc;
    iVar2 = iVar3;
    if (0xfff < uVar4) {
      iVar2 = *(int *)(iVar3 + -4);
      uVar4 = uVar4 + 0x23;
      if (0x1f < (iVar3 - iVar2) - 4U) {
LAB_0049e1e1:
        _invalid_parameter_noinfo_noreturn();
        pcVar1 = (code *)swi(3);
        iVar3 = (*pcVar1)();
        return iVar3;
      }
    }
    func_0x00519359(iVar2,uVar4);
    *(undefined4 *)(param_1 + 300) = 0;
    *(undefined4 *)(param_1 + 0x130) = 0;
    *(undefined4 *)(param_1 + 0x134) = 0;
  }
  func_0x0050a5b0();
  func_0x00486b10();
  __1QDialog__UAE_XZ();
  if ((param_2 & 1) != 0) {
    func_0x00519359(param_1,0x1170);
  }
  return param_1;
}


