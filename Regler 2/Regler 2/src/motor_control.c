/*
 * motor_control.c
 *
 * Created: 25.05.2016 13:39:59
 *  Author: Jonas, Hannes
 */ 



#include "asf.h"
#include "settings_t.h"
#include "motor_control.h"

void motor_init(void)
{
	tc_sync_start(TIMER_ESC);
	tc_waveform_opt_t opt;
	opt.acpa = TC_EVT_EFFECT_SET;
	opt.acpc = TC_EVT_EFFECT_CLEAR;
	opt.aeevt = TC_EVT_EFFECT_NOOP;
	opt.aswtrg = TC_EVT_EFFECT_NOOP;
	opt.bcpb = TC_EVT_EFFECT_SET;
	opt.bcpc = TC_EVT_EFFECT_CLEAR;
	opt.beevt = TC_EVT_EFFECT_NOOP;
	opt.bswtrg = TC_EVT_EFFECT_NOOP;
	opt.burst = TC_BURST_NOT_GATED;
	opt.channel = TIMER_ESC;
	opt.clki = TC_CLOCK_RISING_EDGE;
	opt.cpcdis = false;
	opt.cpcstop = DISABLE;
	opt.eevt = TC_EXT_EVENT_SEL_TIOB_INPUT;
	opt.eevtedg = TC_SEL_NO_EDGE;
	opt.enetrg = false;
	opt.tcclks = TC_CLOCK_SOURCE_TC4; // 0.001067 ms pro Schritt, 4ms für 0 bis RC in 3749 Schritte, Operationsbereich 1875 (2ms) bis 2811 (3ms)
	opt.wavsel = TC_WAVEFORM_SEL_UP_MODE_RC_TRIGGER;
	tc_init_waveform(TIMER_ESC, &opt);
	set.motor_timer_period = 3749;
	set.motor_timer_value_max = 1875;
	set.motor_timer_value_min = 2811;
	tc_write_rc(TIMER_ESC, TIMER_ESC_1_2_CHANNEL, set.motor_timer_period);
	tc_write_rc(TIMER_ESC, TIMER_ESC_3_4_CHANNEL, set.motor_timer_period);
	tc_write_ra(TIMER_ESC, TIMER_ESC_1_2_CHANNEL, set.motor_timer_value_min);
	tc_write_ra(TIMER_ESC, TIMER_ESC_3_4_CHANNEL, set.motor_timer_value_min);
	tc_write_rb(TIMER_ESC, TIMER_ESC_1_2_CHANNEL, set.motor_timer_value_min);
	tc_write_rb(TIMER_ESC, TIMER_ESC_3_4_CHANNEL, set.motor_timer_value_min);
	
};

//Start Motor with defined speed or change speed.
//Speed as Array[] with speed[0] as Speed if _motor_pos != MOTOR_POS_ALL
//else Speed[MOTOR_POS_FR] = Speed of MOTOR FRONT RIGHT ...
bool motor_start(motor_pos _motor_pos, uint_fast16_t *speed)
{
	return false;
};

//return Array speed[] from all motors
uint_fast16_t *get_motor_speed(void)
{
	int ESC1, ESC2, ESC3, ESC4;
	ESC1 = tc_read_ra(TIMER_ESC, TIMER_ESC_1_2_CHANNEL);
	ESC2 = tc_read_rb(TIMER_ESC, TIMER_ESC_1_2_CHANNEL);
	ESC3 = tc_read_ra(TIMER_ESC, TIMER_ESC_3_4_CHANNEL);
	ESC4 = tc_read_rb(TIMER_ESC, TIMER_ESC_3_4_CHANNEL);
	return 0;
};


//Stop Motor definied in _motor_pos
bool motor_stop(motor_pos _motor_pos)
{
	return false;
};
