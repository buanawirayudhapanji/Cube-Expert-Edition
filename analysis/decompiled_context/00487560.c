
char * __thiscall FUN_00487560(undefined4 param_1,char *param_2,uint param_3)

{
  QString::asprintf(param_2,"%d.%d.%d",param_3 >> 0x10 & 0xff,param_3 >> 8 & 0xff,param_3 & 0xff,
                    param_1);
  return param_2;
}


