
QObject * FUN_00510a20(void)

{
  QObject *this;
  QNetworkAccessManager *this_00;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0055ce38;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this = (QObject *)DAT_0076add8;
  if (DAT_0076add8 == (undefined4 *)0x0) {
    this = operator_new(0x10);
    local_8 = 0;
    QObject::QObject(this,(QObject *)0x0);
    *(undefined ***)this = CMyHttp::vftable;
    QString::QString((QString *)(this + 0xc));
    local_8._0_1_ = 2;
    this_00 = operator_new(8);
    local_8 = CONCAT31(local_8._1_3_,3);
    QNetworkAccessManager::QNetworkAccessManager(this_00,(QObject *)0x0);
    *(undefined ***)this_00 = QNetworkAccessManager::vftable;
    *(QNetworkAccessManager **)(this + 8) = this_00;
  }
  ExceptionList = local_10;
  DAT_0076add8 = (undefined4 *)this;
  return this;
}


