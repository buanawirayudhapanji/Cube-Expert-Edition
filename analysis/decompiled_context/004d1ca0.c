
void __thiscall FUN_004d1ca0(int *param_1,QListWidgetItem *param_2)

{
  QListWidget *this;
  char cVar1;
  void **ppvVar2;
  int iVar3;
  QString *pQVar4;
  int *piVar5;
  undefined4 *puVar6;
  QVariant local_38 [16];
  QFile local_28 [8];
  QString local_20 [4];
  int local_1c;
  QTypedArrayData<unsigned_short> *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00539d6e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  QListWidgetItem::text(param_2);
  local_8 = 0;
  if (*(int *)(local_1c + 4) == 0) goto LAB_004d1f9a;
  QFile::QFile(local_28);
  puVar6 = &param_2;
  local_8._0_1_ = 1;
  QListWidget::selectedItems(*(QListWidget **)(*param_1 + 0x148));
  local_8._0_1_ = 2;
  this = *(QListWidget **)(*param_1 + 0x148);
  ppvVar2 = QListData::at((QListData *)&param_2,0);
  iVar3 = QListWidget::row(this,*ppvVar2);
  if (iVar3 == -1) {
    local_18 = (QTypedArrayData<unsigned_short> *)&DAT_00755d70;
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_00486bb0(&local_18,puVar6);
    pQVar4 = (QString *)&local_18;
LAB_004d1f01:
    QString::~QString(pQVar4);
    local_8 = CONCAT31(local_8._1_3_,9);
  }
  else {
    ppvVar2 = QListData::at((QListData *)&param_2,0);
    piVar5 = &local_14;
    QListWidgetItem::text(*ppvVar2);
    local_8._0_1_ = 4;
    if (*(int *)(local_14 + 4) != 0) {
      pQVar4 = (QString *)FUN_004876a0(local_20,&local_14,piVar5);
      local_8._0_1_ = 5;
      QVariant::QVariant(local_38,pQVar4);
      local_8._0_1_ = 6;
      local_18 = QString::fromAscii_helper("/Config/WavLoadDir",0x12);
      local_8._0_1_ = 7;
      FUN_00487c00(&local_18,local_38);
      QString::~QString((QString *)&local_18);
      QVariant::~QVariant(local_38);
      local_8._0_1_ = 4;
      QString::~QString(local_20);
      cVar1 = FUN_00508540(&local_14);
      if (cVar1 == '\0') {
        QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7250,(char *)&local_18,"Load File Failure!",0);
        local_8._0_1_ = 10;
        FUN_00486bb0(&local_18);
        QString::~QString((QString *)&local_18);
      }
      else {
        iVar3 = QAbstractSlider::value(*(QAbstractSlider **)(*param_1 + 500));
        *(char *)(*param_1 + 0x2d3) = (char)iVar3;
        *(undefined1 *)(*param_1 + 0x2d2) = 2;
        *(undefined1 *)(*param_1 + 0x2c0) = 0x43;
        *(undefined1 *)(*param_1 + 0x2c1) = 0x41;
        *(undefined1 *)(*param_1 + 0x2c2) = 0x42;
        *(undefined1 *)(*param_1 + 0x2c3) = 0;
        iVar3 = *param_1;
        FUN_00508610(*(undefined4 *)(iVar3 + 0x1ed0),*(undefined4 *)(iVar3 + 0x1ed4),
                     *(undefined4 *)(iVar3 + 0x1ed8),*(undefined4 *)(iVar3 + 0x1edc),
                     *(undefined2 *)(iVar3 + 0x1ee0),*(undefined4 *)(iVar3 + 0x217c));
        FUN_00508b30(*param_1 + 0x2d4,0x18);
        iVar3 = QAbstractSlider::value(*(QAbstractSlider **)(*param_1 + 500));
        *(char *)(*param_1 + 0x2d3) = (char)iVar3;
        (**(code **)(**(int **)(*param_1 + 0x21c) + 0x2c))(1);
        cVar1 = FUN_00506590(5,0x18,*param_1 + 0x2c0,0x1814,*param_1);
        if (cVar1 == '\0') {
          QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7250,(char *)&local_18,"Data write failure!",0
                         );
          local_8._0_1_ = 8;
          FUN_00486bb0(&local_18);
          local_8 = CONCAT31(local_8._1_3_,4);
          QString::~QString((QString *)&local_18);
          (**(code **)(**(int **)(*param_1 + 0x21c) + 0x2c))(0);
          pQVar4 = (QString *)&local_14;
          goto LAB_004d1f01;
        }
        FUN_004d4b30(1);
        (**(code **)(**(int **)(*param_1 + 0x21c) + 0x2c))(0);
      }
    }
    QString::~QString((QString *)&local_14);
    local_8 = CONCAT31(local_8._1_3_,0xb);
  }
  if (*(int *)param_2 == 0) {
LAB_004d1f85:
    QListData::dispose((Data *)param_2);
  }
  else if (*(int *)param_2 != -1) {
    LOCK();
    iVar3 = *(int *)param_2;
    *(int *)param_2 = *(int *)param_2 + -1;
    UNLOCK();
    if (iVar3 == 1) goto LAB_004d1f85;
  }
  QFile::~QFile(local_28);
LAB_004d1f9a:
  QString::~QString((QString *)&local_1c);
  ExceptionList = local_10;
  return;
}


