
void __thiscall FUN_004de750(undefined4 param_1,QTypedArrayData<unsigned_short> *param_2)

{
  QNetworkReply *this;
  NetworkError NVar1;
  int iVar2;
  QString *pQVar3;
  undefined4 uVar4;
  StandardButton SVar5;
  QUrl *pQVar6;
  QChar aQStack_46 [6];
  QVariant local_34 [16];
  float local_24;
  QByteArray local_20 [4];
  QTypedArrayData<unsigned_short> *local_1c;
  QTypedArrayData<unsigned_short> *local_18;
  QString local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  this = (QNetworkReply *)param_2;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0053ee56;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  QNetworkReply::attribute((QNetworkReply *)param_2,(Attribute)local_34);
  local_8 = 0;
  NVar1 = QNetworkReply::error(this);
  if (NVar1 == 0) {
    QIODevice::readAll((QIODevice *)this);
    local_8._0_1_ = 1;
    QString::QString(local_14,local_20);
    local_8._0_1_ = 2;
    local_18 = QString::fromAscii_helper("version=",8);
    local_8._0_1_ = 3;
    iVar2 = QString::indexOf(local_14,(QString *)&local_18,0,1);
    if (iVar2 != -1) {
      pQVar3 = (QString *)QString::mid(local_14,(int)&local_1c,iVar2 + *(int *)(local_18 + 4));
      QString::operator=(local_14,pQVar3);
      QString::~QString((QString *)&local_1c);
      local_24 = QString::toFloat(local_14,(bool *)0x0);
      param_2 = QString::fromAscii_helper("CubeSuite V2.8.10",0x11);
      local_8._0_1_ = 4;
      QString::toUpper((QString *)&param_2);
      QString::~QString((QString *)&local_1c);
      QChar::QChar(aQStack_46 + -0x12,0x56);
      iVar2 = QString::indexOf((QString *)&param_2);
      if (iVar2 != -1) {
        pQVar3 = (QString *)QString::mid((QString *)&param_2,(int)&local_1c,iVar2 + 1);
        QString::operator=((QString *)&param_2,pQVar3);
        QString::~QString((QString *)&local_1c);
        local_1c = (QTypedArrayData<unsigned_short> *)
                   QString::toFloat((QString *)&param_2,(bool *)0x0);
        if ((float)local_1c < local_24) {
          uVar4 = QString::asprintf((char *)&local_24,
                                    "A new version(V%.2f) is available, would you like to download ?"
                                   );
          local_1c = (QTypedArrayData<unsigned_short> *)&DAT_00756330;
          local_8._0_1_ = 6;
          SVar5 = QMessageBox::question(param_1,&local_1c,uVar4,0x14000,0x4000);
          QString::~QString((QString *)&local_1c);
          local_8._0_1_ = 4;
          QString::~QString((QString *)&local_24);
          if (SVar5 == 0x4000) {
            local_1c = QString::fromAscii_helper
                                 ("http://124.232.137.132:8998/CubeSugarSuite/CubeSugarSuite.exe",
                                  0x3d);
            local_8._0_1_ = 7;
            pQVar6 = (QUrl *)QUrl::QUrl((QUrl *)&local_24,(QString *)&local_1c,0);
            local_8._0_1_ = 8;
            QDesktopServices::openUrl(pQVar6);
            QUrl::~QUrl((QUrl *)&local_24);
            QString::~QString((QString *)&local_1c);
          }
        }
      }
      QString::~QString((QString *)&param_2);
    }
    QString::~QString((QString *)&local_18);
    QString::~QString(local_14);
    local_8 = (uint)local_8._1_3_ << 8;
    QByteArray::~QByteArray(local_20);
  }
  QObject::deleteLater((QObject *)this);
  QVariant::~QVariant(local_34);
  ExceptionList = local_10;
  return;
}


