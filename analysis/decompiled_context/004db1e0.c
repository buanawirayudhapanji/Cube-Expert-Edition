
void __fastcall FUN_004db1e0(int param_1)

{
  uint uVar1;
  QListWidgetItem *this;
  undefined4 uVar2;
  StandardButton SVar3;
  int iVar4;
  QChar aQStack_36 [2];
  QString local_24 [4];
  undefined4 local_20;
  QString local_1c [4];
  QTypedArrayData<unsigned_short> *local_18;
  undefined *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0053d279;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 0x48c) == 3) {
    uVar1 = *(uint *)(param_1 + 0x490);
    if ((uVar1 < (uint)(*(int *)(param_1 + 0x458) - *(int *)(param_1 + 0x454) >> 2)) &&
       (*(int *)(*(int *)(*(int *)(param_1 + 0x454) + uVar1 * 4) + 0x34) != 0)) {
      this = QListWidget::item(*(QListWidget **)(param_1 + 0x28),uVar1);
      QListWidgetItem::text(this);
      local_8 = 0;
      local_18 = QString::fromAscii_helper("Continue to delete song \'%1\' ?",0x1e);
      local_20 = CONCAT31(local_20._1_3_,0x20);
      local_8._0_1_ = 1;
      QChar::QChar(aQStack_36 + -10,local_20);
      uVar2 = QString::arg((QString *)&local_18,local_24,local_1c,0);
      local_14 = &DAT_00756064;
      local_8._0_1_ = 3;
      SVar3 = QMessageBox::information(0,&local_14,uVar2,0x14000);
      QString::~QString((QString *)&local_14);
      QString::~QString(local_24);
      local_8 = (uint)local_8._1_3_ << 8;
      QString::~QString((QString *)&local_18);
      if (SVar3 == 0x4000) {
        if (((uVar1 < (uint)(*(int *)(param_1 + 0x458) - *(int *)(param_1 + 0x454) >> 2)) &&
            (iVar4 = FUN_004dd880(), iVar4 == 0)) && (iVar4 = FUN_004dc100(), iVar4 == 0)) {
          FUN_004dd2e0();
        }
        else {
          FUN_004dc350();
        }
      }
      QString::~QString(local_1c);
    }
  }
  ExceptionList = local_10;
  return;
}


