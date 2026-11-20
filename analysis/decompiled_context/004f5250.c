
void __thiscall FUN_004f5250(uint param_1,QTypedArrayData<unsigned_short> *param_2)

{
  QListData *this;
  byte bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  void **ppvVar6;
  QString *pQVar7;
  char *pcVar8;
  QWidget *this_00;
  char *pcVar9;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar4 = (int)param_2;
  local_8 = 0xffffffff;
  puStack_c = &LAB_005308ae;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  bVar1 = *(byte *)(param_1 + 0x18);
  if ((-(uint)(bVar1 != 0) & (uint)bVar1) < 7) {
    uVar5 = -(uint)(bVar1 != 0) & (uint)bVar1;
  }
  else {
    uVar5 = 7;
  }
  local_14 = param_1;
  FUN_00487530(*(undefined1 *)(uVar5 * 0x1da + (int)param_2 + 0x31 + param_1),1,&local_14,
               DAT_00759b24 ^ (int)register0x00000010 - 4U);
  pcVar9 = "ON";
  if ((char)local_14 == '\0') {
    pcVar9 = "OFF";
  }
  pcVar8 = pcVar9;
  do {
    cVar2 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar2 != '\0');
  param_2 = QString::fromAscii_helper(pcVar9,(int)pcVar8 - (int)(pcVar9 + 1));
  this = (QListData *)(param_1 + 0x1360);
  local_8 = 0;
  if ((**(int **)(param_1 + 0x1360) != 1) && (**(int **)(param_1 + 0x1360) != 0)) {
    FUN_004f2b00(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar6 = QListData::at(this,iVar4);
  QLabel::setText(*(QLabel **)((int)*ppvVar6 + 0xc),
                  (QString *)(&DAT_007634d8 + (local_14 >> 8 & 0xff) * 4));
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2b00(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar6 = QListData::at(this,iVar4);
  QWidget::setDisabled(*(QWidget **)((int)*ppvVar6 + 4),(char)local_14 == '\0');
  iVar3 = **(int **)this;
  if ((char)local_14 == '\0') {
    if ((iVar3 != 1) && (iVar3 != 0)) {
      FUN_004f2b00(*(undefined4 *)(*(int *)this + 4));
    }
    ppvVar6 = QListData::at(this,iVar4);
    this_00 = *(QWidget **)*ppvVar6;
    pQVar7 = (QString *)(param_1 + 0x1370);
  }
  else {
    if ((iVar3 != 1) && (iVar3 != 0)) {
      FUN_004f2b00(*(undefined4 *)(*(int *)this + 4));
    }
    ppvVar6 = QListData::at(this,iVar4);
    this_00 = *(QWidget **)*ppvVar6;
    pQVar7 = (QString *)(param_1 + 0x1374);
  }
  QWidget::setStyleSheet(this_00,pQVar7);
  if ((**(int **)this != 1) && (**(int **)this != 0)) {
    FUN_004f2b00(*(undefined4 *)(*(int *)this + 4));
  }
  ppvVar6 = QListData::at(this,iVar4);
  QAbstractButton::setText(*(QAbstractButton **)*ppvVar6,(QString *)&param_2);
  QString::~QString((QString *)&param_2);
  ExceptionList = local_10;
  return;
}


