
QString * FUN_004f6850(QString *param_1,QString *param_2,QString *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0052fb1f;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  QString::QString(param_1,param_2);
  local_8 = 0;
  QString::append(param_1,param_3);
  ExceptionList = local_10;
  return param_1;
}


