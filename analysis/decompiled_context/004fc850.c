
void __thiscall FUN_004fc850(undefined4 *param_1,QWidget *param_2)

{
  QGroupBox *pQVar1;
  QLabel *pQVar2;
  QWidget *pQVar3;
  QAbstractButton *pQVar4;
  QString *pQVar5;
  QString local_1c [4];
  QString local_18 [4];
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054a7c4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = param_1;
  pQVar5 = (QString *)
           QCoreApplication::translate((char *)local_18,"Speaker","IR cabinets simulation editor",0)
  ;
  local_8 = 0;
  QWidget::setWindowTitle(param_2,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString(local_18);
  pQVar1 = (QGroupBox *)*param_1;
  pQVar5 = (QString *)QCoreApplication::translate((char *)&param_2,"Speaker","Import IR",0);
  local_8 = 1;
  QGroupBox::setTitle(pQVar1,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QLabel *)local_14[2];
  pQVar5 = (QString *)QCoreApplication::translate((char *)&param_2,"Speaker","Import to",0);
  local_8 = 2;
  QLabel::setText(pQVar2,pQVar5);
  QString::~QString((QString *)&param_2);
  pQVar3 = (QWidget *)local_14[3];
  pQVar5 = (QString *)QString::QString((QString *)&param_2);
  local_8 = 3;
  QWidget::setToolTip(pQVar3,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar4 = (QAbstractButton *)local_14[3];
  pQVar5 = (QString *)QCoreApplication::translate((char *)&param_2,"Speaker","Open IR Files",0);
  local_8 = 4;
  QAbstractButton::setText(pQVar4,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QLabel *)local_14[5];
  pQVar5 = (QString *)QCoreApplication::translate((char *)&param_2,"Speaker","Distance",0);
  local_8 = 5;
  QLabel::setText(pQVar2,pQVar5);
  QString::~QString((QString *)&param_2);
  pQVar3 = (QWidget *)local_14[7];
  pQVar5 = (QString *)QString::QString((QString *)&param_2);
  local_8 = 6;
  QWidget::setToolTip(pQVar3,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar4 = (QAbstractButton *)local_14[7];
  pQVar5 = (QString *)QCoreApplication::translate((char *)&param_2,"Speaker","Save",0);
  local_8 = 7;
  QAbstractButton::setText(pQVar4,pQVar5);
  QString::~QString((QString *)&param_2);
  pQVar3 = (QWidget *)local_14[9];
  pQVar5 = (QString *)QString::QString((QString *)&param_2);
  local_8 = 8;
  QWidget::setToolTip(pQVar3,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar4 = (QAbstractButton *)local_14[9];
  pQVar5 = (QString *)QCoreApplication::translate((char *)&param_2,"Speaker","Factory IR",0);
  local_8 = 9;
  QAbstractButton::setText(pQVar4,pQVar5);
  QString::~QString((QString *)&param_2);
  pQVar3 = (QWidget *)local_14[10];
  pQVar5 = (QString *)QString::QString((QString *)&param_2);
  local_8 = 10;
  QWidget::setToolTip(pQVar3,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar4 = (QAbstractButton *)local_14[10];
  pQVar5 = (QString *)QCoreApplication::translate((char *)&param_2,"Speaker","Factory reset",0);
  local_8 = 0xb;
  QAbstractButton::setText(pQVar4,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar1 = (QGroupBox *)local_14[0xb];
  pQVar5 = (QString *)QCoreApplication::translate((char *)&param_2,"Speaker","Preset",0);
  local_8 = 0xc;
  QGroupBox::setTitle(pQVar1,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QLabel *)local_14[0xe];
  pQVar5 = (QString *)QCoreApplication::translate((char *)&param_2,"Speaker","TYPE",0);
  local_8 = 0xd;
  QLabel::setText(pQVar2,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QLabel *)local_14[0xf];
  pQVar5 = (QString *)QCoreApplication::translate((char *)&param_2,"Speaker","GAIN",0);
  local_8 = 0xe;
  QLabel::setText(pQVar2,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QLabel *)local_14[0x12];
  pQVar5 = (QString *)QCoreApplication::translate((char *)&param_2,"Speaker","TONE",0);
  local_8 = 0xf;
  QLabel::setText(pQVar2,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QLabel *)local_14[0x14];
  pQVar5 = (QString *)QCoreApplication::translate((char *)&param_2,"Speaker","FB",0);
  local_8 = 0x10;
  QLabel::setText(pQVar2,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QLabel *)local_14[0x15];
  pQVar5 = (QString *)QCoreApplication::translate((char *)&param_2,"Speaker","VOLUME",0);
  local_8 = 0x11;
  QLabel::setText(pQVar2,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QLabel *)local_14[0x17];
  pQVar5 = (QString *)QCoreApplication::translate((char *)&param_2,"Speaker","MOD",0);
  local_8 = 0x12;
  QLabel::setText(pQVar2,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QLabel *)local_14[0x1a];
  pQVar5 = (QString *)QCoreApplication::translate((char *)&param_2,"Speaker","MIX",0);
  local_8 = 0x13;
  QLabel::setText(pQVar2,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QLabel *)local_14[0x1b];
  pQVar5 = (QString *)QCoreApplication::translate((char *)&param_2,"Speaker","REVERB",0);
  local_8 = 0x14;
  QLabel::setText(pQVar2,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QLabel *)local_14[0x1d];
  pQVar5 = (QString *)QCoreApplication::translate((char *)&param_2,"Speaker","IR CAB",0);
  local_8 = 0x15;
  QLabel::setText(pQVar2,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QLabel *)local_14[0x20];
  pQVar5 = (QString *)QCoreApplication::translate((char *)&param_2,"Speaker","TIME",0);
  local_8 = 0x16;
  QLabel::setText(pQVar2,pQVar5);
  QString::~QString((QString *)&param_2);
  pQVar3 = (QWidget *)local_14[0x21];
  pQVar5 = (QString *)QString::QString((QString *)&param_2);
  local_8 = 0x17;
  QWidget::setToolTip(pQVar3,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar4 = (QAbstractButton *)local_14[0x21];
  pQVar5 = (QString *)QCoreApplication::translate((char *)&param_2,"Speaker","Save",0);
  local_8 = 0x18;
  QAbstractButton::setText(pQVar4,pQVar5);
  QString::~QString((QString *)&param_2);
  pQVar4 = (QAbstractButton *)local_14[0x2c];
  pQVar5 = (QString *)QString::QString((QString *)&param_2);
  local_8 = 0x19;
  QAbstractButton::setText(pQVar4,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QLabel *)local_14[0x2d];
  pQVar5 = (QString *)
           QCoreApplication::translate
                     ((char *)&param_2,"Speaker","-------------------------------",0);
  local_8 = 0x1a;
  QLabel::setText(pQVar2,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QLabel *)local_14[0x2e];
  pQVar5 = (QString *)
           QCoreApplication::translate
                     ((char *)&param_2,"Speaker","---------------------------------",0);
  local_8 = 0x1b;
  QLabel::setText(pQVar2,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QLabel *)local_14[0x2f];
  pQVar5 = (QString *)
           QCoreApplication::translate
                     ((char *)&param_2,"Speaker","---------------------------------",0);
  local_8 = 0x1c;
  QLabel::setText(pQVar2,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QLabel *)local_14[0x30];
  pQVar5 = (QString *)
           QCoreApplication::translate
                     ((char *)&param_2,"Speaker","-------------------------------",0);
  local_8 = 0x1d;
  QLabel::setText(pQVar2,pQVar5);
  QString::~QString((QString *)&param_2);
  pQVar4 = (QAbstractButton *)local_14[0x31];
  pQVar5 = (QString *)QString::QString((QString *)&param_2);
  local_8 = 0x1e;
  QAbstractButton::setText(pQVar4,pQVar5);
  QString::~QString((QString *)&param_2);
  pQVar4 = (QAbstractButton *)local_14[0x32];
  pQVar5 = (QString *)QString::QString((QString *)&param_2);
  local_8 = 0x1f;
  QAbstractButton::setText(pQVar4,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QLabel *)local_14[0x33];
  pQVar5 = (QString *)
           QCoreApplication::translate
                     ((char *)&param_2,"Speaker","-------------------------------",0);
  local_8 = 0x20;
  QLabel::setText(pQVar2,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QLabel *)local_14[0x34];
  pQVar5 = (QString *)
           QCoreApplication::translate
                     ((char *)&param_2,"Speaker","---------------------------------",0);
  local_8 = 0x21;
  QLabel::setText(pQVar2,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QLabel *)local_14[0x35];
  pQVar5 = (QString *)
           QCoreApplication::translate
                     ((char *)&param_2,"Speaker",
                      "------------------------------------------------------------------------------------------------------------------------------------"
                      ,0);
  local_8 = 0x22;
  QLabel::setText(pQVar2,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QLabel *)local_14[0x36];
  pQVar5 = (QString *)QCoreApplication::translate((char *)&param_2,"Speaker","VB LVL",0);
  local_8 = 0x23;
  QLabel::setText(pQVar2,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QLabel *)local_14[0x39];
  pQVar5 = (QString *)QCoreApplication::translate((char *)&param_2,"Speaker","VB HZ",0);
  local_8 = 0x24;
  QLabel::setText(pQVar2,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QLabel *)local_14[0x3c];
  pQVar5 = (QString *)QCoreApplication::translate((char *)&param_2,"Speaker","VB POS",0);
  local_8 = 0x25;
  QLabel::setText(pQVar2,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QLabel *)local_14[0x40];
  pQVar5 = (QString *)QCoreApplication::translate((char *)local_1c,"Speaker","USB Loopback",0);
  local_8 = 0x26;
  QLabel::setText(pQVar2,pQVar5);
  QString::~QString(local_1c);
  ExceptionList = local_10;
  return;
}


