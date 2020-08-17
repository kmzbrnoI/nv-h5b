#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>

#include "signal.h"
#include "leds.h"
#include "pwm.h"

typedef struct {
	uint8_t outputs; // mask, see leds.h
	uint8_t flash; // mask, see leds.h
} SignalCode;

#define NO_CODES 16

const SignalCode codes[2][NO_CODES] PROGMEM = {{
	{LED_RED, 0},
	{LED_GREEN, 0},
	{LED_YELLOW_TOP, 0},
	{LED_YELLOW_TOP, LED_YELLOW_TOP},
	{LED_GREEN | LED_YELLOW_BOTTOM, 0},
	{LED_ALL, 0},
	{LED_YELLOW_TOP | LED_YELLOW_BOTTOM, 0},
	{LED_YELLOW_TOP | LED_YELLOW_BOTTOM, LED_YELLOW_TOP},
	{LED_RED | LED_WHITE, LED_WHITE}, // PN
	{LED_RED | LED_WHITE, 0},
	{LED_WHITE, 0},
	{LED_GREEN | LED_WHITE, 0},
	{LED_YELLOW_TOP | LED_WHITE, 0},
	{0, 0},
	{LED_YELLOW_TOP | LED_WHITE, LED_YELLOW_TOP},
	{LED_YELLOW_TOP | LED_WHITE | LED_YELLOW_BOTTOM, 0},
}, {
	{LED_WHITE | LED_YELLOW_TOP, 0},
	{LED_WHITE | LED_GREEN, 0},
	{LED_WHITE | LED_GREEN, 0},
	{LED_WHITE | LED_GREEN, 0},
	{LED_WHITE | LED_YELLOW_TOP, LED_YELLOW_TOP},
	{LED_ALL, 0},
	{LED_WHITE | LED_YELLOW_TOP, LED_YELLOW_TOP},
	{LED_WHITE | LED_YELLOW_TOP, LED_YELLOW_TOP},
	{LED_WHITE | LED_YELLOW_TOP, 0}, // PN
	{LED_WHITE | LED_YELLOW_TOP, 0},
	{LED_WHITE | LED_YELLOW_TOP, 0},
	{LED_WHITE | LED_GREEN, 0},
	{LED_WHITE | LED_YELLOW_TOP, 0},
	{LED_WHITE | 0, 0},
	{LED_YELLOW_TOP, LED_YELLOW_TOP},
	{LED_YELLOW_TOP, 0},
}};

volatile int8_t current_signal_code = -1;
volatile bool flash_state = false;
volatile uint16_t counter = 0;
volatile uint8_t signal_set = 0;

static inline SignalCode signal_code(uint8_t index) {
	SignalCode code;
	memcpy_P(&code, &codes[signal_set][index], sizeof(SignalCode));
	return code;
}

void set_signal_code(uint8_t code) {
	if (code >= NO_CODES)
		return;

	uint8_t turn_on = signal_code(code).outputs;

	if (current_signal_code != -1) {
		turn_on &= ~signal_code(current_signal_code).outputs;
		uint8_t turn_off = signal_code(current_signal_code).outputs & (~signal_code(code).outputs);
		ramp_down(turn_off);
	}

	ramp_up(turn_on);
	current_signal_code = code;
	flash_state = true;
	counter = 0;
}

void signal_update() {
	counter++;

	if ((signal_code(current_signal_code).flash != 0) && (counter % SIGNAL_FLASH_PERIOD == 0)) {
		if (flash_state)
			ramp_down(signal_code(current_signal_code).flash);
		else
			ramp_up(signal_code(current_signal_code).flash);

		flash_state = !flash_state;
	}
}
