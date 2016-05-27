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
/*
	read_Sensor_Data liest von der Registeraddresse _addr count values aus
*/
status_code_t read_sensor_data(bno055_register_addr_t _addr, uint_fast8_t *values, uint_fast8_t count);

/*
	write_Sensor_Data schreibt an der Registeraddresse _addr count values 
*/
status_code_t write_sensor_data(bno055_register_addr_t _addr, uint_fast8_t *values, uint_fast8_t count);

#endif /* SENSOR_H_ */