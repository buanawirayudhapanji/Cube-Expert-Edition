
void __thiscall FUN_004a5e10(QObject *param_1,undefined4 param_2)

{
  uint uVar1;
  QObject *this;
  QString *pQVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0052c59e;
  local_10 = ExceptionList;
  uVar1 = DAT_00759b24 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  this = QObject::sender(param_1);
  pQVar2 = (QString *)QString::asprintf((char *)&param_2,&DAT_005842a8,param_2,uVar1);
  local_8 = 0;
  QWidget::setToolTip((QWidget *)this,pQVar2);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&param_2);
  if ((*(int *)(param_1 + 0x80) - *(int *)(param_1 + 0x7c) & 0xfffffff8U) != 0) {
    FUN_004a7040();
  }
  ExceptionList = local_10;
  return;
}


