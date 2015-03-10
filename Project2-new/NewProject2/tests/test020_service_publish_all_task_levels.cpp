#ifdef USE_TEST_020
/*
    Desired Trace
	T020;40;41;42;
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

SERVICE* service;
int16_t one = 1;
int16_t* data = &one;

void roundrobin_subscriber() {
	Service_Subscribe(service, data); // woken by system task
	add_to_trace(*data);
	Service_Subscribe(service, data); // woken by periodic task
	add_to_trace(*data);
	Service_Subscribe(service, data); // woken by roundrobin task
	add_to_trace(*data);
	print_trace();
}

void system() {
	Service_Publish(service, 40);
}

void periodic() {
	Service_Publish(service, 41);
}

void roundrobin() {
	PORTC |= _BV(PC4);
	Service_Publish(service, 42);
			PORTC &= ~(_BV(PC4));
}

void periodic_task_creator() {
	Task_Create_System(system, 0);
	Task_Next();
	Task_Create_Periodic(periodic, 0, 100, 100, 0);
	Task_Next();
	Task_Create_RR(roundrobin, 0);
	Task_Next();
}

int r_main() {
    uart_init();
    set_trace_test(20);

	DDRC = _BV(PC4);

	service = Service_Init();
	
	Task_Create_RR(roundrobin_subscriber, 0);
	Task_Create_Periodic(periodic_task_creator, 0, 100, 100, 10); // runs at 10th tick, and after subscriber

	return 0;
}

#endif