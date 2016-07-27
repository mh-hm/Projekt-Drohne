/*
 * rtc.h
 *
 * Created: 27.07.2016 21:16:37
 *  Author: Martin
 */ 


#ifndef RTC_H_
#define RTC_H_

void rtc_init(volatile avr32_ast_t *ast);
bool is_rtc_busy(volatile avr32_ast_t *ast);
void rtc_set_periodic_interrupt0(volatile avr32_ast_t *ast);
uint32_t rtc_get_hz();

#endif /* RTC_H_ */