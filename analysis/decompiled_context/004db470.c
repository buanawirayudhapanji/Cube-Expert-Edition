
void __fastcall FUN_004db470(int param_1)

{
  char cVar1;
  QListWidgetItem *this;
  undefined4 uVar2;
  StandardButton SVar3;
  int iVar4;
  undefined4 uVar5;
  QChar aQStack_62 [2];
  undefined4 local_2c;
  int local_28;
  QString local_24 [4];
  QTypedArrayData<unsigned_short> *local_20;
  QTypedArrayData<unsigned_short> *local_1c;
  undefined *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0051b521;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 0x48c) == 3) {
    if ((*(uint *)(param_1 + 0x490) <
         (uint)(*(int *)(param_1 + 0x458) - *(int *)(param_1 + 0x454) >> 2)) &&
       (*(int *)(*(int *)(*(int *)(param_1 + 0x454) + *(uint *)(param_1 + 0x490) * 4) + 0x34) != 0))
    {
      local_1c = QString::fromAscii_helper
                           ("\'%1\' already exist, continue to overwrite the song?",0x33);
      local_8 = 0;
      this = QListWidget::item(*(QListWidget **)(param_1 + 0x28),*(int *)(param_1 + 0x490));
      uVar2 = QListWidgetItem::text(this);
      local_20 = (QTypedArrayData<unsigned_short> *)CONCAT31(local_20._1_3_,0x20);
      local_8._0_1_ = 1;
      QChar::QChar(aQStack_62 + -10,local_20);
      uVar2 = QString::arg((QString *)&local_1c,&local_28,uVar2,0);
      local_18 = &DAT_00755f58;
      local_8 = CONCAT31(local_8._1_3_,3);
      SVar3 = QMessageBox::information(0,&local_18,uVar2,0x14000);
      QString::~QString((QString *)&local_18);
      QString::~QString((QString *)&local_28);
      QString::~QString((QString *)&local_2c);
      local_8 = 0xffffffff;
      QString::~QString((QString *)&local_1c);
      if (SVar3 != 0x4000) {
        ExceptionList = local_10;
        return;
      }
    }
    local_1c = QString::fromAscii_helper("/Config/WavLoadDir",0x12);
    local_8 = 4;
    FUN_00484be0(local_24);
    QString::~QString((QString *)&local_1c);
    local_18 = &DAT_00755fb8;
    local_1c = (QTypedArrayData<unsigned_short> *)&DAT_00755f8c;
    local_8._0_1_ = 8;
    QFileDialog::getOpenFileName(&local_14,param_1,&local_1c,local_24,&local_18,0);
    QString::~QString((QString *)&local_1c);
    local_8._0_1_ = 0xb;
    QString::~QString((QString *)&local_18);
    if (*(int *)(local_14 + 4) != 0) {
      iVar4 = FUN_00488eb0();
      local_28 = *(int *)(iVar4 + 0x44);
      FUN_004876a0(&local_2c,&local_14);
      local_8._0_1_ = 0xc;
      local_20 = QString::fromAscii_helper("/Config/WavLoadDir",0x12);
      local_8._0_1_ = 0xd;
      FUN_00485f80(&local_20);
      QString::~QString((QString *)&local_20);
      local_8._0_1_ = 0xb;
      QString::~QString((QString *)&local_2c);
      local_2c = *(undefined4 *)(param_1 + 0x490);
      cVar1 = FUN_0050a930();
      if (cVar1 == '\0') {
        local_20 = (QTypedArrayData<unsigned_short> *)&DAT_00755fec;
        local_8._0_1_ = 0xe;
        FUN_00486bb0();
        QString::~QString((QString *)&local_20);
      }
      else {
        QProgressBar::setValue(*(QProgressBar **)(param_1 + 0x20),0);
        QWidget::show(*(QWidget **)(param_1 + 0x20));
        *(undefined4 *)(param_1 + 0x48c) = 1;
        FUN_0050aff0(*(undefined4 *)(local_28 + 0x20),*(undefined4 *)(local_28 + 0x1c));
        uVar2 = FUN_0050a640();
        uVar5 = FUN_0050a630();
        FUN_004dd540(*(undefined4 *)(param_1 + 0x490),uVar5,uVar2);
        FUN_004dc350();
        FUN_004dc100();
        FUN_004dd2e0();
        QWidget::hide(*(QWidget **)(param_1 + 0x20));
        *(undefined4 *)(param_1 + 0x48c) = 3;
      }
    }
    QString::~QString((QString *)&local_14);
    QString::~QString(local_24);
  }
  ExceptionList = local_10;
  return;
}


