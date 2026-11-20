
void __fastcall FUN_00484a20(int param_1)

{
  QSize *pQVar1;
  QSize local_1c [8];
  undefined *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0051b627;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pQVar1 = (QSize *)QSize::QSize(local_1c);
  local_14 = &DAT_00754000;
  local_8 = 0;
  QIcon::addFile((QIcon *)(param_1 + 0x4a0),(QString *)&local_14,pQVar1,0,0);
  QString::~QString((QString *)&local_14);
  pQVar1 = (QSize *)QSize::QSize(local_1c);
  local_14 = &DAT_00754074;
  local_8 = 1;
  QIcon::addFile((QIcon *)(param_1 + 0x4a4),(QString *)&local_14,pQVar1,0,0);
  QString::~QString((QString *)&local_14);
  ExceptionList = local_10;
  return;
}


