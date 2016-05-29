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
	delay_ms(BNO055_STARTUP_TIME_MS);							//SENSOR STARTUP TIME
	twim_master_init(TWI_SENS, &_twi_opt);
	
	//Konfigurieren des Sensores
	write_sensor_data(BNO055_OPR_MODE_ADDR, BNO055_OPERATION_MODE_NDOF);
	delay_ms(19);												//SENSOR SWITCHING OPERATION MODE TIME
	
	//REMAP X AS Y
	write_sensor_data(BNO055_AXIS_MAP_CONFIG_ADDR, BNO055_REMAP_X_Y,1);											//AXIS REMAPPING
	write_sensor_data(BNO055_AXIS_MAP_SIGN_ADDR, (BNO055_REMAP_AXIS_POSITIVE)&(BNO055_REMAP_AXIS_POSITIVE)&(BNO055_REMAP_AXIS_POSITIVE), 1);														//AXIS REMAPPING SIGN
	
	//Output Data Format
	uint_fast8_t _units = (BNO055_ACCEL_UNIT_MSQ << BNO055_ACCEL_UNIT_POS) & \
		(BNO055_GYRO_UNIT_RPS << BNO055_GYRO_UNIT_POS) & \		//????????
		(BNO055_EULER_UNIT_DEG << BNO055_EULER_UNIT_POS) & \	//????????
		(BNO055_TEMP_UNIT_CELSIUS << BNO055_TEMP_UNIT_POS); 
	write_sensor_data(BNO055_UNIT_SEL_ADDR, _units, 1);					
}

status_code_t read_sensor_data(bno055_register_addr_t _addr, uint8_t *values, uint_fast32_t count){
	//TODO: WRITE START ADDR _addr_t TO SENSOR BEFOR READIN
	twim_write(TWI_SENS, _addr, 1, BNO055_TWI_ADDR_SENSOR, false);
	return twim_read(TWI_SENS, values, count,BNO055_TWI_ADDR_SENSOR,false);
}

status_code_t write_sensor_data(bno055_register_addr_t _addr, uint8_t *values, uint_fast8_t count)
{
	//TODO: WRITE START ADDR _addr_t TO SENSOR BEFOR WRITING
	twim_write(TWI_SENS, _addr, 1, BNO055_TWI_ADDR_SENSOR, false);
	return twim_write(TWI_SENS, values, count, BNO055_TWI_ADDR_SENSOR, false);
}
