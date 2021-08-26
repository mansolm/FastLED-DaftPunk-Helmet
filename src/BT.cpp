#include "Arduino.h"
#include "BT.h"

static uint8_t token_state = 0;
uint8_t lastState = 0;

void readBT()
{
    if (Serial.available() > 0)
    {
        token_state = Serial.read();
    }
}

void setState(uint8_t state)
{
    token_state = state;
}

uint8_t getState()
{
    return token_state;
}