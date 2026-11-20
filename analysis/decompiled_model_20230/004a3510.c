
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __thiscall
FUN_004a3510(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int *unaff_FS_OFFSET;
  int iStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &UNK_0052ab05;
  iStack_10 = *unaff_FS_OFFSET;
  uVar1 = _DAT_00759b24 ^ (int)register0x00000010 - 4U;
  *unaff_FS_OFFSET = (int)&iStack_10;
  __0QDialog__QAE_PAVQWidget__V__QFlags_W4WindowType_Qt_____Z(param_3,param_4,uVar1);
  param_1[2] = &UNK_00580c04;
  *param_1 = &UNK_00584bd4;
  param_1[2] = &UNK_00584ca4;
  param_1[0x12] = _shared_null_QListData__2UData_1_B_exref;
  uStack_8 = 1;
  func_0x0050a570();
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  uStack_8._0_1_ = 4;
  func_0x0051a5b8(param_1 + 0x23,0,0xf70);
  FUN_004a4cc0(param_1);
  FUN_004a4910();
  _setWindowFlags_QWidget__QAEXV__QFlags_W4WindowType_Qt_____Z
            (*(uint *)(param_1[5] + 8) & 0xfffe7fff);
  _setWindowFlags_QWidget__QAEXV__QFlags_W4WindowType_Qt_____Z(*(uint *)(param_1[5] + 8) | 0x100);
  param_1[0x11] = param_2;
  FUN_004a42c0();
  _setAcceptDrops_QWidget__QAEX_N_Z(0);
  func_0x004894e0(1,100,1);
  _setValue_QAbstractSlider__QAEXH_Z(0x32);
  uVar2 = _asprintf_QString__SA_AV1_PBDZZ(&param_3,&UNK_005842a8,0x32);
  uStack_8 = CONCAT31(uStack_8._1_3_,5);
  _setToolTip_QWidget__QAEXABVQString___Z(uVar2);
  __1QString__QAE_XZ();
  *unaff_FS_OFFSET = iStack_10;
  return param_1;
}


