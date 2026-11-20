
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_004c2930(QObject *param_1)

{
  QComboBox *pQVar1;
  uint uVar2;
  QButtonGroup *pQVar3;
  QVariant *pQVar4;
  QString *pQVar5;
  int iVar6;
  QIcon *pQVar7;
  QString *pQVar8;
  QObject *pQVar9;
  QVariant local_17c [16];
  QVariant local_16c [16];
  QVariant local_15c [16];
  QVariant local_14c [16];
  QVariant local_13c [16];
  QString local_12c [4];
  QString local_128 [4];
  QString local_124 [4];
  QIcon local_120 [4];
  QString local_11c [4];
  QString local_118 [4];
  QString local_114 [4];
  QIcon local_110 [4];
  QString local_10c [4];
  QString local_108 [4];
  QIcon local_104 [4];
  QIcon local_100 [4];
  QString local_fc [4];
  QString local_f8 [4];
  QString local_f4 [4];
  QString local_f0 [4];
  QString local_ec [4];
  QString local_e8 [4];
  QString local_e4 [4];
  QString local_e0 [4];
  QString local_dc [4];
  QString local_d8 [4];
  QString local_d4 [4];
  QString local_d0 [4];
  QString local_cc [4];
  QString local_c8 [4];
  QString local_c4 [4];
  QString local_c0 [4];
  QString local_bc [4];
  QComboBox *local_b8;
  QButtonGroup *local_b4;
  uint local_b0;
  QString *local_ac;
  QObject *local_a8;
  uint local_a4;
  QTypedArrayData<unsigned_short> *local_a0;
  QString local_9c [104];
  QString local_34 [4];
  QString local_30 [4];
  QString local_2c [4];
  QString local_28 [4];
  QString local_24 [4];
  QString local_20 [4];
  QString local_1c [4];
  QString local_18 [4];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00535d01;
  local_10 = ExceptionList;
  local_14 = DAT_00759b24 ^ (uint)(local_18 + 0x14);
  ExceptionList = &local_10;
  local_a4 = 0;
  local_b0 = 0;
  local_a8 = param_1;
  pQVar3 = operator_new(8);
  local_8 = 0;
  local_b4 = pQVar3;
  QButtonGroup::QButtonGroup(pQVar3,param_1);
  *(undefined ***)pQVar3 = QButtonGroup::vftable;
  *(QButtonGroup **)(param_1 + 0x858) = pQVar3;
  local_8 = 0xffffffff;
  QButtonGroup::addButton(pQVar3,*(QAbstractButton **)(param_1 + 0x86c),0);
  QButtonGroup::addButton
            (*(QButtonGroup **)(param_1 + 0x858),*(QAbstractButton **)(param_1 + 0x870),1);
  QButtonGroup::setExclusive(*(QButtonGroup **)(param_1 + 0x858),true);
  pQVar3 = operator_new(8);
  local_8 = 1;
  local_b4 = pQVar3;
  QButtonGroup::QButtonGroup(pQVar3,local_a8);
  *(undefined ***)pQVar3 = QButtonGroup::vftable;
  local_8 = 0xffffffff;
  *(QButtonGroup **)(local_a8 + 0x85c) = pQVar3;
  QButtonGroup::addButton(pQVar3,*(QAbstractButton **)(local_a8 + 0x878),0);
  QButtonGroup::addButton
            (*(QButtonGroup **)(local_a8 + 0x85c),*(QAbstractButton **)(local_a8 + 0x87c),1);
  QButtonGroup::addButton
            (*(QButtonGroup **)(local_a8 + 0x85c),*(QAbstractButton **)(local_a8 + 0x880),2);
  QButtonGroup::addButton
            (*(QButtonGroup **)(local_a8 + 0x85c),*(QAbstractButton **)(local_a8 + 0x884),3);
  QButtonGroup::addButton
            (*(QButtonGroup **)(local_a8 + 0x85c),*(QAbstractButton **)(local_a8 + 0x888),4);
  QButtonGroup::addButton
            (*(QButtonGroup **)(local_a8 + 0x85c),*(QAbstractButton **)(local_a8 + 0x88c),5);
  QButtonGroup::addButton
            (*(QButtonGroup **)(local_a8 + 0x85c),*(QAbstractButton **)(local_a8 + 0x890),6);
  QButtonGroup::addButton
            (*(QButtonGroup **)(local_a8 + 0x85c),*(QAbstractButton **)(local_a8 + 0x8a4),7);
  QButtonGroup::addButton
            (*(QButtonGroup **)(local_a8 + 0x85c),*(QAbstractButton **)(local_a8 + 0x894),8);
  QButtonGroup::addButton
            (*(QButtonGroup **)(local_a8 + 0x85c),*(QAbstractButton **)(local_a8 + 0x898),9);
  QButtonGroup::addButton
            (*(QButtonGroup **)(local_a8 + 0x85c),*(QAbstractButton **)(local_a8 + 0x8a8),10);
  QButtonGroup::addButton
            (*(QButtonGroup **)(local_a8 + 0x85c),*(QAbstractButton **)(local_a8 + 0x8ac),0xb);
  QButtonGroup::setExclusive(*(QButtonGroup **)(local_a8 + 0x85c),true);
  pQVar3 = operator_new(8);
  local_8 = 2;
  local_b4 = pQVar3;
  QButtonGroup::QButtonGroup(pQVar3,local_a8);
  *(undefined ***)pQVar3 = QButtonGroup::vftable;
  local_8 = 0xffffffff;
  *(QButtonGroup **)(local_a8 + 0x860) = pQVar3;
  QButtonGroup::addButton(pQVar3,*(QAbstractButton **)(local_a8 + 0x8b4),0);
  QButtonGroup::addButton
            (*(QButtonGroup **)(local_a8 + 0x860),*(QAbstractButton **)(local_a8 + 0x8b8),1);
  QButtonGroup::addButton
            (*(QButtonGroup **)(local_a8 + 0x860),*(QAbstractButton **)(local_a8 + 0x8bc),2);
  QButtonGroup::addButton
            (*(QButtonGroup **)(local_a8 + 0x860),*(QAbstractButton **)(local_a8 + 0x8c0),3);
  QButtonGroup::setExclusive(*(QButtonGroup **)(local_a8 + 0x860),true);
  pQVar3 = operator_new(8);
  local_8 = 3;
  local_b4 = pQVar3;
  QButtonGroup::QButtonGroup(pQVar3,local_a8);
  pQVar9 = local_a8;
  *(undefined ***)pQVar3 = QButtonGroup::vftable;
  local_8 = 0xffffffff;
  *(QButtonGroup **)(local_a8 + 0x864) = pQVar3;
  QButtonGroup::addButton(pQVar3,*(QAbstractButton **)(local_a8 + 0x8c8),0);
  QButtonGroup::addButton
            (*(QButtonGroup **)(pQVar9 + 0x864),*(QAbstractButton **)(pQVar9 + 0x8cc),1);
  QButtonGroup::addButton
            (*(QButtonGroup **)(pQVar9 + 0x864),*(QAbstractButton **)(pQVar9 + 0x8d0),2);
  QButtonGroup::addButton
            (*(QButtonGroup **)(pQVar9 + 0x864),*(QAbstractButton **)(pQVar9 + 0x8d4),3);
  QButtonGroup::addButton
            (*(QButtonGroup **)(pQVar9 + 0x864),*(QAbstractButton **)(pQVar9 + 0x8d8),4);
  QButtonGroup::setExclusive(*(QButtonGroup **)(pQVar9 + 0x864),true);
  QAbstractButton::setChecked(*(QAbstractButton **)(pQVar9 + 0x8b4),true);
  local_a0 = QString::fromAscii_helper
                       ("A to D keys are used to send PC code,\nE and F keys are turned groups,\nA total of 8 groups of 32 timbre. \nThe PC number is displayed as an \nalphanumeric plus number.\n"
                        ,0xa5);
  local_8 = 4;
  FUN_004ad520(&local_a0);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_a0);
  local_a0 = QString::fromAscii_helper
                       ("A to D keys are used to send PC code,\nE to F keys for the flip group, \nA total of 128 timbre. \nThe way to display PC number is a pure\nnumber."
                        ,0x8d);
  local_8 = 5;
  FUN_004ad520(&local_a0);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_a0);
  local_a0 = QString::fromAscii_helper
                       ("A---Swipe up     B---Swipe down  \n\nC----Swipe left     D---Swipe right",
                        0x46);
  local_8 = 6;
  FUN_004ad520(&local_a0);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_a0);
  local_a0 = QString::fromAscii_helper("A---Up     B---Down\n\nC---Left     D---Right",0x2b);
  local_8 = 7;
  FUN_004ad520(&local_a0);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_a0);
  local_a0 = QString::fromAscii_helper
                       ("A---Page up     B---Page down\n\nC---Space     D---Enter",0x36);
  local_8 = 8;
  FUN_004ad520(&local_a0);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_a0);
  local_a0 = QString::fromAscii_helper
                       ("A---Last song     B---Next song\n\nC---Volume -     D---Volume +",0x3e);
  local_8 = 9;
  FUN_004ad520(&local_a0);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_a0);
  local_a0 = QString::fromAscii_helper
                       ("Control manufacturer\'s equipment. \nRefer to manufacturer\'s equipment\ninstructions for details."
                        ,0x5e);
  local_8 = 10;
  FUN_004ad520(&local_a0);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_a0);
  local_a0 = QString::fromAscii_helper("Set up custom MIDI CC and some common\nMIDI.\n",0x2c);
  local_8 = 0xb;
  FUN_004ad520(&local_a0);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_a0);
  local_a0 = QString::fromAscii_helper
                       ("A---Quick astern      B---Fast forward     \nC---Play/pause      D---Loop playback, \nneed to use Chrome browser and install \nthe extension, temporarily support \nYouTube, Bilibil."
                        ,0xb1);
  local_8 = 0xc;
  FUN_004ad520(&local_a0);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_a0);
  local_a0 = QString::fromAscii_helper
                       ("You can customize the way you use your \npedals more flexibly",0x3c);
  local_8 = 0xd;
  FUN_004ad520(&local_a0);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_a0);
  local_a0 = QString::fromAscii_helper("You can set common keyboard keys",0x20);
  local_8 = 0xe;
  FUN_004ad520(&local_a0);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_a0);
  local_a0 = QString::fromAscii_helper
                       ("A to D keys are used to send CC code,\nE to F keys for the flip group, \nA total of 128 timbre. \nThe way to display CC number is a pure\nnumber."
                        ,0x8d);
  local_8 = 0xf;
  FUN_004ad520(&local_a0);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_a0);
  pQVar9 = local_a8;
  local_a0 = QString::fromAscii_helper
                       ("Send an identical MIDI message\nor set of MIDI messages each \ntime a foot pin is pressed and \nlifted. "
                        ,0x65);
  local_8 = 0x10;
  FUN_004ad520(&local_a0);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_a0);
  local_a0 = QString::fromAscii_helper
                       ("You can set two banks of MIDI \ninformation ,A and B. Each\n time you press the nail and\nlift it , the two banks of MIDI \ninformation will be sent in turn.  "
                        ,0x9b);
  local_8 = 0x11;
  FUN_004ad520(&local_a0);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_a0);
  local_a0 = QString::fromAscii_helper
                       ("You can set two banks of MIDI\ninformation, A and B. Each \ntime you press the foot pin \nto send the bank A message,\nlift the bank B message. "
                        ,0x8c);
  local_8 = 0x12;
  FUN_004ad520(&local_a0);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_a0);
  local_a0 = QString::fromAscii_helper
                       ("When you step on a foot pin,\nthe MIDI message or set of \nMIDI messages that you set\nwill be sent at regular intervals.\nYou can also press the pin \nonce to send the first of all \nMIDI messages. "
                        ,0xc1);
  local_8 = 0x13;
  FUN_004ad520(&local_a0);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_a0);
  local_a0 = QString::fromAscii_helper
                       ("Send bank A message every\ntime you step on A foot spike\nand lift it.  Send bank B message\nwhen you step on a foot pin. "
                        ,0x77);
  local_8 = 0x14;
  FUN_004ad520(&local_a0);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_a0);
  local_a0 = QString::fromAscii_helper("PC",2);
  local_8 = 0x15;
  FUN_004ad520(&local_a0);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_a0);
  local_a0 = QString::fromAscii_helper("CC",2);
  local_8 = 0x16;
  FUN_004ad520(&local_a0);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_a0);
  local_a0 = QString::fromAscii_helper("Note ON",7);
  local_8 = 0x17;
  FUN_004ad520(&local_a0);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_a0);
  local_a0 = QString::fromAscii_helper("Note OFF",8);
  local_8 = 0x18;
  FUN_004ad520(&local_a0);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_a0);
  local_a0 = QString::fromAscii_helper("Custom MIDI Code",0x10);
  local_8 = 0x19;
  FUN_004ad520(&local_a0);
  QString::~QString((QString *)&local_a0);
  local_ac = (QString *)(pQVar9 + 0x230);
  local_a0 = (QTypedArrayData<unsigned_short> *)0x0;
  while( true ) {
    pQVar1 = *(QComboBox **)(pQVar9 + 0x90c);
    local_b8 = pQVar1;
    pQVar4 = (QVariant *)QVariant::QVariant(local_17c);
    local_8 = 0x1b;
    QString::QString(local_cc,local_ac + -0x218);
    local_b0 = local_a4 | 0x100;
    local_a4 = local_b0;
    pQVar5 = (QString *)QString::fromUtf8((char *)local_11c,0x589188);
    local_8._0_1_ = 0x1c;
    QString::append(local_cc,pQVar5);
    QString::~QString(local_11c);
    local_8._0_1_ = 0x1d;
    QString::QString(local_c8,local_cc);
    local_b0 = local_a4 | 0x40;
    local_a4 = local_b0;
    QString::append(local_c8,local_ac);
    local_8._0_1_ = 0x1e;
    QString::QString(local_c4,local_c8);
    local_b0 = local_a4 | 0x80;
    local_a4 = local_b0;
    pQVar5 = (QString *)QString::fromUtf8((char *)local_118,0x589184);
    local_8._0_1_ = 0x1f;
    QString::append(local_c4,pQVar5);
    local_8._0_1_ = 0x1e;
    QString::~QString(local_118);
    iVar6 = QComboBox::count(pQVar1);
    pQVar7 = (QIcon *)QIcon::QIcon(local_120);
    local_8 = CONCAT31(local_8._1_3_,0x20);
    QComboBox::insertItem(local_b8,iVar6,pQVar7,local_c4,pQVar4);
    QIcon::~QIcon(local_120);
    uVar2 = local_a4;
    QString::~QString(local_c4);
    QString::~QString(local_c8);
    local_a4 = uVar2 & 0xfffffe3f;
    QString::~QString(local_cc);
    QVariant::~QVariant(local_17c);
    pQVar1 = *(QComboBox **)(local_a8 + 0x918);
    local_b8 = pQVar1;
    pQVar4 = (QVariant *)QVariant::QVariant(local_13c);
    local_8 = 0x22;
    QString::QString(local_d8,local_ac + -0x218);
    local_b0 = local_a4 | 0x200;
    local_a4 = local_b0;
    pQVar5 = (QString *)QString::fromUtf8((char *)local_124,0x589188);
    local_8._0_1_ = 0x23;
    QString::append(local_d8,pQVar5);
    QString::~QString(local_124);
    local_8._0_1_ = 0x24;
    QString::QString(local_d4,local_d8);
    local_b0 = local_a4 | 0x400;
    local_a4 = local_b0;
    QString::append(local_d4,local_ac);
    local_8._0_1_ = 0x25;
    QString::QString(local_d0,local_d4);
    local_b0 = local_a4 | 0x800;
    local_a4 = local_b0;
    pQVar5 = (QString *)QString::fromUtf8((char *)local_128,0x589184);
    local_8._0_1_ = 0x26;
    QString::append(local_d0,pQVar5);
    local_8._0_1_ = 0x25;
    QString::~QString(local_128);
    iVar6 = QComboBox::count(pQVar1);
    pQVar7 = (QIcon *)QIcon::QIcon(local_104);
    local_8 = CONCAT31(local_8._1_3_,0x27);
    QComboBox::insertItem(local_b8,iVar6,pQVar7,local_d0,pQVar4);
    QIcon::~QIcon(local_104);
    uVar2 = local_a4;
    QString::~QString(local_d0);
    QString::~QString(local_d4);
    local_a4 = uVar2 & 0xfffff1ff;
    QString::~QString(local_d8);
    QVariant::~QVariant(local_13c);
    pQVar1 = *(QComboBox **)(local_a8 + 0x920);
    local_b8 = pQVar1;
    pQVar4 = (QVariant *)QVariant::QVariant(local_14c);
    local_8 = 0x29;
    QString::QString(local_e4,local_ac + -0x218);
    local_b0 = local_a4 | 1;
    local_a4 = local_b0;
    pQVar5 = (QString *)QString::fromUtf8((char *)local_108,0x589188);
    local_8._0_1_ = 0x2a;
    QString::append(local_e4,pQVar5);
    QString::~QString(local_108);
    local_8._0_1_ = 0x2b;
    QString::QString(local_e0,local_e4);
    local_b0 = local_a4 | 2;
    local_a4 = local_b0;
    QString::append(local_e0,local_ac);
    local_8._0_1_ = 0x2c;
    QString::QString(local_dc,local_e0);
    local_b0 = local_a4 | 4;
    local_a4 = local_b0;
    pQVar5 = (QString *)QString::fromUtf8((char *)local_10c,0x589184);
    local_8._0_1_ = 0x2d;
    QString::append(local_dc,pQVar5);
    local_8._0_1_ = 0x2c;
    QString::~QString(local_10c);
    iVar6 = QComboBox::count(pQVar1);
    pQVar7 = (QIcon *)QIcon::QIcon(local_110);
    local_8 = CONCAT31(local_8._1_3_,0x2e);
    QComboBox::insertItem(local_b8,iVar6,pQVar7,local_dc,pQVar4);
    QIcon::~QIcon(local_110);
    uVar2 = local_a4;
    QString::~QString(local_dc);
    QString::~QString(local_e0);
    local_a4 = uVar2 & 0xfffffff8;
    QString::~QString(local_e4);
    QVariant::~QVariant(local_14c);
    pQVar1 = *(QComboBox **)(local_a8 + 0x924);
    local_b8 = pQVar1;
    pQVar4 = (QVariant *)QVariant::QVariant(local_15c);
    local_8 = 0x30;
    QString::QString(local_f0,local_ac + -0x218);
    local_b0 = local_a4 | 8;
    local_a4 = local_b0;
    pQVar5 = (QString *)QString::fromUtf8((char *)local_114,0x589188);
    local_8._0_1_ = 0x31;
    QString::append(local_f0,pQVar5);
    QString::~QString(local_114);
    local_8._0_1_ = 0x32;
    QString::QString(local_ec,local_f0);
    local_b0 = local_a4 | 0x10;
    local_a4 = local_b0;
    QString::append(local_ec,local_ac);
    local_8._0_1_ = 0x33;
    QString::QString(local_e8,local_ec);
    local_b0 = local_a4 | 0x20;
    local_a4 = local_b0;
    pQVar5 = (QString *)QString::fromUtf8((char *)local_12c,0x589184);
    local_8._0_1_ = 0x34;
    QString::append(local_e8,pQVar5);
    local_8._0_1_ = 0x33;
    QString::~QString(local_12c);
    iVar6 = QComboBox::count(pQVar1);
    pQVar7 = (QIcon *)QIcon::QIcon(local_100);
    local_8 = CONCAT31(local_8._1_3_,0x35);
    QComboBox::insertItem(local_b8,iVar6,pQVar7,local_e8,pQVar4);
    QIcon::~QIcon(local_100);
    uVar2 = local_a4;
    QString::~QString(local_e8);
    QString::~QString(local_ec);
    local_a4 = uVar2 & 0xffffffc7;
    QString::~QString(local_f0);
    local_8 = 0xffffffff;
    QVariant::~QVariant(local_15c);
    if (local_a0 < (QTypedArrayData<unsigned_short> *)0x82) {
      pQVar1 = *(QComboBox **)(local_a8 + 0x92c);
      local_b8 = pQVar1;
      pQVar4 = (QVariant *)QVariant::QVariant(local_16c);
      local_8 = 0x37;
      QString::QString(local_fc,local_ac + 0x218);
      local_b0 = local_a4 | 0x2000;
      local_a4 = local_b0;
      pQVar5 = (QString *)QString::fromUtf8((char *)local_bc,0x589188);
      local_8._0_1_ = 0x38;
      QString::append(local_fc,pQVar5);
      QString::~QString(local_bc);
      local_8._0_1_ = 0x39;
      QString::QString(local_f8,local_fc);
      local_b0 = local_a4 | 0x4000;
      local_a4 = local_b0;
      QString::append(local_f8,local_ac + 0x420);
      local_8._0_1_ = 0x3a;
      QString::QString(local_f4,local_f8);
      local_b0 = local_a4 | 0x1000;
      local_a4 = local_b0;
      pQVar5 = (QString *)QString::fromUtf8((char *)local_c0,0x589184);
      local_8._0_1_ = 0x3b;
      QString::append(local_f4,pQVar5);
      local_8._0_1_ = 0x3a;
      QString::~QString(local_c0);
      iVar6 = QComboBox::count(pQVar1);
      pQVar7 = (QIcon *)QIcon::QIcon((QIcon *)&local_b4);
      local_8 = CONCAT31(local_8._1_3_,0x3c);
      QComboBox::insertItem(local_b8,iVar6,pQVar7,local_f4,pQVar4);
      QIcon::~QIcon((QIcon *)&local_b4);
      uVar2 = local_a4;
      QString::~QString(local_f4);
      QString::~QString(local_f8);
      local_a4 = uVar2 & 0xffff8fff;
      QString::~QString(local_fc);
      local_8 = 0xffffffff;
      QVariant::~QVariant(local_16c);
    }
    local_ac = local_ac + 4;
    local_a0 = local_a0 + 1;
    if ((QTypedArrayData<unsigned_short> *)0x85 < local_a0) break;
    pQVar9 = local_a8;
  }
  _eh_vector_constructor_iterator_(local_9c,4,0x22,QString_exref,~QString_exref);
  pQVar5 = local_9c;
  local_8 = 0x3d;
  iVar6 = 0;
  do {
    pQVar8 = (QString *)QString::asprintf((char *)&local_b4,&DAT_00580ff8,iVar6 + 0x41);
    QString::operator=(pQVar5,pQVar8);
    QString::~QString((QString *)&local_b4);
    iVar6 = iVar6 + 1;
    pQVar5 = pQVar5 + 4;
  } while (iVar6 < 0x1a);
  pQVar5 = (QString *)QString::fromLocal8Bit((char *)&local_b4,0x589194);
  QString::operator=(local_34,pQVar5);
  QString::~QString((QString *)&local_b4);
  pQVar5 = (QString *)QString::fromLocal8Bit((char *)&local_b4,0x589198);
  QString::operator=(local_30,pQVar5);
  QString::~QString((QString *)&local_b4);
  pQVar5 = (QString *)QString::fromLocal8Bit((char *)local_c0,0x58919c);
  QString::operator=(local_2c,pQVar5);
  QString::~QString(local_c0);
  pQVar5 = (QString *)QString::fromLocal8Bit((char *)local_bc,0x5891a0);
  QString::operator=(local_28,pQVar5);
  QString::~QString(local_bc);
  QString::operator=(local_24,"PAGE UP");
  QString::operator=(local_20,"PAGE DOWN");
  QString::operator=(local_1c,"SPACE");
  QString::operator=(local_18,"Enter");
  local_ac = local_9c;
  local_a0 = (QTypedArrayData<unsigned_short> *)0x22;
  do {
    pQVar1 = *(QComboBox **)(local_a8 + 0x958);
    pQVar4 = (QVariant *)QVariant::QVariant(local_16c);
    local_8._0_1_ = 0x3e;
    iVar6 = QComboBox::count(pQVar1);
    pQVar7 = (QIcon *)QIcon::QIcon((QIcon *)&local_b4);
    local_8._0_1_ = 0x3f;
    QComboBox::insertItem(pQVar1,iVar6,pQVar7,local_ac,pQVar4);
    QIcon::~QIcon((QIcon *)&local_b4);
    QVariant::~QVariant(local_16c);
    pQVar1 = *(QComboBox **)(local_a8 + 0x964);
    pQVar4 = (QVariant *)QVariant::QVariant(local_15c);
    local_8._0_1_ = 0x40;
    iVar6 = QComboBox::count(pQVar1);
    pQVar7 = (QIcon *)QIcon::QIcon((QIcon *)local_c0);
    local_8._0_1_ = 0x41;
    QComboBox::insertItem(pQVar1,iVar6,pQVar7,local_ac,pQVar4);
    QIcon::~QIcon((QIcon *)local_c0);
    QVariant::~QVariant(local_15c);
    pQVar1 = *(QComboBox **)(local_a8 + 0x96c);
    pQVar4 = (QVariant *)QVariant::QVariant(local_14c);
    local_8._0_1_ = 0x42;
    iVar6 = QComboBox::count(pQVar1);
    pQVar7 = (QIcon *)QIcon::QIcon((QIcon *)local_bc);
    local_8._0_1_ = 0x43;
    QComboBox::insertItem(pQVar1,iVar6,pQVar7,local_ac,pQVar4);
    QIcon::~QIcon((QIcon *)local_bc);
    QVariant::~QVariant(local_14c);
    pQVar1 = *(QComboBox **)(local_a8 + 0x970);
    pQVar4 = (QVariant *)QVariant::QVariant(local_13c);
    local_8._0_1_ = 0x44;
    iVar6 = QComboBox::count(pQVar1);
    pQVar7 = (QIcon *)QIcon::QIcon(local_100);
    pQVar5 = local_ac;
    local_8._0_1_ = 0x45;
    QComboBox::insertItem(pQVar1,iVar6,pQVar7,local_ac,pQVar4);
    QIcon::~QIcon(local_100);
    local_8 = CONCAT31(local_8._1_3_,0x3d);
    QVariant::~QVariant(local_13c);
    local_ac = pQVar5 + 4;
    local_a0 = local_a0 + -1;
  } while (local_a0 != (QTypedArrayData<unsigned_short> *)0x0);
  (**(code **)(**(int **)(local_a8 + 0x97c) + 0x2c))(0);
  local_8 = 0xffffffff;
  _eh_vector_destructor_iterator_(local_9c,4,0x22,~QString_exref);
  ExceptionList = local_10;
  return;
}


