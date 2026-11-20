
void __fastcall FUN_004cf700(char *param_1)

{
  char *pcVar1;
  QVariant *pQVar2;
  QString *pQVar3;
  int iVar4;
  QIcon *pQVar5;
  QChar aQStack_4e [2];
  QVariant local_40 [20];
  int local_2c;
  QString local_28 [4];
  QIcon local_24 [4];
  undefined4 local_20;
  char *local_1c;
  QTypedArrayData<unsigned_short> *local_18;
  QComboBox *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00527f09;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = param_1;
  QWidget::hide(*(QWidget **)(param_1 + 0x38));
  local_20 = CONCAT31(local_20._1_3_,0x20);
  iVar4 = 0;
  do {
    local_14 = *(QComboBox **)(param_1 + 0x1c);
    pQVar2 = (QVariant *)QVariant::QVariant(local_40);
    local_8 = 0;
    local_18 = QString::fromAscii_helper("%1",2);
    local_8._0_1_ = 1;
    local_2c = iVar4 + 1;
    QChar::QChar(aQStack_4e + -6,local_20);
    pQVar3 = (QString *)QString::arg((QString *)&local_18,local_28,iVar4 + 1,0,10);
    local_8._0_1_ = 2;
    iVar4 = QComboBox::count(local_14);
    pQVar5 = (QIcon *)QIcon::QIcon(local_24);
    local_8 = CONCAT31(local_8._1_3_,3);
    QComboBox::insertItem(local_14,iVar4,pQVar5,pQVar3,pQVar2);
    QIcon::~QIcon(local_24);
    QString::~QString(local_28);
    QString::~QString((QString *)&local_18);
    local_8 = 0xffffffff;
    QVariant::~QVariant(local_40);
    pcVar1 = local_1c;
    param_1 = local_1c;
    iVar4 = local_2c;
  } while (local_2c < 10);
  QObject::connect((QObject *)&local_2c,*(char **)(local_1c + 0x24),(QObject *)"2clicked()",local_1c
                   ,0x584344);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  QObject::connect((QObject *)&local_2c,*(char **)(pcVar1 + 0x34),(QObject *)"2clicked()",pcVar1,
                   0x584354);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  QObject::connect((QObject *)&local_2c,*(char **)(pcVar1 + 0x40),(QObject *)"2clicked()",pcVar1,
                   0x584360);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  QObject::connect((QObject *)&local_2c,*(char **)(pcVar1 + 0x3c),(QObject *)"2clicked()",pcVar1,
                   0x584370);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  QObject::connect((QObject *)&local_2c,*(char **)(pcVar1 + 0x30),
                   (QObject *)"2itemClicked(QListWidgetItem*)",pcVar1,0x584380);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  QObject::connect((QObject *)&local_2c,*(char **)(pcVar1 + 0x28),(QObject *)"2valueChanged(int)",
                   pcVar1,0x5843c4);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  QObject::connect((QObject *)local_28,*(char **)(pcVar1 + 0x28),(QObject *)"2sliderMoved(int)",
                   pcVar1,0x5843ec);
  QMetaObject::Connection::~Connection((Connection *)local_28);
  ExceptionList = local_10;
  return;
}


