
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_004f9af0(int param_1)

{
  QString QVar1;
  QTextEdit *this;
  undefined4 uVar2;
  byte bVar3;
  QString *pQVar4;
  int iVar5;
  QString local_6c [4];
  QString local_68 [4];
  undefined4 local_64;
  QString local_60 [4];
  int local_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined1 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00549a71;
  local_10 = ExceptionList;
  local_14 = DAT_00759b24 ^ (uint)(local_60 + 0x5c);
  ExceptionList = &local_10;
  local_64 = 0;
  *(undefined1 *)(param_1 + 0x9c) = 0;
  local_5c = param_1;
  QComboBox::setCurrentIndex(*(QComboBox **)(param_1 + 0x2d0),(uint)*(byte *)(param_1 + 0x28));
  QSpinBox::setValue(*(QSpinBox **)(param_1 + 0x2c0),(int)*(char *)(param_1 + 0x29));
  QSpinBox::setValue(*(QSpinBox **)(local_5c + 0x2cc),(int)*(char *)(local_5c + 0x2a));
  QSpinBox::setValue(*(QSpinBox **)(local_5c + 0x2d8),(uint)*(byte *)(local_5c + 0x2b));
  QSpinBox::setValue(*(QSpinBox **)(local_5c + 0x2dc),(uint)*(byte *)(local_5c + 0x2c));
  QComboBox::setCurrentIndex(*(QComboBox **)(local_5c + 0x3b0),(uint)*(byte *)(local_5c + 0x7b));
  QSpinBox::setValue(*(QSpinBox **)(local_5c + 0x3dc),(uint)*(byte *)(local_5c + 0x7d));
  QLabel::setText(*(QLabel **)(local_5c + 0x3e4),
                  (QString *)(&DAT_00764ad8 + (uint)*(byte *)(local_5c + 0x7d) * 4));
  QSpinBox::setValue(*(QSpinBox **)(local_5c + 0x3c8),(uint)*(byte *)(local_5c + 0x7e));
  QSpinBox::setValue(*(QSpinBox **)(local_5c + 0x398),(uint)*(byte *)(local_5c + 0x7f));
  QComboBox::setCurrentIndex(*(QComboBox **)(local_5c + 0x3d8),(uint)*(byte *)(local_5c + 0x79));
  QComboBox::setCurrentIndex(*(QComboBox **)(local_5c + 0x3e0),(uint)*(byte *)(local_5c + 0x80));
  QComboBox::setCurrentIndex(*(QComboBox **)(local_5c + 0x39c),(uint)*(byte *)(local_5c + 0x81));
  QSpinBox::setValue(*(QSpinBox **)(local_5c + 0x3ac),(uint)*(byte *)(local_5c + 0x82));
  QSpinBox::setValue(*(QSpinBox **)(local_5c + 0x3a8),(uint)*(byte *)(local_5c + 0x83));
  QSpinBox::setValue(*(QSpinBox **)(local_5c + 0x3bc),(uint)*(byte *)(local_5c + 0x84));
  QComboBox::setCurrentIndex(*(QComboBox **)(local_5c + 0x31c),(uint)*(byte *)(local_5c + 0x73));
  QComboBox::setCurrentIndex(*(QComboBox **)(local_5c + 0x2f4),(uint)*(byte *)(local_5c + 0x74));
  QComboBox::setCurrentIndex(*(QComboBox **)(local_5c + 0x314),(uint)*(byte *)(local_5c + 0x75));
  QSpinBox::setValue(*(QSpinBox **)(local_5c + 0x2fc),(uint)*(byte *)(local_5c + 0x76));
  QSpinBox::setValue(*(QSpinBox **)(local_5c + 0x300),(uint)*(byte *)(local_5c + 0x77));
  QSpinBox::setValue(*(QSpinBox **)(local_5c + 0x30c),(uint)*(byte *)(local_5c + 0x78));
  QComboBox::setCurrentIndex(*(QComboBox **)(local_5c + 0x420),(uint)*(byte *)(local_5c + 0x2d));
  QComboBox::setCurrentIndex(*(QComboBox **)(local_5c + 0x400),(uint)*(byte *)(local_5c + 0x2e));
  iVar5 = local_5c;
  QSpinBox::setValue(*(QSpinBox **)(local_5c + 0x418),(uint)*(byte *)(local_5c + 0x2f));
  QSpinBox::setValue(*(QSpinBox **)(iVar5 + 0x410),(uint)*(byte *)(iVar5 + 0x30));
  QSpinBox::setValue(*(QSpinBox **)(iVar5 + 0x40c),(uint)*(byte *)(iVar5 + 0x31));
  uVar2 = *(undefined4 *)(iVar5 + 0x32);
  uStack_54 = *(undefined4 *)(iVar5 + 0x36);
  uStack_50 = *(undefined4 *)(iVar5 + 0x3a);
  uStack_4c = *(undefined4 *)(iVar5 + 0x3e);
  this = *(QTextEdit **)(iVar5 + 0x438);
  local_18 = *(undefined1 *)(iVar5 + 0x72);
  local_48 = *(undefined4 *)(iVar5 + 0x42);
  uStack_44 = *(undefined4 *)(iVar5 + 0x46);
  uStack_40 = *(undefined4 *)(iVar5 + 0x4a);
  uStack_3c = *(undefined4 *)(iVar5 + 0x4e);
  local_38 = *(undefined4 *)(iVar5 + 0x52);
  uStack_34 = *(undefined4 *)(iVar5 + 0x56);
  uStack_30 = *(undefined4 *)(iVar5 + 0x5a);
  uStack_2c = *(undefined4 *)(iVar5 + 0x5e);
  local_28 = *(undefined4 *)(iVar5 + 0x62);
  uStack_24 = *(undefined4 *)(iVar5 + 0x66);
  uStack_20 = *(undefined4 *)(iVar5 + 0x6a);
  uStack_1c = *(undefined4 *)(iVar5 + 0x6e);
  local_8 = 0;
  local_58 = uVar2;
  QString::QString(local_60);
  local_64 = 1;
  bVar3 = (byte)uVar2;
  if ((bVar3 == 0) || (bVar3 < 0x40)) {
    bVar3 = -(bVar3 != 0) & bVar3;
  }
  else {
    bVar3 = 0x40;
  }
  iVar5 = 0;
  if (bVar3 != 0) {
    do {
      QVar1 = local_60[iVar5 + 9];
      if ((byte)QVar1 < 0x10) {
        pQVar4 = (QString *)QString::asprintf((char *)local_68,&DAT_0058955c,(uint)(byte)QVar1);
        local_8 = CONCAT31(local_8._1_3_,1);
        QString::append(local_60,pQVar4);
        pQVar4 = local_68;
      }
      else {
        pQVar4 = (QString *)QString::asprintf((char *)local_6c,&DAT_00589564,(uint)(byte)QVar1);
        local_8 = CONCAT31(local_8._1_3_,2);
        QString::append(local_60,pQVar4);
        pQVar4 = local_6c;
      }
      local_8 = local_8 & 0xffffff00;
      QString::~QString(pQVar4);
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)(uint)bVar3);
  }
  QTextEdit::setText(this,local_60);
  local_8 = 0xffffffff;
  QString::~QString(local_60);
  iVar5 = local_5c;
  FUN_004fa790();
  FUN_004fa9c0();
  *(undefined1 *)(iVar5 + 0x9c) = 1;
  ExceptionList = local_10;
  return;
}


