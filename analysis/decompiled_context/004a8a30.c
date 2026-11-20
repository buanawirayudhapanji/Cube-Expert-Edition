
void __fastcall FUN_004a8a30(int *param_1)

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
  undefined4 uVar11;
  QVariant local_5c [16];
  QVariant local_4c [16];
  QVariant local_3c [16];
  QString local_2c [4];
  QString local_28 [4];
  QString local_24 [4];
  undefined1 local_20 [4];
  QTypedArrayData<unsigned_short> *local_1c;
  QTypedArrayData<unsigned_short> *local_18;
  QTypedArrayData<unsigned_short> *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0052ccf6;
  local_10 = ExceptionList;
  uVar2 = DAT_00759b24 ^ (uint)(local_20 + 0x1c);
  ExceptionList = &local_10;
  local_18 = QString::fromAscii_helper("File(*.ampNGData)",0x11);
  local_8 = 0;
  uVar3 = QVariant::QVariant(local_5c);
  uVar10 = 0x19;
  pcVar9 = "/Config/OpenDigAmpFileDir";
  local_8._0_1_ = 1;
  local_14 = QString::fromAscii_helper("/Config/OpenDigAmpFileDir",0x19);
  local_8._0_1_ = 2;
  this_00 = (QVariant *)FUN_00487a10(local_4c,&local_14,uVar3,pcVar9,uVar10,uVar2);
  local_8._0_1_ = 3;
  uVar3 = QVariant::toString(this_00);
  uVar11 = 0xffffffff;
  pQVar6 = local_24;
  local_8._0_1_ = 4;
  pcVar9 = "Open Amp Data File";
  uVar10 = QString::fromLocal8Bit((char *)pQVar6,0x585ce8);
  local_8 = CONCAT31(local_8._1_3_,5);
  puVar4 = (undefined4 *)
           QFileDialog::getOpenFileNames
                     (local_20,*param_1,uVar10,uVar3,&local_18,0,0,pQVar6,pcVar9,uVar11);
  iVar8 = *param_1;
  uVar3 = *puVar4;
  *puVar4 = shared_null_exref;
  local_1c = *(QTypedArrayData<unsigned_short> **)(iVar8 + 0xf064);
  *(undefined4 *)(iVar8 + 0xf064) = uVar3;
  FUN_00486b10();
  FUN_00486b10();
  QString::~QString(local_24);
  QString::~QString(local_28);
  QVariant::~QVariant(local_4c);
  QString::~QString((QString *)&local_14);
  QVariant::~QVariant(local_5c);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_18);
  bVar1 = QListData::isEmpty((QListData *)(*param_1 + 0xf064));
  if (!bVar1) {
    iVar8 = *param_1;
    if ((**(int **)(iVar8 + 0xf064) != 1) && (**(int **)(iVar8 + 0xf064) != 0)) {
      FUN_004875a0(*(undefined4 *)(*(int *)(iVar8 + 0xf064) + 4));
    }
    ppvVar5 = QListData::at((QListData *)(iVar8 + 0xf064),0);
    pQVar6 = (QString *)FUN_004876a0(local_2c,ppvVar5);
    local_8 = 6;
    QVariant::QVariant(local_3c,pQVar6);
    local_8._0_1_ = 7;
    local_1c = QString::fromAscii_helper("/Config/OpenDigAmpFileDir",0x19);
    local_8 = CONCAT31(local_8._1_3_,8);
    FUN_00487c00(&local_1c,local_3c);
    QString::~QString((QString *)&local_1c);
    QVariant::~QVariant(local_3c);
    local_8 = 0xffffffff;
    QString::~QString(local_2c);
    QListWidget::clear(*(QListWidget **)(*param_1 + 0x28));
    this = *(QListWidget **)(*param_1 + 0x28);
    pQVar7 = (QStringList *)(*param_1 + 0xf064);
    iVar8 = QListWidget::count(this);
    QListWidget::insertItems(this,iVar8,pQVar7);
  }
  ExceptionList = local_10;
  return;
}


