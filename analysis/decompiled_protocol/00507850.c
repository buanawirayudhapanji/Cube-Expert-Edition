
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00507850(undefined2 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
                int param_5)

{
  char cVar1;
  undefined2 *puVar2;
  byte *pbVar3;
  byte bVar4;
  char *pcVar5;
  byte *pbVar6;
  
  puVar2 = param_1;
  *param_1 = _DAT_00756ad0;
  *(undefined1 *)(param_1 + 1) = 0x22;
  *(short *)((int)param_1 + 3) = (short)(param_5 + 8);
  param_1._2_1_ = (undefined1)((uint)(param_5 + 8) >> 0x10);
  *(undefined1 *)((int)puVar2 + 5) = param_1._2_1_;
  *(undefined1 *)(puVar2 + 3) = param_2;
  *(undefined4 *)((int)puVar2 + 7) = param_3;
  *(short *)((int)puVar2 + 0xb) = (short)param_5;
  *(undefined1 *)((int)puVar2 + 0xd) = param_5._2_1_;
  func_0x0051a5a0(puVar2 + 7,param_4,param_5);
  pbVar6 = (byte *)((int)(puVar2 + 7) + param_5);
  pcVar5 = (char *)(puVar2 + 3);
  pbVar3 = pbVar6 + (-6 - (int)puVar2);
  if (pbVar3 != (byte *)0x0) {
    bVar4 = 0;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      bVar4 = bVar4 + cVar1;
      pbVar3 = pbVar3 + -1;
    } while (pbVar3 != (byte *)0x0);
    *pbVar6 = ~bVar4;
    pbVar6 = pbVar6 + 1;
  }
  return (int)pbVar6 - (int)puVar2;
}


