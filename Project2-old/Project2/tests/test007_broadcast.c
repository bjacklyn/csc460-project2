/**
 * @file   test007.c
 * @author Scott Craig and Justin Tanner
 * @date   Mon Oct 29 16:19:32 2007
 * 
 * @brief  Test 007 - test if multiple RR's can wait and be signalled by a broadcast
 * 
 */

#include "common.h"
#include "OS/os.h"
#include "uart/uart.h"
#include "trace/trace.h"

enum { A=1, B, C, D, E, F, G };
const unsigned int PT = 3;
const unsigned char PPP[] = {IDLE, 10, A, 1, C, 50};

extern uint16_t trace_counter;
EVENT* print_event;
EVENT* test_event;    

void wait_task_one(void)
{
    for(;;)
    {
        add_to_trace(10);
        
        Event_Wait(test_event);
        
        add_to_trace(11);

        Task_Next();
    }
}

void wait_task_two(void)
{
    for(;;)
    {
        add_to_trace(20);
        
        Event_Wait(test_event);

        add_to_trace(21);

        Task_Next();
    }
}

void A_task(void)
{
    for(;;)
    {
        add_to_trace(3);
        
        Broadcast_And_Next(test_event);
    }
}

int main(void)
{
    /* setup the test */
	uart_init();
	uart_write((uint8_t*)"\r\nSTART\r\n", 9);
    set_test(7);

    /* setup the event */
    test_event = Event_Init();
    print_event = Event_Init();    
      
   	Task_Create(wait_task_one, 0, RR, 0);
   	Task_Create(wait_task_two, 0, RR, 0);
   	Task_Create(A_task, A, PERIODIC, A);
	
    Event_Wait(print_event);
    print_trace();
}
