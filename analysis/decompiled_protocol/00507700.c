
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00507700(undefined2 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte bVar4;
  char *pcVar5;
  
  *param_1 = _DAT_00756ad0;
  pcVar5 = (char *)(param_1 + 3);
  *(undefined1 *)(param_1 + 1) = 0x24;
  *(undefined2 *)((int)param_1 + 3) = 9;
  *(undefined1 *)((int)param_1 + 5) = 0;
  *(undefined1 *)(param_1 + 3) = param_2;
  *(undefined4 *)((int)param_1 + 7) = param_3;
  *(undefined4 *)((int)param_1 + 0xb) = param_4;
  pbVar3 = (byte *)((int)param_1 + 0xf);
  pbVar2 = pbVar3 + (-6 - (int)param_1);
  if (pbVar2 != (byte *)0x0) {
    bVar4 = 0;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      bVar4 = bVar4 + cVar1;
      pbVar2 = pbVar2 + -1;
    } while (pbVar2 != (byte *)0x0);
    *pbVar3 = ~bVar4;
    pbVar3 = (byte *)(param_1 + 8);
  }
  return (int)pbVar3 - (int)param_1;
}


