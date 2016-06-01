/*
 * motor_control.h
 *
 * Created: 25.05.2016 13:40:29
 *  Author: Jonas, Hannes
 */ 


#ifndef MOTOR_CONTROL_H_
#define MOTOR_CONTROL_H_

#include "asf.h"



//characteristic values for pwm
//getting filled in motor_init() (motor_control.c)
typedef struct{
	int_fast16_t	period; //counter-ticks for one period (4 ms)
	int_fast16_t	min; //min counter-ticks for slowest esc-signal (1 ms high)
	int_fast16_t	max; //max counter-ticks for fastest esc-signal (2 ms high)
	int_fast16_t	max_motorspeed; //max value for motorspeed (for set_motor_speed())
}esc_timer_values_t;

esc_timer_values_t esc_timer_values;



//info: to hold pwm-frequency, for having no glitches in pwm-signal
//current timer-compare-values (motor-speed)
//getting pre-filled in motor_init() (motor_control.c)
//change for setting the speed --> implemented by motor_speed()
//values applied at rc-compare on timer-channel (interrupt)
volatile uint_fast16_t  esc_timer_compare_values[4];



typedef enum motor_pos_t{
	// --> 0=front left, next in order --> (from front to back (from left to right))
	MOTOR_POS_FL = 0, //FRONT LEFT
	MOTOR_POS_FR = 1, //FRONT RIGHT
	MOTOR_POS_BL = 2, //BACK LEFT
	MOTOR_POS_BR = 3,  //BACK RIGHT
	MOTOR_POS_ALL = 4
} motor_pos_t;



//struct for setting and getting the motor-speed
typedef struct{
	// contains all 4 motor-speeds in array, so we could implement it ex. in for-loop
	int_fast16_t position[4];
	//motor_speeds_t.position[0=MOTOR_POS_FL] contains motor-speed for/from the front-left-motor
	//initialized with -1 --> -1 means, that the specific speed will not be set/read
}motor_speeds_t;
	




void motor_init(void); //TODO: static?


//generate struct with pre-filled _int
motor_speeds_t motor_speeds_pref(int_fast16_t _int);


//TODO: maybe check value for under-/overflow...

// start motor with defined speed or change speed
// -1 as motor_speed in struct means that the specific speed is not set
void set_motor_speeds(motor_speeds_t motor_speed);


// return motor_speeds in struct
motor_speeds_t get_motor_speeds(void);


// stop motor defined in motor_pos
void motor_stop(motor_pos_t motor_pos);




//motor-ISR
void t_c1_rc_isr(void);
void t_c2_rc_isr(void);


#endif /* MOTOR_CONTROL_H_ */