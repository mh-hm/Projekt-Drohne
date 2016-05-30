/*
 * com_spi.c
 *
 * Created: 30.05.2016 11:36:49
 *  Author: martin
 */ 

#include "asf.h"

spi_status_t com_spi_init(void)
{
	ioport_set_pin_dir(MISO_REG,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(MOSI_REG,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(SCK_REG, IOPORT_DIR_INPUT);
	ioport_set_pin_level(MISO_REG,IOPORT_PIN_LEVEL_LOW);
	
	static const gpio_map_t SPI_GPIO_MAP =	{{MISO_REG, 0},{MOSI_REG, 0},{SCK_REG,0}};	 //TODO: DEFINE FUNCTION_A 0
	gpio_enable_module(SPI_GPIO_MAP,3);
	
	sysclk_enable_peripheral_clock(SPI_ARDU);
	
	spi_initSlave(SPI_ARDU,8,SPI_MODE_0);
	spi_enable(SPI_ARDU);
	
	irq_register_handler(&com_spi_txrd_int(),,)
	
	return SPI_OK;
}

void com_spi_txrd_int(void)
{
	
};

