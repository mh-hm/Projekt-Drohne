/*
 * settings.h
 *
 * Created: 25.05.2016 13:55:55
 *  Author: Markus
 */ 


#ifndef SETTINGS_H_
#define SETTINGS_H_

#include "asf.h"
#include "bno055.h"

typedef struct{
	uint32_t	p;
	uint32_t	i;
	uint32_t	d;
}pid_settings_t;

#define		SETTINGS_USERPAGE_OFFSET	32
#define		SETTINGS_VERSION			11

//TODO: read sensor_offset from sensor and save to settings
//IF SETTINGS GET CHANGED -> CHANGE VERSION AND DEFAULT VALUES
typedef struct{
		uint16_t						version;
		pid_settings_t					pid_yaw;
		pid_settings_t					pid_pitch;
		pid_settings_t					pid_roll;
		pid_settings_t					pid_throttle;
		uint8_t							sensor_calibration;	//!= 0 if sensor calibration data was successfuly acquired
		struct bno055_accel_offset_t	accel_offset;
		struct bno055_gyro_offset_t		gyro_offset;
		struct bno055_mag_offset_t		mag_offset;		 
	} settings_t;

extern volatile settings_t set;

void settings_init(bool iopin_save);

void settings_save(void);

void check_save(void);

void set_default_values(void);

#endif /* SETTINGS_H_ */