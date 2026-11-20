
void __thiscall FUN_004f71c0(int param_1,QString param_2)

{
  QComboBox *pQVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  QString *pQVar5;
  int iVar6;
  int iVar7;
  QVariant *pQVar8;
  QIcon *pQVar9;
  code *pcVar10;
  code *pcVar11;
  QVariant local_44 [16];
  QString local_34 [4];
  int local_30;
  QTypedArrayData<unsigned_short> *local_2c;
  undefined *local_28;
  QByteArray local_24 [4];
  QString local_20 [4];
  QString local_1c [4];
  undefined4 local_18;
  QString local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00548043;
  local_10 = ExceptionList;
  uVar4 = DAT_00759b24 ^ (uint)(local_14 + 0x10);
  ExceptionList = &local_10;
  local_18 = 0;
  local_8 = 0;
  local_30 = param_1;
  QComboBox::clear(*(QComboBox **)(param_1 + 0x28));
  QByteArray::QByteArray(local_24);
  local_8._0_1_ = 1;
  FUN_00510a20(uVar4);
  local_2c = (QTypedArrayData<unsigned_short> *)&DAT_00756550;
  local_28 = &DAT_00756508;
  local_8._0_1_ = 4;
  QString::QString(local_20,(QString *)&local_28);
  local_18 = 1;
  QString::append(local_20,(QString *)&local_2c);
  local_8._0_1_ = 5;
  QString::QString(local_1c,local_20);
  local_18 = 3;
  QString::append(local_1c,&param_2);
  local_8._0_1_ = 6;
  QString::QString(local_14,local_1c);
  local_18 = 7;
  pQVar5 = (QString *)QString::fromUtf8((char *)local_34,0x592288);
  local_8._0_1_ = 7;
  QString::append(local_14,pQVar5);
  local_8._0_1_ = 6;
  QString::~QString(local_34);
  cVar2 = FUN_005108e0(local_14,local_24);
  QString::~QString(local_14);
  QString::~QString(local_1c);
  QString::~QString(local_20);
  QString::~QString((QString *)&local_28);
  local_8._0_1_ = 1;
  QString::~QString((QString *)&local_2c);
  if (cVar2 != '\0') {
    QString::fromUtf8((QByteArray *)local_1c);
    pcVar11 = fromAscii_helper_exref;
    local_8._0_1_ = 8;
    local_2c = QString::fromAscii_helper("<a href=\"(.*?)\">(.*?)</a>",0x19);
    local_8._0_1_ = 9;
    QRegularExpression::QRegularExpression((QRegularExpression *)&local_28,&local_2c,0);
    local_8._0_1_ = 0xb;
    QString::~QString((QString *)&local_2c);
    QRegularExpression::globalMatch((QRegularExpression *)&local_28,&local_18,local_1c,0,0,0);
    local_8._0_1_ = 0xc;
    bVar3 = QRegularExpressionMatchIterator::hasNext((QRegularExpressionMatchIterator *)&local_18);
    if (bVar3) {
      pcVar10 = ~QRegularExpressionMatch_exref;
      do {
        QRegularExpressionMatchIterator::next((QRegularExpressionMatchIterator *)&local_18);
        local_8._0_1_ = 0xd;
        QRegularExpressionMatch::captured((QRegularExpressionMatch *)local_20,(int)local_14);
        local_8._0_1_ = 0xe;
        local_2c = (QTypedArrayData<unsigned_short> *)(*pcVar11)(&DAT_005922a8,3);
        iVar6 = QString::compare(local_14,(QString *)&local_2c,1);
        QString::~QString((QString *)&local_2c);
        if (iVar6 == 0) {
          QString::~QString(local_14);
        }
        else {
          pQVar1 = *(QComboBox **)(local_30 + 0x28);
          pQVar8 = (QVariant *)QVariant::QVariant(local_44);
          local_8._0_1_ = 0xf;
          iVar6 = QComboBox::count(pQVar1);
          pQVar9 = (QIcon *)QIcon::QIcon((QIcon *)local_34);
          local_8._0_1_ = 0x10;
          QComboBox::insertItem(pQVar1,iVar6,pQVar9,local_14,pQVar8);
          QIcon::~QIcon((QIcon *)local_34);
          QVariant::~QVariant(local_44);
          QString::~QString(local_14);
          pcVar10 = ~QRegularExpressionMatch_exref;
        }
        local_8._0_1_ = 0xc;
        (*pcVar10)();
        bVar3 = QRegularExpressionMatchIterator::hasNext
                          ((QRegularExpressionMatchIterator *)&local_18);
        pcVar11 = fromAscii_helper_exref;
      } while (bVar3);
    }
    iVar6 = local_30;
    iVar7 = QComboBox::count(*(QComboBox **)(local_30 + 0x28));
    if (iVar7 == 0) {
      pQVar1 = *(QComboBox **)(iVar6 + 0x28);
      pQVar8 = (QVariant *)QVariant::QVariant(local_44);
      local_8._0_1_ = 0x11;
      local_30 = (*pcVar11)("No firmware is available for update.",0x24);
      local_8._0_1_ = 0x12;
      iVar6 = QComboBox::count(pQVar1);
      pQVar9 = (QIcon *)QIcon::QIcon((QIcon *)local_34);
      local_8._0_1_ = 0x13;
      QComboBox::insertItem(pQVar1,iVar6,pQVar9,(QString *)&local_30,pQVar8);
      QIcon::~QIcon((QIcon *)local_34);
      QString::~QString((QString *)&local_30);
      QVariant::~QVariant(local_44);
    }
    QRegularExpressionMatchIterator::~QRegularExpressionMatchIterator
              ((QRegularExpressionMatchIterator *)&local_18);
    QRegularExpression::~QRegularExpression((QRegularExpression *)&local_28);
    QString::~QString(local_1c);
  }
  QByteArray::~QByteArray(local_24);
  QString::~QString(&param_2);
  ExceptionList = local_10;
  return;
}


