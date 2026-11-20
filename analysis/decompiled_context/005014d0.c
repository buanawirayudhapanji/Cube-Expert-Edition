
void __thiscall FUN_005014d0(int param_1,QString *param_2)

{
  *(undefined4 *)(param_1 + 4) = 0;
  if (*(int *)(param_1 + 0x8c) != *(int *)(param_1 + 0x90)) {
    *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x8c);
  }
  QString::operator=((QString *)(param_1 + 8),param_2);
  FUN_00500ed0(param_2);
  return;
}


