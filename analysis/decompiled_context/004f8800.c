
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_004f8800(int param_1,int param_2)

{
  undefined4 uVar1;
  QTextEdit *this;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  QString *pQVar20;
  undefined1 (*pauVar21) [16];
  undefined3 uStack_6b;
  undefined1 uStack_68;
  undefined3 uStack_67;
  undefined1 uStack_64;
  undefined3 uStack_63;
  undefined1 local_60;
  undefined3 uStack_5f;
  undefined1 uStack_5c;
  undefined3 uStack_5b;
  undefined1 uStack_58;
  undefined3 uStack_57;
  undefined1 uStack_54;
  undefined3 uStack_53;
  undefined1 local_50;
  undefined3 uStack_4f;
  undefined1 uStack_4c;
  undefined3 uStack_4b;
  undefined1 uStack_48;
  undefined3 uStack_47;
  undefined1 uStack_44;
  undefined3 uStack_43;
  undefined1 local_40;
  undefined3 uStack_3f;
  undefined1 uStack_3c;
  undefined3 uStack_3b;
  undefined1 uStack_38;
  undefined3 uStack_37;
  undefined1 uStack_34;
  undefined3 uStack_33;
  undefined1 local_30;
  undefined3 uStack_2f;
  undefined1 local_2c;
  undefined1 uStack_2b;
  QString local_18 [4];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00548e2e;
  local_10 = ExceptionList;
  local_14 = DAT_00759b24 ^ (uint)(local_18 + 0x14);
  ExceptionList = &local_10;
  *(int *)(param_1 + 0x8548) = param_2;
  *(undefined1 *)(param_1 + 0x854d) = 0;
  pauVar21 = (undefined1 (*) [16])
             ((uint)*(byte *)(param_1 + 0x8536) * 0xc1a + param_1 + param_2 * 0x46 + 0x8d8);
  uVar5 = *(undefined4 *)pauVar21[1];
  uVar6 = *(undefined4 *)(pauVar21[1] + 4);
  uVar7 = *(undefined4 *)(pauVar21[1] + 8);
  uVar8 = *(undefined4 *)(pauVar21[1] + 0xc);
  uVar1 = *(undefined4 *)pauVar21[4];
  uVar2 = *(uint *)(*pauVar21 + 4);
  uVar3 = *(undefined4 *)(*pauVar21 + 8);
  uVar4 = *(undefined4 *)(*pauVar21 + 0xc);
  auVar19 = *pauVar21;
  auVar18 = *pauVar21;
  auVar17 = *pauVar21;
  local_2c = (undefined1)*(undefined2 *)(pauVar21[4] + 4);
  uStack_2b = (undefined1)((ushort)*(undefined2 *)(pauVar21[4] + 4) >> 8);
  uVar9 = *(undefined4 *)pauVar21[2];
  uVar10 = *(undefined4 *)(pauVar21[2] + 4);
  uVar11 = *(undefined4 *)(pauVar21[2] + 8);
  uVar12 = *(undefined4 *)(pauVar21[2] + 0xc);
  uVar13 = *(undefined4 *)pauVar21[3];
  uVar14 = *(undefined4 *)(pauVar21[3] + 4);
  uVar15 = *(undefined4 *)(pauVar21[3] + 8);
  uVar16 = *(undefined4 *)(pauVar21[3] + 0xc);
  QComboBox::setCurrentIndex(*(QComboBox **)(param_1 + 0x8a40),*(uint *)*pauVar21 & 0xff);
  QComboBox::setCurrentIndex(*(QComboBox **)(param_1 + 0x8a48),auVar17._1_4_ & 0xff);
  QSpinBox::setValue(*(QSpinBox **)(param_1 + 0x8a64),auVar18._2_4_ & 0xff);
  QSpinBox::setValue(*(QSpinBox **)(param_1 + 0x8a60),auVar19._3_4_ & 0xff);
  QSpinBox::setValue(*(QSpinBox **)(param_1 + 0x8a50),uVar2 & 0xff);
  uStack_6b = (undefined3)(uVar2 >> 8);
  uStack_68 = (undefined1)uVar3;
  uStack_67 = (undefined3)((uint)uVar3 >> 8);
  uStack_64 = (undefined1)uVar4;
  uStack_63 = (undefined3)((uint)uVar4 >> 8);
  local_60 = (undefined1)uVar5;
  uStack_5f = (undefined3)((uint)uVar5 >> 8);
  uStack_5c = (undefined1)uVar6;
  this = *(QTextEdit **)(param_1 + 0x8a6c);
  uStack_5b = (undefined3)((uint)uVar6 >> 8);
  uStack_58 = (undefined1)uVar7;
  uStack_57 = (undefined3)((uint)uVar7 >> 8);
  uStack_54 = (undefined1)uVar8;
  uStack_53 = (undefined3)((uint)uVar8 >> 8);
  local_50 = (undefined1)uVar9;
  uStack_4f = (undefined3)((uint)uVar9 >> 8);
  uStack_4c = (undefined1)uVar10;
  uStack_4b = (undefined3)((uint)uVar10 >> 8);
  uStack_48 = (undefined1)uVar11;
  uStack_47 = (undefined3)((uint)uVar11 >> 8);
  uStack_44 = (undefined1)uVar12;
  uStack_43 = (undefined3)((uint)uVar12 >> 8);
  local_40 = (undefined1)uVar13;
  uStack_3f = (undefined3)((uint)uVar13 >> 8);
  uStack_3c = (undefined1)uVar14;
  uStack_3b = (undefined3)((uint)uVar14 >> 8);
  uStack_38 = (undefined1)uVar15;
  uStack_37 = (undefined3)((uint)uVar15 >> 8);
  uStack_34 = (undefined1)uVar16;
  uStack_33 = (undefined3)((uint)uVar16 >> 8);
  local_30 = (undefined1)uVar1;
  uStack_2f = (undefined3)((uint)uVar1 >> 8);
  pQVar20 = (QString *)
            FUN_004f85f0(local_18,CONCAT13(uStack_68,uStack_6b),CONCAT13(uStack_64,uStack_67),
                         CONCAT13(local_60,uStack_63),CONCAT13(uStack_5c,uStack_5f),
                         CONCAT13(uStack_58,uStack_5b),CONCAT13(uStack_54,uStack_57),
                         CONCAT13(local_50,uStack_53),CONCAT13(uStack_4c,uStack_4f),
                         CONCAT13(uStack_48,uStack_4b),CONCAT13(uStack_44,uStack_47),
                         CONCAT13(local_40,uStack_43),CONCAT13(uStack_3c,uStack_3f),
                         CONCAT13(uStack_38,uStack_3b),CONCAT13(uStack_34,uStack_37),
                         CONCAT13(local_30,uStack_33),CONCAT13(local_2c,uStack_2f),uStack_2b);
  local_8 = 0;
  QTextEdit::setText(this,pQVar20);
  local_8 = 0xffffffff;
  QString::~QString(local_18);
  FUN_004f8010();
  *(undefined1 *)(param_1 + 0x854d) = 1;
  ExceptionList = local_10;
  return;
}


