#ifdef USE_TEST_021
/*
    Desired Trace
	T021;1;2;3;4;5;6;7;8;
	
	Ordering of trace numbers proves pre-emption is occurring in the correct order.
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

SERVICE* service;

int16_t one = 1;
int16_t two = 2;
int16_t three = 3;

int16_t* data1 = &one;
int16_t* data2 = &two;
int16_t* data3 = &three;

void system() {
	add_to_trace(1);
	Service_Subscribe(service, data1);
	PORTC &= ~(_BV(PC4));
	add_to_trace(5);
}

void roundrobin1() {
	add_to_trace(2);
	Service_Subscribe(service, data2);
	add_to_trace(7);
}

void roundrobin2() {
	add_to_trace(3);
	Service_Subscribe(service, data3);
	add_to_trace(8);
	print_trace();
}

void periodic() {
	add_to_trace(4);
	PORTC |= _BV(PC4);
	Service_Publish(service, 42);
	add_to_trace(6);
}

int r_main() {
    uart_init();
    set_trace_test(21);

	DDRC = _BV(PC4);

	service = Service_Init();
	
	Task_Create_System(system, 0);
	//Task_Create_Periodic(periodic, 0, 100, 50, 10);
	Task_Create_RR(periodic, 0);
	Task_Create_RR(roundrobin1, 0);
	Task_Create_RR(roundrobin2, 0);

	return 0;
}

#endif