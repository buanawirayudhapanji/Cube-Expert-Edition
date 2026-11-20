
void FUN_00487af0(QString *param_1)

{
  bool bVar1;
  
  bVar1 = QFile::exists(param_1);
  if (bVar1) {
                    /* WARNING: Could not recover jumptable at 0x00487b04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    QFile::remove(param_1);
    return;
  }
  return;
}


