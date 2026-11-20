
void __fastcall FUN_0050ee30(QWidget *param_1)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  QWidget *pQVar6;
  int iVar7;
  float fVar8;
  int iVar9;
  uint uVar10;
  QWidget *pQVar11;
  QWidget *pQVar12;
  QTypedArrayData<unsigned_short> *pQVar13;
  QRect *pQVar14;
  double dVar15;
  double dVar16;
  QString aQStack_f6 [2];
  QRect local_ec [16];
  QString local_dc [32];
  undefined1 local_bc;
  int local_b8;
  int iStack_b4;
  int iStack_b0;
  int iStack_ac;
  int local_a8;
  int iStack_a4;
  int iStack_a0;
  int iStack_9c;
  int local_98;
  int iStack_94;
  int iStack_90;
  int iStack_8c;
  int local_88;
  int iStack_84;
  int iStack_80;
  QWidget *pQStack_7c;
  int local_78;
  int iStack_74;
  int iStack_70;
  int iStack_6c;
  int local_68;
  int iStack_64;
  int iStack_60;
  QWidget *pQStack_5c;
  QTypedArrayData<unsigned_short> *local_58;
  QTypedArrayData<unsigned_short> *local_54;
  int local_50;
  int iStack_4c;
  undefined8 uStack_48;
  QTypedArrayData<unsigned_short> *local_40;
  QTypedArrayData<unsigned_short> *local_3c;
  QWidget *local_38;
  int local_34;
  QRect *local_30;
  QWidget *local_2c;
  QWidget *local_28;
  QWidget *local_24;
  float local_20;
  uint local_1c;
  QWidget *local_18;
  QWidget *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005587f9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar7 = *(int *)(param_1 + 0x1c);
  *(int *)(param_1 + 0xa8) = iVar7;
  *(int *)(param_1 + 0xb0) = iVar7;
  local_20 = (float)(*(uint *)(param_1 + 200) / 10);
  *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0x2c) - iVar7;
  iVar9 = *(int *)(param_1 + 0x30) - iVar7;
  *(int *)(param_1 + 0xb4) = iVar9;
  *(int *)(param_1 + 0xb8) =
       ((iVar7 * -2 - *(int *)(param_1 + 0x28)) + iVar9) / (int)(*(uint *)(param_1 + 200) - 1);
  local_14 = param_1;
  QRect::setRect((QRect *)(param_1 + 0x120),*(int *)(param_1 + 0x1c),*(int *)(param_1 + 0x1c),
                 *(int *)(param_1 + 0x2c) - iVar7,iVar9);
  pQVar14 = (QRect *)(param_1 + 0x130);
  iVar7 = (*(int *)(param_1 + 0xac) - *(int *)(param_1 + 0x24)) + *(int *)(param_1 + 0x1c);
  *(int *)(param_1 + 0xcc) = iVar7;
  local_30 = pQVar14;
  QRect::setRect(pQVar14,*(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x20),
                 *(int *)(param_1 + 0xb0) + *(int *)(param_1 + 0x20),iVar7,
                 *(int *)(param_1 + 0xb8) * *(int *)(param_1 + 200));
  iVar7 = QRect::top(pQVar14);
  local_28 = (QWidget *)((*(int *)(param_1 + 200) / 2) * *(int *)(param_1 + 0xb8) + iVar7);
  iVar3 = QRect::right(pQVar14);
  iVar4 = QRect::top(pQVar14);
  iVar7 = *(int *)(local_14 + 200);
  iVar9 = *(int *)(local_14 + 0xb8);
  iVar5 = QRect::left(local_30);
  *(int *)(local_14 + 0xe4) = (iVar7 / 2) * iVar9 + iVar4;
  *(int *)(local_14 + 0xe0) = iVar5;
  *(QWidget **)(local_14 + 0xec) = local_28;
  *(int *)(local_14 + 0xe8) = iVar3;
  local_1c = 1;
  do {
    if (local_1c != 5) {
      iVar7 = QRect::top(local_30);
      local_28 = local_14 + 0x140;
      iVar7 = (*(int *)(local_14 + 200) / 10) * *(int *)(local_14 + 0xb8) * local_1c + iVar7;
      iVar9 = QRect::right(local_30);
      local_50 = QRect::left(local_30);
      pQVar11 = local_28;
      uStack_48 = (double)CONCAT44(iVar7,iVar9);
      piVar2 = *(int **)local_28;
      iStack_4c = iVar7;
      if (((*piVar2 != 1) && (*piVar2 != 0)) || ((piVar2[2] & 0x7fffffffU) < piVar2[1] + 1U)) {
        FUN_0050cdd0();
      }
      iVar7 = *(int *)pQVar11;
      piVar2 = (int *)(*(int *)(iVar7 + 4) * 0x10 + *(int *)(iVar7 + 0xc) + iVar7);
      *piVar2 = local_50;
      piVar2[1] = iStack_4c;
      piVar2[2] = (int)uStack_48;
      piVar2[3] = uStack_48._4_4_;
      piVar2 = (int *)(*(int *)pQVar11 + 4);
      *piVar2 = *piVar2 + 1;
    }
    pQVar14 = local_30;
    local_1c = local_1c + 1;
  } while ((int)local_1c < 10);
  local_1c = 0;
  local_24 = local_14 + 0x158;
  do {
    pQVar11 = local_14;
    iVar7 = QRect::top(pQVar14);
    iVar3 = (*(int *)(pQVar11 + 200) / 10) * *(int *)(local_14 + 0xb8) * local_1c;
    iVar9 = QRect::right(pQVar14);
    *(int *)local_24 = iVar9 + 0x15;
    local_1c = local_1c + 1;
    *(int *)(local_24 + 4) = iVar3 + iVar7 + 3;
    local_24 = local_24 + 8;
  } while ((int)local_1c < 10);
  local_24 = *(QWidget **)(local_14 + 200);
  local_2c = (QWidget *)0x1;
  if (1 < (int)local_24) {
    fVar8 = local_20;
    pQVar11 = local_14;
    do {
      if ((int)local_2c % (int)fVar8 != 0) {
        local_38 = pQVar11 + 0x148;
        iVar7 = QRect::top(pQVar14);
        local_28 = (QWidget *)(*(int *)(pQVar11 + 0xb8) * (int)local_2c + iVar7);
        iVar7 = QRect::right(pQVar14);
        iVar9 = QRect::top(local_30);
        iVar9 = *(int *)(pQVar11 + 0xb8) * (int)local_2c + iVar9;
        local_68 = QRect::left(local_30);
        pQVar11 = local_38;
        pQStack_5c = local_28;
        piVar2 = *(int **)local_38;
        iStack_64 = iVar9;
        iStack_60 = iVar7;
        if (((*piVar2 != 1) && (*piVar2 != 0)) || ((piVar2[2] & 0x7fffffffU) < piVar2[1] + 1U)) {
          FUN_0050cdd0();
        }
        iVar7 = *(int *)pQVar11;
        piVar2 = (int *)(*(int *)(iVar7 + 4) * 0x10 + *(int *)(iVar7 + 0xc) + iVar7);
        *piVar2 = local_68;
        piVar2[1] = iStack_64;
        piVar2[2] = iStack_60;
        piVar2[3] = (int)pQStack_5c;
        piVar2 = (int *)(*(int *)pQVar11 + 4);
        *piVar2 = *piVar2 + 1;
        fVar8 = local_20;
        pQVar11 = local_14;
        pQVar14 = local_30;
      }
      local_24 = *(QWidget **)(pQVar11 + 200);
      local_2c = (QWidget *)((int)local_2c + 1);
    } while ((int)local_2c < (int)local_24);
  }
  local_1c = 0;
  if (-1 < (int)local_24) {
    pQVar11 = local_24;
    do {
      local_24 = (QWidget *)0x6;
      if ((((int)local_1c % (int)local_20 == 0) || (local_1c == 0)) ||
         ((QWidget *)local_1c == pQVar11)) {
        local_24 = (QWidget *)0xf;
      }
      iVar7 = QRect::right(pQVar14);
      iStack_74 = QRect::top(pQVar14);
      iStack_74 = *(int *)(local_14 + 0xb8) * local_1c + iStack_74;
      iStack_70 = (int)local_24 + iVar7;
      pQVar11 = local_14 + 0x144;
      piVar2 = *(int **)pQVar11;
      local_78 = iVar7;
      iStack_6c = iStack_74;
      if (((*piVar2 != 1) && (*piVar2 != 0)) || ((piVar2[2] & 0x7fffffffU) < piVar2[1] + 1U)) {
        FUN_0050cdd0();
        pQVar14 = local_30;
      }
      iVar7 = *(int *)pQVar11;
      piVar2 = (int *)(*(int *)(iVar7 + 4) * 0x10 + *(int *)(iVar7 + 0xc) + iVar7);
      *piVar2 = local_78;
      piVar2[1] = iStack_74;
      piVar2[2] = iStack_70;
      piVar2[3] = iStack_6c;
      local_1c = local_1c + 1;
      *(int *)(*(int *)pQVar11 + 4) = *(int *)(*(int *)pQVar11 + 4) + 1;
      pQVar11 = *(QWidget **)(local_14 + 200);
    } while ((int)local_1c <= (int)pQVar11);
  }
  iVar7 = QRect::bottom(pQVar14);
  iVar9 = QRect::left(pQVar14);
  dVar15 = DAT_00581060;
  *(int *)(local_14 + 0x1d0) = iVar9;
  *(int *)(local_14 + 0x1d4) = iVar7 + 0x1e;
  local_1c = 0;
  libm_sse2_log_precise();
  local_24 = local_14 + 0x154;
  local_38 = local_14 + 0x34;
  local_2c = local_14 + 0x1d8;
  uStack_48 = dVar15;
  do {
    uVar1 = *(ushort *)local_38;
    dVar15 = DAT_00581070;
    libm_sse2_pow_precise();
    local_28 = (QWidget *)(float)dVar15;
    dVar15 = (double)uVar1;
    libm_sse2_log_precise();
    local_20 = (float)dVar15;
    dVar15 = (double)(float)local_28;
    libm_sse2_log_precise();
    uVar10 = (uint)(((double)local_20 - uStack_48) / (double)(float)dVar15);
    local_20 = (float)uVar10;
    if (((local_1c == 1) || (local_1c == 8)) || ((local_1c == 0x11 || (local_1c == 0x1a)))) {
      local_28 = local_14 + 0x14c;
      local_18 = (QWidget *)QRect::bottom(pQVar14);
      iVar7 = QRect::left(pQVar14);
      iVar9 = QRect::top(local_30);
      local_a8 = QRect::left(local_30);
      pQVar11 = local_28;
      local_a8 = local_a8 + (int)local_20;
      iStack_9c = (int)local_18;
      piVar2 = *(int **)local_28;
      iStack_a4 = iVar9;
      iStack_a0 = iVar7 + uVar10;
      if (((*piVar2 != 1) && (*piVar2 != 0)) || ((piVar2[2] & 0x7fffffffU) < piVar2[1] + 1U)) {
        FUN_0050cdd0();
      }
      pQVar14 = local_30;
      iVar7 = *(int *)pQVar11;
      piVar2 = (int *)(*(int *)(iVar7 + 4) * 0x10 + *(int *)(iVar7 + 0xc) + iVar7);
      *piVar2 = local_a8;
      piVar2[1] = iStack_a4;
      piVar2[2] = iStack_a0;
      piVar2[3] = iStack_9c;
      piVar2 = (int *)(*(int *)pQVar11 + 4);
      *piVar2 = *piVar2 + 1;
      iVar7 = QRect::bottom(local_30);
      local_18 = (QWidget *)(iVar7 + 0xf);
      iVar7 = QRect::left(pQVar14);
      iVar7 = (int)local_20 + iVar7;
      iVar9 = QRect::bottom(pQVar14);
      local_b8 = QRect::left(local_30);
      pQVar11 = local_24;
      local_b8 = local_b8 + (int)local_20;
      iStack_ac = (int)local_18;
      piVar2 = *(int **)local_24;
      iStack_b4 = iVar9;
      iStack_b0 = iVar7;
      if (((*piVar2 != 1) && (*piVar2 != 0)) || ((piVar2[2] & 0x7fffffffU) < piVar2[1] + 1U)) {
        FUN_0050cdd0();
      }
      iVar7 = local_b8;
      iVar9 = iStack_b4;
      iVar3 = iStack_b0;
      iVar4 = iStack_ac;
    }
    else {
      local_18 = local_14 + 0x150;
      local_28 = (QWidget *)QRect::bottom(pQVar14);
      iVar7 = QRect::left(pQVar14);
      iVar9 = QRect::top(local_30);
      local_88 = QRect::left(local_30);
      pQVar11 = local_18;
      local_88 = local_88 + (int)local_20;
      pQStack_7c = local_28;
      piVar2 = *(int **)local_18;
      iStack_84 = iVar9;
      iStack_80 = iVar7 + uVar10;
      if (((*piVar2 != 1) && (*piVar2 != 0)) || ((piVar2[2] & 0x7fffffffU) < piVar2[1] + 1U)) {
        FUN_0050cdd0();
      }
      pQVar14 = local_30;
      iVar7 = *(int *)pQVar11;
      piVar2 = (int *)(*(int *)(iVar7 + 4) * 0x10 + *(int *)(iVar7 + 0xc) + iVar7);
      *piVar2 = local_88;
      piVar2[1] = iStack_84;
      piVar2[2] = iStack_80;
      piVar2[3] = (int)pQStack_7c;
      piVar2 = (int *)(*(int *)pQVar11 + 4);
      *piVar2 = *piVar2 + 1;
      iVar7 = QRect::bottom(local_30);
      local_18 = (QWidget *)(iVar7 + 6);
      iVar7 = QRect::left(pQVar14);
      iVar7 = (int)local_20 + iVar7;
      iVar9 = QRect::bottom(pQVar14);
      local_98 = QRect::left(local_30);
      pQVar11 = local_24;
      local_98 = local_98 + (int)local_20;
      iStack_8c = (int)local_18;
      piVar2 = *(int **)local_24;
      iStack_94 = iVar9;
      iStack_90 = iVar7;
      if (((*piVar2 != 1) && (*piVar2 != 0)) || ((piVar2[2] & 0x7fffffffU) < piVar2[1] + 1U)) {
        if ((piVar2[2] & 0x7fffffffU) < piVar2[1] + 1U) {
          FUN_0050cdd0();
          iVar7 = local_98;
          iVar9 = iStack_94;
          iVar3 = iStack_90;
          iVar4 = iStack_8c;
          goto LAB_0050f656;
        }
        FUN_0050cdd0();
      }
      iVar7 = local_98;
      iVar9 = iStack_94;
      iVar3 = iStack_90;
      iVar4 = iStack_8c;
    }
LAB_0050f656:
    pQVar14 = local_30;
    iVar5 = *(int *)pQVar11;
    piVar2 = (int *)(*(int *)(iVar5 + 4) * 0x10 + *(int *)(iVar5 + 0xc) + iVar5);
    *piVar2 = iVar7;
    piVar2[1] = iVar9;
    piVar2[2] = iVar3;
    piVar2[3] = iVar4;
    *(int *)(*(int *)pQVar11 + 4) = *(int *)(*(int *)pQVar11 + 4) + 1;
    local_18 = (QWidget *)(local_1c + 1);
    if (((((int)local_18 % 3 == 0) || (local_1c == 1)) || (local_1c == 9)) ||
       ((local_1c == 0x12 || (local_1c == 0x1b)))) {
      iVar7 = QRect::bottom(local_30);
      iVar9 = QRect::left(pQVar14);
      *(int *)local_2c = iVar9 + (int)local_20;
      *(int *)(local_2c + 4) = iVar7 + 0x1e;
      local_2c = local_2c + 8;
    }
    local_38 = local_38 + 4;
    local_1c = (uint)local_18;
    if (0x1b < local_18) {
      local_18 = local_14 + 0x278;
      if (*(int *)(*(int *)(local_14 + 0x278) + 4) != 0) {
        local_38 = (QWidget *)FUN_0050d9b0();
        pQVar6 = (QWidget *)FUN_0050d930();
        pQVar11 = local_38;
        if (pQVar6 != local_38) {
          do {
            pQVar12 = pQVar6 + 0x34;
            QString::~QString((QString *)(pQVar6 + 0x10));
            pQVar6 = pQVar12;
          } while (pQVar12 != pQVar11);
          pQVar14 = local_30;
        }
        *(undefined4 *)(*(int *)local_18 + 4) = 0;
      }
      uVar1 = *(ushort *)(local_14 + 0x38);
      dVar15 = DAT_00581070;
      libm_sse2_pow_precise();
      local_18 = (QWidget *)(float)dVar15;
      dVar15 = (double)uVar1;
      libm_sse2_log_precise();
      local_28 = (QWidget *)(float)dVar15;
      dVar15 = DAT_00581060;
      libm_sse2_log_precise();
      dVar16 = (double)(float)local_18;
      uStack_48 = dVar15;
      libm_sse2_log_precise();
      local_18 = (QWidget *)(float)(((double)(float)local_28 - uStack_48) / (double)(float)dVar16);
      iVar7 = QRect::left(pQVar14);
      local_2c = (QWidget *)(iVar7 + (int)(float)local_18);
      uVar1 = *(ushort *)(local_14 + 0xa0);
      dVar15 = DAT_00581070;
      libm_sse2_pow_precise();
      local_18 = (QWidget *)(float)dVar15;
      dVar15 = (double)uVar1;
      libm_sse2_log_precise();
      local_28 = (QWidget *)(float)dVar15;
      dVar15 = DAT_00581060;
      libm_sse2_log_precise();
      dVar16 = (double)(float)local_18;
      uStack_48 = dVar15;
      libm_sse2_log_precise();
      local_18 = (QWidget *)(float)(((double)(float)local_28 - uStack_48) / (double)(float)dVar16);
      iVar7 = QRect::left(pQVar14);
      local_20 = (float)(iVar7 + (int)(float)local_18);
      iVar7 = QRect::top(pQVar14);
      pQVar11 = local_14;
      local_38 = (QWidget *)((*(int *)(local_14 + 200) / 2) * *(int *)(local_14 + 0xb8) + iVar7);
      iVar7 = QRect::top(pQVar14);
      local_1c = (*(int *)(pQVar11 + 200) / 10) * *(int *)(pQVar11 + 0xb8) + iVar7;
      iVar7 = QRect::top(pQVar14);
      pQVar11 = local_14;
      local_24 = (QWidget *)
                 (iVar7 + (*(int *)(local_14 + 200) / 10) * *(int *)(local_14 + 0xb8) * 9);
      *(double *)(local_14 + 0xc0) =
           (double)(int)((int)local_24 - local_1c) /
           (double)(*(int *)(local_14 + 0xd8) - *(int *)(local_14 + 0xd4));
      local_3c = QString::fromAscii_helper("HP",2);
      pQVar11[0x2b0] = (QWidget)0x0;
      QString::QString(aQStack_f6 + -10,(QString *)&local_3c);
      FUN_0050da60(pQVar11 + 0x280,pQVar11 + 0x11e,0,local_2c,local_20,local_38);
      QString::~QString((QString *)&local_3c);
      QString::fromAscii_helper("LS",2);
      FUN_0050da60(local_14 + 0x2b4,local_14 + 0x118,local_14 + 0x110,local_2c,local_20,local_1c);
      local_28 = local_14 + 0x27c;
      FUN_0050d810();
      FUN_0050d810();
      pQVar11 = local_14;
      if (0 < *(int *)(local_14 + 0x18)) {
        local_18 = (QWidget *)CONCAT31(local_18._1_3_,0x20);
        pQVar13 = (QTypedArrayData<unsigned_short> *)0x0;
        do {
          memset(local_ec,0,0x34);
          QRect::QRect(local_ec);
          QString::QString(local_dc);
          local_bc = 1;
          local_8 = 0;
          local_54 = QString::fromAscii_helper("%1",2);
          local_40 = pQVar13 + *(int *)(pQVar11 + 0x10c);
          local_8._0_1_ = 1;
          iVar7 = *(int *)(pQVar11 + 0x114);
          local_3c = pQVar13 + 1;
          QChar::QChar((QChar *)(aQStack_f6 + -0xe),local_18);
          QString::arg((QString *)&local_54,aQStack_f6 + -10,local_3c,0,10);
          pQVar11 = local_14;
          FUN_0050da60(local_ec,iVar7 + (int)pQVar13 * 2,local_40,local_2c,local_20,local_1c);
          local_8 = (uint)local_8._1_3_ << 8;
          QString::~QString((QString *)&local_54);
          FUN_0050d810();
          FUN_0050d810();
          local_8 = 0xffffffff;
          QString::~QString(local_dc);
          pQVar13 = local_3c;
        } while ((int)local_3c < *(int *)(pQVar11 + 0x18));
      }
      QString::fromAscii_helper("HS",2);
      FUN_0050da60(pQVar11 + 0x31c,pQVar11 + 0x11a,pQVar11 + 0x111,local_2c,local_20,local_1c);
      local_58 = QString::fromAscii_helper("LP",2);
      pQVar11[0x318] = (QWidget)0x0;
      QString::QString(aQStack_f6 + -10,(QString *)&local_58);
      FUN_0050da60(pQVar11 + 0x2e8,local_14 + 0x11c,0,local_2c,local_20,local_38);
      QString::~QString((QString *)&local_58);
      FUN_0050d810();
      FUN_0050d810();
      pQVar14 = local_30;
      iVar7 = QRect::width(local_30);
      pQVar11 = local_14;
      *(int *)(local_14 + 0xcc) = iVar7;
      QVector<QPoint>::clear((QVector<QPoint> *)(local_14 + 0xdc));
      local_24 = (QWidget *)0x0;
      if (0 < *(int *)(pQVar11 + 0xcc)) {
        do {
          local_34 = QRect::left(pQVar14);
          local_34 = local_34 + (int)local_24;
          local_30 = (QRect *)0x32;
          QVector<QPoint>::append((QVector<QPoint> *)(pQVar11 + 0xdc),(QPoint *)&local_34);
          local_24 = (QWidget *)((int)local_24 + 1);
        } while ((int)local_24 < *(int *)(pQVar11 + 0xcc));
      }
      FUN_0050e8d0();
      QWidget::update(pQVar11);
      pQVar11[0xa4] = (QWidget)0x1;
      ExceptionList = local_10;
      return;
    }
  } while( true );
}


