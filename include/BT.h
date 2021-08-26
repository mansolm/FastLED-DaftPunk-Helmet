#include <Arduino.h>

#ifndef BT_H
#define BT_H

void readBT();
void setState(uint8_t state);
uint8_t getState();

#endif