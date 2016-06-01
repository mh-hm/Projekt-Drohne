/*
 * pid.h
 *
 * Created: 31.05.2016 12:09:45
 *  Author: Markus
 */ 


#ifndef PID_H_
#define PID_H_

#include <settings_t.h>

uint_fast32_t time_since_start;			//Laufzeit des Reglers (Zum Integrieren und Differenzieren)
uint_fast32_t last_cycle_count;			//Variable zur bestimmen der Laufzeit


typedef struct pid_tmp
{
	int_fast32_t e_old;
	int_fast32_t e_int;
}pid_tmp;

uint_fast32_t get_time_since_last_pid(void);
int_fast32_t calculate_actuating_variable(pid_settings_t _set, int_fast32_t w, int_fast32_t x, pid_tmp *_tmp);
void actuate();



#endif /* PID_H_ */