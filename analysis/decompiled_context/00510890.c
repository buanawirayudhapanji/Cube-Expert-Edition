
QObject * __thiscall FUN_00510890(QObject *param_1,byte param_2)

{
  *(undefined ***)param_1 = CMyHttp::vftable;
  if (*(int **)(param_1 + 8) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 8) + 0xc))(1);
  }
  QString::~QString((QString *)(param_1 + 0xc));
  QObject::~QObject(param_1);
  if ((param_2 & 1) != 0) {
    FUN_00519359(param_1,0x10);
  }
  return param_1;
}


