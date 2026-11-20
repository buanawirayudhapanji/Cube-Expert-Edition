
QDialog * __thiscall FUN_005182c0(QDialog *param_1,byte *param_2)

{
  byte bVar1;
  char *pcVar2;
  uint uVar3;
  QDialog *pQVar4;
  byte *pbVar5;
  bool bVar6;
  
  if (param_2 == (byte *)0x0) {
    return (QDialog *)0x0;
  }
  pcVar2 = s_BaseDialog_007598dc;
  pbVar5 = param_2;
  do {
    bVar1 = *pbVar5;
    bVar6 = bVar1 < (byte)*pcVar2;
    if (bVar1 != *pcVar2) {
LAB_00518300:
      uVar3 = -(uint)bVar6 | 1;
      goto LAB_00518305;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar5[1];
    bVar6 = bVar1 < (byte)pcVar2[1];
    if (bVar1 != pcVar2[1]) goto LAB_00518300;
    pbVar5 = pbVar5 + 2;
    pcVar2 = pcVar2 + 2;
  } while (bVar1 != 0);
  uVar3 = 0;
LAB_00518305:
  if (uVar3 == 0) {
    return param_1;
  }
  pQVar4 = QDialog::qt_metacast(param_1,(char *)param_2);
  return pQVar4;
}


