
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __thiscall FUN_00505530(int param_1,QString *param_2,char param_3)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  QTypedArrayData<unsigned_short> *pQVar5;
  uint *puVar6;
  undefined4 uVar7;
  uint *puVar8;
  undefined8 local_78;
  QVariant local_70 [8];
  uint local_68;
  uint local_64;
  uint *local_60;
  uint *local_5c;
  uint *local_58;
  int local_54;
  uint local_50;
  uint local_4c;
  int local_48;
  QString local_44 [4];
  int local_40;
  QTypedArrayData<unsigned_short> *local_3c;
  undefined4 *local_38;
  uint *local_34;
  QString local_30 [4];
  uint *local_2c;
  int local_28;
  uint local_24;
  QTypedArrayData<unsigned_short> *local_20;
  QTypedArrayData<unsigned_short> *local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054d1b9;
  local_10 = ExceptionList;
  uVar3 = DAT_00759b24 ^ (uint)(local_30 + 0x2c);
  ExceptionList = &local_10;
  local_48 = 1;
  local_28 = param_1;
  local_14 = uVar3;
  QProgressBar::setValue(*(QProgressBar **)(param_1 + 0x34),0);
  QWidget::show(*(QWidget **)(param_1 + 0x34));
  *(undefined4 *)(param_1 + 0x50) = 2;
  local_40 = param_1 + 100;
  iVar4 = FUN_005014d0(param_2);
  if (iVar4 == 0) {
    FUN_00486bb0(param_1 + 100,uVar3);
    goto LAB_00505ad8;
  }
  iVar4 = *(int *)(param_1 + 0x4c);
  iVar1 = *(int *)(iVar4 + 0x2ca78);
  local_3c = *(QTypedArrayData<unsigned_short> **)(iVar4 + 0x2ca68);
  local_78 = *(undefined8 *)(iVar4 + 0x2ca84);
  if ((((local_3c != (QTypedArrayData<unsigned_short> *)0xffffffff) &&
       (pQVar5 = (QTypedArrayData<unsigned_short> *)FUN_00501450(), pQVar5 != local_3c)) &&
      (puVar6 = (uint *)QGuiApplication::queryKeyboardModifiers(), (*puVar6 & 0x2000000) == 0)) &&
     ((*(char *)(param_1 + 0x105) == '\0' && (param_3 == '\0')))) {
    FUN_00486c20("File not match the connected device,please confirm");
    ExceptionList = local_10;
    return false;
  }
  QString::QString(local_44);
  local_8 = 0;
  FUN_00487760(param_2,local_44);
  local_34 = (uint *)&DAT_00756924;
  local_8._0_1_ = 1;
  FUN_004f6850(local_30,local_44,&local_34);
  QString::~QString((QString *)&local_34);
  puVar6 = (uint *)0x0;
  local_2c = (uint *)0x0;
  local_60 = (uint *)0x0;
  local_5c = (uint *)0x0;
  local_34 = (uint *)0x0;
  local_58 = (uint *)0x0;
  local_8._0_1_ = 4;
  uVar7 = FUN_00486cd0(&local_20);
  local_8._0_1_ = 5;
  FUN_004f68c0(&local_18,uVar7,"~calcTemp.ini");
  local_8 = CONCAT31(local_8._1_3_,7);
  QString::~QString((QString *)&local_20);
  uVar3 = 0;
  if (*(int *)(local_28 + 0x68) == 0) {
    puVar8 = (uint *)0x0;
  }
  else {
    do {
      iVar4 = FUN_005011c0(uVar3,&local_38);
      if (iVar4 != 0) {
        FUN_00487330(&local_18,iVar4,local_38);
      }
      FUN_005100e0();
      local_8._0_1_ = 8;
      cVar2 = FUN_005102f0(&local_18);
      if (cVar2 == '\0') {
        QString::QString((QString *)&local_1c,(QString *)((int)&local_78 + 4));
        local_8._0_1_ = 9;
        FUN_00486bb0(&local_1c);
        QString::~QString((QString *)&local_1c);
        FUN_00510180();
        local_8 = CONCAT31(local_8._1_3_,4);
        QString::~QString((QString *)&local_18);
        local_2c = local_60;
        puVar8 = local_60;
        goto LAB_005057a0;
      }
      local_64 = *(uint *)(iVar1 + 4);
      local_68 = uVar3;
      if (puVar6 == local_34) {
        FUN_005016c0(puVar6,&local_68);
        local_34 = local_58;
      }
      else {
        *puVar6 = uVar3;
        puVar6[1] = local_64;
        local_5c = puVar6 + 2;
      }
      puVar6 = local_5c;
      local_8 = CONCAT31(local_8._1_3_,7);
      FUN_00510180();
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(local_28 + 0x68));
    local_2c = local_60;
    puVar8 = local_60;
  }
  FUN_00487af0(&local_18);
  local_8 = CONCAT31(local_8._1_3_,4);
  QString::~QString((QString *)&local_18);
LAB_005057a0:
  local_20 = (QTypedArrayData<unsigned_short> *)((uint)local_20 & 0xffffff00);
  FUN_00501bb0(puVar8,puVar6,(int)puVar6 - (int)puVar8 >> 3,local_20);
  uVar7 = QVariant::QVariant(local_70,param_2);
  local_8._0_1_ = 10;
  local_1c = QString::fromAscii_helper("/Config/UpdateNotFinishedPath",0x1d);
  local_8._0_1_ = 0xb;
  FUN_00487c00(&local_1c,uVar7);
  QString::~QString((QString *)&local_1c);
  local_8 = CONCAT31(local_8._1_3_,4);
  QVariant::~QVariant(local_70);
  for (puVar8 = local_2c; puVar8 != puVar6; puVar8 = puVar8 + 2) {
    iVar4 = FUN_005011c0(*puVar8,&local_24);
    if (iVar4 != 0) {
      FUN_00487330(local_30,iVar4,local_24);
    }
    iVar4 = FUN_00501270(*puVar8,&local_24);
    if (iVar4 == 0) goto LAB_00505aa5;
    local_4c = local_24;
    FUN_005100e0();
    local_8._0_1_ = 0xc;
    cVar2 = FUN_005102f0(local_30);
    if (cVar2 == '\0') {
      QString::QString((QString *)&local_20,(QString *)((int)&local_78 + 4));
      local_8._0_1_ = 0xd;
      FUN_00486bb0(&local_20);
      QString::~QString((QString *)&local_20);
LAB_00505a99:
      local_8 = CONCAT31(local_8._1_3_,4);
      FUN_00510180();
      goto LAB_00505aa5;
    }
    if ((uint)local_78 < local_4c) {
      FUN_00486c20("Space not enough !");
      goto LAB_00505a99;
    }
    local_64 = FUN_005102a0(local_4c);
    local_18 = 0;
    local_50 = 0;
    if (local_64 != 0) {
      local_54 = 0;
      local_1c = (QTypedArrayData<unsigned_short> *)0x50;
      do {
        local_38 = (undefined4 *)(iVar1 + local_54);
        cVar2 = FUN_005063a0(*local_38,local_38[1]);
        if (cVar2 == '\0') {
          FUN_00486c20("Erase sector failed,address=0x%.8X",local_38[1]);
          goto LAB_00505a99;
        }
        local_18 = local_18 + local_38[2];
        QProgressBar::setValue(*(QProgressBar **)(local_28 + 0x34),(uint)local_1c / local_64);
        FUN_00487020();
        if (local_4c <= local_18) break;
        local_50 = local_50 + 1;
        local_1c = local_1c + 0x50;
        local_54 = local_54 + 0xc;
      } while (local_50 < local_64);
    }
    local_8 = CONCAT31(local_8._1_3_,4);
    FUN_00510180();
  }
  if (puVar6 != local_2c) {
    do {
      puVar6 = puVar6 + -2;
      iVar4 = FUN_005011c0(*puVar6,&local_24);
      if (iVar4 != 0) {
        FUN_00487330(local_30,iVar4,local_24);
      }
      iVar4 = FUN_00501270(*puVar6,&local_24);
      if ((iVar4 == 0) || (iVar4 = FUN_00505320(local_30,iVar4,local_24), iVar4 == 0))
      goto LAB_00505aa5;
    } while (puVar6 != local_2c);
  }
  if ((local_3c == (QTypedArrayData<unsigned_short> *)0x272a) ||
     (iVar4 = FUN_00501450(), iVar4 == 0x272a)) {
    FUN_005071b0(0);
    thunk_FUN_00508160();
  }
  goto LAB_005059ab;
LAB_00505aa5:
  local_48 = 0;
LAB_005059ab:
  local_20 = QString::fromAscii_helper("",0);
  local_8._0_1_ = 0xe;
  uVar7 = QVariant::QVariant(local_70,(QString *)&local_20);
  local_8._0_1_ = 0xf;
  local_3c = QString::fromAscii_helper("/Config/UpdateNotFinishedPath",0x1d);
  local_8._0_1_ = 0x10;
  FUN_00487c00(&local_3c,uVar7);
  QString::~QString((QString *)&local_3c);
  QVariant::~QVariant(local_70);
  local_8 = CONCAT31(local_8._1_3_,4);
  QString::~QString((QString *)&local_20);
  FUN_00487af0(local_30);
  if (local_2c != (uint *)0x0) {
    uVar3 = (int)local_34 - (int)local_2c & 0xfffffff8;
    puVar6 = local_2c;
    if (0xfff < uVar3) {
      puVar6 = (uint *)local_2c[-1];
      uVar3 = uVar3 + 0x23;
      if (0x1f < (uint)((int)local_2c + (-4 - (int)puVar6))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
    FUN_00519359(puVar6,uVar3);
  }
  QString::~QString(local_30);
  QString::~QString(local_44);
LAB_00505ad8:
  ExceptionList = local_10;
  return local_48 != 0;
}


