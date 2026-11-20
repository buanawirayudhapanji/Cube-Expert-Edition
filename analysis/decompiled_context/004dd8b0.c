
int __thiscall FUN_004dd8b0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  QMessageLogger *this;
  QMessageLogger *this_00;
  QMessageLogger *this_01;
  uint uVar5;
  QMessageLogger local_18 [20];
  
  iVar1 = param_3;
  iVar4 = param_2;
  pcVar3 = (char *)QMessageLogger::QMessageLogger(local_18,(char *)0x0,0,(char *)0x0);
  if (iVar4 == iVar1) {
    QMessageLogger::debug(this,pcVar3,"Find finished=%d\n",iVar4);
    return iVar4;
  }
  QMessageLogger::debug(this,pcVar3,"Find between %d ~ %d; ",iVar4,iVar1);
  uVar5 = (uint)(iVar1 + 1 + iVar4) >> 1;
  cVar2 = FUN_005063f0(1,param_1[4] * *param_1 + param_1[5] * uVar5 + param_1[1],&param_2,4,0);
  if (cVar2 == '\0') {
    return -1;
  }
  if (param_2 == -1) {
    pcVar3 = (char *)QMessageLogger::QMessageLogger(local_18,(char *)0x0,0,(char *)0x0);
    QMessageLogger::debug(this_01,pcVar3,"%d not used\n",uVar5);
    iVar4 = FUN_004dd8b0(iVar4,uVar5 - 1);
    return iVar4;
  }
  pcVar3 = (char *)QMessageLogger::QMessageLogger(local_18,(char *)0x0,0,(char *)0x0);
  QMessageLogger::debug(this_00,pcVar3,"%d used\n",uVar5);
  iVar4 = FUN_004dd8b0(uVar5,param_3);
  return iVar4;
}


