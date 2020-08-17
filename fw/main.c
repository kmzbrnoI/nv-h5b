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
static inline void detect_signal_type();

///////////////////////////////////////////////////////////////////////////////

uint16_t counter_100us = 0;

///////////////////////////////////////////////////////////////////////////////

int main() {
	init();
	set_signal_code(8);

	while (true) {
	}
}

static inline void init() {
	detect_signal_type();
	led_init();
	decode_init();

	// Setup timer 0
	TCCR0A |= 1 << WGM01; // CTC mode
	TCCR0B |= 1 << CS01; // no prescaler
	TIMSK |= 1 << OCIE0A; // enable compare match A
	OCR0A = 99;

	sei(); // enable interrupts globally
}

static inline void detect_signal_type() {
	DDRB |= LED_RED; // pin as output
	PORTB &= ~(LED_RED); // zero to output
	_delay_ms(1);
	signal_set = (PINB & LED_YELLOW_TOP) ? 0 : 1; // TODO: change to bottom
}

ISR(TIM0_COMPA_vect) {
	// Timer 0 @ 10 kHz (period 100 us)
	counter_100us++;

	signal_update();
	pwm_update();
}
