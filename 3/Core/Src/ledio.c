/*
 * ledio.c
 *
 *  Created on: Nov 12, 2023
 *      Author: denis
 */

#include "ledio.h"
#include <stdint.h>

uint16_t leds[] = {GPIO_PIN_12, GPIO_PIN_13,  GPIO_PIN_14, GPIO_PIN_15};

void light_led(const uint16_t led, const int delay)
{
	if (delay < 0)
	{
		printf("Error: Invalid delay value %d\n", delay);
		return;
	}

	if (led == GPIO_PIN_12 || led == GPIO_PIN_13 || led == GPIO_PIN_14 || led == GPIO_PIN_15)
	{
		printf("Error: Invalid LED pin %u\n", led);
		return;
	}

	HAL_GPIO_TogglePin(GPIOA, led);
	HAL_Delay(delay);
}

