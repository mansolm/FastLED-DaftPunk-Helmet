#include <Arduino.h>
#include <FastLED.h>
#include "constants.h"
#include "LEDS.h"

CRGB leds[NUM_LEDS];

void ledSetup()
{
    FastLED.addLeds<CHIPSET, LED_PIN, GBR>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(BRIGHTNESS);
}

uint16_t XY(uint8_t x, uint8_t y)
{
    if (y % 2 == 0)
    {
        return (y * WIDTH) + x;
    }
    return (y * WIDTH) + (WIDTH - x - 1);
}

void setLEDS(uint8_t x, uint8_t y, CRGB color)
{
    leds[XY(x, y)] = color;
}

void setLEDSi(uint8_t i, CRGB color)
{
    leds[i] = color;
}

void fade(uint16_t num, uint8_t scale)
{
    fadeToBlackBy(leds, num, scale);
}

CRGB *getLeds()
{
    return leds;
}

void showLEDS()
{
    FastLED.show();
}