/* Main source file of NV-H5B S-COM receiver.
 */

#include <stdbool.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>

#include "common.h"
#include "leds.h"
#include "pwm.h"
#include "signal.h"
#include "decode.h"

///////////////////////////////////////////////////////////////////////////////

int main();
static inline void init();

///////////////////////////////////////////////////////////////////////////////

uint16_t counter_100us = 0;

///////////////////////////////////////////////////////////////////////////////

int main() {
	init();
	led_set(LED_RED, true);

	while (true) {
	}
}

static inline void init() {
	led_init();
	decode_init();

	// Setup timer 0
	TCCR0A |= 1 << WGM01; // CTC mode
	TCCR0B |= 1 << CS01; // no prescaler
	TIMSK |= 1 << OCIE0A; // enable compare match A
	OCR0A = 119;

	sei(); // enable interrupts globally
}

ISR(TIM0_COMPA_vect) {
	// Timer 0 @ 10 kHz (period 100 us)
	counter_100us++;

	signal_update();
	pwm_update();
}
