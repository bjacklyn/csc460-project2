#ifdef USE_TEST_022
/*
    Desired Trace
	T022;1;2;3;4;5;
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

SERVICE* service;

int16_t one = 1;
int16_t two = 2;

int16_t* data1 = &one;
int16_t* data2 = &two;

void system() {
	add_to_trace(1);
	Service_Subscribe(service, data1);
	add_to_trace(4);
}

void roundrobin() {
	add_to_trace(2);
	Service_Subscribe(service, data2);
	add_to_trace(5);
	print_trace();
}

ISR(TIMER3_COMPA_vect)
{
	Disable_Interrupt();
	
	OCR3A = 0;
	TIMSK3 = 0;
	
	Set_Tasks_Preemptable(false);
	Service_Publish(service, 99);
	Set_Tasks_Preemptable(true);
	
	add_to_trace(3);
	
	Enable_Interrupt();
}

int r_main() {
    uart_init();
    set_trace_test(22);

	service = Service_Init();
	
	TCCR3B |= (_BV(CS31));
	OCR3A = TCNT3 + 64000;
	TIMSK3 |= _BV(OCIE3A);
	
 	Task_Create_System(system, 0);
 	Task_Create_RR(roundrobin, 0);

	return 0;
}

#endif