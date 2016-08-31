/*
 * pid.h
 *
 * Created: 31.05.2016 12:09:45
 *  Author: Markus
 */ 


#ifndef PID_H_
#define PID_H_

#include <settings_t.h>
#include "motor_control.h"



uint_fast32_t throotle;


enum wind_up_t{
		WIND_UP_OFF,
		WIND_UP_POS,
		WIND_UP_NEG
	};

typedef struct pid_tmp
{
	int32_t	e_old;
	int32_t	e_int;
	enum wind_up_t	wind_up;
}pid_tmp;

motor_values_t volatile speed;

void pid_init(void);
uint_fast32_t get_time_since_last_pid(void);
uint_fast32_t get_controller_runtime();
int_fast32_t calculate_actuating_variable(pid_settings_t _set, int_fast32_t w, int_fast32_t x, pid_tmp *_tmp);
void pid_control();

#endif /* PID_H_ */