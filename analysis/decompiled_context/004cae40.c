
void __fastcall FUN_004cae40(QWidget *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  QWidget *pQVar4;
  char cVar5;
  uint uVar6;
  StandardButton SVar7;
  int iVar8;
  uint uVar9;
  __int64 _Var10;
  QFile local_2c [8];
  undefined *local_24;
  char *local_20;
  int *local_1c;
  QString local_18 [4];
  QWidget *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00526593;
  local_10 = ExceptionList;
  uVar6 = DAT_00759b24 ^ (uint)(local_18 + 0x14);
  ExceptionList = &local_10;
  local_24 = &DAT_00755b50;
  local_1c = &DAT_00755b24;
  local_8 = 1;
  local_14 = param_1;
  SVar7 = QMessageBox::information(0,&local_1c,&local_24,0x14000,0);
  QString::~QString((QString *)&local_1c);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_24);
  if (SVar7 != 0x4000) {
    ExceptionList = local_10;
    return;
  }
  FUN_00486cd0(local_18);
  local_8 = 2;
  QMetaObject::tr((QMetaObject *)&PTR_DAT_006f8264,(char *)&local_24,"bin/H8.bin",0);
  local_8._0_1_ = 3;
  QString::append(local_18,(QString *)&local_24);
  local_8._0_1_ = 2;
  QString::~QString((QString *)&local_24);
  QFile::QFile(local_2c);
  local_8._0_1_ = 4;
  iVar8 = FUN_00486ef0(local_2c,local_18,1,1);
  if (iVar8 == 0) goto LAB_004cb031;
  _Var10 = QFile::size(local_2c);
  local_20 = (char *)FUN_00519367((int)_Var10);
  FUN_004908a0(local_20,local_24);
  local_8._0_1_ = 5;
  QIODevice::read((QIODevice *)local_2c,local_20,(ulonglong)uVar6 << 0x20);
  QFileDevice::close((QFileDevice *)local_2c);
  uVar6 = *(uint *)(*(int *)(param_1 + 200) + 0x2ca74);
  iVar8 = FUN_00488eb0(*(undefined4 *)(*(int *)(param_1 + 200) + 0x2ca68));
  if (iVar8 == 0) {
LAB_004cb004:
    local_8._0_1_ = 7;
  }
  else {
    puVar2 = *(undefined4 **)(iVar8 + 0x48);
    if ((uint)(puVar2[3] + puVar2[2]) < uVar6 + 0xa000) {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f8264,(char *)&local_24,"No enough space!",0);
      local_8._0_1_ = 6;
      FUN_00486bb0(&local_24);
      QString::~QString((QString *)&local_24);
      goto LAB_004cb004;
    }
    uVar9 = uVar6;
    if (uVar6 < uVar6 + 0xa000) {
      do {
        cVar5 = FUN_005063a0(*puVar2,uVar9);
        if (cVar5 == '\0') {
          FUN_00486c20("Erase 0x%.8X failed!",uVar9);
          goto LAB_004cb004;
        }
        uVar9 = uVar9 + puVar2[1];
      } while (uVar9 < uVar6 + 0xa000);
    }
    pQVar4 = local_14;
    QWidget::show(*(QWidget **)(local_14 + 0x38));
    QWidget::setDisabled(pQVar4,true);
    pQVar4 = local_14;
    FUN_004ceba0(*puVar2,uVar6,local_20 + 0xa000,0xa000);
    QWidget::hide(*(QWidget **)(pQVar4 + 0x38));
    QWidget::setDisabled(pQVar4,false);
    local_8._0_1_ = 8;
  }
  piVar3 = local_1c;
  if (local_1c != (int *)0x0) {
    LOCK();
    iVar8 = local_1c[1] + -1;
    local_1c[1] = iVar8;
    UNLOCK();
    if (iVar8 == 0) {
      (**(code **)(*local_1c + 4))();
      LOCK();
      piVar1 = piVar3 + 2;
      iVar8 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar8 == 1) {
        (**(code **)(*piVar3 + 8))();
      }
    }
  }
LAB_004cb031:
  QFile::~QFile(local_2c);
  QString::~QString(local_18);
  ExceptionList = local_10;
  return;
}


