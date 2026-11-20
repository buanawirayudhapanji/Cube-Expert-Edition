
void __thiscall FUN_004d36a0(int param_1,QTypedArrayData<unsigned_short> *param_2)

{
  QLabel *this;
  longlong lVar1;
  undefined4 uVar2;
  QString *pQVar3;
  QChar aQStack_32 [2];
  QString local_20 [4];
  QString local_1c [4];
  undefined4 local_18;
  QTypedArrayData<unsigned_short> *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0053ab79;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(short *)((int)param_2 + 8) == 0x3f0) {
    lVar1 = (ulonglong)*(uint *)((int)param_2 + 0x10) * 100;
    uVar2 = __aulldiv((int)lVar1,
                      *(int *)((int)param_2 + 0x14) * 100 + (int)((ulonglong)lVar1 >> 0x20),
                      *(undefined4 *)((int)param_2 + 0x18));
    this = *(QLabel **)(param_1 + 0x21c);
    local_14 = QString::fromAscii_helper("%1%2",4);
    local_18 = CONCAT31(local_18._1_3_,0x20);
    local_8 = 0;
    QChar::QChar(aQStack_32 + -6,local_18);
    pQVar3 = (QString *)QString::arg((QString *)&local_14,local_20,uVar2,0,10);
    local_8._0_1_ = 1;
    param_2 = QString::fromAscii_helper("%",1);
    local_18 = CONCAT31(local_18._1_3_,0x20);
    local_8._0_1_ = 2;
    QChar::QChar(aQStack_32 + -6,local_18);
    pQVar3 = (QString *)QString::arg(pQVar3,local_1c,&param_2,0);
    local_8 = CONCAT31(local_8._1_3_,3);
    QLabel::setText(this,pQVar3);
    QString::~QString(local_1c);
    QString::~QString((QString *)&param_2);
    QString::~QString(local_20);
    QString::~QString((QString *)&local_14);
  }
  ExceptionList = local_10;
  return;
}


