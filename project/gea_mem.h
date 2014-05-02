#ifndef GEA_MEM_H
#define GEA_MEM_H

#define e_adc_tps_full 0
#define e_adc_tps_close 1

#define e_inj_data_off_deg 2

#define e_inj_data_dur_deg 13

#define e_ign_data_off_deg 24

#define NumbOfVar ((uint8_t)0x35)

#define SAVE 0
#define READ 1

void Mem_Setup(void);

uint16_t read_mem(uint16_t addr);
void save_mem(uint16_t addr, uint16_t data);

void mem_adc(uint8_t mode);
void mem_inj_data_off_deg(uint8_t mode);
void mem_inj_data_dur_deg(uint8_t mode);
void mem_ign_data_off_deg(uint8_t mode);

void mem_load_all(void);

#endif