
void __thiscall FUN_004e3d20(int param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  QString *pQVar7;
  QChar aQStack_5e [2];
  int *local_28;
  QString local_20 [4];
  undefined4 local_1c;
  undefined4 local_18;
  QTypedArrayData<unsigned_short> *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00541d5d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = 0;
  if (*(int *)(param_2 + 0x18) == 0x1000034) {
    uVar3 = *(undefined4 *)(*(int *)(param_1 + 0x1b4) + 0x2ca6c);
    iVar5 = FUN_00488eb0();
    if (iVar5 != 0) {
      puVar2 = *(undefined4 **)(iVar5 + 0x48);
      uVar6 = FUN_00519367();
      FUN_004908a0(uVar6);
      local_8 = 0;
      cVar4 = FUN_005063f0(*puVar2,uVar3,uVar6,0x5a000);
      if (cVar4 == '\0') {
        QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7c58,(char *)&param_2,"Read data failed !",0);
        local_8 = CONCAT31(local_8._1_3_,8);
        FUN_00486bb0();
      }
      else {
        pQVar7 = (QString *)FUN_00486cd0();
        local_8._0_1_ = 2;
        QString::QString((QString *)&param_2,pQVar7);
        local_18 = 1;
        pQVar7 = (QString *)QString::fromUtf8((char *)&local_14,0x591e1c);
        local_8._0_1_ = 3;
        QString::append((QString *)&param_2,pQVar7);
        QString::~QString((QString *)&local_14);
        local_8._0_1_ = 4;
        QString::~QString((QString *)&local_1c);
        iVar5 = FUN_00487330(&param_2,uVar6);
        if (iVar5 == 0) {
          QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7c58,(char *)&local_14,
                          "Midi bank save Failed!",0);
          local_18 = 5;
          local_8 = CONCAT31(local_8._1_3_,7);
          FUN_00486bb0();
          QString::~QString((QString *)&local_14);
        }
        else {
          local_14 = QString::fromAscii_helper("File saved at:%1",0x10);
          local_1c = CONCAT31(local_1c._1_3_,0x20);
          local_8._0_1_ = 5;
          QChar::QChar(aQStack_5e + -6,local_1c);
          QString::arg((QString *)&local_14,local_20,&param_2,0);
          local_8 = CONCAT31(local_8._1_3_,6);
          FUN_00486bb0();
          QString::~QString(local_20);
          QString::~QString((QString *)&local_14);
        }
      }
      QString::~QString((QString *)&param_2);
      local_8 = 9;
      if (local_28 != (int *)0x0) {
        LOCK();
        iVar5 = local_28[1] + -1;
        local_28[1] = iVar5;
        UNLOCK();
        if (iVar5 == 0) {
          (**(code **)(*local_28 + 4))();
          LOCK();
          piVar1 = local_28 + 2;
          iVar5 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar5 == 1) {
            (**(code **)(*local_28 + 8))();
          }
        }
      }
    }
  }
  ExceptionList = local_10;
  return;
}


