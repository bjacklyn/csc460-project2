#ifdef USE_TEST_010
/*
    Desired Trace
    T010;1;50;2;50;3;55;
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


void system() {
	add_to_trace(2);
	add_to_trace(Now());
	_delay_ms(5);
}

void periodic1() {
	add_to_trace(1);
	add_to_trace(Now());
	
	Task_Create_System(system, 0);
	add_to_trace(3);
	add_to_trace(Now());
	print_trace();
}

int r_main() {
    uart_init();
    set_trace_test(10);
	
    Task_Create_Periodic(periodic1, 0, 50, 20, 10); // run on 10th tick

	return 0;
}

#endif
