
int __thiscall FUN_004a3680(int param_1,byte param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *(int *)(param_1 + 0x80);
  if (iVar3 != 0) {
    uVar4 = *(int *)(param_1 + 0x88) - iVar3 & 0xfffffff8;
    iVar2 = iVar3;
    if (0xfff < uVar4) {
      iVar2 = *(int *)(iVar3 + -4);
      uVar4 = uVar4 + 0x23;
      if (0x1f < (iVar3 - iVar2) - 4U) goto LAB_004a375c;
    }
    func_0x00519359(iVar2,uVar4);
    *(undefined4 *)(param_1 + 0x80) = 0;
    *(undefined4 *)(param_1 + 0x84) = 0;
    *(undefined4 *)(param_1 + 0x88) = 0;
  }
  iVar3 = *(int *)(param_1 + 0x74);
  if (iVar3 != 0) {
    uVar4 = *(int *)(param_1 + 0x7c) - iVar3 & 0xfffffffc;
    iVar2 = iVar3;
    if (0xfff < uVar4) {
      iVar2 = *(int *)(iVar3 + -4);
      uVar4 = uVar4 + 0x23;
      if (0x1f < (iVar3 - iVar2) - 4U) {
LAB_004a375c:
        _invalid_parameter_noinfo_noreturn();
        pcVar1 = (code *)swi(3);
        iVar3 = (*pcVar1)();
        return iVar3;
      }
    }
    func_0x00519359(iVar2,uVar4);
    *(undefined4 *)(param_1 + 0x74) = 0;
    *(undefined4 *)(param_1 + 0x78) = 0;
    *(undefined4 *)(param_1 + 0x7c) = 0;
  }
  func_0x0050a5b0();
  func_0x00486b10();
  __1QDialog__UAE_XZ();
  if ((param_2 & 1) != 0) {
    func_0x00519359(param_1,0xffc);
  }
  return param_1;
}


