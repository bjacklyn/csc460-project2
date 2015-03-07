#ifdef USE_TEST_012

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/*
    Desired Trace
    ERR_RUN_3_PERIODIC_TOOK_TOO_LONG
*/

void system() {
	_delay_ms(1);
}

void periodic1() {
	for (;;)
	{
		_delay_ms(20);
		Task_Create_System(system, 0);
		_delay_ms(25);
		Task_Next();
	}
}

int r_main() {
    uart_init();
    set_trace_test(12);
	
    Task_Create_Periodic(periodic1, 0, 10, 40, 5); // run on 10th tick

	return 0;
}

#endif
