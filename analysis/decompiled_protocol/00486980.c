
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00486980(undefined1 *param_1,int param_2,uint param_3)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  uint *unaff_FS_OFFSET;
  uint uStack_1c;
  uint uStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &UNK_0051c720;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (uint)&uStack_10;
  if ((*(int **)(param_1 + 0xc818) == (int *)0x0) ||
     (cVar1 = (**(code **)(**(int **)(param_1 + 0xc818) + 0x14))(), cVar1 == '\0')) {
    *unaff_FS_OFFSET = uStack_10;
    return 0;
  }
  *param_1 = 0xf0;
  pbVar5 = param_1 + 1;
  uStack_8 = 0;
  if (*(int *)(param_1 + 0xc814) == 0) {
    func_0x0051a5a0(pbVar5,param_2,param_3);
    pbVar5 = pbVar5 + param_3;
  }
  else {
    uVar6 = 0;
    uVar4 = 0;
    uStack_1c = 0;
    if (param_3 != 0) {
      do {
        bVar2 = (byte)uVar6;
        uVar6 = uVar6 + 8;
        uVar4 = uVar4 | (uint)*(byte *)(uStack_1c + param_2) << (bVar2 & 0x1f);
        if (6 < (int)uVar6) {
          uVar3 = uVar6 / 7;
          uVar6 = uVar6 % 7;
          do {
            bVar2 = (byte)uVar4;
            uVar4 = uVar4 >> 7;
            *pbVar5 = bVar2 & 0x7f;
            pbVar5 = pbVar5 + 1;
            uVar3 = uVar3 - 1;
          } while (uVar3 != 0);
        }
        uStack_1c = uStack_1c + 1;
      } while (uStack_1c < param_3);
      if (uVar6 != 0) {
        *pbVar5 = (byte)uVar4 & 0x7f;
        pbVar5 = pbVar5 + 1;
      }
    }
  }
  *pbVar5 = 0xf7;
  (**(code **)(**(int **)(*(int *)(param_1 + 0xc818) + 4) + 0x20))
            (param_1,pbVar5 + (1 - (int)param_1));
  *unaff_FS_OFFSET = uStack_10;
  return 1;
}


