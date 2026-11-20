
void FUN_004dc350(undefined *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0051b77a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  switch(param_1) {
  case (undefined *)0x0:
    param_1 = &DAT_00756084;
    local_8 = 0;
    break;
  case (undefined *)0x1:
    param_1 = &DAT_007560b0;
    local_8 = 1;
    break;
  case (undefined *)0x2:
    param_1 = &DAT_007560e4;
    local_8 = 2;
    break;
  case (undefined *)0x3:
    param_1 = &DAT_00756120;
    local_8 = 3;
    break;
  case (undefined *)0x4:
    param_1 = &DAT_00756154;
    local_8 = 4;
    break;
  case (undefined *)0x5:
    param_1 = &DAT_0075618c;
    local_8 = 5;
    break;
  case (undefined *)0x6:
    param_1 = &DAT_007561bc;
    local_8 = 6;
    break;
  case (undefined *)0x7:
    param_1 = &DAT_007561f0;
    local_8 = 7;
    break;
  case (undefined *)0x8:
    param_1 = &DAT_00756220;
    local_8 = 8;
    break;
  case (undefined *)0x9:
    param_1 = &DAT_00756254;
    local_8 = 9;
    break;
  case (undefined *)0xa:
    param_1 = &DAT_0075628c;
    local_8 = 10;
    break;
  case (undefined *)0xb:
    param_1 = &DAT_007562cc;
    local_8 = 0xb;
    break;
  default:
    param_1 = &DAT_0075630c;
    local_8 = 0xc;
  }
  FUN_00486bb0(&param_1,DAT_00759b24 ^ (int)register0x00000010 - 4U);
  QString::~QString((QString *)&param_1);
  ExceptionList = local_10;
  return;
}


