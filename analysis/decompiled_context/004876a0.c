
QString * FUN_004876a0(QString *param_1,QString *param_2)

{
  QDir *this;
  QString *pQVar1;
  QDir local_20 [4];
  QString local_1c [4];
  undefined4 local_18;
  QFileInfo local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0051d461;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = 0;
  QString::QString(param_1);
  local_8 = 0;
  local_18 = 1;
  QFileInfo::QFileInfo(local_14,param_2);
  local_8 = 1;
  this = (QDir *)QFileInfo::absoluteDir(local_14);
  local_8._0_1_ = 2;
  pQVar1 = (QString *)QDir::path(this);
  QString::operator=(param_1,pQVar1);
  QString::~QString(local_1c);
  local_8 = CONCAT31(local_8._1_3_,1);
  QDir::~QDir(local_20);
  QString::operator+=(param_1,'/');
  QFileInfo::~QFileInfo(local_14);
  ExceptionList = local_10;
  return param_1;
}


