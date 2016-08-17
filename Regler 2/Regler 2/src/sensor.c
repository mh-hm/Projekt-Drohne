/*
 * sensor.c
 *
 * Created: 27.05.2016 08:51:16
 *  Author: Markus
 */ 
#include "asf.h"
#include "sensor.h"
#include "settings_t.h"

volatile bno055_reg_page0_t sensor_reg_page0;
volatile bno055_reg_page1_t sensor_reg_page1;

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

void sensor_switch_mode(bno055_opr_mode_t mode)
{
	if (sensor_write_data(BNO055_OPR_MODE_ADDR, &mode,1) == TWI_SUCCESS)
		sensor_reg_page0.opr_mode = mode;
		
	cpu_delay_ms(BNO055_MODE_SWITCHING_DELAY,sysclk_get_cpu_hz());					//SENSOR SWITCHING OPERATION MODE TIME
}

bno055_opr_mode_t sensor_read_mode(void)
{
	sensor_read_data(BNO055_OPR_MODE_ADDR,&sensor_reg_page0.opr_mode,1);
	return sensor_reg_page0.opr_mode;
}

bool sensor_read_calibration(void)
{
	sensor_switch_page(BNO055_PAGE_ZERO);
	bno055_opr_mode_t old_mode = sensor_reg_page0.opr_mode;
	sensor_switch_mode(BNO055_OPERATION_MODE_CONFIG);
	if (sensor_read_data(BNO055_ACCEL_OFFSET_X_LSB_ADDR,&sensor_reg_page0.accel_offset_x_lsb,22) != STATUS_OK) return false;
	
	set.accel_offset.x = (((int16_t) sensor_reg_page0.accel_offset_x_msb) << 8) | ((int16_t) sensor_reg_page0.accel_offset_x_lsb);
	set.accel_offset.y = (((int16_t) sensor_reg_page0.accel_offset_y_msb) << 8) | ((int16_t) sensor_reg_page0.accel_offset_y_lsb);
	set.accel_offset.z = (((int16_t) sensor_reg_page0.accel_offset_z_msb) << 8) | ((int16_t) sensor_reg_page0.accel_offset_z_lsb);
	
	set.mag_offset.x =	 (((int16_t) sensor_reg_page0.mag_offset_x_msb) << 8) | ((int16_t) sensor_reg_page0.mag_offset_x_lsb);
	set.mag_offset.y =	 (((int16_t) sensor_reg_page0.mag_offset_y_msb) << 8) | ((int16_t) sensor_reg_page0.mag_offset_y_lsb);
	set.mag_offset.z =	 (((int16_t) sensor_reg_page0.mag_offset_z_msb) << 8) | ((int16_t) sensor_reg_page0.mag_offset_z_lsb);
	
	set.gyro_offset.x =	 (((int16_t) sensor_reg_page0.gyro_offset_x_msb) << 8) | ((int16_t) sensor_reg_page0.gyro_offset_x_lsb);
	set.gyro_offset.y =	 (((int16_t) sensor_reg_page0.gyro_offset_y_msb) << 8) | ((int16_t) sensor_reg_page0.gyro_offset_y_lsb);
	set.gyro_offset.z =	 (((int16_t) sensor_reg_page0.gyro_offset_z_msb) << 8) | ((int16_t) sensor_reg_page0.gyro_offset_z_lsb);
	
	set.accel_offset.r = (((int16_t) sensor_reg_page0.accel_radius_msb) << 8) | ((int16_t) sensor_reg_page0.accel_radius_lsb);
	set.mag_offset.r =	 (((int16_t) sensor_reg_page0.mag_radius_msb) << 8) | ((int16_t) sensor_reg_page0.mag_radius_lsb);
	
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
	sensor_switch_page(BNO055_PAGE_ZERO);
	struct bno055_accel_t _acc;
	sensor_read_data(BNO055_ACCEL_DATA_X_LSB_ADDR, &sensor_reg_page0.accel_data_x_lsb,6);
	_acc.x = (((int16_t) sensor_reg_page0.accel_data_x_msb) << 8) + ((int16_t) sensor_reg_page0.accel_data_x_lsb);
	_acc.y = (((int16_t) sensor_reg_page0.accel_data_y_msb) << 8) + ((int16_t) sensor_reg_page0.accel_data_y_lsb);
	_acc.z = (((int16_t) sensor_reg_page0.accel_data_z_msb) << 8) + ((int16_t) sensor_reg_page0.accel_data_z_lsb);
	return _acc;
};

struct bno055_gyro_t sensor_read_gyro(void)
{
	sensor_switch_page(BNO055_PAGE_ZERO);
	struct bno055_gyro_t _gyro;
	sensor_read_data(BNO055_GYRO_DATA_X_LSB_ADDR, &sensor_reg_page0.gyro_data_x_lsb,6);
	_gyro.x = (((int16_t) sensor_reg_page0.gyro_data_x_msb) << 8) + ((int16_t) sensor_reg_page0.gyro_data_x_lsb);
	_gyro.y = (((int16_t) sensor_reg_page0.gyro_data_y_msb) << 8) + ((int16_t) sensor_reg_page0.gyro_data_y_lsb);
	_gyro.z = (((int16_t) sensor_reg_page0.gyro_data_z_msb) << 8) + ((int16_t) sensor_reg_page0.gyro_data_z_lsb);
	return _gyro;
};

struct bno055_mag_t sensor_read_mag(void)
{
	sensor_switch_page(BNO055_PAGE_ZERO);
	struct bno055_mag_t _mag;
	sensor_read_data(BNO055_MAG_DATA_X_LSB_ADDR, &sensor_reg_page0.mag_data_x_lsb,6);
	_mag.x = (((int16_t) sensor_reg_page0.mag_data_x_msb) << 8) + ((int16_t) sensor_reg_page0.mag_data_x_lsb);
	_mag.y = (((int16_t) sensor_reg_page0.mag_data_y_msb) << 8) + ((int16_t) sensor_reg_page0.mag_data_y_lsb);
	_mag.z = (((int16_t) sensor_reg_page0.mag_data_z_msb) << 8) + ((int16_t) sensor_reg_page0.mag_data_z_lsb);
	return _mag;
};

struct bno055_euler_t sensor_read_euler(void)
{
	sensor_switch_page(BNO055_PAGE_ZERO);
	struct bno055_euler_t _eul;
	sensor_read_data(BNO055_EULER_H_LSB_ADDR, &sensor_reg_page0.euler_h_lsb,6);
	_eul.h = (((int16_t) sensor_reg_page0.euler_h_msb) << 8) + ((int16_t) sensor_reg_page0.euler_h_lsb);
	_eul.r = (((int16_t) sensor_reg_page0.euler_r_msb) << 8) + ((int16_t) sensor_reg_page0.euler_r_lsb);
	_eul.p = (((int16_t) sensor_reg_page0.euler_p_msb) << 8) + ((int16_t) sensor_reg_page0.euler_p_lsb);
	return _eul;
};

void sensor_read_page0(void)
{
	sensor_switch_page(BNO055_PAGE_ZERO);
	sensor_read_data(BNO055_CHIP_ID_ADDR,&sensor_reg_page0,BNO055_REGISTER_PAGE0_COUNT_BYTES);
}

void sensor_read_page1(void)
{
	sensor_switch_page(BNO055_PAGE_ONE);
	sensor_read_data(BNO055_ACCEL_CONFIG_ADDR,&sensor_reg_page1,BNO055_REGISTER_PAGE1_COUNT_BYTES);
}
	
void sensor_read_all(void)
{
	sensor_read_page0();
	sensor_read_page1();
};

void sensor_switch_page(uint8_t page)
{
	if (page == sensor_reg_page0.page_id) return;
	if (sensor_write_data(BNO055_PAGE_ID_ADDR,&page,1) == TWI_SUCCESS) sensor_reg_page0.page_id = page;
	//TODO: If TWI_ERROR -> do something
};
