#ifdef USE_TEST_007

/*
    Desired Trace
    T007;1;2;3;4;5;6;7;8;9;10;
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t count = 1;

void periodic1() {
	for(;;) {
		add_to_trace(count);
		
		if ((count % 10) == 0)
		{
			print_trace();
			break;
		}
		
		Task_Next();
		
		count++;
	}
}

int r_main() {
    uart_init();
    set_trace_test(7);
	
    Task_Create_Periodic(periodic1, 0, 20, 100, 10); // run on 10th tick

	return 0;
}

#endif