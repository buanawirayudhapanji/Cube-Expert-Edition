
undefined8 FUN_004c4ae0(QString *param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  QString *pQVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  QString local_1c [4];
  QString local_18 [4];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00535db1;
  local_10 = ExceptionList;
  uVar2 = DAT_00759b24 ^ (uint)(local_18 + 0x14);
  ExceptionList = &local_10;
  local_14 = 0;
  QString::QString(param_1);
  iVar6 = 1;
  local_8 = 0;
  local_14 = 1;
  bVar1 = *param_2;
  pcVar4 = (code *)(uint)bVar1;
  if ((-(uint)(bVar1 != 0) & (uint)pcVar4) < 0x7f) {
    uVar5 = (-(uint)(bVar1 != 0) & (uint)pcVar4) + 1;
    if (uVar5 < 2) goto LAB_004c4bc7;
  }
  else {
    uVar5 = 0x80;
  }
  do {
    if (param_2[iVar6] < 0x10) {
      pQVar3 = (QString *)
               QString::asprintf((char *)local_18,&DAT_0058955c,(uint)param_2[iVar6],uVar2);
      local_8 = 1;
      QString::append(param_1,pQVar3);
      pQVar3 = local_18;
    }
    else {
      pQVar3 = (QString *)
               QString::asprintf((char *)local_1c,&DAT_00589564,(uint)param_2[iVar6],uVar2);
      local_8 = 2;
      QString::append(param_1,pQVar3);
      pQVar3 = local_1c;
    }
    local_8 = local_8 & 0xffffff00;
    QString::~QString(pQVar3);
    iVar6 = iVar6 + 1;
    pcVar4 = asprintf_exref;
  } while (iVar6 < (int)uVar5);
LAB_004c4bc7:
  ExceptionList = local_10;
  return CONCAT44(pcVar4,param_1);
}


