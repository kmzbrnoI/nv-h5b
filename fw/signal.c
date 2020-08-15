#include <stdint.h>

#include "signal.h"
#include "leds.h"

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
	{LED_RED, LED_WHITE, 0},
	{LED_WHITE, 0},
	{LED_GREEN | LED_WHITE, 0},
	{LED_YELLOW_TOP | LED_WHITE, 0},
	{0, 0},
	{LED_YELLOW_TOP | LED_WHITE, LED_YELLOW_TOP},
	{LED_YELLOW_TOP | LED_WHITE | LED_YELLOW_BOTTOM, 0},
};
