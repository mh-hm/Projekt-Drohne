/*
 * pid.c
 *
 * Created: 31.05.2016 12:08:40
 *  Author: Markus
 */ 

#include <asf.h>
#include "bno055.h"
#include "sensor.h"
#include "pid.h"
#include "motor_control.h"


struct bno055_euler_t set_point = {0,0,0};
uint_fast32_t throotle = 0;


uint_fast32_t get_time_since_last_pid(void)
{
	uint_fast32_t count = Get_sys_count();
	//Check for an cycle counter overflow
	if(last_cycle_count > count)
	{
		uint_fast32_t _c = (UINT32_MAX - last_cycle_count) + count;
		return cpu_cy_2_us(_c, sysclk_get_cpu_hz());
	}
	//No cycle counter overflow
	else
	{
		return cpu_cy_2_us(count-last_cycle_count, sysclk_get_cpu_hz());
	}
}

<<<<<<< HEAD
//w is set value, x is the actual meassured value
=======


	
//w ist Sollwert, x ist Istwert
>>>>>>> origin/master
int_fast32_t calculate_actuating_variable(pid_settings_t _set, int_fast32_t w, int_fast32_t x, pid_tmp *_tmp)
{
	time_since_start += get_time_since_last_pid();		//Calculation of the Controllers runtime
	
	int_fast32_t e,y;
	
	e = w - x;			//Calculatibg the controll deviation
	
	_tmp->e_int += e;	
	
	//Calculating the actuation variable out of the controlled system include a proportional, integration and a differentation part
	// y = KP * e + KI * INT(e,dt) + KD (de/dt)
	y = _set.p * e;
	y += _set.i * _tmp->e_int * time_since_start;
	y += _set.d *(e - _tmp->e_old)/time_since_start;
	
	//Speichern des Wertes f�r die n�chste Regelung
	//Save the Control Deviation for the next controlling cycle
	_tmp->e_old = e;
		
	return y;
}
	
void control()
{
	struct bno055_euler_t x;
	x = read_sensor_euler();
	struct bno055_euler_t y = {0,0,0};
		
		
	//throttle constant for the controller
	uint_fast32_t _thr = 0;
	
	//static temp variable for the controller needed for integration and differentation
	static pid_tmp p_tmp = {0,0};
	static pid_tmp h_tmp = {0,0};
	static pid_tmp r_tmp = {0,0};
	static pid_tmp thr_tmp = {0,0};
	
	//calculate all actuating variables 
	y.p = calculate_actuating_variable(set.pid_pitch, set_point.p, x.p, &p_tmp);
	y.r = calculate_actuating_variable(set.pid_roll, set_point.r, x.r, &r_tmp);
	y.h = calculate_actuating_variable(set.pid_yaw, set_point.h, x.h, &h_tmp);
	int_fast32_t throttle = calculate_actuating_variable(set.pid_throttle, throotle, _thr, &thr_tmp);
	
	//Add all actuating variables to the motor speeds
	uint_fast32_t _esc0 = y.r + y.h +  y.p + _thr;
	uint_fast32_t _esc1 = (-y.r) + y.h +  (-y.p) + _thr;
	uint_fast32_t _esc2 = y.r + (-y.h) +  y.p + _thr;
	uint_fast32_t _esc3 =(-y.r) + (-y.h) +  (-y.p) + _thr;
	
<<<<<<< HEAD
	//read actual motorspeed
	motorspeed speed = get_motor_speed();
	speed.esc0 += _esc0;
	speed.esc1 += _esc1;
	speed.esc2 += _esc2;
	speed.esc3 += _esc3;
	

	//Check if speed values of the motors is in the accepted area
	//Maximum und Minimumwerte �berpr�fen
	if(speed.esc0 < set.motor_esc_timer_value_min) speed.esc0 = set.motor_esc_timer_value_min;
	if(speed.esc0 > set.motor_esc_timer_value_max) speed.esc0 = set.motor_esc_timer_value_max;
	if(speed.esc1 < set.motor_esc_timer_value_min) speed.esc1 = set.motor_esc_timer_value_min;
	if(speed.esc1 > set.motor_esc_timer_value_max) speed.esc1 = set.motor_esc_timer_value_max;
	if(speed.esc2 < set.motor_esc_timer_value_min) speed.esc0 = set.motor_esc_timer_value_min;
	if(speed.esc2 > set.motor_esc_timer_value_max) speed.esc0 = set.motor_esc_timer_value_max;
	if(speed.esc3 < set.motor_esc_timer_value_min) speed.esc1 = set.motor_esc_timer_value_min;
	if(speed.esc3 > set.motor_esc_timer_value_max) speed.esc1 = set.motor_esc_timer_value_max;
	
	//Set new motorspeed
	motor_start(MOTOR_POS_FL, speed.esc0);
	motor_start(MOTOR_POS_FR, speed.esc1);
	motor_start(MOTOR_POS_BL, speed.esc2);
	motor_start(MOTOR_POS_BR, speed.esc3);
=======
	//TODO: check
	//motor_speeds_t speed = get_motor_speeds();
	motor_values_t speed;
	speed.position[MOTOR_POS_FL] = _esc0;
	speed.position[MOTOR_POS_FR] = _esc1;
	speed.position[MOTOR_POS_BL] = _esc2;
	speed.position[MOTOR_POS_BR] = _esc3;
	//TODO: --> Funktion zum Inkrementeiren/Dekrementieren wurde implementiert!
	//NICHT NOTWENDIG: ANSONSTEN SUMMIERT SICH THROTTLE IN JEDEM ZYKLUS AUF UND ALLE MOTOREN AUF VOLLGAS
	
	for (uint_fast8_t i = 0; i < 3; i++)
	{
		if (speed.position[i]>esc_timer_values.max) speed.position[i] = esc_timer_values.max;
	}
	
	//TODO: check
	set_motor_speeds(speed);
>>>>>>> origin/master
}