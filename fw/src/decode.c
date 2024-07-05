#include <avr/interrupt.h>
#include <stdbool.h>

#include "decode.h"
#include "signal.h"
#include "common.h"

//#include "leds.h" // DEBUG

#define BIT_MIN_LENGTH 20  // 4 ms
#define BIT_MAX_LENGTH 150  // 30 ms
#define SIGNAL_TIMEOUT 250  // 50 ms

volatile uint8_t level_time = 0;
volatile uint8_t period;
volatile uint8_t receiving_time;
volatile int16_t received_value;
volatile uint8_t received_code;
volatile uint8_t last_received_code = 0xFF;

#define REC_NONE -3
#define REC_STARTBIT -2
#define REC_AFTERSTARTBIT -1
#define REC_BIT0 0
#define REC_BIT6 6
#define REC_STOPBIT 7
volatile int8_t last_received = REC_NONE;

static inline bool bus_state(void) { return PINB & 0x1; }

void decode_init(void) {
	// PB0 input by default
	PCMSK = 1 << PCINT0;
	GIMSK |= 1 << PCIE; // enable pin change interrupt
}

ISR(PCINT0_vect) {
	if (last_received == REC_NONE && !bus_state() && level_time >= SIGNAL_TIMEOUT) {
		// start-bit
		last_received = REC_STARTBIT;
	} else if (last_received == REC_STARTBIT) {
		if (level_time < BIT_MIN_LENGTH || level_time > BIT_MAX_LENGTH) {
			last_received = REC_NONE;
			return;
		}
		period = level_time;
		last_received = REC_AFTERSTARTBIT;
		receiving_time = 0;
		received_code = 0;
		received_value = 0;
	}

	level_time = 0;
}

static inline void code_received(void) {
	if (received_code == last_received_code && received_code != current_signal_code)
		set_signal_code(received_code);
	last_received_code = received_code;
}

void decode_update(void) {
	if (counter_100us % 2 != 0)
		return;

	if (level_time < 0xFF)
		level_time++;

	if (last_received >= REC_AFTERSTARTBIT && last_received <= REC_STOPBIT) {
		receiving_time++;
		if (bus_state())
			received_value++;
		else
			received_value--;

		if (receiving_time >= period) {
			last_received++;
			receiving_time = 0;

			if (received_value > period/2) {
				if (last_received > REC_BIT0)
					received_code |= (1 << (last_received-REC_BIT0-1));
			} else if (received_value > -period/2) { // error
				last_received = REC_NONE;
				return;
			}
			received_value = 0;

			if (last_received == REC_STOPBIT+1) {
				last_received = REC_NONE;
				if ((received_code & 0x80) != 0) // error
					return;
				code_received();
			}
		}
	}
}
