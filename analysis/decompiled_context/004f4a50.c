
void __thiscall FUN_004f4a50(QObject *param_1,int param_2)

{
  QObject QVar1;
  char cVar2;
  uint uVar3;
  QObject *pQVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005308ae;
  local_10 = ExceptionList;
  uVar3 = DAT_00759b24 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  pQVar4 = QObject::sender(param_1);
  iVar5 = QComboBox::currentIndex(*(QComboBox **)(param_1 + 0x11f4));
  QVar1 = param_2._0_1_;
  if (pQVar4 == *(QObject **)(param_1 + 0x11b4)) {
    param_1[0x1b] = param_2._0_1_;
    cVar2 = FUN_00506590(4,3,param_1 + 0x1b,1,0);
    if (cVar2 == '\0') {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7c3c,(char *)&param_2,"Write data failed !",0);
      local_8 = 0;
      FUN_00486bb0(&param_2,uVar3);
      QString::~QString((QString *)&param_2);
      ExceptionList = local_10;
      return;
    }
    ExceptionList = local_10;
    return;
  }
  if (pQVar4 == *(QObject **)(param_1 + 0x1150)) {
    param_1 = param_1 + 0x22;
    uVar7 = 1;
    iVar5 = 10;
    *param_1 = param_2._0_1_;
    uVar6 = 4;
  }
  else if (pQVar4 == *(QObject **)(param_1 + 0x1160)) {
    param_1 = param_1 + 0x23;
    uVar7 = 1;
    iVar5 = 0xb;
    *param_1 = param_2._0_1_;
    uVar6 = 4;
  }
  else if (pQVar4 == *(QObject **)(param_1 + 0x1170)) {
    param_1 = param_1 + 0x28;
    uVar7 = 2;
    iVar5 = 0x10;
    *(undefined2 *)param_1 = (undefined2)param_2;
    uVar6 = 4;
  }
  else {
    if (pQVar4 == *(QObject **)(param_1 + 0x1284)) {
      param_1 = param_1 + iVar5 * 0x1da + 0x2d;
      *param_1 = param_2._0_1_;
      iVar5 = iVar5 * 0x1da + 1;
    }
    else if (pQVar4 == *(QObject **)(param_1 + 0x1290)) {
      param_1 = param_1 + iVar5 * 0x1da + 0x2e;
      *param_1 = param_2._0_1_;
      iVar5 = iVar5 * 0x1da + 2;
    }
    else if (pQVar4 == *(QObject **)(param_1 + 0x12a0)) {
      param_1 = param_1 + iVar5 * 0x1da + 0x2f;
      *param_1 = param_2._0_1_;
      iVar5 = iVar5 * 0x1da + 3;
    }
    else if (pQVar4 == *(QObject **)(param_1 + 0x12a4)) {
      param_1 = param_1 + iVar5 * 0x1da + 0x30;
      *param_1 = param_2._0_1_;
      iVar5 = iVar5 * 0x1da + 4;
    }
    else if (pQVar4 == *(QObject **)(param_1 + 0x1324)) {
      QLabel::setText(*(QLabel **)(param_1 + 0x132c),(QString *)(&DAT_007636d8 + param_2 * 4));
      param_1 = param_1 + iVar5 * 0x1da + 0x1fe;
      *param_1 = QVar1;
      iVar5 = iVar5 * 0x1da + 0x1d2;
    }
    else if (pQVar4 == *(QObject **)(param_1 + 0x1310)) {
      param_1 = param_1 + iVar5 * 0x1da + 0x1ff;
      *param_1 = param_2._0_1_;
      iVar5 = iVar5 * 0x1da + 0x1d3;
    }
    else if (pQVar4 == *(QObject **)(param_1 + 0x12e0)) {
      param_1 = param_1 + iVar5 * 0x1da + 0x200;
      *param_1 = param_2._0_1_;
      iVar5 = iVar5 * 0x1da + 0x1d4;
    }
    else if (pQVar4 == *(QObject **)(param_1 + 0x12f4)) {
      param_1 = param_1 + iVar5 * 0x1da + 0x203;
      *param_1 = param_2._0_1_;
      iVar5 = iVar5 * 0x1da + 0x1d7;
    }
    else if (pQVar4 == *(QObject **)(param_1 + 0x12f0)) {
      param_1 = param_1 + iVar5 * 0x1da + 0x204;
      *param_1 = param_2._0_1_;
      iVar5 = iVar5 * 0x1da + 0x1d8;
    }
    else {
      if (pQVar4 != *(QObject **)(param_1 + 0x1304)) {
        ExceptionList = local_10;
        return;
      }
      param_1 = param_1 + iVar5 * 0x1da + 0x205;
      *param_1 = param_2._0_1_;
      iVar5 = iVar5 * 0x1da + 0x1d9;
    }
    uVar7 = 1;
    uVar6 = 5;
  }
  FUN_004f49c0(uVar6,iVar5,param_1,uVar7);
  ExceptionList = local_10;
  return;
}


