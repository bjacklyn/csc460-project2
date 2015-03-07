#ifdef USE_TEST_008

/*
    Desired Trace
    T008;1;2;3;4;5;6;7;8;9;10;
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t count1 = 1;
volatile uint8_t count2 = 1;

void odd_periodic() {
	for(;;) {
		if ((count1 % 2) == 1)
		{
			add_to_trace(count1);
		}
		
		Task_Next();
		
		count1++;
	}
}

void even_periodic() {
	for(;;) {
		if ((count2 % 2) == 0)
		{
			add_to_trace(count2);
		}
		
		if (count2 == 10)
		{
			print_trace();
			break;
		}
		
		Task_Next();
		
		count2++;
	}
}

int r_main() {
    uart_init();
    set_trace_test(8);
	
    Task_Create_Periodic(odd_periodic, 0, 20, 100, 10); // run on 10th tick
	Task_Create_Periodic(even_periodic, 0, 20, 100, 20); // run on 20th tick

	return 0;
}

#endif