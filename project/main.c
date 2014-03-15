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
  Serial_Setup();
  Pal_Setup();
  Icu_Setup();
  Adc_Setup();
  Gpt_Setup();
  
  /*
   * Normal main() thread activity, in this demo it does nothing except
   * sleeping in a loop and check the button state.
   */
  while (TRUE) {
    Shell_Setup(); /* create shell */
    chThdSleepMilliseconds(500);
  }
}
