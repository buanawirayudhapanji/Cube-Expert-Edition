
void __thiscall FUN_004b0e30(int param_1,QListWidgetItem *param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  QListWidgetItem *pQVar4;
  QSize *pQVar5;
  QLabel *pQVar6;
  QSpinBox *pQVar7;
  int iVar8;
  QDialogButtonBox local_80 [24];
  QDialog local_68 [24];
  QFormLayout local_50 [16];
  int local_40;
  QSize local_3c [4];
  QSpinBox *local_38;
  QObject local_34 [4];
  QString local_30 [4];
  QTypedArrayData<unsigned_short> *local_2c;
  QTypedArrayData<unsigned_short> *local_28;
  QTypedArrayData<unsigned_short> *local_24;
  QTypedArrayData<unsigned_short> *local_20;
  undefined1 *local_1c;
  QSpinBox *local_18;
  QSpinBox *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00530c78;
  local_10 = ExceptionList;
  uVar2 = DAT_00759b24 ^ (uint)(local_30 + 0x2c);
  ExceptionList = &local_10;
  iVar8 = 0;
  local_40 = param_1;
  iVar3 = QListWidget::count(*(QListWidget **)(param_1 + 0x9f8));
  if (0 < iVar3) {
    do {
      pQVar4 = QListWidget::item(*(QListWidget **)(param_1 + 0x9f8),iVar8);
      if (pQVar4 == param_2) break;
      iVar8 = iVar8 + 1;
      iVar3 = QListWidget::count(*(QListWidget **)(param_1 + 0x9f8));
    } while (iVar8 < iVar3);
  }
  puVar1 = (undefined1 *)(param_1 + 0xa45 + iVar8 * 5);
  local_1c = puVar1;
  QDialog::QDialog(local_68,param_1,0,uVar2);
  local_8 = 0;
  pQVar5 = (QSize *)QSize::QSize(local_3c,400,0xdc);
  QWidget::setFixedSize((QWidget *)local_68,pQVar5);
  QFormLayout::QFormLayout(local_50,(QWidget *)local_68);
  local_8._0_1_ = 1;
  QString::asprintf((char *)local_30,"Edit MIDI Code [%d]",iVar8 + 1);
  local_8._0_1_ = 2;
  pQVar6 = operator_new(0x18);
  local_8._0_1_ = 3;
  QLabel::QLabel(pQVar6,local_30,0,0);
  *(undefined ***)pQVar6 = QLabel::vftable;
  *(undefined ***)(pQVar6 + 8) = QLabel::vftable;
  local_8._0_1_ = 2;
  QFormLayout::addRow(local_50,(QWidget *)pQVar6);
  local_2c = QString::fromAscii_helper("Channel: ",9);
  local_8._0_1_ = 4;
  pQVar7 = operator_new(0x18);
  local_8._0_1_ = 5;
  local_38 = pQVar7;
  QSpinBox::QSpinBox(pQVar7,(QWidget *)local_68);
  *(undefined ***)pQVar7 = QSpinBox::vftable;
  *(undefined ***)(pQVar7 + 8) = QSpinBox::vftable;
  local_8._0_1_ = 4;
  QSpinBox::setRange(pQVar7,1,0x10);
  QSpinBox::setValue(pQVar7,(byte)puVar1[1] + 1);
  QFormLayout::addRow(local_50,(QString *)&local_2c,(QWidget *)pQVar7);
  local_28 = QString::fromAscii_helper("Data: ",6);
  local_8._0_1_ = 6;
  local_18 = operator_new(0x18);
  local_8._0_1_ = 7;
  QSpinBox::QSpinBox(local_18,(QWidget *)local_68);
  local_8._0_1_ = 6;
  *(undefined ***)local_18 = QSpinBox::vftable;
  *(undefined ***)(local_18 + 8) = QSpinBox::vftable;
  QSpinBox::setRange(local_18,0,0x7f);
  QSpinBox::setValue(local_18,(uint)(byte)local_1c[2]);
  QFormLayout::addRow(local_50,(QString *)&local_28,(QWidget *)local_18);
  local_24 = QString::fromAscii_helper("Loosen Value: ",0xe);
  local_8._0_1_ = 8;
  pQVar7 = operator_new(0x18);
  local_8._0_1_ = 9;
  QSpinBox::QSpinBox(pQVar7,(QWidget *)local_68);
  local_8._0_1_ = 8;
  *(undefined ***)pQVar7 = QSpinBox::vftable;
  *(undefined ***)(pQVar7 + 8) = QSpinBox::vftable;
  QSpinBox::setRange(pQVar7,0,0x7f);
  QSpinBox::setValue(pQVar7,(uint)(byte)local_1c[3]);
  QFormLayout::addRow(local_50,(QString *)&local_24,(QWidget *)pQVar7);
  local_20 = QString::fromAscii_helper("Step On Value: ",0xf);
  local_8._0_1_ = 10;
  local_14 = operator_new(0x18);
  local_8._0_1_ = 0xb;
  QSpinBox::QSpinBox(local_14,(QWidget *)local_68);
  local_8._0_1_ = 10;
  *(undefined ***)local_14 = QSpinBox::vftable;
  *(undefined ***)(local_14 + 8) = QSpinBox::vftable;
  QSpinBox::setRange(local_14,0,0x7f);
  puVar1 = local_1c;
  QSpinBox::setValue(local_14,(uint)(byte)local_1c[4]);
  QFormLayout::addRow(local_50,(QString *)&local_20,(QWidget *)local_14);
  QDialogButtonBox::QDialogButtonBox(local_80,0x400400,1,local_68);
  local_8 = CONCAT31(local_8._1_3_,0xc);
  QFormLayout::addRow(local_50,(QWidget *)local_80);
  QObject::connect((QObject *)&local_1c,(char *)local_80,(QObject *)"2accepted()",(char *)local_68,
                   0x5894e4);
  QMetaObject::Connection::~Connection((Connection *)&local_1c);
  QObject::connect(local_34,(char *)local_80,(QObject *)"2rejected()",(char *)local_68,0x5894fc);
  QMetaObject::Connection::~Connection((Connection *)local_34);
  iVar3 = QDialog::exec(local_68);
  if (iVar3 == 1) {
    iVar3 = QSpinBox::value(local_38);
    puVar1[1] = (char)iVar3 + -1;
    *puVar1 = 1;
    iVar3 = QSpinBox::value(pQVar7);
    puVar1[3] = (char)iVar3;
    iVar3 = QSpinBox::value(local_14);
    puVar1[4] = (char)iVar3;
    iVar3 = QSpinBox::value(local_18);
    puVar1[2] = (char)iVar3;
    FUN_004bd840(1);
  }
  QDialogButtonBox::~QDialogButtonBox(local_80);
  QString::~QString((QString *)&local_20);
  QString::~QString((QString *)&local_24);
  QString::~QString((QString *)&local_28);
  QString::~QString((QString *)&local_2c);
  QString::~QString(local_30);
  QFormLayout::~QFormLayout(local_50);
  QDialog::~QDialog(local_68);
  ExceptionList = local_10;
  return;
}


