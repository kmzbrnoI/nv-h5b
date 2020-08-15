/* Main source file of NV-H5B S-COM receiver.
 */

#include <stdbool.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>

#include "leds.h"
#include "pwm.h"

///////////////////////////////////////////////////////////////////////////////

int main();
void init();

///////////////////////////////////////////////////////////////////////////////

int main() {
	init();

	while (true) {
	}
}

void init() {
	led_init();

	// Setup timer 0
	TCCR0A |= 1 << WGM01; // CTC mode
	TCCR0B |= 1 << CS01; // prescaler 8×
	TIMSK0 |= 1 << OCIE0A; // enable compare match A
	OCR0A = 149;

	sei(); // enable interrupts globally
}


ISR(TIM0_COMPA_vect) {
	// Timer 0 @ 1 kHz (period 1 ms)
	static uint16_t counter = 0xFFFF;
	counter++;

	if (counter % 2000 == 0)
		led_set(0xFF, true);
	else if (counter % 2000 == 1000)
		led_set(0xFF, false);
}
