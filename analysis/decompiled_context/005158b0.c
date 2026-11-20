
void FUN_005158b0(undefined4 param_1,int param_2,int param_3,int param_4)

{
  QString aQStack_8 [4];
  
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_004f6ac0();
      return;
    }
    if (param_3 == 1) {
      QString::QString(aQStack_8,*(QString **)(param_4 + 4));
      FUN_004f71c0();
    }
    else if (param_3 == 2) {
      FUN_004f7180();
      return;
    }
  }
  return;
}


