/**
 * \file
 *
 * \brief User board definition template
 *
 */

 /* This file is intended to contain definitions and configuration details for
 * features and devices that are available on the board, e.g., frequency and
 * startup time for an external crystal, external memory devices, LED and USART
 * pins.
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#ifndef USER_BOARD_H
#define USER_BOARD_H

#include <conf_board.h>

#define LED_TRANS				AVR32_PIN_PA23

//ESC:
//<Hannes,Jonas>
#define TIMER_ESC				&AVR32_TC
#define TIMER_ESC_CHANNEL_1_2	1
#define TIMER_ESC_CHANNEL_3_4	0
#define ESC1_SIGNAL				AVR32_PIN_PA21 //TCA1
#define ESC2_SIGNAL				AVR32_PIN_PA22 //TCB1
#define ESC3_SIGNAL				AVR32_PIN_PA27 //TCB0
#define ESC4_SIGNAL				AVR32_PIN_PA26 //TCA0
//</Hannes,Jonas>


//CONNECTION COMMUNICATION PROCESSOR
#define	RST_ARDU_REG			AVR32_PIN_PB12
#define	MISO_REG				AVR32_PIN_PA00
#define	MOSI_REG				AVR32_PIN_PA01
#define	SCK_REG					AVR32_PIN_PA02

#define SPI_ARDU				&AVR32_SPI
#define SPI_ARDU_MODE			SPI_MODE_0
#define SPI_ARDU_IRQ_LEVEL		1

//SENSOR:
#define ADDR0_SENS_LEVEL		IOPORT_PIN_LEVEL_LOW //ADDRESS SELECTION PIN
#define TWI_ADDR_MASTER			0x50

#define TWI_SENS				&AVR32_TWIM
#define TWI_SENS_SPEED			TWI_FAST_MODE_SPEED //400kHz

//SENSOR Pins:
#define	ADDR0_SENS				AVR32_PIN_PA16
#define	INT_SENS				AVR32_PIN_PA13
#define BOOT_SENS				AVR32_PIN_PA12
#define SDA_SENS				AVR32_PIN_PA10
#define SCL_SENS				AVR32_PIN_PA09
#define RST_SENS				AVR32_PIN_PA08

#define LED_R_SENS				AVR32_PIN_PA15
#define	LED_G_SENS				AVR32_PIN_PA17
#define LED_B_SENS				AVR32_PIN_PA14

#define LED_SENS_ON				IOPORT_PIN_LEVEL_LOW
#define LED_SENS_OFF			IOPORT_PIN_LEVEL_HIGH

//GPIO, ADC

#define ADC0					AVR32_PIN_PA03
#define ADC2					AVR32_PIN_PA05
#define ADC4					AVR32_PIN_PA07

#define	GPIO_PB17				AVR32_PIN_PB17
#define	GPIO_PB18				AVR32_PIN_PB18
#define	GPIO_PA24				AVR32_PIN_PA24
#define	GPIO_PA25				AVR32_PIN_PA25
#define	GPIO_PA18				AVR32_PIN_PA18
#define	GPIO_PA19				AVR32_PIN_PA19
#define	GPIO_PA20				AVR32_PIN_PA20

// External oscillator settings.
// Uncomment and set correct values if external oscillator is used.

// External oscillator frequency
//#define BOARD_XOSC_HZ          8000000

// External oscillator type.
//!< External clock signal
//#define BOARD_XOSC_TYPE        XOSC_TYPE_EXTERNAL
//!< 32.768 kHz resonator on TOSC
//#define BOARD_XOSC_TYPE        XOSC_TYPE_32KHZ
//!< 0.4 to 16 MHz resonator on XTALS
//#define BOARD_XOSC_TYPE        XOSC_TYPE_XTAL

// External oscillator startup time
//#define BOARD_XOSC_STARTUP_US  500000


#endif // USER_BOARD_H
