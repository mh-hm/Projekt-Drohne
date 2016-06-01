/*
 * pid.h
 *
 * Created: 31.05.2016 12:09:45
 *  Author: Markus
 */ 


#ifndef PID_H_
#define PID_H_

#include <settings_t.h>

uint_fast32_t time_since_start;			//Runtime of the controller
uint_fast32_t last_cycle_count;			//Variable vor calculating the runtime

typedef struct pid_tmp
{
	int_fast32_t e_old;
	int_fast32_t e_int;
}pid_tmp;

uint_fast32_t get_time_since_last_pid(void);
uint_fast32_t get_controller_runtime();
int_fast32_t calculate_actuating_variable(pid_settings_t _set, int_fast32_t w, int_fast32_t x, pid_tmp *_tmp);
void control();



#endif /* PID_H_ */