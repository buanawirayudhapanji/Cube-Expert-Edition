
char * __thiscall FUN_00511a50(int *param_1,char *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  QTypedArrayData<unsigned_short> *pQVar4;
  uint uVar5;
  
  iVar3 = FUN_00488eb0(*(undefined4 *)(param_1[0xfe] + 0x2ca68));
  if (iVar3 == 0) {
    pQVar4 = QString::fromAscii_helper("",0);
    *(QTypedArrayData<unsigned_short> **)param_2 = pQVar4;
    return param_2;
  }
  iVar3 = *(int *)(iVar3 + 0x44);
  uVar1 = *(uint *)(iVar3 + 0x24);
  iVar2 = *(int *)(iVar3 + 0x20);
  iVar3 = *(int *)(iVar3 + 0x1c);
  uVar5 = (**(code **)(**(int **)(*param_1 + param_3 * 4) + 4))();
  uVar5 = uVar5 / ((uVar1 >> 3) * iVar2 * iVar3);
  QString::asprintf(param_2,"Song %.3d -- %.2d:%.2d",param_3 + 1,uVar5 / 0x3c,uVar5 % 0x3c);
  return param_2;
}


