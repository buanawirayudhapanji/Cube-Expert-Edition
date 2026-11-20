
void FUN_004dff60(void)

{
  bool bVar1;
  QStringList *pQVar2;
  int iVar3;
  QMessageLogger *this;
  QDebug *this_00;
  QFont *pQVar4;
  undefined4 uVar5;
  QMessageLogger local_3c [20];
  QFont local_28 [8];
  QTypedArrayData<unsigned_short> *local_20;
  QFontDatabase local_1c [4];
  QTypedArrayData<unsigned_short> *local_18;
  QTypedArrayData<unsigned_short> *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0053f32a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  QFontDatabase::QFontDatabase(local_1c);
  uVar5 = 0;
  pQVar2 = (QStringList *)QFontDatabase::families(local_1c,(WritingSystem)&local_18);
  local_8 = 0;
  local_14 = QString::fromAscii_helper("FontAwesome",0xb);
  local_8 = CONCAT31(local_8._1_3_,1);
  bVar1 = QtPrivate::QStringList_contains(pQVar2,(QString *)&local_14,1);
  QString::~QString((QString *)&local_14);
  local_8 = 0xffffffff;
  FUN_00486b10(uVar5);
  if (!bVar1) {
    local_14 = QString::fromAscii_helper(":/Font/fontawesome",0x12);
    local_8 = 2;
    QFontDatabase::addApplicationFont((QString *)&local_14);
    local_8 = 0xffffffff;
    QString::~QString((QString *)&local_14);
    QFontDatabase::applicationFontFamilies((int)&local_18);
    local_8 = 3;
    iVar3 = QListData::size((QListData *)&local_18);
    if (iVar3 == 0) {
      this = (QMessageLogger *)QMessageLogger::QMessageLogger(local_3c,(char *)0x0,0,(char *)0x0);
      this_00 = (QDebug *)QMessageLogger::debug(this);
      local_8 = CONCAT31(local_8._1_3_,4);
      QDebug::operator<<(this_00,"load fontawesome-webfont.ttf error");
      QDebug::~QDebug((QDebug *)&local_20);
    }
    local_8 = 0xffffffff;
    FUN_00486b10();
  }
  uVar5 = 0;
  pQVar2 = (QStringList *)QFontDatabase::families(local_1c,(WritingSystem)&local_14);
  local_8 = 5;
  local_18 = QString::fromAscii_helper("FontAwesome",0xb);
  local_8 = CONCAT31(local_8._1_3_,6);
  bVar1 = QtPrivate::QStringList_contains(pQVar2,(QString *)&local_18,1);
  QString::~QString((QString *)&local_18);
  local_8 = 0xffffffff;
  FUN_00486b10(uVar5);
  if (bVar1) {
    local_20 = QString::fromAscii_helper("FontAwesome",0xb);
    local_8 = 7;
    pQVar4 = (QFont *)QFont::QFont(local_28,(QString *)&local_20,-1,-1,false);
    QFont::operator=((QFont *)&DAT_007626a0,pQVar4);
    QFont::~QFont(local_28);
    local_8 = 0xffffffff;
    QString::~QString((QString *)&local_20);
    QFont::setHintingPreference((QFont *)&DAT_007626a0,1);
  }
  QFont::setPixelSize((QFont *)&DAT_007626a0,0x19);
  ExceptionList = local_10;
  return;
}


