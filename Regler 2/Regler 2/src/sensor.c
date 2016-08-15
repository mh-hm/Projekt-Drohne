/*
 * sensor.c
 *
 * Created: 27.05.2016 08:51:16
 *  Author: Markus
 */ 
#include "asf.h"
#include "sensor.h"
#include "settings_t.h"

bno055_reg_page0_u_t sensor_reg_page0;
bno055_reg_page1_u_t sensor_reg_page1;

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
	
	cpu_delay_ms(5,sysclk_get_cpu_hz());
	
	ioport_set_pin_level(RST_SENS, HIGH);
	cpu_delay_ms(BNO055_STARTUP_TIME_MS,sysclk_get_cpu_hz());							//SENSOR STARTUP TIME
	twim_master_init(TWI_SENS, &_twi_opt);
	
	//Konfigurieren des Sensores
	
	uint8_t val;
	//Change to external Clock
	sensor_read_all();
	val = BNO055_CLK_SRC_EXTERNAL << BNO055_CLK_SRC_POS;
 	sensor_write_data(BNO055_CLK_SRC_REG, &val,1);
	//Remap Axes
 	val = BNO055_REMAP_X_Y_Z_TYPE0;
	sensor_write_data(BNO055_AXIS_MAP_CONFIG_ADDR, &val,1);											//AXIS REMAPPING
	val =	(BNO055_REMAP_AXIS_POSITIVE << BNO055_REMAP_Z_SIGN_POS)| \
			(BNO055_REMAP_AXIS_NEGATIVE << BNO055_REMAP_Y_SIGN_POS )| \
			(BNO055_REMAP_AXIS_POSITIVE << BNO055_REMAP_X_SIGN_POS);
	sensor_write_data(BNO055_AXIS_MAP_SIGN_ADDR, &val, 1);											//AXIS REMAPPING SIGN
	
	//Output Data Format
	val =	(BNO055_ACCEL_UNIT_MSQ << BNO055_ACCEL_UNIT_POS) | \
			(BNO055_GYRO_UNIT_RPS << BNO055_GYRO_UNIT_POS) | \
			(BNO055_EULER_UNIT_DEG << BNO055_EULER_UNIT_POS) | \
			(BNO055_TEMP_UNIT_CELSIUS << BNO055_TEMP_UNIT_POS); 
	sensor_write_data(BNO055_UNIT_SEL_ADDR, &val, 1);
	
	sensor_switch_mode(BNO055_OPERATION_MODE_NDOF);
	sensor_read_all();
}

void sensor_switch_mode(uint8_t val)
{
	sensor_write_data(BNO055_OPR_MODE_ADDR, &val,1);
	cpu_delay_ms(BNO055_SWITCH_OP_TIME_MS,sysclk_get_cpu_hz());					//SENSOR SWITCHING OPERATION MODE TIME
}

uint8_t sensor_read_mode(void)
{
	uint8_t old_mode;
	sensor_read_data(BNO055_OPR_MODE_ADDR,&old_mode,1);
	return old_mode;
}

bool sensor_read_calibration(void)
{
	uint8_t old_mode = sensor_read_mode();
	sensor_switch_mode(BNO055_OPERATION_MODE_CONFIG);
	uint8_t buf[22];
	if (sensor_read_data(BNO055_ACCEL_OFFSET_X_LSB_ADDR,&buf,22) != STATUS_OK) return false;
	
	set.accel_offset.x = (((int16_t) buf[1]) << 8) + ((int16_t) buf[0]);
	set.accel_offset.y = (((int16_t) buf[3]) << 8) + ((int16_t) buf[2]);
	set.accel_offset.z = (((int16_t) buf[5]) << 8) + ((int16_t) buf[4]);
	
	set.mag_offset.x = (((int16_t) buf[7]) << 8) + ((int16_t) buf[6]);
	set.mag_offset.y = (((int16_t) buf[9]) << 8) + ((int16_t) buf[8]);
	set.mag_offset.z = (((int16_t) buf[11]) << 8) + ((int16_t) buf[10]);
	
	set.gyro_offset.x = (((int16_t) buf[13]) << 8) + ((int16_t) buf[12]);
	set.gyro_offset.y = (((int16_t) buf[15]) << 8) + ((int16_t) buf[14]);
	set.gyro_offset.z = (((int16_t) buf[17]) << 8) + ((int16_t) buf[16]);
	
	set.accel_offset.r = (((int16_t) buf[19]) << 8) + ((int16_t) buf[18]);
	set.mag_offset.r = (((int16_t) buf[21]) << 8) + ((int16_t) buf[20]);
	
	set.sensor_calibration = 1;
	sensor_switch_mode(old_mode);
	return true;
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

status_code_t sensor_read_data(bno055_register_addr_t _addr, void* values, uint32_t count){
	
	ioport_set_pin_level(LED_TRANS,HIGH);
	twim_package_t pack;
	pack.addr[0] = _addr;
	pack.addr_length = 1;
	pack.buffer = values;
	pack.chip = BNO055_TWI_ADDR_SENSOR;
	pack.length = count;
	pack.no_wait = false;
	
	status_code_t rt = twim_read_packet(TWI_SENS, &pack);
	ioport_set_pin_level(LED_TRANS,LOW);
	return rt;
}

status_code_t sensor_write_data(bno055_register_addr_t _addr, uint8_t *values, uint_fast8_t count)
{
	ioport_set_pin_level(LED_TRANS,HIGH);
	uint8_t volatile _values[count + 1];
	_values[0] = _addr;
	for (uint_fast8_t i = 0; i< count; i++) _values[i+1] = values[i];
	
	status_code_t rt = twim_write(TWI_SENS, (void*) &_values, count + 1, BNO055_TWI_ADDR_SENSOR, false);
	ioport_set_pin_level(LED_TRANS,LOW);
	return rt;
};

struct bno055_accel_t sensor_read_accel(void)
{
	uint_fast8_t buf[6];
	struct bno055_accel_t _acc;
	sensor_read_data(BNO055_ACCEL_DATA_X_LSB_ADDR, &buf,6);
	_acc.x = (((int16_t) buf[1]) << 8) + ((int16_t) buf[0]);
	_acc.y = (((int16_t) buf[3]) << 8) + ((int16_t) buf[2]);
	_acc.z = (((int16_t) buf[5]) << 8) + ((int16_t) buf[4]);
	return _acc;
};

struct bno055_gyro_t sensor_read_gyro(void)
{
	uint_fast8_t buf[6];
	struct bno055_gyro_t _gyro;
	sensor_read_data(BNO055_GYRO_DATA_X_LSB_ADDR, &buf,6);
	_gyro.x = (((int16_t) buf[1]) << 8) + ((int16_t) buf[0]);
	_gyro.y = (((int16_t) buf[3]) << 8) + ((int16_t) buf[2]);
	_gyro.z = (((int16_t) buf[5]) << 8) + ((int16_t) buf[4]);
	return _gyro;
};

struct bno055_mag_t sensor_read_mag(void)
{
	uint_fast8_t buf[6];
	struct bno055_mag_t _mag;
	sensor_read_data(BNO055_MAG_DATA_X_LSB_ADDR, &buf,6);
	_mag.x = (((int16_t) buf[1]) << 8) + ((int16_t) buf[0]);
	_mag.y = (((int16_t) buf[3]) << 8) + ((int16_t) buf[2]);
	_mag.z = (((int16_t) buf[5]) << 8) + ((int16_t) buf[4]);
	return _mag;
};

struct bno055_euler_t sensor_read_euler(void)
{
	uint8_t buf[6];
	struct bno055_euler_t _eul;
	sensor_read_data(BNO055_EULER_H_LSB_ADDR, &buf,6);
	_eul.h = (((int16_t) buf[1]) << 8) + ((int16_t) buf[0]);
	_eul.r = (((int16_t) buf[3]) << 8) + ((int16_t) buf[2]);
	_eul.p = (((int16_t) buf[5]) << 8) + ((int16_t) buf[4]);
	return _eul;
};

void sensor_read_all(void)
{
	//sensor_switch_page(BNO055_PAGE_ZERO);
	sensor_read_data(BNO055_CHIP_ID_ADDR,&sensor_reg_page0.reg_array,BNO055_REGISTER_PAGE0_COUNT_BYTES);
	sensor_switch_page(BNO055_PAGE_ONE);
	sensor_read_data(BNO055_ACCEL_CONFIG_ADDR,&sensor_reg_page1.reg_array,BNO055_REGISTER_PAGE1_COUNT_BYTES);
	sensor_switch_page(BNO055_PAGE_ZERO);
};

void sensor_switch_page(uint8_t page)
{
	sensor_write_data(BNO055_PAGE_ID_ADDR,&page,1);
};

//uint8_t page_0[106];
//uint8_t page_1[31];
//struct bno055_accel_t acc;
//struct bno055_gyro_t gyr;
//struct bno055_euler_t eul;
//
//void read_sensor(void)
//{
	////!!! Works only if start Adresse for read is 0
	//uint8_t val = BNO055_PAGE_ZERO; //CHANGE PAGE
	//write_sensor_data(BNO055_PAGE_ID_ADDR, &val, 1);
	//
	//
	//read_sensor_data(BNO055_CHIP_ID_ADDR, &page_0, 106);
	//
	//acc.x = ((int16_t) page_0[BNO055_ACCEL_DATA_X_MSB_ADDR] << 8) + (int16_t) page_0[BNO055_ACCEL_DATA_X_LSB_ADDR];
	//acc.y = ((int16_t) page_0[BNO055_ACCEL_DATA_Y_MSB_ADDR] << 8) + (int16_t) page_0[BNO055_ACCEL_DATA_Y_LSB_ADDR];
	//acc.z = ((int16_t) page_0[BNO055_ACCEL_DATA_Z_MSB_ADDR] << 8) + (int16_t) page_0[BNO055_ACCEL_DATA_Z_LSB_ADDR];
	//
	//eul.h = ((int16_t) page_0[BNO055_EULER_H_MSB_ADDR] << 8) + (int16_t) page_0[BNO055_EULER_H_LSB_ADDR];
	//eul.p = ((int16_t) page_0[BNO055_EULER_P_MSB_ADDR] << 8) + (int16_t) page_0[BNO055_EULER_P_LSB_ADDR];
	//eul.r = ((int16_t) page_0[BNO055_EULER_R_MSB_ADDR] << 8) + (int16_t) page_0[BNO055_EULER_R_LSB_ADDR];
	//
	//gyr.x = ((int16_t) page_0[BNO055_GYRO_DATA_X_MSB_ADDR] << 8) + (int16_t) page_0[BNO055_GYRO_DATA_X_LSB_ADDR];
	//gyr.y = ((int16_t) page_0[BNO055_GYRO_DATA_Y_MSB_ADDR] << 8) + (int16_t) page_0[BNO055_GYRO_DATA_Y_LSB_ADDR];
	//gyr.z = ((int16_t) page_0[BNO055_GYRO_DATA_Z_MSB_ADDR] << 8) + (int16_t) page_0[BNO055_GYRO_DATA_Z_LSB_ADDR];
	//
	//val = BNO055_PAGE_ONE; //CHANGE PAGE
	//write_sensor_data(BNO055_PAGE_ID_ADDR, &val, 1);
	//
	//read_sensor_data(BNO055_CHIP_ID_ADDR, &page_1, 20);
//}