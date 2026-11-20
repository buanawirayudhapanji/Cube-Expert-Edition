
void __thiscall FUN_004c1390(char *param_1,QSpinBox *param_2)

{
  byte bVar1;
  QWidget *pQVar2;
  undefined4 uVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  QListWidgetItem *pQVar7;
  QSize *pQVar8;
  QLabel *pQVar9;
  QSpinBox *pQVar10;
  QTextEdit *this;
  QComboBox *pQVar11;
  uint uVar12;
  int iVar13;
  char *pcVar14;
  undefined1 auStackY_170 [128];
  undefined1 *puVar15;
  QStringList *pQVar16;
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
  iVar13 = 0;
  local_2c = 0;
  iVar6 = QListWidget::count(*(QListWidget **)(param_1 + 0x8f0));
  if (0 < iVar6) {
    do {
      pQVar7 = QListWidget::item(*(QListWidget **)(param_1 + 0x8f0),iVar13);
      if (pQVar7 == (QListWidgetItem *)param_2) break;
      iVar13 = iVar13 + 1;
      iVar6 = QListWidget::count(*(QListWidget **)(param_1 + 0x8f0));
    } while (iVar13 < iVar6);
    local_2c = iVar13;
  }
  local_20 = checkedId_exref;
  iVar6 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x860));
  local_18 = param_1 + iVar13 * 5 + iVar6 * 0xa1 + 0x99a;
  local_11 = local_18[2];
  QDialog::QDialog(local_6c);
  local_8 = 0;
  iVar6 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x860));
  param_2 = (QSpinBox *)CONCAT13(iVar6 == 4,param_2._0_3_);
  pQVar8 = (QSize *)QSize::QSize(local_44,400,0xdc);
  QWidget::setFixedSize((QWidget *)local_6c,pQVar8);
  QFormLayout::QFormLayout(local_54,(QWidget *)local_6c);
  local_8._0_1_ = 1;
  QString::asprintf((char *)local_3c);
  local_8._0_1_ = 2;
  pQVar9 = operator_new(0x18);
  local_8._0_1_ = 3;
  local_28 = pQVar9;
  QLabel::QLabel(pQVar9);
  *(undefined ***)pQVar9 = QLabel::vftable;
  *(undefined ***)(pQVar9 + 8) = QLabel::vftable;
  local_8._0_1_ = 2;
  QFormLayout::addRow(local_54,(QWidget *)pQVar9);
  pQVar9 = operator_new(0x18);
  local_8._0_1_ = 4;
  local_28 = pQVar9;
  local_24 = QString::fromAscii_helper("Channel: ",9);
  local_8 = CONCAT31(local_8._1_3_,5);
  local_1c = 1;
  QLabel::QLabel(pQVar9);
  *(undefined ***)pQVar9 = QLabel::vftable;
  *(undefined ***)(pQVar9 + 8) = QLabel::vftable;
  *(QLabel **)(param_1 + 0x10e0) = pQVar9;
  local_8 = 2;
  QString::~QString((QString *)&local_24);
  pQVar10 = operator_new(0x18);
  local_8._0_1_ = 7;
  local_28 = (QLabel *)pQVar10;
  QSpinBox::QSpinBox(pQVar10,(QWidget *)local_6c);
  *(undefined ***)pQVar10 = QSpinBox::vftable;
  *(undefined ***)(pQVar10 + 8) = QSpinBox::vftable;
  local_8._0_1_ = 2;
  *(QSpinBox **)(param_1 + 0x10f0) = pQVar10;
  QSpinBox::setRange(pQVar10,1,0x10);
  QSpinBox::setValue(*(QSpinBox **)(param_1 + 0x10f0),(byte)local_18[1] + 1);
  QFormLayout::addRow(local_54,*(QWidget **)(param_1 + 0x10e0),*(QWidget **)(param_1 + 0x10f0));
  local_38 = QString::fromAscii_helper("Data: ",6);
  local_8._0_1_ = 8;
  pQVar9 = operator_new(0x18);
  local_8._0_1_ = 9;
  local_28 = pQVar9;
  local_24 = QString::fromAscii_helper("Data1: ",7);
  local_8 = CONCAT31(local_8._1_3_,10);
  local_1c = 2;
  QLabel::QLabel(pQVar9);
  *(undefined ***)pQVar9 = QLabel::vftable;
  *(undefined ***)(pQVar9 + 8) = QLabel::vftable;
  *(QLabel **)(param_1 + 0x10e4) = pQVar9;
  local_8 = 8;
  QString::~QString((QString *)&local_24);
  local_34 = QString::fromAscii_helper("Min Value: ",0xb);
  local_8._0_1_ = 0xc;
  pQVar10 = operator_new(0x18);
  local_8._0_1_ = 0xd;
  local_28 = (QLabel *)pQVar10;
  QSpinBox::QSpinBox(pQVar10,(QWidget *)local_6c);
  *(undefined ***)pQVar10 = QSpinBox::vftable;
  *(undefined ***)(pQVar10 + 8) = QSpinBox::vftable;
  local_8._0_1_ = 0xc;
  *(QSpinBox **)(param_1 + 0x10f4) = pQVar10;
  QSpinBox::setRange(pQVar10,0,0x7f);
  QSpinBox::setValue(*(QSpinBox **)(param_1 + 0x10f4),(uint)(byte)local_18[3]);
  pQVar9 = operator_new(0x18);
  local_8._0_1_ = 0xe;
  local_28 = pQVar9;
  local_24 = QString::fromAscii_helper("Data2: ",7);
  local_8 = CONCAT31(local_8._1_3_,0xf);
  local_1c = 4;
  QLabel::QLabel(pQVar9);
  *(undefined ***)pQVar9 = QLabel::vftable;
  *(undefined ***)(pQVar9 + 8) = QLabel::vftable;
  *(QLabel **)(param_1 + 0x10e8) = pQVar9;
  local_8 = 0xc;
  QString::~QString((QString *)&local_24);
  local_30 = QString::fromAscii_helper("Max Value: ",0xb);
  local_8._0_1_ = 0x11;
  pQVar10 = operator_new(0x18);
  local_8._0_1_ = 0x12;
  local_28 = (QLabel *)pQVar10;
  QSpinBox::QSpinBox(pQVar10,(QWidget *)local_6c);
  *(undefined ***)pQVar10 = QSpinBox::vftable;
  *(undefined ***)(pQVar10 + 8) = QSpinBox::vftable;
  local_8._0_1_ = 0x11;
  *(QSpinBox **)(param_1 + 0x10f8) = pQVar10;
  QSpinBox::setRange(pQVar10,0,0x7f);
  pcVar14 = local_18;
  QSpinBox::setValue(*(QSpinBox **)(param_1 + 0x10f8),(uint)(byte)local_18[4]);
  pQVar10 = operator_new(0x18);
  if (iVar6 == 4) {
    local_8._0_1_ = 0x13;
    local_28 = (QLabel *)pQVar10;
    QSpinBox::QSpinBox(pQVar10,(QWidget *)local_6c);
    *(undefined ***)pQVar10 = QSpinBox::vftable;
    *(undefined ***)(pQVar10 + 8) = QSpinBox::vftable;
    local_8 = CONCAT31(local_8._1_3_,0x11);
    QSpinBox::setRange(pQVar10,0,0x7f);
    QSpinBox::setValue(pQVar10,(uint)(byte)pcVar14[2]);
    QFormLayout::addRow(local_54,(QString *)&local_38,(QWidget *)pQVar10);
    QFormLayout::addRow(local_54,(QString *)&local_34,*(QWidget **)(param_1 + 0x10f4));
    QFormLayout::addRow(local_54,(QString *)&local_30,*(QWidget **)(param_1 + 0x10f8));
    param_2 = pQVar10;
    pcVar14 = local_18;
  }
  else {
    local_8._0_1_ = 0x14;
    local_40 = pQVar10;
    local_24 = QString::fromAscii_helper("Custom Midi Code: ",0x12);
    local_8 = CONCAT31(local_8._1_3_,0x15);
    local_1c = 8;
    QLabel::QLabel((QLabel *)pQVar10);
    *(undefined ***)pQVar10 = QLabel::vftable;
    *(undefined ***)(pQVar10 + 8) = QLabel::vftable;
    *(QSpinBox **)(param_1 + 0x10ec) = pQVar10;
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
    pQVar11 = operator_new(0x18);
    local_8._0_1_ = 0x19;
    local_40 = (QSpinBox *)pQVar11;
    QComboBox::QComboBox(pQVar11,(QWidget *)local_6c);
    *(undefined ***)pQVar11 = QComboBox::vftable;
    *(undefined ***)(pQVar11 + 8) = QComboBox::vftable;
    local_8._0_1_ = 0x18;
    *(QComboBox **)(param_1 + 0x10fc) = pQVar11;
    QWidget::setFixedWidth((QWidget *)pQVar11,0xaa);
    pQVar11 = *(QComboBox **)(param_1 + 0x10fc);
    pQVar16 = (QStringList *)(param_1 + 0x10d8);
    iVar13 = QComboBox::count(pQVar11);
    QComboBox::insertItems(pQVar11,iVar13,pQVar16);
    bVar1 = local_18[2];
    if (bVar1 == 0) {
      uVar12 = 0;
    }
    else {
      uVar12 = 4;
      if (bVar1 < 4) {
        uVar12 = (uint)bVar1;
      }
    }
    QComboBox::setCurrentIndex(*(QComboBox **)(param_1 + 0x10fc),uVar12);
    pQVar2 = *(QWidget **)(param_1 + 0x10fc);
    pQVar9 = operator_new(0x18);
    local_8._0_1_ = 0x1a;
    local_40 = (QSpinBox *)pQVar9;
    local_24 = QString::fromAscii_helper("Midi Type: ",0xb);
    local_8 = CONCAT31(local_8._1_3_,0x1b);
    local_1c = 0x10;
    QLabel::QLabel(pQVar9,&local_24,0);
    *(undefined ***)pQVar9 = QLabel::vftable;
    *(undefined ***)(pQVar9 + 8) = QLabel::vftable;
    local_8 = 0x1c;
    QFormLayout::addRow(local_54,(QWidget *)pQVar9,pQVar2);
    local_8 = 0x18;
    QString::~QString((QString *)&local_24);
    QFormLayout::addRow(local_54,*(QWidget **)(param_1 + 0x10e4),*(QWidget **)(param_1 + 0x10f4));
    QFormLayout::addRow(local_54,*(QWidget **)(param_1 + 0x10e8),*(QWidget **)(param_1 + 0x10f8));
    QFormLayout::addRow(local_54,*(QWidget **)(param_1 + 0x10ec),*(QWidget **)(param_1 + 0x1100));
    QObject::connect((QObject *)&local_24,*(char **)(param_1 + 0x10fc),
                     (QObject *)"2currentIndexChanged(int)",param_1,0x589514);
    QMetaObject::Connection::~Connection((Connection *)&local_24);
    pcVar14 = local_18;
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
  iVar13 = QDialog::exec(local_6c);
  if (iVar13 == 1) {
    iVar13 = QSpinBox::value(*(QSpinBox **)(param_1 + 0x10f0));
    *pcVar14 = '\x01';
    pcVar14[1] = (char)iVar13 + -1;
    iVar13 = QSpinBox::value(*(QSpinBox **)(param_1 + 0x10f4));
    pcVar14[3] = (char)iVar13;
    iVar13 = QSpinBox::value(*(QSpinBox **)(param_1 + 0x10f8));
    pcVar14[4] = (char)iVar13;
    if (iVar6 == 4) {
      iVar6 = QSpinBox::value(param_2);
      cVar5 = (char)iVar6;
    }
    else {
      iVar6 = QComboBox::currentIndex(*(QComboBox **)(param_1 + 0x10fc));
      cVar5 = (char)iVar6;
    }
    pcVar4 = local_20;
    pcVar14[2] = cVar5;
    if (cVar5 == '\x04') {
      (*local_20)();
      (*pcVar4)();
      puVar15 = auStackY_170 + 0x94;
      QTextEdit::toPlainText(*(QTextEdit **)(param_1 + 0x1100));
      FUN_004ca1a0(puVar15);
      if (local_2c != 0) {
        cVar5 = pcVar14[2];
        iVar6 = (*local_20)();
        param_1[iVar6 * 0xa1 + 0x99c] = cVar5;
        pcVar14[2] = local_11;
      }
    }
    uVar3 = *(undefined4 *)(param_1 + 0x8f0);
    iVar6 = (*local_20)();
    FUN_004ca340(0,param_1 + iVar6 * 0xa1 + 0x99a,uVar3);
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


