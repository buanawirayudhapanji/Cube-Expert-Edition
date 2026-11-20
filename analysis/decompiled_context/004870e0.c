
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

QString * FUN_004870e0(QString *param_1)

{
  char cVar1;
  uint uVar2;
  DWORD DVar3;
  UINT UVar4;
  QTypedArrayData<unsigned_short> *pQVar5;
  QListData *this;
  QString *pQVar6;
  char *pcVar7;
  char ****ppppcVar8;
  char ****ppppcVar9;
  int iVar10;
  QString *pQVar11;
  undefined2 *puVar12;
  QString *local_40;
  QString *local_3c;
  QTypedArrayData<unsigned_short> *local_38;
  undefined1 local_34 [4];
  CHAR local_30 [4];
  char ****local_2c [4];
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  char ***local_8;
  
  puStack_c = &LAB_0051d3e7;
  local_10 = ExceptionList;
  uVar2 = DAT_00759b24 ^ (uint)(local_2c + 10);
  ExceptionList = &local_10;
  local_40 = param_1;
  local_3c = param_1;
  local_18 = 0xf;
  local_1c = 0;
  local_2c[0] = (char ****)0x0;
  local_8 = (char ***)0x0;
  local_30[0] = '\0';
  local_30[1] = '\0';
  local_30[2] = 0;
  local_14 = uVar2;
  DVar3 = GetLogicalDrives();
  iVar10 = 0;
  do {
    if ((DVar3 & 1) != 0) {
      FUN_00487ce0(local_30,&DAT_00580ff8,iVar10 + 0x41,uVar2);
      puVar12 = (undefined2 *)(local_34 + 3);
      do {
        pcVar7 = (char *)((int)puVar12 + 1);
        puVar12 = (undefined2 *)((int)puVar12 + 1);
      } while (*pcVar7 != '\0');
      *puVar12 = DAT_00580ffc;
      UVar4 = GetDriveTypeA(local_30);
      if (UVar4 == 2) {
        pcVar7 = local_30;
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        FUN_004873d0(local_30,(int)pcVar7 - (int)(local_30 + 1));
        ppppcVar9 = (char ****)local_2c;
        if ((local_18 < 0x10) || (ppppcVar9 = local_2c[0], local_2c[0] != (char ****)0x0)) {
          ppppcVar8 = ppppcVar9;
          do {
            cVar1 = *(char *)ppppcVar8;
            ppppcVar8 = (char ****)((int)ppppcVar8 + 1);
          } while (cVar1 != '\0');
          iVar10 = (int)ppppcVar8 - (int)((int)ppppcVar9 + 1);
        }
        else {
          iVar10 = -1;
        }
        local_38 = QString::fromAscii_helper((char *)ppppcVar9,iVar10);
        local_8._0_1_ = 1;
        local_34 = (undefined1  [4])QString::fromAscii_helper(":",1);
        local_8._0_1_ = 2;
        this = (QListData *)QString::split((QString *)&local_38,&local_40,local_34,0,1);
        local_8 = (char ***)CONCAT31(local_8._1_3_,3);
        if ((**(int **)this != 1) && (**(int **)this != 0)) {
          FUN_004875a0(*(undefined4 *)(*(int *)this + 4));
        }
        pQVar6 = (QString *)QListData::at(this,0);
        pQVar11 = local_3c;
        QString::QString(local_3c,pQVar6);
        FUN_00486b10();
        QString::~QString((QString *)local_34);
        QString::~QString((QString *)&local_38);
        goto LAB_00487278;
      }
    }
    iVar10 = iVar10 + 1;
    DVar3 = DVar3 >> 1;
    if (0xe < iVar10) {
      pQVar5 = QString::fromAscii_helper("",0);
      *(QTypedArrayData<unsigned_short> **)local_3c = pQVar5;
      pQVar11 = local_3c;
LAB_00487278:
      if (0xf < local_18) {
        uVar2 = local_18 + 1;
        ppppcVar9 = local_2c[0];
        if (0xfff < uVar2) {
          ppppcVar9 = (char ****)local_2c[0][-1];
          uVar2 = local_18 + 0x24;
          if ((char *)0x1f < (char *)((int)local_2c[0] + (-4 - (int)ppppcVar9))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
        }
        FUN_00519359(ppppcVar9,uVar2);
      }
      ExceptionList = local_10;
      return pQVar11;
    }
  } while( true );
}


