#include "srcconf.h"

volatile uint16_t VirtAddVarTab[NumbOfVar];

extern adcsample_t adc_tps_close,adc_tps_full;
extern uint16_t inj_data_ms_perc[cdata][cdata];
extern uint16_t ign_data_off_deg[cdata][cdata];
extern uint16_t inj_ms_base,inj_open_time;

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

void mem_injec(uint8_t mode){
  if(mode==0){
    save_mem(e_inj_ms_base,inj_ms_base);
    save_mem(e_inj_open_time,inj_open_time);
  }
  else if(mode==1){
    inj_ms_base=read_mem(e_inj_ms_base);
    inj_open_time=read_mem(e_inj_open_time);
  }
}

void mem_inj_data(uint8_t idx_tps,uint8_t idx_rpm,uint8_t mode){
  int i,j;
  
  i=idx_tps;
  j=idx_rpm;
  
  if(mode==0){
     save_mem(e_inj_data+(i*cdata)+j,inj_data_ms_perc[i][j]);
  }
  else if(mode==1){
     inj_data_ms_perc[i][j]=read_mem(e_inj_data+(i*cdata)+j);
  }
}

void mem_ign_data(uint8_t idx_tps,uint8_t idx_rpm,uint8_t mode){
  int i,j;
  
  i=idx_tps;
  j=idx_rpm;
  
  if(mode==0){
     save_mem(e_ign_data+(i*cdata)+j,ign_data_off_deg[i][j]);
  }
  else if(mode==1){
     ign_data_off_deg[i][j]=read_mem(e_ign_data+(i*cdata)+j);
  }
}

void mem_load_all(void){
  mem_adc(READ);
  
  mem_injec(READ);
  
  uint8_t i,j;
  
  for(i=0;i<cdata;i++){
	  for(j=0;j<cdata;j++){
		  mem_inj_data(i,j,READ);
	  }
  }
  
  for(i=0;i<cdata;i++){
	  for(j=0;j<cdata;j++){
		  mem_ign_data(i,j,READ);
	  }
  }
  
}
