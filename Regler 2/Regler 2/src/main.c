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
			val = (esc_timer_values.max_motorspeed * sensor_euler.r)/(45*16) + esc_timer_values.min;
			
			//TODO: nicht direkt schreiben benütze Funktion
			//tc_write_ra(TIMER_ESC, ESC_TIMER_USED_CHANNEL1, val);
			//tc_write_ra(TIMER_ESC, ESC_TIMER_USED_CHANNEL2, val);
			//tc_write_rb(TIMER_ESC, ESC_TIMER_USED_CHANNEL1, val);
			//tc_write_rb(TIMER_ESC, ESC_TIMER_USED_CHANNEL2, val);
		}
		else
		{
			//TODO: nicht direkt schreiben benütze Funktion
			//tc_write_ra(TIMER_ESC, ESC_TIMER_USED_CHANNEL1, esc_timer_values.min);
			//tc_write_ra(TIMER_ESC, ESC_TIMER_USED_CHANNEL2, esc_timer_values.min);
			//tc_write_rb(TIMER_ESC, ESC_TIMER_USED_CHANNEL1, esc_timer_values.min);
			//tc_write_rb(TIMER_ESC, ESC_TIMER_USED_CHANNEL2, esc_timer_values.min);
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


