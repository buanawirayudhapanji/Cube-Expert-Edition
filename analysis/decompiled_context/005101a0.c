
uint FUN_005101a0(QString param_1)

{
  int iVar1;
  QString *pQVar2;
  uint uVar3;
  undefined4 uStack_2c;
  QString local_18 [4];
  undefined *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0055b59e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  QChar::QChar((QChar *)&uStack_2c,0x3b);
  iVar1 = QString::indexOf(&param_1);
  if (iVar1 != -1) {
    uStack_2c = 0x5101fa;
    pQVar2 = (QString *)QString::left(&param_1,(int)&local_14);
    QString::operator=(&param_1,pQVar2);
    QString::~QString((QString *)&local_14);
  }
  pQVar2 = (QString *)QString::trimmed(&param_1);
  QString::operator=(&param_1,pQVar2);
  QString::~QString((QString *)&local_14);
  uStack_2c = 0x510238;
  pQVar2 = (QString *)QString::left(&param_1,(int)local_18);
  local_14 = &DAT_0075726c;
  uStack_2c = 0x51024d;
  iVar1 = QString::compare(pQVar2,(QString *)&local_14,0);
  QString::~QString((QString *)&local_14);
  QString::~QString(local_18);
  if (iVar1 == 0) {
    iVar1 = 0x10;
  }
  else {
    iVar1 = 10;
  }
  uStack_2c = 0x510276;
  uVar3 = QString::toUInt(&param_1,(bool *)0x0,iVar1);
  QString::~QString(&param_1);
  ExceptionList = local_10;
  return uVar3;
}


