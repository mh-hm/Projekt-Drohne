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
#define ESC_FL__SIGNAL_PIN			AVR32_PIN_PA22 //TCB1
#define ESC_FL__SIGNAL_PER_FUNC		PER_FUNC_B
#define ESC_FL__TIMER_CHANNEL		1
//front right (FR)
#define ESC_FR__SIGNAL_PIN			AVR32_PIN_PA21 //TCA1
#define ESC_FR__SIGNAL_PER_FUNC		PER_FUNC_B
#define ESC_FR__TIMER_CHANNEL		1
//back left (BL)
#define ESC_BL__SIGNAL_PIN			AVR32_PIN_PA27 //TCB0
#define ESC_BL__SIGNAL_PER_FUNC		PER_FUNC_C
#define ESC_BL__TIMER_CHANNEL		0
//back right (BR)
#define ESC_BR__SIGNAL_PIN			AVR32_PIN_PA26 //TCA0
#define ESC_BR__SIGNAL_PER_FUNC		PER_FUNC_C
#define ESC_BR__TIMER_CHANNEL		0

//TODO: Anpassung!
#define MOTOR_POS_T_C1_A			MOTOR_POS_BR
#define MOTOR_POS_T_C1_B			MOTOR_POS_BL
#define MOTOR_POS_T_C2_A			MOTOR_POS_FR
#define MOTOR_POS_T_C2_B			MOTOR_POS_FL

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
#define SPI_ARDU_IRQ_LEVEL		3
#define PDCA_IRQ_LEVEL			SPI_ARDU_IRQ_LEVEL

#define PDCA_CHANNEL_SPI_RX		0
#define PDCA_CHANNEL_SPI_TX		1
#define PDCA_IRQ_NR				AVR32_PDCA_IRQ_0

#define USART					&AVR32_USART0
#define USART_RX				AVR32_PIN_PA18
#define USART_RX_PER_FUNC		PER_FUNC_A
#define USART_TX				AVR32_PIN_PA19
#define USART_TX_PER_FUNC		PER_FUNC_A
#define USART_BAUD				38400
#define USART_CHARLENGTH		8
#define USART_PARITY			USART_NO_PARITY
#define USART_STOP				USART_1_STOPBIT
#define USART_CHMODE			CONFIG_USART_SERIAL_MODE

#define USART_DEBUG

//SENSOR:
#define ADDR0_SENS_LEVEL		IOPORT_PIN_LEVEL_LOW //ADDRESS SELECTION PIN
#define TWI_ADDR_MASTER			0x50

#define TWI_SENS				&AVR32_TWIM
#define TWI_SENS_SPEED			TWI_FAST_MODE_SPEED //400kHz

#define PWMA_GCLK_NR			4
#define PWMA_GCLK_SCR			SCIF_GCCTRL_PBACLOCK
#define PWMA_GCLK_DIV			1		//f_GCLK = f_SRC / (2*(DIV+1)) if DIVEN = true
#define PWMA_GCLK_DIVEN			false

//AST

#define AST_RTC					&AVR32_AST
#define AST_SELECTED_CLOCK		AVR32_AST_CSSEL_SLOWCLOCK
#define AST_PRESCALER			6

#define AST_PIR_PID				0
#define AST_PIR_PID_PRESCALSER	13	//10 17ms //TODO: Check Time
#define ast_per0_pir_func		pid_control()

#define AST_PIR_LEDS			1
#define AST_PIR_LEDS_PRESCALER	14	//PERODIC TIME = (2 ^ (PRESCALER + 1)) / CLOCK
#define ast_per1_pir_func		;	//ISR FUNCTION
//TO INIT PER-INTERRUPT:
//ast_set_periodic_interrupt(AST_RTC,AST_PIR_LEDS_PRESCALER,AST_PIR_LEDS);

#define AST_IRQ_LEVEL			1
#define AST_IRQ_NR				AVR32_AST_PER_IRQ
#define AST_IRQ_GROUP			AVR32_AST_IRQ_GROUP1

//REGLER
#define PID_SHIFT_AMOUNT		0
//#define TEST_PID

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
