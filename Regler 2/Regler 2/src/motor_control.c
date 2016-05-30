/*
 * motor_control.c
 *
 * Created: 25.05.2016 13:39:59
 *  Author: Jonas, Hannes
 */ 



#include "asf.h"
#include "motor_control.h"

void motor_init(void)
{
	
};

//Start Motor with defined speed or change speed.
//Speed as Array[] with speed[0] as Speed if _motor_pos != MOTOR_POS_ALL
//else Speed[MOTOR_POS_FR] = Speed of MOTOR FRONT RIGHT ...
bool motor_start(motor_pos _motor_pos, uint_fast16_t *speed)
{
	
	return false;
};

//return Array speed[] from all motors
uint_fast16_t *get_motor_speed(void)
{
	return 0;
};


//Stop Motor definied in _motor_pos
bool motor_stop(motor_pos _motor_pos)
{
	return false;
};
