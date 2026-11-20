
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_004ca1a0(QString param_1,char *param_2)

{
  short sVar1;
  char *pcVar2;
  QRegularExpression *pQVar3;
  QString *pQVar4;
  QChar *pQVar5;
  char *local_3c;
  QString local_38 [2];
  short local_36;
  QChar *local_34;
  QTypedArrayData<unsigned_short> *local_30;
  char local_2a;
  char local_29;
  QTypedArrayData<unsigned_short> local_28 [4];
  char acStack_24 [4];
  char acStack_20 [4];
  char acStack_1c [4];
  char local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pcVar2 = param_2;
  puStack_c = &LAB_00536c40;
  local_10 = ExceptionList;
  local_14 = DAT_00759b24 ^ (uint)(acStack_1c + 0x18);
  ExceptionList = &local_10;
  local_3c = param_2 + 1;
  local_8 = 0;
  memset(local_3c,0,0x7f);
  local_28[0] = (QTypedArrayData<unsigned_short>)s_0123456789ABCDEF_00589568[0];
  local_28[1] = (QTypedArrayData<unsigned_short>)s_0123456789ABCDEF_00589568[1];
  local_28[2] = (QTypedArrayData<unsigned_short>)s_0123456789ABCDEF_00589568[2];
  local_28[3] = (QTypedArrayData<unsigned_short>)s_0123456789ABCDEF_00589568[3];
  acStack_24[0] = s_0123456789ABCDEF_00589568[4];
  acStack_24[1] = s_0123456789ABCDEF_00589568[5];
  acStack_24[2] = s_0123456789ABCDEF_00589568[6];
  acStack_24[3] = s_0123456789ABCDEF_00589568[7];
  acStack_20[0] = s_0123456789ABCDEF_00589568[8];
  acStack_20[1] = s_0123456789ABCDEF_00589568[9];
  acStack_20[2] = s_0123456789ABCDEF_00589568[10];
  acStack_20[3] = s_0123456789ABCDEF_00589568[0xb];
  acStack_1c[0] = s_0123456789ABCDEF_00589568[0xc];
  acStack_1c[1] = s_0123456789ABCDEF_00589568[0xd];
  acStack_1c[2] = s_0123456789ABCDEF_00589568[0xe];
  acStack_1c[3] = s_0123456789ABCDEF_00589568[0xf];
  local_18 = s_0123456789ABCDEF_00589568[0x10];
  local_30 = QString::fromAscii_helper("\\s",2);
  local_8._0_1_ = 1;
  pQVar3 = (QRegularExpression *)
           QRegularExpression::QRegularExpression((QRegularExpression *)&local_34,&local_30,0);
  local_8._0_1_ = 2;
  pQVar4 = QString::remove(&param_1,pQVar3);
  pQVar4 = (QString *)QString::toUpper(pQVar4);
  QString::operator=(&param_1,pQVar4);
  QString::~QString(local_38);
  QRegularExpression::~QRegularExpression((QRegularExpression *)&local_34);
  local_8 = (uint)local_8._1_3_ << 8;
  QString::~QString((QString *)&local_30);
  pQVar4 = (QString *)QString::left(&param_1,(int)&local_34);
  QString::operator=(&param_1,pQVar4);
  QString::~QString((QString *)&local_34);
  local_29 = '\0';
  pQVar5 = QString::begin(&param_1);
  local_34 = QString::end(&param_1);
  if (pQVar5 != local_34) {
    do {
      sVar1 = *(short *)pQVar5;
      local_30 = (QTypedArrayData<unsigned_short> *)0x0;
      do {
        QChar::QChar((QChar *)&local_36,(int)(char)local_28[(int)local_30]);
        if (local_36 == sVar1) {
          if (local_29 == '\0') {
            local_2a = (char)local_30._0_1_ << 4;
            local_29 = '\x01';
          }
          else {
            local_2a = local_2a + (char)local_30._0_1_;
            local_29 = '\0';
            *local_3c = local_2a;
            local_3c = local_3c + 1;
          }
          goto LAB_004ca306;
        }
        local_30 = local_30 + 1;
      } while ((int)local_30 < 0x10);
      if (local_29 != '\0') {
        local_2a = '\0';
        local_29 = '\0';
      }
LAB_004ca306:
      pQVar5 = pQVar5 + 2;
    } while (pQVar5 != local_34);
  }
  *pcVar2 = ((char)local_3c - (char)pcVar2) + -1;
  QString::~QString(&param_1);
  ExceptionList = local_10;
  return;
}


