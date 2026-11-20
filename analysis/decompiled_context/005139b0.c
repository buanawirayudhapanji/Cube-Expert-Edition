
int __thiscall FUN_005139b0(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  QMessageLogger *this;
  QMessageLogger *this_00;
  QMessageLogger *this_01;
  QMessageLogger local_18 [20];
  
  iVar1 = param_3;
  iVar5 = param_2;
  pcVar4 = (char *)QMessageLogger::QMessageLogger(local_18,(char *)0x0,0,(char *)0x0);
  if (iVar5 == iVar1) {
    QMessageLogger::debug(this,pcVar4,"Find finished=%d\n",iVar5);
    return iVar5;
  }
  QMessageLogger::debug(this,pcVar4,"Find between %d ~ %d; ",iVar5,iVar1);
  param_3 = (uint)(iVar1 + 1 + iVar5) >> 1;
  cVar3 = FUN_005063f0(1,param_1[5] * param_1[1] + param_1[6] * param_3 + param_1[2],&param_2,2,0);
  if (cVar3 == '\0') {
    return -1;
  }
  if (((char)param_2 == 'H') && ((char)((uint)param_2 >> 8) == 'D')) {
    pcVar4 = (char *)QMessageLogger::QMessageLogger(local_18,(char *)0x0,0,(char *)0x0);
    uVar2 = param_3;
    QMessageLogger::debug(this_00,pcVar4,"%d used\n",param_3);
    iVar5 = (**(code **)(*param_1 + 0x14))(uVar2,iVar1);
    return iVar5;
  }
  pcVar4 = (char *)QMessageLogger::QMessageLogger(local_18,(char *)0x0,0,(char *)0x0);
  uVar2 = param_3;
  QMessageLogger::debug(this_01,pcVar4,"%d not used\n",param_3);
  iVar5 = (**(code **)(*param_1 + 0x14))(iVar5,uVar2 - 1);
  return iVar5;
}


