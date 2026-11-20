
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_004844a0(int param_1)

{
  uint uVar1;
  int iVar2;
  QString *pQVar3;
  undefined4 uVar4;
  QFile local_58 [8];
  int local_50;
  int local_4c;
  int local_48;
  QTypedArrayData<unsigned_short> *local_44;
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
  puStack_c = &LAB_0051b5de;
  local_10 = ExceptionList;
  uVar1 = DAT_00759b24 ^ (uint)(local_40 + 0xf);
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 0x498) == 3) {
    local_14 = uVar1;
    iVar2 = FUN_00511b10(*(undefined4 *)(param_1 + 0x49c));
    if (iVar2 != 0) {
      local_44 = QString::fromAscii_helper("/Config/WavSaveDir",0x12);
      local_8 = (QTypedArrayData<unsigned_short> *)0x0;
      FUN_00484be0(&local_48,&local_44);
      local_8._0_1_ = 2;
      QString::~QString((QString *)&local_44);
      if (*(int *)(local_48 + 4) == 0) {
        pQVar3 = (QString *)
                 QString::asprintf((char *)local_40,"./Song %.3d",*(int *)(param_1 + 0x49c) + 1,
                                   uVar1);
        QString::operator=((QString *)&local_48,pQVar3);
      }
      else {
        pQVar3 = (QString *)
                 QString::asprintf((char *)local_40,"./Song %.3d",*(int *)(param_1 + 0x49c) + 1,
                                   uVar1);
        local_8._0_1_ = 3;
        QString::append((QString *)&local_48,pQVar3);
      }
      QString::~QString((QString *)local_40);
      local_40[0] = (QTypedArrayData<unsigned_short> *)&DAT_00754150;
      local_44 = (QTypedArrayData<unsigned_short> *)&DAT_00754124;
      local_8._0_1_ = 5;
      QFileDialog::getSaveFileName(&local_4c,param_1,&local_44,&local_48,local_40,0,0);
      QString::~QString((QString *)&local_44);
      local_8._0_1_ = 8;
      QString::~QString((QString *)local_40);
      if (*(int *)(local_4c + 4) != 0) {
        QFile::QFile(local_58);
        local_8._0_1_ = 9;
        iVar2 = FUN_00486ef0(local_58,&local_4c,2,1);
        if (iVar2 != 0) {
          uVar4 = FUN_004876a0(&local_44,&local_4c);
          local_8._0_1_ = 10;
          local_40[0] = QString::fromAscii_helper("/Config/WavSaveDir",0x12);
          local_8._0_1_ = 0xb;
          FUN_00485f80(local_40,uVar4);
          QString::~QString((QString *)local_40);
          local_8._0_1_ = 9;
          QString::~QString((QString *)&local_44);
          local_40[0] = (QTypedArrayData<unsigned_short> *)
                        FUN_00511a20(*(undefined4 *)(param_1 + 0x49c));
          local_44 = (QTypedArrayData<unsigned_short> *)FUN_00519367(local_40[0]);
          QProgressBar::setValue(*(QProgressBar **)(param_1 + 0x28),0);
          QWidget::show(*(QWidget **)(param_1 + 0x28));
          *(undefined4 *)(param_1 + 0x498) = 0;
          local_50 = FUN_00511c70(*(undefined4 *)(param_1 + 0x49c),local_44,local_40[0],param_1);
          if (local_50 == 0) {
            iVar2 = *(int *)(param_1 + 0x2c);
            local_2c = *(undefined4 *)(iVar2 + 0x2ca74);
            uStack_28 = *(undefined4 *)(iVar2 + 0x2ca78);
            uStack_24 = *(undefined4 *)(iVar2 + 0x2ca7c);
            uStack_20 = *(undefined4 *)(iVar2 + 0x2ca80);
            local_1c = *(undefined8 *)(iVar2 + 0x2ca84);
            iVar2 = FUN_00488eb0(*(undefined4 *)(iVar2 + 0x2ca68));
            iVar2 = *(int *)(iVar2 + 0x44);
            FUN_0050a570();
            local_8._0_1_ = 0xc;
            FUN_0050a5f0(*(undefined2 *)(iVar2 + 0x20),*(undefined4 *)(iVar2 + 0x1c),
                         *(undefined2 *)(iVar2 + 0x24));
            FUN_0050b260(local_44,(uint)local_40[0] /
                                  ((*(uint *)(iVar2 + 0x24) >> 3) * *(int *)(iVar2 + 0x20)),0);
            FUN_0050b160(*(undefined4 *)(iVar2 + 0x20));
            FUN_0050b180(local_58);
            local_8._0_1_ = 9;
            FUN_0050a5b0();
          }
          else {
            free(local_44);
          }
          QFileDevice::close((QFileDevice *)local_58);
          FUN_00484ce0(local_50);
          QWidget::hide(*(QWidget **)(param_1 + 0x28));
          *(undefined4 *)(param_1 + 0x498) = 3;
        }
        QFile::~QFile(local_58);
      }
      QString::~QString((QString *)&local_4c);
      QString::~QString((QString *)&local_48);
    }
  }
  ExceptionList = local_10;
  return;
}


