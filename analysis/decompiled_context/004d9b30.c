
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_004d9b30(void **param_1)

{
  int *piVar1;
  uint uVar2;
  QWidget *pQVar3;
  QString *pQVar4;
  undefined4 uVar5;
  void *pvVar6;
  void **ppvVar7;
  bool bVar8;
  QColor aQStack_7e [2];
  code *local_70;
  undefined4 local_6c;
  void **local_68;
  QString local_64 [4];
  QString local_60 [4];
  QString local_5c [4];
  QWidget *local_58;
  undefined1 local_54;
  undefined3 uStack_53;
  QObject local_50 [4];
  void **local_4c;
  uint local_48;
  int local_44;
  int local_40;
  uint local_3c;
  QString *local_38;
  uint local_34;
  int local_30;
  undefined4 *local_2c;
  QWidget *local_28;
  QColor local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0053c46e;
  local_10 = ExceptionList;
  local_14 = DAT_00759b24 ^ (uint)(local_24 + 0x20);
  ExceptionList = &local_10;
  local_40 = 0;
  local_34 = 0;
  if (0 < (int)param_1[7]) {
    pvVar6 = param_1[8];
    local_68 = param_1;
    do {
      if (local_34 != 0) {
        uVar2 = local_34 & 0x80000003;
        bVar8 = uVar2 == 0;
        if ((int)uVar2 < 0) {
          bVar8 = (uVar2 - 1 | 0xfffffffc) == 0xffffffff;
        }
        if (bVar8) {
          local_40 = local_40 + 10;
        }
      }
      local_48 = 0;
      if (0 < (int)pvVar6) {
        local_30 = 10;
        ppvVar7 = param_1 + 0x10e;
        local_44 = local_40 + 0xa0 + local_34 * 0x3c;
        local_3c = local_34;
        local_38 = (QString *)(param_1 + 0x10f);
        local_4c = ppvVar7;
        do {
          QColor::QColor(local_24,(QColor *)(param_1 + (local_48 & 1) * 4 + 0x11f));
          operator_new(0x58);
          local_8 = 0;
          local_28 = (QWidget *)FUN_0050b9c0();
          local_8 = 0xffffffff;
          QColor::QColor(aQStack_7e + -0x12,local_24);
          FUN_0050bea0();
          *(uint *)(local_28 + 0x54) = local_3c;
          QWidget::setGeometry(local_28,local_44,local_30,0x32,0x32);
          piVar1 = *ppvVar7;
          if (((*piVar1 != 1) && (*piVar1 != 0)) || ((piVar1[2] & 0x7fffffffU) < piVar1[1] + 1U)) {
            local_2c = (undefined4 *)(-(uint)((piVar1[2] & 0x7fffffffU) < piVar1[1] + 1U) & 8);
            FUN_004d9e60();
          }
          pvVar6 = *ppvVar7;
          local_70 = FUN_005147c0;
          local_6c = 0;
          *(QWidget **)(*(int *)((int)pvVar6 + 0xc) + *(int *)((int)pvVar6 + 4) * 4 + (int)pvVar6) =
               local_28;
          *(int *)((int)*ppvVar7 + 4) = *(int *)((int)*ppvVar7 + 4) + 1;
          local_2c = operator_new(0xc);
          *local_2c = 1;
          local_2c[1] = FUN_004d9a40;
          local_2c[2] = param_1;
          QObject::connectImpl
                    (local_50,(void **)local_28,(QObject *)&local_70,param_1,(QSlotObjectBase *)0x0,
                     (ConnectionType)local_2c,(int *)0x0,(QMetaObject *)0x0);
          QMetaObject::Connection::~Connection((Connection *)local_50);
          if (local_34 == 0) {
            pQVar3 = operator_new(0x18);
            local_8 = 1;
            local_58 = pQVar3;
            QLabel::QLabel((QLabel *)pQVar3);
            *(undefined ***)pQVar3 = QLabel::vftable;
            *(undefined ***)(pQVar3 + 8) = QLabel::vftable;
            local_8 = 0xffffffff;
            QWidget::setGeometry(pQVar3,local_44 + -0x96,local_30,0x96,0x32);
            pQVar4 = (QString *)QString::fromUtf8((char *)local_64,0x58eb0c);
            local_8 = 2;
            uVar2 = QColor::rgba(local_24);
            uVar5 = QString::number((uint)local_60,uVar2);
            _local_54 = CONCAT31(uStack_53,0x20);
            local_8._0_1_ = 3;
            QChar::QChar((QChar *)(aQStack_7e + -0xe));
            pQVar4 = (QString *)QString::arg(pQVar4,local_5c,uVar5);
            pQVar3 = local_58;
            local_8 = CONCAT31(local_8._1_3_,4);
            QWidget::setStyleSheet(local_58,pQVar4);
            QString::~QString(local_5c);
            QString::~QString(local_60);
            local_8 = 0xffffffff;
            QString::~QString(local_64);
            QLabel::setText((QLabel *)pQVar3,local_38);
            QLabel::setAlignment((QLabel *)pQVar3);
            ppvVar7 = local_4c;
            param_1 = local_68;
          }
          local_38 = local_38 + 4;
          local_48 = local_48 + 1;
          local_30 = local_30 + 0x3c;
          local_3c = local_3c + 0x10;
          pvVar6 = param_1[8];
        } while ((int)local_48 < (int)pvVar6);
      }
      local_34 = local_34 + 1;
    } while ((int)local_34 < (int)param_1[7]);
  }
  ExceptionList = local_10;
  return;
}


