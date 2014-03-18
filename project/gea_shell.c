#include "srcconf.h"

uint8_t datatest=0,datatest_count=0;

Thread *shelltp = NULL;

static WORKING_AREA(wa_datatestThread, 128);
static msg_t datatestThread(void *arg) {
  (void)arg;
  chRegSetThreadName("adc_trigger");
  while (TRUE) {
    if(datatest==1){
      data_send();
      chThdSleepMilliseconds(500);
      datatest_count++;
    }
    else if(datatest==2){
      on_inj1;
      on_inj2;
      on_ign1;
      on_ign2;
      palClearPad(GPIOA,led);
      chThdSleepMilliseconds(500);
      off_inj1;
      off_inj2;
      off_ign1;
      off_ign2;
      palSetPad(GPIOA,led);
      chThdSleepMilliseconds(500);
      datatest_count++;
    }
    
    if(datatest_count==15){
      datatest=0;
    }
    
  }
  return 0;
}

static void cmd_data(BaseSequentialStream *chp, int argc, char *argv[]) {
  (void)argv;
  if(argc>0){
    chprintf(chp,"data\r\n");
    return;
  };
  datatest=1;
}

static void cmd_test(BaseSequentialStream *chp, int argc, char *argv[]) {
  (void)argv;
  if(argc>0){
    chprintf(chp,"data\r\n");
    return;
  };
  datatest=2;
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
  chThdCreateStatic(wa_datatestThread, sizeof(wa_datatestThread), NORMALPRIO, datatestThread, NULL);
}

void Shell_Setup(void){
  if (!shelltp)
      shelltp = shellCreate(&shell_cfg1, SHELL_WA_SIZE, NORMALPRIO); /* create shell tread */
    else if (chThdTerminated(shelltp)) {
      chThdRelease(shelltp);    /* Recovers memory of the previous shell.   */
      shelltp = NULL;           /* Triggers spawning of a new shell.        */
    }
    chThdSleepMilliseconds(1000);
}
