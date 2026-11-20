
void __fastcall FUN_00496b80(QWidget *param_1)

{
  char cVar1;
  uint uVar2;
  StandardButton SVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  QWidget *this;
  bool bVar7;
  __int64 _Var8;
  int *local_2c;
  QFile local_28 [8];
  undefined *local_20;
  int *local_1c;
  QString local_18 [4];
  QWidget *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00527e6e;
  local_10 = ExceptionList;
  uVar2 = DAT_00759b24 ^ (uint)(local_18 + 0x14);
  ExceptionList = &local_10;
  local_20 = &DAT_007557dc;
  local_1c = (int *)&DAT_007557b0;
  local_8 = 1;
  local_14 = param_1;
  SVar3 = QMessageBox::information(0,&local_1c,&local_20,0x14000,0);
  QString::~QString((QString *)&local_1c);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_20);
  if (SVar3 == 0x4000) {
    iVar4 = FUN_00488eb0(*(undefined4 *)(*(int *)(param_1 + 0x4038) + 0x2ca68));
    FUN_00486cd0(local_18);
    local_8._0_1_ = 2;
    local_8._1_3_ = 0;
    if (iVar4 != 0) {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f8c30,(char *)&local_20,"bin/FFFFX.bin",0);
      local_8._0_1_ = 3;
      QString::append(local_18,(QString *)&local_20);
      local_8._0_1_ = 2;
      QString::~QString((QString *)&local_20);
      QFile::QFile(local_28);
      local_8._0_1_ = 4;
      iVar4 = FUN_00486ef0(local_28,local_18,1,1);
      if (iVar4 != 0) {
        _Var8 = QFile::size(local_28);
        piVar5 = (int *)FUN_00519367((int)_Var8);
        FUN_004908a0(piVar5,local_20);
        local_8 = CONCAT31(local_8._1_3_,5);
        QIODevice::read((QIODevice *)local_28,(char *)piVar5,(ulonglong)uVar2 << 0x20);
        QFileDevice::close((QFileDevice *)local_28);
        uVar2 = 0x20000000;
        do {
          cVar1 = FUN_005063a0(4,uVar2);
          this = local_14;
          if (cVar1 == '\0') {
            FUN_00486c20("Erase 0x%.8X failed!",uVar2);
            local_8._0_1_ = 6;
            goto LAB_00496ea1;
          }
          uVar2 = uVar2 + 0x1000;
        } while (uVar2 < 0x20011800);
        QWidget::setDisabled(local_14,true);
        cVar1 = FUN_00506590(4,0x20000000,piVar5,0x11800,this);
        if (cVar1 == '\0') {
          QMetaObject::tr((QMetaObject *)&PTR_DAT_006f8c30,(char *)&local_20,"Write data failed !",0
                         );
          local_8._0_1_ = 10;
          FUN_00486bb0(&local_20);
          local_8 = CONCAT31(local_8._1_3_,5);
          QString::~QString((QString *)&local_20);
        }
        else {
          local_1c = (int *)FUN_00519367(0x11800);
          cVar1 = FUN_005063f0(4,0x20000000,local_1c,0x11800,this);
          if (cVar1 == '\0') {
            QMetaObject::tr((QMetaObject *)&PTR_DAT_006f8c30,(char *)&local_20,
                            "Read verify data failed !",0);
            local_8._0_1_ = 9;
            FUN_00486bb0(&local_20);
            local_8 = CONCAT31(local_8._1_3_,5);
            QString::~QString((QString *)&local_20);
            free(local_1c);
          }
          else {
            uVar2 = 0x117fc;
            piVar6 = local_1c;
            do {
              if (*piVar5 != *piVar6) {
                QMetaObject::tr((QMetaObject *)&PTR_DAT_006f8c30,(char *)&local_20,
                                "Verify data failed !",0);
                local_8._0_1_ = 8;
                goto LAB_00496ddd;
              }
              piVar5 = piVar5 + 1;
              piVar6 = piVar6 + 1;
              bVar7 = 3 < uVar2;
              uVar2 = uVar2 - 4;
            } while (bVar7);
            QMetaObject::tr((QMetaObject *)&PTR_DAT_006f8c30,(char *)&local_20,"Successful!",0);
            local_8._0_1_ = 7;
LAB_00496ddd:
            FUN_00486bb0(&local_20);
            local_8 = CONCAT31(local_8._1_3_,5);
            QString::~QString((QString *)&local_20);
            this = local_14;
            free(local_1c);
          }
        }
        QWidget::setDisabled(this,false);
        local_8._0_1_ = 0xb;
LAB_00496ea1:
        if (local_2c != (int *)0x0) {
          LOCK();
          iVar4 = local_2c[1] + -1;
          local_2c[1] = iVar4;
          UNLOCK();
          if (iVar4 == 0) {
            (**(code **)(*local_2c + 4))();
            LOCK();
            piVar5 = local_2c + 2;
            iVar4 = *piVar5;
            *piVar5 = *piVar5 + -1;
            UNLOCK();
            if (iVar4 == 1) {
              (**(code **)(*local_2c + 8))();
            }
          }
        }
      }
      QFile::~QFile(local_28);
    }
    QString::~QString(local_18);
  }
  ExceptionList = local_10;
  return;
}


