
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_004db790(int param_1)

{
  uint uVar1;
  QString *pQVar2;
  int iVar3;
  undefined4 uVar4;
  QTypedArrayData<unsigned_short> *pQVar5;
  QFile local_58 [8];
  int local_50;
  int local_4c;
  QTypedArrayData<unsigned_short> *local_48;
  int local_44;
  QTypedArrayData<unsigned_short> *local_40 [5];
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined8 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  QTypedArrayData<unsigned_short> *local_8;
  
  local_8 = (QTypedArrayData<unsigned_short> *)0xffffffff;
  puStack_c = &LAB_0053d2fe;
  local_10 = ExceptionList;
  uVar1 = DAT_00759b24 ^ (uint)(local_40 + 0xf);
  if (*(int *)(param_1 + 0x48c) != 3) {
    return;
  }
  if ((uint)(*(int *)(param_1 + 0x458) - *(int *)(param_1 + 0x454) >> 2) <=
      *(uint *)(param_1 + 0x490)) {
    return;
  }
  if (*(int *)(*(int *)(*(int *)(param_1 + 0x454) + *(uint *)(param_1 + 0x490) * 4) + 0x34) == 0) {
    return;
  }
  ExceptionList = &local_10;
  local_14 = uVar1;
  local_40[0] = QString::fromAscii_helper("/Config/WavSaveDir",0x12);
  local_8 = (QTypedArrayData<unsigned_short> *)0x0;
  FUN_00484be0(&local_4c,local_40);
  local_8._0_1_ = 2;
  QString::~QString((QString *)local_40);
  if (*(int *)(local_4c + 4) == 0) {
    pQVar2 = (QString *)
             QString::asprintf((char *)&local_44,"./Song %.3d",*(int *)(param_1 + 0x490) + 1,uVar1);
    QString::operator=((QString *)&local_4c,pQVar2);
  }
  else {
    pQVar2 = (QString *)
             QString::asprintf((char *)&local_44,"./Song %.3d",*(int *)(param_1 + 0x490) + 1,uVar1);
    local_8._0_1_ = 3;
    QString::append((QString *)&local_4c,pQVar2);
  }
  QString::~QString((QString *)&local_44);
  local_48 = (QTypedArrayData<unsigned_short> *)&DAT_00755f24;
  local_40[0] = (QTypedArrayData<unsigned_short> *)&DAT_00755ef8;
  local_8._0_1_ = 5;
  QFileDialog::getSaveFileName(&local_50,param_1,local_40,&local_4c,&local_48,0,0);
  QString::~QString((QString *)local_40);
  local_8._0_1_ = 8;
  QString::~QString((QString *)&local_48);
  if (*(int *)(local_50 + 4) == 0) goto LAB_004dbad5;
  QFile::QFile(local_58);
  local_8._0_1_ = 9;
  iVar3 = FUN_00486ef0(local_58,&local_50,2,1);
  if (iVar3 != 0) {
    uVar4 = FUN_004876a0(&local_44,&local_50);
    local_8._0_1_ = 10;
    local_48 = QString::fromAscii_helper("/Config/WavSaveDir",0x12);
    local_8._0_1_ = 0xb;
    FUN_00485f80(&local_48,uVar4);
    QString::~QString((QString *)&local_48);
    local_8._0_1_ = 9;
    QString::~QString((QString *)&local_44);
    if (*(uint *)(param_1 + 0x490) <
        (uint)(*(int *)(param_1 + 0x458) - *(int *)(param_1 + 0x454) >> 2)) {
      pQVar5 = *(QTypedArrayData<unsigned_short> **)
                (*(int *)(*(int *)(param_1 + 0x454) + *(uint *)(param_1 + 0x490) * 4) + 0x34);
    }
    else {
      pQVar5 = (QTypedArrayData<unsigned_short> *)0x0;
    }
    local_48 = pQVar5;
    local_40[0] = (QTypedArrayData<unsigned_short> *)FUN_00519367(pQVar5);
    QProgressBar::setValue(*(QProgressBar **)(param_1 + 0x20),0);
    QWidget::show(*(QWidget **)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 0x48c) = 0;
    if (*(int *)(*(int *)(param_1 + 0x2c) + 0xc844) == 3) {
      iVar3 = 1;
LAB_004dba9d:
      free(local_40[0]);
    }
    else {
      if ((uint)(*(int *)(param_1 + 0x458) - *(int *)(param_1 + 0x454) >> 2) <=
          *(uint *)(param_1 + 0x490)) {
        iVar3 = 8;
        goto LAB_004dba9d;
      }
      iVar3 = FUN_004ddd80(local_40[0],pQVar5,param_1);
      local_44 = iVar3;
      if (iVar3 != 0) goto LAB_004dba9d;
      iVar3 = *(int *)(param_1 + 0x2c);
      local_2c = *(undefined4 *)(iVar3 + 0x2ca74);
      uStack_28 = *(undefined4 *)(iVar3 + 0x2ca78);
      uStack_24 = *(undefined4 *)(iVar3 + 0x2ca7c);
      uStack_20 = *(undefined4 *)(iVar3 + 0x2ca80);
      local_1c = *(undefined8 *)(iVar3 + 0x2ca84);
      iVar3 = FUN_00488eb0(*(undefined4 *)(iVar3 + 0x2ca68));
      iVar3 = *(int *)(iVar3 + 0x44);
      FUN_0050a570();
      local_8._0_1_ = 0xc;
      FUN_0050a5f0(*(undefined2 *)(iVar3 + 0x20),*(undefined4 *)(iVar3 + 0x1c),
                   *(undefined2 *)(iVar3 + 0x24));
      FUN_0050b260(local_40[0],
                   (uint)local_48 / ((*(uint *)(iVar3 + 0x24) >> 3) * *(int *)(iVar3 + 0x20)),0);
      FUN_0050b160(*(undefined4 *)(iVar3 + 0x20));
      FUN_0050b180(local_58);
      local_8._0_1_ = 9;
      FUN_0050a5b0();
      iVar3 = local_44;
    }
    QFileDevice::close((QFileDevice *)local_58);
    FUN_004dc350(iVar3);
    QWidget::hide(*(QWidget **)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 0x48c) = 3;
  }
  QFile::~QFile(local_58);
LAB_004dbad5:
  QString::~QString((QString *)&local_50);
  QString::~QString((QString *)&local_4c);
  ExceptionList = local_10;
  return;
}


