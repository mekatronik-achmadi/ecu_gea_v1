#include "srcconf.h"

extern adcsample_t adc_tps;
extern icucnt_t rpm;

static WORKING_AREA(wa_pumpThread, 128);
static msg_t pumpThread(void *arg) {
  (void)arg;
  while (TRUE) {
    on_pump;
    chThdSleepMilliseconds(10000);
    off_pump;
    chThdSleepMilliseconds(10000);
  }
  return 0;
}

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

  palSetPadMode(GPIOB,pump,PAL_MODE_OUTPUT_PUSHPULL);
  chThdCreateStatic(wa_pumpThread, sizeof(wa_pumpThread), NORMALPRIO, pumpThread, NULL);

  chThdSleepMilliseconds(500);
  palSetPadMode(GPIOB,output,PAL_MODE_OUTPUT_PUSHPULL);
  out_active;
}

//maju
void Iac_CW(uint8_t loop){
  IACA_H;IACB_L;IACC_L;IACD_L; interval;interval;interval;
  uint8_t i;
  for(i=0;i<loop;i++){
    IACA_H;IACB_L;IACC_L;IACD_L; interval;
    IACA_L;IACB_L;IACC_H;IACD_L; interval;
    IACA_L;IACB_H;IACC_L;IACD_L; interval;
    IACA_L;IACB_L;IACC_L;IACD_H; interval;
  }
  IACA_L;IACB_L;IACC_L;IACD_L; interval;
}

//mundur
void Iac_CCW(uint8_t loop){
  IACA_H;IACB_L;IACC_L;IACD_L; interval;interval;interval;
  uint8_t i;
  for(i=0;i<loop;i++){
    IACA_H;IACB_L;IACC_L;IACD_L; interval;
    IACA_L;IACB_H;IACC_H;IACD_L; interval;
    IACA_L;IACB_L;IACC_H;IACD_L; interval;
    IACA_L;IACB_L;IACC_L;IACD_H; interval;
  }
  IACA_L;IACB_L;IACC_L;IACD_L; interval;
}
