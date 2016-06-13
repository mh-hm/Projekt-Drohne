/*
 * sensor.c
 *
 * Created: 27.05.2016 08:51:16
 *  Author: Markus
 */ 
#include "asf.h"
#include "sensor.h" 

void sensor_init(void){
	//ioport_set_pin_dir(BOOT_SENS, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(ADDR0_SENS, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(RST_SENS, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(INT_SENS, IOPORT_DIR_INPUT);
	
	//TODO: CHECK BOOT_SENS PIN LEVEL (NOT HIGH??)
	
	//ioport_set_pin_level(BOOT_SENS, HIGH);
	ioport_set_pin_level(ADDR0_SENS, ADDR0_SENS_LEVEL);
	ioport_set_pin_level(RST_SENS, LOW);
	
	sysclk_enable_peripheral_clock(TWI_SENS);
	
	static const gpio_map_t TWI_GPIO_MAP =	{{SDA_SENS, 0},{SCL_SENS, 0}};	 //TODO: DEFINE FUNCTION_A 0
	gpio_enable_module(TWI_GPIO_MAP,2);
		
	twim_options_t _twi_opt;
	_twi_opt.chip = BNO055_TWI_ADDR_SENSOR;
	_twi_opt.pba_hz = sysclk_get_pba_hz();
	_twi_opt.smbus = false;
	_twi_opt.speed = TWI_SENS_SPEED;
	
	delay_ms(5);
	ioport_set_pin_level(RST_SENS, HIGH);
	delay_ms(700);							//SENSOR STARTUP TIME
	twim_master_init(TWI_SENS, &_twi_opt);
}

status_code_t read_sensor_data(bno055_register_addr_t _addr, uint8_t *values, uint_fast32_t count){
	//TODO: WRITE START ADDR _addr_t TO SENSOR BEFOR READING
	return twim_read(TWI_SENS, values, count,BNO055_TWI_ADDR_SENSOR,false);
}

status_code_t write_sensor_data(bno055_register_addr_t _addr, uint8_t *values, uint_fast8_t count)
{
	//TODO: WRITE START ADDR _addr_t TO SENSOR BEFOR WRITING
	return twim_write(TWI_SENS, values, count++, BNO055_TWI_ADDR_SENSOR, false);
}
