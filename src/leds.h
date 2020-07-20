#ifndef _LEDS_H_
#define _LEDS_H_

#include "stdint.h"

void LedsCreate(uint16_t *direction);

void LedsTurnOn(uint8_t led);

void LedsTurnOff(uint8_t led);

void LedsTurnAllOn(void);

void LedsTurnAllOff(void);

uint8_t LedsReadState(uint8_t led);

#endif /* _LEDS_H_ */