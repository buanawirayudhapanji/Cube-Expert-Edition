
void FUN_00501bb0(undefined4 *param_1,undefined4 *param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  uint *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *_Src;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *local_1c;
  undefined4 *local_18;
  int local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  _Src = param_1;
  if (0x100 < (int)((int)param_2 - (int)param_1 & 0xfffffff8U)) {
    do {
      if (param_3 < 1) {
        uVar6 = (int)param_2 - (int)_Src;
        local_8 = (int)uVar6 >> 3;
        iVar8 = (int)uVar6 >> 4;
        if (0 < iVar8) {
          local_14 = local_8 - 1;
          iVar5 = local_14 >> 1;
          do {
            uVar3 = _Src[iVar8 * 2 + -2];
            iVar8 = iVar8 + -1;
            local_c = _Src[iVar8 * 2 + 1];
            iVar9 = iVar8;
            iVar10 = iVar8;
            if (iVar8 < iVar5) {
              do {
                iVar9 = (2 - (uint)((uint)_Src[iVar10 * 4 + 5] < (uint)_Src[iVar10 * 4 + 3])) +
                        iVar10 * 2;
                uVar4 = _Src[iVar9 * 2 + 1];
                _Src[iVar10 * 2] = _Src[iVar9 * 2];
                _Src[iVar10 * 2 + 1] = uVar4;
                iVar10 = iVar9;
              } while (iVar9 < iVar5);
            }
            if ((iVar9 == iVar5) && ((local_8 & 1) == 0)) {
              uVar4 = _Src[local_8 * 2 + -1];
              _Src[iVar9 * 2] = _Src[local_8 * 2 + -2];
              _Src[iVar9 * 2 + 1] = uVar4;
              iVar9 = local_14;
            }
            while ((iVar8 < iVar9 &&
                   (iVar10 = iVar9 + -1 >> 1, (uint)_Src[iVar10 * 2 + 1] < local_c))) {
              uVar4 = _Src[iVar10 * 2 + 1];
              _Src[iVar9 * 2] = _Src[iVar10 * 2];
              _Src[iVar9 * 2 + 1] = uVar4;
              iVar9 = iVar10;
            }
            _Src[iVar9 * 2] = uVar3;
            _Src[iVar9 * 2 + 1] = local_c;
            local_10 = iVar8;
          } while (0 < iVar8);
        }
        if ((int)local_8 < 2) {
          return;
        }
        do {
          local_1c = *(undefined4 **)((uVar6 - 8) + (int)_Src);
          uVar1 = uVar6 - 8;
          local_18 = *(undefined4 **)((uVar6 - 4) + (int)_Src);
          uVar3 = _Src[1];
          *(undefined4 *)((uVar6 - 8) + (int)_Src) = *_Src;
          *(undefined4 *)((uVar6 - 4) + (int)_Src) = uVar3;
          FUN_00501b00(_Src,0,(int)uVar1 >> 3,&local_1c,param_4);
          uVar6 = uVar1;
        } while (0xf < (int)(uVar1 & 0xfffffff8));
        return;
      }
      FUN_00501890(&local_1c,_Src,param_2,param_4);
      puVar7 = local_18;
      param_3 = (param_3 >> 1) + (param_3 >> 2);
      if ((int)((int)local_1c - (int)_Src & 0xfffffff8U) <
          (int)((int)param_2 - (int)local_18 & 0xfffffff8U)) {
        FUN_00501bb0(_Src,local_1c,param_3,param_4);
        param_1 = puVar7;
        _Src = puVar7;
      }
      else {
        FUN_00501bb0(local_18,param_2,param_3,param_4);
        param_2 = local_1c;
      }
    } while (0x100 < (int)((int)param_2 - (int)_Src & 0xfffffff8U));
  }
  if ((_Src != param_2) && (puVar7 = _Src + 2, puVar7 != param_2)) {
    local_18 = (undefined4 *)(8 - (int)_Src);
    do {
      local_c = *puVar7;
      local_8 = puVar7[1];
      if (local_8 < (uint)_Src[1]) {
        memmove(_Src + 2,_Src,(int)local_18 + -8 + (int)puVar7);
        *_Src = local_c;
        _Src[1] = local_8;
      }
      else {
        puVar11 = puVar7;
        puVar12 = puVar7;
        if (local_8 < (uint)puVar7[-1]) {
          do {
            puVar12 = puVar11 + -2;
            *puVar11 = *puVar12;
            puVar11[1] = puVar11[-1];
            puVar2 = puVar11 + -3;
            puVar11 = puVar12;
          } while (local_8 < *puVar2);
          _Src = param_1;
        }
        *puVar12 = local_c;
        puVar12[1] = local_8;
      }
      puVar7 = puVar7 + 2;
    } while (puVar7 != param_2);
  }
  return;
}


