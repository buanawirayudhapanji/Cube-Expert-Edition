
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_0050de00(int param_1)

{
  int *piVar1;
  QPen *pQVar2;
  QColor *pQVar3;
  int iVar4;
  QPoint *pQVar5;
  int iVar6;
  QArrayData *pQVar7;
  int iVar8;
  int iVar9;
  QRect *pQVar10;
  QString *pQVar11;
  int *piVar12;
  QRect *pQVar13;
  uint uVar14;
  QColor aQStackY_150 [128];
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  QString local_88 [4];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  QRect local_68;
  double local_64;
  undefined8 local_5c;
  QFontMetrics local_54 [4];
  QPolygonF local_50 [4];
  QVector<QPoint> local_4c [4];
  QPainterPath local_48 [4];
  QRect *local_44;
  QPoint *local_40;
  QRect *local_3c;
  QPainter local_38 [4];
  QColor local_34 [16];
  double local_24;
  double local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0055878f;
  local_10 = ExceptionList;
  local_14 = DAT_00759b24 ^ (uint)(local_34 + 0x30);
  ExceptionList = &local_10;
  local_3c = (QRect *)param_1;
  QPainter::QPainter(local_38,(QPaintDevice *)(-(uint)(param_1 != 0) & param_1 + 8U));
  local_8 = 0;
  QPainter::setRenderHint(local_38,1,true);
  FUN_00488c90();
  QColor::QColor(aQStackY_150 + 0x94,0x3c,0x3c,0x3c,0xff);
  pQVar2 = (QPen *)FUN_00488d30();
  QPainter::setPen(local_38,pQVar2);
  pQVar3 = (QColor *)QColor::QColor((QColor *)&local_24,0x3c,0x3c,0x3c,0xff);
  QPainter::fillRect(local_38,(QRect *)(param_1 + 0x120),pQVar3);
  pQVar10 = (QRect *)((int)local_3c + 0x130);
  local_44 = pQVar10;
  pQVar3 = (QColor *)QColor::QColor((QColor *)&local_24,0,0,0,0xff);
  QPainter::fillRect(local_38,pQVar10,pQVar3);
  FUN_00488c90();
  QColor::QColor(aQStackY_150 + 0x94,0xc,0x3a,0x2e,0xff);
  pQVar2 = (QPen *)FUN_00488d30();
  QPainter::setPen(local_38,pQVar2);
  pQVar10 = local_3c;
  QPainter::drawLines(local_38,(QVector<QLine> *)((int)local_3c + 0x148));
  QPainter::drawLines(local_38,(QVector<QLine> *)((int)pQVar10 + 0x150));
  FUN_00488c90();
  QColor::QColor(aQStackY_150 + 0x94,0x19,0x75,0x5c,0xff);
  pQVar2 = (QPen *)FUN_00488d30();
  QPainter::setPen(local_38,pQVar2);
  pQVar10 = local_3c;
  QPainter::drawLines(local_38,(QVector<QLine> *)((int)local_3c + 0x140));
  QPainter::drawLines(local_38,(QVector<QLine> *)((int)pQVar10 + 0x14c));
  FUN_00488c90();
  QColor::QColor(aQStackY_150 + 0x94,0x33,0xea,0xb8,0xff);
  pQVar2 = (QPen *)FUN_00488d30();
  QPainter::setPen(local_38,pQVar2);
  QPainter::drawRects(local_38,(QRect *)(param_1 + 0x120),1);
  QPainter::drawRects(local_38,local_44,1);
  pQVar10 = local_3c;
  QPainter::drawLines(local_38,(QLine *)((int)local_3c + 0xe0),1);
  QPainter::drawLines(local_38,(QVector<QLine> *)((int)pQVar10 + 0x144));
  QPainter::drawLines(local_38,(QVector<QLine> *)((int)pQVar10 + 0x154));
  QPainter::fontMetrics(local_38);
  local_40 = (QPoint *)((int)pQVar10 + 0x1d0);
  local_8 = CONCAT31(local_8._1_3_,1);
  uVar14 = 0;
  do {
    pQVar11 = (QString *)((int)pQVar10 + 0x240 + uVar14);
    iVar4 = QFontMetrics::horizontalAdvance(local_54,pQVar11,-1);
    local_64 = (double)(*(int *)local_40 - iVar4 / 2);
    local_5c = (double)*(int *)((int)local_40 + 4);
    QPainter::drawText(local_38,(QPointF *)&local_64,pQVar11);
    local_40 = (QPoint *)((int)local_40 + 8);
    uVar14 = uVar14 + 4;
    pQVar10 = local_3c;
  } while (uVar14 < 0x38);
  uVar14 = 0;
  piVar12 = (int *)((int)local_3c + 0x158);
  do {
    local_64 = (double)*piVar12;
    local_5c = (double)piVar12[1];
    QPainter::drawText(local_38,(QPointF *)&local_64,(QString *)((int)local_3c + 0x1a8 + uVar14));
    piVar12 = piVar12 + 2;
    uVar14 = uVar14 + 4;
  } while (uVar14 < 0x28);
  QVector<QPoint>::QVector<QPoint>(local_4c);
  pQVar10 = local_3c;
  local_8 = CONCAT31(local_8._1_3_,2);
  pQVar5 = QVector<QPoint>::begin((QVector<QPoint> *)((int)local_3c + 0xdc));
  local_40 = QVector<QPoint>::end((QVector<QPoint> *)((int)pQVar10 + 0xdc));
  if (pQVar5 != local_40) {
    do {
      iVar4 = *(int *)(pQVar5 + 4);
      local_5c = *(double *)pQVar5;
      iVar6 = QRect::top(local_44);
      if (iVar6 < iVar4) {
        iVar4 = local_5c._4_4_;
        iVar6 = QRect::bottom(local_44);
        if (iVar4 < iVar6) {
          QVector<QPoint>::append(local_4c,(QPoint *)&local_5c);
        }
      }
      pQVar5 = pQVar5 + 8;
    } while (pQVar5 != local_40);
  }
  QPainterPath::QPainterPath(local_48);
  local_8._0_1_ = 3;
  QPolygon::QPolygon((QPolygon *)&local_44,local_4c);
  local_8._0_1_ = 4;
  QPolygonF::QPolygonF(local_50,(QPolygon *)&local_44);
  local_8 = CONCAT31(local_8._1_3_,6);
  QPolygon::~QPolygon((QPolygon *)&local_44);
  QPainterPath::addPolygon(local_48,local_50);
  QPainter::drawPath(local_38,local_48);
  FUN_00488c90();
  QColor::QColor(aQStackY_150 + 0x90,0xff,0xff,0xff,0xff);
  pQVar2 = (QPen *)FUN_00488d30();
  QPainter::setPen(local_38,pQVar2);
  piVar12 = (int *)((int)local_3c + 0x27c);
  if ((*(int *)*piVar12 != 1) && (*(int *)*piVar12 != 0)) {
    if ((*(uint *)(*piVar12 + 8) & 0x7fffffff) == 0) {
      pQVar7 = QArrayData::allocate();
      *piVar12 = (int)pQVar7;
    }
    else {
      FUN_0050e400();
    }
  }
  piVar1 = (int *)*piVar12;
  iVar4 = piVar1[3];
  if ((*piVar1 != 1) && (*piVar1 != 0)) {
    if ((*(uint *)(*piVar12 + 8) & 0x7fffffff) == 0) {
      pQVar7 = QArrayData::allocate();
      *piVar12 = (int)pQVar7;
    }
    else {
      FUN_0050e400();
    }
  }
  iVar6 = *piVar12;
  local_3c = (QRect *)(*(int *)(iVar6 + 4) * 0x34 + *(int *)(iVar6 + 0xc) + iVar6);
  if ((QRect *)(iVar4 + (int)piVar1) != local_3c) {
    local_44 = (QRect *)(iVar4 + (int)piVar1) + 0x14;
    do {
      pQVar10 = local_44;
      local_98 = *(undefined4 *)(local_44 + -0x14);
      uStack_94 = *(undefined4 *)(local_44 + -0x10);
      uStack_90 = *(undefined4 *)(local_44 + -0xc);
      uStack_8c = *(undefined4 *)(local_44 + -8);
      QString::QString(local_88,(QString *)(local_44 + -4));
      local_84 = *(undefined4 *)pQVar10;
      local_80 = *(undefined4 *)(pQVar10 + 4);
      local_7c = *(undefined4 *)(pQVar10 + 8);
      local_78 = *(undefined4 *)(pQVar10 + 0xc);
      local_74 = *(undefined4 *)(pQVar10 + 0x10);
      local_70 = *(undefined4 *)(pQVar10 + 0x14);
      local_6c = *(undefined4 *)(pQVar10 + 0x18);
      local_68 = pQVar10[0x1c];
      local_8._0_1_ = 7;
      QPainter::fontMetrics(local_38);
      local_8._0_1_ = 8;
      iVar4 = QFontMetrics::horizontalAdvance((QFontMetrics *)&local_40,local_88,-1);
      iVar6 = QRect::width((QRect *)&local_98);
      pQVar3 = (QColor *)QColor::QColor(local_34,0xff,0xff,0xff,0xff);
      QPainter::fillRect(local_38,(QRect *)&local_98,pQVar3);
      iVar8 = QRect::y((QRect *)&local_98);
      iVar9 = QRect::x((QRect *)&local_98);
      local_24 = (double)(iVar9 + (iVar6 - iVar4) / 2);
      local_1c = (double)(iVar8 + -5);
      QPainter::drawText(local_38,(QPointF *)&local_24,local_88);
      QFontMetrics::~QFontMetrics((QFontMetrics *)&local_40);
      local_8 = CONCAT31(local_8._1_3_,6);
      QString::~QString(local_88);
      pQVar13 = local_44 + 0x34;
      pQVar10 = local_44 + 0x20;
      local_44 = pQVar13;
    } while (pQVar10 != local_3c);
  }
  QPolygonF::~QPolygonF(local_50);
  QPainterPath::~QPainterPath(local_48);
  QVector<QPoint>::~QVector<QPoint>(local_4c);
  QFontMetrics::~QFontMetrics(local_54);
  QPainter::~QPainter(local_38);
  ExceptionList = local_10;
  return;
}


