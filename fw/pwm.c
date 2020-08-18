#include <stdint.h>
#include <stdbool.h>

#include "pwm.h"
#include "leds.h"
#include "common.h"

#define RAMP_UP_PERIOD 40
#define RAMP_DOWN_PERIOD 80
#define PWM_FULL 20

volatile uint8_t ramp_up_mask = 0;
volatile uint8_t ramp_down_mask = 0;
volatile uint8_t ramp_up_shift;
volatile uint8_t ramp_down_shift;

void pwm_update() {
	volatile static uint8_t pwm_counter = 0;

	if (ramp_up_mask != 0) {
		led_set(ramp_up_mask, pwm_counter <= ramp_up_shift);
		if (counter_100us % RAMP_UP_PERIOD == 0) {
			ramp_up_shift++;
			if (ramp_up_shift >= PWM_FULL-1) {
				led_set(ramp_up_mask, true);
				ramp_up_mask = 0; // end
			}
		}
	}

	if (ramp_down_mask != 0) {
		led_set(ramp_down_mask, pwm_counter <= ramp_down_shift);
		if (counter_100us % RAMP_DOWN_PERIOD == 0) {
			ramp_down_shift--;
			if (ramp_down_shift <= 1) {
				led_set(ramp_down_mask, false);
				ramp_down_mask = 0; // end
			}
		}
	}

	pwm_counter++;
	if (pwm_counter >= PWM_FULL)
		pwm_counter = 0;
}

void ramp_up(uint8_t mask) {
	ramp_up_mask = mask;
	ramp_up_shift = 0;
}

void ramp_down(uint8_t mask) {
	ramp_down_mask = mask;
	ramp_down_shift = PWM_FULL;
}
