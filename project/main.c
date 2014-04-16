#include "srcconf.h"

uint16_t i;

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
  Pal_Setup();
  Serial_Setup();
  Icu_Setup();
  Adc_Setup();
  Gpt_Setup();
  
  palSetPad(GPIOA,led);
  
//   Iac_Start();
  
  while (TRUE) {   
    Shell_Setup(); /* create shell */
    chThdSleepMilliseconds(500);
  };
}
