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





// initializes the motor-functions, setting timer-preferences, etc. ...
void motor_init(void) //TODO: static?
{
	//set-up the pins of all ESC
	ioport_set_pin_dir(ESC_BL__SIGNAL_PIN, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(ESC_BR__SIGNAL_PIN, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(ESC_FL__SIGNAL_PIN, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(ESC_FR__SIGNAL_PIN, IOPORT_DIR_OUTPUT);
	
	
	//enable clock for timer
	sysclk_enable_peripheral_clock(TIMER_ESC);
	
	
	static const gpio_map_t TIMER_GPIO_MAP =	{
		{ESC_FL__SIGNAL_PIN, ESC_FL__SIGNAL_PER_FUNC},
		{ESC_FR__SIGNAL_PIN, ESC_FR__SIGNAL_PER_FUNC},
		{ESC_BL__SIGNAL_PIN, ESC_BL__SIGNAL_PER_FUNC},
		{ESC_BR__SIGNAL_PIN, ESC_BR__SIGNAL_PER_FUNC}
												};
	gpio_enable_module(TIMER_GPIO_MAP,4);

	
	//timer-channel ESC__TIMER_USED_CHANNEL1 (x = channel = [0/1/2])
	tc_waveform_opt_t wf_opt;
	wf_opt.acpa = TC_EVT_EFFECT_CLEAR; //clear TIOAx on RA-Compare [Duty-Cycle]
	wf_opt.acpc = TC_EVT_EFFECT_SET; //set TIOAx on RC-Compare [Frequency]
	wf_opt.aeevt = TC_EVT_EFFECT_NOOP; //external event: no effect on TIOAx
	wf_opt.aswtrg = TC_EVT_EFFECT_NOOP; //software-trigger: no effect on TIOAx
	
	wf_opt.bcpb = TC_EVT_EFFECT_CLEAR; //set TIOBx on RB-Compare [Duty-Cycle]
	wf_opt.bcpc = TC_EVT_EFFECT_SET; //clear TIOBx on RC-Compare [Frequency]
	wf_opt.beevt = TC_EVT_EFFECT_NOOP; //external event: no effect on TIOBx
	wf_opt.bswtrg = TC_EVT_EFFECT_NOOP; //software-trigger: no effect on TIOBx
	
	wf_opt.burst = TC_BURST_NOT_GATED; //no burst
	wf_opt.channel = ESC_TIMER_USED_CHANNEL1; //timer-channel
	wf_opt.clki = TC_CLOCK_RISING_EDGE; //count on rising-edge
	wf_opt.cpcdis = false; //counter clock disable on RC-Compare: false
	wf_opt.cpcstop = false; //counter clock stop on RC-Compare: false
	wf_opt.eevt = TC_EXT_EVENT_SEL_XC0_OUTPUT; //TIOBx not as Input
	wf_opt.eevtedg = TC_SEL_NO_EDGE; //external event edge selection
	wf_opt.enetrg = false; //event-trigger enable: false
	
	//TIMER_CLOCK1 32 KHz oscillator clock (CLK_32K)
	//TIMER_CLOCK2 PBA Clock / 2
	//TIMER_CLOCK3 PBA Clock / 8
	//TIMER_CLOCK4 PBA Clock / 32
	//TIMER_CLOCK5 PBA Clock / 128
	wf_opt.tcclks = TC_CLOCK_SOURCE_TC3; // --> prescaler = 8
	
	
	//timer-values are calculated on base of (variable) pba-clock (pba_c)
	esc_timer_values.period =  sysclk_get_pba_hz()/2000; //ticks for one (periode=4ms): pba_c/2000 = pba_c/(8/4*1000) = pba_c/(prescaler/periode)
	esc_timer_values.max = esc_timer_values.period/2; //ticks for fastest-signal (2ms)
	esc_timer_values.min = esc_timer_values.period/4; //ticks for slowest-signal (1ms)
	esc_timer_values.max_motorspeed = esc_timer_values.max - esc_timer_values.min; //[0; max_motorspeed] = interval for controller
	
	
	
	
	
	wf_opt.wavsel = TC_WAVEFORM_SEL_UP_MODE_RC_TRIGGER;
	tc_init_waveform(TIMER_ESC, &wf_opt); //init waveform, timer-channel=ESC__TIMER_USED_CHANNEL1
	
	
	//edit for channel 1
	wf_opt.channel = ESC_TIMER_USED_CHANNEL2; //timer-channel=ESC__TIMER_USED_CHANNEL2
	tc_init_waveform(TIMER_ESC, &wf_opt);
	
	
	//set esc_timer_compare for motor-speed minimal/off
	for (uint_fast8_t i=0; i<4; ++i)
	{
		esc_timer_compare_values[i] = esc_timer_values.min;
	}
	
	
	//set pwm-frequency
	tc_write_rc(TIMER_ESC, ESC_TIMER_USED_CHANNEL1, esc_timer_values.period);
	tc_write_rc(TIMER_ESC, ESC_TIMER_USED_CHANNEL2, esc_timer_values.period);
	
	//pre-fill
	tc_write_ra(TIMER_ESC, ESC_TIMER_USED_CHANNEL1, esc_timer_values.min);
	tc_write_ra(TIMER_ESC, ESC_TIMER_USED_CHANNEL2, esc_timer_values.min);
	tc_write_rb(TIMER_ESC, ESC_TIMER_USED_CHANNEL1, esc_timer_values.min);
	tc_write_rb(TIMER_ESC, ESC_TIMER_USED_CHANNEL2, esc_timer_values.min);

	tc_start (TIMER_ESC, ESC_TIMER_USED_CHANNEL1); //starting timer-channel
	tc_start (TIMER_ESC, ESC_TIMER_USED_CHANNEL2);
	
	
	
	
	
	tc_interrupt_t ir_conf;
	ir_conf.covfs = 0; // counter-overflow-interrupt
	ir_conf.cpas = 0; // RA-compare-interrupt
	ir_conf.cpbs = 0; // RB-compare-interrupt
	ir_conf.cpcs = 1; // RC-compare-interrupt
	ir_conf.etrgs = 0; // external-trigger-interrupt
	//ir_conf.int // function?
	ir_conf.ldras = 0; // RA-load-interrupt
	ir_conf.ldrbs = 0; // RB-load-interrupt
	ir_conf.lovrs = 0; // load-overrun-interrupt
	
	tc_configure_interrupts(TIMER_ESC, ESC_TIMER_USED_CHANNEL1, &ir_conf);
	tc_configure_interrupts(TIMER_ESC, ESC_TIMER_USED_CHANNEL2, &ir_conf);
	
	//Disable_global_interrupt(); //was done previously --> in board_init() (init.c)
	//INTC_init_interrupts(); //initializing hardware-interrupt-controller
	
	//Register the RTC interrupt handler to the interrupt controller
	INTC_register_interrupt(&t_c1_rc_isr, AVR32_TC_IRQ0, AVR32_INTC_INT0);
	INTC_register_interrupt(&t_c2_rc_isr, AVR32_TC_IRQ1, AVR32_INTC_INT0);
};



#if __GNUC__
	__attribute__((__interrupt__))
//#elif __ICCAVR32__
//#pragma handler = AVR32_TC_IRQ_GROUP, 1
	//__interrupt
#endif
void t_c1_rc_isr(void)
{
	tc_write_ra(TIMER_ESC, ESC_TIMER_USED_CHANNEL1, esc_timer_compare_values[MOTOR_POS_T_C1_A]);
	tc_write_rb(TIMER_ESC, ESC_TIMER_USED_CHANNEL1, esc_timer_compare_values[MOTOR_POS_T_C1_B]);
	tc_read_sr(TIMER_ESC, ESC_TIMER_USED_CHANNEL1);
}

#if __GNUC__
	__attribute__((__interrupt__))
//#elif __ICCAVR32__
//#pragma handler = AVR32_TC_IRQ_GROUP, 1
	//__interrupt
#endif
void t_c2_rc_isr(void)
{
	tc_write_ra(TIMER_ESC, ESC_TIMER_USED_CHANNEL2, esc_timer_compare_values[MOTOR_POS_T_C2_A]);
	tc_write_rb(TIMER_ESC, ESC_TIMER_USED_CHANNEL2, esc_timer_compare_values[MOTOR_POS_T_C2_B]);
	tc_read_sr(TIMER_ESC, ESC_TIMER_USED_CHANNEL2);
}




		
// generate struct with pre-filled _int as values in struct-array
motor_values_t motor_values_pref(int_fast16_t _int)
{
	motor_values_t struct_mv_ret;
	for (uint_fast8_t i=0; i<4; ++i)
	{
		struct_mv_ret.position[i]=_int;
	}
	return struct_mv_ret;
}


// start motor with defined speed or change speed
// -1 as motor_speed in struct means that the specific speed is not set
// the values will be checked for right range:
//		on underflow --> min_motorspeed=0 will be set
//		on overflow --> max_motorspeed (as defined in esc_timer_values.max_motorspeed) will be set
void set_motor_speeds(motor_values_t motor_speeds)
{
	for (uint_fast8_t i=0; i<4; ++i)
	{
		if (motor_speeds.position[i] != -1)
		{
			if (motor_speeds.position[i] < 0) // check underflow
			{
				esc_timer_compare_values[i] = esc_timer_values.min;
			}
			else if (motor_speeds.position[i] > esc_timer_values.max_motorspeed) // check overflow
			{
				esc_timer_compare_values[i] = esc_timer_values.max;
			}
			else
			{
				// value ok
				esc_timer_compare_values[i] = motor_speeds.position[i] + esc_timer_values.min;
			}
		}
	}
}


// alter motor-speeds (decrement/increment)
// 0 as motor_value in struct means that the specific speed stays the same
// negative values will slow down the specific motor (decrement)
// positive values will increment motor-speed
// the values will be checked for right range, after altering:
//		on speed underflow min_motorspeed=0 will be set
//		on speed overflow max_motorspeed (as defined in esc_timer_values.max_motorspeed) will be set
void alter_motor_speeds(motor_values_t motor_altering_values)
{
	for (uint_fast8_t i=0; i<4; ++i)
	{
		if (motor_altering_values.position[i] != 0)
		{
			motor_altering_values.position[i] += esc_timer_compare_values[i]; // altering
			
			// range-checking
			if (motor_altering_values.position[i] < esc_timer_values.min) // underflow
			{
				esc_timer_compare_values[i] = esc_timer_values.min;
			}
			else if (motor_altering_values.position[i] > esc_timer_values.max) // overflow
			{
				esc_timer_compare_values[i] = esc_timer_values.max;
			}
			else
			{
				// ok --> setting
				esc_timer_compare_values[i] = motor_altering_values.position[i];
			}
		}
	}
}


// return all motor_speeds in struct
motor_values_t get_motor_speeds(void)
{
	motor_values_t struct_ms_ret;
	for (uint_fast8_t i=0; i<4; ++i)
	{
		struct_ms_ret.position[i] = esc_timer_compare_values[i] - esc_timer_values.min;
	}
	return struct_ms_ret;
};


//stop motor defined in motor_pos, or all
void motor_stop(motor_pos_t motor_pos)
{
	if (motor_pos == MOTOR_POS_ALL)
	{
		for (uint_fast8_t i=0; i<4; ++i)
		{
			esc_timer_compare_values[i] = esc_timer_values.min;
		}
	}
	else
	{
		esc_timer_compare_values[motor_pos] = esc_timer_values.min;
	}
};