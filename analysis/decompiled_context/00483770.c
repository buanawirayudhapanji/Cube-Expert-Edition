
QDialog * __thiscall
FUN_00483770(QDialog *param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  char cVar1;
  bool bVar2;
  int *piVar3;
  QWidget *this;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0051a89c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  QDialog::QDialog(param_1,param_3,param_4,DAT_00759b24 ^ (int)register0x00000010 - 4U);
  *(undefined ***)(param_1 + 8) = BaseDialog::vftable;
  *(undefined ***)param_1 = CLooperEditDlg::vftable;
  *(undefined ***)(param_1 + 8) = CLooperEditDlg::vftable;
  *(undefined4 *)(param_1 + 0x2c) = param_2;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  local_8 = 1;
  FUN_0050a570();
  local_8._0_1_ = 2;
  FUN_005114e0(*(undefined4 *)(param_1 + 0x2c));
  QIcon::QIcon((QIcon *)(param_1 + 0x4a0));
  QIcon::QIcon((QIcon *)(param_1 + 0x4a4));
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_004851a0(param_1);
  FUN_00484ec0();
  QWidget::hide(*(QWidget **)(param_1 + 0x28));
  QProgressBar::setRange(*(QProgressBar **)(param_1 + 0x28),0,100);
  QWidget::setWindowFlags((QWidget *)param_1,*(uint *)(*(int *)(param_1 + 0x14) + 8) & 0xfffe7fff);
  QWidget::setWindowFlags((QWidget *)param_1,*(uint *)(*(int *)(param_1 + 0x14) + 8) | 0x100);
  FUN_0050a5f0(1,12000,0x10);
  *(undefined4 *)(param_1 + 0x498) = 3;
  *(undefined4 *)(param_1 + 0x49c) = 0xffffffff;
  QEvent::registerEventType(0x3f0);
  FUN_00484a20();
  QObject::connect((QObject *)&param_3,*(char **)(param_1 + 0x18),
                   (QObject *)"2currentRowChanged(int)",(char *)param_1,0x580de0);
  QMetaObject::Connection::~Connection((Connection *)&param_3);
  QObject::connect((QObject *)&param_3,*(char **)(param_1 + 0x1c),(QObject *)"2clicked()",
                   (char *)param_1,0x580e10);
  QMetaObject::Connection::~Connection((Connection *)&param_3);
  QObject::connect((QObject *)&param_3,*(char **)(param_1 + 0x24),(QObject *)"2clicked()",
                   (char *)param_1,0x580e2c);
  QMetaObject::Connection::~Connection((Connection *)&param_3);
  QObject::connect((QObject *)&param_3,*(char **)(param_1 + 0x20),(QObject *)"2clicked()",
                   (char *)param_1,0x580e40);
  QMetaObject::Connection::~Connection((Connection *)&param_3);
  FUN_00485d60();
  if (*(int *)(*(int *)(param_1 + 0x2c) + 0xc844) != 3) {
    cVar1 = FUN_005069b0();
    param_3 = CONCAT13(1,(undefined3)param_3);
    if (cVar1 != '\0') goto LAB_00483951;
  }
  param_3 = param_3 & 0xffffff;
LAB_00483951:
  piVar3 = (int *)FUN_00488eb0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x2ca68));
  if (((piVar3 == (int *)0x0) || (*piVar3 == -1)) || (piVar3[0xf] == 0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if ((param_3._3_1_ == '\0') || (bVar2)) {
    QWidget::setEnabled(*(QWidget **)(param_1 + 0x24),false);
    if ((param_3._3_1_ == '\0') || (bVar2)) {
      QWidget::setEnabled(*(QWidget **)(param_1 + 0x1c),false);
      this = *(QWidget **)(param_1 + 0x20);
      if ((param_3._3_1_ == '\0') || (bVar2)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
    }
    else {
      QWidget::setEnabled(*(QWidget **)(param_1 + 0x1c),true);
      this = *(QWidget **)(param_1 + 0x20);
      bVar2 = true;
    }
  }
  else {
    QWidget::setEnabled(*(QWidget **)(param_1 + 0x24),true);
    QWidget::setEnabled(*(QWidget **)(param_1 + 0x1c),true);
    this = *(QWidget **)(param_1 + 0x20);
    bVar2 = true;
  }
  QWidget::setEnabled(this,bVar2);
  cVar1 = FUN_005069b0();
  if (cVar1 == '\0') {
    FUN_005071b0(1);
    thunk_FUN_00508160();
  }
  else {
    FUN_00484ad0();
  }
  ExceptionList = local_10;
  return param_1;
}


