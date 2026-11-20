
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00507930(undefined2 *param_1,undefined1 param_2)

{
  *param_1 = _DAT_00756ad0;
  *(undefined1 *)(param_1 + 1) = param_2;
  *(undefined2 *)((int)param_1 + 3) = 0;
  *(undefined1 *)((int)param_1 + 5) = 0;
  *(undefined1 *)(param_1 + 3) = 0xff;
  return 7;
}


