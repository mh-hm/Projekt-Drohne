/*
 * motor_control.h
 *
 * Created: 25.05.2016 13:40:29
 *  Author: Jonas, Hannes
 */ 


#ifndef MOTOR_CONTROL_H_
#define MOTOR_CONTROL_H_

#include "asf.h"

typedef enum motor_pos{
	MOTOR_POS_FL = 0, //FRONT LEFT     // --> links vorne beginnend, dann im Uhrzeiger-Sinn
	MOTOR_POS_FR = 1, //FRONT RIGHT
	MOTOR_POS_BL = 2, //BACK LEFT	
	MOTOR_POS_BR = 3,  //BACK RIGHT
	MOTOR_POS_ALL = 4
	}motor_pos;

typedef struct motorspeed
{
	uint_fast32_t esc0;
	uint_fast32_t esc1;
	uint_fast32_t esc2;
	uint_fast32_t esc3;
}motorspeed;


void motor_init(void);

bool motor_start(motor_pos _motor_pos, uint_fast16_t *speed);
//Start Motor with defined speed or change speed.
//Speed as Array[] with speed[0] as Speed if _motor_pos != MOTOR_POS_ALL
//else Speed[MOTOR_POS_FR] = Speed of MOTOR FRONT RIGHT ...

motorspeed get_motor_speed(void);
//return Array speed[] from all motors

bool motor_stop(motor_pos _motor_pos);
//Stop Motor definied in _motor_pos

#endif /* MOTOR_CONTROL_H_ */