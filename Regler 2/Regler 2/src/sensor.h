/*
 * sensor.h
 *
 * Created: 26.05.2016 00:24:48
 *  Author: Martin
 */ 


#ifndef SENSOR_H_
#define SENSOR_H_


#include "asf.h"
#include "bno055.h"
#include "user_board.h"

void sensor_init(void);

void sensor_switch_mode(uint8_t val);

uint8_t sensor_read_mode(void);

bool sensor_read_calibration(void);

void sensor_led_init(void);
/*
	read_Sensor_Data liest von der Registeraddresse _addr count values aus
*/
status_code_t sensor_read_data(bno055_register_addr_t _addr, const uint8_t *values, uint32_t count);

/*
	write_Sensor_Data schreibt an der Registeraddresse _addr count values 
*/
status_code_t sensor_write_data(bno055_register_addr_t _addr, uint8_t *values, uint_fast8_t count);

struct bno055_accel_t sensor_read_accel(void);

struct bno055_gyro_t sensor_read_gyro(void);

struct bno055_mag_t sensor_read_mag(void);

struct bno055_euler_t sensor_read_euler(void);

#endif /* SENSOR_H_ */