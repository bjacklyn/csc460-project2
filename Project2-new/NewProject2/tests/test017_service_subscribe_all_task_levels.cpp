#ifdef USE_TEST_017
/*
    Desired Trace
    T017;1;2;3; then ERR_RUN_7_ILLEGAL_PERIODIC_TASK_SUBSCRIBED_TO_SERVICE
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

SERVICE* service;
int16_t* data;

volatile uint8_t count = 0;

void system() {
	add_to_trace(1);
	
	Service_Subscribe(service, data);
	
	add_to_trace(997); // should not get here
}

void roundrobin() {
	add_to_trace(2);
	
	Service_Subscribe(service, data);
	
	add_to_trace(998); // should not get here
}

void periodic() {
	add_to_trace(3);
	print_trace();
	Task_Next();
	
	Service_Subscribe(service, data);
		
	add_to_trace(999); // should not get here
}

int r_main() {
    uart_init();
    set_trace_test(17);
	
	service = Service_Init();
	
	Task_Create_System(system, 0);
	Task_Create_Periodic(periodic, 0, 500, 200, 25);
	Task_Create_RR(roundrobin, 0);
	
	return 0;
}

#endif