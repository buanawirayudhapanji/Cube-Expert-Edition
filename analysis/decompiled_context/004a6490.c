
void __fastcall FUN_004a6490(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  QString *this;
  undefined4 local_28;
  int *local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0052c68a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = param_1;
  if (*(int *)(param_1 + 0x7c) == *(int *)(param_1 + 0x80)) {
    FUN_00486c20("Please select a IR wav sample file",DAT_00759b24 ^ (int)register0x00000010 - 4U);
    ExceptionList = local_10;
    return;
  }
  local_1c = QComboBox::currentIndex(*(QComboBox **)(param_1 + 0x2c));
  iVar5 = QComboBox::currentIndex(*(QComboBox **)(param_1 + 0x30));
  local_28 = 0;
  FUN_004908a0(0,local_20);
  local_8 = 0;
  cVar4 = FUN_004a6700(&local_28,&local_14);
  if (cVar4 != '\0') {
    iVar3 = *(int *)(*(int *)(param_1 + 0x40) + 0x2ca74);
    iVar6 = FUN_00488eb0(*(undefined4 *)(*(int *)(param_1 + 0x40) + 0x2ca68));
    if (iVar6 != 0) {
      puVar2 = *(undefined4 **)(iVar6 + 0x48);
      uVar8 = (iVar5 + local_1c * 9) * 0x1000 + iVar3;
      local_1c = local_14 + uVar8;
      local_20 = uVar8;
      if ((uint)(puVar2[3] + puVar2[2]) < local_1c) {
        QMetaObject::tr((QMetaObject *)&PTR_DAT_006f875c,(char *)&local_14,"No enough space!",0);
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_00486bb0(&local_14);
        this = (QString *)&local_14;
      }
      else {
        if (uVar8 < local_1c) {
          do {
            cVar4 = FUN_005063a0(*puVar2,uVar8);
            if (cVar4 == '\0') {
              FUN_00486c20("Erase 0x%.8X failed!",uVar8);
              goto LAB_004a66a2;
            }
            uVar8 = uVar8 + puVar2[1];
          } while (uVar8 < local_1c);
        }
        uVar7 = FUN_005066c0(*puVar2,local_20,local_28,local_14,0);
        switch(uVar7) {
        case 0:
          QMetaObject::tr((QMetaObject *)&PTR_DAT_006f875c,(char *)&local_18,"Write data failed !",0
                         );
          local_8 = CONCAT31(local_8._1_3_,5);
          break;
        case 1:
          QMetaObject::tr((QMetaObject *)&PTR_DAT_006f875c,(char *)&local_18,"Successful!",0);
          local_8 = CONCAT31(local_8._1_3_,2);
          break;
        default:
          goto LAB_004a66a2;
        case 3:
          QMetaObject::tr((QMetaObject *)&PTR_DAT_006f875c,(char *)&local_18,"Verify data failed",0)
          ;
          local_8 = CONCAT31(local_8._1_3_,3);
          break;
        case 4:
          QMetaObject::tr((QMetaObject *)&PTR_DAT_006f875c,(char *)&local_18,"Write data timeout !",
                          0);
          local_8 = CONCAT31(local_8._1_3_,4);
        }
        FUN_00486bb0(&local_18);
        this = (QString *)&local_18;
      }
      QString::~QString(this);
    }
  }
LAB_004a66a2:
  local_8 = 6;
  if (local_24 != (int *)0x0) {
    LOCK();
    iVar5 = local_24[1] + -1;
    local_24[1] = iVar5;
    UNLOCK();
    if (iVar5 == 0) {
      (**(code **)(*local_24 + 4))();
      LOCK();
      piVar1 = local_24 + 2;
      iVar5 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar5 == 1) {
        (**(code **)(*local_24 + 8))();
      }
    }
  }
  ExceptionList = local_10;
  return;
}


