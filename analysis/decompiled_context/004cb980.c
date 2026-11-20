
void __fastcall FUN_004cb980(char *param_1)

{
  QComboBox *this;
  QComboBox *pQVar1;
  char *pcVar2;
  QVariant *pQVar3;
  QString *pQVar4;
  int iVar5;
  QIcon *pQVar6;
  char *pcVar7;
  QChar aQStack_4e [2];
  QVariant local_40 [20];
  int local_2c;
  QComboBox *local_28;
  QIcon local_24 [4];
  undefined4 local_20;
  QTypedArrayData<unsigned_short> *local_1c;
  QComboBox *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0053792d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = param_1;
  QWidget::hide(*(QWidget **)(param_1 + 0x38));
  local_20 = CONCAT31(local_20._1_3_,0x20);
  iVar5 = 0;
  do {
    local_18 = *(QComboBox **)(param_1 + 0x1c);
    pQVar3 = (QVariant *)QVariant::QVariant(local_40);
    local_8 = 0;
    local_1c = QString::fromAscii_helper("%1",2);
    local_8._0_1_ = 1;
    local_2c = iVar5 + 1;
    QChar::QChar(aQStack_4e + -6,local_20);
    pQVar4 = (QString *)QString::arg((QString *)&local_1c,&local_28,iVar5 + 1,0,10);
    local_8._0_1_ = 2;
    iVar5 = QComboBox::count(local_18);
    pQVar6 = (QIcon *)QIcon::QIcon(local_24);
    local_8 = CONCAT31(local_8._1_3_,3);
    QComboBox::insertItem(local_18,iVar5,pQVar6,pQVar4,pQVar3);
    QIcon::~QIcon(local_24);
    QString::~QString((QString *)&local_28);
    QString::~QString((QString *)&local_1c);
    QVariant::~QVariant(local_40);
    param_1 = local_14;
    iVar5 = local_2c;
  } while (local_2c < 10);
  local_2c = CONCAT31(local_2c._1_3_,0x20);
  local_18 = (QComboBox *)0x1;
  do {
    pQVar1 = local_18;
    this = *(QComboBox **)(local_14 + 0x48);
    local_28 = this;
    pQVar3 = (QVariant *)QVariant::QVariant(local_40);
    local_8 = 4;
    local_1c = QString::fromAscii_helper("%1",2);
    local_8._0_1_ = 5;
    QChar::QChar(aQStack_4e + -6,local_2c);
    pQVar4 = (QString *)QString::arg((QString *)&local_1c,&local_20,pQVar1,0,10);
    local_8._0_1_ = 6;
    iVar5 = QComboBox::count(this);
    pQVar6 = (QIcon *)QIcon::QIcon(local_24);
    local_8 = CONCAT31(local_8._1_3_,7);
    QComboBox::insertItem(local_28,iVar5,pQVar6,pQVar4,pQVar3);
    QIcon::~QIcon(local_24);
    QString::~QString((QString *)&local_20);
    QString::~QString((QString *)&local_1c);
    local_8 = 0xffffffff;
    QVariant::~QVariant(local_40);
    pcVar2 = local_14;
    local_18 = (QComboBox *)((int)local_18 + 1);
  } while ((int)local_18 < 0xb);
  QObject::connect((QObject *)&local_2c,*(char **)(local_14 + 0x48),
                   (QObject *)"2currentIndexChanged(int)",local_14,0x5842d8);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  QObject::connect((QObject *)&local_2c,*(char **)(pcVar2 + 0x9c),(QObject *)"2clicked()",pcVar2,
                   0x58430c);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  QObject::connect((QObject *)&local_2c,*(char **)(pcVar2 + 0x24),(QObject *)"2clicked()",pcVar2,
                   0x584344);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  QObject::connect((QObject *)&local_2c,*(char **)(pcVar2 + 0x34),(QObject *)"2clicked()",pcVar2,
                   0x584354);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  QObject::connect((QObject *)&local_2c,*(char **)(pcVar2 + 0x40),(QObject *)"2clicked()",pcVar2,
                   0x584360);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  QObject::connect((QObject *)&local_2c,*(char **)(pcVar2 + 0x3c),(QObject *)"2clicked()",pcVar2,
                   0x584370);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  QObject::connect((QObject *)&local_2c,*(char **)(pcVar2 + 0x30),
                   (QObject *)"2itemClicked(QListWidgetItem*)",pcVar2,0x584380);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  QObject::connect((QObject *)&local_2c,*(char **)(pcVar2 + 0x28),(QObject *)"2valueChanged(int)",
                   pcVar2,0x5843c4);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  QObject::connect((QObject *)&local_2c,*(char **)(pcVar2 + 0x28),(QObject *)"2sliderMoved(int)",
                   pcVar2,0x5843ec);
  QMetaObject::Connection::~Connection((Connection *)&local_2c);
  local_1c = (QTypedArrayData<unsigned_short> *)0x0;
  if (0 < *(int *)(pcVar2 + 0x110)) {
    pcVar7 = pcVar2 + 0x13c;
    do {
      QObject::connect((QObject *)&local_2c,*(char **)(pcVar7 + 0x28),
                       (QObject *)"2valueChanged(int)",*(char **)pcVar7,0x584438);
      QMetaObject::Connection::~Connection((Connection *)&local_2c);
      QObject::connect((QObject *)&local_28,*(char **)pcVar7,(QObject *)"2valueChanged(int)",
                       *(char **)(pcVar7 + 0x28),0x584438);
      QMetaObject::Connection::~Connection((Connection *)&local_28);
      QObject::connect((QObject *)local_24,*(char **)pcVar7,(QObject *)"2valueChanged(int)",pcVar2,
                       0x584448);
      QMetaObject::Connection::~Connection((Connection *)local_24);
      pcVar7 = pcVar7 + 4;
      local_1c = (QTypedArrayData<unsigned_short> *)((int)local_1c + 1);
    } while ((int)local_1c < *(int *)(pcVar2 + 0x110));
  }
  ExceptionList = local_10;
  return;
}


