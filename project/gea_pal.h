#ifndef GEA2_PAL
#define GEA2_PAL

#define led 8

#define inj_1 6
#define inj_2 7
#define ign_1 9
#define ign_2 8

#define no_pulse palTogglePad(GPIOA,led)

#define on_inj1 palSetPad(GPIOC,inj_1)
#define off_inj1 palClearPad(GPIOC,inj_1)

#define on_inj2 palSetPad(GPIOC,inj_2)
#define off_inj2 palClearPad(GPIOC,inj_2)

#define off_ign1 palSetPad(GPIOC,ign_1)
#define on_ign1 palClearPad(GPIOC,ign_1)

#define off_ign2 palSetPad(GPIOC,ign_2)
#define on_ign2 palClearPad(GPIOC,ign_2)

// add handler to using IAC

void Pal_Setup(void);

#endif  
