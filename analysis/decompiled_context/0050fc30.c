
QSlider * __thiscall FUN_0050fc30(QSlider *param_1,QWidget *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0055882e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  QSlider::QSlider(param_1,param_2);
  local_8 = 0;
  *(undefined ***)param_1 = MySlider::vftable;
  *(undefined ***)(param_1 + 8) = MySlider::vftable;
  QAbstractSlider::setPageStep((QAbstractSlider *)param_1,0);
  ExceptionList = local_10;
  return param_1;
}


