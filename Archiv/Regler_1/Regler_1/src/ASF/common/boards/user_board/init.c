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

void board_init(void)
{
	sysclk_init();
	ioport_init();
	sensor_init();
	
	ioport_set_pin_dir(LED_TRANS, IOPORT_DIR_OUTPUT);
	
}
