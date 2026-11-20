
void __thiscall FUN_004dc4c0(undefined4 *param_1,QWidget *param_2)

{
  QWidget *pQVar1;
  QAbstractButton *pQVar2;
  undefined4 *puVar3;
  bool bVar4;
  QString *pQVar5;
  QListWidgetItem *this;
  QString local_1c [4];
  QString local_18 [4];
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0053d3b4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = param_1;
  pQVar5 = (QString *)QCoreApplication::translate((char *)local_18,"LooperDrum","Dialog",0);
  local_8 = 0;
  QWidget::setWindowTitle(param_2,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString(local_18);
  pQVar1 = (QWidget *)*param_1;
  pQVar5 = (QString *)
           QCoreApplication::translate
                     ((char *)&param_2,"LooperDrum","Import a wav file to the selected song",0);
  local_8 = 1;
  QWidget::setToolTip(pQVar1,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QAbstractButton *)*local_14;
  pQVar5 = (QString *)QCoreApplication::translate((char *)&param_2,"LooperDrum"," Import     ",0);
  local_8 = 2;
  QAbstractButton::setText(pQVar2,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar1 = (QWidget *)local_14[1];
  pQVar5 = (QString *)
           QCoreApplication::translate((char *)&param_2,"LooperDrum","Delte the selected song",0);
  local_8 = 3;
  QWidget::setToolTip(pQVar1,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar1 = (QWidget *)local_14[3];
  pQVar5 = (QString *)
           QCoreApplication::translate
                     ((char *)&param_2,"LooperDrum","Export the selected song as a wav file",0);
  local_8 = 4;
  QWidget::setToolTip(pQVar1,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  pQVar2 = (QAbstractButton *)local_14[3];
  pQVar5 = (QString *)QCoreApplication::translate((char *)&param_2,"LooperDrum"," Export     ",0);
  local_8 = 5;
  QAbstractButton::setText(pQVar2,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  puVar3 = local_14;
  bVar4 = QListWidget::isSortingEnabled((QListWidget *)local_14[4]);
  param_2 = (QWidget *)CONCAT31(param_2._1_3_,bVar4);
  QListWidget::setSortingEnabled((QListWidget *)puVar3[4],false);
  this = QListWidget::item((QListWidget *)puVar3[4],0);
  pQVar5 = (QString *)QCoreApplication::translate((char *)local_1c,"LooperDrum","121212121",0);
  local_8 = 6;
  QListWidgetItem::setText(this,pQVar5);
  local_8 = 0xffffffff;
  QString::~QString(local_1c);
  QListWidget::setSortingEnabled((QListWidget *)local_14[4],SUB41(param_2,0));
  ExceptionList = local_10;
  return;
}


