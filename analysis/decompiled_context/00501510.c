
QString * __thiscall FUN_00501510(int *param_1,QString *param_2,QString *param_3)

{
  QString *this;
  int iVar1;
  QString *pQVar2;
  int iVar3;
  uint uVar4;
  void *pvVar5;
  QString *pQVar6;
  uint uVar7;
  uint uVar8;
  QString *pQVar9;
  QString *pQVar10;
  
  iVar1 = *param_1;
  iVar3 = param_1[1] - iVar1 >> 2;
  if (iVar3 == 0x3fffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_0048b600();
  }
  uVar4 = iVar3 + 1;
  uVar8 = param_1[2] - iVar1 >> 2;
  if (0x3fffffff - (uVar8 >> 1) < uVar8) {
LAB_005016b5:
                    /* WARNING: Subroutine does not return */
    FUN_004847e0();
  }
  uVar8 = (uVar8 >> 1) + uVar8;
  uVar7 = uVar4;
  if (uVar4 <= uVar8) {
    uVar7 = uVar8;
  }
  if (0x3fffffff < uVar7) goto LAB_005016b5;
  uVar7 = uVar7 * 4;
  if (uVar7 < 0x1000) {
    if (uVar7 == 0) {
      pQVar6 = (QString *)0x0;
    }
    else {
      pQVar6 = operator_new(uVar7);
    }
  }
  else {
    if (uVar7 + 0x23 <= uVar7) goto LAB_005016b5;
    pvVar5 = operator_new(uVar7 + 0x23);
    if (pvVar5 == (void *)0x0) goto LAB_005016af;
    pQVar6 = (QString *)((int)pvVar5 + 0x23U & 0xffffffe0);
    *(void **)(pQVar6 + -4) = pvVar5;
  }
  this = pQVar6 + ((int)param_2 - iVar1 >> 2) * 4;
  QString::QString(this,param_3);
  pQVar10 = (QString *)param_1[1];
  pQVar9 = (QString *)*param_1;
  pQVar2 = pQVar6;
  if (param_2 == pQVar10) {
    for (; pQVar9 != pQVar10; pQVar9 = pQVar9 + 4) {
      QString::QString(pQVar2,pQVar9);
      pQVar2 = pQVar2 + 4;
    }
  }
  else {
    for (; pQVar9 != param_2; pQVar9 = pQVar9 + 4) {
      QString::QString(pQVar2,pQVar9);
      pQVar2 = pQVar2 + 4;
    }
    pQVar10 = (QString *)param_1[1];
    if (param_2 != pQVar10) {
      iVar1 = 4 - (int)param_2;
      do {
        QString::QString(param_2 + (int)(this + iVar1),param_2);
        param_2 = param_2 + 4;
      } while (param_2 != pQVar10);
    }
  }
  pQVar10 = (QString *)*param_1;
  if (pQVar10 != (QString *)0x0) {
    pQVar9 = (QString *)param_1[1];
    for (; pQVar10 != pQVar9; pQVar10 = pQVar10 + 4) {
      QString::~QString(pQVar10);
    }
    iVar1 = *param_1;
    uVar8 = param_1[2] - iVar1 & 0xfffffffc;
    iVar3 = iVar1;
    if (0xfff < uVar8) {
      iVar3 = *(int *)(iVar1 + -4);
      uVar8 = uVar8 + 0x23;
      if (0x1f < (iVar1 - iVar3) - 4U) {
LAB_005016af:
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
    FUN_00519359(iVar3,uVar8);
  }
  *param_1 = (int)pQVar6;
  param_1[1] = (int)(pQVar6 + uVar4 * 4);
  param_1[2] = (int)(pQVar6 + uVar7);
  return this;
}


