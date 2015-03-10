#ifdef USE_TEST_015
/*
    Desired Trace
    T015;0;
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int r_main() {
    uart_init();
    set_trace_test(15);
	
	SERVICE* service = Service_Init();
	
	uint8_t service_index = (uint8_t)((uint16_t)(service) - 1);
	
	add_to_trace(service_index);
	print_trace();

	return 0;
}

#endif