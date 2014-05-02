#include "srcconf.h"

volatile uint16_t VirtAddVarTab[NumbOfVar];

extern adcsample_t adc_tps_close,adc_tps_full;

extern uint16_t inj_data_off_deg[cdata];
extern uint16_t inj_data_dur_deg[cdata];
extern uint16_t ign_data_off_deg[cdata];

void Mem_Setup(void){
  FLASH_Unlock();
  EE_Init();
  mem_load_all();
}

uint16_t read_mem(uint16_t addr){
	uint16_t data;
	EE_ReadVariable(addr, &data);
	return data;
}

void save_mem(uint16_t addr, uint16_t data){
	EE_WriteVariable(addr, data);
}

void mem_adc(uint8_t mode){
  if(mode==0){
    save_mem(e_adc_tps_close,adc_tps_close);
    save_mem(e_adc_tps_full,adc_tps_full);
  }
  else if(mode==1){
    adc_tps_close=read_mem(e_adc_tps_close);
    adc_tps_full=read_mem(e_adc_tps_full);
  }
}

void mem_inj_data_off_deg(uint8_t mode){
  int i=0;
  
  for(i=0;i<cdata;i++){
    if(mode==0){
      save_mem(e_inj_data_off_deg+i,inj_data_off_deg[i]);
    }
    else if(mode==1){
      inj_data_off_deg[i]=read_mem(e_inj_data_off_deg+i);
    }
  }
}

void mem_inj_data_dur_deg(uint8_t mode){
  int i=0;
  
  for(i=0;i<cdata;i++){
    if(mode==0){
      save_mem(e_inj_data_dur_deg+i,inj_data_dur_deg[i]);
    }
    else if(mode==1){
      inj_data_dur_deg[i]=read_mem(e_inj_data_dur_deg+i);
    }
  }
}

void mem_ign_data_off_deg(uint8_t mode){
  int i=0;
  
  for(i=0;i<cdata;i++){
    if(mode==0){
      save_mem(e_ign_data_off_deg+i,ign_data_off_deg[i]);
    }
    else if(mode==1){
      ign_data_off_deg[i]=read_mem(e_ign_data_off_deg+i);
    }
  }
}

void mem_load_all(void){
  mem_adc(READ);
  mem_inj_data_off_deg(READ);
  mem_inj_data_dur_deg(READ);
  mem_ign_data_off_deg(READ);
}
