
void __fastcall FUN_00491e80(char *param_1)

{
  QComboBox *pQVar1;
  QVariant *pQVar2;
  QString *pQVar3;
  int iVar4;
  QIcon *pQVar5;
  char *pcVar6;
  QChar aQStack_4e [2];
  QVariant local_40 [20];
  int local_2c;
  QString local_28 [4];
  QIcon local_24 [4];
  undefined4 local_20;
  QTypedArrayData<unsigned_short> *local_1c;
  QComboBox *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0052673a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = param_1;
  QWidget::hide(*(QWidget **)(param_1 + 0x6c));
  local_20 = CONCAT31(local_20._1_3_,0x20);
  iVar4 = 0;
  do {
    local_18 = *(QComboBox **)(param_1 + 0x50);
    pQVar2 = (QVariant *)QVariant::QVariant(local_40);
    local_8 = 0;
    local_1c = QString::fromAscii_helper("%1",2);
    local_8._0_1_ = 1;
    local_2c = iVar4 + 1;
    QChar::QChar(aQStack_4e + -6,local_20);
    pQVar3 = (QString *)QString::arg((QString *)&local_1c,local_28,iVar4 + 1,0,10);
    local_8._0_1_ = 2;
    iVar4 = QComboBox::count(local_18);
    pQVar5 = (QIcon *)QIcon::QIcon(local_24);
    local_8 = CONCAT31(local_8._1_3_,3);
    QComboBox::insertItem(local_18,iVar4,pQVar5,pQVar3,pQVar2);
    QIcon::~QIcon(local_24);
    QString::~QString(local_28);
    QString::~QString((QString *)&local_1c);
    QVariant::~QVariant(local_40);
    param_1 = local_14;
    iVar4 = local_2c;
  } while (local_2c < 8);
  pQVar1 = *(QComboBox **)(local_14 + 0x7c);
  pQVar2 = (QVariant *)QVariant::QVariant(local_40);
  local_8 = 4;
  local_1c = QString::fromAscii_helper("A",1);
  local_8._0_1_ = 5;
  iVar4 = QComboBox::count(pQVar1);
  pQVar5 = (QIcon *)QIcon::QIcon((QIcon *)&local_2c);
  local_8 = CONCAT31(local_8._1_3_,6);
  QComboBox::insertItem(pQVar1,iVar4,pQVar5,(QString *)&local_1c,pQVar2);
  QIcon::~QIcon((QIcon *)&local_2c);
  QString::~QString((QString *)&local_1c);
  QVariant::~QVariant(local_40);
  pQVar1 = *(QComboBox **)(local_14 + 0x7c);
  pQVar2 = (QVariant *)QVariant::QVariant(local_40);
  local_8 = 7;
  local_1c = QString::fromAscii_helper("B",1);
  local_8._0_1_ = 8;
  iVar4 = QComboBox::count(pQVar1);
  pQVar5 = (QIcon *)QIcon::QIcon((QIcon *)&local_2c);
  local_8 = CONCAT31(local_8._1_3_,9);
  QComboBox::insertItem(pQVar1,iVar4,pQVar5,(QString *)&local_1c,pQVar2);
  QIcon::~QIcon((QIcon *)&local_2c);
  QString::~QString((QString *)&local_1c);
  QVariant::~QVariant(local_40);
  pQVar1 = *(QComboBox **)(local_14 + 0x7c);
  pQVar2 = (QVariant *)QVariant::QVariant(local_40);
  local_8 = 10;
  local_1c = QString::fromAscii_helper("C",1);
  local_8._0_1_ = 0xb;
  iVar4 = QComboBox::count(pQVar1);
  pQVar5 = (QIcon *)QIcon::QIcon((QIcon *)&local_2c);
  local_8 = CONCAT31(local_8._1_3_,0xc);
  QComboBox::insertItem(pQVar1,iVar4,pQVar5,(QString *)&local_1c,pQVar2);
  QIcon::~QIcon((QIcon *)&local_2c);
  QString::~QString((QString *)&local_1c);
  local_8 = 0xffffffff;
  QVariant::~QVariant(local_40);
  pcVar6 = local_14;
  QObject::connect((QObject *)&local_2c,*(char **)(local_14 + 0x7c),
                   (QObject *)"2currentIndexChanged(int)",local_14,0x5842d8);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  QObject::connect((QObject *)&local_2c,*(char **)(pcVar6 + 0xd0),(QObject *)"2clicked()",pcVar6,
                   0x58430c);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  QObject::connect((QObject *)&local_2c,*(char **)(pcVar6 + 0x120),(QObject *)"2toggled(bool)",
                   pcVar6,0x58431c);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  QObject::connect((QObject *)&local_2c,*(char **)(pcVar6 + 0x58),(QObject *)"2clicked()",pcVar6,
                   0x584344);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  QObject::connect((QObject *)&local_2c,*(char **)(pcVar6 + 0x68),(QObject *)"2clicked()",pcVar6,
                   0x584354);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  QObject::connect((QObject *)&local_2c,*(char **)(pcVar6 + 0x74),(QObject *)"2clicked()",pcVar6,
                   0x584360);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  QObject::connect((QObject *)&local_2c,*(char **)(pcVar6 + 0x70),(QObject *)"2clicked()",pcVar6,
                   0x584370);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  QObject::connect((QObject *)&local_2c,*(char **)(pcVar6 + 100),
                   (QObject *)"2itemClicked(QListWidgetItem*)",pcVar6,0x584380);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  QObject::connect((QObject *)&local_2c,*(char **)(pcVar6 + 0x5c),(QObject *)"2valueChanged(int)",
                   pcVar6,0x5843c4);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  QObject::connect((QObject *)&local_2c,*(char **)(pcVar6 + 0x5c),(QObject *)"2sliderMoved(int)",
                   pcVar6,0x5843ec);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  QObject::connect((QObject *)&local_2c,*(char **)(pcVar6 + 0xfc),(QObject *)"2clicked()",pcVar6,
                   0x584414);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  QObject::connect((QObject *)&local_2c,*(char **)(pcVar6 + 0x110),(QObject *)"2clicked()",pcVar6,
                   0x584420);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  QObject::connect((QObject *)&local_2c,*(char **)(pcVar6 + 0x114),(QObject *)"2clicked()",pcVar6,
                   0x58442c);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  pcVar6 = pcVar6 + 0x198;
  local_1c = (QTypedArrayData<unsigned_short> *)0xa;
  do {
    QObject::connect((QObject *)&local_2c,*(char **)pcVar6,(QObject *)"2valueChanged(int)",
                     *(char **)(pcVar6 + 0x28),0x584438);
    QMetaObject::Connection::~Connection((Connection *)&local_2c);
    QObject::connect((QObject *)local_28,*(char **)(pcVar6 + 0x28),(QObject *)"2valueChanged(int)",
                     *(char **)pcVar6,0x584438);
    QMetaObject::Connection::~Connection((Connection *)local_28);
    QObject::connect((QObject *)local_24,*(char **)pcVar6,(QObject *)"2valueChanged(int)",local_14,
                     0x584448);
    QMetaObject::Connection::~Connection((Connection *)local_24);
    local_1c = (QTypedArrayData<unsigned_short> *)((int)local_1c + -1);
    pcVar6 = pcVar6 + 4;
  } while (local_1c != (QTypedArrayData<unsigned_short> *)0x0);
  ExceptionList = local_10;
  return;
}


