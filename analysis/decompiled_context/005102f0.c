
bool __thiscall FUN_005102f0(int *param_1,QString *param_2)

{
  undefined8 *puVar1;
  bool bVar2;
  QString *pQVar3;
  QVariant *pQVar4;
  uint uVar5;
  int iVar6;
  QByteArray *this;
  uint uVar7;
  QString aQStack_10a [2];
  QVariant local_fc [16];
  QString local_ec [16];
  QVariant local_dc [16];
  QString local_cc [16];
  QVariant local_bc [16];
  QString local_ac [16];
  QVariant local_9c [16];
  QString local_8c [16];
  uint local_7c;
  uint uStack_78;
  int local_74;
  QString local_70 [4];
  QString local_6c [4];
  QString local_68 [4];
  QString local_64 [4];
  QString local_60 [4];
  QString local_5c [4];
  QString local_58 [4];
  QString local_54 [4];
  uint local_50;
  QString local_4c [4];
  uint local_48;
  uint local_44;
  QSettings local_40 [8];
  uint local_38;
  QString local_34 [4];
  QString local_30 [4];
  QString local_2c [4];
  QString local_28 [4];
  QString local_24 [4];
  uint local_20;
  int local_1c;
  QString local_18 [4];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pQVar3 = param_2;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0055c241;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = 0;
  bVar2 = QFile::exists(param_2);
  if (!bVar2) {
    ExceptionList = local_10;
    return bVar2;
  }
  QSettings::QSettings(local_40,pQVar3,1,(QObject *)0x0);
  local_8 = 0;
  local_20 = 0;
  if (*param_1 != param_1[1]) {
    param_1[1] = *param_1;
  }
  param_1[3] = 0;
  QString::QString((QString *)&local_1c);
  local_44 = 0xffffffff;
  QString::QString(local_18);
  local_8._0_1_ = 2;
  local_50 = 1;
  uVar7 = 0;
  while( true ) {
    pQVar3 = (QString *)QString::asprintf((char *)local_54,"FLASH %d");
    QString::operator=(local_18,pQVar3);
    QString::~QString(local_54);
    local_8._0_1_ = 3;
    QString::QString(local_24,local_18);
    local_14 = uVar7 | 1;
    pQVar3 = (QString *)QString::fromUtf8((char *)local_58,0x59408c);
    local_8._0_1_ = 4;
    QString::append(local_24,pQVar3);
    local_8._0_1_ = 3;
    QString::~QString(local_58);
    bVar2 = QSettings::contains(local_40,local_24);
    local_14 = uVar7 & 0xfffffffe;
    local_8._0_1_ = 2;
    QString::~QString(local_24);
    if (!bVar2) break;
    QVariant::QVariant(local_9c);
    local_8._0_1_ = 6;
    QString::QString(local_28,local_18);
    uVar7 = local_14;
    local_14 = local_14 | 2;
    pQVar3 = (QString *)QString::fromUtf8((char *)local_5c,0x59408c);
    local_8._0_1_ = 7;
    QString::append(local_28,pQVar3);
    local_8._0_1_ = 6;
    QString::~QString(local_5c);
    pQVar4 = (QVariant *)QSettings::value(local_40,local_8c,(QVariant *)local_28);
    local_8._0_1_ = 8;
    uVar5 = QVariant::toUInt(pQVar4,(bool *)0x0);
    local_38 = uVar5;
    QVariant::~QVariant((QVariant *)local_8c);
    QString::~QString(local_28);
    local_8._0_1_ = 2;
    QVariant::~QVariant(local_9c);
    if (local_44 != 0xffffffff) {
      if (local_44 == uVar5) goto LAB_005104f2;
      param_2 = (QString *)&DAT_0075721c;
LAB_0051083f:
      QString::operator=((QString *)(param_1 + 4),(QString *)&param_2);
      QString::~QString((QString *)&param_2);
      bVar2 = false;
      goto LAB_0051085b;
    }
    local_44 = uVar5;
LAB_005104f2:
    QVariant::QVariant(local_bc);
    local_8._0_1_ = 10;
    QString::QString(local_2c,local_18);
    local_14 = uVar7 & 0xfffffffd | 4;
    pQVar3 = (QString *)QString::fromUtf8((char *)local_60,0x594094);
    local_8._0_1_ = 0xb;
    QString::append(local_2c,pQVar3);
    local_8._0_1_ = 10;
    QString::~QString(local_60);
    pQVar4 = (QVariant *)QSettings::value(local_40,local_ac,(QVariant *)local_2c);
    local_8._0_1_ = 0xc;
    pQVar3 = (QString *)QVariant::toString(pQVar4);
    QString::operator=((QString *)&local_1c,pQVar3);
    QString::~QString(local_64);
    QVariant::~QVariant((QVariant *)local_ac);
    QString::~QString(local_2c);
    local_8._0_1_ = 2;
    QVariant::~QVariant(local_bc);
    if (*(int *)(local_1c + 4) == 0) {
      param_2 = (QString *)&DAT_00757284;
      goto LAB_0051083f;
    }
    QString::QString(aQStack_10a + -6,(QString *)&local_1c);
    local_48 = FUN_005101a0();
    if ((local_20 != 0) && (local_20 != local_48)) {
      this = (QByteArray *)QString::toLatin1(local_18);
      local_8._0_1_ = 0xd;
      QByteArray::data(this);
      pQVar3 = (QString *)QString::asprintf((char *)&param_2,"%s address not follow the last flash")
      ;
      QString::operator=((QString *)(param_1 + 4),pQVar3);
      QString::~QString((QString *)&param_2);
      QByteArray::~QByteArray((QByteArray *)&local_38);
      bVar2 = false;
      goto LAB_0051085b;
    }
    QVariant::QVariant(local_dc);
    local_8._0_1_ = 0xf;
    QString::QString(local_30,local_18);
    local_14 = uVar7 & 0xfffffff9 | 8;
    pQVar3 = (QString *)QString::fromUtf8((char *)local_68,0x5940cc);
    local_8._0_1_ = 0x10;
    QString::append(local_30,pQVar3);
    local_8._0_1_ = 0xf;
    QString::~QString(local_68);
    pQVar4 = (QVariant *)QSettings::value(local_40,local_cc,(QVariant *)local_30);
    local_8._0_1_ = 0x11;
    pQVar3 = (QString *)QVariant::toString(pQVar4);
    QString::operator=((QString *)&local_1c,pQVar3);
    QString::~QString(local_6c);
    QVariant::~QVariant((QVariant *)local_cc);
    QString::~QString(local_30);
    local_8._0_1_ = 2;
    QVariant::~QVariant(local_dc);
    if (*(int *)(local_1c + 4) == 0) {
      param_2 = (QString *)&DAT_007572d0;
      goto LAB_0051083f;
    }
    QString::QString(aQStack_10a + -6,(QString *)&local_1c);
    local_20 = FUN_005101a0();
    QVariant::QVariant(local_fc);
    local_8._0_1_ = 0x13;
    QString::QString(local_34,local_18);
    local_14 = uVar7 & 0xfffffff1 | 0x10;
    pQVar3 = (QString *)QString::fromUtf8((char *)local_70,0x5940dc);
    local_8._0_1_ = 0x14;
    QString::append(local_34,pQVar3);
    local_8._0_1_ = 0x13;
    QString::~QString(local_70);
    pQVar4 = (QVariant *)QSettings::value(local_40,local_ec,(QVariant *)local_34);
    local_8._0_1_ = 0x15;
    QVariant::toString(pQVar4);
    QVariant::~QVariant((QVariant *)local_ec);
    local_14 = uVar7 & 0xffffffe1;
    QString::~QString(local_34);
    local_8 = CONCAT31(local_8._1_3_,0x19);
    QVariant::~QVariant(local_fc);
    QString::QString(aQStack_10a + -6,local_4c);
    iVar6 = FUN_005101a0();
    uVar7 = local_20;
    uVar5 = local_48;
    if (local_48 < local_20) {
      do {
        local_7c = local_38;
        puVar1 = (undefined8 *)param_1[1];
        uStack_78 = uVar5;
        local_74 = iVar6;
        if (puVar1 == (undefined8 *)param_1[2]) {
          FUN_0050ff30(puVar1);
          uVar7 = local_20;
        }
        else {
          *puVar1 = CONCAT44(uVar5,local_38);
          *(int *)(puVar1 + 1) = iVar6;
          param_1[1] = param_1[1] + 0xc;
        }
        uVar5 = uVar5 + iVar6;
      } while (uVar5 < uVar7);
    }
    param_1[3] = param_1[3] + (uVar7 - local_48);
    local_8._0_1_ = 2;
    QString::~QString(local_4c);
    local_50 = local_50 + 1;
    if (99 < local_50) break;
    uVar7 = local_14;
  }
  bVar2 = true;
LAB_0051085b:
  QString::~QString(local_18);
  QString::~QString((QString *)&local_1c);
  QSettings::~QSettings(local_40);
  ExceptionList = local_10;
  return bVar2;
}


