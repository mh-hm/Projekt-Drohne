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
#include "ast_rtc.h"

	

int main (void)
{
	board_init();

	bool w_done = false;
	ioport_set_pin_level(LED_R_SENS,LED_SENS_ON);
	while (1)
	{
		if (!w_done)
		{
			
			sensor_read_page0();
			//ioport_set_pin_level(LED_B_SENS,sensor_reg_page0.calib_stat==63?LED_SENS_ON:LED_SENS_OFF);
			
			if(sensor_reg_page0.calib_stat == 0xff)
			{
				sensor_read_calibration();
				if  (sensor_euler.h != 0 || sensor_euler.p != 0 || sensor_euler.r != 0)
				{
						sensor_euler = sensor_read_euler();
						app_euler = sensor_euler;
						throotle = 0;
						w_done = true;
						pid_init();
				}
				ioport_set_pin_level(LED_R_SENS,LED_SENS_OFF);
			}
		}
		else
		{
			//ast_enable_async_wakeup(AST_RTC,AVR32_AST_WER_PER0_MASK);
			//sleepmgr_enter_sleep();	//TODO: Interrupt enable? Wake up from interrupt? Wake up from ast possible
			//Sleepmode Stop -> 16,7mA normal Mode -> 28,4mA (30MHz)
			//Sleepmode Stop disables PBA -> is used for motors pwm
		}
		
		check_save();
		//uint8_t calib_stat;
		//read_sensor_data(BNO055_CALIB_STAT_ADDR, &calib_stat, 1);
		
		//ioport_toggle_pin_level(GPIO_PA25);
				
	}
}


