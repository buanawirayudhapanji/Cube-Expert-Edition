
void __fastcall FUN_004d2a50(int *param_1)

{
  QListWidget *this;
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  QVariant *this_00;
  undefined4 *puVar4;
  void **ppvVar5;
  QString *pQVar6;
  QStringList *pQVar7;
  int iVar8;
  char *pcVar9;
  undefined4 uVar10;
  QVariant local_5c [16];
  QVariant local_4c [16];
  QVariant local_3c [16];
  QString local_2c [4];
  QString local_28 [4];
  undefined1 local_24 [4];
  QTypedArrayData<unsigned_short> *local_20;
  QTypedArrayData<unsigned_short> *local_1c;
  QTypedArrayData<unsigned_short> *local_18;
  QString local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00526636;
  local_10 = ExceptionList;
  uVar2 = DAT_00759b24 ^ (uint)(local_14 + 0x10);
  ExceptionList = &local_10;
  local_1c = QString::fromAscii_helper("Wav Files(*.wav)",0x10);
  local_8 = 0;
  uVar3 = QVariant::QVariant(local_5c);
  uVar10 = 0x11;
  pcVar9 = "/Config/ConvIRDir";
  local_8._0_1_ = 1;
  local_18 = QString::fromAscii_helper("/Config/ConvIRDir",0x11);
  local_8._0_1_ = 2;
  this_00 = (QVariant *)FUN_00487a10(local_4c,&local_18,uVar3,pcVar9,uVar10,uVar2);
  local_8._0_1_ = 3;
  uVar3 = QVariant::toString(this_00);
  local_8._0_1_ = 4;
  QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7250,(char *)local_14,"Open IR wav sample files",0);
  local_8 = CONCAT31(local_8._1_3_,5);
  puVar4 = (undefined4 *)
           QFileDialog::getOpenFileNames(local_24,*param_1,local_14,uVar3,&local_1c,0,0);
  iVar8 = *param_1;
  uVar3 = *puVar4;
  *puVar4 = shared_null_exref;
  local_20 = *(QTypedArrayData<unsigned_short> **)(iVar8 + 0x2a4);
  *(undefined4 *)(iVar8 + 0x2a4) = uVar3;
  FUN_00486b10();
  FUN_00486b10();
  QString::~QString(local_14);
  QString::~QString(local_28);
  QVariant::~QVariant(local_4c);
  QString::~QString((QString *)&local_18);
  QVariant::~QVariant(local_5c);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_1c);
  bVar1 = QListData::isEmpty((QListData *)(*param_1 + 0x2a4));
  if (!bVar1) {
    iVar8 = *param_1;
    if ((**(int **)(iVar8 + 0x2a4) != 1) && (**(int **)(iVar8 + 0x2a4) != 0)) {
      FUN_004875a0(*(undefined4 *)(*(int *)(iVar8 + 0x2a4) + 4));
    }
    ppvVar5 = QListData::at((QListData *)(iVar8 + 0x2a4),0);
    pQVar6 = (QString *)FUN_004876a0(local_2c,ppvVar5);
    local_8 = 6;
    QVariant::QVariant(local_3c,pQVar6);
    local_8._0_1_ = 7;
    local_20 = QString::fromAscii_helper("/Config/ConvIRDir",0x11);
    local_8 = CONCAT31(local_8._1_3_,8);
    FUN_00487c00(&local_20,local_3c);
    QString::~QString((QString *)&local_20);
    QVariant::~QVariant(local_3c);
    local_8 = 0xffffffff;
    QString::~QString(local_2c);
    QListWidget::clear(*(QListWidget **)(*param_1 + 0x148));
    this = *(QListWidget **)(*param_1 + 0x148);
    pQVar7 = (QStringList *)(*param_1 + 0x2a4);
    iVar8 = QListWidget::count(this);
    QListWidget::insertItems(this,iVar8,pQVar7);
  }
  ExceptionList = local_10;
  return;
}


