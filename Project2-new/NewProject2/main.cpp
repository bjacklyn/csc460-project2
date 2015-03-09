#include "main.h"
#include "os.h"
#include "kernel.h"
#include "uart/uart.h"
#include "trace/trace.h"
#include "profile.h"

#define USE_TEST_021

#include "tests/test000_now.cpp"
#include "tests/test001_now_roll_over.cpp" // takes 65 seconds to run
#include "tests/test002_system_queue.cpp"
#include "tests/test003_roundrobin_queue1.cpp"
#include "tests/test004_roundrobin_queue2.cpp"
#include "tests/test005_periodic_queue1.cpp"
#include "tests/test006_periodic_queue2.cpp"
#include "tests/test007_periodic_queue3.cpp"
#include "tests/test008_periodic_valid_tasks_scheduling.cpp"
#include "tests/test009_periodic_rr_queue1.cpp"
#include "tests/test010_periodic_system_queue1.cpp"
#include "tests/test011_periodic_system_queue2.cpp"
#include "tests/test012_periodic_invalid_wcet.cpp"
#include "tests/test013_periodic_invalid_tasks_scheduling.cpp"
#include "tests/test014_all_tasks.cpp"
#include "tests/test015_service_init.cpp"
#include "tests/test016_service_init_too_many_services.cpp"
#include "tests/test017_service_subscribe_all_task_levels.cpp"
#include "tests/test018_service_invalid_periodic_subscribe.cpp"
#include "tests/test019_service_subscribe_non_existing_service.cpp"
#include "tests/test020_service_publish_all_task_levels.cpp"
#include "tests/test021_service_multiple_subscribe_and_publish.cpp"
#include "tests/test022_service_publish_from_interrupt.cpp"

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