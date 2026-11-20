
/* Library Function - Single Match
    void * __cdecl operator new(unsigned int)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void * __cdecl operator_new(uint param_1)

{
  int iVar1;
  void *pvVar2;
  undefined1 auStack_14 [8];
  undefined4 uStack_c;
  
  do {
    uStack_c = 0x519343;
    pvVar2 = malloc(param_1);
    if (pvVar2 != (void *)0x0) {
      return pvVar2;
    }
    uStack_c = 0x519336;
    iVar1 = _callnewh(param_1);
  } while (iVar1 != 0);
  if (param_1 == 0xffffffff) {
    FUN_00483ac0();
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(auStack_14,(ThrowInfo *)&DAT_006ffcec);
  }
  pvVar2 = (void *)FUN_0051a0dc();
  return pvVar2;
}


