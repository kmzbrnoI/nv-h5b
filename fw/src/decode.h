#ifndef _DECODE_H_
#define _DECODE_H_

extern uint8_t last_received_code;
extern void (*on_received)(uint8_t code);

void decode_init(void);
void decode_update(void);

#endif
