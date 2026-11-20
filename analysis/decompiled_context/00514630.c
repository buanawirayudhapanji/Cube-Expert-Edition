
int FUN_00514630(int param_1,char **param_2)

{
  QTextCodec *pQVar1;
  QWidget *this;
  int iVar2;
  QApplication local_1c [8];
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005621bd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  QApplication::QApplication(local_1c,&param_1,param_2,0x50f02);
  local_8 = 0;
  pQVar1 = QTextCodec::codecForName("GB18030");
  QTextCodec::setCodecForLocale(pQVar1);
  local_14 = operator_new(0x54);
  local_8._0_1_ = 1;
  this = (QWidget *)FUN_004de510(0,0);
  local_8 = (uint)local_8._1_3_ << 8;
  QWidget::show(this);
  iVar2 = QApplication::exec();
  QApplication::~QApplication(local_1c);
  ExceptionList = local_10;
  return iVar2;
}


