#ifndef _LEDS_H_
#define _LEDS_H_

#include <stdbool.h>
#include <stdint.h>
#include <avr/io.h>

#define LED_YELLOW_BOTTOM 32
#define LED_WHITE 4
#define LED_RED 8
#define LED_GREEN 16
#define LED_YELLOW_TOP 2
#define LED_ALL 0x3E

static inline void led_set(uint8_t mask, bool state) {
	// LED indexed from 0
	if (state)
		PORTB &= ~(mask & LED_ALL);
	else
		PORTB |= (mask & LED_ALL);
}

static inline void led_init() {
	DDRB |= LED_ALL;
	PORTB |= LED_ALL;
}

#endif
