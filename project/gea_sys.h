#ifndef GEA2_SYS
#define GEA2_SYS

#define top_tooth 9
#define bottom_tooth 21

#define inj_start_tooth 14

#define ign_charge_tooth 3
#define ign_discharge_tooth 6

#define all_tooth 23

#define cdata 12



void inj_ign(void);
void ign_out(void);
void inj_out(void);
void engine_ovf(void);
void engine_calc(void);
void engine_set(void);
void engine_notimer(void);
void data_send(void);

#endif 
