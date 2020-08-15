#include <stdint.h>

#include "signal.h"
#include "leds.h"
#include "pwm.h"

typedef struct {
	uint8_t outputs; // mask, see leds.h
	uint8_t flash; // mask, see leds.h
} SignalCode;

const SignalCode codes[] = {
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
};

volatile uint8_t current_signal_code = 0;

void set_signal_code(uint8_t code) {
	uint8_t turn_off = codes[current_signal_code].outputs & (~codes[code].outputs);
	uint8_t turn_on = codes[code].outputs & (~codes[current_signal_code].outputs);

	ramp_down(turn_off);
	ramp_up(turn_on);
	current_signal_code = code;
}
