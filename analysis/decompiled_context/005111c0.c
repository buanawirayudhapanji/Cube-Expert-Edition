
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_005111c0(undefined4 *param_1)

{
  char cVar1;
  size_t _Size;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  void *_Dst;
  uint uVar7;
  QMessageLogger *this;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  uint in_stack_00000014;
  uint in_stack_00000018;
  undefined4 in_stack_0000001c;
  int *in_stack_00000020;
  undefined4 in_stack_ffffff80;
  void *in_stack_ffffff84;
  char *in_stack_ffffff88;
  undefined4 ****local_3c;
  undefined4 ****local_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  uint local_1c;
  uint uStack_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar2 = in_stack_00000020;
  puStack_c = &LAB_0055dadd;
  local_10 = ExceptionList;
  local_14 = DAT_00759b24 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  local_8 = 0;
  pcVar3 = (char *)FUN_0048e870(&DAT_00594130,0);
  pcVar8 = pcVar3;
  do {
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_004873d0(pcVar3,(int)pcVar8 - (int)(pcVar3 + 1));
  FUN_005070a0(0x2f);
  iVar4 = FUN_0048eb30(&DAT_00594138);
  while( true ) {
    if (iVar4 == 0) {
      iVar4 = FUN_0048eb30(&DAT_0059412c);
      uVar9 = in_stack_00000014;
      while (in_stack_00000014 = uVar9, iVar4 != 0) {
        puVar5 = &param_1;
        if (0xf < in_stack_00000018) {
          puVar5 = param_1;
        }
        piVar6 = piVar2;
        if (uVar9 < 0x10) {
          _Dst = (void *)*puVar5;
          in_stack_ffffff80 = puVar5[1];
          in_stack_ffffff84 = (void *)puVar5[2];
          in_stack_ffffff88 = (char *)puVar5[3];
          uVar10 = 0xf;
        }
        else {
          uVar10 = uVar9 | 0xf;
          if (0x7fffffff < uVar10) {
            uVar10 = 0x7fffffff;
          }
          _Dst = (void *)FUN_00484800(uVar10 + 1);
          memcpy(_Dst,puVar5,uVar9 + 1);
        }
        FUN_005111c0(_Dst,in_stack_ffffff80,in_stack_ffffff84,in_stack_ffffff88,uVar9,uVar10,iVar4,
                     piVar6);
        iVar4 = FUN_0048f3b0(&DAT_0059412c);
        uVar9 = in_stack_00000014;
      }
      if (0xf < in_stack_00000018) {
        uVar9 = in_stack_00000018 + 1;
        puVar5 = param_1;
        if (0xfff < uVar9) {
          puVar5 = (undefined4 *)param_1[-1];
          uVar9 = in_stack_00000018 + 0x24;
          if (0x1f < (uint)((int)param_1 + (-4 - (int)puVar5))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
        }
        FUN_00519359(puVar5,uVar9);
      }
      ExceptionList = local_10;
      return;
    }
    in_stack_ffffff88 = (char *)FUN_0048f010();
    _Size = in_stack_00000014;
    pcVar8 = in_stack_ffffff88;
    do {
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    uVar9 = (int)pcVar8 - (int)(in_stack_ffffff88 + 1);
    if (0x7fffffff - in_stack_00000014 < uVar9) break;
    uVar10 = 0xf;
    local_2c = (undefined4 ****)0x0;
    puVar5 = &param_1;
    if (0xf < in_stack_00000018) {
      puVar5 = param_1;
    }
    uVar7 = in_stack_00000014 + uVar9;
    local_3c = &local_2c;
    if (0xf < uVar7) {
      uVar10 = uVar7;
      if (uVar7 < 0x10) {
        uVar10 = 0x10;
      }
      uVar10 = uVar10 | 0xf;
      if (uVar10 < 0x80000000) {
        if (uVar10 < 0x16) {
          uVar10 = 0x16;
        }
      }
      else {
        uVar10 = 0x7fffffff;
      }
      local_3c = (undefined4 ****)FUN_00484800(uVar10 + 1);
      local_2c = local_3c;
    }
    local_1c = uVar7;
    uStack_18 = uVar10;
    memcpy(local_3c,puVar5,_Size);
    in_stack_ffffff84 = (void *)(_Size + (int)local_3c);
    in_stack_ffffff80 = 0x511304;
    memcpy(in_stack_ffffff84,in_stack_ffffff88,uVar9);
    *(undefined1 *)((int)local_3c + uVar7) = 0;
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar4 = *piVar2;
    if (piVar2[1] == 0x7ffffff) {
                    /* WARNING: Subroutine does not return */
      std::_Xlength_error("list too long");
    }
    local_8._0_1_ = 2;
    piVar6 = operator_new(0x20);
    local_8 = (uint)local_8._1_3_ << 8;
    piVar6[6] = 0;
    piVar6[7] = 0;
    piVar6[2] = (int)local_2c;
    piVar6[3] = iStack_28;
    piVar6[4] = iStack_24;
    piVar6[5] = iStack_20;
    piVar6[6] = local_1c;
    piVar6[7] = uStack_18;
    piVar2[1] = piVar2[1] + 1;
    puVar5 = *(undefined4 **)(iVar4 + 4);
    *piVar6 = iVar4;
    piVar6[1] = (int)puVar5;
    *(int **)(iVar4 + 4) = piVar6;
    *puVar5 = piVar6;
    pcVar8 = (char *)QMessageLogger::QMessageLogger
                               ((QMessageLogger *)&iStack_28,(char *)0x0,0,(char *)0x0);
    this = (QMessageLogger *)(*(int *)(*piVar2 + 4) + 8);
    if (0xf < *(uint *)(*(int *)(*piVar2 + 4) + 0x1c)) {
      this = *(QMessageLogger **)this;
    }
    QMessageLogger::debug(this,pcVar8,this);
    iVar4 = FUN_0048f3b0(&DAT_00594138);
  }
                    /* WARNING: Subroutine does not return */
  FUN_004866c0();
}


