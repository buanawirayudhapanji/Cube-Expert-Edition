
void __fastcall FUN_00505d00(QWidget *param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  QString *pQVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  code *pcVar8;
  uint uVar9;
  QChar aQStack_76 [2];
  undefined4 local_40;
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
  
  pcVar8 = fromAscii_helper_exref;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054d2b6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = QString::fromAscii_helper("CubeSuite V2.8.10",0x11);
  local_8 = 0;
  if (*(int *)(*(int *)(param_1 + 0x4c) + 0xc844) == 3) {
    pcVar7 = " - (No device connected !)";
  }
  else {
    cVar2 = FUN_005069b0();
    if (cVar2 != '\0') {
      iVar1 = *(int *)(*(int *)(param_1 + 0x4c) + 0x2ca68);
      local_28 = FUN_00488eb0();
      if (local_28 == 0) {
        QString::operator+=((QString *)&local_18," - (Unknown device connected !)");
      }
      else {
        local_20 = QString::fromAscii_helper("%1 - (Connected - %2, Ver=V%3)",0x1e);
        local_8._0_1_ = 1;
        local_1c = QString::fromAscii_helper("CubeSuite V2.8.10",0x11);
        local_24 = (QString *)CONCAT31(local_24._1_3_,0x20);
        local_8._0_1_ = 2;
        QChar::QChar(aQStack_76 + -6,local_24);
        local_24 = (QString *)QString::arg((QString *)&local_20,local_38,&local_1c,0);
        local_8._0_1_ = 3;
        pcVar7 = (char *)(local_28 + 4);
        if (pcVar7 == (char *)0x0) {
          iVar6 = -1;
        }
        else {
          pcVar5 = pcVar7;
          do {
            cVar2 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar2 != '\0');
          iVar6 = (int)pcVar5 - (local_28 + 5);
        }
        local_14 = QString::fromAscii_helper(pcVar7,iVar6);
        local_28 = CONCAT31(local_28._1_3_,0x20);
        local_8._0_1_ = 4;
        QChar::QChar(aQStack_76 + -6,local_28);
        pQVar4 = (QString *)QString::arg(local_24,local_34,&local_14,0);
        local_8._0_1_ = 5;
        uVar3 = FUN_00487560(local_30);
        local_28 = CONCAT31(local_28._1_3_,0x20);
        local_8._0_1_ = 6;
        QChar::QChar(aQStack_76 + -6,local_28);
        pQVar4 = (QString *)QString::arg(pQVar4,local_2c,uVar3,0);
        QString::operator=((QString *)&local_18,pQVar4);
        QString::~QString(local_2c);
        QString::~QString(local_30);
        QString::~QString(local_34);
        QString::~QString((QString *)&local_14);
        QString::~QString(local_38);
        QString::~QString((QString *)&local_1c);
        local_8 = (uint)local_8._1_3_ << 8;
        QString::~QString((QString *)&local_20);
        pcVar8 = fromAscii_helper_exref;
      }
      if ((iVar1 == 0x272b) || (iVar1 == 0x272c)) {
        FUN_005063f0(1,0xfffffff0,&local_14,2);
        local_20 = (QTypedArrayData<unsigned_short> *)(*pcVar8)(&DAT_005933b0);
        uVar9 = (uint)local_14 & 0xffff;
        local_40 = CONCAT31((int3)((uint)iVar1 >> 8),0x20);
        local_8._0_1_ = 7;
        QChar::QChar(aQStack_76 + -6,local_40);
        pQVar4 = (QString *)QString::arg((QString *)&local_20,local_38,uVar9,2,0x10);
        local_8._0_1_ = 8;
        QString::append((QString *)&local_18,pQVar4);
        QString::~QString(local_38);
        local_8 = (uint)local_8._1_3_ << 8;
        QString::~QString((QString *)&local_20);
      }
      goto LAB_00505f7c;
    }
    pcVar7 = " - (Please enter update mode !)";
  }
  QString::operator+=((QString *)&local_18,pcVar7);
LAB_00505f7c:
  QWidget::setWindowTitle(param_1,(QString *)&local_18);
  QString::~QString((QString *)&local_18);
  ExceptionList = local_10;
  return;
}


