
QDialog * __thiscall FUN_004e17d0(QDialog *param_1,byte param_2)

{
  QString::~QString((QString *)(param_1 + 0x50));
  QString::~QString((QString *)(param_1 + 0x4c));
  QDialog::~QDialog(param_1);
  if ((param_2 & 1) != 0) {
    FUN_00519359(param_1,0x54);
  }
  return param_1;
}


