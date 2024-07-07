#ifndef _PWM_H_
#define _PWM_H_

#include <stdbool.h>

void ramp_up(uint8_t mask);
void ramp_down(uint8_t mask);
void pwm_update(void);

#endif
