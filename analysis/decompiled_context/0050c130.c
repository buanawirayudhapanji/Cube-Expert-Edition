
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0050c130(QWidget *param_1)

{
  undefined4 uVar1;
  QWidget *pQVar2;
  QWidget *this;
  int iVar3;
  int iVar4;
  int iVar5;
  QTypedArrayData<unsigned_short> *pQVar6;
  QPolygon *this_00;
  double dVar7;
  double dVar8;
  QRectF local_74 [2];
  QChar aQStack_72 [30];
  QRectF local_54 [16];
  double local_44;
  double local_3c;
  QFont local_34 [8];
  double local_2c;
  undefined8 local_24;
  QBrush local_1c [4];
  QWidget *local_18;
  QPainter local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00555668;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = param_1;
  iVar3 = QWidget::width(param_1);
  iVar4 = QWidget::height(param_1);
  iVar5 = iVar4;
  if (iVar3 < iVar4) {
    iVar5 = iVar3;
  }
  QPainter::QPainter(local_14,(QPaintDevice *)
                              (-(uint)(local_18 != (QWidget *)0x0) & (uint)(local_18 + 8)));
  local_8 = 0;
  QPainter::setRenderHints(local_14,3,1);
  local_44 = (double)iVar3 * DAT_005937f8;
  local_3c = (double)(iVar4 / 2);
  QPainter::translate(local_14,(QPointF *)&local_44);
  pQVar2 = local_18;
  QPainter::scale(local_14,(double)iVar5 / (double)*(int *)(local_18 + 0x28),
                  (double)iVar5 / (double)*(int *)(local_18 + 0x28));
  iVar5 = *(int *)(pQVar2 + 0x28);
  QPainter::save(local_14);
  QPainter::setPen(local_14,0);
  dVar7 = (double)(iVar5 * 2 + -100);
  dVar8 = (double)(0x32 - iVar5);
  QRectF::QRectF(local_54,dVar8,dVar8,dVar7,dVar7);
  local_24 = (DAT_00593d60 - (double)*(int *)(pQVar2 + 0x38)) - (double)*(int *)(pQVar2 + 0x3c);
  iVar5 = QAbstractSlider::value((QAbstractSlider *)pQVar2);
  local_2c = (double)iVar5;
  iVar5 = QAbstractSlider::minimum((QAbstractSlider *)pQVar2);
  local_2c = local_2c - (double)iVar5;
  iVar5 = QAbstractSlider::maximum((QAbstractSlider *)pQVar2);
  iVar3 = QAbstractSlider::minimum((QAbstractSlider *)pQVar2);
  local_2c = (local_2c / (double)(iVar5 - iVar3)) * local_24;
  local_24 = local_24 - local_2c;
  QBrush::QBrush(local_1c,(QColor *)(pQVar2 + 0x40),1);
  local_8._0_1_ = 1;
  QPainter::setBrush(local_14,local_1c);
  local_8 = (uint)local_8._1_3_ << 8;
  QBrush::~QBrush(local_1c);
  QPainter::drawPie(local_14,local_54,
                    (int)(((double)(0x10e - *(int *)(local_18 + 0x38)) - local_2c) * _DAT_00593d50),
                    (int)(local_2c * _DAT_00593d50));
  QBrush::QBrush(local_1c,(QColor *)(local_18 + 0x50),1);
  local_8._0_1_ = 2;
  QPainter::setBrush(local_14,local_1c);
  local_8 = (uint)local_8._1_3_ << 8;
  QBrush::~QBrush(local_1c);
  QPainter::drawPie(local_14,local_54,
                    (int)((((double)(0x10e - *(int *)(local_18 + 0x38)) - local_2c) - local_24) *
                         _DAT_00593d50),(int)(local_24 * _DAT_00593d50));
  QPainter::restore(local_14);
  pQVar2 = local_18;
  iVar3 = *(int *)(local_18 + 0x28);
  QPainter::save(local_14);
  QPainter::setPen(local_14,0);
  QBrush::QBrush(local_1c,(QColor *)(pQVar2 + 0x60),1);
  local_8._0_1_ = 3;
  QPainter::setBrush(local_14,local_1c);
  local_8 = (uint)local_8._1_3_ << 8;
  QBrush::~QBrush(local_1c);
  iVar5 = iVar3 * 2 + -0x78;
  iVar3 = 0x3c - iVar3;
  QPainter::drawEllipse(local_14,iVar3,iVar3,iVar5,iVar5);
  QPainter::restore(local_14);
  pQVar2 = local_18;
  QPainter::save(local_14);
  QPainter::setPen(local_14,0);
  QBrush::QBrush((QBrush *)((int)&local_24 + 4),(QColor *)(pQVar2 + 0x70),1);
  local_8._0_1_ = 4;
  QPainter::setBrush(local_14,(QBrush *)((int)&local_24 + 4));
  local_8 = (uint)local_8._1_3_ << 8;
  QBrush::~QBrush((QBrush *)((int)&local_24 + 4));
  QPolygon::QPolygon((QPolygon *)local_1c);
  local_8._0_1_ = 5;
  QPolygon::setPoints(this_00,(int)local_1c,3,-5);
  this = local_18;
  QPainter::rotate(local_14,(double)*(int *)(local_18 + 0x38));
  local_2c = (DAT_00593d60 - (double)*(int *)(this + 0x38)) - (double)*(int *)(this + 0x3c);
  iVar5 = QAbstractSlider::maximum((QAbstractSlider *)this);
  iVar3 = QAbstractSlider::minimum((QAbstractSlider *)local_18);
  local_2c = local_2c / (double)(iVar5 - iVar3);
  iVar5 = QAbstractSlider::minimum((QAbstractSlider *)local_18);
  iVar3 = QAbstractSlider::value((QAbstractSlider *)local_18);
  QPainter::rotate(local_14,(double)(iVar3 - iVar5) * local_2c);
  QPainter::drawConvexPolygon(local_14,(QPolygon *)local_1c);
  QPainter::restore(local_14);
  local_8 = (uint)local_8._1_3_ << 8;
  QPolygon::~QPolygon((QPolygon *)local_1c);
  iVar3 = *(int *)(local_18 + 0x28);
  QPainter::save(local_14);
  QPainter::setPen(local_14,0);
  QBrush::QBrush((QBrush *)((int)&local_24 + 4),(QColor *)(pQVar2 + 0x70),1);
  local_8._0_1_ = 6;
  QPainter::setBrush(local_14,(QBrush *)((int)&local_24 + 4));
  local_8 = (uint)local_8._1_3_ << 8;
  QBrush::~QBrush((QBrush *)((int)&local_24 + 4));
  iVar5 = iVar3 * 2 + -0xa4;
  iVar3 = 0x52 - iVar3;
  QPainter::drawEllipse(local_14,iVar3,iVar3,iVar5,iVar5);
  QPainter::restore(local_14);
  iVar3 = *(int *)(local_18 + 0x28);
  QPainter::save(local_14);
  QPainter::setPen(local_14,0);
  QBrush::QBrush((QBrush *)((int)&local_24 + 4),(QColor *)(local_18 + 0x80),1);
  local_8._0_1_ = 7;
  QPainter::setBrush(local_14,(QBrush *)((int)&local_24 + 4));
  local_8 = (uint)local_8._1_3_ << 8;
  QBrush::~QBrush((QBrush *)((int)&local_24 + 4));
  iVar5 = iVar3 * 2 + -0xaa;
  iVar3 = 0x55 - iVar3;
  QPainter::drawEllipse(local_14,iVar3,iVar3,iVar5,iVar5);
  QPainter::restore(local_14);
  pQVar2 = local_18;
  iVar5 = *(int *)(local_18 + 0x28);
  QPainter::save(local_14);
  QPainter::setPen(local_14,(QColor *)(pQVar2 + 0x90));
  QFont::QFont(local_34);
  local_8._0_1_ = 8;
  QFont::setPixelSize(local_34,0x12);
  QPainter::setFont(local_14,local_34);
  dVar7 = (double)(iVar5 * 2);
  dVar8 = (double)-iVar5;
  QRectF::QRectF(local_74,dVar8,dVar8,dVar7,dVar7);
  pQVar6 = QString::fromAscii_helper("%1",2);
  local_24 = (double)CONCAT44(pQVar6,(undefined4)local_24);
  uVar1 = *(undefined4 *)(pQVar2 + 0x2c);
  local_8._0_1_ = 9;
  iVar5 = QAbstractSlider::value((QAbstractSlider *)pQVar2);
  local_18 = (QWidget *)CONCAT31(local_18._1_3_,0x20);
  local_3c = (double)iVar5;
  QChar::QChar((QChar *)(local_74 + -0x10),local_18);
  QString::arg((QString *)((int)&local_24 + 4),local_1c,SUB84(local_3c,0),
               (int)((ulonglong)local_3c >> 0x20),0,0x66,uVar1);
  local_8 = CONCAT31(local_8._1_3_,0xb);
  QString::~QString((QString *)((int)&local_24 + 4));
  QPainter::drawText(local_14,local_74,0x84,(QString *)local_1c,(QRectF *)0x0);
  QPainter::restore(local_14);
  QString::~QString((QString *)local_1c);
  QFont::~QFont(local_34);
  QPainter::~QPainter(local_14);
  ExceptionList = local_10;
  return;
}


