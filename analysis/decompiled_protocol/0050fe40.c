
void __thiscall FUN_0050fe40(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = param_1[3];
  uVar3 = iVar1 + param_3;
  if ((uint)param_1[1] < uVar3) {
    iVar2 = param_1[1] - iVar1;
    func_0x0051a5a0(*param_1 + iVar1,param_2,iVar2);
    uVar3 = param_3 - iVar2;
    func_0x0051a5a0(*param_1,iVar2 + param_2,uVar3);
    param_1[3] = -(uint)(uVar3 < (uint)param_1[1]) & uVar3;
    return;
  }
  func_0x0051a5a0(*param_1 + iVar1,param_2,param_3);
  param_1[3] = -(uint)(uVar3 < (uint)param_1[1]) & uVar3;
  return;
}


