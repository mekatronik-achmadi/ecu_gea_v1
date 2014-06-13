#ifndef GEA_MEM_H
#define GEA_MEM_H

#define e_adc_tps_full 0
#define e_adc_tps_close 1

#define e_inj_ms_base 2
#define e_inj_open_time 3

#define e_inj_data 4

#define e_ign_data 149

#define NumbOfVar ((uint16_t)0x300)

#define SAVE 0
#define READ 1

void Mem_Setup(void);

uint16_t read_mem(uint16_t addr);
void save_mem(uint16_t addr, uint16_t data);

void mem_adc(uint8_t mode);
void mem_injec(uint8_t mode);
void mem_inj_data(uint8_t idx_tps,uint8_t idx_rpm,uint8_t mode);
void mem_ign_data(uint8_t idx_tps,uint8_t idx_rpm,uint8_t mode);

void mem_load_all(void);

#endif
