/*
 * motor_control.h
 *
 * Created: 25.05.2016 13:40:29
 *  Author: Jonas, Hannes
 */ 


#ifndef MOTOR_CONTROL_H_
#define MOTOR_CONTROL_H_

#include "asf.h"



// characteristic values for pwm
// getting filled in motor_init() (motor_control.c)
typedef struct{
	int_fast16_t	period; // counter-ticks for one period (4 ms)
	int_fast16_t	min; // min counter-ticks for slowest esc-signal (1 ms high)
	int_fast16_t	max; // max counter-ticks for fastest esc-signal (2 ms high)
	int_fast16_t	max_motorspeed; // max value for motorspeed (ex. for set_motor_speed())
	// min value for motor-speed will always be 0!
}esc_timer_values_t;

esc_timer_values_t esc_timer_values;



// info: to hold pwm-frequency, for having no glitches in pwm-signal
// current timer-compare-values (motor-speed)
// getting pre-filled in motor_init() (motor_control.c)
// change for setting the speed --> implemented by motor_speed()
// values applied at rc-compare on timer-channel (interrupt)
volatile uint16_t  esc_timer_compare_values[4];



typedef enum motor_pos_t{
	// --> 0 = front left, next in order --> (from front to back (from left to right))
	MOTOR_POS_FL = 0,  // FRONT LEFT
	MOTOR_POS_FR = 1,  // FRONT RIGHT
	MOTOR_POS_BL = 2,  // BACK LEFT
	MOTOR_POS_BR = 3,  // BACK RIGHT
	MOTOR_POS_ALL = 4
} motor_pos_t;



// struct for holding values for each motor
// ex. for setting, reading and altering motor-speeds...
typedef struct{
	// contains all 4 motor-values in array, so we could implement it ex. in a for-loop
	int16_t position[4];
	// motor_values_t.position[0=MOTOR_POS_FL] contains value for/from the front-left-motor
	// -1 means, that the specific speed will not be set in set_motor_speeds
	// 0 means, that the specific motor-speed will not be altered, if used with alter_motor_speeds
}motor_values_t;
	



// initializes the motor-functions, setting timer-preferences, etc. ...
void motor_init(void); //TODO: static? --> mit static kommen immer Fehlermeldungen bei der Funktion...


// generate struct with pre-filled _int as values in struct-array
motor_values_t motor_values_pref(int_fast16_t _int);


// start motor with defined speed or change speed
// -1 as motor_speed in struct means that the specific speed is not set
// the values will be checked for right range:
//		on underflow --> min_motorspeed=0 will be set
//		on overflow --> max_motorspeed (as defined in esc_timer_values.max_motorspeed) will be set
void set_motor_speeds(motor_values_t motor_speed);


// alter motor-speeds (decrement/increment)
// 0 as motor_value in struct means that the specific speed stays the same
// negative values will slow down the specific motor (decrement)
// positive values will increment motor-speed
// the values will be checked for right range, after altering:
//		on speed underflow min_motorspeed=0 will be set
//		on speed overflow max_motorspeed (as defined in esc_timer_values.max_motorspeed) will be set
void alter_motor_speeds(motor_values_t motor_altering_values);


// return all motor_speeds in struct
motor_values_t get_motor_speeds(void);


// stop motor defined in motor_pos
void motor_stop(motor_pos_t motor_pos);




//motor-ISR
void t_c1_rc_isr(void);
void t_c2_rc_isr(void);


#endif /* MOTOR_CONTROL_H_ */