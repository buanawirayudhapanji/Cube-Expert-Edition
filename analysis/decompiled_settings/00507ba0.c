
undefined4 __thiscall
FUN_00507ba0(int param_1,undefined4 param_2,uint param_3,uint *param_4,undefined4 *param_5,
            undefined4 *param_6,undefined4 param_7)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iStack_8;
  
  iStack_8 = 0;
  iVar3 = param_3 + 0xf;
  cVar1 = func_0x00507fc0(param_1 + 0xc864,iVar3,&iStack_8,param_7);
  if (cVar1 != '\0') {
    if (*(char *)(param_1 + 0xc866) == '#') {
      if (iVar3 != iStack_8) {
        func_0x00486c20(&UNK_00593540,iVar3,iStack_8);
        return 0;
      }
      param_3 = (uint)*(uint3 *)(param_1 + 0xc867);
      cVar1 = FUN_00507970((byte *)(param_1 + 0xc86a),param_3,
                           *(undefined1 *)(param_3 + 0xc86a + param_1));
      if (cVar1 == '\0') {
        uVar2 = __0QMessageLogger__QAE_PBDH0_Z(0,0,0);
        _debug_QMessageLogger__QBAXPBDZZ(uVar2,&UNK_00593570);
        return 0;
      }
      *param_4 = (uint)*(byte *)(param_1 + 0xc86a);
      *param_5 = *(undefined4 *)(param_1 + 0xc86b);
      *param_6 = 0;
      *(undefined2 *)param_6 = *(undefined2 *)(param_1 + 0xc86f);
      *(undefined1 *)((int)param_6 + 2) = *(undefined1 *)(param_1 + 0xc871);
      func_0x0051a5a0(param_2,param_1 + 0xc872,*param_6);
      return 1;
    }
    uVar2 = __0QMessageLogger__QAE_PBDH0_Z(0,0,0);
    _debug_QMessageLogger__QBAXPBDZZ(uVar2,&UNK_00593620);
  }
  return 0;
}


