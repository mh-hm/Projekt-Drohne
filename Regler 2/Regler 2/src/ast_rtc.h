/*
 * ast.h
 *
 * Created: 27.07.2016 21:16:37
 *  Author: Martin
 */ 


#ifndef AST_RTC_H_
#define AST_RTC_H_

bool ast_init(void);
void ast_set_periodic_interrupt(volatile avr32_ast_t *ast, uint8_t prescaler, uint8_t periodic_channel);
uint32_t ast_get_per_time_ms(uint8_t prescaler);

#endif /* AST_RTC_H_ */