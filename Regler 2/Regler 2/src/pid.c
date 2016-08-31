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
#include "ast_rtc.h"

#include <stdio.h>

volatile struct bno055_euler_t sensor_euler;
volatile struct bno055_euler_t communication_frame_in,app_euler;

//#define TEST_PID

#ifdef TEST_PID
	pid_tmp volatile test_tmp = {0,0};
	int32_t volatile test_x = 0, test_w = 0, a = 0;
	pid_settings_t test_set;
#endif	

int_fast32_t volatile act_time = 0;

void pid_init(void)
{
	#ifdef TEST_PID
		test_set.p = 1;
		test_set.i = 1000;
		test_set.d = 10;
		ioport_set_pin_mode(GPIO_PB18,IOPORT_MODE_PULLUP);
	#endif
	act_time = (int_fast32_t) ast_get_per_time_ms(AST_PIR_PID_PRESCALSER);
	ast_set_periodic_interrupt(AST_RTC,AST_PIR_PID_PRESCALSER,AST_PIR_PID);
}

//w is set value, x is the actual meassured value	
//w ist Sollwert, x ist Istwert
int_fast32_t calculate_actuating_variable(pid_settings_t _set, int_fast32_t w, int_fast32_t x, pid_tmp *_tmp)
{
	
	int_fast32_t e,y;
	
	e = w - x;			//Calculating the control deviation
	
	if(abs(e) > 180*16)
	{
		e += (w>x)?(-360*16):(360*16);
	}

	//e = e << PID_SHIFT_AMOUNT;
	
	if(_tmp->wind_up == WIND_UP_OFF) _tmp->e_int += e;
	else if(_tmp->wind_up == WIND_UP_NEG && e > 0) _tmp->e_int += e;
	else if(_tmp->wind_up == WIND_UP_POS && e < 0) _tmp->e_int += e;
	
		
	//Calculating the actuation variable out of the controlled system include a proportional, integration and a differentation part
	// y = KP * e + KI * INT(e,dt) + KD (de/dt)
	y = _set.p * e;
	if (_set.i != 0) y += (_tmp->e_int * act_time) / _set.i;
	y += _set.d *(e - _tmp->e_old)/act_time;
	
	_tmp->wind_up = (y >= esc_timer_values.max_motorspeed)?WIND_UP_POS:(y <= 0)?WIND_UP_NEG:WIND_UP_OFF;
	
	//Speichern des Wertes für die nächste Regelung
	//Save the Control Deviation for the next controlling cycle
	_tmp->e_old = e;

	return y; // >> PID_SHIFT_AMOUNT;
}
	
void pid_control()
{
	ioport_toggle_pin_level(LED_B_SENS);
	ioport_set_pin_level(GPIO_PA25, HIGH);
	#ifdef TEST_PID
		
		if (ioport_get_pin_level(GPIO_PB18))
			test_w = 20;
		else 
			test_w = -20;
	
		a = calculate_actuating_variable(test_set, test_w, test_x, &test_tmp);
		speed.position[MOTOR_POS_FL] = test_tmp.wind_up;
		speed.position[MOTOR_POS_FR] = test_w;
		speed.position[MOTOR_POS_BL] = a;
		speed.position[MOTOR_POS_BR] = test_tmp.e_int;
	#else
		communication_frame_out.sensor_euler =  sensor_read_euler();
		struct bno055_euler_t volatile y = {0,0,0};
		
		//throttle constant for the controller
		uint_fast32_t volatile _thr = 0;
	
		//static temp variable for the controller needed for integration and differentation
		static volatile pid_tmp p_tmp = {0,0,false};
		static volatile pid_tmp h_tmp = {0,0,false};
		static volatile pid_tmp r_tmp = {0,0,false};
	//	static pid_tmp thr_tmp = {0,0};
	
	
		//calculate all actuating variables 
		y.p = calculate_actuating_variable(set.pid_pitch, (communication_frame_in.app_euler.p<0)?communication_frame_in.app_euler.p+360*16:communication_frame_in.app_euler.p, (communication_frame_out.sensor_euler.p<0)?sensor_euler.p+360*16:sensor_euler.p, &p_tmp);
		y.r = calculate_actuating_variable(set.pid_roll, communication_frame_in.app_euler.r, communication_frame_out.sensor_euler.r, &r_tmp);
		y.h = calculate_actuating_variable(set.pid_yaw, communication_frame_in.app_euler.h, communication_frame_out.sensor_euler.h, &h_tmp);
		//int_fast32_t throttle = calculate_actuating_variable(set.pid_throttle, throotle, _thr, &thr_tmp);
	
		#ifdef USART_DEBUG
			char str[10];
			sprintf(&str,"%i\t%i\t%i\n", p_tmp.e_old, r_tmp.e_old, h_tmp.e_old);
			usart_write_line(USART,str);
		#endif
	
		//Add all actuating variables to the motor speeds
		int_fast32_t _esc0 =	 y.r	+	 y.h	+	-y.p	+	throotle;
		int_fast32_t _esc1 =	-y.r	+	-y.h	+	-y.p	+	throotle;
		int_fast32_t _esc2 =	 y.r	+	-y.h	+	 y.p	+	throotle;
		int_fast32_t _esc3 =	-y.r	+	 y.h	+	 y.p	+	throotle;
	
		//TODO: check
	
		speed.position[MOTOR_POS_FL] = _esc0;
		speed.position[MOTOR_POS_FR] = _esc1;
		speed.position[MOTOR_POS_BL] = _esc2;
		speed.position[MOTOR_POS_BR] = _esc3;
		
	#endif
	//set_motor_speeds(speed);
	ioport_set_pin_level(GPIO_PA25, LOW);
}

