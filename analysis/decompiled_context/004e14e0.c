
longlong * FUN_004e14e0(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  lVar1 = _Query_perf_frequency();
  lVar2 = _Query_perf_counter();
  if (lVar1 == 10000000) {
    *param_1 = lVar2 * 100;
    return param_1;
  }
  uVar3 = __allrem(lVar2,lVar1);
  uVar3 = __allmul(uVar3,1000000000,0);
  lVar4 = __alldiv(uVar3,lVar1);
  uVar5 = __alldiv(lVar2,lVar1);
  lVar1 = (uVar5 & 0xffffffff) * 1000000000;
  *param_1 = lVar4 + CONCAT44((int)(uVar5 >> 0x20) * 1000000000 + (int)((ulonglong)lVar1 >> 0x20),
                              (int)lVar1);
  return param_1;
}


