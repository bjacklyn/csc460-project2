#ifdef USE_TEST_001

/*
    Desired Trace
    T001;0;25;50;75;100;125;...;
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

extern int r_main() { 
    uart_init();
    set_trace_test(0);
    
	int j;
	uint16_t v;		
    for(j = 0; j < TRACE_ARRAY_SIZE; ++j){
        v = Now();
        add_to_trace(v);
        _delay_ms(275);
    }	
    print_trace();
    return 0;
}

#endif