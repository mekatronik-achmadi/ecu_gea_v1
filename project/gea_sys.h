#ifndef GEA2_SYS
#define GEA2_SYS

#define top_tooth 9
#define bottom_tooth 21

#define intake_port_open 11
#define intake_port_close 2

#define coil_on 4
#define coil_off 7

#define exhaust_port_open 18
#define exhaust_port_close 6

#define all_tooth 23
#define deg_per_tooth 15

#define cdata 12

#define inj_open_time 200
#define engine_vol 650
#define engine_flow_sec 3.3

void inj_ign(void);
void ign_out(void);
void inj_out(void);
void engine_ovf(void);
void engine_calc(void);
void engine_set(void);
void data_send(void);

#endif 
