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

struct bno055_euler_t sensor_euler;

int main (void)
{
	board_init();		

	while (1)
	{
		sensor_euler = read_sensor_euler();
		
		if (sensor_euler.r < 45*16 && sensor_euler.r > 0)
		{
			uint_fast32_t val;
			val = (set.motor_esc_timer_value_interval * sensor_euler.r)/(45*16) + set.motor_esc_timer_value_min;
			
			tc_write_ra(TIMER_ESC, TIMER_ESC_1_2_CHANNEL, val);
			tc_write_ra(TIMER_ESC, TIMER_ESC_3_4_CHANNEL, val);
			tc_write_rb(TIMER_ESC, TIMER_ESC_1_2_CHANNEL, val);
			tc_write_rb(TIMER_ESC, TIMER_ESC_3_4_CHANNEL, val);
		}
		else
		{
			tc_write_ra(TIMER_ESC, TIMER_ESC_1_2_CHANNEL, set.motor_esc_timer_value_min);
			tc_write_ra(TIMER_ESC, TIMER_ESC_3_4_CHANNEL, set.motor_esc_timer_value_min);
			tc_write_rb(TIMER_ESC, TIMER_ESC_1_2_CHANNEL, set.motor_esc_timer_value_min);
			tc_write_rb(TIMER_ESC, TIMER_ESC_3_4_CHANNEL, set.motor_esc_timer_value_min);
		}
		
		ioport_set_pin_level(LED_TRANS,LOW);
		ioport_set_pin_level(LED_B_SENS, LED_SENS_OFF);
		ioport_set_pin_level(LED_R_SENS, LED_SENS_OFF);
		ioport_set_pin_level(LED_G_SENS, LED_SENS_OFF);
		delay_ms(100);
		ioport_set_pin_level(LED_B_SENS, LED_SENS_ON);
		ioport_set_pin_level(LED_R_SENS, LED_SENS_OFF);
		ioport_set_pin_level(LED_G_SENS, LED_SENS_OFF);
		delay_ms(100);
		ioport_set_pin_level(LED_TRANS,HIGH);
		ioport_set_pin_level(LED_B_SENS, LED_SENS_OFF);
		ioport_set_pin_level(LED_R_SENS, LED_SENS_ON);
		ioport_set_pin_level(LED_G_SENS, LED_SENS_OFF);
		delay_ms(100);
		ioport_set_pin_level(LED_B_SENS, LED_SENS_OFF);
		ioport_set_pin_level(LED_R_SENS, LED_SENS_OFF);
		ioport_set_pin_level(LED_G_SENS, LED_SENS_ON);
		delay_ms(100);
	}
}


