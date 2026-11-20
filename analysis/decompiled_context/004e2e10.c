
void __fastcall FUN_004e2e10(QTypedArrayData<unsigned_short> *param_1)

{
  undefined4 *puVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  QTypedArrayData<unsigned_short> *pQVar7;
  uint uVar8;
  QTypedArrayData<unsigned_short> *local_18;
  QByteArray local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00541b74;
  local_10 = ExceptionList;
  uVar3 = DAT_00759b24 ^ (uint)(local_14 + 0x10);
  ExceptionList = &local_10;
  local_18 = param_1;
  QByteArray::QByteArray(local_14);
  local_8 = 0;
  QByteArray::resize(local_14,0x97b);
  uVar4 = FUN_00486d80(param_1 + 0x288,0x96f,uVar3);
  pcVar5 = QByteArray::data(local_14);
  *(ulonglong *)pcVar5 = CONCAT44(uVar4,0x4d444346);
  pcVar5[8] = '\0';
  pcVar5[9] = '\0';
  pcVar5[10] = '\0';
  pcVar5[0xb] = '\0';
  pQVar7 = param_1 + 0x288;
  pcVar5 = pcVar5 + 0xc;
  for (iVar6 = 0x25b; iVar6 != 0; iVar6 = iVar6 + -1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pQVar7;
    pQVar7 = pQVar7 + 4;
    pcVar5 = pcVar5 + 4;
  }
  *(undefined2 *)pcVar5 = *(undefined2 *)pQVar7;
  *(QTypedArrayData<unsigned_short> *)(pcVar5 + 2) = pQVar7[2];
  uVar3 = *(uint *)(*(int *)(local_18 + 0x1b4) + 0x2ca6c);
  iVar6 = FUN_00488eb0(*(undefined4 *)(*(int *)(local_18 + 0x1b4) + 0x2ca68));
  if (iVar6 == 0) goto LAB_004e3066;
  puVar1 = *(undefined4 **)(iVar6 + 0x48);
  if ((uint)(puVar1[3] + puVar1[2]) < uVar3 + 0x97b) {
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7c58,(char *)&local_18,"No enough space!",0);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00486bb0(&local_18);
  }
  else {
    uVar8 = uVar3;
    if (uVar3 < uVar3 + 0x97b) {
      do {
        cVar2 = FUN_005063a0(*puVar1,uVar8);
        if (cVar2 == '\0') {
          FUN_00486c20("Erase 0x%.8X failed!",uVar8);
          goto LAB_004e3066;
        }
        uVar8 = uVar8 + puVar1[1];
      } while (uVar8 < uVar3 + 0x97b);
    }
    pcVar5 = QByteArray::data(local_14);
    uVar4 = FUN_005066c0(*puVar1,uVar3,pcVar5,0x97b,0);
    switch(uVar4) {
    case 0:
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7c58,(char *)&local_18,"Write data failed !",0);
      local_8._0_1_ = 5;
      break;
    case 1:
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7c58,(char *)&local_18,"Successful!",0);
      local_8._0_1_ = 2;
      break;
    default:
      goto LAB_004e302c;
    case 3:
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7c58,(char *)&local_18,"Verify data failed",0);
      local_8._0_1_ = 3;
      break;
    case 4:
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7c58,(char *)&local_18,"Write data timeout !",0);
      local_8._0_1_ = 4;
    }
    FUN_00486bb0(&local_18);
    local_8 = (uint)local_8._1_3_ << 8;
    QString::~QString((QString *)&local_18);
LAB_004e302c:
    pcVar5 = QByteArray::data(local_14);
    local_18 = QString::fromAscii_helper("C:\\MidiConfig.bin",0x11);
    local_8 = CONCAT31(local_8._1_3_,6);
    FUN_00487330(&local_18,pcVar5,0x97b);
  }
  QString::~QString((QString *)&local_18);
LAB_004e3066:
  QByteArray::~QByteArray(local_14);
  ExceptionList = local_10;
  return;
}


