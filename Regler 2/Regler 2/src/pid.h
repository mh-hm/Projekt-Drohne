/*
 * pid.h
 *
 * Created: 31.05.2016 12:09:45
 *  Author: Markus
 */ 


#ifndef PID_H_
#define PID_H_

#include <settings_t.h>


pid_settings_t settings;
uint_fast32_t e_old;
uint_fast32_t e_int;
uint_fast32_t time_since_start;
uint_fast32_t last_cycle_count;

uint_fast32_t get_time_since_last_pid();



#endif /* PID_H_ */