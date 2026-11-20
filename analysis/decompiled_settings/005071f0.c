
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_005071f0(int param_1)

{
  char cVar1;
  uint uVar2;
  byte bStack_28;
  byte bStack_27;
  ushort uStack_26;
  byte bStack_24;
  byte bStack_23;
  undefined1 uStack_22;
  undefined1 uStack_21;
  byte bStack_20;
  byte bStack_1f;
  ushort uStack_1e;
  byte bStack_1c;
  byte bStack_1b;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  byte bStack_18;
  byte bStack_17;
  undefined1 uStack_16;
  undefined1 uStack_15;
  undefined4 uStack_8;
  
  uStack_8 = _DAT_00759b24 ^ (int)register0x00000010 - 4U;
  *(undefined4 *)(param_1 + 0x2caa0) = 0;
  cVar1 = func_0x005063f0(0,*(undefined4 *)(param_1 + 0x2ca8c),&bStack_28,0x14,0);
  if (cVar1 == '\0') {
    func_0x005195c6();
    return;
  }
  *(uint *)(param_1 + 0x2ca64) = (uint)uStack_26 << 0x10 | (uint)bStack_27 << 8 | (uint)bStack_28;
  uVar2 = (uint)CONCAT11(uStack_21,uStack_22) << 0x10 | (uint)bStack_23 << 8 | (uint)bStack_24;
  *(uint *)(param_1 + 0x2ca68) = uVar2;
  if ((((((uVar2 == 0x76df) || (uVar2 == 0x4f06)) || (uVar2 == 0x272e)) ||
       (((uVar2 == 0x5032 || (uVar2 == 0x4fce)) ||
        ((uVar2 == 0x2792 || ((uVar2 == 0x4e3e || (uVar2 == 0x4ea2)))))))) || (uVar2 == 0x4f09)) ||
     ((uVar2 == 0x272f || (uVar2 == 0x4e3f)))) {
    _DAT_00756ac8 = 0x80;
    _DAT_00756acc = 0x80;
  }
  else if (((uVar2 == 0x2733) || (uVar2 == 0x29e5)) || (uVar2 == 0x2a49)) {
    _DAT_00756ac8 = 0x200;
    _DAT_00756acc = 0x200;
  }
  else {
    _DAT_00756ac8 = 0x400;
    _DAT_00756acc = 0x400;
  }
  *(uint *)(param_1 + 0x2ca6c) = (uint)uStack_1e << 0x10 | (uint)bStack_1f << 8 | (uint)bStack_20;
  *(uint *)(param_1 + 0x2ca70) =
       (uint)CONCAT11(uStack_19,uStack_1a) << 0x10 | (uint)bStack_1b << 8 | (uint)bStack_1c;
  *(uint *)(param_1 + 0x2ca74) =
       (uint)CONCAT11(uStack_15,uStack_16) << 0x10 | (uint)bStack_17 << 8 | (uint)bStack_18;
  func_0x005195c6();
  return;
}


