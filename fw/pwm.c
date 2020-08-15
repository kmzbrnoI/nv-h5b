#include <stdint.h>
#include <stdbool.h>

#include "pwm.h"
#include "leds.h"

const uint8_t RAMP_UP_PERIOD = 20;
const uint8_t RAMP_DOWN_PERIOD = 50;
const uint8_t RAMP_ATOMIC_INCREMENT = 5;
uint8_t ramp_up_mask = 0, ramp_down_mask = 0;
uint8_t ramp_up_shift, ramp_down_shift;

void pwm_update(uint16_t counter) {
	static uint8_t pwm_counter = 0;

	if (ramp_up_mask != 0) {
		led_set(ramp_up_mask, pwm_counter <= ramp_up_shift);
		if (counter % RAMP_UP_PERIOD == 0) {
			if (ramp_up_shift >= (0xFF-RAMP_ATOMIC_INCREMENT)) {
				ramp_up_mask = 0; // end
				led_set(ramp_up_mask, true);
			}
			ramp_up_shift += RAMP_ATOMIC_INCREMENT;
		}
	}

	if (ramp_down_mask != 0) {
		led_set(ramp_down_mask, pwm_counter <= ramp_down_shift);
		if (counter % RAMP_DOWN_PERIOD == 0) {
			if (ramp_down_shift >= (0xFF-RAMP_ATOMIC_INCREMENT)) {
				ramp_down_mask = 0; // end
				led_set(ramp_down_mask, true);
			}
			ramp_down_shift += RAMP_ATOMIC_INCREMENT;
		}
	}

	pwm_counter++;
}

void ramp_up(uint8_t mask) {
	ramp_up_mask = mask;
	ramp_up_shift = 0;
}

void ramp_down(uint8_t mask) {
	ramp_down_mask = mask;
	ramp_down_shift = 0;
}
