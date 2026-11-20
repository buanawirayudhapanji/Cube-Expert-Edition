
QString * FUN_004f68c0(QString *param_1,QString *param_2,int param_3)

{
  QString *pQVar1;
  QString local_18 [4];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00547278;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = 0;
  QString::QString(param_1,param_2);
  local_8 = 0;
  local_14 = 1;
  pQVar1 = (QString *)QString::fromUtf8((char *)local_18,param_3);
  local_8 = 1;
  QString::append(param_1,pQVar1);
  QString::~QString(local_18);
  ExceptionList = local_10;
  return param_1;
}


