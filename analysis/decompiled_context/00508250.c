
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __thiscall FUN_00508250(short *param_1,QIODevice *param_2)

{
  code *pcVar1;
  int iVar2;
  code *pcVar3;
  void *_Memory;
  char cVar4;
  uint uVar5;
  QString *pQVar6;
  QByteArray *pQVar7;
  char *pcVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  __int64 _Var12;
  undefined8 uVar13;
  char *pcVar14;
  char local_4c [4];
  QString local_48 [4];
  QByteArray local_44 [4];
  short *local_40;
  short *local_3c;
  char local_35;
  short local_34 [6];
  undefined4 uStack_28;
  short local_24;
  int local_20 [2];
  undefined2 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00551acd;
  local_10 = ExceptionList;
  uVar5 = DAT_00759b24 ^ (uint)(local_20 + 7);
  ExceptionList = &local_10;
  local_24 = 0;
  local_20[0] = 0;
  local_20[1] = 0;
  local_34[0] = 0;
  local_34[1] = 0;
  local_34[2] = 0;
  local_34[3] = 0;
  local_34[4] = 0;
  local_34[5] = 0;
  uStack_28 = 0;
  local_18 = 0;
  local_3c = param_1;
  local_14 = uVar5;
  QIODevice::read(param_2,(char *)local_20,(ulonglong)uVar5 << 0x20);
  if (local_20[0] == 0x46464952) {
    QIODevice::read(param_2,local_4c,(ulonglong)uVar5 << 0x20);
    QIODevice::read(param_2,(char *)local_20,(ulonglong)uVar5 << 0x20);
    if (local_20[0] == 0x45564157) {
      local_35 = '\0';
      local_40 = param_1 + 0x16;
      _Var12 = QIODevice::read(param_2,(char *)local_40,(ulonglong)uVar5 << 0x20);
      if (_Var12 != 0) {
        while (*(int *)(param_1 + 0x16) != 0x61746164) {
          pcVar1 = *(code **)(*(int *)param_2 + 0x38);
          if (*(int *)(param_1 + 0x16) != 0x20746d66) {
            pcVar3 = *(code **)(*(int *)param_2 + 0x40);
            uVar13 = (*pcVar1)();
            cVar4 = (*pcVar3)((uint)uVar13 + *(uint *)(local_3c + 0x18),
                              (int)((ulonglong)uVar13 >> 0x20) +
                              (uint)CARRY4((uint)uVar13,*(uint *)(local_3c + 0x18)));
            if (cVar4 != '\0') goto LAB_005083f7;
LAB_00508412:
            if (local_35 == '\0') goto LAB_005084c6;
            pQVar6 = (QString *)(**(code **)(*(int *)param_2 + 0x6c))(local_48);
            local_8 = 6;
            pQVar7 = (QByteArray *)QString::toLatin1(pQVar6);
            local_8 = CONCAT31(local_8._1_3_,7);
            pcVar8 = QByteArray::data(pQVar7);
            FUN_00486c20("Wave file \'%s\' has no data chunk",pcVar8);
            QByteArray::~QByteArray(local_44);
            pQVar6 = local_48;
            goto LAB_0050850c;
          }
          local_35 = '\x01';
          iVar9 = (*pcVar1)();
          iVar2 = *(int *)(param_1 + 0x18);
          QIODevice::read(param_2,(char *)local_34,(ulonglong)uVar5 << 0x20);
          (**(code **)(*(int *)param_2 + 0x40))(iVar2 + iVar9,0);
          if (local_34[0] != 1) {
            ExceptionList = local_10;
            return 0;
          }
LAB_005083f7:
          _Var12 = QIODevice::read(param_2,(char *)local_40,(ulonglong)uVar5 << 0x20);
          if (_Var12 == 0) goto LAB_00508412;
          param_1 = local_3c;
        }
        if (local_35 != '\0') {
          *param_1 = local_34[0];
          param_1[1] = local_34[1];
          param_1[2] = local_34[2];
          param_1[3] = local_34[3];
          param_1[4] = local_34[4];
          param_1[5] = local_34[5];
          param_1[6] = (short)uStack_28;
          param_1[7] = uStack_28._2_2_;
          param_1[8] = local_24;
          uVar10 = *(uint *)(param_1 + 0x18) / (uStack_28 & 0xffff);
          if (uVar10 != 0) {
            uVar11 = FUN_00519367(uVar10 * (uStack_28 & 0xffff));
            _Memory = *(void **)(param_1 + 0x12);
            *(undefined4 *)(param_1 + 0x12) = uVar11;
            if (_Memory != (void *)0x0) {
              free(_Memory);
            }
          }
          *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x18);
          QIODevice::read(param_2,*(char **)(param_1 + 0x12),(ulonglong)uVar5 << 0x20);
          ExceptionList = local_10;
          return 1;
        }
      }
LAB_005084c6:
      pQVar6 = (QString *)(**(code **)(*(int *)param_2 + 0x6c))(&local_3c);
      local_8 = 4;
      pQVar7 = (QByteArray *)QString::toLatin1(pQVar6);
      local_8 = CONCAT31(local_8._1_3_,5);
      pcVar8 = QByteArray::data(pQVar7);
      pcVar14 = "Wave file \'%s\' has no format chunk";
    }
    else {
      pQVar6 = (QString *)(**(code **)(*(int *)param_2 + 0x6c))(&local_3c);
      local_8 = 2;
      pQVar7 = (QByteArray *)QString::toLatin1(pQVar6);
      local_8 = CONCAT31(local_8._1_3_,3);
      pcVar8 = QByteArray::data(pQVar7);
      pcVar14 = "Wave file \'%s\' has no WAVE flat";
    }
    FUN_00486c20(pcVar14,pcVar8);
    QByteArray::~QByteArray((QByteArray *)&local_40);
    pQVar6 = (QString *)&local_3c;
  }
  else {
    pQVar6 = (QString *)(**(code **)(*(int *)param_2 + 0x6c))(&local_40);
    local_8 = 0;
    pQVar7 = (QByteArray *)QString::toLatin1(pQVar6);
    local_8 = CONCAT31(local_8._1_3_,1);
    pcVar8 = QByteArray::data(pQVar7);
    FUN_00486c20("Wave file \'%s\' has no RIFF flag",pcVar8);
    QByteArray::~QByteArray((QByteArray *)&local_3c);
    pQVar6 = (QString *)&local_40;
  }
LAB_0050850c:
  QString::~QString(pQVar6);
  ExceptionList = local_10;
  return 0;
}


