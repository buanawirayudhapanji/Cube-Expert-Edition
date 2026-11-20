
void FUN_0050da10(QArrayData *param_1)

{
  int iVar1;
  int iVar2;
  QArrayData *pQVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(param_1 + 0xc);
  for (pQVar3 = param_1 + iVar2; pQVar3 != param_1 + iVar1 * 0x34 + iVar2; pQVar3 = pQVar3 + 0x34) {
    QString::~QString((QString *)(pQVar3 + 0x10));
  }
  QArrayData::deallocate(param_1,0x34,4);
  return;
}


