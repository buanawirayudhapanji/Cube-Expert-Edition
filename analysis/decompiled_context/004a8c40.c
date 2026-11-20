
void __fastcall FUN_004a8c40(int *param_1)

{
  char cVar1;
  uint uVar2;
  QString *pQVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  int local_1c;
  QString local_18 [7];
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0052cd52;
  local_10 = ExceptionList;
  uVar2 = DAT_00759b24 ^ (uint)(local_18 + 0x14);
  ExceptionList = &local_10;
  iVar5 = *param_1;
  if ((**(int **)(iVar5 + 0xf064) != 1) && (**(int **)(iVar5 + 0xf064) != 0)) {
    FUN_004875a0(*(undefined4 *)(*(int *)(iVar5 + 0xf064) + 4));
  }
  pQVar3 = (QString *)QListData::at((QListData *)(iVar5 + 0xf064),0);
  QString::QString((QString *)&local_1c,pQVar3);
  local_8 = 0;
  if (*(int *)(local_1c + 4) == 0) {
    uVar7 = 0xffffffff;
    pQVar3 = local_18;
    pcVar6 = "Please select an AMP data first!";
    uVar4 = QString::fromLocal8Bit((char *)pQVar3,0x585c60);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00486bb0(uVar4,pQVar3,pcVar6,uVar7,uVar2);
  }
  else {
    local_11 = '\0';
    iVar5 = QComboBox::currentIndex(*(QComboBox **)(*param_1 + 0x20));
    cVar1 = FUN_00506590(5,iVar5 + -0x10000000,&local_11,1,0);
    if (cVar1 == '\0') {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f8624,(char *)local_18,"Data write failure!",0);
      local_8 = CONCAT31(local_8._1_3_,2);
    }
    else {
      cVar1 = '\n';
      FUN_004872d0(500);
      do {
        cVar1 = cVar1 + -1;
        FUN_004872d0(500);
        FUN_005063f0(5,0xf0000000,&local_11,1,0);
        if (local_11 == -1) {
          QMetaObject::tr((QMetaObject *)&PTR_DAT_006f8624,(char *)local_18,"Save successfully!",0);
          local_8 = CONCAT31(local_8._1_3_,3);
          goto LAB_004a8dac;
        }
      } while (cVar1 != '\0');
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f8624,(char *)local_18,"Save fail!",0);
      local_8 = CONCAT31(local_8._1_3_,4);
    }
LAB_004a8dac:
    FUN_00486bb0(local_18);
  }
  QString::~QString(local_18);
  QString::~QString((QString *)&local_1c);
  ExceptionList = local_10;
  return;
}


