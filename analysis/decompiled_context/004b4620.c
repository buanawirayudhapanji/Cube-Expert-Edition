
undefined8 FUN_004b4620(QString *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  QString *pQVar3;
  uint uVar4;
  undefined4 extraout_EDX;
  code *pcVar5;
  int iVar6;
  QString local_18 [4];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005313c1;
  local_10 = ExceptionList;
  uVar2 = DAT_00759b24 ^ (uint)(local_18 + 0x14);
  ExceptionList = &local_10;
  local_14 = 0;
  QString::QString(param_1);
  local_8 = 0;
  local_14 = 1;
  bVar1 = *param_2;
  uVar4 = param_3 - 1;
  if ((int)(-(uint)(bVar1 != 0) & (uint)bVar1) < (int)uVar4) {
    uVar4 = -(uint)(bVar1 != 0) & (uint)bVar1;
  }
  iVar6 = 1;
  pcVar5 = (code *)CONCAT31((int3)((uint)extraout_EDX >> 8),bVar1);
  if (1 < (int)(uVar4 + 1)) {
    do {
      if (param_2[iVar6] < 0x10) {
        pQVar3 = (QString *)
                 QString::asprintf((char *)&param_3,&DAT_0058955c,(uint)param_2[iVar6],uVar2);
        local_8 = 1;
        QString::append(param_1,pQVar3);
        pQVar3 = (QString *)&param_3;
      }
      else {
        pQVar3 = (QString *)
                 QString::asprintf((char *)local_18,&DAT_00589564,(uint)param_2[iVar6],uVar2);
        local_8 = 2;
        QString::append(param_1,pQVar3);
        pQVar3 = local_18;
      }
      local_8 = local_8 & 0xffffff00;
      QString::~QString(pQVar3);
      iVar6 = iVar6 + 1;
      pcVar5 = asprintf_exref;
    } while (iVar6 < (int)(uVar4 + 1));
  }
  ExceptionList = local_10;
  return CONCAT44(pcVar5,param_1);
}


