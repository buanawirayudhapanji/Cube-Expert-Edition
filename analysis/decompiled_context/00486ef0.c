
undefined4 FUN_00486ef0(QFile *param_1,QString *param_2,undefined4 param_3,int param_4)

{
  QFile *pQVar1;
  char cVar2;
  QFileInfo *this;
  undefined4 uVar3;
  QChar aQStack_2a [2];
  QFileInfo local_20 [4];
  QString local_1c [4];
  QString local_18 [4];
  QTypedArrayData<unsigned_short> *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pQVar1 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0051d372;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  QFile::setFileName(param_1,param_2);
  cVar2 = (**(code **)(*(int *)pQVar1 + 0x30))();
  if (cVar2 != '\0') {
    ExceptionList = local_10;
    return 1;
  }
  if (param_4 != 0) {
    local_14 = QString::fromAscii_helper
                         ("Open file \'%1\' failed, it may be occupied by other process",0x3a);
    local_8 = 0;
    this = (QFileInfo *)QFileInfo::QFileInfo(local_20,param_2);
    local_8._0_1_ = 1;
    uVar3 = QFileInfo::fileName(this);
    param_1 = (QFile *)CONCAT31(param_1._1_3_,0x20);
    local_8._0_1_ = 2;
    QChar::QChar(aQStack_2a + -10,param_1);
    uVar3 = QString::arg((QString *)&local_14,local_18,uVar3,0);
    param_1 = (QFile *)&DAT_0075459c;
    local_8 = CONCAT31(local_8._1_3_,4);
    QMessageBox::information(0,&param_1,uVar3,0x400);
    QString::~QString((QString *)&param_1);
    QString::~QString(local_18);
    QString::~QString(local_1c);
    QFileInfo::~QFileInfo(local_20);
    QString::~QString((QString *)&local_14);
  }
  ExceptionList = local_10;
  return 0;
}


