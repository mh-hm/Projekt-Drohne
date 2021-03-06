/*
 * com_spi.c
 *
 * Created: 30.05.2016 11:36:49
 *  Author: martin
 */ 

#include "asf.h"
#include "communication.h"
#include "spi_protocol.h"
#include "pid.h"
#include "motor_control.h"

#define MACRO_EN_SPI_RX_INTR		(*SPI_ARDU).ier = AVR32_SPI_IER_RDRF_MASK; //enable Interrupt
#define MACRO_DIS_SPI_RX_INTR		(*SPI_ARDU).idr = AVR32_SPI_IER_RDRF_MASK; //disable Interrupt


motor_values_t speed_1;

ISR(com_spi_interrupt_handler, AVR32_SPI_IRQ_GROUP, SPI_ARDU_IRQ_LEVEL)
{
	irqflags_t flags = cpu_irq_save();
	
	pdca_disable(PDCA_CHANNEL_SPI_RX);
	pdca_disable(PDCA_CHANNEL_SPI_TX);
	volatile pdca_channel_options_t pdca_opt;
	pdca_opt.transfer_size	= PDCA_TRANSFER_SIZE_BYTE;
	pdca_opt.etrig			= false;
	pdca_opt.r_addr			= NULL;
	pdca_opt.r_size			= 0;
	
	uint8_t cmd = spi_get(SPI_ARDU);
	spi_put(SPI_ARDU, cmd);
	//#ifdef USART_DEBUG
		//usart_write_line(USART,"CMD: ");
		//usart_putchar(USART,cmd);
		//usart_putchar(USART,'\n');
	//#endif
	
	switch (cmd)
	{
		case SPI_CMD_EULER_COORD_BATT:
			
			pdca_opt.pid			= AVR32_SPI_PDCA_ID_RX;
			pdca_opt.addr			= (void *)&communication_frame_in;
			pdca_opt.size			= SPI_CMD_EULER_COORD_BATT_NUM_BYTES;
			pdca_init_channel(PDCA_CHANNEL_SPI_RX,&pdca_opt);
			
			pdca_opt.pid			= AVR32_SPI_PDCA_ID_TX;
			pdca_opt.addr			= (void *)&communication_frame_out;
			pdca_opt.size			= SPI_CMD_EULER_COORD_BATT_NUM_BYTES;
			pdca_init_channel(PDCA_CHANNEL_SPI_TX,&pdca_opt);
			
			MACRO_DIS_SPI_RX_INTR;
			pdca_enable_interrupt_transfer_complete(PDCA_CHANNEL_SPI_RX);
			
			pdca_enable(PDCA_CHANNEL_SPI_RX);
			pdca_enable(PDCA_CHANNEL_SPI_TX);
			break;
		case SPI_CMD_MOTOR_DEBUG:
			pdca_opt.pid			= AVR32_SPI_PDCA_ID_RX;
			pdca_opt.addr			= (void *)&speed_1;
			pdca_opt.size			= SPI_CMD_MOTOR_DEBUG_NUM_BYTES;
			pdca_init_channel(PDCA_CHANNEL_SPI_RX,&pdca_opt);
			
			pdca_opt.pid			= AVR32_SPI_PDCA_ID_TX;
			pdca_opt.addr			= (void *)&esc_timer_compare_values;
			pdca_opt.size			= SPI_CMD_MOTOR_DEBUG_NUM_BYTES;
			pdca_init_channel(PDCA_CHANNEL_SPI_TX,&pdca_opt);
			
			MACRO_DIS_SPI_RX_INTR;
			
			pdca_enable_interrupt_transfer_complete(PDCA_CHANNEL_SPI_RX);
			
			pdca_enable(PDCA_CHANNEL_SPI_RX);
			pdca_enable(PDCA_CHANNEL_SPI_TX);
			break;
		case SPI_CMD_SET_WRITE:
			break;
		case SPI_CMD_EULER_COORD_BATT_DIAG:
			pdca_opt.pid			= AVR32_SPI_PDCA_ID_RX;
			pdca_opt.addr			= (void *)&communication_frame_in;
			pdca_opt.size			= SPI_CMD_EULER_COORD_BATT_DIAG_NUM_BYTES;
			pdca_init_channel(PDCA_CHANNEL_SPI_RX,&pdca_opt);
		
			pdca_opt.pid			= AVR32_SPI_PDCA_ID_TX;
			pdca_opt.addr			= (void *)&communication_frame_out;
			pdca_opt.size			= SPI_CMD_EULER_COORD_BATT_DIAG_NUM_BYTES;
			pdca_init_channel(PDCA_CHANNEL_SPI_TX,&pdca_opt);
		
			MACRO_DIS_SPI_RX_INTR;
		
			pdca_enable_interrupt_transfer_complete(PDCA_CHANNEL_SPI_RX);
		
			pdca_enable(PDCA_CHANNEL_SPI_RX);
			pdca_enable(PDCA_CHANNEL_SPI_TX);
			break;
		default:
			break;
	}
	
	cpu_irq_restore(flags);
};

ISR(com_pdca_interrupt_handler, AVR32_PDCA_IRQ_GROUP, PDCA_IRQ_LEVEL)
{
	//#ifdef USART_DEBUG
		//usart_write_line(USART,"CMD END\n");
	//#endif
	pdca_disable_interrupt_transfer_complete(PDCA_CHANNEL_SPI_RX);
	pdca_disable(PDCA_CHANNEL_SPI_RX);
	pdca_disable(PDCA_CHANNEL_SPI_TX);
	//spi_get(SPI_ARDU);
	MACRO_EN_SPI_RX_INTR;
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
	
	
	bool global_interrupt_enabled = cpu_irq_is_enabled ();
	if (global_interrupt_enabled) cpu_irq_disable();
	
	irq_register_handler(com_spi_interrupt_handler, AVR32_SPI_IRQ, SPI_ARDU_IRQ_LEVEL);
	
	sysclk_enable_peripheral_clock(&AVR32_PDCA);
	irq_register_handler(com_pdca_interrupt_handler, PDCA_IRQ_NR, PDCA_IRQ_LEVEL);
	
	MACRO_EN_SPI_RX_INTR;
	
	
	spi_enable(SPI_ARDU);
	cpu_irq_enable();
	
#ifdef CONFIG_SLEEPMGR_ENABLE
	sleepmgr_lock_mode(SLEEPMGR_IDLE);	//PDCA needs HSBClock
#endif
	
	return SPI_OK;
}

void usart_init(void)
{
	
	ioport_set_pin_dir(USART_TX,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(USART_RX,IOPORT_DIR_INPUT);
	
	static const gpio_map_t USART_GPIO_MAP =	{{USART_RX, USART_RX_PER_FUNC},{USART_TX, USART_TX_PER_FUNC}};
	gpio_enable_module(USART_GPIO_MAP,2);
		
	sysclk_enable_peripheral_clock(USART);
	
	usart_options_t opt;
	opt.baudrate = USART_BAUD;
	opt.charlength = USART_CHARLENGTH;
	opt.channelmode = USART_CHMODE;
	opt.paritytype = USART_PARITY;
	opt.stopbits = USART_STOP;	
	usart_init_rs232(USART, &opt, sysclk_get_pba_hz());
}

