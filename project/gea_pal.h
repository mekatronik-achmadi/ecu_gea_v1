#ifndef GEA2_PAL
#define GEA2_PAL

#define led 8

#define inj_1 9
#define inj_2 8
#define ign_1 7
#define ign_2 6
#define pump 15

//sistem tanpa pullup
//#define output 6
//sistem dengan pullup
#define output 14

#define no_pulse palTogglePad(GPIOA,led)

#define on_inj1 palSetPad(GPIOC,inj_1)
#define off_inj1 palClearPad(GPIOC,inj_1)

#define on_inj2 palSetPad(GPIOC,inj_2)
#define off_inj2 palClearPad(GPIOC,inj_2)

#define off_ign1 palSetPad(GPIOC,ign_1)
#define on_ign1 palClearPad(GPIOC,ign_1)

#define off_ign2 palSetPad(GPIOC,ign_2)
#define on_ign2 palClearPad(GPIOC,ign_2)

#define on_pump palSetPad(GPIOB,pump)
#define off_pump palClearPad(GPIOB,pump)

//sistem tanpa pullup
//#define out_active palSetPad(GPIOB,output)
//sistem dengan pullup
#define out_active palSetPad(GPIOB,output)

#define interval chThdSleepMilliseconds(6);

#define IACA 15
#define IACB 14
#define IACC 13
#define IACD 12

#define IACA_H palSetPad(GPIOB,IACA)
#define IACA_L palClearPad(GPIOB,IACA)

#define IACB_H palSetPad(GPIOB,IACB)
#define IACB_L palClearPad(GPIOB,IACB)

#define IACC_H palSetPad(GPIOB,IACC)
#define IACC_L palClearPad(GPIOB,IACC)

#define IACD_H palSetPad(GPIOB,IACD)
#define IACD_L palClearPad(GPIOB,IACD)

void Pal_Setup(void);
void Iac_CW(uint8_t loop);
void Iac_CCW(uint8_t loop);
void Iac_Start(void);

#endif  
