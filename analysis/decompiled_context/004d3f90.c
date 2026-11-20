
void FUN_004d3f90(int param_1,int param_2)

{
  undefined4 uVar1;
  QTypedArrayData<unsigned_short> *pQVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0053ac0f;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 == 0) {
    if (param_2 != 0) {
      FUN_00519359();
    }
  }
  else if (param_1 == 1) {
    uVar1 = FUN_00519367();
    QString::fromAscii_helper("Restore Complete",0x10);
    local_8 = 0;
    QString::fromAscii_helper(&DAT_0058cebc,0x31);
    uVar3 = 0x40000;
    local_8 = CONCAT31(local_8._1_3_,2);
    pQVar2 = QString::fromAscii_helper("BOR",3);
    local_8 = 0xffffffff;
    FUN_004d3320(pQVar2,uVar1,uVar3);
    ExceptionList = local_10;
    return;
  }
  ExceptionList = local_10;
  return;
}


