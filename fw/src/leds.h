#ifndef _LEDS_H_
#define _LEDS_H_

#include <stdbool.h>
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

#define LED_YELLOW_BOTTOM 2
#define LED_WHITE 4
#define LED_RED 8
#define LED_GREEN 16
#define LED_YELLOW_TOP 32
#define LED_ALL 0x3E

static inline void led_set(uint8_t mask, bool state) {
	if (state)
		PORTB &= ~(mask & LED_ALL);
	else
		PORTB |= (mask & LED_ALL);
}

static inline void led_toggle(uint8_t mask) {
	led_set(mask, true);
	_delay_ms(1);
	led_set(mask, false);
}

static inline void led_init() {
	DDRB |= LED_ALL;
	PORTB |= LED_ALL;
}

#endif
