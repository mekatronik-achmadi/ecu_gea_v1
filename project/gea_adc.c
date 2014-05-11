#include "srcconf.h" 

static adcsample_t samples[ADC_GRP1_NUM_CHANNELS * ADC_GRP1_BUF_DEPTH];

adcsample_t adc_tps;
adcsample_t adc_tps_val,adc_tps_close,adc_tps_full;
uint32_t sum_adc_tps;

void adccb(ADCDriver *adcp, adcsample_t *buffer, size_t n){
  (void) buffer; (void) n;
  int i;
  if (adcp->state == ADC_COMPLETE) {
    sum_adc_tps=0;
    for(i=0;i<ADC_GRP1_BUF_DEPTH;i++){
	sum_adc_tps=sum_adc_tps+samples[0+(i*ADC_GRP1_NUM_CHANNELS)];
     }
     adc_tps_val=sum_adc_tps/10;
     
     if(adc_tps_full!=0){
       if(adc_tps_val>=adc_tps_close){adc_tps=100*(adc_tps_val-adc_tps_close)/(adc_tps_full-adc_tps_close);}
     }
   }
 }
 
 static const ADCConversionGroup adcgrpcfg = {
  FALSE,
  ADC_GRP1_NUM_CHANNELS,
  adccb,
  NULL,
  /* HW dependent part.*/
  0,
  0,
  ADC_SMPR2_SMP_AN0(ADC_SAMPLE_239P5),
  0,
  ADC_SQR1_NUM_CH(ADC_GRP1_NUM_CHANNELS),
  0,
  ADC_SQR3_SQ1_N(ADC_CHANNEL_IN0)
};

static WORKING_AREA(wa_adcThread, 128);
static msg_t adcThread(void *arg) {
  (void)arg;
  while (TRUE) {
    chThdSleepMilliseconds(100);
    adcStartConversion(&ADCD1, &adcgrpcfg, samples, ADC_GRP1_BUF_DEPTH);
  }
  return 0;
}

void Adc_Setup(void){
  palSetPadMode(GPIOA,0,PAL_MODE_INPUT_ANALOG);
  adcStart(&ADCD1, NULL);
  chThdCreateStatic(wa_adcThread, sizeof(wa_adcThread), NORMALPRIO, adcThread, NULL);
  adc_tps_full=1385;adc_tps_close=195;
}
