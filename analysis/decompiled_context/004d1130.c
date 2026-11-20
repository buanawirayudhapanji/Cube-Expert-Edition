
QWidget * __thiscall
FUN_004d1130(QWidget *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  QWidget *pQVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00539bf4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  QDialog::QDialog((QDialog *)param_1,param_3,param_4,DAT_00759b24 ^ (int)register0x00000010 - 4U);
  *(undefined ***)(param_1 + 8) = BaseDialog::vftable;
  local_8 = 0;
  *(undefined ***)param_1 = IRBox::vftable;
  *(undefined ***)(param_1 + 8) = IRBox::vftable;
  QImage::QImage((QImage *)(param_1 + 0x18));
  local_8._0_1_ = 1;
  pQVar4 = param_1 + 0x2c;
  iVar3 = 10;
  do {
    QPoint::QPoint((QPoint *)pQVar4);
    pQVar4 = pQVar4 + 8;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _eh_vector_constructor_iterator_(param_1 + 0x7c,4,10,QString_exref,~QString_exref);
  local_8._0_1_ = 2;
  pQVar4 = param_1 + 0xa4;
  iVar3 = 0xc;
  do {
    QPoint::QPoint((QPoint *)pQVar4);
    pQVar4 = pQVar4 + 8;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _eh_vector_constructor_iterator_(param_1 + 0x104,4,0xc,QString_exref,~QString_exref);
  param_1[0x228] = (QWidget)0x1;
  *(code **)(param_1 + 0x2a4) = shared_null_exref;
  param_1[0x2d2] = (QWidget)0x2;
  *(undefined4 *)(param_1 + 0x2120) = 0;
  param_1[0x212c] = (QWidget)0x0;
  *(undefined4 *)(param_1 + 0x2130) = 10;
  *(undefined4 *)(param_1 + 0x2134) = 9;
  *(undefined4 *)(param_1 + 0x215c) = 0;
  *(undefined4 *)(param_1 + 0x2160) = 0;
  *(undefined4 *)(param_1 + 0x216c) = 0;
  *(undefined4 *)(param_1 + 0x2170) = 0;
  *(undefined4 *)(param_1 + 0x2178) = 0;
  *(undefined4 *)(param_1 + 0x217c) = 0x800;
  QVector<QPoint>::QVector<QPoint>((QVector<QPoint> *)(param_1 + 0x2180));
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004d5620(param_1);
  QWidget::setWindowFlags(param_1,*(uint *)(*(int *)(param_1 + 0x14) + 8) & 0xffff7fff);
  iVar3 = QWidget::height(param_1);
  iVar1 = QWidget::width(param_1);
  QWidget::setFixedSize(param_1,iVar1,iVar3);
  *(undefined4 *)(param_1 + 0x28) = param_2;
  uVar2 = FUN_00519367(9);
  *(undefined4 *)(param_1 + 0x2104) = uVar2;
  uVar2 = FUN_00519367(5);
  *(undefined4 *)(param_1 + 0x2108) = uVar2;
  uVar2 = FUN_00519367(5);
  *(undefined4 *)(param_1 + 0x210c) = uVar2;
  uVar2 = FUN_00519367(10);
  *(undefined4 *)(param_1 + 0x2114) = uVar2;
  (**(code **)(**(int **)(param_1 + 0x21c) + 0x2c))(0);
  QAbstractSlider::setTracking(*(QAbstractSlider **)(param_1 + 500),false);
  QAbstractSlider::setRange(*(QAbstractSlider **)(param_1 + 500),0,0x7f);
  *(undefined4 *)(param_1 + 0x22c) = *(undefined4 *)(param_1 + 0x1ac);
  *(undefined4 *)(param_1 + 0x230) = *(undefined4 *)(param_1 + 0x1b0);
  *(undefined4 *)(param_1 + 0x234) = *(undefined4 *)(param_1 + 0x1b4);
  *(undefined4 *)(param_1 + 0x238) = *(undefined4 *)(param_1 + 0x1b8);
  *(undefined4 *)(param_1 + 0x23c) = *(undefined4 *)(param_1 + 0x1bc);
  *(undefined4 *)(param_1 + 0x240) = *(undefined4 *)(param_1 + 0x188);
  *(undefined4 *)(param_1 + 0x244) = *(undefined4 *)(param_1 + 0x18c);
  *(undefined4 *)(param_1 + 0x248) = *(undefined4 *)(param_1 + 400);
  *(undefined4 *)(param_1 + 0x24c) = *(undefined4 *)(param_1 + 0x194);
  *(undefined4 *)(param_1 + 0x250) = *(undefined4 *)(param_1 + 0x198);
  *(undefined4 *)(param_1 + 0x254) = *(undefined4 *)(param_1 + 0x19c);
  *(undefined4 *)(param_1 + 600) = *(undefined4 *)(param_1 + 0x1a0);
  *(undefined4 *)(param_1 + 0x25c) = *(undefined4 *)(param_1 + 0x1a4);
  *(undefined4 *)(param_1 + 0x260) = *(undefined4 *)(param_1 + 0x1a8);
  *(undefined4 *)(param_1 + 0x264) = *(undefined4 *)(param_1 + 0x1c4);
  *(undefined4 *)(param_1 + 0x268) = *(undefined4 *)(param_1 + 0x1c8);
  *(undefined4 *)(param_1 + 0x26c) = *(undefined4 *)(param_1 + 0x1cc);
  *(undefined4 *)(param_1 + 0x270) = *(undefined4 *)(param_1 + 0x1d0);
  *(undefined4 *)(param_1 + 0x274) = *(undefined4 *)(param_1 + 0x1d4);
  *(undefined4 *)(param_1 + 0x278) = *(undefined4 *)(param_1 + 0x1d8);
  *(undefined4 *)(param_1 + 0x27c) = *(undefined4 *)(param_1 + 0x1dc);
  *(undefined4 *)(param_1 + 0x280) = *(undefined4 *)(param_1 + 0x15c);
  *(undefined4 *)(param_1 + 0x284) = *(undefined4 *)(param_1 + 0x160);
  *(undefined4 *)(param_1 + 0x288) = *(undefined4 *)(param_1 + 0x164);
  *(undefined4 *)(param_1 + 0x28c) = *(undefined4 *)(param_1 + 0x168);
  *(undefined4 *)(param_1 + 0x290) = *(undefined4 *)(param_1 + 0x16c);
  *(undefined4 *)(param_1 + 0x294) = *(undefined4 *)(param_1 + 0x178);
  *(undefined4 *)(param_1 + 0x298) = *(undefined4 *)(param_1 + 0x17c);
  *(undefined4 *)(param_1 + 0x29c) = *(undefined4 *)(param_1 + 0x170);
  *(undefined4 *)(param_1 + 0x2a0) = *(undefined4 *)(param_1 + 0x174);
  FUN_004d41e0();
  FUN_004d43f0();
  *(undefined4 *)(param_1 + 0x1ed0) = 0x10001;
  *(undefined4 *)(param_1 + 0x1ed4) = 0xac44;
  *(undefined4 *)(param_1 + 0x1edc) = 0x180003;
  *(undefined4 *)(param_1 + 0x1ed8) = 0x204cc;
  *(undefined2 *)(param_1 + 0x1ee0) = 0x12;
  iVar3 = QObject::startTimer((QObject *)param_1,1000,1);
  *(int *)(param_1 + 0x134) = iVar3;
  (**(code **)(**(int **)(param_1 + 0x218) + 0x2c))(0);
  ExceptionList = local_10;
  return param_1;
}


