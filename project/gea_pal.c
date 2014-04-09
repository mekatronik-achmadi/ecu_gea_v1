#include "srcconf.h"

void Pal_Setup(void){
  palSetPadMode(GPIOA,led,PAL_MODE_OUTPUT_PUSHPULL);
  
  palSetPadMode(GPIOC,inj_1,PAL_MODE_OUTPUT_PUSHPULL);
  palSetPadMode(GPIOC,inj_2,PAL_MODE_OUTPUT_PUSHPULL);
  palSetPadMode(GPIOC,ign_1,PAL_MODE_OUTPUT_PUSHPULL);
  palSetPadMode(GPIOC,ign_2,PAL_MODE_OUTPUT_PUSHPULL);
  
  palSetPadMode(GPIOB,IACA,PAL_MODE_OUTPUT_PUSHPULL);
  palSetPadMode(GPIOB,IACB,PAL_MODE_OUTPUT_PUSHPULL);
  palSetPadMode(GPIOB,IACC,PAL_MODE_OUTPUT_PUSHPULL);
  palSetPadMode(GPIOB,IACD,PAL_MODE_OUTPUT_PUSHPULL);
}

#define interval 6

void Iac_up(void){
  // 1st phase
  IACA_H;IACB_L;
  IACC_L;IACD_L;
  chThdSleepMilliseconds(interval);
  
  // 2nd phase
  IACA_L;IACB_L;
  IACC_H;IACD_L;
  chThdSleepMilliseconds(interval);
  
  // 3rd phase
  IACA_L;IACB_H;
  IACC_L;IACD_L;
  chThdSleepMilliseconds(interval);
  
  // 4th phase
  IACA_L;IACB_L;
  IACC_L;IACD_H;
  chThdSleepMilliseconds(interval);
}

void Iac_down(void){
  // 1st phase
  IACA_L;IACB_H;
  IACC_L;IACD_L;
  chThdSleepMilliseconds(interval);
  
  // 2nd phase
  IACA_L;IACB_L;
  IACC_L;IACD_H;
  chThdSleepMilliseconds(interval);
  
  // 3rd phase
  IACA_H;IACB_L;
  IACC_L;IACD_L;
  chThdSleepMilliseconds(interval);
  
  // 4th phase
  IACA_L;IACB_L;
  IACC_H;IACD_L;
  chThdSleepMilliseconds(interval);
}
