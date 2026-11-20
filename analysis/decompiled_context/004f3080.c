
void __thiscall FUN_004f3080(QObject *param_1,QObject param_2)

{
  char cVar1;
  QObject *pQVar2;
  int iVar3;
  int iVar4;
  void **ppvVar5;
  QListData *this;
  int iVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054589e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pQVar2 = QObject::sender(param_1);
  iVar3 = QComboBox::currentIndex(*(QComboBox **)(param_1 + 0x11f4));
  this = (QListData *)(param_1 + 0x1358);
  iVar6 = 0;
  iVar4 = QListData::size(this);
  if (0 < iVar4) {
    while( true ) {
      if ((**(int **)this != 1) && (**(int **)this != 0)) {
        FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar5 = QListData::at(this,iVar6);
      if (*(QObject **)((int)*ppvVar5 + 0x20) == pQVar2) break;
      iVar6 = iVar6 + 1;
      iVar4 = QListData::size(this);
      if (iVar4 <= iVar6) {
        ExceptionList = local_10;
        return;
      }
    }
    iVar3 = (iVar3 * 0x4f + iVar6) * 6;
    param_1[iVar3 + 0x11d] = param_2;
    cVar1 = FUN_00506590(5,iVar3 + 0xf1,param_1 + iVar3 + 0x11d,1,0);
    if (cVar1 == '\0') {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7c3c,(char *)&param_2,"Write data failed !",0);
      local_8 = 0;
      FUN_00486bb0(&param_2);
      QString::~QString((QString *)&param_2);
    }
  }
  ExceptionList = local_10;
  return;
}


