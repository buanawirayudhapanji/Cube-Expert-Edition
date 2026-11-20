
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00507770(undefined2 *param_1,undefined1 param_2,undefined4 param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  byte bVar4;
  
  iVar3 = 5;
  bVar4 = 0;
  *param_1 = _DAT_00756ad0;
  pcVar2 = (char *)(param_1 + 3);
  *(undefined1 *)(param_1 + 1) = 0x21;
  *(undefined2 *)((int)param_1 + 3) = 5;
  *(undefined1 *)((int)param_1 + 5) = 0;
  *(undefined1 *)(param_1 + 3) = param_2;
  *(undefined4 *)((int)param_1 + 7) = param_3;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    bVar4 = bVar4 + cVar1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(byte *)((int)param_1 + 0xb) = ~bVar4;
  return 0xc;
}


