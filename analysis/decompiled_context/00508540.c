
undefined1 FUN_00508540(undefined4 param_1)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  QMessageLogger *this;
  QDebug *this_00;
  __int64 _Var4;
  QMessageLogger local_30 [20];
  QFile local_1c [12];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00551b17;
  local_10 = ExceptionList;
  uVar2 = DAT_00759b24 ^ (uint)(local_1c + 0x18);
  ExceptionList = &local_10;
  uVar1 = 0;
  QFile::QFile(local_1c);
  local_8 = 0;
  iVar3 = FUN_00486ef0(local_1c,param_1,1,1,uVar2);
  if (iVar3 != 0) {
    uVar1 = FUN_00508250();
    this = (QMessageLogger *)QMessageLogger::QMessageLogger(local_30,(char *)0x0,0,(char *)0x0);
    this_00 = (QDebug *)QMessageLogger::debug(this);
    local_8._0_1_ = 1;
    _Var4 = QFile::size(local_1c);
    QDebug::operator<<(this_00,_Var4);
    local_8 = (uint)local_8._1_3_ << 8;
    QDebug::~QDebug((QDebug *)&param_1);
    QFileDevice::close((QFileDevice *)local_1c);
  }
  QFile::~QFile(local_1c);
  ExceptionList = local_10;
  return uVar1;
}


