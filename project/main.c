#include "srcconf.h"

uint8_t i;

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
  
  IACA_H;IACB_L;
  IACC_L;IACD_L;
  
  /*
   * Normal main() thread activity, in this demo it does nothing except
   * sleeping in a loop and check the button state.
   */
  palSetPad(GPIOA,led);
  
  while (TRUE) {
    
    Shell_Setup(); /* create shell */
    chThdSleepMilliseconds(500);
//     for(i=0;i<5;i++){
//       Iac_up();
//     };
//     for(i=0;i<5;i++){
//       Iac_down();
//     };
  };
}
