/*
 * motor_control.h
 *
 * Created: 25.05.2016 13:40:29
 *  Author: Jonas, Hannes
 */ 


#ifndef MOTOR_CONTROL_H_
#define MOTOR_CONTROL_H_

extern settings set;

typedef enum motor_pos{
	MOTOR_POS_FR = 0, //FRONT RIGHT
	MOTOR_POS_FL = 1, //FRONT LEFT
	MOTOR_POS_BR = 2, //BACK RIGHT	
	MOTOR_POS_BL = 3,  //BACK LEFT
	MOTOR_POS_ALL = 4
	}motor_pos;

void motor_init();

bool motor_start(motor_pos _motor_pos, uint_fast16_t *speed);
//Start Motor with defined speed.
//Speed as Array[] with speed[0] as Speed if _motor_pos != MOTOR_POS_ALL
//else Speed[MOTOR_POS_FR] = Speed of MOTOR FRONT RIGHT ...

uint_fast16_t *get_motor_speed();
//return Array speed[] from all motors

bool motor_stop(motor_pos _motor_pos);
//Stop Motor definied in _motor_pos

#endif /* MOTOR_CONTROL_H_ */