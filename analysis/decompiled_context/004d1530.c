
void __thiscall FUN_004d1530(int *param_1,uint param_2,QString param_3,int param_4)

{
  int iVar1;
  QString QVar2;
  int iVar3;
  char cVar4;
  undefined1 *puVar5;
  code *pcVar6;
  undefined1 uStack0000000b;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  uVar9 = param_2;
  pcVar6 = blockSignals_exref;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00539c2e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  QObject::blockSignals(*(QObject **)(*param_1 + 0x1e0),true);
  iVar3 = param_4;
  QObject::blockSignals(*(QObject **)(*param_1 + 0x240 + param_4 * 4),true);
  if (iVar3 - 1U < 7) {
    QObject::blockSignals(*(QObject **)(*param_1 + 0x260 + iVar3 * 4),true);
  }
  QVar2 = param_3;
  iVar8 = *param_1;
  uVar9 = uVar9 & 0xffff;
  if (iVar3 == 0) {
    *(undefined2 *)(iVar8 + 0x1ece) = (undefined2)param_2;
    QSpinBox::setValue(*(QSpinBox **)(*param_1 + 0x240),uVar9);
    cVar4 = FUN_00506590(5,0x1c26,*param_1 + 0x1ece,2,*param_1);
    if (cVar4 == '\0') {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7250,(char *)&param_3,"Write data failed !",0);
      local_8 = iVar3;
      FUN_00486bb0();
      local_8 = 0xffffffff;
      QString::~QString(&param_3);
    }
    uStack0000000b = 2;
    puVar5 = &uStack0000000b;
LAB_004d185f:
    FUN_00506590(5,0xa0000000,puVar5,1,0);
  }
  else {
    if (iVar3 == 1) {
      *(undefined2 *)(iVar8 + 0x1ec8) = (undefined2)param_2;
      *(QString *)(*param_1 + 0x1ebb) = param_3;
      QSpinBox::setValue(*(QSpinBox **)(*param_1 + 0x244),uVar9);
      QDoubleSpinBox::setValue
                (*(QDoubleSpinBox **)(*param_1 + 0x264),(double)(int)(char)QVar2 / DAT_00581060);
      FUN_004d5590(0x1c20,*param_1 + 0x1ec8,2,*param_1);
      uStack0000000b = 2;
      FUN_00506590(5,0xa0000000,&uStack0000000b,1,0);
      iVar1 = *param_1;
      iVar8 = iVar1 + 0x1ebb;
      uVar7 = 0x1c13;
    }
    else {
      if (iVar3 != 7) {
        if (iVar3 == 8) {
          *(undefined2 *)(iVar8 + 0x1ecc) = (undefined2)param_2;
          QSpinBox::setValue(*(QSpinBox **)(*param_1 + 0x260),uVar9);
          FUN_004d5590(0x1c24,*param_1 + 0x1ecc,2,*param_1);
          uStack0000000b = 2;
          puVar5 = &uStack0000000b;
        }
        else {
          *(undefined2 *)(iVar8 + 0x1eba + iVar3 * 2) = (undefined2)param_2;
          *(QString *)(*param_1 + 0x1eb4 + iVar3) = param_3;
          QSpinBox::setValue(*(QSpinBox **)(*param_1 + 0x240 + iVar3 * 4),uVar9);
          if (iVar3 - 2U < 4) {
            QDoubleSpinBox::setValue
                      (*(QDoubleSpinBox **)(*param_1 + 0x260 + iVar3 * 4),
                       (double)(int)(char)param_3 / DAT_00581060);
          }
          FUN_004d5590(iVar3 * 2 + 0x1c12,*param_1 + (iVar3 + 0xf5d) * 2,2,*param_1);
          uStack0000000b = 2;
          FUN_00506590(5,0xa0000000,&uStack0000000b,1,0);
          FUN_004d5590(iVar3 + 0x1c0c,iVar3 + 0x1eb4 + *param_1,1,*param_1);
          param_2._3_1_ = 2;
          puVar5 = (undefined1 *)((int)&param_2 + 3);
        }
        goto LAB_004d185f;
      }
      *(undefined2 *)(iVar8 + 0x1eca) = (undefined2)param_2;
      *(QString *)(*param_1 + 0x1ebc) = param_3;
      QSpinBox::setValue(*(QSpinBox **)(*param_1 + 0x25c),uVar9);
      QDoubleSpinBox::setValue
                (*(QDoubleSpinBox **)(*param_1 + 0x27c),(double)(int)(char)QVar2 / DAT_00581060);
      FUN_004d5590(0x1c22,*param_1 + 0x1eca,2,*param_1);
      uStack0000000b = 2;
      FUN_00506590(5,0xa0000000,&uStack0000000b,1,0);
      iVar1 = *param_1;
      iVar8 = iVar1 + 0x1ebc;
      uVar7 = 0x1c14;
    }
    FUN_004d5590(uVar7,iVar8,CONCAT44(iVar1,1));
    uStack0000000b = 2;
    FUN_00506590(5,0xa0000000,&uStack0000000b,1,0);
    pcVar6 = blockSignals_exref;
  }
  (*pcVar6)();
  (*pcVar6)(0);
  if (iVar3 - 1U < 7) {
    (*pcVar6)(0);
  }
  ExceptionList = local_10;
  return;
}


