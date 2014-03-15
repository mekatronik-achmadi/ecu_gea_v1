#include "srcconf.h"

icucnt_t last_period;
extern adcsample_t adc_tps;
extern icucnt_t rpm;

uint8_t v_ovf,v_data;

static WORKING_AREA(wa_ovfThread, 128);
static msg_t ovfThread(void *arg) {
  (void)arg;
  chRegSetThreadName("ovf_trigger");
  while (TRUE) {
    v_ovf++;
    if(v_ovf==5){
//       engine_ovf();
      v_ovf=0;
    }
    
    v_data++;
    if(v_data==5){
      v_data=0;
//       chprintf((BaseSequentialStream *)&SD1, "rpm = %6i tps= %4i \r\n",rpm,adc_tps);
    }
    chThdSleepMilliseconds(100);
  }
  return 0;
}

static void icuperiodcb(ICUDriver *icup) {
  last_period = icuGetPeriod(icup);
  v_ovf=0;
//   inj_calc();
//   ign_calc();
//   engine_calc();
}


static ICUConfig icucfg = {
  ICU_INPUT_ACTIVE_HIGH,
  F_ICU,                                  /* 10kHz ICU clock frequency.   */
  NULL,
  icuperiodcb,
  NULL,
  ICU_CHANNEL_2,
  0
};

void Icu_Setup(void){
  palSetPadMode(GPIOA, 7, PAL_MODE_INPUT_PULLDOWN );
  icuStart(&ICUD3, &icucfg);
  icuEnable(&ICUD3);
  chThdCreateStatic(wa_ovfThread, sizeof(wa_ovfThread), NORMALPRIO, ovfThread, NULL);
}