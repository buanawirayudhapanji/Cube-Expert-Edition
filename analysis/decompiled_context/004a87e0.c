
void __thiscall FUN_004a87e0(int *param_1,QListWidgetItem *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  size_t sVar7;
  undefined1 *puVar8;
  int iVar9;
  void *_Dst;
  __int64 _Var10;
  int *piVar11;
  QFile local_20 [8];
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0052cc80;
  local_10 = ExceptionList;
  uVar5 = DAT_00759b24 ^ (uint)(local_20 + 0x1c);
  ExceptionList = &local_10;
  piVar11 = &local_14;
  local_18 = param_1;
  QListWidgetItem::text(param_2);
  local_8 = 0;
  if (*(int *)(local_14 + 4) != 0) {
    QFile::QFile(local_20);
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar6 = FUN_00486ef0(local_20,&local_14,1,1,piVar11,uVar5);
    if (iVar6 != 0) {
      _Var10 = QFile::size(local_20);
      QIODevice::read((QIODevice *)local_20,(char *)(*param_1 + 0x4038),
                      CONCAT44(piVar11,(int)((ulonglong)_Var10 >> 0x20)));
      QFileDevice::close((QFileDevice *)local_20);
      iVar6 = *param_1;
      *(undefined1 *)(iVar6 + 0x4038) = 0x41;
      *(undefined1 *)(*param_1 + 0x4039) = 0x4d;
      *(undefined1 *)(*param_1 + 0x403a) = 0x50;
      *(undefined1 *)(*param_1 + 0x403b) = 0;
      iVar9 = *param_1;
      uVar1 = *(undefined4 *)(iVar9 + 0x403c);
      uVar2 = *(undefined4 *)(iVar9 + 0x4040);
      uVar3 = *(undefined4 *)(iVar9 + 0x4044);
      *(undefined4 *)(iVar6 + 0x38) = *(undefined4 *)(iVar9 + 0x4038);
      *(undefined4 *)(iVar6 + 0x3c) = uVar1;
      *(undefined4 *)(iVar6 + 0x40) = uVar2;
      *(undefined4 *)(iVar6 + 0x44) = uVar3;
      uVar1 = *(undefined4 *)(iVar9 + 0x404c);
      uVar2 = *(undefined4 *)(iVar9 + 0x4050);
      uVar3 = *(undefined4 *)(iVar9 + 0x4054);
      *(undefined4 *)(iVar6 + 0x48) = *(undefined4 *)(iVar9 + 0x4048);
      *(undefined4 *)(iVar6 + 0x4c) = uVar1;
      *(undefined4 *)(iVar6 + 0x50) = uVar2;
      *(undefined4 *)(iVar6 + 0x54) = uVar3;
      uVar1 = *(undefined4 *)(iVar9 + 0x405c);
      uVar2 = *(undefined4 *)(iVar9 + 0x4060);
      uVar3 = *(undefined4 *)(iVar9 + 0x4064);
      *(undefined4 *)(iVar6 + 0x58) = *(undefined4 *)(iVar9 + 0x4058);
      *(undefined4 *)(iVar6 + 0x5c) = uVar1;
      *(undefined4 *)(iVar6 + 0x60) = uVar2;
      *(undefined4 *)(iVar6 + 100) = uVar3;
      *(undefined8 *)(iVar6 + 0x68) = *(undefined8 *)(iVar9 + 0x4068);
      *(undefined4 *)(iVar6 + 0x70) = *(undefined4 *)(iVar9 + 0x4070);
      sVar7 = *(size_t *)(*param_1 + 0x4074);
      if ((int)sVar7 < 1) {
        sVar7 = 0;
      }
      memcpy((void *)(iVar6 + 0x74),(void *)(*param_1 + 0x4078),sVar7);
      iVar9 = *param_1;
      _Dst = (void *)(iVar6 + 0x74 + *(int *)(iVar9 + 0x4074));
      uVar5 = 0;
      do {
        sVar7 = *(size_t *)(uVar5 + 0x8e98 + iVar9);
        if ((int)sVar7 < 1) {
          sVar7 = 0;
        }
        memcpy(_Dst,(void *)(iVar9 + 0x8e9c + uVar5),sVar7);
        piVar11 = local_18;
        iVar9 = *local_18;
        _Dst = (void *)((int)_Dst + *(int *)(uVar5 + 0x8e98 + iVar9));
        uVar5 = uVar5 + 0x138c;
      } while (uVar5 < 0x61bc);
      *(undefined1 *)(iVar9 + 0xf054) = 0x47;
      *(undefined1 *)(*local_18 + 0xf055) = 0x41;
      *(undefined1 *)(*local_18 + 0xf056) = 0x54;
      *(undefined1 *)(*local_18 + 0xf057) = 0x45;
      *(undefined1 *)(*local_18 + 0xf058) = 0;
      memcpy((void *)(iVar9 + 0x3c38),(void *)(*local_18 + 0xf054),0xb02c);
      cVar4 = FUN_00506590(5,0,*piVar11 + 0x38,0x4000,0);
      if (cVar4 == '\0') {
        QMetaObject::tr((QMetaObject *)&PTR_DAT_006f8624,(char *)&param_2,"Data write failure!",0);
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_00486bb0(&param_2);
        QString::~QString((QString *)&param_2);
      }
      else {
        puVar8 = (undefined1 *)FUN_00519367(1);
        *puVar8 = 1;
        FUN_00506590(5,0xa0000000,puVar8,1,0);
      }
    }
    QFile::~QFile(local_20);
  }
  QString::~QString((QString *)&local_14);
  ExceptionList = local_10;
  return;
}


