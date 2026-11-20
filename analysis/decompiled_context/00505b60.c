
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_00505b60(int param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  char *pcVar4;
  QString *this;
  QString local_28 [4];
  QString local_24 [4];
  undefined *local_20;
  short local_1c [2];
  char local_18;
  char local_17;
  char local_16;
  char local_15;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054d22b;
  local_10 = ExceptionList;
  uVar2 = DAT_00759b24 ^ (uint)(local_1c + 0xc);
  ExceptionList = &local_10;
  local_14 = uVar2;
  cVar1 = FUN_005063f0(1,0xfffffff0,local_1c,8,0);
  if (cVar1 == '\0') {
    pcVar4 = "Read NAND ID failed!";
  }
  else {
    if ((((local_18 == '\x12') && (local_17 == '4')) && (local_16 == 'V')) && (local_15 == 'x')) {
      if (local_1c[0] == -0x2ae4) {
        local_20 = &DAT_00756a50;
        local_8 = 0;
        uVar3 = FUN_00486cd0(local_28);
        local_8._0_1_ = 1;
        uVar3 = FUN_004f6850(local_24,uVar3,&local_20);
        local_8 = CONCAT31(local_8._1_3_,2);
        cVar1 = FUN_00505530(uVar3,1);
        QString::~QString(local_24);
        this = local_28;
      }
      else {
        local_20 = &DAT_00756a8c;
        local_8 = 3;
        uVar3 = FUN_00486cd0(local_24);
        local_8._0_1_ = 4;
        uVar3 = FUN_004f6850(local_28,uVar3,&local_20);
        local_8 = CONCAT31(local_8._1_3_,5);
        cVar1 = FUN_00505530(uVar3,1);
        QString::~QString(local_28);
        this = local_24;
      }
      QString::~QString(this);
      local_8 = 0xffffffff;
      QString::~QString((QString *)&local_20);
      if (cVar1 != '\0') {
        FUN_005071f0();
        FUN_00505d00();
      }
      pcVar4 = "Successful!";
      if (cVar1 == '\0') {
        pcVar4 = "Failed!";
      }
      FUN_00486c20(pcVar4);
      QWidget::hide(*(QWidget **)(param_1 + 0x34));
      *(undefined4 *)(param_1 + 0x50) = 3;
      ExceptionList = local_10;
      return;
    }
    pcVar4 = "NAND ID check failed!";
  }
  FUN_00486c20(pcVar4,uVar2);
  ExceptionList = local_10;
  return;
}


