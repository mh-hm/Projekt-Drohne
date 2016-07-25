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



int main (void)
{
	board_init();
	
	#define TEST_PID
	
	#ifdef TEST_PID
		pid_tmp test_tmp = {0,0};
		uint32_t test_x = 0, test_w = 0, a = 0;
		pid_settings_t test_set;
		motor_values_t speed; 
		test_set.p = 1;
		test_set.i = 1;
		test_set.d = 1;
	#endif

	
	bool w_done = false;
	while (1)
	{
		if (!w_done)
		{
			sensor_euler = read_sensor_euler();
			if(sensor_euler.h != 0 || sensor_euler.p != 0 || sensor_euler.r != 0)
			{
				app_euler = sensor_euler;
				throotle = 0;
				w_done = true;
			}
		}
		else
		{
			#ifdef TEST_PID
				a = calculate_actuating_variable(test_set, test_w, test_x, &test_tmp);
				speed.position[MOTOR_POS_FL] = test_x;
				speed.position[MOTOR_POS_FR] = test_w;
				speed.position[MOTOR_POS_BL] = a;
				speed.position[MOTOR_POS_BR] = a;
				
				set_motor_speeds(speed);
			#else
				control();	
			#endif
		}
		
		
		check_save();
		uint8_t calib_stat;
		read_sensor_data(BNO055_CALIB_STAT_ADDR, &calib_stat, 1);
		
		ioport_toggle_pin_level(GPIO_PA25);
				
	}
}


