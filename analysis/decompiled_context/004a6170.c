
void __fastcall FUN_004a6170(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  char cVar4;
  uint uVar5;
  StandardButton SVar6;
  int iVar7;
  undefined4 uVar8;
  undefined *puVar9;
  __int64 _Var10;
  QFile local_30 [8];
  char *local_28;
  int *local_24;
  int local_20;
  undefined *local_1c;
  QString local_18 [4];
  undefined *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0052c627;
  local_10 = ExceptionList;
  uVar5 = DAT_00759b24 ^ (uint)(local_18 + 0x14);
  ExceptionList = &local_10;
  local_1c = &DAT_00755abc;
  local_14 = &DAT_00755a90;
  local_8 = 1;
  local_20 = param_1;
  SVar6 = QMessageBox::information(0,&local_14,&local_1c,0x14000,0);
  QString::~QString((QString *)&local_14);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_1c);
  if (SVar6 != 0x4000) {
    ExceptionList = local_10;
    return;
  }
  FUN_00486cd0(local_18);
  local_8 = 2;
  QMetaObject::tr((QMetaObject *)&PTR_DAT_006f875c,(char *)&local_1c,"bin/Synth.bin",0);
  local_8._0_1_ = 3;
  QString::append(local_18,(QString *)&local_1c);
  local_8._0_1_ = 2;
  QString::~QString((QString *)&local_1c);
  QFile::QFile(local_30);
  local_8._0_1_ = 4;
  iVar7 = FUN_00486ef0(local_30,local_18,1,1);
  if (iVar7 == 0) goto LAB_004a635a;
  _Var10 = QFile::size(local_30);
  local_14 = (undefined *)_Var10;
  local_28 = (char *)FUN_00519367(local_14);
  FUN_004908a0(local_28,local_20);
  local_8._0_1_ = 5;
  QIODevice::read((QIODevice *)local_30,local_28,(ulonglong)uVar5 << 0x20);
  QFileDevice::close((QFileDevice *)local_30);
  puVar3 = *(undefined **)(*(int *)(param_1 + 0x40) + 0x2ca74);
  iVar7 = FUN_00488eb0(*(undefined4 *)(*(int *)(param_1 + 0x40) + 0x2ca68));
  if (iVar7 == 0) {
LAB_004a632d:
    local_8._0_1_ = 7;
  }
  else {
    puVar2 = *(undefined4 **)(iVar7 + 0x48);
    if ((undefined *)(puVar2[3] + puVar2[2]) < local_14 + (int)puVar3) {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f875c,(char *)&local_1c,"No enough space!",0);
      local_8._0_1_ = 6;
      FUN_00486bb0(&local_1c);
      QString::~QString((QString *)&local_1c);
      goto LAB_004a632d;
    }
    puVar9 = puVar3;
    if (puVar3 < local_14 + (int)puVar3) {
      do {
        cVar4 = FUN_005063a0(*puVar2,puVar9);
        if (cVar4 == '\0') {
          FUN_00486c20("Erase 0x%.8X failed!",puVar9);
          goto LAB_004a632d;
        }
        puVar9 = puVar9 + puVar2[1];
      } while (puVar9 < local_14 + (int)puVar3);
    }
    uVar8 = FUN_005066c0(*puVar2,puVar3,local_28,local_14,0);
    switch(uVar8) {
    case 0:
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f875c,(char *)&local_20,"Write data failed !",0);
      local_8._0_1_ = 0xb;
      break;
    case 1:
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f875c,(char *)&local_20,"Successful!",0);
      local_8._0_1_ = 8;
      break;
    default:
      goto LAB_004a646c;
    case 3:
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f875c,(char *)&local_20,"Verify data failed",0);
      local_8._0_1_ = 9;
      break;
    case 4:
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f875c,(char *)&local_20,
                      "Write data time                                      out !",0);
      local_8._0_1_ = 10;
    }
    FUN_00486bb0(&local_20);
    QString::~QString((QString *)&local_20);
LAB_004a646c:
    local_8._0_1_ = 0xc;
  }
  if (local_24 != (int *)0x0) {
    LOCK();
    iVar7 = local_24[1] + -1;
    local_24[1] = iVar7;
    UNLOCK();
    if (iVar7 == 0) {
      (**(code **)(*local_24 + 4))();
      LOCK();
      piVar1 = local_24 + 2;
      iVar7 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar7 == 1) {
        (**(code **)(*local_24 + 8))();
      }
    }
  }
LAB_004a635a:
  QFile::~QFile(local_30);
  QString::~QString(local_18);
  ExceptionList = local_10;
  return;
}


