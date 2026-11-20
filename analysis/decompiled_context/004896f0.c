
int * FUN_004896f0(int *param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  bool bVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  __int64 _Var12;
  undefined8 local_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0052263d;
  local_10 = ExceptionList;
  uVar4 = DAT_00759b24 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  iVar9 = 0;
  pcVar7 = param_2;
  do {
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  uVar8 = (int)pcVar7 - (int)(param_2 + 1);
  iVar11 = *(int *)(*(int *)(*param_1 + 4) + 0x24 + (int)param_1);
  uVar2 = *(uint *)(*(int *)(*param_1 + 4) + 0x20 + (int)param_1);
  if ((iVar11 < 0) ||
     ((iVar11 < 1 && (((uVar2 == 0 || (iVar11 < 0)) || ((iVar11 < 1 && (uVar2 <= uVar8)))))))) {
    local_24 = 0;
    local_24._4_4_ = 0;
    local_24._0_4_ = (basic_ostream<char,std::char_traits<char>_> *)0x0;
    iVar10 = (int)(basic_ostream<char,std::char_traits<char>_> *)local_24;
    iVar11 = local_24._4_4_;
  }
  else {
    iVar10 = uVar2 - uVar8;
    iVar11 = iVar11 - (uint)(uVar2 < uVar8);
  }
  FUN_0048ab80(param_1);
  local_8 = 0;
  if (local_24._4_1_ == '\0') {
    piVar5 = (int *)FUN_0048986d();
    return piVar5;
  }
  local_8 = 1;
  if ((*(uint *)(*(int *)(*param_1 + 4) + 0x14 + (int)param_1) & 0x1c0) != 0x40) {
    for (; (-1 < iVar11 && ((0 < iVar11 || (iVar10 != 0)))); iVar10 = iVar10 + -1) {
      iVar6 = std::basic_streambuf<char,std::char_traits<char>_>::sputc
                        (*(basic_streambuf<char,std::char_traits<char>_> **)
                          (*(int *)(*param_1 + 4) + 0x38 + (int)param_1),
                         *(char *)(*(int *)(*param_1 + 4) + 0x40 + (int)param_1));
      if (iVar6 == -1) {
        iVar9 = 4;
        goto LAB_00489828;
      }
      iVar11 = iVar11 + -1 + (uint)(iVar10 != 0);
    }
  }
  _Var12 = std::basic_streambuf<char,std::char_traits<char>_>::sputn
                     (*(basic_streambuf<char,std::char_traits<char>_> **)
                       (*(int *)(*param_1 + 4) + 0x38 + (int)param_1),param_2,
                      (ulonglong)uVar4 << 0x20);
  if (((uint)_Var12 == uVar8) && ((int)((ulonglong)_Var12 >> 0x20) == 0)) {
    for (; (-1 < iVar11 && ((0 < iVar11 || (iVar10 != 0)))); iVar10 = iVar10 + -1) {
      iVar6 = std::basic_streambuf<char,std::char_traits<char>_>::sputc
                        (*(basic_streambuf<char,std::char_traits<char>_> **)
                          (*(int *)(*param_1 + 4) + 0x38 + (int)param_1),
                         *(char *)(*(int *)(*param_1 + 4) + 0x40 + (int)param_1));
      if (iVar6 == -1) goto LAB_00489825;
      iVar11 = iVar11 + -1 + (uint)(iVar10 != 0);
    }
  }
  else {
LAB_00489825:
    iVar9 = 4;
  }
LAB_00489828:
  local_8 = 0;
  iVar11 = *(int *)(*param_1 + 4);
  *(undefined4 *)(iVar11 + 0x20 + (int)param_1) = 0;
  *(undefined4 *)(iVar11 + 0x24 + (int)param_1) = 0;
  std::basic_ios<char,std::char_traits<char>_>::setstate
            ((basic_ios<char,std::char_traits<char>_> *)(*(int *)(*param_1 + 4) + (int)param_1),
             iVar9,false);
  local_8 = 3;
  bVar3 = std::uncaught_exception();
  if (!bVar3) {
    std::basic_ostream<char,std::char_traits<char>_>::_Osfx
              ((basic_ostream<char,std::char_traits<char>_> *)local_24);
  }
  local_8 = CONCAT31(local_8._1_3_,4);
  if (*(int **)((basic_ostream<char,std::char_traits<char>_> *)local_24 +
               *(int *)(*(int *)(basic_ostream<char,std::char_traits<char>_> *)local_24 + 4) + 0x38)
      != (int *)0x0) {
    (**(code **)(**(int **)((basic_ostream<char,std::char_traits<char>_> *)local_24 +
                           *(int *)(*(int *)(basic_ostream<char,std::char_traits<char>_> *)local_24
                                   + 4) + 0x38) + 8))();
  }
  ExceptionList = local_10;
  return param_1;
}


