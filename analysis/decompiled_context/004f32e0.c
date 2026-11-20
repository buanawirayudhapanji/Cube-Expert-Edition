
void __thiscall FUN_004f32e0(QObject *param_1,int param_2)

{
  QListData *this;
  char cVar1;
  QObject *pQVar2;
  int iVar3;
  int iVar4;
  void **ppvVar5;
  int iVar6;
  QString local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005265be;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pQVar2 = QObject::sender(param_1);
  iVar3 = QComboBox::currentIndex(*(QComboBox **)(param_1 + 0x11f4));
  this = (QListData *)(param_1 + 0x1358);
  iVar6 = 0;
  iVar4 = QListData::size(this);
  if (0 < iVar4) {
    do {
      if ((**(int **)this != 1) && (**(int **)this != 0)) {
        FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar5 = QListData::at(this,iVar6);
      if (*(QObject **)((int)*ppvVar5 + 0x28) == pQVar2) {
        iVar4 = (iVar3 * 0x4f + iVar6) * 6;
        param_1[iVar4 + 0x11f] = SUB41(param_2,0);
        cVar1 = FUN_00506590(5,iVar4 + 0xf3,param_1 + iVar4 + 0x11f,1,0);
        if (cVar1 == '\0') {
          QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7c3c,(char *)local_14,"Write data failed !",0)
          ;
          local_8 = 0;
          FUN_00486bb0(local_14);
          local_8 = 0xffffffff;
          QString::~QString(local_14);
        }
        if ((**(int **)this != 1) && (**(int **)this != 0)) {
          FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
        }
        ppvVar5 = QListData::at(this,iVar6);
        QLabel::setText(*(QLabel **)((int)*ppvVar5 + 0x18),(QString *)(&DAT_007636d8 + param_2 * 4))
        ;
      }
      iVar6 = iVar6 + 1;
      iVar4 = QListData::size(this);
    } while (iVar6 < iVar4);
  }
  ExceptionList = local_10;
  return;
}


