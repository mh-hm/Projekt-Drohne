/*
 * sensor.c
 *
 * Created: 27.05.2016 08:51:16
 *  Author: Markus
 */ 
#include "asf.h"
#include "sensor.h" 

void sensor_init(void){
	ioport_set_pin_dir(BOOT_SENS, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(ADDR0_SENS, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(RST_SENS, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(INT_SENS, IOPORT_DIR_INPUT);
	
	
	//ioport_set_pin_mode(SDA_SENS, IOPORT_MODE_OPEN_DRAIN);
	//ioport_set_pin_mode(SCL_SENS, IOPORT_MODE_OPEN_DRAIN);
	ioport_set_pin_mode(SCL_SENS,IOPORT_MODE_PULLUP);
	ioport_set_pin_mode(SDA_SENS,IOPORT_MODE_PULLUP);
	//ioport_set_pin_dir(SDA_SENS, IOPORT_DIR_OUTPUT);
	//ioport_set_pin_dir(SCL_SENS, IOPORT_DIR_OUTPUT);
	
	ioport_set_pin_level(BOOT_SENS, HIGH);
	ioport_set_pin_level(ADDR0_SENS, ADDR0_SENS_LEVEL);
	ioport_set_pin_level(RST_SENS, LOW);
	
	sysclk_enable_peripheral_clock(TWI_SENS);
	
	twim_options_t _twi_opt;
	_twi_opt.chip = TWI_ADDR_MASTER;
	_twi_opt.pba_hz = sysclk_get_pba_hz();
	_twi_opt.smbus = false;
	_twi_opt.speed = TWI_SENS_SPEED;
	
	delay_ms(5);
	ioport_set_pin_level(RST_SENS, HIGH);
	delay_ms(5);
	
	twim_master_enable(TWI_SENS);
	twim_master_init(TWI_SENS, &_twi_opt);
	twim_master_enable(TWI_SENS);
}

status_code_t read_sensor_data(bno055_register_addr_t _addr, uint_fast8_t *values, uint_fast32_t count){
	return twim_read(TWI_SENS, values, count,BNO055_TWI_ADDR_SENSOR,false);
	
}

status_code_t write_sensor_data(bno055_register_addr_t _addr, uint_fast8_t *values, uint_fast8_t count)
{
	return twim_write(TWI_SENS, values, count, BNO055_TWI_ADDR_SENSOR, false);
}
