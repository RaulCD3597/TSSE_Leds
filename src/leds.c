#include "leds.h"

#define LEDS_ALL_OFF 0x0000
#define LEDS_ALL_ON 0xFFFF
#define LEDS_TO_BITS_OFFSET 1
#define LEDS_BIT_ON 1
#define LED_ON 1
#define LED_OFF 0

static uint16_t *port;

static uint8_t LedToBit(uint8_t led)
{
    return (led - LEDS_TO_BITS_OFFSET);
}

uint16_t BitMask(uint8_t bit)
{
    return (LEDS_BIT_ON << bit);
}

void LedsCreate(uint16_t *direction)
{
    port = direction;
    *port = LEDS_ALL_OFF;
}

void LedsTurnOn(uint8_t led)
{
    *port |= BitMask(LedToBit(led));
}

void LedsTurnOff(uint8_t led)
{
    *port &= ~BitMask(LedToBit(led));
}

void LedsTurnAllOn(void)
{
    *port = LEDS_ALL_ON;
}

void LedsTurnAllOff(void)
{
    *port = LEDS_ALL_OFF;
}

uint8_t LedsReadState(uint8_t led)
{
    return (((*port)&BitMask(LedToBit(led)))? LED_ON : LED_OFF);
}