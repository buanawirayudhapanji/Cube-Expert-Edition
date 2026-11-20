
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004a4770(uint param_1)

{
  double *pdVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  undefined4 uStack_8;
  
  if (*(int *)(*(int *)(param_1 + 0x44) + 0xc844) != 3) {
    uStack_8 = param_1 & 0xffffff;
    cVar3 = FUN_00507ea0(0x764,(int)&uStack_8 + 3,1);
    if (cVar3 != '\0') {
      iVar4 = _value_QAbstractSlider__QBEHXZ();
      pfVar5 = (float *)(param_1 + 0x7f8);
      uStack_8 = CONCAT13(1,(undefined3)uStack_8);
      iVar6 = 0;
      *(float *)(param_1 + 0x7f4) = (float)iVar4 / _DAT_00584580;
      uVar2 = *(uint *)(param_1 + 0x80);
      if (((float *)(uVar2 + 0xff8) < pfVar5) || (param_1 + 0xff4 < uVar2)) {
        iVar6 = 0x20;
        do {
          pdVar1 = (double *)(iVar6 + -0x20 + uVar2);
          *(ulonglong *)pfVar5 = CONCAT44((float)pdVar1[1],(float)*pdVar1);
          pdVar1 = (double *)(iVar6 + -0x10 + uVar2);
          *(ulonglong *)(pfVar5 + 2) = CONCAT44((float)pdVar1[1],(float)*pdVar1);
          *(ulonglong *)(pfVar5 + 4) =
               CONCAT44((float)((double *)(iVar6 + uVar2))[1],(float)*(double *)(iVar6 + uVar2));
          pdVar1 = (double *)(iVar6 + 0x10 + uVar2);
          iVar6 = iVar6 + 0x40;
          *(ulonglong *)(pfVar5 + 6) = CONCAT44((float)pdVar1[1],(float)*pdVar1);
          pfVar5 = pfVar5 + 8;
        } while (iVar6 < 0x1020);
      }
      else {
        do {
          *pfVar5 = (float)*(double *)(uVar2 + iVar6 * 8);
          pfVar5[1] = (float)*(double *)(uVar2 + 8 + iVar6 * 8);
          pfVar5[2] = (float)*(double *)(uVar2 + 0x10 + iVar6 * 8);
          iVar4 = iVar6 * 8;
          iVar6 = iVar6 + 4;
          pfVar5[3] = (float)*(double *)(uVar2 + 0x18 + iVar4);
          pfVar5 = pfVar5 + 4;
        } while (iVar6 < 0x1fd);
        if (iVar6 < 0x200) {
          iVar6 = iVar6 * 8;
          do {
            pdVar1 = (double *)(iVar6 + uVar2);
            iVar6 = iVar6 + 8;
            *pfVar5 = (float)*pdVar1;
            pfVar5 = pfVar5 + 1;
          } while (iVar6 < 0x1000);
        }
      }
      cVar3 = FUN_00507ea0(0x768,param_1 + 0x7f4,0x804);
      if (cVar3 == '\0') {
        func_0x00486c20(&UNK_005844ec);
      }
      cVar3 = FUN_00507ea0(0x764,(int)&uStack_8 + 3,1);
      if (cVar3 != '\0') {
        return;
      }
    }
    func_0x00486c20(&UNK_005844dc);
  }
  return;
}


