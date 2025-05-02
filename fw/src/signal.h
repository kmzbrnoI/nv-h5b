#ifndef _SIGNAL_H_
#define _SIGNAL_H_

#define SIGNAL_FLASH_PERIOD 55 // units: 10 ms

typedef enum {
	stMain = 0,
	stRepeater = 1,
	ST_COUNT
} SignalType;

extern volatile uint8_t current_signal_code;
extern volatile SignalType signal_set;

void set_signal_code(uint8_t code);
void signal_update_10ms();

#endif
