#ifndef _PWM_H_
#define _PWM_H_

void pwm_update(uint16_t counter);
void ramp_up(uint8_t mask);
void ramp_down(uint8_t mask);

#endif
