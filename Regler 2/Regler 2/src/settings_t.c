/*
 * settings.c
 *
 * Created: 25.05.2016 23:02:54
 *  Author: Martin
 */ 

#include "settings_t.h"

settings_t set;

void settings_init(void)
{
	//TODO: Read user page
	set.motor_esc_timer_period = 3750;
	set.motor_esc_timer_value_max = 1875;
	set.motor_esc_timer_value_min = 937;
	set.motor_esc_timer_value_interval = set.motor_esc_timer_value_max - set.motor_esc_timer_value_min;
	
	
}