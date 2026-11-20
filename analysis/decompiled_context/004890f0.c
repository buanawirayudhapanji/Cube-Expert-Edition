
void __thiscall FUN_004890f0(QDial *param_1,QPaintEvent *param_2)

{
  short sVar1;
  ushort uVar2;
  QDial *this;
  QCharRef *pQVar3;
  short *psVar4;
  ushort *puVar5;
  QString *pQVar6;
  int iVar7;
  QRect *pQVar8;
  int iVar9;
  QChar aQStackY_108 [128];
  char cVar10;
  QPainter local_5c [4];
  QWidget *local_58;
  QStyle *local_54;
  undefined1 local_48 [8];
  undefined1 local_40 [8];
  undefined1 local_38 [8];
  undefined1 local_30 [8];
  QDial *local_28;
  int local_24 [2];
  int local_1c;
  ushort local_16;
  ushort local_14;
  short local_12;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005225df;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_28 = param_1;
  QDial::paintEvent(param_1,param_2);
  if (DAT_007556a8 == '\0') {
    ExceptionList = local_10;
    return;
  }
  QWidget::toolTip((QWidget *)param_1);
  iVar9 = 0;
  local_8 = 0;
  if (0 < *(int *)(local_24[0] + 4)) {
    do {
      pQVar3 = (QCharRef *)QString::operator[]((QString *)local_24,(int)local_30);
      psVar4 = (short *)QCharRef::operator_class_QChar(pQVar3);
      sVar1 = *psVar4;
      QChar::QChar((QChar *)((int)&param_2 + 2),0x2b);
      if (param_2._2_2_ == sVar1) break;
      pQVar3 = (QCharRef *)QString::operator[]((QString *)local_24,(int)local_38);
      psVar4 = (short *)QCharRef::operator_class_QChar(pQVar3);
      sVar1 = *psVar4;
      QChar::QChar((QChar *)&local_12,0x2d);
      if (local_12 == sVar1) break;
      pQVar3 = (QCharRef *)QString::operator[]((QString *)local_24,(int)local_40);
      puVar5 = (ushort *)QCharRef::operator_class_QChar(pQVar3);
      uVar2 = *puVar5;
      QChar::QChar((QChar *)&local_14,0x30);
      if (local_14 <= uVar2) {
        pQVar3 = (QCharRef *)QString::operator[]((QString *)local_24,(int)local_48);
        puVar5 = (ushort *)QCharRef::operator_class_QChar(pQVar3);
        uVar2 = *puVar5;
        QChar::QChar((QChar *)&local_16,0x39);
        if (uVar2 <= local_16) break;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < *(int *)(local_24[0] + 4));
  }
  iVar7 = *(int *)(local_24[0] + 4);
  do {
    do {
      iVar7 = iVar7 + -1;
      if (iVar7 < 0) goto LAB_004892c3;
      pQVar3 = (QCharRef *)QString::operator[]((QString *)local_24,(int)local_48);
      psVar4 = (short *)QCharRef::operator_class_QChar(pQVar3);
      sVar1 = *psVar4;
      QChar::QChar((QChar *)((int)&param_2 + 2),0x25);
      if (param_2._2_2_ == sVar1) goto LAB_004892c3;
      pQVar3 = (QCharRef *)QString::operator[]((QString *)local_24,(int)local_40);
      puVar5 = (ushort *)QCharRef::operator_class_QChar(pQVar3);
      uVar2 = *puVar5;
      QChar::QChar((QChar *)&local_16,0x30);
    } while (uVar2 < local_16);
    pQVar3 = (QCharRef *)QString::operator[]((QString *)local_24,(int)local_38);
    puVar5 = (ushort *)QCharRef::operator_class_QChar(pQVar3);
    uVar2 = *puVar5;
    QChar::QChar((QChar *)&local_14,0x39);
  } while (local_14 < uVar2);
LAB_004892c3:
  pQVar6 = (QString *)QString::mid((QString *)local_24,(int)&param_2,iVar9);
  QString::operator=((QString *)local_24,pQVar6);
  QString::~QString((QString *)&param_2);
  QChar::QChar(aQStackY_108 + 0x88,0x2e);
  iVar9 = QString::indexOf((QString *)local_24);
  if (iVar9 == -1) goto LAB_00489455;
  QChar::QChar(aQStackY_108 + 0x88,0x25);
  iVar7 = QString::indexOf((QString *)local_24);
  if (iVar7 == -1) {
    iVar7 = *(int *)(local_24[0] + 4);
    do {
      do {
        iVar7 = iVar7 + -1;
        if (iVar7 < iVar9) goto LAB_00489434;
        pQVar3 = (QCharRef *)QString::operator[]((QString *)local_24,(int)local_48);
        psVar4 = (short *)QCharRef::operator_class_QChar(pQVar3);
        sVar1 = *psVar4;
        QChar::QChar((QChar *)((int)&param_2 + 2),0x30);
      } while (param_2._2_2_ == sVar1);
      pQVar3 = (QCharRef *)QString::operator[]((QString *)local_24,(int)local_40);
      puVar5 = (ushort *)QCharRef::operator_class_QChar(pQVar3);
      uVar2 = *puVar5;
      QChar::QChar((QChar *)&local_16,0x2e);
    } while (local_16 == uVar2);
  }
  else {
    iVar7 = iVar7 + -1;
    local_1c = iVar7;
    if (iVar7 < iVar9) goto LAB_00489455;
    do {
      pQVar3 = (QCharRef *)QString::operator[]((QString *)local_24,(int)local_48);
      psVar4 = (short *)QCharRef::operator_class_QChar(pQVar3);
      sVar1 = *psVar4;
      QChar::QChar((QChar *)((int)&param_2 + 2),0x30);
      if (param_2._2_2_ != sVar1) {
        pQVar3 = (QCharRef *)QString::operator[]((QString *)local_24,(int)local_40);
        puVar5 = (ushort *)QCharRef::operator_class_QChar(pQVar3);
        uVar2 = *puVar5;
        QChar::QChar((QChar *)&local_16,0x2e);
        if (local_16 != uVar2) break;
      }
      iVar7 = iVar7 + -1;
    } while (iVar9 <= iVar7);
    if (iVar7 == local_1c) goto LAB_00489455;
    cVar10 = '%';
    pQVar3 = (QCharRef *)QString::operator[]((QString *)local_24,(int)local_48);
    QCharRef::operator=(pQVar3,cVar10);
  }
LAB_00489434:
  pQVar6 = (QString *)QString::left((QString *)local_24,(int)&param_2);
  QString::operator=((QString *)local_24,pQVar6);
  QString::~QString((QString *)&param_2);
LAB_00489455:
  QPainter::QPainter(local_5c);
  this = local_28;
  local_8._0_1_ = 1;
  local_58 = (QWidget *)local_28;
  local_54 = QWidget::style((QWidget *)local_28);
  QPainter::begin(local_5c,(QPaintDevice *)(-(uint)(this != (QDial *)0x0) & (uint)(this + 8)));
  local_8 = CONCAT31(local_8._1_3_,2);
  pQVar8 = (QRect *)QWidget::rect((QWidget *)this);
  QPainter::drawText(local_5c,pQVar8,0x84,(QString *)local_24,(QRect *)0x0);
  QPainter::~QPainter(local_5c);
  QString::~QString((QString *)local_24);
  ExceptionList = local_10;
  return;
}


