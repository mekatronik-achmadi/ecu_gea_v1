#include "srcconf.h"

/*
 * Application entry point.
 */
int main(void) {
  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();
  
  /*
   * Project defined HAL Setup
   */
//   Mem_Setup();
  Pal_Setup();
  Serial_Setup();
  Icu_Setup();
  Adc_Setup();
  Gpt_Setup();
  
  palSetPad(GPIOA,led);
  
  while (TRUE) {   
    Shell_Setup(); /* create shell */
    chThdSleepMilliseconds(500);
  };
}
