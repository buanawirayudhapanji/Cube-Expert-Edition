
void FUN_00487760(QString *param_1,QString *param_2)

{
  QDir *this;
  QString *pQVar1;
  QDir local_1c [4];
  QString local_18 [4];
  QFileInfo local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0051d497;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  QFileInfo::QFileInfo(local_14,param_1);
  local_8 = 0;
  this = (QDir *)QFileInfo::absoluteDir(local_14);
  local_8._0_1_ = 1;
  pQVar1 = (QString *)QDir::path(this);
  QString::operator=(param_2,pQVar1);
  QString::~QString(local_18);
  local_8 = (uint)local_8._1_3_ << 8;
  QDir::~QDir(local_1c);
  QString::operator+=(param_2,'/');
  QFileInfo::~QFileInfo(local_14);
  ExceptionList = local_10;
  return;
}


