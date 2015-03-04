#ifdef USE_TEST_005

/*
    Desired Trace
    T005;1;
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void periodic1() {
	add_to_trace(1);
	add_to_trace(Now());
	print_trace();
}

int r_main() {
    uart_init();
    set_trace_test(5);
	
    Task_Create_Periodic(periodic1, 0, 50, 100, 50); // run on 5th tick

	return 0;
}

#endif