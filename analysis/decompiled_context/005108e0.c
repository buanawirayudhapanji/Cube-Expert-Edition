
bool __thiscall FUN_005108e0(int param_1,QString *param_2,QByteArray *param_3)

{
  QNetworkAccessManager *this;
  QUrl *pQVar1;
  QNetworkRequest *pQVar2;
  QNetworkReply *this_00;
  NetworkError NVar3;
  QByteArray *pQVar4;
  QVariant local_30 [16];
  QEventLoop local_20 [8];
  QByteArray local_18 [4];
  QObject local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0055cdd9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  QByteArray::clear(param_3);
  QEventLoop::QEventLoop(local_20,(QObject *)0x0);
  local_8 = 0;
  QObject::connect(local_14,*(char **)(param_1 + 8),(QObject *)"2finished(QNetworkReply*)",
                   (char *)local_20,0x59411c);
  QMetaObject::Connection::~Connection((Connection *)local_14);
  this = *(QNetworkAccessManager **)(param_1 + 8);
  pQVar1 = (QUrl *)QUrl::QUrl((QUrl *)local_14,param_2,0);
  local_8._0_1_ = 1;
  pQVar2 = (QNetworkRequest *)QNetworkRequest::QNetworkRequest((QNetworkRequest *)&param_2,pQVar1);
  local_8._0_1_ = 2;
  this_00 = QNetworkAccessManager::get(this,pQVar2);
  QNetworkRequest::~QNetworkRequest((QNetworkRequest *)&param_2);
  local_8 = (uint)local_8._1_3_ << 8;
  QUrl::~QUrl((QUrl *)local_14);
  QEventLoop::exec(local_20,0);
  QNetworkReply::attribute(this_00,(Attribute)local_30);
  local_8 = CONCAT31(local_8._1_3_,3);
  NVar3 = QNetworkReply::error(this_00);
  if (NVar3 == 0) {
    pQVar4 = (QByteArray *)QIODevice::readAll((QIODevice *)this_00);
    QByteArray::operator=(param_3,pQVar4);
    QByteArray::~QByteArray(local_18);
  }
  QObject::deleteLater((QObject *)this_00);
  QVariant::~QVariant(local_30);
  QEventLoop::~QEventLoop(local_20);
  ExceptionList = local_10;
  return NVar3 == 0;
}


