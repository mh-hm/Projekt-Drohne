/*
 * pid.h
 *
 * Created: 31.05.2016 12:09:45
 *  Author: Markus
 */ 


#ifndef PID_H_
#define PID_H_

#include <settings_t.h>


pid_settings_t settings;				//Konstanten des Reglers


//e_old und e_int zu settings hinzufügen da sie nur vom Regler benötigt werden und außerhalb des Reglers nicht benötigt werden ?????????=
bno055_euler_t set_point;				//Führungsgröße der Regelstrecke (Sollwert)
bno055_euler_t e_old;					//Abspeichern der letzten Regelabweichung um das Differential zu bilden
bno055_euler_t e_int;					//Aufsummieren der Regelabweichungen zum Integrieren
bno055_euler_t old_e;					

uint_fast32_t time_since_start;			//Laufzeit des Reglers (Zum Integrieren und Differenzieren)
uint_fast32_t last_cycle_count;			//Variable zur bestimmen der Laufzeit

uint_fast32_t get_time_since_last_pid(void);
bno055_euler_t calculate_actuating_variables(bno055_euler_t w, bno055_euler_t *old_e);
void actuate();



#endif /* PID_H_ */