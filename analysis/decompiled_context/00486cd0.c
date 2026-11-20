
QString * FUN_00486cd0(QString *param_1)

{
  QString *pQVar1;
  QString local_8 [4];
  
  if (*(int *)(*(int *)((int)ThreadLocalStoragePointer + _tls_index * 4) + 4) < DAT_0075b824) {
    FUN_0051977a(&DAT_0075b824);
    if (DAT_0075b824 == -1) {
      QString::QString((QString *)&DAT_0075b820);
      _atexit((_func_4879 *)&LAB_0057b990);
      FUN_00519730(&DAT_0075b824);
    }
  }
  if (*(int *)(DAT_0075b820 + 4) == 0) {
    pQVar1 = (QString *)QCoreApplication::applicationDirPath();
    QString::operator=((QString *)&DAT_0075b820,pQVar1);
    QString::~QString(local_8);
    QString::operator+=((QString *)&DAT_0075b820,'/');
  }
  QString::QString(param_1,(QString *)&DAT_0075b820);
  return param_1;
}


