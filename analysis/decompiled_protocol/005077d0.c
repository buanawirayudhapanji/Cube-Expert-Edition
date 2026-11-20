
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_005077d0(undefined2 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  byte *pbVar2;
  byte bVar3;
  byte *pbVar4;
  char *pcVar5;
  
  *param_1 = _DAT_00756ad0;
  pcVar5 = (char *)(param_1 + 3);
  *(undefined1 *)(param_1 + 1) = 0x23;
  *(undefined2 *)((int)param_1 + 3) = 8;
  *(undefined1 *)((int)param_1 + 5) = 0;
  *(undefined1 *)(param_1 + 3) = param_2;
  *(undefined4 *)((int)param_1 + 7) = param_3;
  *(undefined2 *)((int)param_1 + 0xb) = (undefined2)param_4;
  *(undefined1 *)((int)param_1 + 0xd) = param_4._2_1_;
  pbVar4 = (byte *)(param_1 + 7);
  pbVar2 = pbVar4 + (-6 - (int)param_1);
  if (pbVar2 != (byte *)0x0) {
    bVar3 = 0;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      bVar3 = bVar3 + cVar1;
      pbVar2 = pbVar2 + -1;
    } while (pbVar2 != (byte *)0x0);
    *pbVar4 = ~bVar3;
    pbVar4 = (byte *)((int)param_1 + 0xf);
  }
  return (int)pbVar4 - (int)param_1;
}


