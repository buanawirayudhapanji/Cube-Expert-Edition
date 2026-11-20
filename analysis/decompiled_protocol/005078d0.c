
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005078d0(undefined2 *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  byte bVar4;
  
  iVar3 = 2;
  bVar4 = 0;
  *param_1 = _DAT_00756ad0;
  pcVar2 = (char *)(param_1 + 3);
  *(undefined1 *)(param_1 + 1) = 0x50;
  *(undefined2 *)((int)param_1 + 3) = 2;
  *(undefined1 *)((int)param_1 + 5) = 0;
  param_1[3] = 0x7f7f;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    bVar4 = bVar4 + cVar1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(byte *)(param_1 + 4) = ~bVar4;
  return 9;
}


