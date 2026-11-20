
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

QString * FUN_004f85f0(QString *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                      undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12
                      ,undefined4 param_13,undefined4 param_14,undefined4 param_15,
                      undefined4 param_16,undefined4 param_17,undefined1 param_18)

{
  QString QVar1;
  byte bVar2;
  uint uVar3;
  QString *pQVar4;
  int iVar5;
  QString local_64 [4];
  QString local_60 [4];
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined1 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00548df1;
  local_10 = ExceptionList;
  uVar3 = DAT_00759b24 ^ (uint)(local_60 + 0x5c);
  ExceptionList = &local_10;
  local_18 = param_18;
  local_58 = param_2;
  uStack_54 = param_3;
  uStack_50 = param_4;
  uStack_4c = param_5;
  local_48 = param_6;
  uStack_44 = param_7;
  uStack_40 = param_8;
  uStack_3c = param_9;
  local_38 = param_10;
  uStack_34 = param_11;
  uStack_30 = param_12;
  uStack_2c = param_13;
  local_5c = 0;
  local_28 = param_14;
  uStack_24 = param_15;
  uStack_20 = param_16;
  uStack_1c = param_17;
  local_14 = uVar3;
  QString::QString(param_1);
  local_8 = 0;
  local_5c = 1;
  bVar2 = (byte)param_2;
  if ((bVar2 == 0) || (bVar2 < 0x40)) {
    bVar2 = -(bVar2 != 0) & bVar2;
  }
  else {
    bVar2 = 0x40;
  }
  iVar5 = 0;
  if (bVar2 != 0) {
    do {
      QVar1 = local_60[iVar5 + 9];
      if ((byte)QVar1 < 0x10) {
        pQVar4 = (QString *)
                 QString::asprintf((char *)local_60,&DAT_0058955c,(uint)(byte)QVar1,uVar3);
        local_8 = 1;
        QString::append(param_1,pQVar4);
        pQVar4 = local_60;
      }
      else {
        pQVar4 = (QString *)
                 QString::asprintf((char *)local_64,&DAT_00589564,(uint)(byte)QVar1,uVar3);
        local_8 = 2;
        QString::append(param_1,pQVar4);
        pQVar4 = local_64;
      }
      local_8 = local_8 & 0xffffff00;
      QString::~QString(pQVar4);
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)(uint)bVar2);
  }
  ExceptionList = local_10;
  return param_1;
}


