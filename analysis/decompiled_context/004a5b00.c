
QDialog * __thiscall
FUN_004a5b00(QDialog *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  QWidget *this;
  QString *pQVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0052ba02;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  QDialog::QDialog(param_1,param_3,param_4,DAT_00759b24 ^ (int)register0x00000010 - 4U);
  *(undefined ***)(param_1 + 8) = BaseDialog::vftable;
  *(undefined ***)param_1 = CCubeSugarIREditDlg::vftable;
  *(undefined ***)(param_1 + 8) = CCubeSugarIREditDlg::vftable;
  *(code **)(param_1 + 0x44) = shared_null_exref;
  local_8 = 1;
  FUN_0050a570();
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  local_8._0_1_ = 4;
  memset(param_1 + 0x88,0,0x810);
  FUN_004a74c0(param_1);
  FUN_004a71d0();
  QWidget::setWindowFlags((QWidget *)param_1,*(uint *)(*(int *)(param_1 + 0x14) + 8) & 0xfffe7fff);
  QWidget::setWindowFlags((QWidget *)param_1,*(uint *)(*(int *)(param_1 + 0x14) + 8) | 0x100);
  *(undefined4 *)(param_1 + 0x40) = param_2;
  QObject::connect((QObject *)&param_3,*(char **)(param_1 + 0x1c),(QObject *)"2clicked()",
                   (char *)param_1,0x5859fc);
  QMetaObject::Connection::~Connection((Connection *)&param_3);
  QObject::connect((QObject *)&param_3,*(char **)(param_1 + 0x24),(QObject *)"2clicked()",
                   (char *)param_1,0x584354);
  QMetaObject::Connection::~Connection((Connection *)&param_3);
  QObject::connect((QObject *)&param_3,*(char **)(param_1 + 0x34),(QObject *)"2clicked()",
                   (char *)param_1,0x585a0c);
  QMetaObject::Connection::~Connection((Connection *)&param_3);
  QObject::connect((QObject *)&param_3,*(char **)(param_1 + 0x18),
                   (QObject *)"2itemClicked(QListWidgetItem*)",(char *)param_1,0x584380);
  QMetaObject::Connection::~Connection((Connection *)&param_3);
  QObject::connect((QObject *)&param_3,*(char **)(param_1 + 0x3c),(QObject *)"2valueChanged(int)",
                   (char *)param_1,0x5843c4);
  QMetaObject::Connection::~Connection((Connection *)&param_3);
  QObject::connect((QObject *)&param_3,*(char **)(param_1 + 0x3c),(QObject *)"2sliderMoved(int)",
                   (char *)param_1,0x5843ec);
  QMetaObject::Connection::~Connection((Connection *)&param_3);
  QWidget::setAcceptDrops(*(QWidget **)(param_1 + 0x18),false);
  FUN_004894e0(1,0x96,1);
  QAbstractSlider::setValue(*(QAbstractSlider **)(param_1 + 0x3c),100);
  this = *(QWidget **)(param_1 + 0x3c);
  pQVar1 = (QString *)QString::asprintf((char *)&param_3,&DAT_005842a8,100);
  local_8 = CONCAT31(local_8._1_3_,5);
  QWidget::setToolTip(this,pQVar1);
  QString::~QString((QString *)&param_3);
  ExceptionList = local_10;
  return param_1;
}


