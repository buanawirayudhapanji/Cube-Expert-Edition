
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004fb020(QObject *param_1,uint param_2)

{
  char cVar1;
  uint uVar2;
  QObject *this;
  QString *pQVar3;
  int iVar4;
  QObject *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0052652e;
  local_10 = ExceptionList;
  uVar2 = DAT_00759b24 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  local_14 = param_1;
  this = QObject::sender(param_1);
  pQVar3 = (QString *)QString::asprintf((char *)&local_14,&DAT_005842a8,param_2,uVar2);
  local_8 = 0;
  QWidget::setToolTip((QWidget *)this,pQVar3);
  local_8 = 0xffffffff;
  QString::~QString((QString *)&local_14);
  if (((*(int *)(param_1 + 0x15c) - *(int *)(param_1 + 0x158) & 0xfffffff8U) != 0) &&
     (*(int *)(*(int *)(param_1 + 0x11c) + 0xc844) != 3)) {
    param_2 = param_2 & 0xffffff;
    cVar1 = FUN_00507ea0(0x768,(int)&param_2 + 3,1);
    if (cVar1 != '\0') {
      iVar4 = QAbstractSlider::value(*(QAbstractSlider **)(param_1 + 0x28));
      param_2 = CONCAT13(1,(undefined3)param_2);
      *(float *)(param_1 + 0x9a8) = (float)iVar4 / _DAT_00584580;
      cVar1 = FUN_00507ea0(0x768,param_1 + 0x9a8,4);
      if (cVar1 == '\0') {
        FUN_00486c20("Write parameters failed");
      }
      cVar1 = FUN_00507ea0(0x768,(int)&param_2 + 3,1);
      if (cVar1 != '\0') {
        ExceptionList = local_10;
        return;
      }
    }
    FUN_00486c20("Close IR failed");
  }
  ExceptionList = local_10;
  return;
}


