#include "srcconf.h"
extern icucnt_t rpm;
uint8_t iac_stt,iac_stt_prev;

static WORKING_AREA(wa_iacThread, 128);
static msg_t iacThread(void *arg) {
  (void)arg;
  chRegSetThreadName("iac_control");
  while (TRUE) {
    
    if(rpm<1000){
      iac_stt=0;
    }
    else if(rpm>=1000){
      iac_stt=1;
    }
    
    if(iac_stt_prev!=iac_stt){
      if(iac_stt==0){
	Iac_CCW(30);
      }
      else if(iac_stt==1){
	Iac_CW(30);
      }
    }
    
    iac_stt_prev=iac_stt;
    
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

void Iac_Start(void){
  Iac_CCW(30);
  interval;
  Iac_CCW(30);
  interval;
  Iac_CW(30);
  chThdCreateStatic(wa_iacThread, sizeof(wa_iacThread), NORMALPRIO, iacThread, NULL);
}