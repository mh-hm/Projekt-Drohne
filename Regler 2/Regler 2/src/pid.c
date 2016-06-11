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

//w is set value, x is the actual meassured value	
//w ist Sollwert, x ist Istwert
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
	
	//Speichern des Wertes für die nächste Regelung
	//Save the Control Deviation for the next controlling cycle
	_tmp->e_old = e;
		
	return y;
}

void writeDataToSPI(uint_fast16_t data)
{
	//while(!spi_is_tx_empty(SPI_ARDU));
	if(spi_is_tx_empty(SPI_ARDU))
	{
		spi_put(SPI_ARDU, data & 0xFF);
		//while(!spi_is_tx_empty(SPI_ARDU));
		//if(spi_is_tx_empty(SPI_ARDU))
		//{
		//	spi_put(SPI_ARDU, (data & 0xFF));
		//}
	}
}
	
void control()
{
	struct bno055_euler_t x;
	x = read_sensor_euler();
	struct bno055_euler_t y = {0,0,0};
		
	if(spi_is_rx_full(SPI_ARDU))
	{
		uint_fast8_t rxdata = spi_get(SPI_ARDU);
		if(rxdata == 0x01)
		{
			writeDataToSPI((x.h & 0xFF));
		}
		else if(rxdata == 0x02)
		{
			writeDataToSPI((x.h >> 8));
		}
		if(rxdata == 0x05)
		{
			writeDataToSPI((x.p & 0xFF));
		}
		else if(rxdata == 0x06)
		{
			writeDataToSPI((x.p >> 8));
		}
		if(rxdata == 0x10)
		{
			writeDataToSPI((x.r & 0xFF));
		}
		else if(rxdata == 0x11)
		{
			writeDataToSPI((x.r >> 8));
		}
	}
	
		
	//throttle constant for the controller
	uint_fast32_t _thr = 0;
	
	//static temp variable for the controller needed for integration and differentation
	static pid_tmp p_tmp = {0,0};
	static pid_tmp h_tmp = {0,0};
	static pid_tmp r_tmp = {0,0};
//	static pid_tmp thr_tmp = {0,0};
	
	
	//calculate all actuating variables 
	y.p = calculate_actuating_variable(set.pid_pitch, set_point.p, x.p, &p_tmp);
	y.r = calculate_actuating_variable(set.pid_roll, set_point.r, x.r, &r_tmp);
	y.h = calculate_actuating_variable(set.pid_yaw, set_point.h, x.h, &h_tmp);
	//int_fast32_t throttle = calculate_actuating_variable(set.pid_throttle, throotle, _thr, &thr_tmp);
	
	//Add all actuating variables to the motor speeds
	uint_fast32_t _esc0 = y.r + y.h +  y.p + throotle;
	uint_fast32_t _esc1 = (-y.r) + y.h +  (-y.p) + throotle;
	uint_fast32_t _esc2 = y.r + (-y.h) +  y.p + throotle;
	uint_fast32_t _esc3 =(-y.r) + (-y.h) +  (-y.p) + throotle;
	
	//TODO: check
	motor_values_t speed;
	speed.position[MOTOR_POS_FL] = _esc0;
	speed.position[MOTOR_POS_FR] = _esc1;
	speed.position[MOTOR_POS_BL] = _esc2;
	speed.position[MOTOR_POS_BR] = _esc3;
	
	
	set_motor_speeds(speed);
}