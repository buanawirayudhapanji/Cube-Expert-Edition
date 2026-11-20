
void __thiscall
FUN_0050da60(int param_1,QRect *param_2,undefined4 param_3,char *param_4,int param_5,int param_6,
            int param_7,int param_8,QString param_9,undefined4 param_10)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  QRect local_20 [16];
  double local_10;
  int local_8;
  
  *(int *)(param_2 + 0x1c) = param_5 + -7;
  *(int *)(param_2 + 0x20) = param_6 + -7;
  *(int *)(param_2 + 0x24) = param_7 + -7;
  *(int *)(param_2 + 0x28) = param_8 + -7;
  *(undefined4 *)(param_2 + 0x2c) = param_10;
  local_8 = param_1;
  QString::operator=((QString *)(param_2 + 0x10),&param_9);
  *(undefined4 *)(param_2 + 0x14) = param_3;
  *(char **)(param_2 + 0x18) = param_4;
  local_10 = 0.0;
  if (param_2[0x30] != (QRect)0x0) {
    local_10 = (double)(int)*param_4;
  }
  puVar4 = (undefined4 *)QRect::QRect(local_20,0,0,0xe,0xe);
  uVar1 = puVar4[1];
  uVar2 = puVar4[2];
  uVar3 = puVar4[3];
  *(undefined4 *)param_2 = *puVar4;
  *(undefined4 *)(param_2 + 4) = uVar1;
  *(undefined4 *)(param_2 + 8) = uVar2;
  *(undefined4 *)(param_2 + 0xc) = uVar3;
  iVar5 = QRect::center((QRect *)(param_1 + 0x130));
  iVar7 = (int)((double)(*(int *)(iVar5 + 4) + -7) - local_10 * *(double *)(param_1 + 0xc0));
  dVar8 = (double)**(ushort **)(param_2 + 0x14);
  libm_sse2_log_precise();
  dVar9 = DAT_00581070;
  libm_sse2_pow_precise();
  dVar10 = (double)(float)dVar9;
  libm_sse2_log_precise();
  iVar5 = QRect::left((QRect *)(param_1 + 0x130));
  dVar9 = DAT_00581060;
  libm_sse2_log_precise();
  iVar5 = (int)(((double)(float)dVar8 - dVar9) / (double)(float)dVar10) + iVar5 + -7;
  if (iVar5 <= *(int *)(param_2 + 0x1c)) {
    iVar5 = *(int *)(param_2 + 0x1c);
  }
  iVar6 = *(int *)(param_2 + 0x20);
  if (iVar5 < *(int *)(param_2 + 0x20)) {
    iVar6 = iVar5;
  }
  if (iVar7 <= *(int *)(param_2 + 0x24)) {
    iVar7 = *(int *)(param_2 + 0x24);
  }
  iVar5 = *(int *)(param_2 + 0x28);
  if (iVar7 < *(int *)(param_2 + 0x28)) {
    iVar5 = iVar7;
  }
  QRect::setRect(param_2,iVar6,iVar5,0xe,0xe);
  QString::~QString(&param_9);
  return;
}


