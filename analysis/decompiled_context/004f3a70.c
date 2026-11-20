
void __thiscall FUN_004f3a70(QObject *param_1,int param_2)

{
  char cVar1;
  QObject *pQVar2;
  int iVar3;
  int iVar4;
  void **ppvVar5;
  QString *pQVar6;
  QLabel *this;
  QListData *this_00;
  int iVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054589e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pQVar2 = QObject::sender(param_1);
  iVar3 = QComboBox::currentIndex(*(QComboBox **)(param_1 + 0x11f4));
  this_00 = (QListData *)(param_1 + 0x1354);
  iVar7 = 0;
  iVar4 = QListData::size(this_00);
  if (iVar4 < 1) {
    ExceptionList = local_10;
    return;
  }
  while( true ) {
    if ((**(int **)this_00 != 1) && (**(int **)this_00 != 0)) {
      FUN_004f2bd0(*(undefined4 *)(*(int *)this_00 + 4));
    }
    ppvVar5 = QListData::at(this_00,iVar7);
    if (*(QObject **)((int)*ppvVar5 + 0x24) == pQVar2) break;
    iVar7 = iVar7 + 1;
    iVar4 = QListData::size(this_00);
    if (iVar4 <= iVar7) {
      ExceptionList = local_10;
      return;
    }
  }
  if ((**(int **)this_00 != 1) && (**(int **)this_00 != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this_00 + 4));
  }
  ppvVar5 = QListData::at(this_00,iVar7);
  iVar4 = QComboBox::currentIndex(*(QComboBox **)((int)*ppvVar5 + 0x1c));
  if (iVar4 != 0) {
    if ((**(int **)this_00 != 1) && (**(int **)this_00 != 0)) {
      FUN_004f2bd0(*(undefined4 *)(*(int *)this_00 + 4));
    }
    ppvVar5 = QListData::at(this_00,iVar7);
    iVar4 = QComboBox::currentIndex(*(QComboBox **)((int)*ppvVar5 + 0x1c));
    if (iVar4 != 4) {
      if ((**(int **)this_00 != 1) && (**(int **)this_00 != 0)) {
        FUN_004f2bd0(*(undefined4 *)(*(int *)this_00 + 4));
      }
      ppvVar5 = QListData::at(this_00,iVar7);
      this = *(QLabel **)((int)*ppvVar5 + 0x18);
      pQVar6 = (QString *)(&DAT_007636d8 + param_2 * 4);
      goto LAB_004f3bdf;
    }
  }
  if ((**(int **)this_00 != 1) && (**(int **)this_00 != 0)) {
    FUN_004f2bd0(*(undefined4 *)(*(int *)this_00 + 4));
  }
  ppvVar5 = QListData::at(this_00,iVar7);
  this = *(QLabel **)((int)*ppvVar5 + 0x18);
  pQVar6 = (QString *)(&DAT_007634d8 + param_2 * 4);
LAB_004f3bdf:
  iVar4 = param_2;
  QLabel::setText(this,pQVar6);
  iVar3 = iVar3 * 0x1da + iVar7 * 8;
  param_1[iVar3 + 0x17e] = SUB41(iVar4,0);
  cVar1 = FUN_00506590(5,iVar3 + 0x152,param_1 + iVar3 + 0x17e,1,0);
  if (cVar1 == '\0') {
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7c3c,(char *)&param_2,"Write data failed !",0);
    local_8 = 0;
    FUN_00486bb0(&param_2);
    QString::~QString((QString *)&param_2);
  }
  ExceptionList = local_10;
  return;
}


