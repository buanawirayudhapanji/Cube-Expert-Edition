
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004a4070(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  double *pdVar7;
  int iVar8;
  float *pfVar9;
  int iVar10;
  int *unaff_FS_OFFSET;
  undefined4 uStack_1c;
  int *piStack_18;
  int iStack_14;
  int iStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &UNK_0052669d;
  iStack_10 = *unaff_FS_OFFSET;
  uVar4 = _DAT_00759b24 ^ (int)register0x00000010 - 4U;
  *unaff_FS_OFFSET = (int)&iStack_10;
  piVar1 = (int *)(param_1 + 0x80);
  if (*piVar1 == *(int *)(param_1 + 0x84)) {
    *unaff_FS_OFFSET = iStack_10;
    return 0;
  }
  *param_3 = 0x808;
  iStack_14 = param_1;
  uStack_1c = func_0x00519367(0x808,uVar4);
  func_0x004908a0(uStack_1c,param_2);
  piVar3 = piStack_18;
  uStack_8 = 0;
  *param_2 = uStack_1c;
  if (piStack_18 != (int *)param_2[1]) {
    if (piStack_18 != (int *)0x0) {
      LOCK();
      piStack_18[1] = piStack_18[1] + 1;
      UNLOCK();
    }
    piVar2 = (int *)param_2[1];
    if (piVar2 != (int *)0x0) {
      LOCK();
      iVar8 = piVar2[1] + -1;
      piVar2[1] = iVar8;
      UNLOCK();
      if (iVar8 == 0) {
        (**(code **)(*piVar2 + 4))();
        LOCK();
        iVar8 = piVar2[2] + -1;
        piVar2[2] = iVar8;
        UNLOCK();
        if (iVar8 == 0) {
          (**(code **)(*piVar2 + 8))();
        }
      }
    }
    param_2[1] = piVar3;
  }
  uStack_8 = 1;
  if (piVar3 != (int *)0x0) {
    LOCK();
    iVar8 = piVar3[1] + -1;
    piVar3[1] = iVar8;
    UNLOCK();
    if (iVar8 == 0) {
      (**(code **)(*piVar3 + 4))();
      LOCK();
      piVar2 = piVar3 + 2;
      iVar8 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar8 == 1) {
        (**(code **)(*piVar3 + 8))();
      }
    }
  }
  puVar5 = *(undefined8 **)(param_1 + 0x84);
  iVar8 = (int)puVar5 - *piVar1 >> 3;
  uStack_8 = 0xffffffff;
  if (iVar8 < 0x200) {
    iVar8 = 0x200 - iVar8;
    do {
      uStack_1c = 0;
      piStack_18 = (int *)0x0;
      if (puVar5 == *(undefined8 **)(param_1 + 0x88)) {
        func_0x00490930(puVar5,&uStack_1c);
        puVar5 = *(undefined8 **)(param_1 + 0x84);
      }
      else {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
        *(undefined8 **)(param_1 + 0x84) = puVar5;
      }
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  puVar6 = (undefined1 *)func_0x00519329(0x808);
  _uStack_1c = CONCAT44(puVar6,uStack_1c);
  func_0x0051a5b8(puVar6,0,0x808);
  *puVar6 = 0;
  iVar8 = _value_QAbstractSlider__QBEHXZ();
  iVar10 = 0x40;
  *(float *)(puVar6 + 4) = (float)iVar8 / _DAT_00584580;
  pdVar7 = (double *)(*piVar1 + 0x10);
  pfVar9 = (float *)(puVar6 + 0xc);
  do {
    pfVar9[-1] = (float)pdVar7[-2];
    *pfVar9 = (float)pdVar7[-1];
    pfVar9[1] = (float)*pdVar7;
    pfVar9[2] = (float)pdVar7[1];
    pfVar9[3] = (float)pdVar7[2];
    pfVar9[4] = (float)pdVar7[3];
    pfVar9[5] = (float)pdVar7[4];
    pfVar9[6] = (float)pdVar7[5];
    iVar10 = iVar10 + -1;
    pdVar7 = pdVar7 + 8;
    pfVar9 = pfVar9 + 8;
  } while (iVar10 != 0);
  func_0x0051a5a0(*param_2,puVar6,*param_3);
  func_0x00519359(puVar6,0x808);
  *unaff_FS_OFFSET = iStack_10;
  return 1;
}


