
void __thiscall FUN_0049f520(int param_1,undefined1 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if (*(int *)(param_1 + 0x1c0) != 0) {
    iVar1 = _sender_QObject__IBEPAV1_XZ();
    piVar3 = (int *)(param_1 + 0x148);
    iVar2 = 10;
    do {
      if (iVar1 == piVar3[10]) {
        *(undefined1 *)*piVar3 = param_2;
        FUN_00506590(5,(*piVar3 - param_1) + 0x7ffffe3c,*piVar3,1,param_1);
      }
      piVar3 = piVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}


