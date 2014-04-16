#include "srcconf.h"

extern adcsample_t adc_tps;
adcsample_t adc_tps_prev,adc_tps_dif;

uint8_t iac_stt,iac_stt_prev;

static WORKING_AREA(wa_iacThread, 128);
static msg_t iacThread(void *arg) {
  (void)arg;
  chRegSetThreadName("iac_control");
  while (TRUE) {
    /*
    if(adc_tps<300){
      iac_stt=0;
    }
    else if(adc_tps>=300){
      iac_stt=1;
    }
    
    if(iac_stt_prev!=iac_stt){
      if(iac_stt==0){
	for(i=0;i<range;i++){
	  Iac_CCW();
	};
	IACA_L;IACB_L;IACC_L;IACD_L;interval;
      }
      else if(iac_stt==1){
	for(i=0;i<range;i++){
	  Iac_CW();
	};
	IACA_L;IACB_L;IACC_L;IACD_L;interval;
      }
    }
    
    iac_stt_prev=iac_stt;
    
    chThdSleepMilliseconds(100);
    */
    
    
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
  
}

/*
maju
void Iac_CW(void){
  IACA_H;IACB_L;IACC_L;IACD_L;	interval;
  IACA_L;IACB_L;IACC_H;IACD_L;	interval;
  IACA_L;IACB_H;IACC_L;IACD_L;	interval;
  IACA_L;IACB_L;IACC_L;IACD_H;	interval;
  IACA_H;IACB_L;IACC_L;IACD_L;	interval;
  IACA_L;IACB_L;IACC_H;IACD_L;	interval;
  IACA_L;IACB_H;IACC_L;IACD_L;	interval;
  IACA_L;IACB_L;IACC_L;IACD_H;	interval;
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
}*/

/*
void Iac_CW(uint8_t loop){
  IACA_H;IACB_L;IACC_H;IACD_L; interval;interval;interval;
  uint8_t i;
  for(i=0;i<loop;i++){
    IACA_H;IACB_L;IACC_H;IACD_L; interval;//1
    IACA_H;IACB_L;IACC_L;IACD_L; interval;//2
    IACA_H;IACB_L;IACC_L;IACD_H; interval;//3
    IACA_L;IACB_L;IACC_L;IACD_H; interval;//4
    IACA_L;IACB_H;IACC_L;IACD_H; interval;//5
    IACA_L;IACB_H;IACC_L;IACD_L; interval;//6
    IACA_L;IACB_H;IACC_H;IACD_L; interval;//7
    IACA_L;IACB_L;IACC_H;IACD_L; interval;//8
  }
  IACA_L;IACB_L;IACC_L;IACD_L; interval;
}

//mundur
void Iac_CCW(uint8_t loop){
  IACA_H;IACB_L;IACC_H;IACD_L; interval;interval;interval;
  uint8_t i;
  for(i=0;i<loop;i++){
    IACA_L;IACB_L;IACC_H;IACD_L; interval;//8
    IACA_L;IACB_H;IACC_H;IACD_L; interval;//7
    IACA_L;IACB_H;IACC_L;IACD_L; interval;//6
    IACA_L;IACB_H;IACC_L;IACD_H; interval;//5
    IACA_L;IACB_L;IACC_L;IACD_H; interval;//4
    IACA_H;IACB_L;IACC_L;IACD_H; interval;//3
    IACA_H;IACB_L;IACC_L;IACD_L; interval;//2
    IACA_H;IACB_L;IACC_H;IACD_L; interval;//1
  }
  IACA_L;IACB_L;IACC_L;IACD_L; interval;
}*/

void Iac_CW(uint8_t loop){
  IACA_H;IACB_L;IACC_L;IACD_L; interval;interval;interval;
  uint8_t i;
  for(i=0;i<loop;i++){
    
  }
  IACA_L;IACB_L;IACC_L;IACD_L; interval;
}

//mundur
void Iac_CCW(uint8_t loop){
  IACA_H;IACB_L;IACC_L;IACD_L; interval;interval;interval;
  uint8_t i;
  for(i=0;i<loop;i++){
    
  }
  IACA_L;IACB_L;IACC_L;IACD_L; interval;
}

void Iac_Start(void){
  
  chThdCreateStatic(wa_iacThread, sizeof(wa_iacThread), NORMALPRIO, iacThread, NULL);
}