
undefined4 __thiscall FUN_0050b180(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iStack_8;
  
  iStack_8 = param_1;
  _write_QIODevice__QAE_JPBD_J_Z(&UNK_00593828,4,0);
  iStack_8 = 0;
  _write_QIODevice__QAE_JPBD_J_Z(&iStack_8,4,0);
  _write_QIODevice__QAE_JPBD_J_Z(&UNK_00593830,8,0);
  iStack_8 = 0x12;
  _write_QIODevice__QAE_JPBD_J_Z(&iStack_8,4,0);
  _write_QIODevice__QAE_JPBD_J_Z(param_1 + 0x14,0x12,0);
  _write_QIODevice__QAE_JPBD_J_Z(&UNK_0059383c,4,0);
  iStack_8 = func_0x0050b710();
  iStack_8 = (uint)*(ushort *)(param_1 + 0x20) * iStack_8;
  _write_QIODevice__QAE_JPBD_J_Z(&iStack_8,4,0);
  iVar1 = iStack_8;
  uVar2 = func_0x0050b700();
  _write_QIODevice__QAE_JPBD_J_Z(uVar2,iVar1,0);
  (**(code **)(*param_2 + 0x40))(4,0);
  iStack_8 = (**(code **)(*param_2 + 0x3c))();
  iStack_8 = iStack_8 + -4;
  _write_QIODevice__QAE_JPBD_J_Z(&iStack_8,4,0);
  return 1;
}


