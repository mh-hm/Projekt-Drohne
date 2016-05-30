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

uint8_t page_0[106];
uint8_t page_1[31];
struct bno055_accel_t acc;
struct bno055_gyro_t gyr;
struct bno055_euler_t eul;

void read_sensor(void)
{
		//TODO: Works only if start Adresse for read is 0
		uint8_t val = BNO055_PAGE_ZERO; //CHANGE PAGE
		write_sensor_data(BNO055_PAGE_ID_ADDR, &val, 1);
		
		
		read_sensor_data(BNO055_CHIP_ID_ADDR, &page_0, 106);
		
		acc.x = ((int16_t) page_0[BNO055_ACCEL_DATA_X_MSB_ADDR] << 8) + (int16_t) page_0[BNO055_ACCEL_DATA_X_LSB_ADDR];
		acc.y = ((int16_t) page_0[BNO055_ACCEL_DATA_Y_MSB_ADDR] << 8) + (int16_t) page_0[BNO055_ACCEL_DATA_Y_LSB_ADDR];
		acc.z = ((int16_t) page_0[BNO055_ACCEL_DATA_Z_MSB_ADDR] << 8) + (int16_t) page_0[BNO055_ACCEL_DATA_Z_LSB_ADDR];
		
		eul.h = ((int16_t) page_0[BNO055_EULER_H_MSB_ADDR] << 8) + (int16_t) page_0[BNO055_EULER_H_LSB_ADDR];
		eul.p = ((int16_t) page_0[BNO055_EULER_P_MSB_ADDR] << 8) + (int16_t) page_0[BNO055_EULER_P_LSB_ADDR];
		eul.r = ((int16_t) page_0[BNO055_EULER_R_MSB_ADDR] << 8) + (int16_t) page_0[BNO055_EULER_R_LSB_ADDR];
		
		gyr.x = ((int16_t) page_0[BNO055_GYRO_DATA_X_MSB_ADDR] << 8) + (int16_t) page_0[BNO055_GYRO_DATA_X_LSB_ADDR];
		gyr.y = ((int16_t) page_0[BNO055_GYRO_DATA_Y_MSB_ADDR] << 8) + (int16_t) page_0[BNO055_GYRO_DATA_Y_LSB_ADDR];
		gyr.z = ((int16_t) page_0[BNO055_GYRO_DATA_Z_MSB_ADDR] << 8) + (int16_t) page_0[BNO055_GYRO_DATA_Z_LSB_ADDR];
		
		val = BNO055_PAGE_ONE; //CHANGE PAGE
		write_sensor_data(BNO055_PAGE_ID_ADDR, &val, 1);
		
		read_sensor_data(BNO055_CHIP_ID_ADDR, &page_1, 20);
}

int main (void)
{
	board_init();		
	


	while (1)
	{
		read_sensor();
		ioport_set_pin_level(LED_TRANS,LOW);
		ioport_set_pin_level(LED_B_SENS, LED_SENS_OFF);
		ioport_set_pin_level(LED_R_SENS, LED_SENS_OFF);
		ioport_set_pin_level(LED_G_SENS, LED_SENS_OFF);
		delay_ms(250);
		ioport_set_pin_level(LED_B_SENS, LED_SENS_ON);
		ioport_set_pin_level(LED_R_SENS, LED_SENS_OFF);
		ioport_set_pin_level(LED_G_SENS, LED_SENS_OFF);
		delay_ms(250);
		ioport_set_pin_level(LED_TRANS,HIGH);
		ioport_set_pin_level(LED_B_SENS, LED_SENS_OFF);
		ioport_set_pin_level(LED_R_SENS, LED_SENS_ON);
		ioport_set_pin_level(LED_G_SENS, LED_SENS_OFF);
		delay_ms(250);
		ioport_set_pin_level(LED_B_SENS, LED_SENS_OFF);
		ioport_set_pin_level(LED_R_SENS, LED_SENS_OFF);
		ioport_set_pin_level(LED_G_SENS, LED_SENS_ON);
		delay_ms(250);
	}
	
}


