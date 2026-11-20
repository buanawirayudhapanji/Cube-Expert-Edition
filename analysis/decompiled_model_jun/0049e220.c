
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0049e220(int param_1,uint param_2)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int *unaff_FS_OFFSET;
  int iStack_14;
  int iStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &UNK_0052652e;
  iStack_10 = *unaff_FS_OFFSET;
  uVar2 = _DAT_00759b24 ^ (int)register0x00000010 - 4U;
  *unaff_FS_OFFSET = (int)&iStack_10;
  iStack_14 = param_1;
  _sender_QObject__IBEPAV1_XZ(uVar2);
  uVar3 = _asprintf_QString__SA_AV1_PBDZZ(&iStack_14,&UNK_005842a8,param_2);
  uStack_8 = 0;
  _setToolTip_QWidget__QAEXABVQString___Z(uVar3);
  uStack_8 = 0xffffffff;
  __1QString__QAE_XZ();
  if (((*(int *)(param_1 + 0x13c) - *(int *)(param_1 + 0x138) & 0xfffffff8U) != 0) &&
     (*(int *)(*(int *)(param_1 + 0xf8) + 0xc844) != 3)) {
    param_2 = param_2 & 0xffffff;
    cVar1 = FUN_00507ea0(0x764,(int)&param_2 + 3,1);
    if (cVar1 != '\0') {
      iVar4 = _value_QAbstractSlider__QBEHXZ();
      param_2 = CONCAT13(1,(undefined3)param_2);
      *(float *)(param_1 + 0x968) = (float)iVar4 / _DAT_00584580;
      cVar1 = FUN_00507ea0(0x768,(float *)(param_1 + 0x968),4);
      if (cVar1 == '\0') {
        func_0x00486c20(&UNK_005844ec);
      }
      cVar1 = FUN_00507ea0(0x764,(int)&param_2 + 3,1);
      if (cVar1 != '\0') goto LAB_0049e337;
    }
    func_0x00486c20(&UNK_005844dc);
  }
LAB_0049e337:
  *unaff_FS_OFFSET = iStack_10;
  return;
}


