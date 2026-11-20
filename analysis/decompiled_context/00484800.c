
void * FUN_00484800(uint param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  if (param_1 < 0x1000) {
    if (param_1 == 0) {
      return (void *)0x0;
    }
    pvVar1 = operator_new(param_1);
    return pvVar1;
  }
  if (param_1 + 0x23 <= param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_004847e0();
  }
  pvVar1 = operator_new(param_1 + 0x23);
  if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  pvVar2 = (void *)((int)pvVar1 + 0x23U & 0xffffffe0);
  *(void **)((int)pvVar2 - 4) = pvVar1;
  return pvVar2;
}


