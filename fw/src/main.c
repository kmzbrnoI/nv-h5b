/* Main source file of NV-H5B S-COM receiver.
 */

#include <stdbool.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/wdt.h>

#include "common.h"
#include "leds.h"
#include "pwm.h"
#include "signal.h"
#include "decode.h"

///////////////////////////////////////////////////////////////////////////////

int main();
static inline void init(void);
static inline void detect_signal_type(void);
static inline void init_led_test(void);

///////////////////////////////////////////////////////////////////////////////

volatile uint8_t counter_100us = 0;

///////////////////////////////////////////////////////////////////////////////

int main() {
	init();
	set_signal_code(8);

	while (true) {
		wdt_reset();
	}
}

void init(void) {
	ACSR |= ACD;  // analog comparator disable

	detect_signal_type();
	led_init();
	decode_init();

	// Setup timer 0
	TCCR0A |= 1 << WGM01; // CTC mode
	TCCR0B |= 1 << CS01; // no prescaler
	TIMSK |= 1 << OCIE0A; // enable compare match A
	OCR0A = 99;

	init_led_test();

	wdt_enable(WDTO_250MS);

	sei(); // enable interrupts globally
}

void init_led_test(void) {
}

void detect_signal_type(void) {
	// repeater = red and bottom yellow wires connected
	DDRB |= LED_RED; // pin as output
	PORTB &= ~(LED_RED); // zero to output
	_delay_ms(1);
	signal_set = (PINB & LED_YELLOW_BOTTOM) ? stMain : stRepeater;
}

ISR(TIM0_COMPA_vect) {
	// Timer 0 @ 10 kHz (period 100 us)
	counter_100us++;

	signal_update();
	pwm_update();
	decode_update();
}
