
void __thiscall FUN_004f4560(QObject *param_1,QObject param_2)

{
  char cVar1;
  QObject *pQVar2;
  int iVar3;
  int iVar4;
  void **ppvVar5;
  int iVar6;
  QListData *this;
  int iVar7;
  QString local_18 [4];
  QObject *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005459be;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = param_1;
  pQVar2 = QObject::sender(param_1);
  iVar3 = QComboBox::currentIndex(*(QComboBox **)(param_1 + 0x11f4));
  this = (QListData *)(param_1 + 0x135c);
  iVar7 = 0;
  iVar4 = QListData::size(this);
  if (0 < iVar4) {
    iVar4 = 0;
    do {
      if ((**(int **)this != 1) && (**(int **)this != 0)) {
        FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar5 = QListData::at(this,iVar7);
      if (*(QObject **)((int)*ppvVar5 + 0x2c) == pQVar2) {
        iVar6 = iVar3 * 0x1da + iVar4;
        local_14[iVar6 + 0x4e] = param_2;
        cVar1 = FUN_00506590(5,iVar6 + 0x22,local_14 + iVar6 + 0x4e,1,0);
        if (cVar1 == '\0') {
          QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7c3c,(char *)local_18,"Write data failed !",0)
          ;
          local_8 = 0;
          FUN_00486bb0(local_18);
          local_8 = 0xffffffff;
          QString::~QString(local_18);
        }
      }
      iVar7 = iVar7 + 1;
      iVar4 = iVar4 + 0x46;
      iVar6 = QListData::size(this);
    } while (iVar7 < iVar6);
  }
  ExceptionList = local_10;
  return;
}


