#include "srcconf.h"

Thread *shelltp = NULL;

static void cmd_num(BaseSequentialStream *chp, int argc, char *argv[]) {
  (void)argv;
  int num=0;
  if (argc != 1) {
    chprintf(chp, "Usage: nomer [nomer] piye to bos?\r\n");
    return;
  }
  num = atoi(argv[0]);
  chprintf(chp,"your number is %4i\r\n",num);
}

static void cmd_start(BaseSequentialStream *chp, int argc, char *argv[]) {
  (void)argv;
  if(argc>0){
    chprintf(chp,"Serial Shell Connected!\r\n");
    return;
  };
  chprintf(chp,"Serial Shell Connected!\r\n");
}

static void cmd_mem(BaseSequentialStream *chp, int argc, char *argv[]) {
  size_t n, size;

  (void)argv;
  if (argc > 0) {
    chprintf(chp, "Usage: mem\r\n");
    return;
  }
  n = chHeapStatus(NULL, &size);
  chprintf(chp, "core free memory : %u bytes\r\n", chCoreStatus());
  chprintf(chp, "heap fragments   : %u\r\n", n);
  chprintf(chp, "heap free total  : %u bytes\r\n", size);
}

static const ShellCommand commands[] = {
  {"mem", cmd_mem},
  {"num",cmd_num},
  {"ok",cmd_start},
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
//   shellInit();
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
