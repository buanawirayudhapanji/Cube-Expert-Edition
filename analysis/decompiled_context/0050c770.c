
QWidget * __thiscall FUN_0050c770(QWidget *param_1,undefined4 param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005561f6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  QWidget::QWidget(param_1,param_2,0,DAT_00759b24 ^ (int)register0x00000010 - 4U);
  local_8 = 0;
  *(undefined ***)param_1 = SwitchControl::vftable;
  *(undefined ***)(param_1 + 8) = SwitchControl::vftable;
  param_1[0x18] = (QWidget)0x0;
  QColor::QColor((QColor *)(param_1 + 0x1c),0xaa,0xaa,0xaa,0xff);
  QColor::QColor((QColor *)(param_1 + 0x2c),3);
  QColor::QColor((QColor *)(param_1 + 0x3c),0x33,0xea,0xb8,0xff);
  QColor::QColor((QColor *)(param_1 + 0x4c),0xaa,0xaa,0xaa,0xff);
  QColor::QColor((QColor *)(param_1 + 0x5c),3);
  *(undefined8 *)(param_1 + 0x70) = DAT_00593e70;
  *(undefined8 *)(param_1 + 0x88) = DAT_00593e60;
  QTimer::QTimer((QTimer *)(param_1 + 0x98),(QObject *)0x0);
  local_8._0_1_ = 1;
  QCursor::QCursor((QCursor *)&param_2,0xd);
  local_8._0_1_ = 2;
  QWidget::setCursor(param_1,(QCursor *)&param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  QCursor::~QCursor((QCursor *)&param_2);
  QObject::connect((QObject *)&param_2,(char *)(param_1 + 0x98),(QObject *)"2timeout()",
                   (char *)param_1,0x593e40);
  QMetaObject::Connection::~Connection((Connection *)&param_2);
  ExceptionList = local_10;
  return param_1;
}


