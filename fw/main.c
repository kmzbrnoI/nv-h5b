/* Main source file of NV-H5B S-COM receiver.
 */

#include <stdbool.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>

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
	sei(); // enable interrupts globally
}
