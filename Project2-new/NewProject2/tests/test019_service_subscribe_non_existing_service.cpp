#ifdef USE_TEST_019
/*
    Desired Trace
	ERR_RUN_8_SUBSCRIBED_TO_NON_EXISTING_SERVICE
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

SERVICE* service;
int16_t* data;

int r_main() {
    uart_init();
    set_trace_test(19);
	
	// create MAXSERVICE services
	for (int i = 0; i < MAXSERVICE; i++)
	{
		Service_Init();
	}
	
	service = Service_Init();
	
	Service_Subscribe(service, data);

	return 0;
}

#endif