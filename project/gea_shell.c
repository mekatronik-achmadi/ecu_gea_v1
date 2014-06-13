#include "srcconf.h"

extern adcsample_t adc_tps_val,adc_tps_close,adc_tps_full;

extern uint16_t inj_data_ms_perc[cdata][cdata];
extern uint16_t ign_data_off_deg[cdata][cdata];

extern uint16_t inj_ms_base,inj_open_time;

Thread *shelltp = NULL;

static void cmd_data(BaseSequentialStream *chp, int argc, char *argv[]) {
  (void)argv;
  
  if(argc>0){
    chprintf(chp,"bad commands");
    return;
  }
  
  data_send();
  return;
}

static void cmd_tps_val(BaseSequentialStream *chp, int argc, char *argv[]) {
  (void)argv;
  
  if(argc>0){
    chprintf(chp,"bad commands");
    return;
  }
  
  chprintf(chp,"%i\n",adc_tps_val);
  return;
}

static void cmd_save_tps(BaseSequentialStream *chp, int argc, char *argv[]){
  
  if(argc!=2){
    chprintf(chp,"bad commands");
    return;
  }
  
  adc_tps_close=atoi(argv[0]);
  adc_tps_full=atoi(argv[1]);
  mem_adc(SAVE);
  
  return;
}

static void cmd_read_tps(BaseSequentialStream *chp, int argc, char *argv[]){
  (void)argv;
  
  if(argc>0){
    chprintf(chp,"bad commands");
    return;
  }
  
  mem_adc(READ);
  chprintf(chp,"%i,%i\n",adc_tps_close,adc_tps_full);
  return;
}

static void cmd_save_injec(BaseSequentialStream *chp, int argc, char *argv[]){
  
  if(argc!=2){
    chprintf(chp,"bad commands");
    return;
  }
  
  inj_ms_base=atoi(argv[0]);
  inj_open_time=atoi(argv[1]);
  mem_injec(SAVE);
  
  return;
}

static void cmd_read_injec(BaseSequentialStream *chp, int argc, char *argv[]){
  (void)argv;
  
  if(argc>0){
    chprintf(chp,"bad commands");
    return;
  }
  
  mem_injec(READ);
  chprintf(chp,"%i,%i\n",inj_ms_base,inj_open_time);
  return;
}

static void cmd_save_inj(BaseSequentialStream *chp, int argc, char *argv[]){
  if(argc!=3){
    chprintf(chp,"bad commands");
    return;
  }
  int i,j,inj_data;
  
  i=atoi(argv[0]);
  j=atoi(argv[1]);
  inj_data=atoi(argv[2]);
  
  inj_data_ms_perc[i][j]=inj_data;
  
  mem_inj_data(i,j,SAVE);
  
  return;
}


static void cmd_read_inj(BaseSequentialStream *chp, int argc, char *argv[]){
  (void)argv;
  if(argc!=2){
    chprintf(chp,"bad commands");
    return;
  }
  int i,j,inj_data;
  
  i=atoi(argv[0]);
  j=atoi(argv[1]);
  
  mem_inj_data(i,j,READ);
  
  inj_data=inj_data_ms_perc[i][j];
  
  chprintf(chp,"%i,%i,%i\n",i,j,inj_data); 
  return;
}

static void cmd_save_ign(BaseSequentialStream *chp, int argc, char *argv[]){
  if(argc!=3){
    chprintf(chp,"bad commands");
    return;
  }
  int i,j,ign_data;
  
  i=atoi(argv[0]);
  j=atoi(argv[1]);
  ign_data=atoi(argv[2]);
  
  ign_data_off_deg[i][j]=ign_data;
  
  mem_ign_data(i,j,SAVE);
  
  return;
}


static void cmd_read_ign(BaseSequentialStream *chp, int argc, char *argv[]){
  (void)argv;
  if(argc!=2){
    chprintf(chp,"bad commands");
    return;
  }
  int i,j,ign_data;
  
  i=atoi(argv[0]);
  j=atoi(argv[1]);
  
  mem_ign_data(i,j,READ);
  
  ign_data=ign_data_off_deg[i][j];
  
  chprintf(chp,"%i,%i,%i\n",i,j,ign_data); 
  return;
}

static void cmd_iac_up(BaseSequentialStream *chp, int argc, char *argv[]){
  if(argc!=1){
    chprintf(chp,"bad commands");
    return;
  }
  Iac_CW(atoi(argv[0]));
  chprintf(chp,"iac up for %i\n",atoi(argv[0]));
  return;
}

static void cmd_iac_down(BaseSequentialStream *chp, int argc, char *argv[]){
  if(argc!=1){
    chprintf(chp,"bad commands");
    return;
  }
  Iac_CCW(atoi(argv[0]));
  chprintf(chp,"iac down for %i\n",atoi(argv[0]));
  return;
}

static const ShellCommand commands[] = {
  {"data",cmd_data},
  
  {"tps_val",cmd_tps_val},
  {"save_tps",cmd_save_tps},
  {"read_tps",cmd_read_tps},
  
  {"save_injec",cmd_save_injec},
  {"read_injec",cmd_read_injec},
  
  {"save_inj",cmd_save_inj},
  {"read_inj",cmd_read_inj},
  
  {"save_ign",cmd_save_ign},
  {"read_ign",cmd_read_ign},

  {"iac_up",cmd_iac_up},
  {"iac_down",cmd_iac_down},
  {NULL, NULL}
};

static const ShellConfig shell_cfg1 = {
  (BaseSequentialStream *)&SD1,
  commands
};

/*
static WORKING_AREA(wa_dataThread, 128);
static msg_t dataThread(void *arg) {
  (void)arg;
  while (TRUE) {
    data_send();
    chThdSleepMilliseconds(500);   
  }
  return 0;
}
*/

void Serial_Setup(void){
  palSetPadMode(GPIOA,9,16);
  palSetPadMode(GPIOA,10,2);
  sdStart(&SD1,NULL);
  shellInit();
  //chThdCreateStatic(wa_dataThread, sizeof(wa_dataThread), NORMALPRIO, dataThread, NULL);
}

void Shell_Setup(void){
    if (!shelltp){
      shelltp = shellCreate(&shell_cfg1, SHELL_WA_SIZE, NORMALPRIO);} /* create shell tread */
    else if (chThdTerminated(shelltp)) {
      chThdRelease(shelltp);    /* Recovers memory of the previous shell.   */
      shelltp = NULL;           /* Triggers spawning of a new shell.        */
    }
}
