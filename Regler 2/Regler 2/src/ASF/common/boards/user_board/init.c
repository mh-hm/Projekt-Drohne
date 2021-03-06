/**
 * \file
 *
 * \brief User board initialization template
 *
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include <asf.h>
#include <board.h>
#include <conf_board.h>
#include "sensor.h"
#include "communication.h"
#include "motor_control.h"
#include "settings_t.h"
#include "pid.h"
#include "ast_rtc.h"

void board_init(void)
{
	sysclk_init();
	INTC_init_interrupts();
	sleepmgr_init();
	ioport_init();
	//ioport_set_pin_dir(RST_ARDU_REG, IOPORT_DIR_OUTPUT);
	settings_init(true);
	sensor_init();
	motor_init();
	com_spi_init();
	ast_init();
	usart_init();
	
		
	ioport_set_pin_dir(GPIO_PA25, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(LED_TRANS, IOPORT_DIR_OUTPUT);
	//ioport_set_pin_dir(RST_ARDU_REG, IOPORT_DIR_INPUT);
}
