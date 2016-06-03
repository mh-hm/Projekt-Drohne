/*
 * settings.c
 *
 * Created: 25.05.2016 23:02:54
 *  Author: Martin
 */ 

#include "settings_t.h"

volatile settings_t set;

//Read settings set of UserPage on Controller
//If no data -> Default-values
void settings_init(bool iopin_save)
{
	if (flashcdw_quick_user_page_read())
	{
		//User page empty -> default values
	}	
	else
	{
		flashcdw_memcpy(&set, (uint32_t*) AVR32_USER_PAGE_ADDRESS, sizeof(set), false);
	}
	if (iopin_save)
	{
		ioport_set_pin_dir(PIN_SAVE, IOPORT_DIR_INPUT);
		ioport_set_pin_mode(PIN_SAVE, IOPORT_MODE_PULLUP);
	}
}

//Save settings set to UserPage on Controller
void settings_save(void)
{
	flashcdw_memcpy((uint32_t*) AVR32_USER_PAGE_ADDRESS,&set, sizeof(set), true);
}

void check_save(void)
{
	if(ioport_get_pin_level(PIN_SAVE) == LOW)
	{
		settings_save();
		//TODO: check and add status LED blink
	}
}
