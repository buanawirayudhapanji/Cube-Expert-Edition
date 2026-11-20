
void __thiscall FUN_0050d810(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  uint uVar2;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  QString local_3c [4];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0055871d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = (int *)*param_1;
  local_14 = piVar1[2] & 0x7fffffff;
  local_18 = piVar1[1] + 1;
  if (((*piVar1 == 1) || (*piVar1 == 0)) && (local_18 <= local_14)) {
    FUN_0050cf60(param_2);
  }
  else {
    local_4c = *param_2;
    uStack_48 = param_2[1];
    uStack_44 = param_2[2];
    uStack_40 = param_2[3];
    QString::QString(local_3c,(QString *)(param_2 + 4));
    local_38 = param_2[5];
    local_34 = param_2[6];
    local_30 = param_2[7];
    local_2c = param_2[8];
    local_28 = param_2[9];
    local_24 = param_2[10];
    local_20 = param_2[0xb];
    local_1c = *(undefined1 *)(param_2 + 0xc);
    local_8 = 0;
    if (local_14 < local_18) {
      uVar2 = *(int *)(*param_1 + 4) + 1;
    }
    else {
      uVar2 = *(uint *)(*param_1 + 8) & 0x7fffffff;
    }
    FUN_0050e400(uVar2,-(local_14 < local_18) & 8);
    FUN_0050cf00(&local_4c);
    QString::~QString(local_3c);
  }
  *(int *)(*param_1 + 4) = *(int *)(*param_1 + 4) + 1;
  ExceptionList = local_10;
  return;
}


