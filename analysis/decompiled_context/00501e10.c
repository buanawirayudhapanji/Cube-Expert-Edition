
QObject * __thiscall
FUN_00501e10(QDialog *param_1,QTypedArrayData<unsigned_short> *param_2,undefined4 param_3,
            undefined4 param_4,QTypedArrayData<unsigned_short> *param_5,undefined4 param_6)

{
  QDialog *this;
  QObject QVar1;
  char cVar2;
  CheckState CVar3;
  undefined4 uVar4;
  QVariant *pQVar5;
  int iVar6;
  QString *pQVar7;
  code *pcVar8;
  QVariant local_3c [16];
  QVariant local_2c [16];
  undefined4 local_1c;
  int local_18;
  QDialog *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054bd8e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = 0;
  local_14 = param_1;
  QDialog::QDialog(param_1,param_5,param_6,DAT_00759b24 ^ (uint)(local_2c + 0x28));
  *(undefined ***)(param_1 + 8) = BaseDialog::vftable;
  *(undefined ***)param_1 = CUpdateDialog::vftable;
  *(undefined ***)(param_1 + 8) = CUpdateDialog::vftable;
  *(undefined4 *)(param_1 + 0x50) = 3;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  local_8 = 1;
  FUN_00500d80();
  param_1[0x104] = param_2._0_1_;
  local_8._0_1_ = 2;
  *(undefined4 *)(param_1 + 0x118) = 0;
  *(undefined4 *)(param_1 + 0x124) = param_4;
  FUN_00503fe0(param_1);
  FUN_00503dd0();
  QWidget::setWindowFlags((QWidget *)param_1,*(uint *)(*(int *)(param_1 + 0x14) + 8) & 0xfffe7fff);
  QWidget::setWindowFlags((QWidget *)param_1,*(uint *)(*(int *)(param_1 + 0x14) + 8) | 0x100);
  *(undefined4 *)(param_1 + 0x4c) = param_3;
  QObject::connect((QObject *)&param_2,*(char **)(param_1 + 0x30),(QObject *)"2clicked()",
                   (char *)param_1,0x593168);
  QMetaObject::Connection::~Connection((Connection *)&param_2);
  QObject::connect((QObject *)&param_2,*(char **)(local_14 + 0x48),(QObject *)"2clicked()",
                   (char *)local_14,0x593180);
  QMetaObject::Connection::~Connection((Connection *)&param_2);
  QObject::connect((QObject *)&param_2,*(char **)(local_14 + 0x24),(QObject *)"2clicked(bool)",
                   (char *)local_14,0x593194);
  QMetaObject::Connection::~Connection((Connection *)&param_2);
  QObject::connect((QObject *)&param_2,*(char **)(local_14 + 0x38),(QObject *)"2clicked(bool)",
                   (char *)local_14,0x5931b0);
  QMetaObject::Connection::~Connection((Connection *)&param_2);
  QObject::connect((QObject *)&param_2,*(char **)(local_14 + 0x44),(QObject *)"2clicked(bool)",
                   (char *)local_14,0x5931c4);
  QMetaObject::Connection::~Connection((Connection *)&param_2);
  QObject::connect((QObject *)&param_2,*(char **)(local_14 + 0x2c),
                   (QObject *)"2currentIndexChanged(int)",(char *)local_14,0x5931dc);
  QMetaObject::Connection::~Connection((Connection *)&param_2);
  QEvent::registerEventType(0x3f0);
  this = local_14;
  CVar3 = QCheckBox::checkState(*(QCheckBox **)(local_14 + 0x24));
  param_2 = (QTypedArrayData<unsigned_short> *)CONCAT31((int3)(CVar3 >> 8),CVar3 != 2);
  param_5 = (QTypedArrayData<unsigned_short> *)CONCAT31(param_5._1_3_,CVar3 == 2);
  (**(code **)(**(int **)(this + 0x2c) + 0x2c))(param_2);
  (**(code **)(**(int **)(this + 0x28) + 0x2c))(param_2);
  uVar4 = param_5;
  (**(code **)(**(int **)(this + 0x1c) + 0x2c))(param_5);
  (**(code **)(**(int **)(this + 0x30) + 0x2c))(uVar4);
  (**(code **)(**(int **)(this + 0x20) + 0x2c))(uVar4);
  pcVar8 = hide_exref;
  QWidget::hide(*(QWidget **)(this + 0x34));
  (**(code **)(**(int **)(this + 0x38) + 0x2c))(*(QObject *)(this + 0x104));
  (**(code **)(**(int **)(this + 0x44) + 0x2c))(*(QObject *)(this + 0x104));
  if (*(QObject *)(this + 0x104) == (QObject)0x0) {
    *(QObject *)(this + 0x105) = (QObject)0x0;
  }
  else {
    uVar4 = QVariant::QVariant(local_3c);
    local_8._0_1_ = 3;
    param_2 = QString::fromAscii_helper("/Config/AutoUpdate",0x12);
    local_8._0_1_ = 4;
    pQVar5 = (QVariant *)FUN_00487a10(local_2c,&param_2,uVar4);
    local_8._0_1_ = 5;
    QVar1 = (QObject)QVariant::toBool(pQVar5);
    *(QObject *)(this + 0x105) = QVar1;
    QVariant::~QVariant(local_2c);
    QString::~QString((QString *)&param_2);
    local_8._0_1_ = 2;
    QVariant::~QVariant(local_3c);
    QAbstractButton::setChecked(*(QAbstractButton **)(this + 0x38),(bool)*(QObject *)(this + 0x105))
    ;
    iVar6 = QObject::startTimer((QObject *)this,200,1);
    pcVar8 = hide_exref;
    *(int *)(this + 0x10c) = iVar6;
  }
  *(undefined4 *)(this + 0x108) = 0;
  *(QObject *)(this + 0x11c) = (QObject)0x0;
  (*pcVar8)();
  (*pcVar8)();
  if (*(int *)(*(int *)(this + 0x4c) + 0xc844) == 3) {
LAB_0050211b:
    if (*(QObject *)(this + 0x104) == (QObject)0x0) goto LAB_0050212b;
  }
  else {
    iVar6 = FUN_00506990();
    if (iVar6 != 1) goto LAB_0050211b;
  }
  FUN_005035c0();
LAB_0050212b:
  uVar4 = QVariant::QVariant(local_2c);
  local_8._0_1_ = 6;
  param_5 = QString::fromAscii_helper("/Config/UpdateNotFinishedPath",0x1d);
  local_8._0_1_ = 7;
  pQVar5 = (QVariant *)FUN_00487a10(local_3c,&param_5,uVar4);
  local_8._0_1_ = 8;
  QVariant::toString(pQVar5);
  QVariant::~QVariant(local_3c);
  QString::~QString((QString *)&param_5);
  local_8._0_1_ = 0xc;
  QVariant::~QVariant(local_2c);
  if (*(int *)(local_18 + 4) == 0) {
    pQVar7 = (QString *)FUN_00486cd0(&param_3);
    local_8._0_1_ = 0xe;
    QString::QString((QString *)&param_2,pQVar7);
    local_1c = 1;
    pQVar7 = (QString *)QString::fromUtf8((char *)&param_4,0x593228);
    local_8._0_1_ = 0xf;
    QString::append((QString *)&param_2,pQVar7);
    local_8._0_1_ = 0xe;
    QString::~QString((QString *)&param_4);
    FUN_00487af0(&param_2);
    QString::~QString((QString *)&param_2);
    local_8._0_1_ = 0xc;
    QString::~QString((QString *)&param_3);
  }
  QWidget::setAcceptDrops((QWidget *)this,true);
  FUN_00505d00();
  iVar6 = *(int *)(*(int *)(this + 0x4c) + 0xc844);
  cVar2 = FUN_005069b0();
  if ((iVar6 == 3) ||
     (param_2 = (QTypedArrayData<unsigned_short> *)CONCAT31(param_2._1_3_,1), cVar2 == '\0')) {
    param_2 = (QTypedArrayData<unsigned_short> *)((uint)param_2 & 0xffffff00);
  }
  QWidget::setEnabled(*(QWidget **)(this + 0x48),SUB41(param_2,0));
  iVar6 = QComboBox::count(*(QComboBox **)(this + 0x2c));
  if (iVar6 == 0) {
    FUN_005035c0();
  }
  cVar2 = FUN_005069b0();
  if (cVar2 == '\0') {
    FUN_005071b0(1);
    thunk_FUN_00508160();
  }
  if ((*(QObject *)(this + 0x104) != (QObject)0x0) && (*(QObject *)(this + 0x105) != (QObject)0x0))
  {
    cVar2 = FUN_005069b0();
    if (cVar2 != '\0') {
      *(undefined4 *)(this + 0x108) = 1;
    }
  }
  cVar2 = FUN_005069b0();
  if (cVar2 != '\0') {
    if (*(int *)(*(int *)(this + 0x4c) + 0x2ca68) == 0x1fff0) {
      FUN_00505b60();
    }
  }
  *(undefined4 *)(this + 0x110) = 0xffffffff;
  if (*(int *)(this + 0x124) != 0) {
    iVar6 = QObject::startTimer((QObject *)this,500,1);
    *(int *)(this + 0x110) = iVar6;
    iVar6 = QObject::startTimer((QObject *)this,1000,1);
    *(int *)(this + 0x114) = iVar6;
  }
  QString::~QString((QString *)&local_18);
  ExceptionList = local_10;
  return (QObject *)this;
}


