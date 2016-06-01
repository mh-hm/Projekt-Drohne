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


//TODO: motor_esc_timer_value_interval wird vom Regler nicht ben�tigt
//TODO: pid_jaw, pid_pitch, pid_roll werden vom selben Regler gesteuert, haben also die selben Werte
//TODO: pid_throttle ist kein PID Regler sondern nur ein Faktor mit dem die Drehzahlen der Motoren erh�ht oder gesenkt wird
typedef struct{
		uint_fast16_t   motor_esc_timer_period;
		uint_fast16_t	motor_esc_timer_value_min;
		uint_fast16_t	motor_esc_timer_value_max;
		uint_fast16_t	motor_esc_timer_value_interval; //Regel-Interval
		pid_settings_t	pid_yaw;
		pid_settings_t	pid_pitch;
		pid_settings_t	pid_roll;
		pid_settings_t	pid_throttle;
		sensor_offset_t	sensor_offset;  
	} settings_t;

extern volatile settings_t set;

void settings_init(void);

void settings_save(void);

#endif /* SETTINGS_H_ */