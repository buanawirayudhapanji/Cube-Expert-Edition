
void __fastcall FUN_004e0d10(QWidget *param_1)

{
  char cVar1;
  QString *pQVar2;
  undefined4 uVar3;
  QMessageLogger *this;
  QDebug *this_00;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  QChar aQStack_82 [2];
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined8 local_58;
  QString local_50 [4];
  QString local_4c [4];
  QString local_48 [12];
  undefined4 local_3c;
  QString local_38 [4];
  QString local_34 [4];
  QString local_30 [4];
  int local_2c;
  QString *local_28;
  QWidget *local_24;
  QTypedArrayData<unsigned_short> *local_20;
  QTypedArrayData<unsigned_short> *local_1c;
  QTypedArrayData<unsigned_short> *local_18;
  QTypedArrayData<unsigned_short> *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0053f579;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_24 = param_1;
  local_14 = QString::fromAscii_helper("CubeSuite V2.8.10",0x11);
  iVar5 = *(int *)(param_1 + 0x28);
  local_8 = 0;
  if (*(int *)(iVar5 + 0xc844) == 3) {
    pcVar6 = " - (No device connected !)";
  }
  else {
    uStack_64 = *(undefined4 *)(iVar5 + 0x2ca78);
    uStack_60 = *(undefined4 *)(iVar5 + 0x2ca7c);
    uStack_5c = *(undefined4 *)(iVar5 + 0x2ca80);
    local_58 = *(undefined8 *)(iVar5 + 0x2ca84);
    local_2c = FUN_00488eb0();
    if (local_2c != 0) {
      if (*(int *)(*(int *)(param_1 + 0x28) + 0x2caa0) == 0) {
        local_20 = QString::fromAscii_helper("%1 - (%2, Ver=V%3)",0x12);
        local_8._0_1_ = 1;
        local_1c = QString::fromAscii_helper("CubeSuite V2.8.10",0x11);
        local_28 = (QString *)CONCAT31(local_28._1_3_,0x20);
        local_8._0_1_ = 2;
        QChar::QChar(aQStack_82 + -6,local_28);
        local_28 = (QString *)QString::arg((QString *)&local_20,&local_3c,&local_1c,0);
        local_8._0_1_ = 3;
        pcVar6 = (char *)(local_2c + 4);
        if (pcVar6 == (char *)0x0) {
          iVar5 = -1;
        }
        else {
          local_2c = local_2c + 5;
          pcVar4 = pcVar6;
          do {
            cVar1 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar1 != '\0');
          iVar5 = (int)pcVar4 - local_2c;
        }
        local_18 = QString::fromAscii_helper(pcVar6,iVar5);
        local_2c = CONCAT31(local_2c._1_3_,0x20);
        local_8._0_1_ = 4;
        QChar::QChar(aQStack_82 + -6,local_2c);
        pQVar2 = (QString *)QString::arg(local_28,local_38,&local_18,0);
        local_8._0_1_ = 5;
        uVar3 = FUN_00487560(local_34);
        local_2c = CONCAT31(local_2c._1_3_,0x20);
        local_8._0_1_ = 6;
        QChar::QChar(aQStack_82 + -6,local_2c);
        pQVar2 = (QString *)QString::arg(pQVar2,local_30,uVar3,0);
        QString::operator=((QString *)&local_14,pQVar2);
        QString::~QString(local_30);
        QString::~QString(local_34);
        QString::~QString(local_38);
        QString::~QString((QString *)&local_18);
        QString::~QString((QString *)&local_3c);
        QString::~QString((QString *)&local_1c);
        local_8 = (uint)local_8._1_3_ << 8;
        QString::~QString((QString *)&local_20);
        param_1 = local_24;
      }
      else if (*(int *)(*(int *)(param_1 + 0x28) + 0x2caa0) == 1) {
        FUN_004e0160();
        local_8._0_1_ = 7;
        this = (QMessageLogger *)
               QMessageLogger::QMessageLogger
                         ((QMessageLogger *)&uStack_64,(char *)0x0,0,(char *)0x0);
        this_00 = (QDebug *)QMessageLogger::debug(this);
        local_8._0_1_ = 8;
        QDebug::operator<<(this_00,local_50);
        local_8._0_1_ = 7;
        QDebug::~QDebug((QDebug *)&local_3c);
        local_1c = QString::fromAscii_helper("%1 - [%2,%3]",0xc);
        local_8._0_1_ = 9;
        local_20 = QString::fromAscii_helper("CubeSuite V2.8.10",0x11);
        local_3c = CONCAT31(local_3c._1_3_,0x20);
        local_8._0_1_ = 10;
        QChar::QChar(aQStack_82 + -6,local_3c);
        pQVar2 = (QString *)QString::arg((QString *)&local_1c,local_30,&local_20,0);
        local_3c = CONCAT31(local_3c._1_3_,0x20);
        local_8._0_1_ = 0xb;
        QChar::QChar(aQStack_82 + -6,local_3c);
        pQVar2 = (QString *)QString::arg(pQVar2,local_34,local_50,0);
        local_3c = CONCAT31(local_3c._1_3_,0x20);
        local_8._0_1_ = 0xc;
        QChar::QChar(aQStack_82 + -6,local_3c);
        pQVar2 = (QString *)QString::arg(pQVar2,local_38,local_4c,0);
        QString::operator=((QString *)&local_14,pQVar2);
        QString::~QString(local_38);
        QString::~QString(local_34);
        QString::~QString(local_30);
        QString::~QString((QString *)&local_20);
        QString::~QString((QString *)&local_1c);
        local_8 = (uint)local_8._1_3_ << 8;
        QString::~QString(local_48);
        QString::~QString(local_4c);
        QString::~QString(local_50);
        param_1 = local_24;
      }
      goto LAB_004e102f;
    }
    pcVar6 = " - (Unknown device connected !)";
  }
  QString::operator+=((QString *)&local_14,pcVar6);
LAB_004e102f:
  QWidget::setWindowTitle(param_1,(QString *)&local_14);
  QString::~QString((QString *)&local_14);
  ExceptionList = local_10;
  return;
}


