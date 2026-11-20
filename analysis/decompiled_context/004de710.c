
void __fastcall FUN_004de710(int param_1)

{
  FUN_004e0d10();
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x2c))(*(int *)(*(int *)(param_1 + 0x28) + 0xc844) == 3)
  ;
  FUN_004e01a0();
  if (*(int **)(param_1 + 0x50) == (int *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x004de746. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x50) + 200))();
  return;
}


