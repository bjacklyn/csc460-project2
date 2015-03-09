#ifdef USE_TEST_016
/*
    Desired Trace
    T016;255;
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int r_main() {
    uart_init();
    set_trace_test(16);
	
	// create MAXSERVICE services
	for (int i = 0; i < MAXSERVICE; i++)
	{
		Service_Init();
	}
	
	// handler should point to -1 (or 255 since unsigned)
	SERVICE* service = Service_Init();
	uint8_t service_index = (uint8_t)((uint16_t)(service) - 1);
	
	add_to_trace(service_index);
	print_trace();

	return 0;
}

#endif