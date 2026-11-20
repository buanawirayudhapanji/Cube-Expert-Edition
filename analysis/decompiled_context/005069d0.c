
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 __thiscall FUN_005069d0(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  QRegularExpression *pQVar4;
  QString *pQVar5;
  QString *this;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 in_stack_ffffff68;
  undefined4 in_stack_ffffff6c;
  undefined4 uVar10;
  undefined4 uVar11;
  char *pcVar12;
  undefined4 uVar13;
  undefined1 local_70 [8];
  QTypedArrayData<unsigned_short> *local_68;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_64 [4];
  QRegularExpression local_60 [4];
  int *local_5c;
  int local_58 [4];
  undefined4 local_48;
  uint local_44;
  uint local_40 [4];
  undefined4 local_30;
  uint local_2c;
  undefined1 local_28 [6];
  char local_22;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054e181;
  local_10 = ExceptionList;
  uVar2 = DAT_00759b24 ^ (uint)(local_28 + 0x24);
  ExceptionList = &local_10;
  local_14 = uVar2;
  cVar1 = FUN_00508180(param_2,1,param_3);
  if (cVar1 == '\0') goto LAB_00507077;
  local_30 = 0;
  local_2c = 0xf;
  local_40[0] = 0;
  local_48 = 0;
  local_44 = 0xf;
  local_58[0] = 0;
  local_8 = 1;
  uVar10 = 0x506a63;
  cVar1 = FUN_005068b0(local_40,local_58,1000);
  if (cVar1 != '\0') {
    iVar3 = FUN_00506230("looperpro1",0);
    if (iVar3 == -1) {
      iVar3 = FUN_00506230("Cuvave-IR",0);
      if (iVar3 == -1) {
        uVar13 = 0;
        pcVar12 = "LooperMini_";
        uVar11 = 0x506ace;
        iVar3 = FUN_00506230("LooperMini_",0);
        if (iVar3 == -1) {
          uVar13 = 0;
          pcVar12 = "LPCBA_";
          uVar11 = 0x506ae6;
          iVar3 = FUN_00506230("LPCBA_",0);
          if (iVar3 != -1) goto LAB_00506f52;
          uVar13 = 0;
          pcVar12 = "LooperPro_";
          uVar11 = 0x506afe;
          iVar3 = FUN_00506230("LooperPro_",0);
          if (iVar3 == -1) {
            uVar13 = 0;
            pcVar12 = "LooperPlus_";
            uVar11 = 0x506b2f;
            iVar3 = FUN_00506230("LooperPlus_",0);
            if (iVar3 == -1) {
              uVar13 = 0;
              pcVar12 = "LooperProX_";
              uVar11 = 0x506b60;
              iVar3 = FUN_00506230("LooperProX_",0);
              if (iVar3 == -1) {
                uVar13 = 0;
                pcVar12 = "LooperAutoX_";
                uVar11 = 0x506b91;
                iVar3 = FUN_00506230("LooperAutoX_",0);
                if (iVar3 == -1) {
                  uVar13 = 0;
                  pcVar12 = "LooperAuto_";
                  uVar11 = 0x506bc2;
                  iVar3 = FUN_00506230("LooperAuto_",0);
                  if (iVar3 == -1) {
                    uVar13 = 0;
                    pcVar12 = "LooperDrum_";
                    uVar11 = 0x506bf3;
                    iVar3 = FUN_00506230("LooperDrum_",0);
                    if (iVar3 == -1) {
                      uVar13 = 0;
                      pcVar12 = "LooperDrumX2_";
                      uVar11 = 0x506c0b;
                      iVar3 = FUN_00506230("LooperDrumX2_",0);
                      if (iVar3 == -1) {
                        uVar13 = 0;
                        pcVar12 = "LooperDrumX_";
                        uVar11 = 0x506c23;
                        iVar3 = FUN_00506230("LooperDrumX_",0);
                        if (iVar3 == -1) {
                          uVar13 = 0;
                          pcVar12 = "DrumBuddy_";
                          uVar11 = 0x506c3b;
                          iVar3 = FUN_00506230("DrumBuddy_",0);
                          if (iVar3 == -1) {
                            uVar13 = 0;
                            pcVar12 = "LooperDrumV2_";
                            uVar11 = 0x506c53;
                            iVar3 = FUN_00506230("LooperDrumV2_",0);
                            if (iVar3 == -1) {
                              uVar13 = 0;
                              pcVar12 = "DrumBuddyV2_";
                              uVar11 = 0x506c6b;
                              iVar3 = FUN_00506230("DrumBuddyV2_",0);
                              if (iVar3 == -1) {
                                uVar13 = 0;
                                pcVar12 = "DLP-1";
                                uVar11 = 0x506c83;
                                iVar3 = FUN_00506230("DLP-1",0);
                                if (iVar3 == -1) {
                                  uVar13 = 0;
                                  pcVar12 = "IR-BOX";
                                  uVar11 = 0x506c9b;
                                  iVar3 = FUN_00506230("IR-BOX",0);
                                  if (iVar3 == -1) {
                                    uVar13 = 0;
                                    pcVar12 = "Micphone";
                                    uVar11 = 0x506ccc;
                                    iVar3 = FUN_00506230("Micphone",0);
                                    if (iVar3 == -1) {
                                      uVar13 = 0;
                                      pcVar12 = "IRCAB_";
                                      uVar11 = 0x506cfd;
                                      iVar3 = FUN_00506230("IRCAB_",0);
                                      if (iVar3 == -1) {
                                        QString::fromStdString(local_64);
                                        local_8._0_1_ = 2;
                                        local_68 = QString::fromAscii_helper("[\\x00-\\x1F]",0xb);
                                        local_8._0_1_ = 3;
                                        pQVar4 = (QRegularExpression *)
                                                 QRegularExpression::QRegularExpression
                                                           (local_60,&local_68,0);
                                        local_8._0_1_ = 4;
                                        pQVar5 = QString::remove((QString *)local_64,pQVar4);
                                        QString::operator=((QString *)local_64,pQVar5);
                                        QRegularExpression::~QRegularExpression(local_60);
                                        local_8._0_1_ = 2;
                                        QString::~QString((QString *)&local_68);
                                        local_68 = QString::fromAscii_helper("_",1);
                                        local_8._0_1_ = 5;
                                        QString::split((QString *)local_64,&local_5c,&local_68,0,1);
                                        local_8 = CONCAT31(local_8._1_3_,7);
                                        QString::~QString((QString *)&local_68);
                                        uVar2 = 0;
                                        pQVar5 = (QString *)&DAT_00765ad8;
                                        do {
                                          if ((*local_5c != 1) && (*local_5c != 0)) {
                                            FUN_004875a0(local_5c[1]);
                                          }
                                          this = (QString *)QListData::at((QListData *)&local_5c,0);
                                          iVar3 = QString::compare(this,pQVar5,0);
                                          if (iVar3 == 0) {
                                            *(undefined4 *)(param_1 + 0x2caa0) = 1;
                                            pQVar5 = (QString *)FUN_00506030(0);
                                            QString::operator=((QString *)(param_1 + 0x2ca90),pQVar5
                                                              );
                                            iVar3 = QListData::size((QListData *)&local_5c);
                                            if (iVar3 < 3) {
                                              QString::operator=((QString *)(param_1 + 0x2ca94),
                                                                 "unknow");
                                            }
                                            else {
                                              pQVar5 = (QString *)FUN_00506030(1);
                                              QString::operator=((QString *)(param_1 + 0x2ca94),
                                                                 pQVar5);
                                            }
                                            QString::operator=((QString *)(param_1 + 0x2ca98),
                                                               (QString *)
                                                               (&DAT_00765ae0 + uVar2 * 0x10));
                                            DAT_00756ac8 = (&DAT_00765ae4)[uVar2 * 4];
                                            *(undefined4 *)(param_1 + 0x2ca9c) = DAT_00756ac8;
                                            DAT_00756acc = DAT_00756ac8;
                                            FUN_00486b10();
                                            QString::~QString((QString *)local_64);
                                            if (local_44 < 0x10) goto LAB_00506f00;
                                            uVar2 = local_44 + 1;
                                            iVar3 = local_58[0];
                                            if (uVar2 < 0x1000) goto LAB_00506ef6;
                                            iVar3 = *(int *)(local_58[0] + -4);
                                            iVar6 = local_58[0] - iVar3;
                                            goto joined_r0x00506ef4;
                                          }
                                          uVar2 = uVar2 + 1;
                                          pQVar5 = pQVar5 + 0x10;
                                        } while (uVar2 < 0x10);
                                        *(undefined4 *)(param_1 + 0x2ca8c) = 0x2100;
                                        FUN_005071f0();
                                        FUN_00486b10();
                                        local_8 = CONCAT31(local_8._1_3_,1);
                                        QString::~QString((QString *)local_64);
                                        goto LAB_00506f71;
                                      }
                                      FUN_00489eb0(local_40);
                                      uVar9 = 0x400;
                                      uVar8 = 0x2a4b;
                                    }
                                    else {
                                      FUN_00489eb0(local_40);
                                      uVar9 = 0x400;
                                      uVar8 = 0x2a4d;
                                    }
                                  }
                                  else {
                                    FUN_00489eb0(local_40);
                                    uVar9 = 0x400;
                                    uVar8 = 0x29e5;
                                  }
                                  goto LAB_00506f6a;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                    FUN_00489eb0(local_40);
                    uVar9 = 0x400;
                    uVar8 = 0x2982;
                  }
                  else {
                    FUN_00489eb0(local_40);
                    uVar9 = 0x400;
                    uVar8 = 0x2981;
                  }
                }
                else {
                  FUN_00489eb0(local_40);
                  uVar9 = 0x100f;
                  uVar8 = 0x291f;
                }
              }
              else {
                FUN_00489eb0(local_40);
                uVar9 = 0x100f;
                uVar8 = 0x291e;
              }
            }
            else {
              FUN_00489eb0(local_40);
              uVar9 = 0x400;
              uVar8 = 0x2921;
            }
          }
          else {
            FUN_00489eb0(local_40);
            uVar9 = 0x400;
            uVar8 = 0x291d;
          }
        }
        else {
LAB_00506f52:
          FUN_00489eb0(local_40);
          uVar9 = 0x400;
          uVar8 = 0x28b9;
        }
LAB_00506f6a:
        FUN_005073f0(uVar8,uVar9,in_stack_ffffff68,in_stack_ffffff6c,uVar10,uVar11,pcVar12,uVar13);
      }
      else {
        *(undefined4 *)(param_1 + 0x2ca8c) = 0x180;
        FUN_005071f0(uVar2);
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x2ca8c) = 0x4180;
      FUN_005071f0(uVar2);
    }
LAB_00506f71:
    cVar1 = FUN_00507de0(0x12);
    if ((cVar1 != '\0') && (cVar1 = FUN_00507aa0(0x12,local_28,0xd,local_70,200,1), cVar1 != '\0'))
    {
      *(uint *)(param_1 + 0x2caa4) = (uint)(local_22 == '\0');
      if (0xf < local_44) {
        uVar2 = local_44 + 1;
        iVar3 = local_58[0];
        if (0xfff < uVar2) {
          iVar3 = *(int *)(local_58[0] + -4);
          iVar6 = local_58[0] - iVar3;
joined_r0x00506ef4:
          uVar2 = local_44 + 0x24;
          if (0x1f < iVar6 - 4U) goto LAB_00506f32;
        }
LAB_00506ef6:
        FUN_00519359(iVar3,uVar2);
      }
LAB_00506f00:
      if (0xf < local_2c) {
        uVar7 = local_2c + 1;
        uVar2 = local_40[0];
        if (0xfff < uVar7) {
          uVar2 = *(uint *)(local_40[0] - 4);
          uVar7 = local_2c + 0x24;
          if (0x1f < (local_40[0] - uVar2) - 4) goto LAB_00506f32;
        }
        FUN_00519359(uVar2,uVar7);
      }
      ExceptionList = local_10;
      return 1;
    }
  }
  local_8 = local_8 & 0xffffff00;
  if (0xf < local_44) {
    uVar2 = local_44 + 1;
    iVar3 = local_58[0];
    if (0xfff < uVar2) {
      iVar3 = *(int *)(local_58[0] + -4);
      uVar2 = local_44 + 0x24;
      if (0x1f < (local_58[0] - iVar3) - 4U) goto LAB_00506f32;
    }
    FUN_00519359(iVar3,uVar2);
  }
  local_8 = 0xffffffff;
  if (0xf < local_2c) {
    uVar7 = local_2c + 1;
    uVar2 = local_40[0];
    if (0xfff < uVar7) {
      uVar2 = *(uint *)(local_40[0] - 4);
      uVar7 = local_2c + 0x24;
      if (0x1f < (local_40[0] - uVar2) - 4) {
LAB_00506f32:
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
    FUN_00519359(uVar2,uVar7);
  }
  local_30 = 0;
  local_2c = 0xf;
  local_40[0] = local_40[0] & 0xffffff00;
LAB_00507077:
  FUN_00508160();
  ExceptionList = local_10;
  return 0;
}


