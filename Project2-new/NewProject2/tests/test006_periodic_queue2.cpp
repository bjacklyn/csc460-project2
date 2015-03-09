#ifdef USE_TEST_006

/*
    Desired Trace
    T006;1;2;
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void periodic1() {
	add_to_trace(1);
}

void periodic2() {
	add_to_trace(2);
	print_trace();
}

int r_main() {
    uart_init();
    set_trace_test(6);

	_delay_ms(2000);

    Task_Create_Periodic(periodic1, 0, 50, 100, 50); // run on 50th tick
	Task_Create_Periodic(periodic2, 0, 50, 100, 70); // run on 70th tick

	return 0;
}

#endif