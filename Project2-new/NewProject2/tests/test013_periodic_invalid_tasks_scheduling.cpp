#ifdef USE_TEST_013
/*
    Desired Trace
    ERR_RUN_6_INVALID_PERIODIC_SCHEDULING
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void periodic1() {
	add_to_trace(1);
	add_to_trace(Now());
	
	add_to_trace(3);
	add_to_trace(Now());
}

void periodic2() {
	add_to_trace(4);
	add_to_trace(Now());
	print_trace();
}

int r_main() {
    uart_init();
    set_trace_test(13);
	
    Task_Create_Periodic(periodic1, 0, 50, 20, 10); // run on 10th tick
	Task_Create_Periodic(periodic2, 0, 50, 20, 10); // run on 10th tick

	return 0;
}

#endif