/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>
#include "settings_t.h"
#include "motor_control.h"
#include "sensor.h"
#include "bno055.h"
#include "com_spi.h"
#include "pid.h"

struct bno055_euler_t sensor_euler;

int main (void)
{
	board_init();		
	bool w_done = false;
	while (1)
	{
		if (!w_done)
		{
			sensor_euler = read_sensor_euler();
			if(sensor_euler.h != 0 || sensor_euler.p != 0 || sensor_euler.r != 0)
			{
				set_point = sensor_euler;
				throotle = 50;
				w_done = true;
			}
		}
		else
		control();
		
		check_save();
		
		//ioport_set_pin_level(LED_TRANS,LOW);
		//ioport_set_pin_level(LED_B_SENS, LED_SENS_OFF);
		//ioport_set_pin_level(LED_R_SENS, LED_SENS_OFF);
		//ioport_set_pin_level(LED_G_SENS, LED_SENS_OFF);
		//delay_ms(100);
		//ioport_set_pin_level(LED_B_SENS, LED_SENS_ON);
		//ioport_set_pin_level(LED_R_SENS, LED_SENS_OFF);
		//ioport_set_pin_level(LED_G_SENS, LED_SENS_OFF);
		//delay_ms(100);
		//ioport_set_pin_level(LED_TRANS,HIGH);
		//ioport_set_pin_level(LED_B_SENS, LED_SENS_OFF);
		//ioport_set_pin_level(LED_R_SENS, LED_SENS_ON);
		//ioport_set_pin_level(LED_G_SENS, LED_SENS_OFF);
		//delay_ms(100);
		//ioport_set_pin_level(LED_B_SENS, LED_SENS_OFF);
		//ioport_set_pin_level(LED_R_SENS, LED_SENS_OFF);
		//ioport_set_pin_level(LED_G_SENS, LED_SENS_ON);
		//delay_ms(100);
	}
}


