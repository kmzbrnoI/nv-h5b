#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>

#include "signal.h"
#include "leds.h"
#include "pwm.h"

typedef struct {
	uint8_t permanent; // mask, see leds.h
	uint8_t flash; // mask, see leds.h
} SignalCode;

#define NO_SETS 2
#define NO_CODES 17
#define CODE_INIT 0xFF

const SignalCode codes[NO_SETS][NO_CODES] PROGMEM = {{
	// main signal
	{LED_RED, 0},
	{LED_GREEN, 0},
	{LED_YELLOW_TOP, 0},
	{0, LED_YELLOW_TOP},
	{LED_GREEN | LED_YELLOW_BOTTOM, 0},
	{LED_ALL, 0},
	{LED_YELLOW_TOP | LED_YELLOW_BOTTOM, 0},
	{LED_YELLOW_BOTTOM, LED_YELLOW_TOP},
	{LED_RED, LED_WHITE}, // PN
	{LED_WHITE, 0},
	{LED_RED | LED_WHITE, 0},
	{LED_GREEN | LED_WHITE, 0},
	{LED_YELLOW_TOP | LED_WHITE, 0},
	{0, 0},
	{LED_WHITE, LED_YELLOW_TOP},
	{LED_YELLOW_TOP | LED_WHITE | LED_YELLOW_BOTTOM, 0},
	{LED_WHITE | LED_YELLOW_BOTTOM, LED_YELLOW_TOP},
}, {
	// 'predvest' / repeater signal
	{LED_WHITE | LED_YELLOW_TOP, 0},
	{LED_WHITE | LED_GREEN, 0},
	{LED_WHITE | LED_GREEN, 0},
	{LED_WHITE | LED_GREEN, 0},
	{LED_WHITE, LED_YELLOW_TOP},
	{LED_ALL, 0},
	{LED_WHITE, LED_YELLOW_TOP},
	{LED_WHITE, LED_YELLOW_TOP},
	{LED_WHITE | LED_YELLOW_TOP, 0}, // PN
	{LED_WHITE | LED_YELLOW_TOP, 0},
	{LED_WHITE | LED_YELLOW_TOP, 0},
	{LED_WHITE | LED_GREEN, 0},
	{LED_WHITE | LED_YELLOW_TOP, 0},
	{0, 0},
	{LED_WHITE, LED_YELLOW_TOP},
	{LED_WHITE | LED_YELLOW_TOP, 0},
	{LED_WHITE, LED_YELLOW_TOP},
}};

volatile uint8_t current_signal_code = CODE_INIT;
volatile bool flash_state = false;
volatile uint8_t counter = 0;
volatile SignalType signal_set = 0;
volatile uint8_t red_delayed_turnoff = 0;

static inline SignalCode signal_code(uint8_t index) {
	if (index >= NO_CODES)
		index = 0;
	SignalCode code;
	memcpy_P(&code, &codes[signal_set][index], sizeof(SignalCode));
	return code;
}

void set_signal_code(uint8_t code) {
	if ((code >= NO_CODES) || (code == current_signal_code))
		return;

	uint8_t code_all = signal_code(code).permanent | signal_code(code).flash;
	uint8_t current_all = signal_code(current_signal_code).permanent | signal_code(current_signal_code).flash;
	uint8_t turn_on = code_all;

	if (current_signal_code != CODE_INIT) {
		turn_on &= ~signal_code(current_signal_code).permanent;
		uint8_t turn_off = current_all & (~code_all);
		if (flash_state) {
			turn_on &= ~signal_code(current_signal_code).flash; // do not turn on already turned on
		} else {
			turn_off &= ~signal_code(current_signal_code).flash; // do not turn off already turned off
		}

		if (((signal_code(code).permanent & LED_RED) == 0) && (signal_code(current_signal_code).permanent & LED_RED)) {
			// Delay turning the red LED off
			red_delayed_turnoff = RED_DELAY_TURNOFF;
			turn_off &= ~LED_RED;
		}

		ramp_down(turn_off);
	}

	ramp_up(turn_on);
	current_signal_code = code;
	flash_state = true;
	counter = 0;
}

void signal_update_10ms() {
	counter++;

	if (red_delayed_turnoff > 0) {
		red_delayed_turnoff--;
		if (red_delayed_turnoff == 0)
			ramp_down(LED_RED);
	}

	if ((counter >= SIGNAL_FLASH_PERIOD) && (current_signal_code != CODE_INIT)) {
		counter = 0;
		if (flash_state) {
			ramp_down(signal_code(current_signal_code).flash);
		} else {
			ramp_up(signal_code(current_signal_code).flash);
		}

		flash_state = !flash_state;
	}
}
