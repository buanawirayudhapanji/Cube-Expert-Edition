
void __fastcall FUN_0049eea0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  puVar4 = (undefined4 *)func_0x00519367(0x30);
  func_0x005063f0(5,0,puVar4,0x30,0);
  uVar1 = puVar4[1];
  uVar2 = puVar4[2];
  uVar3 = puVar4[3];
  *(undefined4 *)(param_1 + 0x1c4) = *puVar4;
  *(undefined4 *)(param_1 + 0x1c8) = uVar1;
  *(undefined4 *)(param_1 + 0x1cc) = uVar2;
  *(undefined4 *)(param_1 + 0x1d0) = uVar3;
  uVar1 = puVar4[5];
  uVar2 = puVar4[6];
  uVar3 = puVar4[7];
  *(undefined4 *)(param_1 + 0x1d4) = puVar4[4];
  *(undefined4 *)(param_1 + 0x1d8) = uVar1;
  *(undefined4 *)(param_1 + 0x1dc) = uVar2;
  *(undefined4 *)(param_1 + 0x1e0) = uVar3;
  uVar1 = puVar4[9];
  uVar2 = puVar4[10];
  uVar3 = puVar4[0xb];
  *(undefined4 *)(param_1 + 0x1e4) = puVar4[8];
  *(undefined4 *)(param_1 + 0x1e8) = uVar1;
  *(undefined4 *)(param_1 + 0x1ec) = uVar2;
  *(undefined4 *)(param_1 + 0x1f0) = uVar3;
  iVar5 = _currentIndex_QComboBox__QBEHXZ();
  iVar6 = 0;
  if (-1 < iVar5 << 4) {
    iVar6 = iVar5 << 4;
  }
  *(int *)(param_1 + 0x148) = param_1 + 0x1c9 + iVar6;
  *(int *)(param_1 + 0x14c) = param_1 + 0x1cd + iVar6;
  *(int *)(param_1 + 0x150) = param_1 + 0x1c7 + iVar6;
  *(int *)(param_1 + 0x154) = param_1 + 0x1cb + iVar6;
  *(int *)(param_1 + 0x158) = param_1 + 0x1c8 + iVar6;
  *(int *)(param_1 + 0x15c) = param_1 + 0x1ca + iVar6;
  *(int *)(param_1 + 0x160) = param_1 + 0x1cc + iVar6;
  *(int *)(param_1 + 0x164) = param_1 + 0x1c6 + iVar6;
  *(int *)(param_1 + 0x168) = param_1 + 0x1c5 + iVar6;
  *(int *)(param_1 + 0x16c) = param_1 + 0x1c4 + iVar6;
  *(undefined4 *)(param_1 + 0x1c0) = 0;
  *(int *)(param_1 + 500) = param_1 + 0x1d0 + iVar6;
  *(int *)(param_1 + 0x1f8) = param_1 + 0x1cf + iVar6;
  *(int *)(param_1 + 0x1fc) = param_1 + 0x1ce + iVar6;
  FUN_004a02e0();
  *(undefined4 *)(param_1 + 0x1c0) = 1;
  return;
}


