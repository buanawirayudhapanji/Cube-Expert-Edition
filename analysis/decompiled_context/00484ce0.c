
void FUN_00484ce0(undefined *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0051b77a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  switch(param_1) {
  case (undefined *)0x0:
    param_1 = &DAT_007542d0;
    local_8 = 0;
    break;
  case (undefined *)0x1:
    param_1 = &DAT_007542fc;
    local_8 = 1;
    break;
  case (undefined *)0x2:
    param_1 = &DAT_00754330;
    local_8 = 2;
    break;
  case (undefined *)0x3:
    param_1 = &DAT_0075436c;
    local_8 = 3;
    break;
  case (undefined *)0x4:
    param_1 = &DAT_007543a0;
    local_8 = 4;
    break;
  case (undefined *)0x5:
    param_1 = &DAT_007543d8;
    local_8 = 5;
    break;
  case (undefined *)0x6:
    param_1 = &DAT_00754408;
    local_8 = 6;
    break;
  case (undefined *)0x7:
    param_1 = &DAT_0075443c;
    local_8 = 7;
    break;
  case (undefined *)0x8:
    param_1 = &DAT_0075446c;
    local_8 = 8;
    break;
  case (undefined *)0x9:
    param_1 = &DAT_007544a0;
    local_8 = 9;
    break;
  case (undefined *)0xa:
    param_1 = &DAT_007544d8;
    local_8 = 10;
    break;
  case (undefined *)0xb:
    param_1 = &DAT_00754518;
    local_8 = 0xb;
    break;
  default:
    param_1 = &DAT_00754558;
    local_8 = 0xc;
  }
  FUN_00486bb0(&param_1,DAT_00759b24 ^ (int)register0x00000010 - 4U);
  QString::~QString((QString *)&param_1);
  ExceptionList = local_10;
  return;
}


