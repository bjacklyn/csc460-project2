#ifdef USE_TEST_018
/*
    Desired Trace
	ERR_RUN_7_ILLEGAL_PERIODIC_TASK_SUBSCRIBED_TO_SERVICE
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

SERVICE* service;
int16_t* data;

volatile uint8_t count = 0;

void periodic() {
	Service_Subscribe(service, data);
}

int r_main() {
    uart_init();
    set_trace_test(18);
	
	service = Service_Init();
	
	Task_Create_Periodic(periodic, 0, 100, 50, 25);

	return 0;
}

#endif