
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_0050b900(QToolButton *param_1)

{
  bool bVar1;
  QMenu *this;
  undefined4 uVar2;
  QColor *pQStack_58;
  QToolButton *pQStack_54;
  undefined4 uStack_50;
  QString local_38 [4];
  QColor local_34 [16];
  QColor local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00553e9e;
  local_10 = ExceptionList;
  local_14 = DAT_00759b24 ^ (uint)(local_24 + 0x20);
  ExceptionList = &local_10;
  this = QToolButton::menu(param_1);
  QWidget::close((QWidget *)this);
  uVar2 = QString::QString(local_38);
  local_8 = 0;
  uStack_50 = 0x50b957;
  QColor::QColor(local_34,2);
  pQStack_58 = local_34;
  pQStack_54 = param_1;
  uStack_50 = uVar2;
  QColorDialog::getColor(local_24);
  local_8 = 0xffffffff;
  QString::~QString(local_38);
  bVar1 = QColor::isValid(local_24);
  if (bVar1) {
    QColor::QColor((QColor *)&pQStack_58,local_24);
    FUN_00514770();
  }
  ExceptionList = local_10;
  return;
}


