
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_00505fb0(int param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  FUN_00507ee0();
  uVar2 = _UNK_005935b8;
  uVar1 = _DAT_005935b0;
  *(undefined ***)(param_1 + 0xc860) = CCriticalSection::vftable;
  *(undefined8 *)(param_1 + 0x2ca64) = uVar1;
  *(undefined8 *)(param_1 + 0x2ca6c) = uVar2;
  *(undefined8 *)(param_1 + 0x2ca74) = uVar1;
  *(undefined8 *)(param_1 + 0x2ca7c) = uVar2;
  *(undefined8 *)(param_1 + 0x2ca84) = uVar1;
  QString::QString((QString *)(param_1 + 0x2ca90));
  QString::QString((QString *)(param_1 + 0x2ca94));
  QString::QString((QString *)(param_1 + 0x2ca98));
  *(undefined4 *)(param_1 + 0x2ca9c) = 0x400;
  *(undefined4 *)(param_1 + 0x2caa0) = 0;
  return param_1;
}


