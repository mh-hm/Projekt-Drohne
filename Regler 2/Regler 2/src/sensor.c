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
	
	sensor_led_init();
	
	//TODO: CHECK BOOT_SENS PIN LEVEL (NOT HIGH??)
	
	//ioport_set_pin_level(BOOT_SENS, HIGH);
	ioport_set_pin_level(ADDR0_SENS, ADDR0_SENS_LEVEL);
	ioport_set_pin_level(RST_SENS, LOW);
	
	sysclk_enable_peripheral_clock(TWI_SENS);
	
	static const gpio_map_t TWI_GPIO_MAP =	{{SDA_SENS, SDA_SENS_PER_FUNC},{SCL_SENS, SCL_SENS_PER_FUNC}};
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
	
	//REMAP X AS Y
	uint8_t val;
	val = BNO055_REMAP_X_Y;
	write_sensor_data(BNO055_AXIS_MAP_CONFIG_ADDR, &val,1);											//AXIS REMAPPING
	val = (BNO055_REMAP_AXIS_POSITIVE)&(BNO055_REMAP_AXIS_POSITIVE)&(BNO055_REMAP_AXIS_POSITIVE);
	write_sensor_data(BNO055_AXIS_MAP_SIGN_ADDR, &val, 1);														//AXIS REMAPPING SIGN
	
	//Output Data Format
	val = (BNO055_ACCEL_UNIT_MSQ << BNO055_ACCEL_UNIT_POS) & \
		(BNO055_GYRO_UNIT_RPS << BNO055_GYRO_UNIT_POS) & \
		(BNO055_EULER_UNIT_DEG << BNO055_EULER_UNIT_POS) & \
		(BNO055_TEMP_UNIT_CELSIUS << BNO055_TEMP_UNIT_POS); 
	write_sensor_data(BNO055_UNIT_SEL_ADDR, &val, 1);
	
	val = BNO055_OPERATION_MODE_NDOF;
	write_sensor_data(BNO055_OPR_MODE_ADDR, &val,1);
	delay_ms(BNO055_SWITCH_OP_TIME_MS);												//SENSOR SWITCHING OPERATION MODE TIME
}

void sensor_led_init(void)
{
	ioport_set_pin_level(LED_B_SENS, LED_SENS_OFF);
	ioport_set_pin_level(LED_G_SENS, LED_SENS_OFF);
	ioport_set_pin_level(LED_R_SENS, LED_SENS_OFF);
	ioport_set_pin_dir(LED_R_SENS, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(LED_G_SENS, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(LED_B_SENS, IOPORT_DIR_OUTPUT);
}

status_code_t read_sensor_data(bno055_register_addr_t _addr, const uint8_t *values, uint32_t count){
	twim_package_t pack;
	pack.addr[0] = _addr;
	pack.addr_length = 1;
	pack.buffer = values;
	pack.chip = BNO055_TWI_ADDR_SENSOR;
	pack.length = count;
	pack.no_wait = false;
	
	return twim_read_packet(TWI_SENS, &pack);
	//return twim_read(TWI_SENS, values, count,BNO055_TWI_ADDR_SENSOR,false);
}

status_code_t write_sensor_data(bno055_register_addr_t _addr, uint8_t *values, uint_fast8_t count)
{
	uint8_t volatile _values[count + 1];
	_values[0] = _addr;
	for (uint_fast8_t i = 0; i< count; i++) _values[i+1] = values[i];
	
	return twim_write(TWI_SENS, &_values, count + 1, BNO055_TWI_ADDR_SENSOR, false);
}
