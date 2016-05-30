/*
 * motor_control.c
 *
 * Created: 25.05.2016 13:39:59
 *  Author: Jonas, Hannes
 */ 



//PWM-Form: first high, afterwards low

#include "asf.h"
#include "settings_t.h"
#include "motor_control.h"

void motor_init(void)
{
	//for TIMER_ESC_1_2_CHANNEL (x = channel = [0/1/2])
	tc_waveform_opt_t opt;
	opt.acpa = TC_EVT_EFFECT_CLEAR; //clear TIOAx on RA-Compare [Duty-Cycle]
	opt.acpc = TC_EVT_EFFECT_SET; //set TIOAx on RC-Compare [Frequency]
	opt.aeevt = TC_EVT_EFFECT_NOOP; //external event: no effect on TIOAx
	opt.aswtrg = TC_EVT_EFFECT_NOOP; //software-trigger: no effect on TIOAx
	
	opt.bcpb = TC_EVT_EFFECT_CLEAR; //set TIOBx on RB-Compare [Duty-Cycle]
	opt.bcpc = TC_EVT_EFFECT_SET; //clear TIOBx on RC-Compare [Frequency]
	opt.beevt = TC_EVT_EFFECT_NOOP; //external event: no effect on TIOBx
	opt.bswtrg = TC_EVT_EFFECT_NOOP; //software-trigger: no effect on TIOBx
	
	opt.burst = TC_BURST_NOT_GATED; //no burst
	opt.channel = TIMER_ESC_1_2_CHANNEL; //timer-channel //#####
	opt.clki = TC_CLOCK_RISING_EDGE; //count on rising-edge
	opt.cpcdis = false; //counter clock disable on RC-Compare: false
	opt.cpcstop = false; //counter clock stop on RC-Compare: false
	opt.eevt = TC_EXT_EVENT_SEL_XC0_OUTPUT; //TIOBx not as Input //#####
	opt.eevtedg = TC_SEL_NO_EDGE; //external event edge selection
	opt.enetrg = false; //event-trigger enable: false
	
	//TIMER_CLOCK1 32 KHz oscillator clock (CLK_32K)
	//TIMER_CLOCK2 PBA Clock / 2
	//TIMER_CLOCK3 PBA Clock / 8
	//TIMER_CLOCK4 PBA Clock / 32
	//TIMER_CLOCK5 PBA Clock / 128
	opt.tcclks = TC_CLOCK_SOURCE_TC4;
	// PBA-Clock [30 MHz] / 32
	// --> 0.00106667 ms pro Schritt; bei 4ms für 0 bis RC
	// --> 3750 Schritte
	// --> Operationsbereich für Duty-Cycle-Compare (RA/RB): 937 (1ms) bis 1875 (2ms)
	
	opt.wavsel = TC_WAVEFORM_SEL_UP_MODE_RC_TRIGGER;
	tc_init_waveform(TIMER_ESC, &opt); //init waveform channel_esc_1_2
	
	
	//edit for TIMER_ESC_3_4_CHANNEL
	opt.channel = TIMER_ESC_3_4_CHANNEL; //timer-channel //#####
	tc_init_waveform(TIMER_ESC, &opt); //init waveform channel_esc_3_4
	
	
	//###
	set.motor_esc_timer_period = 3750;
	set.motor_esc_timer_value_max = 1875;
	set.motor_esc_timer_value_min = 937;
	set.motor_esc_timer_value_interval = set.motor_esc_timer_value_max - set.motor_esc_timer_value_min;
	
	tc_write_rc(TIMER_ESC, TIMER_ESC_1_2_CHANNEL, set.motor_esc_timer_period);
	tc_write_rc(TIMER_ESC, TIMER_ESC_3_4_CHANNEL, set.motor_esc_timer_period);
	
	tc_write_ra(TIMER_ESC, TIMER_ESC_1_2_CHANNEL, set.motor_esc_timer_value_min);
	tc_write_ra(TIMER_ESC, TIMER_ESC_3_4_CHANNEL, set.motor_esc_timer_value_min);
	tc_write_rb(TIMER_ESC, TIMER_ESC_1_2_CHANNEL, set.motor_esc_timer_value_min);
	tc_write_rb(TIMER_ESC, TIMER_ESC_3_4_CHANNEL, set.motor_esc_timer_value_min);
	
	
	//tc_sync_start(TIMER_ESC);
	tc_start (TIMER_ESC, TIMER_ESC_1_2_CHANNEL) //Start timer-channel for ESC1 & ESC2
	tc_start (TIMER_ESC, TIMER_ESC_3_4_CHANNEL) //Start timer-channel for ESC3 & ESC4
};

//Start Motor with defined speed or change speed.
//Speed as Array[] with speed[0] as Speed if _motor_pos != MOTOR_POS_ALL
//else Speed[MOTOR_POS_FR] = Speed of MOTOR FRONT RIGHT ...
bool motor_start(motor_pos _motor_pos, uint_fast16_t *speed)
{
	//#####
	return false;
};

//return Array speed[] from all motors
uint_fast16_t *get_motor_speed(void)
{
	//#####
	uint_fast16_t ESC1, ESC2, ESC3, ESC4;
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
