#ifdef USE_TEST_003

/*
    Desired Trace
    T003;1;2;
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void round_robin1() {
	add_to_trace(1);
	for(;;) {}
}

void round_robin2() {
	add_to_trace(2);
	print_trace();
	for(;;) {}
}

int r_main() {
    uart_init();
    set_trace_test(3);
	
    _delay_ms(2000);
	
    Task_Create_RR(round_robin1, 0);
	Task_Create_RR(round_robin2, 0);
	
	return 0;
}

#endif