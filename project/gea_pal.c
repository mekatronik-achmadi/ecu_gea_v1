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
  
  IACA_L;IACB_L;IACC_L;IACD_L;interval;
}

//maju
void Iac_CW(void){
  IACA_H;IACB_L;IACC_L;IACD_L;	interval;
  IACA_L;IACB_L;IACC_H;IACD_L;	interval;
  IACA_L;IACB_H;IACC_L;IACD_L;	interval;
  IACA_L;IACB_L;IACC_L;IACD_H;	interval;
  IACA_H;IACB_L;IACC_L;IACD_L;	interval;
  IACA_L;IACB_L;IACC_H;IACD_L;	interval;
  IACA_L;IACB_H;IACC_L;IACD_L;	interval;
  IACA_L;IACB_L;IACC_L;IACD_H;	interval;
  IACA_L;IACB_L;IACC_L;IACD_L;
}

//mundur
void Iac_CCW(void){
  IACA_H;IACB_L;IACC_L;IACD_L;	interval;
  IACA_L;IACB_H;IACC_L;IACD_L;	interval;
  IACA_H;IACB_L;IACC_H;IACD_L;	interval;
  IACA_L;IACB_L;IACC_L;IACD_H;	interval;
  IACA_H;IACB_L;IACC_L;IACD_L;	interval;
  IACA_L;IACB_H;IACC_L;IACD_L;	interval;
  IACA_H;IACB_L;IACC_H;IACD_L;	interval;
  IACA_L;IACB_L;IACC_L;IACD_H;	interval;
  IACA_L;IACB_L;IACC_L;IACD_L;
}
