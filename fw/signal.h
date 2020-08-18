#ifndef _SIGNAL_H_
#define _SIGNAL_H_

#define SIGNAL_FLASH_PERIOD 5470 // 65536 should not be divisible by this number

extern volatile int8_t current_signal_code;
extern volatile uint8_t signal_set;

void set_signal_code(uint8_t code);
void signal_update();

#endif
