#include "srcconf.h"

uint8_t stt_run=0;

Thread *shelltp = NULL;

static void cmd_data(BaseSequentialStream *chp, int argc, char *argv[]) {
  (void)argv;
  int i;
  if(argc>0){
    chprintf(chp,"data\r\n");
    return;
  };
  for(i=0;i<15;i++){
    data_send();
    chThdSleepMilliseconds(500);
  };
  chprintf((BaseSequentialStream *)&SD1,"data finished\r\n");
  return;
}

static void cmd_test(BaseSequentialStream *chp, int argc, char *argv[]) {
  (void)argv;
  int i;
  if(argc>0){
    chprintf(chp,"test\r\n");
    return;
  };
  if(stt_run==0){
    for(i=0;i<15;i++){
      on_inj1;
      on_inj2;
      on_ign1;
      on_ign2;
      chThdSleepMilliseconds(25);
      off_inj1;
      off_inj2;
      off_ign1;
      off_ign2;
      chThdSleepMilliseconds(25);
    };
  }
  else{
    chprintf((BaseSequentialStream *)&SD1,"test cannot run during running conditions\r\n");
  }
  chprintf((BaseSequentialStream *)&SD1,"test finished\r\n");
  return;
}

static void cmd_iacup(BaseSequentialStream *chp, int argc, char *argv[]) {
  (void)argv;
  uint16_t i;
  if(argc>0){
    chprintf(chp,"iac up\r\n");
    return;
  };
  for(i=0;i<10;i++){
    Iac_CW();
  };
  chprintf((BaseSequentialStream *)&SD1,"IAC up test finished\r\n");
  return;
}

static void cmd_iacdown(BaseSequentialStream *chp, int argc, char *argv[]) {
  (void)argv;
  uint16_t i;
  if(argc>0){
    chprintf(chp,"iac down\r\n");
    return;
  };
  for(i=0;i<10;i++){
    Iac_CCW();
  }
  chprintf((BaseSequentialStream *)&SD1,"IAC down test finished\r\n");
  return;
}

static const ShellCommand commands[] = {
  {"data",cmd_data},
  {"test",cmd_test},
  {"iacup",cmd_iacup},
  {"iacdown",cmd_iacdown},
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
  /*
   * Shell manager initialization.
   */
  shellInit();
}

void Shell_Setup(void){
  if (!shelltp)
      shelltp = shellCreate(&shell_cfg1, SHELL_WA_SIZE, NORMALPRIO); /* create shell tread */
    else if (chThdTerminated(shelltp)) {
      chThdRelease(shelltp);    /* Recovers memory of the previous shell.   */
      shelltp = NULL;           /* Triggers spawning of a new shell.        */
    }
}
