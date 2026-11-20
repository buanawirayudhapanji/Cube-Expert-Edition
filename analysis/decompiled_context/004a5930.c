
void __thiscall
FUN_004a5930(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4,int *param_5)

{
  int *piVar1;
  uint uVar2;
  int *_Memory;
  char cVar3;
  uint uVar4;
  int *piVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  uVar2 = (uint)param_5;
  piVar5 = param_4;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00527229;
  local_10 = ExceptionList;
  uVar4 = DAT_00759b24 ^ (int)register0x00000010 - 4U;
  ExceptionList = &local_10;
  cVar3 = FUN_00506590(param_2,param_3,param_4,param_5,param_1);
  if (cVar3 == '\0') {
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f8c14,(char *)&param_2,"Write data failed !",0);
    local_8 = 3;
    FUN_00486bb0(&param_2,uVar4);
    QString::~QString((QString *)&param_2);
    ExceptionList = local_10;
    return;
  }
  param_5 = (int *)FUN_00519367(uVar2);
  cVar3 = FUN_005063f0(param_2,param_3,param_5,uVar2,param_1);
  _Memory = param_5;
  piVar1 = param_5;
  if (cVar3 == '\0') {
    QMetaObject::tr((QMetaObject *)&PTR_DAT_006f8c14,(char *)&param_3,"Read verify data failed !",0)
    ;
    local_8 = 2;
    FUN_00486bb0(&param_3,uVar4);
    QString::~QString((QString *)&param_3);
    free(param_5);
    ExceptionList = local_10;
    return;
  }
  while (uVar4 = uVar2 - 4, 3 < uVar2) {
    if (*piVar5 != *piVar1) goto LAB_004a59c0;
    piVar5 = piVar5 + 1;
    piVar1 = piVar1 + 1;
    uVar2 = uVar4;
  }
  if (uVar4 != 0xfffffffc) {
LAB_004a59c0:
    if (((char)*piVar5 != (char)*piVar1) ||
       ((uVar4 != 0xfffffffd &&
        ((*(char *)((int)piVar5 + 1) != *(char *)((int)piVar1 + 1) ||
         ((uVar4 != 0xfffffffe &&
          ((*(char *)((int)piVar5 + 2) != *(char *)((int)piVar1 + 2) ||
           ((uVar4 != 0xffffffff && (*(char *)((int)piVar5 + 3) != *(char *)((int)piVar1 + 3))))))))
         ))))) {
      QMetaObject::tr((QMetaObject *)&PTR_DAT_006f8c14,(char *)&param_3,"Verify data failed !",0);
      local_8 = 1;
      goto LAB_004a5a0c;
    }
  }
  QMetaObject::tr((QMetaObject *)&PTR_DAT_006f8c14,(char *)&param_3,"Successful!",0);
  local_8 = 0;
LAB_004a5a0c:
  FUN_00486bb0(&param_3);
  QString::~QString((QString *)&param_3);
  free(_Memory);
  ExceptionList = local_10;
  return;
}


