#include <Arduino.h>

#ifndef BT_H
#define BT_H

void readBT();
void setFigureState(uint8_t state);
void setAnimationState(uint8_t state);
uint8_t getFigureState();
uint8_t getAnimationState();

#endif