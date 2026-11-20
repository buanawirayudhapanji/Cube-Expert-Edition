
bool __thiscall FUN_00488fa0(QWidget *param_1,QEvent *param_2)

{
  bool bVar1;
  QString *pQVar2;
  undefined4 *puVar3;
  char *pcVar4;
  QMessageLogger *this;
  QMessageLogger local_34 [28];
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0052259e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(short *)(param_2 + 8) == 0x6e) {
    pQVar2 = (QString *)QWidget::toolTip(param_1);
    local_8 = 0;
    puVar3 = (undefined4 *)QCursor::pos();
    local_18 = *puVar3;
    local_14 = puVar3[1] + 10;
    QToolTip::showText((QPoint *)&local_18,pQVar2,param_1);
    local_8 = 0xffffffff;
    QString::~QString((QString *)&param_2);
    pcVar4 = (char *)QMessageLogger::QMessageLogger(local_34,(char *)0x0,0,(char *)0x0);
    QMessageLogger::debug(this,pcVar4,"QParamDail::event");
    ExceptionList = local_10;
    return true;
  }
  bVar1 = QDial::event((QDial *)param_1,param_2);
  ExceptionList = local_10;
  return bVar1;
}


