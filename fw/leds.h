#ifndef _LEDS_H_
#define _LEDS_H_

#include <stdbool.h>
#include <stdint.h>
#include <avr/io.h>

#define LED_YELLOW_BOTTOM 1
#define LED_WHITE 2
#define LED_RED 3
#define LED_GREEN 4
#define LED_YELLOW_TOP 5

/* Output indexes:
 * 0: yellow top
 * 1: green
 * 2: red
 * 3: white
 * 3: yellow bottom
 */

uint8_t _led_output(uint8_t index) {
	switch (index) {
		case 0: return LED_YELLOW_TOP; break;
		case 1: return LED_GREEN; break;
		case 2: return LED_RED; break;
		case 3: return LED_WHITE; break;
		case 4: return LED_YELLOW_BOTTOM; break;
		default: return LED_RED; break;
	}
}

void led_set(uint8_t index, bool state) {
	if (state)
		PORTB |= (1 << _led_output(index));
	else
		PORTB &= ~(1 << _led_output(index));
}

void led_init() {
	DDRB |= 0x3E;
	PORTB |= 0x3E;
}

#endif
