
void __thiscall FUN_004f2df0(QObject *param_1,byte param_2)

{
  QListData *this;
  char cVar1;
  QObject *pQVar2;
  int iVar3;
  int iVar4;
  void **ppvVar5;
  int iVar6;
  QObject *pQVar7;
  QString local_20 [4];
  QObject *local_1c;
  int local_18;
  undefined1 local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054586e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = param_1;
  pQVar2 = QObject::sender(param_1);
  iVar3 = QComboBox::currentIndex(*(QComboBox **)(param_1 + 0x11f4));
  this = (QListData *)(param_1 + 0x1360);
  iVar6 = 0;
  local_18 = 0;
  iVar4 = QListData::size(this);
  if (0 < iVar4) {
    do {
      if ((**(int **)this != 1) && (**(int **)this != 0)) {
        FUN_004f2b00(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar5 = QListData::at(this,iVar6);
      if (*(QObject **)((int)*ppvVar5 + 4) == pQVar2) {
        iVar6 = iVar6 + iVar3 * 0x1da;
        pQVar7 = param_1 + iVar6 + 0x31;
        FUN_00487530(*pQVar7,1,local_14);
        *pQVar7 = (QObject)((byte)*pQVar7 ^ ((byte)*pQVar7 ^ param_2) & 0x7f);
        FUN_004f5250(local_18);
        param_1 = local_1c;
        cVar1 = FUN_00506590(5,iVar6 + 5,pQVar7,1,0);
        if (cVar1 == '\0') {
          QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7c3c,(char *)local_20,"Write data failed !",0)
          ;
          local_8 = 0;
          FUN_00486bb0(local_20);
          local_8 = 0xffffffff;
          QString::~QString(local_20);
        }
        iVar6 = local_18;
      }
      iVar6 = iVar6 + 1;
      local_18 = iVar6;
      iVar4 = QListData::size(this);
    } while (iVar6 < iVar4);
  }
  ExceptionList = local_10;
  return;
}


