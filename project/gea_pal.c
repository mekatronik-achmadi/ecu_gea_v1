#include "srcconf.h"

extern icucnt_t rpm;
extern adcsample_t adc_tps;

static WORKING_AREA(wa_iacThread, 128);
static msg_t iacThread(void *arg) {
  (void)arg;
  chRegSetThreadName("iac_control");
  while (TRUE) {
    if(rpm!=0){
      if(adc_tps<250){
	Iac_CCW();
      }
      else{
	Iac_CW();
      }
    }else{
      Iac_CCW();
    }
    chThdSleepMilliseconds(250);
  };
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
  
  IACA_L;IACB_L;IACC_L;IACD_L;interval;
  
  chThdCreateStatic(wa_iacThread, sizeof(wa_iacThread), NORMALPRIO, iacThread, NULL);
}

//maju
void Iac_CW(void){
  
  int i;
  for(i=0;i<20;i++){
    IACA_H;IACB_L;IACC_L;IACD_L;	interval;
    IACA_L;IACB_L;IACC_H;IACD_L;	interval;
    IACA_L;IACB_H;IACC_L;IACD_L;	interval;
    IACA_L;IACB_L;IACC_L;IACD_H;	interval;
    IACA_H;IACB_L;IACC_L;IACD_L;	interval;
    IACA_L;IACB_L;IACC_H;IACD_L;	interval;
    IACA_L;IACB_H;IACC_L;IACD_L;	interval;
    IACA_L;IACB_L;IACC_L;IACD_H;	interval;
  }
  
  IACA_L;IACB_L;IACC_L;IACD_L;	interval;
}

//mundur
void Iac_CCW(void){
  
  int i;
  for(i=0;i<20;i++){
    IACA_H;IACB_L;IACC_L;IACD_L;	interval;
    IACA_L;IACB_H;IACC_L;IACD_L;	interval;
    IACA_H;IACB_L;IACC_H;IACD_L;	interval;
    IACA_L;IACB_L;IACC_L;IACD_H;	interval;
    IACA_H;IACB_L;IACC_L;IACD_L;	interval;
    IACA_L;IACB_H;IACC_L;IACD_L;	interval;
    IACA_H;IACB_L;IACC_H;IACD_L;	interval;
    IACA_L;IACB_L;IACC_L;IACD_H;	interval;
  }
  
  IACA_L;IACB_L;IACC_L;IACD_L;	interval;
}