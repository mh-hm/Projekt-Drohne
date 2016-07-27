/*
 * rtc.c
 *
 * Created: 27.07.2016 21:16:30
 *  Author: Martin
 */ 

#include "asf.h"
#include "rtc.h"

void rtc_init(volatile avr32_ast_t *ast)
{
	sysclk_enable_peripheral_clock(&ast);
	ast->cr |= (RTC_PRESCALER << AVR32_AST_CR_PSEL);				//Select Prescaler
	ast->clock |= (RTC_SELECTED_CLOCK << AVR32_AST_CLOCK_CSSEL);	//Select Clock
	while(is_rtc_busy(&ast));
	ast->clock |= (1 << AVR32_AST_CLOCK_CEN);						//Enable Clock
	while(is_rtc_busy(&ast));
	ast->cr |= (1 << AVR32_AST_CR_EN);
}

bool is_rtc_busy(volatile avr32_ast_t *ast)
{
	return ast->sr & AVR32_AST_SR_BUSY_MASK != 0;
}

uint32_t rtc_get_hz()
{
	uint32_t clk;
	switch (RTC_SELECTED_CLOCK)
	{
			case AVR32_AST_CSSEL_1KHZCLK:
				clk = 1000;
				break;
			case AVR32_AST_CSSEL_PBCLOCK:
				clk = sysclk_get_pbb_hz();
				break;
			case AVR32_AST_CSSEL_GCLK:
				clk = 0;					//TODO: clk not set
				break;	
			case AVR32_AST_CSSEL_32KHZCLK:
				clk = sysclk_get_pbb_hz();
				break;
			case AVR32_AST_CSSEL_SLOWCLOCK:
				clk = 0;					//TODO: clk not set
				break;
	}
	return clk / (1 << (RTC_PRESCALER + 1));
}

ISR(ast_per0_interrupt_handler, RTC_IRQ_GROUP, RTC_IRQ_LEVEL)
{
	ioport_toggle_pin_level(LED_TRANS);
	while(is_rtc_busy(RTC));
	(*RTC).scr = AVR32_AST_SCR_PER0_MASK;	//TODO: No reset of PER0 Flag
	while(is_rtc_busy(RTC));
};

void rtc_set_periodic_interrupt0(volatile avr32_ast_t *ast)
{
	irq_register_handler(ast_per0_interrupt_handler, RTC_IRQ_NR, RTC_IRQ_LEVEL);
	ast->pir0 = (RTC_PIR0_PRESCALSER << AVR32_AST_PIR0_INSEL);
	ast->ier = AVR32_AST_IER_PER0_MASK;
}

