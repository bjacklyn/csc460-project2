#ifdef USE_TEST_009

/*
    Desired Trace
    T009;1;1;1;1;1;25;1;1;1;1;50;...;125;
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t count = 1;
volatile bool finished = false;

void rr1() {
	for(;;) {
		if (!finished)
		{
			add_to_trace(1);
			_delay_ms(1);
			Task_Next();
		} else {
			Task_Terminate();
		}
	}
}

void rr_print() {
	print_trace();
}

void periodic1() {
	for(;;) {
		add_to_trace(Now());
		
		if (Now() > 100)
		{
			finished = true;
			Task_Create_RR(rr_print, 0);
			break;
		}
		
		Task_Next();
		
		count++;
	}
}

int r_main() {
    uart_init();
    set_trace_test(9);
	
	Task_Create_RR(rr1, 0);
    Task_Create_Periodic(periodic1, 0, 5, 20, 5); // run on 5th tick

	return 0;
}

#endif