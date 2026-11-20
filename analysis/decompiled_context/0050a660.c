
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0050a660(QIODevice *param_1)

{
  code *pcVar1;
  code *pcVar2;
  char cVar3;
  uint uVar4;
  QString *pQVar5;
  QByteArray *pQVar6;
  char *pcVar7;
  int iVar8;
  __int64 _Var9;
  longlong lVar10;
  char *pcVar11;
  undefined4 uVar12;
  char local_54 [4];
  QString local_50 [4];
  QByteArray local_4c [4];
  int local_48;
  uint local_44;
  int local_40;
  QIODevice *local_3c;
  char local_35;
  short local_34 [6];
  undefined4 uStack_28;
  undefined2 local_24;
  int local_20 [2];
  undefined2 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0055326d;
  local_10 = ExceptionList;
  uVar4 = DAT_00759b24 ^ (uint)(local_20 + 7);
  ExceptionList = &local_10;
  local_3c = param_1;
  local_34[0] = 0;
  local_34[1] = 0;
  local_34[2] = 0;
  local_34[3] = 0;
  local_34[4] = 0;
  local_34[5] = 0;
  uStack_28 = 0;
  local_24 = 0;
  local_20[0] = 0;
  local_20[1] = 0;
  local_18 = 0;
  local_14 = uVar4;
  QIODevice::read(param_1,(char *)local_20,(ulonglong)uVar4 << 0x20);
  if (local_20[0] == 0x46464952) {
    QIODevice::read(param_1,local_54,(ulonglong)uVar4 << 0x20);
    QIODevice::read(param_1,(char *)local_20,(ulonglong)uVar4 << 0x20);
    if (local_20[0] == 0x45564157) {
      local_35 = '\0';
      _Var9 = QIODevice::read(param_1,(char *)&local_48,(ulonglong)uVar4 << 0x20);
      if (_Var9 != 0) {
        do {
          if (local_48 == 0x61746164) {
            if (local_35 != '\0') {
              *(short *)(local_40 + 0x14) = local_34[0];
              *(short *)(local_40 + 0x16) = local_34[1];
              *(short *)(local_40 + 0x18) = local_34[2];
              *(short *)(local_40 + 0x1a) = local_34[3];
              *(short *)(local_40 + 0x1c) = local_34[4];
              *(short *)(local_40 + 0x1e) = local_34[5];
              *(undefined2 *)(local_40 + 0x20) = (undefined2)uStack_28;
              *(undefined2 *)(local_40 + 0x22) = uStack_28._2_2_;
              *(undefined2 *)(local_40 + 0x24) = local_24;
              FUN_0050b750(local_44 / (uStack_28 & 0xffff),uStack_28 & 0xffff);
              uVar12 = 0;
              pcVar7 = (char *)FUN_0050b700(local_44);
              QIODevice::read(local_3c,pcVar7,CONCAT44(uVar4,uVar12));
              ExceptionList = local_10;
              return 1;
            }
            goto LAB_0050a8bd;
          }
          pcVar1 = *(code **)(*(int *)param_1 + 0x38);
          if (local_48 == 0x20746d66) {
            local_35 = '\x01';
            iVar8 = (*pcVar1)();
            iVar8 = local_44 + iVar8;
            QIODevice::read(param_1,(char *)local_34,(ulonglong)uVar4 << 0x20);
            (**(code **)(*(int *)param_1 + 0x40))(iVar8,0);
            if (local_34[0] != 1) {
              ExceptionList = local_10;
              return 0;
            }
          }
          else {
            pcVar2 = *(code **)(*(int *)param_1 + 0x40);
            lVar10 = (*pcVar1)();
            cVar3 = (*pcVar2)(lVar10 + (ulonglong)local_44);
            if (cVar3 == '\0') break;
          }
          _Var9 = QIODevice::read(param_1,(char *)&local_48,(ulonglong)uVar4 << 0x20);
        } while (_Var9 != 0);
        if (local_35 != '\0') {
          pQVar5 = (QString *)(**(code **)(*(int *)param_1 + 0x6c))(local_50);
          local_8 = 6;
          pQVar6 = (QByteArray *)QString::toLatin1(pQVar5);
          local_8 = CONCAT31(local_8._1_3_,7);
          pcVar7 = QByteArray::data(pQVar6);
          FUN_00486c20("Wave file \'%s\' has no data chunk",pcVar7);
          QByteArray::~QByteArray(local_4c);
          pQVar5 = local_50;
          goto LAB_0050a903;
        }
      }
LAB_0050a8bd:
      pQVar5 = (QString *)(**(code **)(*(int *)param_1 + 0x6c))(&local_3c);
      local_8 = 4;
      pQVar6 = (QByteArray *)QString::toLatin1(pQVar5);
      local_8 = CONCAT31(local_8._1_3_,5);
      pcVar7 = QByteArray::data(pQVar6);
      pcVar11 = "Wave file \'%s\' has no format chunk";
    }
    else {
      pQVar5 = (QString *)(**(code **)(*(int *)param_1 + 0x6c))(&local_3c);
      local_8 = 2;
      pQVar6 = (QByteArray *)QString::toLatin1(pQVar5);
      local_8 = CONCAT31(local_8._1_3_,3);
      pcVar7 = QByteArray::data(pQVar6);
      pcVar11 = "Wave file \'%s\' has no WAVE flat";
    }
    FUN_00486c20(pcVar11,pcVar7);
    QByteArray::~QByteArray((QByteArray *)&local_40);
    pQVar5 = (QString *)&local_3c;
  }
  else {
    pQVar5 = (QString *)(**(code **)(*(int *)param_1 + 0x6c))(&local_40);
    local_8 = 0;
    pQVar6 = (QByteArray *)QString::toLatin1(pQVar5);
    local_8 = CONCAT31(local_8._1_3_,1);
    pcVar7 = QByteArray::data(pQVar6);
    FUN_00486c20("Wave file \'%s\' has no RIFF flag",pcVar7);
    QByteArray::~QByteArray((QByteArray *)&local_3c);
    pQVar5 = (QString *)&local_40;
  }
LAB_0050a903:
  QString::~QString(pQVar5);
  ExceptionList = local_10;
  return 0;
}


