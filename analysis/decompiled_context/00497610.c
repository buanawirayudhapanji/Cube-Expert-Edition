
void __thiscall FUN_00497610(undefined4 *param_1,QWidget *param_2)

{
  QGroupBox *this;
  QLabel *pQVar1;
  QWidget *pQVar2;
  QAbstractButton *pQVar3;
  QString *pQVar4;
  QString local_1c [4];
  QString local_18 [4];
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00527f8f;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = param_1;
  pQVar4 = (QString *)
           QCoreApplication::translate((char *)local_18,"Cab","IR cabinets simulation editor",0);
  local_8 = 0;
  QWidget::setWindowTitle(param_2,pQVar4);
  local_8 = 0xffffffff;
  QString::~QString(local_18);
  this = (QGroupBox *)*param_1;
  pQVar4 = (QString *)QCoreApplication::translate((char *)&param_2,"Cab","Import IR",0);
  local_8 = 1;
  QGroupBox::setTitle(this,pQVar4);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar1 = (QLabel *)param_1[2];
  pQVar4 = (QString *)QCoreApplication::translate((char *)&param_2,"Cab","Import to",0);
  local_8 = 2;
  QLabel::setText(pQVar1,pQVar4);
  QString::~QString((QString *)&param_2);
  pQVar2 = (QWidget *)local_14[3];
  pQVar4 = (QString *)QString::QString((QString *)&param_2);
  local_8 = 3;
  QWidget::setToolTip(pQVar2,pQVar4);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar3 = (QAbstractButton *)local_14[3];
  pQVar4 = (QString *)QCoreApplication::translate((char *)&param_2,"Cab","Open IR Files",0);
  local_8 = 4;
  QAbstractButton::setText(pQVar3,pQVar4);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar1 = (QLabel *)local_14[5];
  pQVar4 = (QString *)QCoreApplication::translate((char *)&param_2,"Cab","Distance",0);
  local_8 = 5;
  QLabel::setText(pQVar1,pQVar4);
  QString::~QString((QString *)&param_2);
  pQVar2 = (QWidget *)local_14[7];
  pQVar4 = (QString *)QString::QString((QString *)&param_2);
  local_8 = 6;
  QWidget::setToolTip(pQVar2,pQVar4);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar3 = (QAbstractButton *)local_14[7];
  pQVar4 = (QString *)QCoreApplication::translate((char *)&param_2,"Cab","Save",0);
  local_8 = 7;
  QAbstractButton::setText(pQVar3,pQVar4);
  QString::~QString((QString *)&param_2);
  pQVar2 = (QWidget *)local_14[8];
  pQVar4 = (QString *)QString::QString((QString *)&param_2);
  local_8 = 8;
  QWidget::setToolTip(pQVar2,pQVar4);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar3 = (QAbstractButton *)local_14[8];
  pQVar4 = (QString *)QCoreApplication::translate((char *)local_1c,"Cab","Reset",0);
  local_8 = 9;
  QAbstractButton::setText(pQVar3,pQVar4);
  QString::~QString(local_1c);
  ExceptionList = local_10;
  return;
}


