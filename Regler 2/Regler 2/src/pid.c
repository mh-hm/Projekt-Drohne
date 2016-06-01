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




uint_fast32_t get_time_since_last_pid(void)
{
	uint_fast32_t count = Get_sys_count();
	//Ueberlauf
	if(last_cycle_count > count)
	{
		uint_fast32_t _c = (UINT32_MAX - last_cycle_count) + count;
		return cpu_cy_2_us(_c, sysclk_get_cpu_hz());
	}
	//Kein Ueberlauf
	else
	{
		return cpu_cy_2_us(count-last_cycle_count, sysclk_get_cpu_hz());
	}
}
	

struct bno055_euler_t set_point = {0,0,0};
uint_fast32_t throotle = 0;
	
//w ist Sollwert, x ist Istwert
int_fast32_t calculate_actuating_variable(pid_settings_t _set, int_fast32_t w, int_fast32_t x, pid_tmp *_tmp)
{
	time_since_start += get_time_since_last_pid();		//Laufzeit des Reglers berechnen
	
	int_fast32_t e,y;
	
	e = w - x;			//Berechnen der Regelabweichung
	
	_tmp->e_int += e;	
	
	//Berechnen der Regelstrecke mit Proportional-, Integral- und Differentionsanteil
	// y = KP * e + KI * INT(e,dt) + KD (de/dt)
	y = _set.p * e;
	y += _set.i * _tmp->e_int * time_since_start;
	y += _set.d *(e - _tmp->e_old)/time_since_start;
	
	//Speichern des Wertes für die nächste Regelung
	_tmp->e_old = e;
		
	return y;
}
	
void actuate()
{
	struct bno055_euler_t x;
	x = read_sensor_euler();
	struct bno055_euler_t y = {0,0,0};
	uint_fast32_t _thr = 0;
	
	static pid_tmp p_tmp = {0,0};
	static pid_tmp h_tmp = {0,0};
	static pid_tmp r_tmp = {0,0};
	static pid_tmp thr_tmp = {0,0};
	
	y.p = calculate_actuating_variable(set.pid_pitch, set_point.p, x.p, &p_tmp);
	y.r = calculate_actuating_variable(set.pid_roll, set_point.r, x.r, &r_tmp);
	y.h = calculate_actuating_variable(set.pid_yaw, set_point.h, x.h, &h_tmp);
	int_fast32_t throttle = calculate_actuating_variable(set.pid_throttle, throotle, _thr, &thr_tmp);
	
	//Motor Drehzal auslesen und y zu denn richtigen motoren addieren oder subtrahieren
	uint_fast32_t _esc0 = y.r + y.h +  y.p + _thr;
	uint_fast32_t _esc1 = (-y.r) + y.h +  (-y.p) + _thr;
	uint_fast32_t _esc2 = y.r + (-y.h) +  y.p + _thr;
	uint_fast32_t _esc3 =(-y.r) + (-y.h) +  (-y.p) + _thr;
	
	//TODO: check
	motor_speeds_t speed = get_motor_speeds();
	speed.position[MOTOR_POS_FL] += _esc0;
	speed.position[MOTOR_POS_FR] += _esc1;
	speed.position[MOTOR_POS_BL] += _esc2;
	speed.position[MOTOR_POS_BR] += _esc3;
	//Funktion zum Inkrementeiren/Dekrementeiren kommt noch
	
	//TODO: check
	set_motor_speeds(speed);
}