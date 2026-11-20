
void __thiscall FUN_00503ac0(undefined4 *param_1,QWidget *param_2)

{
  QGroupBox *this;
  QLabel *pQVar1;
  QAbstractButton *pQVar2;
  QWidget *pQVar3;
  QString *pQVar4;
  QString local_1c [4];
  QString local_18 [4];
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054cd5a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = param_1;
  pQVar4 = (QString *)
           QCoreApplication::translate((char *)local_18,"UpdateFirmware","Firmware Update",0);
  local_8 = 0;
  QWidget::setWindowTitle(param_2,pQVar4);
  local_8 = 0xffffffff;
  QString::~QString(local_18);
  this = (QGroupBox *)*param_1;
  pQVar4 = (QString *)
           QCoreApplication::translate((char *)&param_2,"UpdateFirmware","Firmware File",0);
  local_8 = 1;
  QGroupBox::setTitle(this,pQVar4);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar1 = (QLabel *)param_1[1];
  pQVar4 = (QString *)QCoreApplication::translate((char *)&param_2,"UpdateFirmware","Path",0);
  local_8 = 2;
  QLabel::setText(pQVar1,pQVar4);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QAbstractButton *)local_14[3];
  pQVar4 = (QString *)
           QCoreApplication::translate
                     ((char *)&param_2,"UpdateFirmware","Select local file for updating",0);
  local_8 = 3;
  QAbstractButton::setText(pQVar2,pQVar4);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar1 = (QLabel *)local_14[4];
  pQVar4 = (QString *)
           QCoreApplication::translate((char *)&param_2,"UpdateFirmware","Firmware list",0);
  local_8 = 4;
  QLabel::setText(pQVar1,pQVar4);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar3 = (QWidget *)local_14[6];
  pQVar4 = (QString *)
           QCoreApplication::translate
                     ((char *)&param_2,"UpdateFirmware","Select a local firmware file",0);
  local_8 = 5;
  QWidget::setToolTip(pQVar3,pQVar4);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QAbstractButton *)local_14[6];
  pQVar4 = (QString *)
           QCoreApplication::translate((char *)&param_2,"UpdateFirmware","Open Firmware Files",0);
  local_8 = 6;
  QAbstractButton::setText(pQVar2,pQVar4);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QAbstractButton *)local_14[8];
  pQVar4 = (QString *)QCoreApplication::translate((char *)&param_2,"UpdateFirmware",&DAT_00593020,0)
  ;
  local_8 = 7;
  QAbstractButton::setText(pQVar2,pQVar4);
  QString::~QString((QString *)&param_2);
  pQVar1 = (QLabel *)local_14[9];
  pQVar4 = (QString *)QString::QString((QString *)&param_2);
  local_8 = 8;
  QLabel::setText(pQVar1,pQVar4);
  QString::~QString((QString *)&param_2);
  pQVar1 = (QLabel *)local_14[10];
  pQVar4 = (QString *)QString::QString((QString *)&param_2);
  local_8 = 9;
  QLabel::setText(pQVar1,pQVar4);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QAbstractButton *)local_14[0xb];
  pQVar4 = (QString *)QCoreApplication::translate((char *)&param_2,"UpdateFirmware",&DAT_0059303c,0)
  ;
  local_8 = 10;
  QAbstractButton::setText(pQVar2,pQVar4);
  QString::~QString((QString *)&param_2);
  pQVar3 = (QWidget *)local_14[0xc];
  pQVar4 = (QString *)QString::QString((QString *)&param_2);
  local_8 = 0xb;
  QWidget::setToolTip(pQVar3,pQVar4);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QAbstractButton *)local_14[0xc];
  pQVar4 = (QString *)QCoreApplication::translate((char *)local_1c,"UpdateFirmware","Update",0);
  local_8 = 0xc;
  QAbstractButton::setText(pQVar2,pQVar4);
  QString::~QString(local_1c);
  ExceptionList = local_10;
  return;
}


