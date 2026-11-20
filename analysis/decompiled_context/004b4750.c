
void FUN_004b4750(QString *param_1,QString *param_2)

{
  while (param_2 != param_1) {
    param_2 = param_2 + -4;
    QString::~QString(param_2);
  }
  return;
}


