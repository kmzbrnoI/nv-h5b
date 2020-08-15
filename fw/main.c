/* Main source file of NV-H5B S-COM receiver.
 */

#include <stdbool.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>

#include "leds.h"
#include "pwm.h"
#include "signal.h"

///////////////////////////////////////////////////////////////////////////////

int main();
void init();

///////////////////////////////////////////////////////////////////////////////

int main() {
	init();

	while (true) {
		ramp_up(LED_ALL);
		_delay_ms(1000);
		ramp_down(LED_ALL);
		_delay_ms(1000);
	}
}

void init() {
	led_init();

	// Setup timer 0
	TCCR0A |= 1 << WGM01; // CTC mode
	TCCR0B |= 1 << CS01; // no prescaler
	TIMSK0 |= 1 << OCIE0A; // enable compare match A
	OCR0A = 119;

	sei(); // enable interrupts globally
}


ISR(TIM0_COMPA_vect) {
	// Timer 0 @ 10 kHz (period 100 us)
	static uint16_t counter = 0xFFFF;
	counter++;

	pwm_update(counter);
}
