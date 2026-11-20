
void __fastcall FUN_004b3db0(int param_1)

{
  byte bVar1;
  QLabel *pQVar2;
  QAbstractButton *pQVar3;
  QString *pQVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  QString local_24 [4];
  undefined4 local_20;
  QComboBox *local_1c;
  int local_18;
  byte local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00531368;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_20 = 0;
  local_18 = param_1;
  QAbstractButton::setChecked
            (*(QAbstractButton **)(param_1 + 0xa04),*(char *)(param_1 + 0x6692) != '\0');
  QAbstractButton::setChecked
            (*(QAbstractButton **)(param_1 + 0xa10),*(char *)(param_1 + 0x6693) != '\0');
  QAbstractButton::setChecked
            (*(QAbstractButton **)(param_1 + 0xa34),*(char *)(param_1 + 0x6694) != '\0');
  pQVar3 = QButtonGroup::button
                     (*(QButtonGroup **)(param_1 + 0x858),(uint)(*(char *)(param_1 + 0xa39) != '\0')
                     );
  QAbstractButton::setChecked(pQVar3,true);
  uVar6 = 0xb;
  if (*(byte *)(param_1 + 0xa38) < 0xb) {
    uVar6 = (uint)*(byte *)(param_1 + 0xa38);
  }
  pQVar3 = QButtonGroup::button(*(QButtonGroup **)(param_1 + 0x860),uVar6);
  QAbstractButton::setChecked(pQVar3,true);
  pQVar2 = *(QLabel **)(param_1 + 0x8a0);
  pQVar4 = (QString *)
           QListData::at((QListData *)(param_1 + 0x669c),(uint)*(byte *)(param_1 + 0xa38));
  QLabel::setText(pQVar2,pQVar4);
  pQVar3 = QButtonGroup::button(*(QButtonGroup **)(param_1 + 0x864),0);
  QAbstractButton::setChecked(pQVar3,true);
  if (*(char *)(param_1 + 0xa38) == '\x03') {
    bVar1 = *(byte *)(param_1 + 0x6690);
    iVar5 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x864));
    if (((*(char *)(iVar5 * 0x1a1 + 0xa95 + (uint)bVar1 * 0x684 + param_1) == '\x01') ||
        (bVar1 = *(byte *)(param_1 + 0x6690),
        iVar5 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x864)),
        *(char *)(iVar5 * 0x1a1 + 0xa95 + (uint)bVar1 * 0x684 + param_1) == '\x02')) ||
       (bVar1 = *(byte *)(param_1 + 0x6690),
       iVar5 = QButtonGroup::checkedId(*(QButtonGroup **)(param_1 + 0x864)),
       *(char *)(iVar5 * 0x1a1 + 0xa95 + (uint)bVar1 * 0x684 + param_1) == '\x04')) {
      uVar9 = 1;
    }
    else {
      uVar9 = 0;
    }
    (**(code **)(**(int **)(param_1 + 0x904) + 0x2c))(uVar9);
    (**(code **)(**(int **)(param_1 + 0x940) + 0x2c))(0);
    (**(code **)(**(int **)(param_1 + 0x914) + 0x2c))(1);
    (**(code **)(**(int **)(param_1 + 0x8bc) + 0x2c))(1);
    (**(code **)(**(int **)(param_1 + 0x8c0) + 0x2c))(1);
    (**(code **)(**(int **)(param_1 + 0x8c4) + 0x2c))(1);
    (**(code **)(**(int **)(param_1 + 0x8c8) + 0x2c))(1);
    (**(code **)(**(int **)(param_1 + 0x950) + 0x2c))(0);
    (**(code **)(**(int **)(param_1 + 0x938) + 0x2c))(0);
    (**(code **)(**(int **)(param_1 + 0x918) + 0x2c))(0);
    (**(code **)(**(int **)(param_1 + 0x8f4) + 0x2c))(1);
    (**(code **)(**(int **)(param_1 + 0x904) + 0x2c))(1);
    (**(code **)(**(int **)(param_1 + 0x8cc) + 0x2c))(1);
    pQVar3 = QButtonGroup::button
                       (*(QButtonGroup **)(param_1 + 0x868),
                        (uint)*(byte *)((uint)*(byte *)(param_1 + 0x6690) * 0x684 + 0xa95 + param_1)
                       );
    QAbstractButton::setChecked(pQVar3,true);
    pQVar2 = *(QLabel **)(param_1 + 0x8d4);
    pQVar4 = (QString *)
             QListData::at((QListData *)(param_1 + 0x66a4),
                           (uint)*(byte *)((uint)*(byte *)(param_1 + 0x6690) * 0x684 + 0xa95 +
                                          param_1));
    QLabel::setText(pQVar2,pQVar4);
  }
  else if (*(char *)(param_1 + 0xa38) == '\v') {
    FUN_004bd9b0();
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x950) + 0x2c))(1);
  }
  (**(code **)(**(int **)(param_1 + 0xa34) + 0x2c))(*(char *)(param_1 + 0xa38) == '\0');
  (**(code **)(**(int **)(param_1 + 0x954) + 0x2c))(*(char *)(param_1 + 0xa38) == '\x02');
  (**(code **)(**(int **)(param_1 + 0x9b0) + 0x2c))(*(char *)(param_1 + 0xa38) == '\n');
  FUN_004bd740();
  QAbstractButton::setChecked
            (*(QAbstractButton **)(param_1 + 0x980),*(char *)(param_1 + 0xa3b) != '\0');
  uVar8 = -(uint)(*(byte *)(param_1 + 0xa3c) != 0) & (uint)*(byte *)(param_1 + 0xa3c);
  uVar6 = 0x86;
  if (uVar8 < 0x86) {
    uVar6 = uVar8;
  }
  QComboBox::setCurrentIndex(*(QComboBox **)(param_1 + 0x958),uVar6);
  QAbstractButton::setChecked
            (*(QAbstractButton **)(param_1 + 0x98c),*(char *)(param_1 + 0xa3d) != '\0');
  uVar8 = -(uint)(*(byte *)(param_1 + 0xa3e) != 0) & (uint)*(byte *)(param_1 + 0xa3e);
  uVar6 = 0x86;
  if (uVar8 < 0x86) {
    uVar6 = uVar8;
  }
  QComboBox::setCurrentIndex(*(QComboBox **)(param_1 + 0x964),uVar6);
  QAbstractButton::setChecked
            (*(QAbstractButton **)(param_1 + 0x994),*(char *)(param_1 + 0xa3f) != '\0');
  uVar8 = -(uint)(*(byte *)(param_1 + 0xa40) != 0) & (uint)*(byte *)(param_1 + 0xa40);
  uVar6 = 0x86;
  if (uVar8 < 0x86) {
    uVar6 = uVar8;
  }
  QComboBox::setCurrentIndex(*(QComboBox **)(param_1 + 0x96c),uVar6);
  QAbstractButton::setChecked
            (*(QAbstractButton **)(param_1 + 0x99c),*(char *)(param_1 + 0xa41) != '\0');
  uVar8 = -(uint)(*(byte *)(param_1 + 0xa42) != 0) & (uint)*(byte *)(param_1 + 0xa42);
  uVar6 = 0x86;
  if (uVar8 < 0x86) {
    uVar6 = uVar8;
  }
  QComboBox::setCurrentIndex(*(QComboBox **)(param_1 + 0x970),uVar6);
  uVar8 = -(uint)(*(byte *)(param_1 + 0xa44) != 0) & (uint)*(byte *)(param_1 + 0xa44);
  uVar6 = 0x82;
  if (uVar8 < 0x82) {
    uVar6 = uVar8;
  }
  QComboBox::setCurrentIndex(*(QComboBox **)(param_1 + 0x978),uVar6);
  bVar1 = *(byte *)(param_1 + 0x6691);
  if ((-(uint)(bVar1 != 0) & (uint)bVar1) < 5) {
    uVar6 = -(uint)(bVar1 != 0) & (uint)bVar1;
  }
  else {
    uVar6 = 5;
  }
  QComboBox::setCurrentIndex(*(QComboBox **)(param_1 + 0x9c0),uVar6);
  iVar5 = (uint)*(byte *)(param_1 + 0x6691) * 4 + 0x14e7 + *(int *)(param_1 + 0x68c8);
  local_11 = *(byte *)(iVar5 + param_1 + iVar5 * 2);
  iVar5 = local_11 - 0x3e;
  if (((local_11 == 0) || (iVar5 < 1)) || (iVar5 < 4)) {
    if ((local_11 == 0) || (iVar5 < 1)) {
      iVar5 = 0;
    }
  }
  else {
    iVar5 = 4;
  }
  QComboBox::setCurrentIndex(*(QComboBox **)(param_1 + 0x9cc),iVar5);
  local_11 = *(byte *)((*(int *)(param_1 + 0x68c8) + (uint)*(byte *)(param_1 + 0x6691) * 4) * 3 +
                       0x3eb6 + param_1);
  iVar5 = local_11 - 0x3e;
  if (((local_11 == 0) || (iVar5 < 1)) || (iVar5 < 4)) {
    if ((local_11 == 0) || (iVar5 < 1)) {
      iVar5 = 0;
    }
  }
  else {
    iVar5 = 4;
  }
  QComboBox::setCurrentIndex(*(QComboBox **)(param_1 + 0x9d0),iVar5);
  iVar5 = local_18;
  local_1c = *(QComboBox **)(param_1 + 0x9d4);
  bVar1 = *(byte *)((*(int *)(param_1 + 0x68c8) + (uint)*(byte *)(param_1 + 0x6691) * 4) * 3 +
                    0x3eb7 + param_1);
  iVar7 = QListData::size((QListData *)(local_18 + 0x68d0));
  if ((int)(-(uint)(bVar1 != 0) & (uint)bVar1) < iVar7 + -1) {
    bVar1 = *(byte *)((*(int *)(iVar5 + 0x68c8) + (uint)*(byte *)(iVar5 + 0x6691) * 4) * 3 + 0x3eb7
                     + iVar5);
    uVar6 = -(uint)(bVar1 != 0) & (uint)bVar1;
  }
  else {
    iVar7 = QListData::size((QListData *)(iVar5 + 0x68d0));
    uVar6 = iVar7 - 1;
  }
  QComboBox::setCurrentIndex(local_1c,uVar6);
  bVar1 = *(byte *)(iVar5 + 0x6695);
  if ((-(uint)(bVar1 != 0) & (uint)bVar1) < 5) {
    uVar6 = -(uint)(bVar1 != 0) & (uint)bVar1;
  }
  else {
    uVar6 = 5;
  }
  QComboBox::setCurrentIndex(*(QComboBox **)(iVar5 + 0xa2c),uVar6);
  (**(code **)(**(int **)(iVar5 + 0xa1c) + 0x2c))(*(char *)(iVar5 + 0xa38) == '\v');
  bVar1 = *(byte *)((*(int *)(iVar5 + 0x68cc) + (uint)*(byte *)(iVar5 + 0x6695) * 4) * 0x1a6 +
                    0x3efd + iVar5);
  uVar6 = 2;
  if (bVar1 < 2) {
    uVar6 = (uint)bVar1;
  }
  pQVar3 = QButtonGroup::button(*(QButtonGroup **)(iVar5 + 0x85c),uVar6);
  QAbstractButton::setChecked(pQVar3,true);
  bVar1 = *(byte *)((*(int *)(iVar5 + 0x68cc) + (uint)*(byte *)(iVar5 + 0x6695) * 4) * 0x1a6 +
                    0x3efe + iVar5);
  uVar6 = (uint)bVar1;
  if (bVar1 == 0) {
    uVar6 = 0;
  }
  else if (8 < uVar6) {
    uVar6 = 9;
  }
  QComboBox::setCurrentIndex(*(QComboBox **)(iVar5 + 0x93c),uVar6);
  bVar1 = *(byte *)(iVar5 + 0x6690);
  if ((-(uint)(bVar1 != 0) & (uint)bVar1) < 7) {
    uVar6 = -(uint)(bVar1 != 0) & (uint)bVar1;
  }
  else {
    uVar6 = 7;
  }
  QComboBox::setCurrentIndex(*(QComboBox **)(iVar5 + 0x914),uVar6);
  pQVar2 = *(QLabel **)(iVar5 + 0x9a0);
  pQVar4 = (QString *)QString::number((int)local_24,*(byte *)(iVar5 + 0xa3a) + 1);
  local_8 = 1;
  QString::fromUtf8((char *)&local_1c,0x589484);
  local_20 = 1;
  QString::append((QString *)&local_1c,pQVar4);
  QLabel::setText(pQVar2,(QString *)&local_1c);
  QString::~QString((QString *)&local_1c);
  local_8 = 0xffffffff;
  QString::~QString(local_24);
  FUN_004bd840(0);
  FUN_004bc7e0(0);
  FUN_004bcf90(0);
  ExceptionList = local_10;
  return;
}


