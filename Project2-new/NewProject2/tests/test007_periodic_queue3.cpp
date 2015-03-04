#ifdef USE_TEST_007

/*
    Desired Trace
    T007;1;1;1;1;2;
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
		}
		
		Task_Next();
		
		count++;
	}
}

// void periodic2() {
// 	//add_to_trace(2);
// 	//print_trace();
// }

int r_main() {
    uart_init();
    set_trace_test(7);
	
    Task_Create_Periodic(periodic1, 0, 20, 100, 10); // run on 10th tick
    //Task_Create_Periodic(periodic2, 0, 50, 100, 70); // run on 70th tick

	return 0;
}

#endif