/*
 * com_spi.c
 *
 * Created: 30.05.2016 11:36:49
 *  Author: martin
 */ 

#include "asf.h"
#include "com_spi.h"


ISR(com_spi_interrupt_handler, AVR32_SPI_IRQ_GROUP, SPI_ARDU_IRQ_LEVEL)
{
	//TODO: TXDE wird nie verlassen
	static uint8_t count = UINT8_MAX;
	spi_put(TWI_SENS,count);
	if(count--) count = UINT8_MAX;
};

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
	
	//bool global_interrupt_enabled = cpu_irq_is_enabled ();
	//if (global_interrupt_enabled) cpu_irq_disable();
	
	//irq_register_handler(com_spi_interrupt_handler, AVR32_SPI_IRQ, SPI_ARDU_IRQ_LEVEL);
	//(*SPI_ARDU).ier = AVR32_SPI_IER_TDRE_MASK; //enable Interrupt
	//cpu_irq_enable();
	
	return SPI_OK;
}


