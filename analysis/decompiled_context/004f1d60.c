
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_004f1d60(int param_1,int param_2)

{
  undefined4 uVar1;
  QTypedArrayData<unsigned_short> *pQVar2;
  QListData *this;
  byte *pbVar3;
  byte bVar4;
  int iVar5;
  void **ppvVar6;
  QString *pQVar7;
  int iVar8;
  QChar aQStack_ae [2];
  uint local_88;
  QString local_84 [4];
  QString local_80 [4];
  QWidget *local_7c;
  QTextEdit *local_78;
  int local_74;
  uint local_70;
  QTypedArrayData<unsigned_short> *local_6c;
  QListData *local_68;
  QListData *local_64;
  byte *local_60;
  byte *local_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  byte local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054577e;
  local_10 = ExceptionList;
  local_14 = DAT_00759b24 ^ (uint)(local_80 + 0x7c);
  ExceptionList = &local_10;
  local_88 = 0;
  local_70 = 0;
  *(undefined1 *)(param_1 + 0xf2f) = 0;
  local_60 = (byte *)0x0;
  local_68 = (QListData *)(param_1 + 0x1354);
  local_74 = param_1;
  iVar5 = QListData::size(local_68);
  local_64 = (QListData *)(param_2 * 0x1da);
  if (0 < iVar5) {
    local_5c = (byte *)(param_1 + 0x17d + (int)local_64);
    local_78 = (QTextEdit *)CONCAT31(local_78._1_3_,0x20);
    do {
      ppvVar6 = QListData::at(local_68,(int)local_60);
      QComboBox::setCurrentIndex(*(QComboBox **)((int)*ppvVar6 + 0x1c),(uint)local_5c[-1]);
      ppvVar6 = QListData::at(local_68,(int)local_60);
      QComboBox::setCurrentIndex(*(QComboBox **)((int)*ppvVar6 + 0x20),(uint)*local_5c);
      this = local_68;
      ppvVar6 = QListData::at(local_68,(int)local_60);
      QSpinBox::setValue(*(QSpinBox **)((int)*ppvVar6 + 0x24),(uint)local_5c[1]);
      ppvVar6 = QListData::at(this,(int)local_60);
      QSpinBox::setValue(*(QSpinBox **)((int)*ppvVar6 + 0x28),(uint)local_5c[2]);
      ppvVar6 = QListData::at(this,(int)local_60);
      QSpinBox::setValue(*(QSpinBox **)((int)*ppvVar6 + 0x2c),(uint)local_5c[3]);
      ppvVar6 = QListData::at(this,(int)local_60);
      local_7c = *(QWidget **)((int)*ppvVar6 + 0x30);
      local_6c = QString::fromAscii_helper("QPushButton{background-color:rgb(%1,%2,%3)}",0x2b);
      local_8 = 0;
      bVar4 = local_5c[4];
      QChar::QChar(aQStack_ae + -6,0x20);
      pQVar7 = (QString *)QString::arg((QString *)&local_6c,&local_88,bVar4,0,10);
      local_8._0_1_ = 1;
      bVar4 = local_5c[5];
      QChar::QChar(aQStack_ae + -6,0x20);
      pQVar7 = (QString *)QString::arg(pQVar7,local_84,bVar4,0,10);
      local_8._0_1_ = 2;
      bVar4 = local_5c[6];
      QChar::QChar(aQStack_ae + -6,local_78);
      pQVar7 = (QString *)QString::arg(pQVar7,local_80,bVar4,0,10);
      local_8 = CONCAT31(local_8._1_3_,3);
      QWidget::setStyleSheet(local_7c,pQVar7);
      QString::~QString(local_80);
      QString::~QString(local_84);
      QString::~QString((QString *)&local_88);
      local_8 = 0xffffffff;
      QString::~QString((QString *)&local_6c);
      pbVar3 = local_60;
      param_1 = local_74;
      FUN_004f5800();
      local_5c = local_5c + 8;
      local_60 = pbVar3 + 1;
      iVar5 = QListData::size((QListData *)(param_1 + 0x1354));
    } while ((int)(pbVar3 + 1) < iVar5);
  }
  iVar8 = 0;
  iVar5 = QListData::size((QListData *)(param_1 + 0x1358));
  if (iVar5 < 1) {
    local_5c = (byte *)((int)local_64 + param_1);
  }
  else {
    local_5c = (byte *)((int)local_64 + param_1);
    local_60 = (byte *)((int)local_5c + 0x11d);
    do {
      ppvVar6 = QListData::at((QListData *)(param_1 + 0x1358),iVar8);
      QComboBox::setCurrentIndex(*(QComboBox **)((int)*ppvVar6 + 0x1c),(uint)local_60[-1]);
      ppvVar6 = QListData::at((QListData *)(param_1 + 0x1358),iVar8);
      QComboBox::setCurrentIndex(*(QComboBox **)((int)*ppvVar6 + 0x20),(uint)*local_60);
      ppvVar6 = QListData::at((QListData *)(param_1 + 0x1358),iVar8);
      QComboBox::setCurrentIndex(*(QComboBox **)((int)*ppvVar6 + 0x24),(uint)local_60[1]);
      ppvVar6 = QListData::at((QListData *)(param_1 + 0x1358),iVar8);
      QSpinBox::setValue(*(QSpinBox **)((int)*ppvVar6 + 0x28),(uint)local_60[2]);
      ppvVar6 = QListData::at((QListData *)(param_1 + 0x1358),iVar8);
      QSpinBox::setValue(*(QSpinBox **)((int)*ppvVar6 + 0x2c),(uint)local_60[3]);
      ppvVar6 = QListData::at((QListData *)(param_1 + 0x1358),iVar8);
      QSpinBox::setValue(*(QSpinBox **)((int)*ppvVar6 + 0x30),(uint)local_60[4]);
      FUN_004f5420();
      local_60 = local_60 + 6;
      iVar8 = iVar8 + 1;
      iVar5 = QListData::size((QListData *)(param_1 + 0x1358));
    } while (iVar8 < iVar5);
  }
  pbVar3 = local_5c;
  QComboBox::setCurrentIndex
            (*(QComboBox **)(param_1 + 0x1294),(uint)*(byte *)((int)local_5c + 0x2c));
  QSpinBox::setValue(*(QSpinBox **)(param_1 + 0x1284),(int)*(char *)((int)pbVar3 + 0x2d));
  QSpinBox::setValue(*(QSpinBox **)(param_1 + 0x1290),(int)*(char *)((int)local_5c + 0x2e));
  QSpinBox::setValue(*(QSpinBox **)(param_1 + 0x12a0),(uint)*(byte *)((int)local_5c + 0x2f));
  QSpinBox::setValue(*(QSpinBox **)(param_1 + 0x12a4),(uint)*(byte *)((int)local_5c + 0x30));
  QComboBox::setCurrentIndex
            (*(QComboBox **)(param_1 + 0x12f8),(uint)*(byte *)((int)local_5c + 0x1fd));
  QSpinBox::setValue(*(QSpinBox **)(param_1 + 0x1324),(uint)*(byte *)((int)local_5c + 0x1fe));
  QLabel::setText(*(QLabel **)(param_1 + 0x132c),
                  (QString *)(&DAT_007636d8 + (uint)*(byte *)((int)local_5c + 0x1fe) * 4));
  QSpinBox::setValue(*(QSpinBox **)(param_1 + 0x1310),(uint)*(byte *)((int)local_5c + 0x1ff));
  QSpinBox::setValue(*(QSpinBox **)(param_1 + 0x12e0),(uint)*(byte *)((int)local_5c + 0x200));
  QComboBox::setCurrentIndex
            (*(QComboBox **)(param_1 + 0x1320),(uint)*(byte *)((int)local_5c + 0x1fc));
  QComboBox::setCurrentIndex
            (*(QComboBox **)(param_1 + 0x1328),(uint)*(byte *)((int)local_5c + 0x201));
  QComboBox::setCurrentIndex
            (*(QComboBox **)(param_1 + 0x12e4),(uint)*(byte *)((int)local_5c + 0x202));
  QSpinBox::setValue(*(QSpinBox **)(param_1 + 0x12f4),(uint)*(byte *)((int)local_5c + 0x203));
  QSpinBox::setValue(*(QSpinBox **)(param_1 + 0x12f0),(uint)*(byte *)((int)local_5c + 0x204));
  QSpinBox::setValue(*(QSpinBox **)(param_1 + 0x1304),(uint)*(byte *)((int)local_5c + 0x205));
  iVar8 = 0;
  local_64 = (QListData *)(param_1 + 0x135c);
  local_6c = (QTypedArrayData<unsigned_short> *)0x0;
  iVar5 = QListData::size(local_64);
  if (0 < iVar5) {
    local_60 = (byte *)((int)local_5c + 0x4b);
    do {
      ppvVar6 = QListData::at(local_64,iVar8);
      QComboBox::setCurrentIndex(*(QComboBox **)((int)*ppvVar6 + 0x1c),(uint)local_60[-1]);
      ppvVar6 = QListData::at(local_64,iVar8);
      QComboBox::setCurrentIndex(*(QComboBox **)((int)*ppvVar6 + 0x20),(uint)*local_60);
      ppvVar6 = QListData::at(local_64,iVar8);
      QSpinBox::setValue(*(QSpinBox **)((int)*ppvVar6 + 0x24),(uint)local_60[1]);
      ppvVar6 = QListData::at(local_64,iVar8);
      QSpinBox::setValue(*(QSpinBox **)((int)*ppvVar6 + 0x28),(uint)local_60[2]);
      ppvVar6 = QListData::at(local_64,iVar8);
      QSpinBox::setValue(*(QSpinBox **)((int)*ppvVar6 + 0x2c),(uint)local_60[3]);
      ppvVar6 = QListData::at(local_64,iVar8);
      local_78 = *(QTextEdit **)((int)*ppvVar6 + 0x30);
      uVar1 = *(undefined4 *)(local_60 + 4);
      uStack_54 = *(undefined4 *)(local_60 + 8);
      uStack_50 = *(undefined4 *)(local_60 + 0xc);
      uStack_4c = *(undefined4 *)(local_60 + 0x10);
      local_48 = *(undefined4 *)(local_60 + 0x14);
      uStack_44 = *(undefined4 *)(local_60 + 0x18);
      uStack_40 = *(undefined4 *)(local_60 + 0x1c);
      uStack_3c = *(undefined4 *)(local_60 + 0x20);
      local_38 = *(undefined4 *)(local_60 + 0x24);
      uStack_34 = *(undefined4 *)(local_60 + 0x28);
      uStack_30 = *(undefined4 *)(local_60 + 0x2c);
      uStack_2c = *(undefined4 *)(local_60 + 0x30);
      local_28 = *(undefined4 *)(local_60 + 0x34);
      uStack_24 = *(undefined4 *)(local_60 + 0x38);
      uStack_20 = *(undefined4 *)(local_60 + 0x3c);
      uStack_1c = *(undefined4 *)(local_60 + 0x40);
      local_18 = local_60[0x44];
      local_8 = 4;
      local_58 = uVar1;
      QString::QString((QString *)&local_68);
      local_88 = local_70 | 1;
      bVar4 = (byte)uVar1;
      if ((bVar4 == 0) || (bVar4 < 0x40)) {
        bVar4 = -(bVar4 != 0) & bVar4;
      }
      else {
        bVar4 = 0x40;
      }
      local_7c = (QWidget *)(uint)bVar4;
      iVar5 = 0;
      local_70 = local_88;
      if (local_7c != (QWidget *)0x0) {
        do {
          if (*(byte *)((int)&local_58 + iVar5 + 1) < 0x10) {
            pQVar7 = (QString *)QString::asprintf((char *)local_84,&DAT_0058955c);
            local_8 = CONCAT31(local_8._1_3_,5);
            QString::append((QString *)&local_68,pQVar7);
            pQVar7 = local_84;
          }
          else {
            pQVar7 = (QString *)QString::asprintf((char *)local_80,&DAT_00589564);
            local_8 = CONCAT31(local_8._1_3_,6);
            QString::append((QString *)&local_68,pQVar7);
            pQVar7 = local_80;
          }
          local_8 = CONCAT31(local_8._1_3_,4);
          QString::~QString(pQVar7);
          iVar5 = iVar5 + 1;
        } while (iVar5 < (int)local_7c);
      }
      QTextEdit::setText(local_78,(QString *)&local_68);
      local_70 = local_70 & 0xfffffffe;
      local_8 = 0xffffffff;
      QString::~QString((QString *)&local_68);
      pQVar2 = local_6c;
      FUN_004f6090();
      iVar8 = (int)pQVar2 + 1;
      local_60 = local_60 + 0x46;
      local_6c = (QTypedArrayData<unsigned_short> *)iVar8;
      iVar5 = QListData::size(local_64);
    } while (iVar8 < iVar5);
    param_1 = local_74;
  }
  iVar5 = 0;
  local_6c = (QTypedArrayData<unsigned_short> *)((int)local_5c + 0x31);
  do {
    FUN_00487530(*local_6c,1);
    if ((**(int **)(param_1 + 0x1360) != 1) && (**(int **)(param_1 + 0x1360) != 0)) {
      FUN_004f2b00();
    }
    ppvVar6 = QListData::at((QListData *)(param_1 + 0x1360),iVar5);
    QSpinBox::setValue(*(QSpinBox **)((int)*ppvVar6 + 4),(uint)local_5c >> 8 & 0xff);
    FUN_004f5250();
    iVar5 = iVar5 + 1;
    local_6c = local_6c + 1;
  } while (iVar5 < 0x19);
  *(undefined1 *)(param_1 + 0xf2f) = 1;
  ExceptionList = local_10;
  return;
}


