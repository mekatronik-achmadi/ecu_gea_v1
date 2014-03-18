#include "srcconf.h"

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
  chprintf((BaseSequentialStream *)&SD1,"data finished");
}

static void cmd_test(BaseSequentialStream *chp, int argc, char *argv[]) {
  (void)argv;
  int i;
  if(argc>0){
    chprintf(chp,"data\r\n");
    return;
  };
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
  chprintf((BaseSequentialStream *)&SD1,"test finished");
}

static const ShellCommand commands[] = {
  {"data",cmd_data},
  {"test",cmd_test},
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
