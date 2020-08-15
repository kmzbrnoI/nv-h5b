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

static inline void led_set(uint8_t mask, bool state) {
	// LED indexed from 0
	if (state)
		PORTB &= ~((mask & 0x1F) << 1);
	else
		PORTB |= ((mask & 0x1F) << 1);

}

static inline void led_init() {
	DDRB |= 0x3E;
	PORTB |= 0x3E;
}

#endif
