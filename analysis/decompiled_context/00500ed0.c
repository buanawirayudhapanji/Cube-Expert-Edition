
undefined4 __thiscall FUN_00500ed0(QString *param_1,QString *param_2)

{
  void *pvVar1;
  int *piVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  char *_Memory;
  QString *pQVar6;
  QString *pQVar7;
  uint uVar8;
  int *piVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  void *_Dst;
  int local_24 [2];
  QString local_1c [4];
  int local_18;
  QString *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054bca7;
  local_10 = ExceptionList;
  uVar4 = DAT_00759b24 ^ (uint)(local_1c + 0x18);
  ExceptionList = &local_10;
  local_14 = param_1;
  QFile::QFile((QFile *)local_24,param_2);
  local_8 = 0;
  QString::QString(local_1c);
  local_8 = CONCAT31(local_8._1_3_,1);
  bVar3 = QFile::open((QFile *)local_24,1);
  if (!bVar3) {
    QString::operator=(param_1,"Open file failed");
    uVar10 = 0;
    goto LAB_00501197;
  }
  QIODevice::read((QIODevice *)local_24,(char *)(param_1 + 0xc),(ulonglong)uVar4 << 0x20);
  uVar12 = 7;
  pQVar6 = param_1 + 0x7c;
  piVar2 = (int *)"Data Number";
  do {
    piVar9 = piVar2;
    pQVar7 = pQVar6;
    if (*(int *)pQVar7 != *piVar9) goto LAB_0050116d;
    bVar3 = 3 < uVar12;
    uVar12 = uVar12 - 4;
    pQVar6 = pQVar7 + 4;
    piVar2 = piVar9 + 1;
  } while (bVar3);
  if ((*(short *)(pQVar7 + 4) == (short)piVar9[1]) && (pQVar7[6] == *(QString *)((int)piVar9 + 6)))
  {
    QFileDevice::seek((QFileDevice *)local_24,0x7b);
    pQVar6 = param_1 + 4;
    *(uint *)pQVar6 = 0;
    QIODevice::read((QIODevice *)local_24,(char *)pQVar6,(ulonglong)uVar4 << 0x20);
    QFileDevice::seek((QFileDevice *)local_24,0x7c);
    QIODevice::read((QIODevice *)local_24,(char *)&local_18,(ulonglong)uVar4 << 0x20);
    iVar5 = FUN_00500e60(local_24,0,0x7c);
    if (local_18 == iVar5) {
      QFileDevice::seek((QFileDevice *)local_24,0x80);
      pvVar1 = *(void **)(param_1 + 0x8c);
      _Dst = *(void **)(param_1 + 0x90);
      if (pvVar1 != *(void **)(param_1 + 0x90)) {
        *(void **)(param_1 + 0x90) = pvVar1;
        _Dst = pvVar1;
      }
      uVar12 = *(uint *)pQVar6;
      if (uVar12 < 100) {
        uVar8 = (int)_Dst - (int)pvVar1 >> 7;
        if (uVar12 < uVar8) {
          *(void **)(param_1 + 0x90) = (void *)(uVar12 * 0x80 + (int)pvVar1);
        }
        else if (uVar8 < uVar12) {
          if ((uint)(*(int *)(param_1 + 0x94) - (int)pvVar1 >> 7) < uVar12) {
            FUN_00500c40(uVar12,(int)&param_2 + 3);
          }
          else {
            iVar5 = uVar12 - uVar8;
            if (iVar5 != 0) {
              memset(_Dst,0,iVar5 * 0x80);
              _Dst = (void *)((int)_Dst + iVar5 * 0x80);
            }
            *(void **)(param_1 + 0x90) = _Dst;
          }
        }
      }
      uVar8 = 0;
      uVar12 = 0;
      if (*(int *)(local_14 + 4) != 0) {
        iVar5 = 0;
        do {
          QIODevice::read((QIODevice *)local_24,(char *)(*(int *)(param_1 + 0x8c) + iVar5),
                          (ulonglong)uVar4 << 0x20);
          uVar8 = uVar8 + 1;
          iVar5 = iVar5 + 0x80;
          uVar12 = *(uint *)(local_14 + 4);
        } while (uVar8 < uVar12);
      }
      uVar8 = 0;
      if (uVar12 != 0) {
        do {
          uVar11 = (uVar8 + 1) * 0x80;
          QFileDevice::seek((QFileDevice *)local_24,(ulonglong)(uVar11 + 0x7c));
          QIODevice::read((QIODevice *)local_24,(char *)&local_18,(ulonglong)uVar4 << 0x20);
          uVar12 = (**(code **)(local_24[0] + 0x3c))();
          if (uVar11 < uVar12) {
            _Memory = (char *)FUN_00519367(0x7c);
            (**(code **)(local_24[0] + 0x40))(uVar11,0);
            QIODevice::read((QIODevice *)local_24,_Memory,(ulonglong)uVar4 << 0x20);
            iVar5 = FUN_00486d80(_Memory,0x7c);
            free(_Memory);
          }
          else {
            iVar5 = 0;
          }
          uVar8 = uVar8 + 1;
          if (local_18 != iVar5) {
            pQVar6 = (QString *)
                     QString::asprintf((char *)&param_2,"Data%ul header checksum Error",uVar8);
            param_1 = local_14;
            goto LAB_00500ff7;
          }
        } while (uVar8 < *(uint *)(local_14 + 4));
      }
      goto LAB_00501189;
    }
    param_2 = (QString *)&DAT_00756828;
    pQVar6 = (QString *)&param_2;
LAB_00500ff7:
    QString::operator=(param_1,pQVar6);
    QString::~QString((QString *)&param_2);
    uVar10 = 0;
  }
  else {
LAB_0050116d:
    param_2 = (QString *)&DAT_007567f4;
    QString::operator=(param_1,(QString *)&param_2);
    QString::~QString((QString *)&param_2);
LAB_00501189:
    uVar10 = 1;
  }
  QFileDevice::close((QFileDevice *)local_24);
LAB_00501197:
  QString::~QString(local_1c);
  QFile::~QFile((QFile *)local_24);
  ExceptionList = local_10;
  return uVar10;
}


