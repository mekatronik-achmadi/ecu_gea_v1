#include "srcconf.h"

static void gpt1cb(GPTDriver *gptp) {
  (void)gptp;
  
}

static void gpt2cb(GPTDriver *gptp) {
  (void)gptp;
  inj_out();
}

static void gpt4cb(GPTDriver *gptp) {
  (void)gptp;
  ign_out();
}

static const GPTConfig gpt1cfg = {
  F_GPT,    /* 10kHz timer clock.*/
  gpt1cb,   /* Timer callback.*/
  0
};

static const GPTConfig gpt2cfg = {
  F_GPT,    /* 10kHz timer clock.*/
  gpt2cb,   /* Timer callback.*/
  0
};

static const GPTConfig gpt4cfg = {
  F_GPT,    /* 10kHz timer clock.*/
  gpt4cb,   /* Timer callback.*/
  0
};

void Gpt_Setup(void){
//   gptStart(&GPTD1, &gpt1cfg);
  gptStart(&GPTD2, &gpt2cfg);
  gptStart(&GPTD4, &gpt4cfg);
}