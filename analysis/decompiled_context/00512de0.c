
int __thiscall FUN_00512de0(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  QMessageLogger *this;
  QMessageLogger *this_00;
  int iVar3;
  QMessageLogger local_18 [20];
  
  iVar3 = param_3;
  if (param_3 < 1) {
    return param_3;
  }
  while( true ) {
    cVar1 = FUN_005063f0(1,*(int *)(param_1 + 0x18) * iVar3 +
                           *(int *)(param_1 + 4) * *(int *)(param_1 + 0x14) + *(int *)(param_1 + 8),
                         &param_3,2,0);
    if (cVar1 == '\0') {
      return -5;
    }
    if (((char)param_3 == 'l') && ((char)((uint)param_3 >> 8) == 'o')) break;
    pcVar2 = (char *)QMessageLogger::QMessageLogger(local_18,(char *)0x0,0,(char *)0x0);
    QMessageLogger::debug(this,pcVar2,"%d not used\n",iVar3);
    iVar3 = iVar3 + -2;
    if (iVar3 < 1) {
      return iVar3;
    }
  }
  pcVar2 = (char *)QMessageLogger::QMessageLogger(local_18,(char *)0x0,0,(char *)0x0);
  QMessageLogger::debug(this_00,pcVar2,"%d used\n",iVar3);
  return iVar3;
}


