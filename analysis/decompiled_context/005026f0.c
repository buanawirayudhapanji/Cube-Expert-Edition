
void __fastcall FUN_005026f0(int param_1)

{
  QString *pQVar1;
  QVariant *this;
  QString *pQVar2;
  QString local_60 [16];
  QVariant local_50 [8];
  QSettings local_48 [8];
  QSettings local_40 [4];
  QString local_3c [4];
  QString local_38 [4];
  QString local_34 [4];
  QTypedArrayData<unsigned_short> *local_30;
  undefined4 local_2c;
  undefined *local_28;
  QTypedArrayData<unsigned_short> *local_24;
  QString local_20 [4];
  undefined *local_1c;
  QString local_18 [4];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0054ca79;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_2c = 0;
  local_28 = &DAT_007568a8;
  local_8 = 0;
  local_24 = QString::fromAscii_helper("/Config/FirmwareDir",0x13);
  local_8._0_1_ = 1;
  pQVar1 = (QString *)QCoreApplication::applicationDirPath();
  local_8._0_1_ = 3;
  QString::QString(local_18,pQVar1);
  local_2c = 2;
  pQVar1 = (QString *)QString::fromUtf8((char *)&local_30,0x580f48);
  local_8._0_1_ = 4;
  QString::append(local_18,pQVar1);
  local_8._0_1_ = 3;
  QString::~QString((QString *)&local_30);
  QSettings::QSettings(local_40,local_18,1,(QObject *)0x0);
  QString::~QString(local_18);
  QString::~QString(local_34);
  QVariant::QVariant(local_50);
  local_8._0_1_ = 8;
  this = (QVariant *)QSettings::value(local_40,local_60,(QVariant *)&local_24);
  local_8._0_1_ = 9;
  QVariant::toString(this);
  QVariant::~QVariant((QVariant *)local_60);
  QVariant::~QVariant(local_50);
  QSettings::~QSettings(local_40);
  local_1c = &DAT_00756870;
  local_8._0_1_ = 0xb;
  QFileDialog::getOpenFileName(&local_14,param_1,&local_1c,local_20,&local_28,0,0);
  QString::~QString((QString *)&local_1c);
  QString::~QString(local_20);
  QString::~QString((QString *)&local_24);
  local_8._0_1_ = 0x10;
  QString::~QString((QString *)&local_28);
  if (*(int *)(local_14 + 4) != 0) {
    pQVar1 = (QString *)FUN_004876a0(local_3c,&local_14);
    local_8._0_1_ = 0x11;
    local_30 = QString::fromAscii_helper("/Config/FirmwareDir",0x13);
    local_8._0_1_ = 0x12;
    pQVar2 = (QString *)QCoreApplication::applicationDirPath();
    local_8._0_1_ = 0x14;
    QString::QString(local_18,pQVar2);
    local_2c = 5;
    pQVar2 = (QString *)QString::fromUtf8((char *)local_34,0x580f48);
    local_8._0_1_ = 0x15;
    QString::append(local_18,pQVar2);
    local_8._0_1_ = 0x14;
    QString::~QString(local_34);
    QSettings::QSettings(local_48,local_18,1,(QObject *)0x0);
    QString::~QString(local_18);
    local_8._0_1_ = 0x18;
    QString::~QString(local_38);
    QVariant::QVariant((QVariant *)local_60,pQVar1);
    local_8._0_1_ = 0x19;
    QSettings::setValue(local_48,(QString *)&local_30,(QVariant *)local_60);
    QVariant::~QVariant((QVariant *)local_60);
    QSettings::~QSettings(local_48);
    QString::~QString((QString *)&local_30);
    local_8._0_1_ = 0x10;
    QString::~QString(local_3c);
    QLineEdit::setText(*(QLineEdit **)(param_1 + 0x20),(QString *)&local_14);
  }
  QString::~QString((QString *)&local_14);
  ExceptionList = local_10;
  return;
}


