
void FUN_004d0f60(QTypedArrayData<unsigned_short> *param_1,int param_2)

{
  int iVar1;
  char *_Src;
  int *piVar2;
  QTypedArrayData<unsigned_short> *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar1 = param_2;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00539b59;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 == (QTypedArrayData<unsigned_short> *)0x0) {
    if (param_2 != 0) {
      FUN_00519359(param_2,0x10,DAT_00759b24 ^ (int)register0x00000010 - 4U);
    }
  }
  else if (param_1 == (QTypedArrayData<unsigned_short> *)0x1) {
    piVar2 = &local_14;
    QLineEdit::text(*(QLineEdit **)(param_2 + 8));
    local_8 = 0;
    if (*(int *)(local_14 + 4) < 1) {
      local_18 = QString::fromAscii_helper("Please enter at least one character!",0x24);
      local_8._0_1_ = 2;
      param_1 = QString::fromAscii_helper("error",5);
      local_8 = CONCAT31(local_8._1_3_,3);
      QMessageBox::warning(*(undefined4 *)(iVar1 + 0xc),&param_1,&local_18,0x400,0,piVar2);
      QString::~QString((QString *)&param_1);
      QString::~QString((QString *)&local_18);
      QString::~QString((QString *)&local_14);
      ExceptionList = local_10;
      return;
    }
    QString::toLatin1((QString *)&local_14);
    local_8 = CONCAT31(local_8._1_3_,1);
    _Src = QByteArray::constData((QByteArray *)&param_1);
    memcpy((void *)(*(int *)(iVar1 + 0xc) + 0x18),_Src,*(size_t *)((int)param_1 + 4));
    *(undefined1 *)(*(int *)((int)param_1 + 4) + 0x18 + *(int *)(iVar1 + 0xc)) = 0;
    (**(code **)(**(int **)(iVar1 + 0xc) + 0xc0))();
    QByteArray::~QByteArray((QByteArray *)&param_1);
    QString::~QString((QString *)&local_14);
    ExceptionList = local_10;
    return;
  }
  ExceptionList = local_10;
  return;
}


