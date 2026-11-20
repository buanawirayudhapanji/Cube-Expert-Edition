
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __thiscall
FUN_0049dee0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  char *pcVar2;
  undefined4 uVar3;
  int *unaff_FS_OFFSET;
  int iStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &UNK_0052952e;
  iStack_10 = *unaff_FS_OFFSET;
  uVar1 = _DAT_00759b24 ^ (int)register0x00000010 - 4U;
  *unaff_FS_OFFSET = (int)&iStack_10;
  __0QDialog__QAE_PAVQWidget__V__QFlags_W4WindowType_Qt_____Z(param_3,param_4,uVar1);
  param_1[2] = &UNK_00580c04;
  *param_1 = &UNK_00584a88;
  param_1[2] = &UNK_00584b58;
  param_1[0x3f] = _shared_null_QListData__2UData_1_B_exref;
  uStack_8 = 1;
  *(undefined1 *)(param_1 + 0x40) = 1;
  func_0x0050a570();
  param_1[0x4b] = 0;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x50] = 0;
  uStack_8._0_1_ = 4;
  param_1[0x70] = 1;
  func_0x0051a5b8(param_1 + 0x80,0,0xf70);
  func_0x004a0400(param_1);
  func_0x0049aa10();
  _setWindowFlags_QWidget__QAEXV__QFlags_W4WindowType_Qt_____Z
            (*(uint *)(param_1[5] + 8) & 0xfffe7fff);
  _setWindowFlags_QWidget__QAEXV__QFlags_W4WindowType_Qt_____Z(*(uint *)(param_1[5] + 8) | 0x100);
  param_1[0x3e] = param_2;
  (**(code **)(*(int *)param_1[0x3d] + 0x2c))(0);
  FUN_0049f590();
  func_0x0049eea0();
  FUN_0049efd0();
  __0QColor__QAE_HHHH_Z(0x33,0xea,0xb8,0xff);
  func_0x0050cd30();
  pcVar2 = (char *)func_0x00519367(1);
  func_0x005063f0(0,0x3000,pcVar2,1,param_1);
  func_0x0050cd50(*pcVar2 != '\0');
  _setAcceptDrops_QWidget__QAEX_N_Z(0);
  func_0x004894e0(1,100,1);
  _setValue_QAbstractSlider__QAEXH_Z(0x32);
  uVar3 = _asprintf_QString__SA_AV1_PBDZZ(&param_3,&UNK_005842a8,0x32);
  uStack_8 = CONCAT31(uStack_8._1_3_,5);
  _setToolTip_QWidget__QAEXABVQString___Z(uVar3);
  __1QString__QAE_XZ();
  *unaff_FS_OFFSET = iStack_10;
  return param_1;
}


