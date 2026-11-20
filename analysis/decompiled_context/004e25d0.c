
QDialog * __thiscall FUN_004e25d0(QDialog *param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined8 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  char *pcVar6;
  QDialog *pQVar7;
  int local_24;
  int iStack_20;
  QDialog *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00540ec4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  QDialog::QDialog(param_1,param_3,param_4,DAT_00759b24 ^ (int)register0x00000010 - 4U);
  *(undefined ***)(param_1 + 8) = BaseDialog::vftable;
  *(undefined ***)param_1 = CCubeMagicMidiEditDlg::vftable;
  *(undefined ***)(param_1 + 8) = CCubeMagicMidiEditDlg::vftable;
  *(code **)(param_1 + 0x1bc) = shared_null_exref;
  *(undefined4 *)(param_1 + 0x1c0) = 0;
  local_8 = 1;
  param_1[0xbf7] = (QDialog)0x0;
  FUN_004e84a0(param_1);
  QWidget::setWindowFlags((QWidget *)param_1,*(uint *)(*(int *)(param_1 + 0x14) + 8) & 0xfffe7fff);
  QWidget::setWindowFlags((QWidget *)param_1,*(uint *)(*(int *)(param_1 + 0x14) + 8) | 0x100);
  *(int *)(param_1 + 0x1b4) = param_2;
  FUN_004e3220();
  FUN_004e3b10();
  cVar4 = FUN_005069b0();
  if (cVar4 != '\0') {
    uVar3 = *(undefined4 *)(*(int *)(param_1 + 0x1b4) + 0x2ca6c);
    iVar5 = FUN_00488eb0(*(undefined4 *)(*(int *)(param_1 + 0x1b4) + 0x2ca68));
    if (iVar5 != 0) {
      puVar2 = *(undefined4 **)(iVar5 + 0x48);
      QByteArray::QByteArray((QByteArray *)&param_3);
      local_8 = CONCAT31(local_8._1_3_,2);
      QByteArray::resize((QByteArray *)&param_3,0x97b);
      pcVar6 = QByteArray::data((QByteArray *)&param_3);
      cVar4 = FUN_005063f0(*puVar2,uVar3,pcVar6,*(undefined4 *)(param_3 + 4),0);
      if (cVar4 != '\0') {
        uVar1 = *(undefined8 *)pcVar6;
        local_24 = (int)uVar1;
        if (local_24 == 0x4d444346) {
          iVar5 = FUN_00486d80(pcVar6 + 0xc,0x96f);
          iStack_20 = (int)((ulonglong)uVar1 >> 0x20);
          if (iVar5 == iStack_20) {
            param_2 = 0;
            pcVar6 = pcVar6 + 0xc;
            pQVar7 = param_1 + 0x288;
            for (iVar5 = 0x25b; iVar5 != 0; iVar5 = iVar5 + -1) {
              *(undefined4 *)pQVar7 = *(undefined4 *)pcVar6;
              pcVar6 = pcVar6 + 4;
              pQVar7 = pQVar7 + 4;
            }
            *(undefined2 *)pQVar7 = *(undefined2 *)pcVar6;
            pQVar7[2] = *(QDialog *)(pcVar6 + 2);
            local_14 = param_1 + 0x3c8;
            pQVar7 = param_1 + 0x1c4;
            do {
              QComboBox::setCurrentIndex(*(QComboBox **)(pQVar7 + 0x1c),(uint)(byte)*local_14);
              QListWidget::setCurrentRow(*(QListWidget **)pQVar7,0);
              FUN_004e3fa0(param_2);
              FUN_004f16c0();
              pQVar7 = pQVar7 + 4;
              param_2 = param_2 + 1;
              local_14 = local_14 + 0x159;
            } while (param_2 < 7);
            QComboBox::setCurrentIndex(*(QComboBox **)(param_1 + 0x15c),(uint)(byte)param_1[0xa86]);
            QComboBox::setCurrentIndex(*(QComboBox **)(param_1 + 0x164),(uint)(byte)param_1[0xa87]);
            QComboBox::setCurrentIndex(*(QComboBox **)(param_1 + 0x1a4),(uint)(byte)param_1[0xbdf]);
            QComboBox::setCurrentIndex(*(QComboBox **)(param_1 + 0x1ac),(uint)(byte)param_1[0xbe0]);
          }
        }
      }
      QByteArray::~QByteArray((QByteArray *)&param_3);
    }
  }
  ExceptionList = local_10;
  return param_1;
}


