/*
 * pid.c
 *
 * Created: 31.05.2016 12:08:40
 *  Author: Markus
 */ 

#include <asf.h>

uint_fast32_t get_time_since_last_pid()
{
	uint_fast32_t count = Get_sys_count();
	//Ueberlauf
	if(last_cycle_count > count)
	{
		uint_fast32_t _c = (UINT32_MAX - last_cycle_count) + count;
		return cpu_cy_2_us(_c);
	}
	//Kein Ueberlauf
	else
	{
		return cpu_cy_2_us((count-last_cycle_count, sysclk_get_cpu_hz());
	}
}
