
undefined4 __thiscall
FUN_00507ba0(int param_1,void *param_2,uint param_3,uint *param_4,undefined4 *param_5,
            size_t *param_6,undefined4 param_7)

{
  char cVar1;
  char *pcVar2;
  QMessageLogger *this;
  QMessageLogger *this_00;
  int iVar3;
  QMessageLogger local_1c [20];
  int local_8;
  
  local_8 = 0;
  iVar3 = param_3 + 0xf;
  cVar1 = FUN_00507fc0(param_1 + 0xc864,iVar3,&local_8,param_7);
  if (cVar1 != '\0') {
    if (*(char *)(param_1 + 0xc866) == '#') {
      if (iVar3 != local_8) {
        FUN_00486c20("Data length error,need %d bytes,got %d bytes",iVar3,local_8);
        return 0;
      }
      param_3 = (uint)*(uint3 *)(param_1 + 0xc867);
      cVar1 = FUN_00507970((byte *)(param_1 + 0xc86a),param_3,
                           *(undefined1 *)(param_3 + 0xc86a + param_1));
      if (cVar1 == '\0') {
        pcVar2 = (char *)QMessageLogger::QMessageLogger(local_1c,(char *)0x0,0,(char *)0x0);
        QMessageLogger::debug(this_00,pcVar2,"get_upload_responds::Checksum error!\n");
        return 0;
      }
      *param_4 = (uint)*(byte *)(param_1 + 0xc86a);
      *param_5 = *(undefined4 *)(param_1 + 0xc86b);
      *param_6 = 0;
      *(undefined2 *)param_6 = *(undefined2 *)(param_1 + 0xc86f);
      *(undefined1 *)((int)param_6 + 2) = *(undefined1 *)(param_1 + 0xc871);
      memcpy(param_2,(void *)(param_1 + 0xc872),*param_6);
      return 1;
    }
    pcVar2 = (char *)QMessageLogger::QMessageLogger(local_1c,(char *)0x0,0,(char *)0x0);
    QMessageLogger::debug(this,pcVar2,"get_upload_responds::Data type not 0x23!\n");
  }
  return 0;
}


