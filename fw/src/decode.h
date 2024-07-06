#ifndef _DECODE_H_
#define _DECODE_H_

volatile uint8_t last_received_code;
void (*volatile on_received)(uint8_t code);

void decode_init(void);
void decode_update(void);

#endif
