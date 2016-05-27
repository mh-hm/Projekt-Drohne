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

int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */
	
	sysclk_init();
	volatile uint_fast32_t val = sysclk_get_pba_hz();
	board_init();
	

	
	uint_fast8_t *value;
	while (1)
	{
		ioport_set_pin_level(LED_TRANS,LOW);
		ioport_set_pin_level(LED_TRANS,HIGH);
	}

	
	//
	//ioport_set_pin_dir(SCL_SENS,IOPORT_DIR_OUTPUT);
	//ioport_set_pin_dir(SDA_SENS,IOPORT_DIR_OUTPUT);
	
	//while(1){
		//ioport_set_pin_level(SCL_SENS, HIGH);
		//ioport_set_pin_level(SDA_SENS, LOW);
		//delay_ms(750);
		//ioport_set_pin_level(SCL_SENS, LOW);
		//ioport_set_pin_level(SDA_SENS, HIGH);
		//delay_ms(750);
	//}
	
	//read_sensor_data(BNO055_GYRO_DATA_X_MSB_ADDR, value, 2);

	
	/* Insert application code here, after the board has been initialized. */
}

