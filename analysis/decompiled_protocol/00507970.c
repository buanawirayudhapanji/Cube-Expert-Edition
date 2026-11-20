
bool FUN_00507970(char *param_1,int param_2,byte param_3)

{
  char cVar1;
  byte bVar2;
  
  if (param_2 == 0) {
    return true;
  }
  bVar2 = 0;
  do {
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    bVar2 = bVar2 + cVar1;
    param_2 = param_2 + -1;
  } while (param_2 != 0);
  bVar2 = ~bVar2;
  if (param_3 != bVar2) {
    func_0x00486c20(&UNK_005935c0,bVar2,param_3);
  }
  return param_3 == bVar2;
}


