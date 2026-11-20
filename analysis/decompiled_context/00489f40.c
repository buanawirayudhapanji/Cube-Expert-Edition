
undefined4 * __thiscall FUN_00489f40(undefined4 *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  
  *param_1 = 0;
  param_1[4] = 0;
  param_1[5] = 0xf;
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_004866d0(param_2,(int)pcVar2 - (int)(param_2 + 1));
  return param_1;
}


