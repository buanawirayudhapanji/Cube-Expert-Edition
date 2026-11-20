
void __fastcall FUN_00485d60(QWidget *param_1)

{
  char cVar1;
  QString *pQVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  QChar aQStack_72 [2];
  QString local_38 [4];
  QString local_34 [4];
  QString local_30 [4];
  QString local_2c [4];
  int local_28;
  QString *local_24;
  QTypedArrayData<unsigned_short> *local_20;
  QTypedArrayData<unsigned_short> *local_1c;
  QTypedArrayData<unsigned_short> *local_18;
  QTypedArrayData<unsigned_short> *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0051ba54;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = QString::fromAscii_helper("CubeSuite V2.8.10",0x11);
  local_8 = 0;
  if (*(int *)(*(int *)(param_1 + 0x2c) + 0xc844) == 3) {
    pcVar6 = " - (No device connected !)";
  }
  else {
    cVar1 = FUN_005069b0();
    if (cVar1 == '\0') {
      pcVar6 = " - (Please enter update mode !)";
    }
    else {
      local_28 = FUN_00488eb0();
      if (local_28 != 0) {
        local_20 = QString::fromAscii_helper("%1 - (Connected - %2, Ver=V%3)",0x1e);
        local_8._0_1_ = 1;
        local_1c = QString::fromAscii_helper("CubeSuite V2.8.10",0x11);
        local_24 = (QString *)CONCAT31(local_24._1_3_,0x20);
        local_8._0_1_ = 2;
        QChar::QChar(aQStack_72 + -6,local_24);
        local_24 = (QString *)QString::arg((QString *)&local_20,local_38,&local_1c,0);
        local_8._0_1_ = 3;
        pcVar6 = (char *)(local_28 + 4);
        if (pcVar6 == (char *)0x0) {
          iVar5 = -1;
        }
        else {
          pcVar4 = pcVar6;
          do {
            cVar1 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar1 != '\0');
          iVar5 = (int)pcVar4 - (local_28 + 5);
        }
        local_18 = QString::fromAscii_helper(pcVar6,iVar5);
        local_28 = CONCAT31(local_28._1_3_,0x20);
        local_8._0_1_ = 4;
        QChar::QChar(aQStack_72 + -6,local_28);
        pQVar2 = (QString *)QString::arg(local_24,local_34,&local_18,0);
        local_8._0_1_ = 5;
        uVar3 = FUN_00487560(local_30);
        local_28 = CONCAT31(local_28._1_3_,0x20);
        local_8._0_1_ = 6;
        QChar::QChar(aQStack_72 + -6,local_28);
        pQVar2 = (QString *)QString::arg(pQVar2,local_2c,uVar3,0);
        QString::operator=((QString *)&local_14,pQVar2);
        QString::~QString(local_2c);
        QString::~QString(local_30);
        QString::~QString(local_34);
        QString::~QString((QString *)&local_18);
        QString::~QString(local_38);
        QString::~QString((QString *)&local_1c);
        local_8 = (uint)local_8._1_3_ << 8;
        QString::~QString((QString *)&local_20);
        goto LAB_00485f45;
      }
      pcVar6 = " - (Unknown device connected !)";
      local_28 = 0;
    }
  }
  QString::operator+=((QString *)&local_14,pcVar6);
LAB_00485f45:
  QWidget::setWindowTitle(param_1,(QString *)&local_14);
  QString::~QString((QString *)&local_14);
  ExceptionList = local_10;
  return;
}


