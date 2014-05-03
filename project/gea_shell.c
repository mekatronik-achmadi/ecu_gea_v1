#include "srcconf.h"

extern adcsample_t adc_tps_val,adc_tps_close,adc_tps_full;

extern uint16_t inj_data_off_deg[cdata];
extern uint16_t inj_data_dur_deg[cdata];
extern uint16_t ign_data_off_deg[cdata];

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
  
  chprintf(chp,"%4i\r\n",adc_tps_val);
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
  chprintf(chp,"tps data set");
  return;
}

static void cmd_read_tps(BaseSequentialStream *chp, int argc, char *argv[]){
  (void)argv;
  
  if(argc>0){
    chprintf(chp,"bad commands");
    return;
  }
  
  mem_adc(READ);
  chprintf(chp,"%4i,%4i\r\n",adc_tps_close,adc_tps_full);
  return;
}

static void cmd_save_injoff(BaseSequentialStream *chp, int argc, char *argv[]){
  if(argc!=11){
    chprintf(chp,"bad commands");
    return;
  }
  int i;
  for(i=0;i<cdata;i++){
    inj_data_off_deg[i]=atoi(argv[i]);
  };
  mem_inj_data_off_deg(SAVE);
  chprintf(chp,"injoff data set");
  return;
}

static void cmd_read_injoff(BaseSequentialStream *chp, int argc, char *argv[]){
  (void)argv;
  if(argc>0){
    chprintf(chp,"bad commands");
    return;
  }
  mem_inj_data_off_deg(READ);
  chprintf(chp,"%3i,%3i,%3i,%3i,%3i,%3i,%3i,%3i,%3i,%3i,%3i\r\n",
	 inj_data_off_deg[0],
	 inj_data_off_deg[1],
	 inj_data_off_deg[2],
	 inj_data_off_deg[3],
	 inj_data_off_deg[4],
	 inj_data_off_deg[5],
	 inj_data_off_deg[6],
	 inj_data_off_deg[7],
	 inj_data_off_deg[8],
	 inj_data_off_deg[9],
	 inj_data_off_deg[10]
	);
  return;
}

static void cmd_save_injdur(BaseSequentialStream *chp, int argc, char *argv[]){
  if(argc!=11){
    chprintf(chp,"bad commands");
    return;
  }
  int i;
  for(i=0;i<cdata;i++){
    inj_data_dur_deg[i]=atoi(argv[i]);
  };
  mem_inj_data_dur_deg(SAVE);
  return;
}

static void cmd_read_injdur(BaseSequentialStream *chp, int argc, char *argv[]){
  (void)argv;
  if(argc>0){
    chprintf(chp,"bad commands");
    return;
  }
  mem_inj_data_dur_deg(READ);
  chprintf(chp,"%3i,%3i,%3i,%3i,%3i,%3i,%3i,%3i,%3i,%3i,%3i\r\n",
	 inj_data_dur_deg[0],
	 inj_data_dur_deg[1],
	 inj_data_dur_deg[2],
	 inj_data_dur_deg[3],
	 inj_data_dur_deg[4],
	 inj_data_dur_deg[5],
	 inj_data_dur_deg[6],
	 inj_data_dur_deg[7],
	 inj_data_dur_deg[8],
	 inj_data_dur_deg[9],
	 inj_data_dur_deg[10]
	);
  return;
}

static void cmd_save_ignoff(BaseSequentialStream *chp, int argc, char *argv[]){
  if(argc!=11){
    chprintf(chp,"bad commands");
    return;
  }
  int i;
  for(i=0;i<cdata;i++){
    ign_data_off_deg[i]=atoi(argv[i]);
  };
  mem_ign_data_off_deg(SAVE);
  return;
}

static void cmd_read_ignoff(BaseSequentialStream *chp, int argc, char *argv[]){
  (void)argv;
  if(argc>0){
    chprintf(chp,"bad commands");
    return;
  }
  mem_inj_data_dur_deg(READ);
  chprintf(chp,"%3i,%3i,%3i,%3i,%3i,%3i,%3i,%3i,%3i,%3i,%3i\r\n",
	 ign_data_off_deg[0],
	 ign_data_off_deg[1],
	 ign_data_off_deg[2],
	 ign_data_off_deg[3],
	 ign_data_off_deg[4],
	 ign_data_off_deg[5],
	 ign_data_off_deg[6],
	 ign_data_off_deg[7],
	 ign_data_off_deg[8],
	 ign_data_off_deg[9],
	 ign_data_off_deg[10]
	);
  return;
}


static const ShellCommand commands[] = {
  {"data",cmd_data},
  {"tps_val",cmd_tps_val},
  {"save_tps",cmd_save_tps},
  {"read_tps",cmd_read_tps},
  {"save_injoff",cmd_save_injoff},
  {"read_injoff",cmd_read_injoff},
  {"save_injdur",cmd_save_injdur},
  {"read_injdur",cmd_read_injdur},
  {"save_ignoff",cmd_save_ignoff},
  {"read_ignoff",cmd_read_ignoff},
  {NULL, NULL}
};

static const ShellConfig shell_cfg1 = {
  (BaseSequentialStream *)&SD1,
  commands
};

void Serial_Setup(void){
  palSetPadMode(GPIOA,9,16);
  palSetPadMode(GPIOA,10,2);
  sdStart(&SD1,NULL);
  shellInit();
}

void Shell_Setup(void){
    if (!shelltp){
      shelltp = shellCreate(&shell_cfg1, SHELL_WA_SIZE, NORMALPRIO);} /* create shell tread */
    else if (chThdTerminated(shelltp)) {
      chThdRelease(shelltp);    /* Recovers memory of the previous shell.   */
      shelltp = NULL;           /* Triggers spawning of a new shell.        */
    }
}
