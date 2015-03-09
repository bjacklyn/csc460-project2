#ifdef USE_TEST_014
/*
    Desired Trace
    T014;1;2;3;
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void system() {
	add_to_trace(1);
}

void periodic() {
	add_to_trace(2);
}

void roundrobin() {
	add_to_trace(3);
	print_trace();
}

int r_main() {
    uart_init();
    set_trace_test(14);
	
	Task_Create_System(system, 0);
    Task_Create_Periodic(periodic, 0, 50, 20, 0); // run on 0th tick
	Task_Create_RR(roundrobin, 0);

	return 0;
}

#endif