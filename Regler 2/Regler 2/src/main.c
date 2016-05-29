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
		
		uint8_t val = BNO055_PAGE_ZERO; //CHANGE PAGE
		write_sensor_data(BNO055_PAGE_ID_ADDR, &val, 1);
		
		
		read_sensor_data(BNO055_CHIP_ID_ADDR, &page_0, 106);
		
		acc.x = ((uint16_t) page_0[BNO055_ACCEL_DATA_X_MSB_ADDR] << 8) + (uint16_t) page_0[BNO055_ACCEL_DATA_X_LSB_ADDR];
		acc.y = ((uint16_t) page_0[BNO055_ACCEL_DATA_Y_MSB_ADDR] << 8) + (uint16_t) page_0[BNO055_ACCEL_DATA_Y_LSB_ADDR];
		acc.z = ((uint16_t) page_0[BNO055_ACCEL_DATA_Z_MSB_ADDR] << 8) + (uint16_t) page_0[BNO055_ACCEL_DATA_Z_LSB_ADDR];
		
		eul.h = ((uint16_t) page_0[BNO055_EULER_H_MSB_ADDR] << 8) + (uint16_t) page_0[BNO055_EULER_H_LSB_ADDR];
		eul.p = ((uint16_t) page_0[BNO055_EULER_P_MSB_ADDR] << 8) + (uint16_t) page_0[BNO055_EULER_P_LSB_ADDR];
		eul.r = ((uint16_t) page_0[BNO055_EULER_R_MSB_ADDR] << 8) + (uint16_t) page_0[BNO055_EULER_R_LSB_ADDR];
		
		gyr.x = ((uint16_t) page_0[BNO055_GYRO_DATA_X_MSB_ADDR] << 8) + (uint16_t) page_0[BNO055_GYRO_DATA_X_LSB_ADDR];
		gyr.y = ((uint16_t) page_0[BNO055_GYRO_DATA_Y_MSB_ADDR] << 8) + (uint16_t) page_0[BNO055_GYRO_DATA_Y_LSB_ADDR];
		gyr.z = ((uint16_t) page_0[BNO055_GYRO_DATA_Z_MSB_ADDR] << 8) + (uint16_t) page_0[BNO055_GYRO_DATA_Z_LSB_ADDR];
		
		val = BNO055_PAGE_ONE; //CHANGE PAGE
		write_sensor_data(BNO055_PAGE_ID_ADDR, &val, 1);
		
		read_sensor_data(BNO055_CHIP_ID_ADDR, &page_1, 31);
}

int main (void)
{
	board_init();		

	
		
	while (1)
	{
		read_sensor();
		ioport_set_pin_level(LED_TRANS,LOW);
		delay_ms(500);
		ioport_set_pin_level(LED_TRANS,HIGH);
		delay_ms(500);
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
	
	

	
	/* Insert application code here, after the board has been initialized. */
}

