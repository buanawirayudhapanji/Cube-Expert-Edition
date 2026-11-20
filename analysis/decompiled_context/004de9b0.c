
void __thiscall
FUN_004de9b0(QTypedArrayData<unsigned_short> *param_1,QTypedArrayData<unsigned_short> *param_2)

{
  QString *pQVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  QTypedArrayData<unsigned_short> *pQVar5;
  QTypedArrayData<unsigned_short> *pQVar6;
  char *pcVar7;
  char *pcVar8;
  QString aQStack_42 [6];
  QString local_30 [4];
  QString local_2c [4];
  QString local_28 [4];
  QTypedArrayData<unsigned_short> *local_24;
  QTypedArrayData<unsigned_short> *local_20;
  QTypedArrayData<unsigned_short> *local_1c;
  QTypedArrayData<unsigned_short> *local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0053f239;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = (QTypedArrayData<unsigned_short> *)0x0;
  local_24 = param_1;
  QWidget::hide(*(QWidget **)(param_1 + 0x20));
  pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
  local_8 = 0;
  local_18 = QString::fromAscii_helper("Firmware Update",0xf);
  iVar2 = QString::compare(pQVar1,(QString *)&local_18,1);
  QString::~QString((QString *)&local_18);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_20);
  if (iVar2 == 0) {
    param_2 = operator_new(0x128);
    local_8 = 1;
    uVar3 = FUN_00501e10();
    local_8 = 0xffffffff;
    *(undefined4 *)(param_1 + 0x50) = uVar3;
    goto LAB_004df92a;
  }
  pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
  local_8 = 2;
  local_18 = QString::fromAscii_helper("MIDI Bank Edit",0xe);
  iVar2 = QString::compare(pQVar1,(QString *)&local_18,1);
  QString::~QString((QString *)&local_18);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_20);
  if (iVar2 == 0) {
    param_2 = operator_new(0xbf8);
    local_8 = 3;
    uVar3 = FUN_004e25d0();
    local_8 = 0xffffffff;
    *(undefined4 *)(param_1 + 0x50) = uVar3;
    goto LAB_004df92a;
  }
  pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
  local_8 = 4;
  local_18 = QString::fromAscii_helper("Cube Baby",9);
  iVar2 = QString::compare(pQVar1,(QString *)&local_18,1);
  QString::~QString((QString *)&local_18);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_20);
  if (iVar2 == 0) {
    param_2 = operator_new(0xffc);
    local_8 = 5;
    uVar3 = FUN_004a3510();
    local_8 = 0xffffffff;
    *(undefined4 *)(param_1 + 0x50) = uVar3;
    goto LAB_004df92a;
  }
  pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
  local_8 = 6;
  local_18 = QString::fromAscii_helper("H8",2);
  iVar2 = QString::compare(pQVar1,(QString *)&local_18,1);
  QString::~QString((QString *)&local_18);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_20);
  if (iVar2 == 0) {
    param_2 = operator_new(0xffc);
    local_8 = 7;
    uVar3 = FUN_004ced80(*(undefined4 *)(param_1 + 0x28));
    local_8 = 0xffffffff;
    *(undefined4 *)(param_1 + 0x50) = uVar3;
    goto LAB_004df92a;
  }
  pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
  local_8 = 8;
  local_18 = (QTypedArrayData<unsigned_short> *)0x1;
  local_20 = QString::fromAscii_helper("Cube Baby*",10);
  local_8 = 9;
  uVar4 = 3;
  local_18 = (QTypedArrayData<unsigned_short> *)0x3;
  iVar2 = QString::compare(pQVar1,(QString *)&local_20,1);
  if (iVar2 == 0) {
LAB_004dec9d:
    local_11 = '\x01';
  }
  else {
    pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
    local_8 = 10;
    local_18 = (QTypedArrayData<unsigned_short> *)&DAT_00000007;
    local_1c = QString::fromAscii_helper("PANDORA mini FX",0xf);
    uVar4 = 0xf;
    iVar2 = QString::compare(pQVar1,(QString *)&local_1c,1);
    local_11 = '\0';
    if (iVar2 == 0) goto LAB_004dec9d;
  }
  if ((uVar4 & 8) != 0) {
    uVar4 = uVar4 & 0xfffffff7;
    QString::~QString((QString *)&local_1c);
  }
  if ((uVar4 & 4) != 0) {
    uVar4 = uVar4 & 0xfffffffb;
    QString::~QString(local_28);
  }
  if ((uVar4 & 2) != 0) {
    uVar4 = uVar4 & 0xfffffffd;
    QString::~QString((QString *)&local_20);
  }
  local_8 = 0xffffffff;
  if ((uVar4 & 1) != 0) {
    uVar4 = uVar4 & 0xfffffffe;
    QString::~QString(local_2c);
  }
  if (local_11 != '\0') {
    param_2 = operator_new(0x1170);
    local_8 = 0xb;
    uVar3 = FUN_0049dee0(*(undefined4 *)(param_1 + 0x28),0,0);
    local_8 = 0xffffffff;
    *(undefined4 *)(param_1 + 0x50) = uVar3;
    goto LAB_004df92a;
  }
  pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
  local_18 = (QTypedArrayData<unsigned_short> *)(uVar4 | 0x10);
  local_8 = 0xc;
  local_1c = QString::fromAscii_helper("H8*",3);
  local_8 = 0xd;
  pQVar5 = (QTypedArrayData<unsigned_short> *)(uVar4 | 0x30);
  local_18 = pQVar5;
  iVar2 = QString::compare(pQVar1,(QString *)&local_1c,1);
  if (iVar2 == 0) {
LAB_004dedbf:
    local_11 = '\x01';
  }
  else {
    pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
    local_18 = (QTypedArrayData<unsigned_short> *)(uVar4 | 0x70);
    local_8 = 0xe;
    local_20 = QString::fromAscii_helper("Pony Mustang",0xc);
    pQVar5 = (QTypedArrayData<unsigned_short> *)(uVar4 | 0xf0);
    iVar2 = QString::compare(pQVar1,(QString *)&local_20,1);
    local_11 = '\0';
    if (iVar2 == 0) goto LAB_004dedbf;
  }
  if ((char)pQVar5 < '\0') {
    pQVar5 = (QTypedArrayData<unsigned_short> *)((uint)pQVar5 & 0xffffff7f);
    QString::~QString((QString *)&local_20);
  }
  if (((uint)pQVar5 & 0x40) != 0) {
    pQVar5 = (QTypedArrayData<unsigned_short> *)((uint)pQVar5 & 0xffffffbf);
    QString::~QString(local_2c);
  }
  if (((uint)pQVar5 & 0x20) != 0) {
    pQVar5 = (QTypedArrayData<unsigned_short> *)((uint)pQVar5 & 0xffffffdf);
    QString::~QString((QString *)&local_1c);
  }
  local_8 = 0xffffffff;
  if (((uint)pQVar5 & 0x10) != 0) {
    pQVar5 = (QTypedArrayData<unsigned_short> *)((uint)pQVar5 & 0xffffffef);
    QString::~QString(local_28);
  }
  if (local_11 != '\0') {
    param_2 = operator_new(0x1164);
    local_8 = 0xf;
    uVar3 = FUN_004ca910(*(undefined4 *)(param_1 + 0x28),0,0);
    local_8 = 0xffffffff;
    *(undefined4 *)(param_1 + 0x50) = uVar3;
    goto LAB_004df92a;
  }
  pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
  local_8 = 0x10;
  local_20 = QString::fromAscii_helper("Foot Ctrl",9);
  iVar2 = QString::compare(pQVar1,(QString *)&local_20,1);
  QString::~QString((QString *)&local_20);
  local_8 = 0xffffffff;
  QString::~QString(local_2c);
  if (iVar2 == 0) {
    param_2 = operator_new(0x1304);
    local_8 = 0x11;
    uVar3 = FUN_004bded0(*(undefined4 *)(param_1 + 0x28),0,0);
    local_8 = 0xffffffff;
    *(undefined4 *)(param_1 + 0x50) = uVar3;
    goto LAB_004df92a;
  }
  pcVar7 = (char *)local_28;
  pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
  local_18 = (QTypedArrayData<unsigned_short> *)((uint)pQVar5 | 0x100);
  local_8 = 0x12;
  local_1c = QString::fromAscii_helper("FootCtrlPlus",0xc);
  local_8 = 0x13;
  pQVar6 = (QTypedArrayData<unsigned_short> *)((uint)pQVar5 | 0x300);
  local_18 = pQVar6;
  iVar2 = QString::compare(pQVar1,(QString *)&local_1c,1);
  if (iVar2 == 0) {
LAB_004def74:
    local_11 = '\x01';
  }
  else {
    pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
    local_18 = (QTypedArrayData<unsigned_short> *)((uint)pQVar5 | 0x700);
    local_8 = 0x14;
    local_20 = QString::fromAscii_helper("GAM-10",6);
    pQVar6 = (QTypedArrayData<unsigned_short> *)((uint)pQVar5 | 0xf00);
    iVar2 = QString::compare(pQVar1,(QString *)&local_20,1);
    local_11 = '\0';
    if (iVar2 == 0) goto LAB_004def74;
  }
  if (((uint)pQVar6 & 0x800) != 0) {
    pQVar6 = (QTypedArrayData<unsigned_short> *)((uint)pQVar6 & 0xfffff7ff);
    QString::~QString((QString *)&local_20);
  }
  if (((uint)pQVar6 & 0x400) != 0) {
    pQVar6 = (QTypedArrayData<unsigned_short> *)((uint)pQVar6 & 0xfffffbff);
    QString::~QString(local_2c);
  }
  if (((uint)pQVar6 & 0x200) != 0) {
    pQVar6 = (QTypedArrayData<unsigned_short> *)((uint)pQVar6 & 0xfffffdff);
    QString::~QString((QString *)&local_1c);
  }
  local_8 = 0xffffffff;
  if (((uint)pQVar6 & 0x100) != 0) {
    pQVar6 = (QTypedArrayData<unsigned_short> *)((uint)pQVar6 & 0xfffffeff);
    QString::~QString(local_28);
  }
  if (local_11 == '\0') {
    pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
    local_8 = 0x16;
    local_20 = QString::fromAscii_helper("AIRMINI",7);
    iVar2 = QString::compare(pQVar1,(QString *)&local_20,1);
    QString::~QString((QString *)&local_20);
    local_8 = 0xffffffff;
    QString::~QString(local_2c);
    if (iVar2 != 0) {
      pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
      local_8 = 0x18;
      local_24 = QString::fromAscii_helper("Drum",4);
      iVar2 = QString::compare(pQVar1,(QString *)&local_24,1);
      QString::~QString((QString *)&local_24);
      local_8 = 0xffffffff;
      QString::~QString(local_2c);
      if (iVar2 == 0) {
        param_2 = operator_new(0x4a0);
        local_8 = 0x19;
        uVar3 = FUN_004dadc0(*(undefined4 *)(param_1 + 0x28));
        local_8 = 0xffffffff;
        *(undefined4 *)(param_1 + 0x50) = uVar3;
        goto LAB_004df92a;
      }
      pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
      local_8 = 0x1a;
      local_24 = QString::fromAscii_helper("Edit Drum",9);
      iVar2 = QString::compare(pQVar1,(QString *)&local_24,1);
      QString::~QString((QString *)&local_24);
      local_8 = 0xffffffff;
      QString::~QString(local_2c);
      if (iVar2 == 0) {
        param_2 = operator_new(0x4bc);
        local_8 = 0x1b;
        uVar3 = FUN_004d9410(*(undefined4 *)(param_1 + 0x28),0);
        local_8 = 0xffffffff;
        *(undefined4 *)(param_1 + 0x50) = uVar3;
        goto LAB_004df92a;
      }
      pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
      local_18 = (QTypedArrayData<unsigned_short> *)((uint)pQVar6 | 0x1000);
      local_8 = 0x1c;
      local_20 = QString::fromAscii_helper("IR Box",6);
      local_8 = 0x1d;
      pQVar5 = (QTypedArrayData<unsigned_short> *)((uint)pQVar6 | 0x3000);
      local_18 = pQVar5;
      iVar2 = QString::compare(pQVar1,(QString *)&local_20,1);
      if (iVar2 == 0) {
LAB_004df25f:
        local_11 = '\x01';
      }
      else {
        pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
        local_18 = (QTypedArrayData<unsigned_short> *)((uint)pQVar6 | 0x7000);
        local_8 = 0x1e;
        local_24 = QString::fromAscii_helper("IMPULSE-R",9);
        pQVar5 = (QTypedArrayData<unsigned_short> *)((uint)pQVar6 | 0xf000);
        iVar2 = QString::compare(pQVar1,(QString *)&local_24,1);
        local_11 = '\0';
        if (iVar2 == 0) goto LAB_004df25f;
      }
      if (((uint)pQVar5 & 0x8000) != 0) {
        pQVar5 = (QTypedArrayData<unsigned_short> *)((uint)pQVar5 & 0xffff7fff);
        QString::~QString((QString *)&local_24);
      }
      if (((uint)pQVar5 & 0x4000) != 0) {
        pQVar5 = (QTypedArrayData<unsigned_short> *)((uint)pQVar5 & 0xffffbfff);
        QString::~QString(local_2c);
      }
      if (((uint)pQVar5 & 0x2000) != 0) {
        pQVar5 = (QTypedArrayData<unsigned_short> *)((uint)pQVar5 & 0xffffdfff);
        QString::~QString((QString *)&local_20);
      }
      local_8 = 0xffffffff;
      if (((uint)pQVar5 & 0x1000) != 0) {
        pQVar5 = (QTypedArrayData<unsigned_short> *)((uint)pQVar5 & 0xffffefff);
        QString::~QString(local_28);
      }
      if (local_11 != '\0') {
        param_2 = operator_new(0x2184);
        local_8 = 0x1f;
        uVar3 = FUN_004d1130(*(undefined4 *)(param_1 + 0x28),0,0);
        local_8 = 0xffffffff;
        *(undefined4 *)(param_1 + 0x50) = uVar3;
        goto LAB_004df92a;
      }
      pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
      local_8 = 0x20;
      local_24 = QString::fromAscii_helper("Cube Baby AC",0xc);
      iVar2 = QString::compare(pQVar1,(QString *)&local_24,1);
      QString::~QString((QString *)&local_24);
      local_8 = 0xffffffff;
      QString::~QString(local_2c);
      if (iVar2 == 0) {
        param_2 = operator_new(0xb80);
        local_8 = 0x21;
        uVar3 = FUN_00498590(*(undefined4 *)(param_1 + 0x28),0,0);
        local_8 = 0xffffffff;
        *(undefined4 *)(param_1 + 0x50) = uVar3;
        goto LAB_004df92a;
      }
      pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
      local_8 = 0x22;
      local_24 = QString::fromAscii_helper("Midi Keyboard",0xd);
      iVar2 = QString::compare(pQVar1,(QString *)&local_24,1);
      QString::~QString((QString *)&local_24);
      local_8 = 0xffffffff;
      QString::~QString(local_2c);
      if (iVar2 != 0) {
        pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
        local_8 = 0x23;
        local_24 = QString::fromAscii_helper("Smk25 Mini",10);
        iVar2 = QString::compare(pQVar1,(QString *)&local_24,1);
        QString::~QString((QString *)&local_24);
        local_8 = 0xffffffff;
        QString::~QString(local_2c);
        if (iVar2 != 0) {
          pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
          local_8 = 0x24;
          local_24 = QString::fromAscii_helper("Speaker",7);
          iVar2 = QString::compare(pQVar1,(QString *)&local_24,1);
          QString::~QString((QString *)&local_24);
          local_8 = 0xffffffff;
          QString::~QString(local_2c);
          if (iVar2 == 0) {
            param_2 = operator_new(0x11b0);
            local_8 = 0x25;
            uVar3 = FUN_004fad20(*(undefined4 *)(param_1 + 0x28),0,0);
            local_8 = 0xffffffff;
            *(undefined4 *)(param_1 + 0x50) = uVar3;
            goto LAB_004df92a;
          }
          pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
          local_8 = 0x26;
          local_24 = QString::fromAscii_helper("Cube Baby Bass",0xe);
          iVar2 = QString::compare(pQVar1,(QString *)&local_24,1);
          QString::~QString((QString *)&local_24);
          local_8 = 0xffffffff;
          QString::~QString(local_2c);
          if (iVar2 == 0) {
            param_2 = operator_new(0xbb0);
            local_8 = 0x27;
            uVar3 = FUN_00490a90(*(undefined4 *)(param_1 + 0x28),0,0);
            local_8 = 0xffffffff;
            *(undefined4 *)(param_1 + 0x50) = uVar3;
            goto LAB_004df92a;
          }
          pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
          local_8 = 0x28;
          local_24 = QString::fromAscii_helper("Looper Edit",0xb);
          iVar2 = QString::compare(pQVar1,(QString *)&local_24,1);
          QString::~QString((QString *)&local_24);
          local_8 = 0xffffffff;
          QString::~QString(local_2c);
          if (iVar2 == 0) {
            param_2 = operator_new(0x4b0);
            local_8 = 0x29;
            uVar3 = FUN_00483770(*(undefined4 *)(param_1 + 0x28),0,0);
            local_8 = 0xffffffff;
            *(undefined4 *)(param_1 + 0x50) = uVar3;
            goto LAB_004df92a;
          }
          pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
          local_8 = 0x2a;
          local_24 = QString::fromAscii_helper("IR Edit",7);
          iVar2 = QString::compare(pQVar1,(QString *)&local_24,1);
          QString::~QString((QString *)&local_24);
          local_8 = 0xffffffff;
          QString::~QString(local_2c);
          if (iVar2 == 0) {
            param_2 = operator_new(0x898);
            local_8 = 0x2b;
            uVar3 = FUN_004a5b00(*(undefined4 *)(param_1 + 0x28),0,0);
            local_8 = 0xffffffff;
            *(undefined4 *)(param_1 + 0x50) = uVar3;
            goto LAB_004df92a;
          }
          pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
          local_8 = 0x2c;
          local_24 = QString::fromAscii_helper("IR CAB",6);
          iVar2 = QString::compare(pQVar1,(QString *)&local_24,1);
          QString::~QString((QString *)&local_24);
          local_8 = 0xffffffff;
          QString::~QString(local_2c);
          if (iVar2 == 0) {
            param_2 = operator_new(0x4098);
            local_8 = 0x2d;
            uVar3 = FUN_00496770(*(undefined4 *)(param_1 + 0x28),0,0);
            local_8 = 0xffffffff;
            *(undefined4 *)(param_1 + 0x50) = uVar3;
            goto LAB_004df92a;
          }
          pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
          local_18 = (QTypedArrayData<unsigned_short> *)((uint)pQVar5 | 0x10000);
          local_8 = 0x2e;
          local_20 = QString::fromAscii_helper("DIG-AMP",7);
          local_8 = 0x2f;
          pQVar6 = (QTypedArrayData<unsigned_short> *)((uint)pQVar5 | 0x30000);
          local_18 = pQVar6;
          iVar2 = QString::compare(pQVar1,(QString *)&local_20,1);
          if (iVar2 == 0) {
LAB_004df786:
            local_11 = '\x01';
          }
          else {
            pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
            local_18 = (QTypedArrayData<unsigned_short> *)((uint)pQVar5 | 0x70000);
            local_8 = 0x30;
            local_24 = QString::fromAscii_helper("DIG-EFX",7);
            pQVar6 = (QTypedArrayData<unsigned_short> *)0xf0000;
            iVar2 = QString::compare(pQVar1,(QString *)&local_24,1);
            local_11 = '\0';
            if (iVar2 == 0) goto LAB_004df786;
          }
          if (((uint)pQVar6 & 0x80000) != 0) {
            pQVar6 = (QTypedArrayData<unsigned_short> *)((uint)pQVar6 & 0xfff7ffff);
            QString::~QString((QString *)&local_24);
          }
          if (((uint)pQVar6 & 0x40000) != 0) {
            pQVar6 = (QTypedArrayData<unsigned_short> *)((uint)pQVar6 & 0xfffbffff);
            QString::~QString(local_2c);
          }
          if (((uint)pQVar6 & 0x20000) != 0) {
            pQVar6 = (QTypedArrayData<unsigned_short> *)((uint)pQVar6 & 0xfffdffff);
            QString::~QString((QString *)&local_20);
          }
          local_8 = 0xffffffff;
          if (((uint)pQVar6 & 0x10000) != 0) {
            QString::~QString(local_28);
          }
          if (local_11 != '\0') {
            param_2 = operator_new(0xf068);
            local_8 = 0x31;
            uVar3 = FUN_004a8600(*(undefined4 *)(param_1 + 0x28),0,0);
            local_8 = 0xffffffff;
            *(undefined4 *)(param_1 + 0x50) = uVar3;
            goto LAB_004df92a;
          }
          pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
          local_8 = 0x32;
          local_24 = QString::fromAscii_helper("Smk25 II",8);
          iVar2 = QString::compare(pQVar1,(QString *)&local_24,1);
          QString::~QString((QString *)&local_24);
          local_8 = 0xffffffff;
          QString::~QString(local_2c);
          if (iVar2 != 0) {
            pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
            local_8 = 0x33;
            local_24 = QString::fromAscii_helper("Smc Mixer",9);
            iVar2 = QString::compare(pQVar1,(QString *)&local_24,1);
            QString::~QString((QString *)&local_24);
            local_8 = 0xffffffff;
            QString::~QString(local_2c);
            if (iVar2 != 0) {
              pQVar1 = (QString *)QListWidgetItem::text((QListWidgetItem *)param_2);
              local_8 = 0x34;
              param_2 = QString::fromAscii_helper("Write the firmware",0x12);
              QString::compare(pQVar1,(QString *)&param_2,1);
              QString::~QString((QString *)&param_2);
              local_8 = 0xffffffff;
              QString::~QString(local_30);
              goto LAB_004df92a;
            }
          }
        }
      }
      FUN_00486c20("This software no longer supports this device, please use MidiSuite");
      goto LAB_004df92a;
    }
    param_2 = operator_new(0x68d8);
    pQVar1 = local_30 + -0x28;
    local_8 = 0x17;
    pcVar8 = (char *)0x7;
    pcVar7 = "AIRMINI";
  }
  else {
    param_2 = operator_new(0x68d8);
    pQVar1 = local_30 + -0x24;
    local_8 = 0x15;
    pcVar8 = "FootCtrlPlus";
  }
  uVar3 = *(undefined4 *)(param_1 + 0x28);
  pQVar5 = QString::fromAscii_helper(pcVar7,(int)pcVar8);
  *(QTypedArrayData<unsigned_short> **)pQVar1 = pQVar5;
  uVar3 = FUN_004aa040(uVar3);
  local_8 = 0xffffffff;
  *(undefined4 *)(local_24 + 0x50) = uVar3;
  param_1 = local_24;
LAB_004df92a:
  if (*(QWidget **)(param_1 + 0x50) != (QWidget *)0x0) {
    QWidget::setAttribute(*(QWidget **)(param_1 + 0x50),0x37,true);
    (**(code **)(**(int **)(param_1 + 0x50) + 0xb8))();
    QAbstractItemView::clearSelection(*(QAbstractItemView **)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  ExceptionList = local_10;
  return;
}


