
void __thiscall FUN_00503470(int param_1,Data *param_2)

{
  int iVar1;
  QMimeData *this;
  QLineEdit *this_00;
  Data *pDVar2;
  bool bVar3;
  QUrl *this_01;
  QUrl *pQVar4;
  QString *pQVar5;
  Data *this_02;
  QString local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054cbe6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this = *(QMimeData **)(param_2 + 0x34);
  bVar3 = QMimeData::hasUrls(this);
  if (!bVar3) {
    ExceptionList = local_10;
    return;
  }
  QMimeData::urls(this);
  local_8 = 0;
  if ((*(int *)param_2 != 1) && (*(int *)param_2 != 0)) {
    FUN_00503360(*(int *)(param_2 + 4));
  }
  this_01 = (QUrl *)QListData::begin((QListData *)&param_2);
  if ((*(int *)param_2 != 1) && (*(int *)param_2 != 0)) {
    FUN_00503360(*(int *)(param_2 + 4));
  }
  pQVar4 = (QUrl *)QListData::end((QListData *)&param_2);
  pDVar2 = param_2;
  for (; param_2 = pDVar2, this_01 != pQVar4; this_01 = this_01 + 4) {
    this_00 = *(QLineEdit **)(param_1 + 0x20);
    pQVar5 = (QString *)QUrl::toLocalFile(this_01);
    local_8._0_1_ = 1;
    QLineEdit::setText(this_00,pQVar5);
    local_8 = (uint)local_8._1_3_ << 8;
    QString::~QString(local_14);
    pDVar2 = param_2;
  }
  local_8 = 2;
  if (*(int *)pDVar2 != 0) {
    if (*(int *)pDVar2 == -1) {
      ExceptionList = local_10;
      return;
    }
    LOCK();
    iVar1 = *(int *)pDVar2;
    *(int *)pDVar2 = *(int *)pDVar2 + -1;
    UNLOCK();
    if (iVar1 != 1) {
      ExceptionList = local_10;
      return;
    }
  }
  iVar1 = *(int *)(pDVar2 + 8);
  this_02 = pDVar2 + (*(int *)(pDVar2 + 0xc) + 4) * 4;
  while (this_02 != pDVar2 + (iVar1 + 4) * 4) {
    this_02 = this_02 + -4;
    QUrl::~QUrl((QUrl *)this_02);
  }
  QListData::dispose(pDVar2);
  ExceptionList = local_10;
  return;
}


