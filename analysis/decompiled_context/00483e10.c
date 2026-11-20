
void __fastcall FUN_00483e10(int param_1)

{
  int iVar1;
  QListWidgetItem *this;
  undefined4 uVar2;
  StandardButton SVar3;
  QChar aQStack_3a [2];
  QString local_24 [4];
  undefined4 local_20;
  QString local_1c [4];
  QTypedArrayData<unsigned_short> *local_18;
  undefined *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0051b459;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((*(int *)(param_1 + 0x498) == 3) && (iVar1 = FUN_00511b10(), iVar1 != 0)) {
    this = QListWidget::item(*(QListWidget **)(param_1 + 0x18),*(int *)(param_1 + 0x49c));
    QListWidgetItem::text(this);
    local_8 = 0;
    local_18 = QString::fromAscii_helper("Continue to delete song \'%1\' ?",0x1e);
    local_20 = CONCAT31(local_20._1_3_,0x20);
    local_8._0_1_ = 1;
    QChar::QChar(aQStack_3a + -10,local_20);
    uVar2 = QString::arg((QString *)&local_18,local_24,local_1c,0);
    local_14 = &DAT_00754290;
    local_8._0_1_ = 3;
    SVar3 = QMessageBox::information(0,&local_14,uVar2,0x14000);
    QString::~QString((QString *)&local_14);
    QString::~QString(local_24);
    local_8 = (uint)local_8._1_3_ << 8;
    QString::~QString((QString *)&local_18);
    if (SVar3 == 0x4000) {
      iVar1 = FUN_005119b0();
      if ((iVar1 == 0) && (iVar1 = FUN_00511b40(), iVar1 == 0)) {
        FUN_00485b60();
      }
      else {
        FUN_00484ce0();
      }
    }
    QString::~QString(local_1c);
  }
  ExceptionList = local_10;
  return;
}


