#include "srcconf.h"

extern uint8_t stt_run;

extern adcsample_t adc_tps;

extern icucnt_t last_period;
icucnt_t prev_last_period,rpm,frekuensi,misstooth;

uint8_t toothcount;
uint8_t inj_phase,ign_phase;

uint16_t inj_data_off_deg[cdata]={10,12,14,16,18,20,25,25,25,25,25};
uint16_t inj_data_dur_deg[cdata]={25,30,35,40,45,50,55,60,65,70,75};
uint16_t data_tps[cdata]={0,10,20,30,40,50,60,70,80,90,100};

uint16_t ign_data_off_deg[cdata]={10,12,15,18,19,20,21,21,23,23,21};
uint16_t data_rpm[cdata]={0,500,1500,2000,2500,3000,3500,4000,4500,5000,5500};

uint16_t ign_dur_deg=30,flow_rate=40;

uint16_t inj_off_deg,inj_dur_deg,inj_dur_tick,inj_on_deg,inj_on_tick;
uint16_t ign_off_deg,ign_dur_tick,ign_on_deg,ign_on_tick;

uint16_t rps,rot_tick,deg_rot_tick;

void inj_calc(void){
    int i;
    for(i=0;i<cdata-2;i++){
        if((adc_tps>=data_tps[i])&&(adc_tps<data_tps[i+1])){
            inj_dur_deg=inj_data_dur_deg[i]+ ((inj_data_dur_deg[i+1]-inj_data_dur_deg[i])*(adc_tps-data_tps[i])/(data_tps[i+1]-data_tps[i]));
            inj_off_deg=inj_data_off_deg[i]+ ((inj_data_off_deg[i+1]-inj_data_off_deg[i])*(adc_tps-data_tps[i])/(data_tps[i+1]-data_tps[i]));
        }
    };

    if(adc_tps<data_tps[0]){
        inj_dur_deg=inj_data_dur_deg[0];
        inj_off_deg=inj_data_off_deg[0];
    }

    if(adc_tps>=data_tps[cdata-1]){
        inj_dur_deg=inj_data_dur_deg[cdata-1];
        inj_off_deg=inj_data_off_deg[cdata-1];
    }

    inj_on_deg=180-inj_dur_deg-inj_off_deg;

    inj_dur_tick=inj_dur_deg*deg_rot_tick;
    inj_on_tick =inj_on_deg*deg_rot_tick;
    
}

void ign_calc(void){
    int i;
    for(i=0;i<cdata-2;i++){
        if((rpm>=data_rpm[i])&&(rpm<data_rpm[i+1])){
            ign_off_deg=ign_data_off_deg[i]+ ((ign_data_off_deg[i+1]-ign_data_off_deg[i])*(rpm-data_rpm[i])/(data_rpm[i+1]-data_rpm[i]));
        }
    };

    if(rpm<data_rpm[0]){
        ign_off_deg=ign_data_off_deg[0];
    }

    if(rpm>=data_rpm[cdata-1]){
        ign_off_deg=ign_data_off_deg[cdata-1];
    }

    ign_on_deg=180-ign_dur_deg-ign_off_deg;

    ign_dur_tick=ign_dur_deg*deg_rot_tick;
    ign_on_tick=ign_on_deg*deg_rot_tick;
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
    
    rps=rpm/60;
    rot_tick=F_GPT/rps;
    deg_rot_tick=rot_tick/360;
    
    toothcount++;
  }
  
  if(toothcount==all_tooth+1){toothcount=0;}
  if(toothcount==all_tooth+2){toothcount=1;} 
}

void engine_set(void){
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
  chprintf((BaseSequentialStream *)&SD1, "%6i,%6i,%6i,%6i,%6i,%6i,%6i,%6i\r\n",
	   rpm,
	   adc_tps,
	   ign_dur_deg,
	   ign_dur_tick,
	   ign_off_deg,
	   inj_dur_deg,
	   inj_dur_tick,
	   inj_off_deg
	  );
}
