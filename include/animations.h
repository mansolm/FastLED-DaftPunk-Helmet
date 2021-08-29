#include <Arduino.h>

#ifndef ANIMA
#define ANIMA

const uint8_t STARLIGHT = 'S';
const uint8_t DIAG = 'D';
const uint8_t FLAMES = 'F';
const uint8_t EQ = 'E';
const uint8_t RESET_A = 'R';

void flow();
void diagonalRainbow();
void clearAnimation();
void flames();
void equalizer();
void starTwinkle(uint8_t intensity, uint8_t fade_v, uint8_t update_time);

#endif