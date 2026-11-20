
void __thiscall FUN_0049e630(int param_1,QListWidgetItem *param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  int iVar4;
  undefined8 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005265be;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar2 = QListWidgetItem::text(param_2);
  local_8 = 0;
  cVar1 = FUN_0050a930(uVar2);
  local_8 = 0xffffffff;
  QString::~QString((QString *)((int)&local_18 + 4));
  if (cVar1 != '\0') {
    FUN_0050b2c0((int *)(param_1 + 0x138),0x200);
    puVar3 = *(undefined8 **)(param_1 + 0x13c);
    iVar4 = (int)puVar3 - *(int *)(param_1 + 0x138) >> 3;
    if (iVar4 < 0x200) {
      iVar4 = 0x200 - iVar4;
      do {
        local_18 = 0;
        if (puVar3 == *(undefined8 **)(param_1 + 0x140)) {
          FUN_00490930(puVar3,&local_18);
          puVar3 = *(undefined8 **)(param_1 + 0x13c);
        }
        else {
          *puVar3 = 0;
          puVar3 = puVar3 + 1;
          *(undefined8 **)(param_1 + 0x13c) = puVar3;
        }
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    FUN_004a0120();
  }
  ExceptionList = local_10;
  return;
}


