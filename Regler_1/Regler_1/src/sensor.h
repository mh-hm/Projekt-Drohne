/*
 * sensor.h
 *
 * Created: 26.05.2016 00:24:48
 *  Author: Martin
 */ 


#ifndef SENSOR_H_
#define SENSOR_H_

#include "asf.h"

#if (ADDR0_SENS_LEVEL == LOW)
	#define TWI_ADDR_SENSOR		0x28
#else
	#define TWI_ADDR_SENSOR		0x29
#endif

typedef enum sensor_addr_page_0{
	 SENSOR_CHIP_ID_ADDR			= 0x00,  // BNO055 CHIP ID 
	 SENSOR_ACC_ID_ADDR				= 0x01,  // ACC chip ID 
	 SENSOR_MAG_ID_ADDR				= 0x02,  // MAG chip ID 
	 SENSOR_GYR_ID_ADDR				= 0x03,  // GYRO chip ID 
	 SENSOR_SW_REV_ID_LSB_ADDR		= 0x04,  // SW Revision ID <7:0> 
	 SENSOR_SW_REV_ID_MSB_ADDR		= 0x05,  // SW Revision ID <15:8> 
	 SENSOR_BL_REV_ID_ADDR			= 0x06,  // Bootloader Version 
	 SENSOR_PAGE_ID_ADDR			= 0x07,  // Page ID 
	 SENSOR_ACC_DATA_X_LSB_ADDR		= 0x08,  // Acceleration Data X <7:0> 
	 SENSOR_ACC_DATA_X_MSB_ADDR		= 0x09,  // Acceleration Data X <15:8>
	 SENSOR_ACC_DATA_Y_LSB_ADDR		= 0x0A,  // Acceleration Data Y <7:0>
	 SENSOR_ACC_DATA_Y_MSB_ADDR		= 0x0B,  // Acceleration Data Y <15:8>
	 SENSOR_ACC_DATA_Z_LSB_ADDR		= 0x0C,  // Acceleration Data Z <7:0>
	 SENSOR_ACC_DATA_Z_MSB_ADDR		= 0x0D,  // Acceleration Data Z <15:8>
	 SENSOR_MAG_DATA_X_LSB_ADDR		= 0x0E,  // Magnetometer Data X <7:0>
	 SENSOR_MAG_DATA_X_MSB_ADDR		= 0x0F,  // Magnetometer Data X <15:8>
	 SENSOR_MAG_DATA_Y_LSB_ADDR		= 0x10,  // Magnetometer Data Y <7:0> 
	 SENSOR_MAG_DATA_Y_MSB_ADDR		= 0x11,  // Magnetometer Data Y <15:8> 
	 SENSOR_MAG_DATA_Z_LSB_ADDR		= 0x12,  // Magnetometer Data Z <7:0> 
	 SENSOR_MAG_DATA_Z_MSB_ADDR		= 0x13,  // Magnetometer Data Z <15:8> 
	 SENSOR_GYR_DATA_X_LSB_ADDR		= 0x14,  // Gyroscope Data X <7:0> 
	 SENSOR_GYR_DATA_X_MSB_ADDR		= 0x15,  // Gyroscope Data X <15:8> 
	 SENSOR_GYR_DATA_Y_LSB_ADDR		= 0x16,  // Gyroscope Data Y <7:0> 
	 SENSOR_GYR_DATA_Y_MSB_ADDR		= 0x17,  // Gyroscope Data Y <15:8> 
	 SENSOR_GYR_DATA_Z_LSB_ADDR		= 0x18,  // Gyroscope Data Z <7:0> 
	 SENSOR_GYR_DATA_Z_MSB_ADDR		= 0x19,  // Gyroscope Data Z <15:8>
	 SENSOR_EUL_HEADING_LSB_ADDR	= 0x1A,  // Heading Data <7:0>
	 SENSOR_EUL_HEADING_MSB_ADDR	= 0x1B,  // Heading Data <15:8>
	 SENSOR_EUL_ROLL_LSB_ADDR		= 0x1C,  // Roll Data <7:0>
	 SENSOR_EUL_ROLL_MSB_ADDR		= 0x1D,  // Roll Data <15:8>
	 SENSOR_EUL_PITCH_LSB_ADDR		= 0x1E,  // Pitch Data <7:0>
	 SENSOR_EUL_PITCH_MSB_ADDR		= 0x1F,  // Pitch Data <15:8>
	 SENSOR_QUA_DATA_W_LSB_ADDR		= 0x20,  // Quaternion w Data <7:0>
	 SENSOR_QUA_DATA_W_MSB_ADDR		= 0x21,  // Quaternion w Data <15:8> 
	 SENSOR_QUA_DATA_X_LSB_ADDR		= 0x22,  // Quaternion x Data <7:0> 
	 SENSOR_QUA_DATA_X_MSB_ADDR		= 0x23,  // Quaternion x Data <15:8> 
	 SENSOR_QUA_DATA_Y_LSB_ADDR		= 0x24,  // Quaternion y Data <7:0> 
	 SENSOR_QUA_DATA_Y_MSB_ADDR		= 0x25,  // Quaternion y Data <15:8> 
	 SENSOR_QUA_DATA_Z_LSB_ADDR		= 0x26,  // Quaternion z Data <7:0> 
	 SENSOR_QUA_DATA_Z_MSB_ADDR		= 0x27,  // Quaternion z Data <15:8> 
	 SENSOR_LIA_DATA_X_LSB_ADDR		= 0x28,  // Linear Acceleration Data X <7:0> 
	 SENSOR_LIA_DATA_X_MBS_ADDR		= 0x29,  // Linear Acceleration Data X <15:8>
	 SENSOR_LIA_DATA_Y_LSB_ADDR		= 0x2A,  // Linear Acceleration Data Y <7:0>
	 SENSOR_LIA_DATA_Y_MBS_ADDR		= 0x2B,  // Linear Acceleration Data Y <15:8>
	 SENSOR_LIA_DATA_Z_LSB_ADDR		= 0x2C,  // Linear Acceleration Data Z <7:0>
	 SENSOR_LIA_DATA_Z_MBS_ADDR		= 0x2D,  // Linear Acceleration Data Z <15:8>
	 SENSOR_GRV_DATA_X_LSB_ADDR		= 0x2E,  // Gravity Vector Data X <7:0>
	 SENSOR_GRV_DATA_X_MSB_ADDR		= 0x2F,  // Gravity Vector Data X <15:8>
	 SENSOR_GRV_DATA_Y_LSB_ADDR		= 0x30,  // Gravity Vector Data Y <7:0> 
	 SENSOR_GRV_DATA_Y_MSB_ADDR		= 0x31,  // Gravity Vector Data Y <15:8> 
	 SENSOR_GRV_DATA_Z_LSB_ADDR		= 0x32,  // Gravity Vector Data Z <7:0> 
	 SENSOR_GRV_DATA_Z_MSB_ADDR		= 0x33,  // Gravity Vector Data Z <15:8> 
	 SENSOR_TEMP_ADDR				= 0x34,  // Temperature 
	 SENSOR_SYS_STATUS_ADDR			= 0x39,  // System Status Code
	 SENSOR_SYS_ERR_ADDR			= 0x3A,  // System Error Code 
	 SENSOR_ACC_OFFSET_X_LSB_ADDR	= 0x55,  // Accelerometer Offset X <7:0> 
	 SENSOR_ACC_OFFSET_X_MSB_ADDR	= 0x56,  // Accelerometer Offset X <15:8> 
	 SENSOR_ACC_OFFSET_Y_LSB_ADDR	= 0x57,  // Accelerometer Offset Y <7:0> 
	 SENSOR_ACC_OFFSET_Y_MSB_ADDR	= 0x58,  // Accelerometer Offset Y <15:8> 
	 SENSOR_ACC_OFFSET_Z_LSB_ADDR	= 0x59,  // Accelerometer Offset Z <7:0> 
	 SENSOR_ACC_OFFSET_Z_MSB_ADDR	= 0x5A,  // Accelerometer Offset Z <15:8>
	 SENSOR_MAG_OFFSET_X_LSB_ADDR	= 0x5B,  // Magnetometer Offset X <7:0>
	 SENSOR_MAG_OFFSET_X_MSB_ADDR	= 0x5C,  // Magnetometer Offset X <15:8>
	 SENSOR_MAG_OFFSET_Y_LSB_ADDR	= 0x5D,  // Magnetometer Offset Y <7:0>
	 SENSOR_MAG_OFFSET_Y_MSB_ADDR	= 0x5E,  // Magnetometer Offset Y <15:8>
	 SENSOR_MAG_OFFSET_Z_LSB_ADDR	= 0x5F,  // Magnetometer Offset Z <7:0>
	 SENSOR_MAG_OFFSET_Z_MSB_ADDR	= 0x60,  // Magnetometer Offset Z <15:8> 
	 SENSOR_GYR_OFFSET_X_LSB_ADDR	= 0x61,  // Gyroscope Offset X <7:0> 
	 SENSOR_GYR_OFFSET_X_MSB_ADDR	= 0x62,  // Gyroscope Offset X <15:8> 
	 SENSOR_GYR_OFFSET_Y_LSB_ADDR	= 0x63,  // Gyroscope Offset Y <7:0> 
	 SENSOR_GYR_OFFSET_Y_MSB_ADDR	= 0x64,  // Gyroscope Offset Y <15:8> 
	 SENSOR_GYR_OFFSET_Z_LSB_ADDR	= 0x65,  // Gyroscope Offset Z <7:0> 
	 SENSOR_GYR_OFFSET_Z_MSB_ADDR	= 0x66,  // Gyroscope Offset Z <15:8> 
	 SENSOR_ACC_RADIUS_LSB_ADDR		= 0x67,  // Accelerometer Radius 
	 SENSOR_ACC_RADIUS_MSB_ADDR		= 0x68,  // Accelerometer Radius 
	 SENSOR_MAG_RADIUS_LSB_ADDR		= 0x69,  // Magnetometer Radius 
	 SENSOR_MAG_RADIUS_MSB_ADDR		= 0x6A,  // Magnetometer Radius
	 
	 SENSOR_CALIB_STAT_ADDR			= 0x35,  // Bitwise
	 SENSOR_ST_RESULT_ADDR			= 0x36,  // Bitwise 
	 SENSOR_INT_STA_ADDR			= 0x37,  // Bitwise
	 SENSOR_SYS_CLK_STATUS_ADDR		= 0x38,  // Bitwise
	 SENSOR_UNIT_SEL_ADDR			= 0x3B,  // Bitwise
	 SENSOR_OPR_MODE_ADDR			= 0x3D,  // Bitwise 
	 SENSOR_PWR_MODE_ADDR			= 0x3E,  // Bitwise 
	 SENSOR_SYS_TRIGGER_ADDR		= 0x3F,  // Bitwise 
	 SENSOR_TEMP_SOURCE_ADDR		= 0x40,  // Bitwise
	 SENSOR_AXIS_MAP_CONFIG_ADDR	= 0x41,  // Bitwise
	 SENSOR_AXIS_MAP_SIGN_ADDR		= 0x42   // Bitwise 	 
}sensor_addr_page_0;


#endif /* SENSOR_H_ */