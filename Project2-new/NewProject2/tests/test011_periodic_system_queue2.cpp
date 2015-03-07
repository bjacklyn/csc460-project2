#ifdef USE_TEST_011
/*
    Desired Trace
    ERR_RUN_6_INVALID_PERIODIC_SCHEDULING
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


void system() {
	_delay_ms(6);
}

void periodic1() {
	Task_Create_System(system, 0);
}

void periodic2() {
	// should be scheduled to run at same time as periodic1 due to system task sleeping
}

int r_main() {
    uart_init();
    set_trace_test(11);
	
    Task_Create_Periodic(periodic1, 0, 50, 20, 5); // run on 5th tick
	Task_Create_Periodic(periodic2, 0, 50, 20, 10); // run on 10th tick

	return 0;
}

#endif
