
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005079c0(uint *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 param_5)

{
  char cVar1;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined1 auStack_1c [2];
  char cStack_1a;
  undefined2 uStack_19;
  undefined1 uStack_17;
  byte bStack_16;
  undefined4 uStack_15;
  undefined2 uStack_11;
  undefined1 uStack_f;
  undefined2 uStack_d;
  undefined4 uStack_8;
  
  uStack_8 = _DAT_00759b24 ^ (uint)(auStack_1c + 0x18);
  uStack_24 = 0;
  cVar1 = func_0x00507fc0(auStack_1c,0x12,&uStack_24,param_5);
  if ((cVar1 != '\0') && (cStack_1a == '$')) {
    uStack_20 = (uint)CONCAT12(uStack_17,uStack_19);
    cVar1 = FUN_00507970(&bStack_16,uStack_20,auStack_1c[uStack_20 + 6]);
    if (cVar1 != '\0') {
      *param_1 = (uint)bStack_16;
      *param_2 = uStack_15;
      *param_3 = 0;
      *(undefined2 *)param_3 = uStack_11;
      *(undefined1 *)((int)param_3 + 2) = uStack_f;
      *param_4 = 0;
      *(undefined2 *)param_4 = uStack_d;
      func_0x005195c6();
      return;
    }
  }
  func_0x005195c6();
  return;
}


