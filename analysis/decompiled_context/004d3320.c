
void FUN_004d3320(QString param_1,char *param_2,int param_3)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  StandardButton SVar4;
  QString *pQVar5;
  int iVar6;
  int *in_stack_00000034;
  QString QStack00000038;
  QString QStack0000003c;
  QChar aQStack_2a [2];
  QFile local_28 [8];
  QString local_20 [4];
  QString local_1c [4];
  undefined *local_18;
  QTypedArrayData<unsigned_short> *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pcVar1 = param_2;
  puStack_c = &LAB_0053aaf9;
  local_10 = ExceptionList;
  uVar3 = DAT_00759b24 ^ (uint)(local_1c + 0x18);
  ExceptionList = &local_10;
  local_14 = (QTypedArrayData<unsigned_short> *)&DAT_00755d10;
  local_18 = &DAT_00755cdc;
  local_8 = 5;
  SVar4 = QMessageBox::information(0,&local_18,&local_14,0x14000);
  QString::~QString((QString *)&local_18);
  local_8._0_1_ = 3;
  QString::~QString((QString *)&local_14);
  if (SVar4 == 0x4000) {
    FUN_00486cd0();
    local_8._0_1_ = 6;
    local_14 = QString::fromAscii_helper("bin/%1.bin",10);
    local_18 = (undefined *)CONCAT31(local_18._1_3_,0x20);
    local_8._0_1_ = 7;
    QChar::QChar(aQStack_2a + -0x12,local_18);
    pQVar5 = (QString *)QString::arg((QString *)&local_14,local_20,&param_1,0);
    local_8._0_1_ = 8;
    QString::append(local_1c,pQVar5);
    QString::~QString(local_20);
    local_8._0_1_ = 6;
    QString::~QString((QString *)&local_14);
    QFile::QFile(local_28);
    local_8._0_1_ = 9;
    iVar6 = FUN_00486ef0(local_28,local_1c,1);
    if (iVar6 == 0) {
      QMetaObject::tr((QMetaObject *)&DAT_007598e8,(char *)&local_14,
                      "Recovery failure! Configuration file loss!",0);
      local_8._0_1_ = 0xc;
    }
    else {
      QIODevice::read((QIODevice *)local_28,pcVar1,CONCAT44(uVar3,param_3 >> 0x1f));
      QFileDevice::close((QFileDevice *)local_28);
      if (in_stack_00000034 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        std::_Xbad_function_call();
      }
      cVar2 = (**(code **)(*in_stack_00000034 + 8))();
      if (cVar2 == '\0') {
        QMetaObject::tr((QMetaObject *)&DAT_007598e8,(char *)&local_14,"Recovery failure!",0);
        local_8._0_1_ = 0xb;
      }
      else {
        QMetaObject::tr((QMetaObject *)&DAT_007598e8,(char *)&local_14,"Successful recovery",0);
        local_8._0_1_ = 10;
      }
    }
    FUN_00486bb0();
    QString::~QString((QString *)&local_14);
    QFile::~QFile(local_28);
    QString::~QString(local_1c);
  }
  QString::~QString(&param_1);
  if (in_stack_00000034 != (int *)0x0) {
    (**(code **)(*in_stack_00000034 + 0x10))();
    in_stack_00000034 = (int *)0x0;
  }
  QString::~QString(&QStack00000038);
  QString::~QString(&QStack0000003c);
  ExceptionList = local_10;
  return;
}


