#include "srcconf.h"

extern adcsample_t adc_tps;

extern icucnt_t last_period;
icucnt_t prev_last_period,rpm,frekuensi,misstooth;

uint8_t toothcount;

uint16_t inj_data_dur_deg[cdata][cdata]={
  
  //    500,	750,	1000,	1250,	1500,	2000,	2500,	3000,	4000,	5000,	5500,	6000
  {	44,	26,	13,	 4,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0}, // 0
  {	26,	29,	33,	35,	37,	40,	42,	44,	51,	55,	57,	59}, // 10
  {	28,	30,	34,	37,	39,	41,	43,	45,	52,	56,	59,	61}, // 15
  {	29,	32,	36,	38,	40,	43,	45,	47,	54,	58,	60,	62}, // 20
  {	36,	38,	43,	45,	48,	50,	52,	54,	61,	65,	68,	70}, // 30
  {	38,	40,	44,	46,	48,	51,	54,	56,	63,	67,	70,	74}, // 40
  {	40,	42,	47,	48,	50,	52,	57,	57,	62,	70,	72,	74}, // 50
  {	42,	45,	50,	52,	55,	57,	62,	62,	69,	75,	77,	80}, // 60
  {	44,	47,	51,	53,	56,	59,	62,	62,	74,	79,	82,	84}, // 70
  {	45,	48,	52,	55,	57,	59,	64,	64,	74,	81,	82,	84}, // 80
  {	47,	49,	54,	97,	97,	97,	97,	97,	88,	88,	88,	88}, // 90
  {	48,	50,	57,	97,	97,	97,	97,	97,	88,	88,	88,	88}  // 100
};


uint16_t ign_data_off_deg[cdata][cdata]={
  
  //    500,	750,	1000,	1250,	1500,	2000,	2500,	3000,	4000,	5000,	5500,	6000
  {	10,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30}, // 0
  {	10,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30}, // 10
  {	10,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30}, // 15
  {	10,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30}, // 20
  {	10,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30}, // 30
  {	10,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30}, // 40
  {	10,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30}, // 50
  {	10,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30}, // 60
  {	10,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30}, // 70
  {	10,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30}, // 80
  {	10,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30}, // 90
  {	10,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30}  // 100
};

uint16_t data_tps[cdata]={0,10,15,20,30,40,50,60,70,80,90,100};
uint16_t data_rpm[cdata]={500,750,1000,1250,1500,2000,2500,3000,4000,5000,5500,6000};

uint16_t inj_dur_deg,inj_dur_deg_out,inj_on_deg,inj_on_tick;
uint16_t ign_off_deg,ign_off_deg_out,ign_off_tick;

uint16_t one_deg_tick,deg_per_tooth;

uint8_t rpm_index,tps_index,rpm_fx;

void inj_ign(void){
  
    int i;
    
    
    for(i=0;i<cdata-2;i++){
        if((rpm>=data_rpm[i])&&(rpm<data_rpm[i+1])){
	  rpm_index=i;
        }
    };
    
    if(rpm<data_rpm[0]){
        rpm_index=0;
    }

    if(rpm>=data_rpm[cdata-1]){
        rpm_index=cdata-1;
    }
    
  
  
    for(i=0;i<cdata-2;i++){
        if((adc_tps>=data_tps[i])&&(adc_tps<data_tps[i+1])){
	  tps_index=i;
        }
    };

    if(adc_tps<data_tps[0]){
        tps_index=0;
    }

    if(adc_tps>=data_tps[cdata-1]){
        tps_index=cdata-1;
    }
    
  
    inj_dur_deg=inj_data_dur_deg[tps_index][rpm_index];
    ign_off_deg=ign_data_off_deg[tps_index][rpm_index];
    
    inj_dur_deg_out=inj_dur_deg*90/100;
    
    inj_on_deg=90-inj_dur_deg_out;
    inj_on_tick=inj_on_deg*one_deg_tick;
    
    ign_off_deg_out=45-ign_off_deg;
    ign_off_tick=ign_off_deg_out*one_deg_tick;
    
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
    
    deg_per_tooth=360/(all_tooth+1);
    one_deg_tick=last_period/deg_per_tooth;
    
    toothcount++;
  }
  
  if(toothcount==all_tooth+1){toothcount=0;}
  if(toothcount==all_tooth+2){toothcount=1;} 
}

void engine_set(void){
  
  if(toothcount==inj_start_tooth){
    chSysLockFromIsr();
    gptStartOneShotI(&GPTD2, inj_on_tick);
    chSysUnlockFromIsr();
  }
  
  if(toothcount==inj_stop_tooth){
    off_inj1;
    off_inj2;
  }
  
  if(toothcount==ign_charge_tooth){
    on_ign1;
    on_ign2;
  }
  
  if(toothcount==ign_discharge_tooth){
    chSysLockFromIsr();
    gptStartOneShotI(&GPTD4, ign_off_tick);
    chSysUnlockFromIsr();
  }
}
  
void engine_notimer(void){
  
  if(toothcount==top_tooth-5){
    on_ign1;
    on_ign2;
  }
  
  if(toothcount==top_tooth){
    off_ign1;
    off_ign2;
  }
}

void inj_out(void){
  on_inj1;
  on_inj2;
}

void ign_out(void){
  off_ign1;
  off_ign2;
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
  chprintf((BaseSequentialStream *)&SD1, "%4i,%4i,%5i,%5i,%5i,%5i,%3i\r\n",
	   rpm,
	   adc_tps,
	   inj_on_tick,
	   ign_off_tick,
	   last_period,
	   one_deg_tick,
	   deg_per_tooth
	  );
}
