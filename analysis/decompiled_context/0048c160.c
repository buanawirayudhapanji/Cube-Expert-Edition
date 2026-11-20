
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048c160(undefined4 param_1,undefined4 *param_2,int param_3,int *param_4,int param_5)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  byte bVar6;
  MMRESULT MVar7;
  int iVar8;
  int iVar9;
  
  piVar1 = param_4;
  iVar9 = param_3;
  if (((param_2 != (undefined4 *)0x3c3) && (param_2 != (undefined4 *)0x3c4)) &&
     (param_2 != (undefined4 *)0x3c6)) {
    return;
  }
  puVar3 = *(undefined4 **)(param_3 + 0x34);
  if (*(char *)(param_3 + 0x32) == '\x01') {
    *(undefined8 *)(puVar3 + 8) = 0;
    *(undefined1 *)(param_3 + 0x32) = 0;
  }
  else {
    *(double *)(puVar3 + 8) =
         ((double)(param_5 - puVar3[2]) + (double)(&DAT_005810c0)[-(param_5 - puVar3[2] >> 0x1f)]) *
         _DAT_00582068;
  }
  puVar3[2] = param_5;
  if (param_2 == (undefined4 *)0x3c3) {
    bVar6 = (byte)param_4;
    if (-1 < (char)bVar6) {
      return;
    }
    if (bVar6 < 0xc0) {
      iVar8 = 3;
    }
    else if (bVar6 < 0xe0) {
      iVar8 = 2;
    }
    else if (bVar6 < 0xf0) {
      iVar8 = 3;
    }
    else if (bVar6 == 0xf1) {
      if ((*(byte *)(param_3 + 0x30) & 2) != 0) {
        return;
      }
      iVar8 = 2;
    }
    else if (bVar6 == 0xf2) {
      iVar8 = 3;
    }
    else if (bVar6 == 0xf3) {
      iVar8 = 2;
    }
    else {
      if ((bVar6 == 0xf8) && ((*(byte *)(param_3 + 0x30) & 2) != 0)) {
        return;
      }
      iVar8 = 1;
      if ((bVar6 == 0xfe) && ((*(byte *)(param_3 + 0x30) & 4) != 0)) {
        return;
      }
    }
    param_2 = &param_4;
    do {
      puVar4 = (undefined1 *)puVar3[5];
      if (puVar4 == (undefined1 *)puVar3[6]) {
        puVar5 = param_2;
        param_2 = (undefined4 *)((int)param_2 + 1);
        FUN_004899f0(puVar4,puVar5);
      }
      else {
        *puVar4 = *(undefined1 *)param_2;
        puVar3[5] = puVar3[5] + 1;
        param_2 = (undefined4 *)((int)param_2 + 1);
      }
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  else {
    if ((((*(byte *)(param_3 + 0x30) & 1) == 0) && (param_2 != (undefined4 *)0x3c6)) &&
       (iVar9 = 0, 0 < param_4[2])) {
      do {
        puVar4 = (undefined1 *)puVar3[5];
        param_2 = (undefined4 *)CONCAT13(*(undefined1 *)(iVar9 + *piVar1),param_2._0_3_);
        if (puVar4 == (undefined1 *)puVar3[6]) {
          FUN_004899f0(puVar4,(int)&param_2 + 3);
        }
        else {
          *puVar4 = *(undefined1 *)(iVar9 + *piVar1);
          puVar3[5] = puVar3[5] + 1;
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < piVar1[2]);
    }
    if (*(int *)(puVar3[piVar1[3] + 10] + 8) == 0) {
      return;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(puVar3 + 0xb));
    MVar7 = midiInAddBuffer((HMIDIIN)*puVar3,(LPMIDIHDR)puVar3[param_4[3] + 10],0x40);
    LeaveCriticalSection((LPCRITICAL_SECTION)(puVar3 + 0xb));
    if (MVar7 != 0) {
      FUN_004896f0(cerr_exref,
                   "\nRtMidiIn::midiInputCallback: error sending sysex to Midi device!!\n\n");
    }
    iVar9 = param_3;
    if ((*(byte *)(param_3 + 0x30) & 1) != 0) {
      return;
    }
  }
  piVar1 = puVar3 + 4;
  if (*(char *)(iVar9 + 0x38) == '\0') {
    if (*(uint *)(iVar9 + 8) < *(uint *)(iVar9 + 0xc)) {
      piVar2 = (int *)(*(int *)(iVar9 + 0x10) + *(int *)(iVar9 + 4) * 0x18);
      *(int *)(iVar9 + 4) = *(int *)(iVar9 + 4) + 1;
      if (piVar2 != piVar1) {
        FUN_004898d0();
      }
      *(undefined8 *)(piVar2 + 4) = *(undefined8 *)(puVar3 + 8);
      if (*(int *)(iVar9 + 4) == *(int *)(iVar9 + 0xc)) {
        *(undefined4 *)(iVar9 + 4) = 0;
      }
      *(int *)(iVar9 + 8) = *(int *)(iVar9 + 8) + 1;
    }
    else {
      FUN_004896f0(cerr_exref,"\nRtMidiIn: message queue limit reached!!\n\n");
    }
  }
  else {
    (**(code **)(iVar9 + 0x3c))(*(undefined8 *)(puVar3 + 8),piVar1,*(undefined4 *)(iVar9 + 0x40));
  }
  if (*piVar1 != puVar3[5]) {
    puVar3[5] = *piVar1;
  }
  return;
}


