#ifdef USE_TEST_002

/*
    Desired Trace
    T002;1;2;
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

uint16_t v;

void system_task_1() {
	add_to_trace(1);
}

void system_task_2() {
	add_to_trace(2);
}

void system_task_3() {
	print_trace();
}

int r_main() {
    uart_init();
    set_trace_test(2);
	
    _delay_ms(2000);
	
    Task_Create_System(system_task_1, 0);
    Task_Create_System(system_task_2, 0);
    Task_Create_System(system_task_3, 0);

	return 0;
}

#endif