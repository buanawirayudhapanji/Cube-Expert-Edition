
void __thiscall FUN_004f4090(QObject *param_1,int param_2)

{
  QListData *this;
  char cVar1;
  QObject *pQVar2;
  int iVar3;
  int iVar4;
  void **ppvVar5;
  int iVar6;
  QString *pQVar7;
  int iVar8;
  QLabel *this_00;
  int iVar9;
  QString local_1c [4];
  QObject *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054594e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = param_1;
  pQVar2 = QObject::sender(param_1);
  iVar3 = QComboBox::currentIndex(*(QComboBox **)(param_1 + 0x11f4));
  this = (QListData *)(param_1 + 0x135c);
  iVar9 = 0;
  iVar4 = QListData::size(this);
  if (0 < iVar4) {
    iVar4 = 0;
    local_14 = 0;
    do {
      if ((**(int **)this != 1) && (**(int **)this != 0)) {
        FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
      }
      ppvVar5 = QListData::at(this,iVar9);
      if (*(QObject **)((int)*ppvVar5 + 0x24) == pQVar2) {
        iVar4 = iVar4 + iVar3 * 0x1da;
        local_18[iVar4 + 0x4c] = SUB41(param_2,0);
        if ((**(int **)this != 1) && (**(int **)this != 0)) {
          FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
        }
        ppvVar5 = QListData::at(this,iVar9);
        iVar6 = QComboBox::currentIndex(*(QComboBox **)((int)*ppvVar5 + 0x1c));
        iVar8 = **(int **)this;
        if (iVar6 == 5) {
          if ((iVar8 != 1) && (iVar8 != 0)) {
            FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
          }
          ppvVar5 = QListData::at(this,iVar9);
          this_00 = *(QLabel **)((int)*ppvVar5 + 0x18);
          pQVar7 = (QString *)(&DAT_007634d8 + param_2 * 4);
        }
        else {
          if ((iVar8 != 1) && (iVar8 != 0)) {
            FUN_004f2bd0(*(undefined4 *)(*(int *)this + 4));
          }
          ppvVar5 = QListData::at(this,iVar9);
          this_00 = *(QLabel **)((int)*ppvVar5 + 0x18);
          pQVar7 = (QString *)(&DAT_007636d8 + param_2 * 4);
        }
        QLabel::setText(this_00,pQVar7);
        cVar1 = FUN_00506590(5,iVar4 + 0x20,local_18 + iVar4 + 0x4c,1,0);
        if (cVar1 == '\0') {
          QMetaObject::tr((QMetaObject *)&PTR_DAT_006f7c3c,(char *)local_1c,"Write data failed !",0)
          ;
          local_8 = 0;
          FUN_00486bb0(local_1c);
          local_8 = 0xffffffff;
          QString::~QString(local_1c);
        }
        iVar4 = local_14;
      }
      iVar4 = iVar4 + 0x46;
      iVar9 = iVar9 + 1;
      local_14 = iVar4;
      iVar8 = QListData::size(this);
    } while (iVar9 < iVar8);
  }
  ExceptionList = local_10;
  return;
}


