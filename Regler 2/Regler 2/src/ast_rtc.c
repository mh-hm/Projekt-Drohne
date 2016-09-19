/*
 * AST.c
 *
 * Created: 27.07.2016 21:16:30
 *  Author: Martin
 */ 

#include "asf.h"
#include "ast_rtc.h"
#include "pid.h"

bool ast_init(void)
{
	sysclk_enable_peripheral_clock(AST_RTC);
	bool st = ast_init_counter(AST_RTC,AST_SELECTED_CLOCK,AST_PRESCALER,0);
	ast_enable(AST_RTC);
#ifdef CONFIG_SLEEPMGR_ENABLE
	if (AST_SELECTED_CLOCK == AVR32_AST_CSSEL_SLOWCLOCK)
		sleepmgr_lock_mode(SLEEPMGR_STOP);
	else
		sleepmgr_lock_mode(SLEEPMGR_FROZEN);
#endif
	return st;
};

uint32_t ast_get_per_time_ms(uint8_t prescaler)
{
	uint32_t clk;
	switch (AST_SELECTED_CLOCK)
	{
		case AVR32_AST_CSSEL_SLOWCLOCK:	//RCSYS 115kHz
			clk = 115000;
			break;
		case AVR32_AST_CSSEL_32KHZCLK:
			clk = 320000;
			break;
		case AVR32_AST_CSSEL_PBCLOCK:
			clk = sysclk_get_pba_hz();
			break;
		case AVR32_AST_CSSEL_GCLK:
			clk = 0;					//TODO: clk not set
			break;	
		case AVR32_AST_CSSEL_1KHZCLK:
			clk = 1000;
			break;
	}
	return (((uint_fast64_t) (1 << (prescaler + 1))) * 1000 ) / clk;
};

ISR(ast_per0_interrupt_handler, AST_IRQ_GROUP, AST_IRQ_LEVEL)
{
	ast_per0_pir_func;
	ast_clear_status_flag(AST_RTC, AVR32_AST_SCR_PER0_MASK);
};

ISR(ast_per1_interrupt_handler, AST_IRQ_GROUP, AST_IRQ_LEVEL)
{
	ast_per1_pir_func;
	ast_clear_status_flag(AST_RTC, AVR32_AST_SCR_PER1_MASK);
};

void ast_set_periodic_interrupt(volatile avr32_ast_t *ast, uint8_t prescaler, uint8_t periodic_channel)
{
	if (periodic_channel == 0)
		{
			avr32_ast_pir0_t pre;
			pre.insel = prescaler;
			ast_set_periodic0_value(AST_RTC, pre);
			irq_register_handler(ast_per0_interrupt_handler, AST_IRQ_NR, AST_IRQ_LEVEL);
		}
	else
		{
			avr32_ast_pir1_t pre;
			pre.insel = prescaler;
			ast_set_periodic1_value(AST_RTC, pre);
			irq_register_handler(ast_per1_interrupt_handler, AST_IRQ_NR, AST_IRQ_LEVEL);
		}
	ast_enable_periodic_interrupt(AST_RTC,periodic_channel);
};

