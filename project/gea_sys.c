#include "srcconf.h"

// uint8_t inj_start,inj_stop;
// uint8_t ign_start,ign_stop;

extern adcsample_t adc_tps;

extern icucnt_t last_period;
icucnt_t prev_last_period,rpm,frekuensi,misstooth;

uint8_t toothcount;
uint8_t inj_phase,ign_phase;

static const uint16_t inj_data_off_deg[7]={10,12,14,16,18,20,25};
static const uint16_t inj_data_dur_deg[7]={15,20,25,30,35,40,45};
static const uint16_t data_tps[7]={0,250,500,750,1000,1250};

static const uint16_t ign_data_off_deg[7]={10,12,15,18,19,20,21};
static const uint16_t data_rpm[7]={0,1000,2000,3000,4000,5000,6000};

static const uint16_t ign_dur_deg=30,flow_rate=40;

uint16_t inj_off_deg,inj_dur_deg,inj_dur_tick,inj_on_deg,inj_on_tick;
uint16_t ign_off_deg,ign_dur_tick,ign_on_deg,ign_on_tick;

void inj_calc(void){
//   if(adc_tps==0){inj_start=top_tooth-2;inj_stop=top_tooth-1;}
//   else if((adc_tps>0)&&(adc_tps<250)){inj_start=top_tooth-3;inj_stop=top_tooth-1;}
//   else if((adc_tps>=250)&&(adc_tps<500)){inj_start=top_tooth-5;inj_stop=top_tooth-1;}
//   else if((adc_tps>=750)&&(adc_tps<1000)){inj_start=top_tooth-7;inj_stop=top_tooth-1;}
//   else if((adc_tps>=1000)&&(adc_tps<1250)){inj_start=0;inj_stop=top_tooth-1;}
//   else if(adc_tps>=1250){inj_start=22;inj_stop=top_tooth-1;}
    int i;
    for(i=0;i<5;i++){
        if((adc_tps>=data_tps[i])&&(adc_tps<data_tps[i+1])){
            inj_dur_deg=inj_data_dur_deg[i]+ ((inj_data_dur_deg[i+1]-inj_data_dur_deg[i])*(adc_tps-data_tps[i])/(data_tps[i+1]-data_tps[i]));
            inj_off_deg=inj_data_off_deg[i]+ ((inj_data_off_deg[i+1]-inj_data_off_deg[i])*(adc_tps-data_tps[i])/(data_tps[i+1]-data_tps[i]));
        }
    };

    if(adc_tps<data_tps[0]){
        inj_dur_deg=inj_data_dur_deg[0];
        inj_off_deg=inj_data_off_deg[0];
    }

    if(adc_tps>=data_tps[5]){
        inj_dur_deg=inj_data_dur_deg[5];
        inj_off_deg=inj_data_off_deg[5];
    }

    inj_on_deg=180-inj_dur_deg-inj_off_deg;

    inj_dur_tick=(inj_dur_deg/15)*(F_GPT/rpm)*(60/24);
    inj_on_tick=(inj_on_deg/15)*(F_GPT/rpm)*(60/24);
    
}

void ign_calc(void){
//   if((rpm>0)&&(rpm<2000)){ign_start=top_tooth-4;ign_stop=top_tooth-1;} 
//   else if((rpm>2000)&&(rpm<3000)){ign_start=top_tooth-5;ign_stop=top_tooth-2;}
//   else if((rpm>3000)&&(rpm<4000)){ign_start=top_tooth-5;ign_stop=top_tooth-2;}
//   else if((rpm>4000)&&(rpm<5000)){ign_start=top_tooth-6;ign_stop=top_tooth-3;}
//   else if((rpm>5000)&&(rpm<10000)){ign_start=top_tooth-5;ign_stop=top_tooth-2;}
//   else if(rpm>15000){ign_start=top_tooth-5;ign_stop=top_tooth-2;}
    int i;
    for(i=0;i<5;i++){
        if((rpm>=data_rpm[i])&&(rpm<data_rpm[i+1])){
            ign_off_deg=ign_data_off_deg[i]+ ((ign_data_off_deg[i+1]-ign_data_off_deg[i])*(rpm-data_rpm[i])/(data_rpm[i+1]-data_rpm[i]));
        }
    };

    if(rpm<data_rpm[0]){
        ign_off_deg=ign_data_off_deg[0];
    }

    if(rpm>=data_rpm[5]){
        ign_off_deg=ign_data_off_deg[5];
    }

    ign_on_deg=180-ign_dur_deg-ign_off_deg;

    ign_dur_tick=(ign_dur_deg/15)*(F_GPT/rpm)*(60/24);
    ign_on_tick=(ign_on_deg/15)*(F_GPT/rpm)*(60/24);
}

void engine_calc(void){
  if(last_period > 0){
    misstooth = (prev_last_period*100) / last_period;
    prev_last_period =  last_period; 
  } 
  
  if((misstooth>40)&&(misstooth<60)){  
    toothcount=0;
  }
  else{
    frekuensi = F_ICU / last_period;
    rpm = frekuensi*60/(all_tooth+1);
    toothcount++;
    if(toothcount==all_tooth){toothcount=0;}
    if(toothcount==all_tooth+1){toothcount=1;} 
  }
}

void engine_set(void){
//     if(toothcount==ign_start){on_ign1;on_ign2;}
//     if(toothcount==ign_stop){off_ign1;off_ign2;}
//   
//     if(toothcount==inj_start){on_inj1;on_inj2;}
//     if(toothcount==inj_stop){off_inj1;off_inj2;}
  if(toothcount==bottom_tooth){
    inj_phase=0;
    ign_phase=0;
    
    chSysLockFromIsr();
    gptStartOneShotI(&GPTD2, inj_on_tick);
    chSysUnlockFromIsr();
    
    chSysLockFromIsr();
    gptStartOneShotI(&GPTD4, ign_on_tick);
    chSysUnlockFromIsr();
  }
}

void inj_out(void){
  if(inj_phase==0){
    on_inj1;
    on_inj2;
    inj_phase=1;
    chSysLockFromIsr();
    gptStartOneShotI(&GPTD2, inj_dur_tick);
    chSysUnlockFromIsr();
  }
  else if(inj_phase==1){
    off_inj1;
    off_inj2;
  }
}

void ign_out(void){
  if(ign_phase==0){
    on_ign1;
    on_ign2;
    ign_phase=1;
    chSysLockFromIsr();
    gptStartOneShotI(&GPTD4, ign_dur_tick);
    chSysUnlockFromIsr();
  }
  else if(ign_phase==1){
    off_ign1;
    off_ign2;
  }
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

void data_send(void){
  chprintf((BaseSequentialStream *)&SD1, "rpm = %6i tps= %4i \r\n",rpm,adc_tps);
}
