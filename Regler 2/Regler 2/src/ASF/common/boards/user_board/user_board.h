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

#define PER_FUNC_A				0
#define PER_FUNC_B				1
#define PER_FUNC_C				2
#define PER_FUNC_D				3

//ESC:
//<Hannes,Jonas>
#define TIMER_ESC					&AVR32_TC
//TODO: Anpassung! (bei Wechsel, bzw. bei konkretem Wissen, welcher ESC auf welchen Anschluss kommt)
//front left (FL)
#define ESC_FL__SIGNAL_PIN			AVR32_PIN_PA26 //TCA0
#define ESC_FL__SIGNAL_PER_FUNC		PER_FUNC_C
#define ESC_FL__TIMER_CHANNEL		0
//front right (FR)
#define ESC_FR__SIGNAL_PIN			AVR32_PIN_PA27 //TCB0
#define ESC_FR__SIGNAL_PER_FUNC		PER_FUNC_C
#define ESC_FR__TIMER_CHANNEL		0
//back left (BL)
#define ESC_BL__SIGNAL_PIN			AVR32_PIN_PA21 //TCA1
#define ESC_BL__SIGNAL_PER_FUNC		PER_FUNC_B
#define ESC_BL__TIMER_CHANNEL		1
//back right (BR)
#define ESC_BR__SIGNAL_PIN			AVR32_PIN_PA22 //TCB1
#define ESC_BR__SIGNAL_PER_FUNC		PER_FUNC_B
#define ESC_BR__TIMER_CHANNEL		1

//TODO: Anpassung!
#define MOTOR_POS_T_C1_A			MOTOR_POS_FL
#define MOTOR_POS_T_C1_B			MOTOR_POS_FR
#define MOTOR_POS_T_C2_A			MOTOR_POS_BL
#define MOTOR_POS_T_C2_B			MOTOR_POS_BR

#define ESC_TIMER_USED_CHANNEL1		0
#define ESC_TIMER_USED_CHANNEL2		1
//</Hannes,Jonas>


//CONNECTION COMMUNICATION PROCESSOR
#define	RST_ARDU_REG			AVR32_PIN_PB12
#define	MISO_REG				AVR32_PIN_PA00
#define MISO_REG_PER_FUNC		PER_FUNC_A
#define	MOSI_REG				AVR32_PIN_PA01
#define MOSI_REG_PER_FUNC		PER_FUNC_A
#define	SCK_REG					AVR32_PIN_PA02
#define SCK_REG_PER_FUNC		PER_FUNC_A

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
#define SDA_SENS_PER_FUNC		PER_FUNC_A
#define SCL_SENS				AVR32_PIN_PA09
#define SCL_SENS_PER_FUNC		PER_FUNC_A
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

#define	GPIO_PB17				AVR32_PIN_PB17	//SAVE PIN
#define	GPIO_PB18				AVR32_PIN_PB18
#define	GPIO_PA24				AVR32_PIN_PA24
#define	GPIO_PA25				AVR32_PIN_PA25
#define	GPIO_PA18				AVR32_PIN_PA18
#define	GPIO_PA19				AVR32_PIN_PA19
#define	GPIO_PA20				AVR32_PIN_PA20

//SAVE PIN
#define PIN_SAVE				GPIO_PB17

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
