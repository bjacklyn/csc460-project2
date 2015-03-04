#ifdef USE_TEST_004

/*
    Desired Trace
    T004;1;2;1;2;
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void round_robin1() {
	add_to_trace(1);
	_delay_ms(TICK + 1);	// wait one tick
	add_to_trace(1);
}

void round_robin2() {
	add_to_trace(2);
	_delay_ms(TICK + 1);	// wait one tick
	add_to_trace(2);
	print_trace();
}

int r_main() {
    uart_init();
    set_trace_test(4);
	
    _delay_ms(2000);
	
    Task_Create_RR(round_robin1, 0);
    Task_Create_RR(round_robin2, 0);

	return 0;
}

#endif