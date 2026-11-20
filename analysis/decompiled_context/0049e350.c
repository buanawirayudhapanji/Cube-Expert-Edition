
void __fastcall FUN_0049e350(QWidget *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *piVar4;
  QWidget *pQVar5;
  char cVar6;
  uint uVar7;
  StandardButton SVar8;
  int iVar9;
  int iVar10;
  __int64 _Var11;
  QFile local_2c [8];
  undefined *local_24;
  char *local_20;
  int *local_1c;
  QWidget *local_18;
  QString local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0052a10c;
  local_10 = ExceptionList;
  uVar7 = DAT_00759b24 ^ (uint)(local_14 + 0x10);
  ExceptionList = &local_10;
  local_24 = &DAT_00755904;
  local_1c = &DAT_007558d8;
  local_8 = 1;
  local_18 = param_1;
  SVar8 = QMessageBox::information(0,&local_1c,&local_24,0x14000,0);
  QString::~QString((QString *)&local_1c);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_24);
  if (SVar8 == 0x4000) {
    iVar9 = *(int *)(param_1 + 0xf8);
    uVar3 = *(uint *)(iVar9 + 0x2ca74);
    iVar10 = *(int *)(iVar9 + 0x2ca68);
    iVar9 = FUN_00488eb0(*(undefined4 *)(iVar9 + 0x2ca68));
    FUN_00486cd0(local_14);
    local_8._0_1_ = 2;
    local_8._1_3_ = 0;
    if (iVar9 != 0) {
      if (iVar10 == 0x4f09) {
        QMetaObject::tr((QMetaObject *)&PTR_DAT_006f8778,(char *)&local_24,"bin/MICRORIG.bin",0);
        local_8._0_1_ = 3;
      }
      else {
        QMetaObject::tr((QMetaObject *)&PTR_DAT_006f8778,(char *)&local_24,"bin/BFI.bin",0);
        local_8._0_1_ = 4;
      }
      QString::append(local_14,(QString *)&local_24);
      local_8._0_1_ = 2;
      QString::~QString((QString *)&local_24);
      QFile::QFile(local_2c);
      local_8._0_1_ = 5;
      iVar10 = FUN_00486ef0(local_2c,local_14,1,1);
      if (iVar10 != 0) {
        _Var11 = QFile::size(local_2c);
        local_20 = (char *)FUN_00519367((int)_Var11);
        FUN_004908a0(local_20,local_24);
        local_8._0_1_ = 6;
        QIODevice::read((QIODevice *)local_2c,local_20,(ulonglong)uVar7 << 0x20);
        QFileDevice::close((QFileDevice *)local_2c);
        puVar2 = *(undefined4 **)(iVar9 + 0x48);
        if ((uint)(puVar2[3] + puVar2[2]) < uVar3 + 0x8000) {
          QMetaObject::tr((QMetaObject *)&PTR_DAT_006f8778,(char *)&local_24,"No enough space!",0);
          local_8._0_1_ = 7;
          FUN_00486bb0(&local_24);
          QString::~QString((QString *)&local_24);
LAB_0049e62a:
          local_8._0_1_ = 8;
        }
        else {
          uVar7 = uVar3;
          if (uVar3 < uVar3 + 0x8000) {
            do {
              cVar6 = FUN_005063a0(*puVar2,uVar7);
              if (cVar6 == '\0') {
                FUN_00486c20("Erase 0x%.8X failed!",uVar7);
                goto LAB_0049e62a;
              }
              uVar7 = uVar7 + puVar2[1];
            } while (uVar7 < uVar3 + 0x8000);
          }
          pQVar5 = local_18;
          QWidget::show(*(QWidget **)(local_18 + 0x38));
          QWidget::setDisabled(pQVar5,true);
          pQVar5 = local_18;
          FUN_004a3330(*puVar2,uVar3,local_20 + 0x9000,0x8000);
          QWidget::hide(*(QWidget **)(pQVar5 + 0x38));
          QWidget::setDisabled(pQVar5,false);
          local_8._0_1_ = 9;
        }
        piVar4 = local_1c;
        if (local_1c != (int *)0x0) {
          LOCK();
          iVar9 = local_1c[1] + -1;
          local_1c[1] = iVar9;
          UNLOCK();
          if (iVar9 == 0) {
            (**(code **)(*local_1c + 4))();
            LOCK();
            piVar1 = piVar4 + 2;
            iVar9 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar9 == 1) {
              (**(code **)(*piVar4 + 8))();
            }
          }
        }
      }
      QFile::~QFile(local_2c);
    }
    QString::~QString(local_14);
  }
  ExceptionList = local_10;
  return;
}


