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
	float	p;
	float	i;
	float	d;
}pid_settings_t;

typedef struct{
	uint_fast16_t	yaw;
	uint_fast16_t	pitch;
	uint_fast16_t	roll;
}sensor_offset_t;


//TODO: motor_esc_timer_value_interval wird vom Regler nicht ben�tigt
//TODO: sensor_offset sollte nicht ben�tigt werden 
typedef struct{
		pid_settings_t	pid_yaw;
		pid_settings_t	pid_pitch;
		pid_settings_t	pid_roll;
		pid_settings_t	pid_throttle;
		sensor_offset_t	sensor_offset;  
	} settings_t;

extern volatile settings_t set;

void settings_init(bool iopin_save);

void settings_save(void);

void check_save(void);



#endif /* SETTINGS_H_ */