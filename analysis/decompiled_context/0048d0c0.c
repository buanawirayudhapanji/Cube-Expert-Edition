
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_0048d0c0(int param_1,char *param_2,uint param_3)

{
  int iVar1;
  MMRESULT MVar2;
  undefined4 uVar3;
  char *pcVar4;
  DWORD local_4c;
  midihdr_tag local_48;
  DWORD local_8;
  
  local_8 = DAT_00759b24 ^ (uint)&(&local_48)[1].dwBufferLength;
  if (*(char *)(param_1 + 8) == '\0') {
    return;
  }
  if (param_3 == 0) {
    FUN_004866d0("MidiOutWinMM::sendMessage: message argument is empty!",0x35);
    FUN_00489eb0(param_1 + 0xc);
    uVar3 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 4);
    if (*param_2 == -0x10) {
      local_48.dwBufferLength = param_3;
      local_48.lpData = param_2;
      local_48.dwFlags = 0;
      MVar2 = midiOutPrepareHeader(*(HMIDIOUT *)(iVar1 + 4),&local_48,0x40);
      if (MVar2 == 0) {
        MVar2 = midiOutLongMsg(*(HMIDIOUT *)(iVar1 + 4),&local_48,0x40);
        if (MVar2 == 0) {
          MVar2 = midiOutUnprepareHeader(*(HMIDIOUT *)(iVar1 + 4),&local_48,0x40);
          if (MVar2 != 0x41) {
            return;
          }
          do {
            Sleep(1);
            MVar2 = midiOutUnprepareHeader(*(HMIDIOUT *)(iVar1 + 4),&local_48,0x40);
          } while (MVar2 == 0x41);
          return;
        }
        uVar3 = 0x37;
        pcVar4 = "MidiOutWinMM::sendMessage: error sending sysex message.";
      }
      else {
        uVar3 = 0x38;
        pcVar4 = "MidiOutWinMM::sendMessage: error preparing sysex header.";
      }
    }
    else {
      if (3 < param_3) {
        FUN_004866d0("MidiOutWinMM::sendMessage: message size is greater than 3 bytes (and not sysex)!"
                     ,0x50);
        FUN_00489eb0(param_1 + 0xc);
        uVar3 = 0;
        goto LAB_0048d20f;
      }
      if (param_3 != 0) {
        memcpy(&local_4c,param_2,param_3);
      }
      MVar2 = midiOutShortMsg(*(HMIDIOUT *)(iVar1 + 4),local_4c);
      if (MVar2 == 0) {
        return;
      }
      uVar3 = 0x36;
      pcVar4 = "MidiOutWinMM::sendMessage: error sending MIDI message.";
    }
    FUN_004866d0(pcVar4,uVar3);
    FUN_00489eb0(param_1 + 0xc);
    uVar3 = 8;
  }
LAB_0048d20f:
  FUN_0048b850(uVar3);
  return;
}


