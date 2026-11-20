
int __thiscall FUN_00511f20(int *param_1,int param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  QMessageLogger *this;
  uint uVar4;
  QMessageLogger *this_00;
  QMessageLogger *this_01;
  QMessageLogger local_18 [20];
  
  iVar3 = param_3;
  pcVar2 = (char *)QMessageLogger::QMessageLogger(local_18,(char *)0x0,0,(char *)0x0);
  if (param_2 == iVar3) {
    QMessageLogger::debug(this,pcVar2,"Find finished=%d\n",param_2);
    return param_2;
  }
  QMessageLogger::debug(this,pcVar2,"Find between %d ~ %d; ",param_2,iVar3);
  uVar4 = (uint)(iVar3 + 1 + param_2) >> 1;
  cVar1 = FUN_005063f0(1,param_1[5] * param_1[1] + param_1[6] * uVar4 + param_1[2],&param_3,4,0);
  if (cVar1 == '\0') {
    return -1;
  }
  if (param_3 == -1) {
    pcVar2 = (char *)QMessageLogger::QMessageLogger(local_18,(char *)0x0,0,(char *)0x0);
    QMessageLogger::debug(this_01,pcVar2,"%d not used\n",uVar4);
    iVar3 = (**(code **)(*param_1 + 0x14))(param_2,uVar4 - 1);
    return iVar3;
  }
  pcVar2 = (char *)QMessageLogger::QMessageLogger(local_18,(char *)0x0,0,(char *)0x0);
  QMessageLogger::debug(this_00,pcVar2,"%d used\n",uVar4);
  iVar3 = (**(code **)(*param_1 + 0x14))(uVar4,iVar3);
  return iVar3;
}


