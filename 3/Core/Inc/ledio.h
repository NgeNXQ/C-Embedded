/*
 * ledio.h
 *
 *  Created on: Nov 12, 2023
 *      Author: denis
 */

#include "main.h"
#include <stdint.h>

#ifndef INC_LEDIO_H_
#define INC_LEDIO_H_

extern uint16_t leds[];

void light_led(const uint16_t, const int);

#endif /* INC_LEDIO_H_ */
