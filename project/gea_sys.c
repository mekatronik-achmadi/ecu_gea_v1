#include "srcconf.h"

extern adcsample_t adc_tps;

extern icucnt_t last_period;
icucnt_t prev_last_period,rpm,rpm_icu,frekuensi,misstooth;

uint8_t toothcount;
uint8_t inj_phase,ign_phase;

uint16_t inj_data_dur_deg[cdata][cdata]={
  
  //    100    500     1000    1200    1300    2000    2500    3000    4000    5000    5500    6000
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
  
  //    100    500     1000    1200    1300    2000    2500    3000    4000    5000    5500    6000
  {	15,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30}, // 0
  {	15,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30}, // 10
  {	15,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30}, // 15
  {	15,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30}, // 20
  {	15,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30}, // 30
  {	15,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30}, // 40
  {	15,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30}, // 50
  {	15,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30}, // 60
  {	15,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30}, // 70
  {	15,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30}, // 80
  {	15,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30}, // 90
  {	15,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30}  // 100
};

uint16_t data_tps[cdata]={0,10,15,20,30,40,50,60,70,80,90,100};
// uint16_t data_rpm[cdata]={1000,1500,2000,2500,3000,3500,4000,4500,5000,5500,6000,6500};
uint16_t data_rpm[cdata]={500,1000,1500,2000,2500,3000,4000,5000,5500,6000,6500,7000};

uint16_t inj_off_deg,inj_dur_deg,inj_dur_tick,inj_on_deg,inj_on_tick;
uint16_t ign_off_deg,ign_dur_deg,ign_dur_tick,ign_on_deg,ign_on_tick;

uint16_t rps,rot_tick,deg_rot_tick;
uint16_t deg_15_tick;

uint8_t rpm_index,tps_index,rpm_fx;

void inj_ign(void){
  
    int i;
    
    
    for(i=0;i<cdata-2;i++){
        if((rpm_icu>=data_rpm[i])&&(rpm_icu<data_rpm[i+1])){
	  rpm_index=i;
        }
    };
    
    if(rpm_icu<data_rpm[0]){
        rpm_index=0;
    }

    if(rpm_icu>=data_rpm[cdata-1]){
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
    
    inj_off_deg=50;
    inj_on_deg=180-inj_dur_deg-inj_off_deg;
    inj_dur_tick=inj_dur_deg*deg_rot_tick;
    inj_on_tick =inj_on_deg*deg_rot_tick;
    
    ign_dur_deg=45;
    ign_on_deg=180-ign_dur_deg-ign_off_deg;
    ign_dur_tick=ign_dur_deg*deg_rot_tick;
    ign_on_tick=ign_on_deg*deg_rot_tick;
}

void engine_calc(void){
  
//   uint8_t i;
  
  if(last_period > 0){
    misstooth = (prev_last_period*100) / last_period;
    prev_last_period =  last_period; 
  } 
  
  if((misstooth>40)&&(misstooth<60)){  
    toothcount=0;
  }
  else{
    frekuensi = F_ICU / last_period;
    rpm_icu = frekuensi*60/(all_tooth+1);
    
    
    
//     for(i=0;i<cdata-2;i++){
//         if((rpm_icu>=data_rpm[i])&&(rpm_icu<data_rpm[i+1])){
// 	  rpm_fx=i;
//         }
//     };
//     
//     if(rpm_icu<data_rpm[0]){
//         rpm_fx=0;
//     }
// 
//     if(rpm_icu>=data_rpm[cdata-1]){
//         rpm_fx=cdata-1;
//     }
//     
//     rpm=data_rpm[rpm_fx];
//     
//     rps=rpm/60;
//     rot_tick=F_GPT/rps;
//     deg_rot_tick=rot_tick/360;
    
    rpm=rpm_icu;
    
    deg_15_tick=last_period;
    deg_rot_tick=deg_15_tick/15;
    
    toothcount++;
  }
  
  if(toothcount==all_tooth+1){toothcount=0;}
  if(toothcount==all_tooth+2){toothcount=1;} 
}

void engine_set(void){
  if(toothcount==bottom_tooth){
    ign_phase=0;
    
    chSysLockFromIsr();
    gptStartOneShotI(&GPTD4, ign_on_tick);
    chSysUnlockFromIsr();
  }
  
  if(toothcount==top_tooth){
    inj_phase=0;
   
    chSysLockFromIsr();
    gptStartOneShotI(&GPTD2, inj_on_tick);
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
  chprintf((BaseSequentialStream *)&SD1, "%4i,%4i,%3i,%3i,%3i,%3i,%5i,%5i,%5i\r\n",
	   rpm_icu,
	   adc_tps,
	   ign_dur_deg,
	   ign_off_deg,
	   inj_dur_deg,
	   inj_off_deg,
	   inj_on_tick,
	   inj_dur_tick,
	   last_period
	  );
}
