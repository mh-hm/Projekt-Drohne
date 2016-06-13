/*
 * settings.h
 *
 * Created: 25.05.2016 13:55:55
 *  Author: Markus
 */ 


#ifndef SETTINGS_H_
#define SETTINGS_H_

#include "asf.h"

typedef struct{
	int_fast32_t	p;
	int_fast32_t	i;
	int_fast32_t	d;
}pid_settings_t;

typedef struct{
	uint_fast16_t	yaw;
	uint_fast16_t	pitch;
	uint_fast16_t	roll;
}sensor_offset_t;

typedef struct{
		uint_fast16_t	motor_pwm_value_min;
		uint_fast16_t	motor_pwm_value_max;
		pid_settings_t	pid_yaw;
		pid_settings_t	pid_pitch;
		pid_settings_t	pid_roll;
		pid_settings_t	pid_throttle;
		sensor_offset_t	sensor_offset;
	} settings_t;

extern settings_t set;

#endif /* SETTINGS_H_ */