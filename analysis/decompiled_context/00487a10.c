
QString * FUN_00487a10(QString *param_1,QVariant *param_2)

{
  QString *pQVar1;
  QSettings local_28 [8];
  QString local_20 [4];
  QString local_1c [4];
  undefined4 local_18;
  QString local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0051d4fa;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = 0;
  pQVar1 = (QString *)QCoreApplication::applicationDirPath();
  local_8 = 1;
  QString::QString(local_14,pQVar1);
  local_18 = 2;
  pQVar1 = (QString *)QString::fromUtf8((char *)local_1c,0x580f48);
  local_8._0_1_ = 2;
  QString::append(local_14,pQVar1);
  local_8._0_1_ = 1;
  QString::~QString(local_1c);
  QSettings::QSettings(local_28,local_14,1,(QObject *)0x0);
  QString::~QString(local_14);
  local_8 = CONCAT31(local_8._1_3_,5);
  QString::~QString(local_20);
  QSettings::value(local_28,param_1,param_2);
  QSettings::~QSettings(local_28);
  ExceptionList = local_10;
  return param_1;
}


