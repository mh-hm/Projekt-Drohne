/*
 * settings.c
 *
 * Created: 25.05.2016 23:02:54
 *  Author: Martin
 */ 

#include "settings_t.h"

settings_t set;

//Read settings set of UserPage on Controller
//If no data -> Default-values
void settings_init(void)
{
	if (flashcdw_quick_user_page_read())
	{
		//User page empty -> default values
		set.motor_esc_timer_period = 3750;
		set.motor_esc_timer_value_max = 1875;
		set.motor_esc_timer_value_min = 937;
		set.motor_esc_timer_value_interval = set.motor_esc_timer_value_max - set.motor_esc_timer_value_min;
	}	
	else
	{
		flashcdw_memcpy(&set, AVR32_USER_PAGE_ADDRESS, sizeof(set), false);
	}
}

//Save settings set to UserPage on Controller
void settings_save(void)
{
	flashcdw_memcpy(AVR32_USER_PAGE_ADDRESS,&set, sizeof(set), true);
}