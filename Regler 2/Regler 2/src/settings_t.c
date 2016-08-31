/*
 * settings.c
 *
 * Created: 25.05.2016 23:02:54
 *  Author: Martin
 */ 

#include "settings_t.h"

volatile settings_t set;
volatile communication_frame_out_t communication_frame_out;
volatile communication_frame_in_t communication_frame_in;

//Read settings set of UserPage on Controller
//If no data -> Default-values
void settings_init(bool iopin_save)
{
	if (flashcdw_quick_user_page_read())
	{
		//User page empty -> default values
		set_default_values();
	}	
	else
	{
		flashcdw_memcpy(&set, (uint32_t*) AVR32_USER_PAGE_ADDRESS + SETTINGS_USERPAGE_OFFSET, sizeof(set), false);
		if(set.version != SETTINGS_VERSION)
		{
			set_default_values();
			settings_save();
		}
	}
	
	if (iopin_save)
	{
		ioport_set_pin_dir(PIN_SAVE, IOPORT_DIR_INPUT);
		ioport_set_pin_mode(PIN_SAVE, IOPORT_MODE_PULLUP);
	}
};

//Save settings set to UserPage on Controller
void settings_save(void)
{
	flashcdw_memcpy((uint32_t*) AVR32_USER_PAGE_ADDRESS + SETTINGS_USERPAGE_OFFSET,&set, sizeof(set), true);
};

void check_save(void)
{
	static bool pin_old = LOW;
	bool pin = ioport_get_pin_level(PIN_SAVE) ;
	if(pin == LOW && pin_old == HIGH)
	{
		settings_save();
		//TODO: check and add status LED blink
	}
	pin_old = pin;
};

void set_default_values(void)
{
	set.version = SETTINGS_VERSION;
	set.pid_pitch.p = 2;
	set.pid_pitch.i = 0;
	set.pid_pitch.d = 0;
	set.pid_roll.p = 2;
	set.pid_roll.i = 0;
	set.pid_roll.d = 0;
	set.pid_yaw.p = 2;
	set.pid_yaw.i = 0;
	set.pid_yaw.d = 0;
	set.sensor_calibration = 0;
	set.accel_offset.r = 0;
	set.accel_offset.x = 0;
	set.accel_offset.y = 0;
	set.accel_offset.z = 0;
	set.gyro_offset.x = 0;
	set.gyro_offset.y = 0;
	set.gyro_offset.z = 0;
	set.mag_offset.r = 0;
	set.mag_offset.x = 0;
	set.mag_offset.y = 0;
	set.mag_offset.z = 0;
};