#include <Arduino.h>
#include <FastLED.h>

#ifndef LEDS_H
#define LEDS_H

void ledSetup();

void fade(uint16_t num, uint8_t scale);
void setLEDSi(uint8_t i, CRGB color);
void setLEDS(uint8_t x, uint8_t y, CRGB color);
void showLEDS();
CRGB *getLeds();

#endif