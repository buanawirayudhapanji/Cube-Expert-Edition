
void __thiscall FUN_004c1bd0(char *param_1,QSpinBox *param_2)

{
  byte bVar1;
  QWidget *pQVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  QListWidgetItem *pQVar6;
  QSize *pQVar7;
  QLabel *pQVar8;
  QSpinBox *pQVar9;
  QTextEdit *this;
  QComboBox *pQVar10;
  uint uVar11;
  int iVar12;
  char *pcVar13;
  undefined1 auStackY_170 [128];
  undefined1 *puVar14;
  QStringList *pQVar15;
  QDialogButtonBox local_84 [24];
  QDialog local_6c [24];
  QFormLayout local_54 [16];
  QSize local_44 [4];
  QSpinBox *local_40;
  QString local_3c [4];
  QTypedArrayData<unsigned_short> *local_38;
  QTypedArrayData<unsigned_short> *local_34;
  QTypedArrayData<unsigned_short> *local_30;
  int local_2c;
  QLabel *local_28;
  QTypedArrayData<unsigned_short> *local_24;
  code *local_20;
  undefined4 local_1c;
  char *local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005356b3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = 0;
  iVar12 = 0;
  local_2c = 0;
  iVar5 = QListWidget::count(*(QListWidget **)(param_1 + 0x8fc));
  if (0 < iVar5) {
    do {
      pQVar6 = QListWidget::item(*(QListWidget **)(param_1 + 0x8fc),iVar12);
      if (pQVar6 == (QListWidgetItem *)param_2) break;
      iVar12 = iVar12 + 1;
      iVar5 = QListWidget::count(*(QListWidget **)(param_1 + 0x8fc));
    } while (iVar12 < iVar5);
    local_2c = iVar12;
  }
  local_20 = checkedId_exref;
  iVar5 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x860));
  local_18 = param_1 + iVar12 * 5 + iVar5 * 0xa1 + 0x9ea;
  local_11 = local_18[2];
  QDialog::QDialog(local_6c);
  local_8 = 0;
  iVar5 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x860));
  param_2 = (QSpinBox *)CONCAT13(iVar5 == 4,param_2._0_3_);
  pQVar7 = (QSize *)QSize::QSize(local_44,400,0xdc);
  QWidget::setFixedSize((QWidget *)local_6c,pQVar7);
  QFormLayout::QFormLayout(local_54,(QWidget *)local_6c);
  local_8._0_1_ = 1;
  QString::asprintf((char *)local_3c);
  local_8._0_1_ = 2;
  pQVar8 = operator_new(0x18);
  local_8._0_1_ = 3;
  local_28 = pQVar8;
  QLabel::QLabel(pQVar8);
  *(undefined ***)pQVar8 = QLabel::vftable;
  *(undefined ***)(pQVar8 + 8) = QLabel::vftable;
  local_8._0_1_ = 2;
  QFormLayout::addRow(local_54,(QWidget *)pQVar8);
  pQVar8 = operator_new(0x18);
  local_8._0_1_ = 4;
  local_28 = pQVar8;
  local_24 = QString::fromAscii_helper("Channel: ",9);
  local_8 = CONCAT31(local_8._1_3_,5);
  local_1c = 1;
  QLabel::QLabel(pQVar8);
  *(undefined ***)pQVar8 = QLabel::vftable;
  *(undefined ***)(pQVar8 + 8) = QLabel::vftable;
  *(QLabel **)(param_1 + 0x10e0) = pQVar8;
  local_8 = 2;
  QString::~QString((QString *)&local_24);
  pQVar9 = operator_new(0x18);
  local_8._0_1_ = 7;
  local_28 = (QLabel *)pQVar9;
  QSpinBox::QSpinBox(pQVar9,(QWidget *)local_6c);
  *(undefined ***)pQVar9 = QSpinBox::vftable;
  *(undefined ***)(pQVar9 + 8) = QSpinBox::vftable;
  local_8._0_1_ = 2;
  *(QSpinBox **)(param_1 + 0x10f0) = pQVar9;
  QSpinBox::setRange(pQVar9,1,0x10);
  QSpinBox::setValue(*(QSpinBox **)(param_1 + 0x10f0),(byte)local_18[1] + 1);
  QFormLayout::addRow(local_54,*(QWidget **)(param_1 + 0x10e0),*(QWidget **)(param_1 + 0x10f0));
  local_38 = QString::fromAscii_helper("Data: ",6);
  local_8._0_1_ = 8;
  pQVar8 = operator_new(0x18);
  local_8._0_1_ = 9;
  local_28 = pQVar8;
  local_24 = QString::fromAscii_helper("Data1: ",7);
  local_8 = CONCAT31(local_8._1_3_,10);
  local_1c = 2;
  QLabel::QLabel(pQVar8);
  *(undefined ***)pQVar8 = QLabel::vftable;
  *(undefined ***)(pQVar8 + 8) = QLabel::vftable;
  *(QLabel **)(param_1 + 0x10e4) = pQVar8;
  local_8 = 8;
  QString::~QString((QString *)&local_24);
  local_34 = QString::fromAscii_helper("Min Value: ",0xb);
  local_8._0_1_ = 0xc;
  pQVar9 = operator_new(0x18);
  local_8._0_1_ = 0xd;
  local_28 = (QLabel *)pQVar9;
  QSpinBox::QSpinBox(pQVar9,(QWidget *)local_6c);
  *(undefined ***)pQVar9 = QSpinBox::vftable;
  *(undefined ***)(pQVar9 + 8) = QSpinBox::vftable;
  local_8._0_1_ = 0xc;
  *(QSpinBox **)(param_1 + 0x10f4) = pQVar9;
  QSpinBox::setRange(pQVar9,0,0x7f);
  QSpinBox::setValue(*(QSpinBox **)(param_1 + 0x10f4),(uint)(byte)local_18[3]);
  pQVar8 = operator_new(0x18);
  local_8._0_1_ = 0xe;
  local_28 = pQVar8;
  local_24 = QString::fromAscii_helper("Data2: ",7);
  local_8 = CONCAT31(local_8._1_3_,0xf);
  local_1c = 4;
  QLabel::QLabel(pQVar8);
  *(undefined ***)pQVar8 = QLabel::vftable;
  *(undefined ***)(pQVar8 + 8) = QLabel::vftable;
  *(QLabel **)(param_1 + 0x10e8) = pQVar8;
  local_8 = 0xc;
  QString::~QString((QString *)&local_24);
  local_30 = QString::fromAscii_helper("Max Value: ",0xb);
  local_8._0_1_ = 0x11;
  pQVar9 = operator_new(0x18);
  local_8._0_1_ = 0x12;
  local_28 = (QLabel *)pQVar9;
  QSpinBox::QSpinBox(pQVar9,(QWidget *)local_6c);
  *(undefined ***)pQVar9 = QSpinBox::vftable;
  *(undefined ***)(pQVar9 + 8) = QSpinBox::vftable;
  local_8._0_1_ = 0x11;
  *(QSpinBox **)(param_1 + 0x10f8) = pQVar9;
  QSpinBox::setRange(pQVar9,0,0x7f);
  pcVar13 = local_18;
  QSpinBox::setValue(*(QSpinBox **)(param_1 + 0x10f8),(uint)(byte)local_18[4]);
  pQVar9 = operator_new(0x18);
  if (iVar5 == 4) {
    local_8._0_1_ = 0x13;
    local_28 = (QLabel *)pQVar9;
    QSpinBox::QSpinBox(pQVar9,(QWidget *)local_6c);
    *(undefined ***)pQVar9 = QSpinBox::vftable;
    *(undefined ***)(pQVar9 + 8) = QSpinBox::vftable;
    local_8 = CONCAT31(local_8._1_3_,0x11);
    QSpinBox::setRange(pQVar9,0,0x7f);
    QSpinBox::setValue(pQVar9,(uint)(byte)pcVar13[2]);
    QFormLayout::addRow(local_54,(QString *)&local_38,(QWidget *)pQVar9);
    QFormLayout::addRow(local_54,(QString *)&local_34,*(QWidget **)(param_1 + 0x10f4));
    QFormLayout::addRow(local_54,(QString *)&local_30,*(QWidget **)(param_1 + 0x10f8));
    param_2 = pQVar9;
    pcVar13 = local_18;
  }
  else {
    local_8._0_1_ = 0x14;
    local_40 = pQVar9;
    local_24 = QString::fromAscii_helper("Custom Midi Code: ",0x12);
    local_8 = CONCAT31(local_8._1_3_,0x15);
    local_1c = 8;
    QLabel::QLabel((QLabel *)pQVar9);
    *(undefined ***)pQVar9 = QLabel::vftable;
    *(undefined ***)(pQVar9 + 8) = QLabel::vftable;
    *(QSpinBox **)(param_1 + 0x10ec) = pQVar9;
    local_8 = 0x11;
    QString::~QString((QString *)&local_24);
    this = operator_new(0x18);
    local_8._0_1_ = 0x17;
    local_40 = (QSpinBox *)this;
    QTextEdit::QTextEdit(this,(QWidget *)local_6c);
    *(undefined ***)this = QTextEdit::vftable;
    *(undefined ***)(this + 8) = QTextEdit::vftable;
    local_8._0_1_ = 0x11;
    *(QTextEdit **)(param_1 + 0x1100) = this;
    (*local_20)();
    FUN_004c4ae0(&local_28);
    local_8._0_1_ = 0x18;
    QTextEdit::setText(*(QTextEdit **)(param_1 + 0x1100),(QString *)&local_28);
    pQVar10 = operator_new(0x18);
    local_8._0_1_ = 0x19;
    local_40 = (QSpinBox *)pQVar10;
    QComboBox::QComboBox(pQVar10,(QWidget *)local_6c);
    *(undefined ***)pQVar10 = QComboBox::vftable;
    *(undefined ***)(pQVar10 + 8) = QComboBox::vftable;
    local_8._0_1_ = 0x18;
    *(QComboBox **)(param_1 + 0x10fc) = pQVar10;
    QWidget::setFixedWidth((QWidget *)pQVar10,0xaa);
    pQVar10 = *(QComboBox **)(param_1 + 0x10fc);
    pQVar15 = (QStringList *)(param_1 + 0x10d8);
    iVar12 = QComboBox::count(pQVar10);
    QComboBox::insertItems(pQVar10,iVar12,pQVar15);
    bVar1 = local_18[2];
    if (bVar1 == 0) {
      uVar11 = 0;
    }
    else {
      uVar11 = 4;
      if (bVar1 < 4) {
        uVar11 = (uint)bVar1;
      }
    }
    QComboBox::setCurrentIndex(*(QComboBox **)(param_1 + 0x10fc),uVar11);
    pQVar2 = *(QWidget **)(param_1 + 0x10fc);
    pQVar8 = operator_new(0x18);
    local_8._0_1_ = 0x1a;
    local_40 = (QSpinBox *)pQVar8;
    local_24 = QString::fromAscii_helper("Midi Type: ",0xb);
    local_8 = CONCAT31(local_8._1_3_,0x1b);
    local_1c = 0x10;
    QLabel::QLabel(pQVar8,&local_24,0);
    *(undefined ***)pQVar8 = QLabel::vftable;
    *(undefined ***)(pQVar8 + 8) = QLabel::vftable;
    local_8 = 0x1c;
    QFormLayout::addRow(local_54,(QWidget *)pQVar8,pQVar2);
    local_8 = 0x18;
    QString::~QString((QString *)&local_24);
    QFormLayout::addRow(local_54,*(QWidget **)(param_1 + 0x10e4),*(QWidget **)(param_1 + 0x10f4));
    QFormLayout::addRow(local_54,*(QWidget **)(param_1 + 0x10e8),*(QWidget **)(param_1 + 0x10f8));
    QFormLayout::addRow(local_54,*(QWidget **)(param_1 + 0x10ec),*(QWidget **)(param_1 + 0x1100));
    QObject::connect((QObject *)&local_24,*(char **)(param_1 + 0x10fc),
                     (QObject *)"2currentIndexChanged(int)",param_1,0x589514);
    QMetaObject::Connection::~Connection((Connection *)&local_24);
    pcVar13 = local_18;
    FUN_004c49b0();
    local_8 = CONCAT31(local_8._1_3_,0x11);
    QString::~QString((QString *)&local_28);
  }
  QDialogButtonBox::QDialogButtonBox(local_84);
  local_8 = CONCAT31(local_8._1_3_,0x1d);
  QFormLayout::addRow(local_54,(QWidget *)local_84);
  QObject::connect((QObject *)&local_28,(char *)local_84,(QObject *)"2accepted()",(char *)local_6c,
                   0x5894e4);
  QMetaObject::Connection::~Connection((Connection *)&local_28);
  QObject::connect((QObject *)&local_28,(char *)local_84,(QObject *)"2rejected()",(char *)local_6c,
                   0x5894fc);
  QMetaObject::Connection::~Connection((Connection *)&local_28);
  iVar12 = QDialog::exec(local_6c);
  if (iVar12 == 1) {
    iVar12 = QSpinBox::value(*(QSpinBox **)(param_1 + 0x10f0));
    *pcVar13 = '\x01';
    pcVar13[1] = (char)iVar12 + -1;
    iVar12 = QSpinBox::value(*(QSpinBox **)(param_1 + 0x10f4));
    pcVar13[3] = (char)iVar12;
    iVar12 = QSpinBox::value(*(QSpinBox **)(param_1 + 0x10f8));
    pcVar13[4] = (char)iVar12;
    if (iVar5 == 4) {
      iVar5 = QSpinBox::value(param_2);
      cVar4 = (char)iVar5;
    }
    else {
      iVar5 = QComboBox::currentIndex(*(QComboBox **)(param_1 + 0x10fc));
      cVar4 = (char)iVar5;
    }
    pcVar13[2] = cVar4;
    if (cVar4 == '\x04') {
      (*local_20)();
      puVar14 = auStackY_170 + 0x94;
      QTextEdit::toPlainText(*(QTextEdit **)(param_1 + 0x1100));
      FUN_004ca1a0(puVar14);
      if (local_2c != 0) {
        cVar4 = pcVar13[2];
        iVar5 = (*local_20)();
        param_1[iVar5 * 0xa1 + 0x9ec] = cVar4;
        pcVar13[2] = local_11;
      }
    }
    uVar3 = *(undefined4 *)(param_1 + 0x8fc);
    iVar5 = (*local_20)();
    FUN_004ca340(1,param_1 + iVar5 * 0xa1 + 0x9ea,uVar3);
  }
  QDialogButtonBox::~QDialogButtonBox(local_84);
  QString::~QString((QString *)&local_30);
  QString::~QString((QString *)&local_34);
  QString::~QString((QString *)&local_38);
  QString::~QString(local_3c);
  QFormLayout::~QFormLayout(local_54);
  QDialog::~QDialog(local_6c);
  ExceptionList = local_10;
  return;
}


