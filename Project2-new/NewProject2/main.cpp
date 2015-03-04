#include "main.h"
#include "os.h"
#include "kernel.h"
#include "uart/uart.h"
#include "trace/trace.h"
#include "profile.h"

#define USE_TEST_007

#include "tests/test000_now.cpp"
#include "tests/test001_now_roll_over.cpp"
#include "tests/test002_system_queue.cpp"
#include "tests/test003_roundrobin_queue1.cpp"
#include "tests/test004_roundrobin_queue2.cpp"
#include "tests/test005_periodic_queue1.cpp"
#include "tests/test006_periodic_queue2.cpp"
#include "tests/test007_periodic_queue3.cpp"

#ifdef _USE_MAIN_
void round_robin(void) { }

/** @brief main function provided by user application. The first task to run. */
int r_main() {
//	Task_Create(round_robin, 0, PERIODIC, 1);
// 	Task_Create(round_robin, 0, PERIODIC, 0);
// 	Task_Create(round_robin, 0, PERIODIC, 0);
// 	Task_Create(round_robin, 0, PERIODIC, 0);
// 	Task_Create(round_robin, 0, PERIODIC, 0);
// 	Task_Create(round_robin, 0, PERIODIC, 0);
// 	Task_Create(round_robin, 0, PERIODIC, 0);
// 	Task_Create(round_robin, 0, PERIODIC, 0);
//  Task_Create(round_robin, 0, PERIODIC, 0); // 9 > maximum number of tasks supported: 
	
	return 0;
}
#endif