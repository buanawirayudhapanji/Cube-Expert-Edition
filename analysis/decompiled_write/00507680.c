
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00507680(undefined2 *param_1,undefined4 param_2,undefined1 param_3)

{
  char cVar1;
  byte *pbVar2;
  byte bVar3;
  char *pcVar4;
  byte *pbVar5;
  
  *param_1 = _DAT_00756ad0;
  pcVar4 = (char *)(param_1 + 3);
  *(undefined1 *)(param_1 + 1) = 0x22;
  *(undefined2 *)((int)param_1 + 3) = 8;
  *(undefined1 *)((int)param_1 + 5) = 0;
  *(undefined1 *)(param_1 + 3) = param_3;
  *(undefined4 *)((int)param_1 + 7) = param_2;
  *(undefined2 *)((int)param_1 + 0xb) = 0;
  *(undefined1 *)((int)param_1 + 0xd) = 0;
  pbVar5 = (byte *)(param_1 + 7);
  pbVar2 = pbVar5 + (-6 - (int)param_1);
  if (pbVar2 != (byte *)0x0) {
    bVar3 = 0;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      bVar3 = bVar3 + cVar1;
      pbVar2 = pbVar2 + -1;
    } while (pbVar2 != (byte *)0x0);
    *pbVar5 = ~bVar3;
    pbVar5 = (byte *)((int)param_1 + 0xf);
  }
  return (int)pbVar5 - (int)param_1;
}


