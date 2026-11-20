
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00496ef0(int param_1,QListWidgetItem *param_2)

{
  char cVar1;
  int iVar2;
  void *_Memory;
  undefined4 uVar3;
  QString local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00527e9e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  QListWidgetItem::text(param_2);
  local_8 = 0;
  cVar1 = FUN_00508540();
  local_8 = 0xffffffff;
  QString::~QString(local_14);
  if (cVar1 != '\0') {
    uVar3 = 0x496f8a;
    FUN_00488eb0();
    FUN_00508610(*(undefined4 *)(param_1 + 0x4084),*(undefined4 *)(param_1 + 0x4088),
                 *(undefined4 *)(param_1 + 0x408c),*(undefined4 *)(param_1 + 0x4090),
                 CONCAT62((int6)(CONCAT44(0x7ff,uVar3) >> 0x10),*(undefined2 *)(param_1 + 0x4094)));
    iVar2 = QAbstractSlider::value(*(QAbstractSlider **)(param_1 + 0x28));
    FUN_00508bd0((void *)(param_1 + 0x3c),(double)(100 - iVar2) / _PTR_00584578);
    memcpy((void *)(param_1 + 0x2038),(void *)(param_1 + 0x3c),0x1ffc);
    if (*(int *)(*(int *)(param_1 + 0x4038) + 0xc844) != 3) {
      cVar1 = FUN_00506590(4,0,param_1 + 0x2038,0x2000,0);
      if (cVar1 == '\0') {
        FUN_00486c20();
      }
      else {
        _Memory = (void *)FUN_00519367();
        cVar1 = FUN_00506590(4,0x10000000,_Memory,1,0);
        if (cVar1 == '\0') {
          FUN_00486c20();
        }
        free(_Memory);
      }
    }
  }
  ExceptionList = local_10;
  return;
}


