
void __thiscall FUN_0048d230(int param_1,int param_2,undefined4 param_3)

{
  if (*(char *)(param_1 + 0x68) != '\0') {
    FUN_004866d0("MidiInApi::setCallback: a callback function is already set!",0x3b);
    FUN_00489eb0(param_1 + 0xc);
    FUN_0048b850(0);
    return;
  }
  if (param_2 == 0) {
    FUN_004866d0("RtMidiIn::setCallback: callback function value is invalid!",0x3a);
    FUN_00489eb0(param_1 + 0xc);
    FUN_0048b850(0);
    return;
  }
  *(int *)(param_1 + 0x6c) = param_2;
  *(undefined4 *)(param_1 + 0x70) = param_3;
  *(undefined1 *)(param_1 + 0x68) = 1;
  return;
}


