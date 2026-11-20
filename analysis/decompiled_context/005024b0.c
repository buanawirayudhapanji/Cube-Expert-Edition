
void __thiscall FUN_005024b0(int param_1,QTypedArrayData<unsigned_short> *param_2)

{
  uint uVar1;
  char *pcVar2;
  undefined4 uVar3;
  QVariant local_20 [16];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054c937;
  local_10 = ExceptionList;
  uVar1 = DAT_00759b24 ^ (uint)(local_20 + 0x1c);
  ExceptionList = &local_10;
  *(bool *)(param_1 + 0x105) = SUB41(param_2,0);
  QVariant::QVariant(local_20,SUB41(param_2,0));
  uVar3 = 0x12;
  pcVar2 = "/Config/AutoUpdate";
  local_8 = 0;
  param_2 = QString::fromAscii_helper("/Config/AutoUpdate",0x12);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_00487c00(&param_2,local_20,pcVar2,uVar3,uVar1);
  QString::~QString((QString *)&param_2);
  QVariant::~QVariant(local_20);
  ExceptionList = local_10;
  return;
}


