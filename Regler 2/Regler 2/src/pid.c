/*
 * pid.c
 *
 * Created: 31.05.2016 12:08:40
 *  Author: Markus
 */ 

#include <asf.h>
#include "bno055.h"
#include "sensor.h"

#ifdef MARKUS


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
	
//Integrieren und speichern des old Values muss auserhalb der Funktion erfolgen
bno055_euler_t calculate_actuating_variables(bno055_euler_t w)
{
	time_since_start += get_time_since_last_pid();		//Laufzeit des Reglers berechnen
	
	bno055_euler_t y;
	bno055_euler_t e;
	
	
	e.h = set_point.h - w.h;
	e.p = set_point.p - w.p;
	e.r = set_point.r - w.r;					//Berechnen der Regelabweichung
	
	e_int.h += e.h;
	e_int.p += e.p;
	e_int.r += e.r;
	
	
	//Berechnen der Regelstrecke mit Proportional-, Integral- und Differentionsanteil
	// y = KP * e + KI * INT(e,dt) + KD (de/dt)
	y.h = settings.p * e.h + \
	settings.i *e_int.h * time_since_start + \
	settings.d *(set_point.h - old_e->h)/time_since_start;
	
	y.p = settings.p * e.p + \
	settings.i *e_int.p * time_since_start + \
	settings.d *(set_point.p - old_e->p)/time_since_start;
	
	y.r = settings.p * e.r + \
	settings.i *e_int.r * time_since_start + \
	settings.d *(set_point.r - old_e->r)/time_since_start;
	
	//Speichern des Wertes für die nächste Regelung
	old_e.h = e.h;
	old_e.p = e.p;
	old_e.r = e.r;	
	
	return e;
}
	
void actuate()
{
	bno055_euler_t w = read_sensor_euler();
	bno055_euler_t y = calculate_actuating_variables(w);
	
	//Motor Drehzal auslesen und y zu denn richtigen motoren addieren oder subtrahieren
	
}
#endif


