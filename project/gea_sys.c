#include "srcconf.h"

uint8_t inj_start,inj_stop;
uint8_t ign_start,ign_stop;
uint8_t toothcount;

extern adcsample_t adc_tps;

extern icucnt_t last_period;
icucnt_t prev_last_period,rpm,frekuensi,misstooth;

void inj_calc(void){
  if(adc_tps==0){inj_start=top_tooth-2;inj_stop=top_tooth-1;}
  else if((adc_tps>0)&&(adc_tps<250)){inj_start=top_tooth-3;inj_stop=top_tooth-1;}
  else if((adc_tps>=250)&&(adc_tps<500)){inj_start=top_tooth-5;inj_stop=top_tooth-1;}
  else if((adc_tps>=750)&&(adc_tps<1000)){inj_start=top_tooth-7;inj_stop=top_tooth-1;}
  else if((adc_tps>=1000)&&(adc_tps<1250)){inj_start=0;inj_stop=top_tooth-1;}
  else if(adc_tps>=1250){inj_start=22;inj_stop=top_tooth-1;}
}

void ign_calc(void){
  if((rpm>0)&&(rpm<2000)){ign_start=top_tooth-4;ign_stop=top_tooth-1;} 
  else if((rpm>2000)&&(rpm<3000)){ign_start=top_tooth-5;ign_stop=top_tooth-2;}
  else if((rpm>3000)&&(rpm<4000)){ign_start=top_tooth-5;ign_stop=top_tooth-2;}
  else if((rpm>4000)&&(rpm<5000)){ign_start=top_tooth-6;ign_stop=top_tooth-3;}
  else if((rpm>5000)&&(rpm<10000)){ign_start=top_tooth-5;ign_stop=top_tooth-2;}
  else if(rpm>15000){ign_start=top_tooth-5;ign_stop=top_tooth-2;}
}

void engine_calc(void){
  
  if(last_period > 0){
    misstooth = (prev_last_period*100) / last_period;
    prev_last_period =  last_period; 
    frekuensi = F_ICU / last_period;
  }
  toothcount++;
  rpm = frekuensi*60/(all_tooth+1);
}

void engine_set(void){
  
  if((misstooth>40)&&(misstooth<60)){toothcount=0;}
  if(toothcount==all_tooth){toothcount=0;}
  if(toothcount==all_tooth+1){toothcount=1;} 
  
  if(toothcount==ign_start){on_ign1;on_ign2;}
  if(toothcount==ign_stop){off_ign1;off_ign2;}
  
  if(toothcount==inj_start){on_inj1;on_inj2;}
  if(toothcount==inj_stop){off_inj1;off_inj2;}
  
}

void engine_ovf(void){
  
  no_pulse;
  frekuensi = 0;
  rpm=0;
  misstooth=0;

  off_inj1;
  off_inj2;
  off_ign1;
  off_ign2;

}
