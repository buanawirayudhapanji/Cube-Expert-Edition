
void __fastcall FUN_004e1420(QObject *param_1)

{
  code *pcVar1;
  uint uVar2;
  uintptr_t *puVar3;
  undefined4 *_ArgList;
  uintptr_t uVar4;
  int iVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0054014c;
  local_10 = ExceptionList;
  uVar2 = DAT_00759b24 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  param_1[0x34] = (QObject)0x0;
  puVar3 = operator_new(8);
  local_8 = 0;
  _ArgList = operator_new(0xc);
  *_ArgList = param_1 + 0x34;
  _ArgList[1] = &DAT_007628ac;
  _ArgList[2] = FUN_004e10e0;
  local_8 = CONCAT31(local_8._1_3_,1);
  uVar4 = _beginthreadex((void *)0x0,0,FUN_004e1060,_ArgList,0,puVar3 + 1);
  *puVar3 = uVar4;
  if (uVar4 == 0) {
    puVar3[1] = 0;
    std::_Throw_Cpp_error(6);
    pcVar1 = (code *)swi(3);
    (*pcVar1)(uVar2);
    return;
  }
  local_8 = 0xffffffff;
  *(uintptr_t **)(param_1 + 0x2c) = puVar3;
  iVar5 = QObject::startTimer(param_1,1000,1);
  *(int *)(param_1 + 0x38) = iVar5;
  ExceptionList = local_10;
  return;
}


