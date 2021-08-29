#include "Arduino.h"
#include "BT.h"

static uint8_t figure_state = 0;
static uint8_t animation_state = 0;

void readBT()
{
    uint8_t c;
    if (Serial.available() > 0)
    {
        c = Serial.read();

        if (c >= 'a' && c <= 'z')
        {
            figure_state = c;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            animation_state = c;
        }
    }
}

void setFigureState(uint8_t state)
{
    figure_state = state;
}

void setAnimationState(uint8_t state)
{
    animation_state = state;
}

uint8_t getFigureState()
{
    return figure_state;
}

uint8_t getAnimationState()
{
    return animation_state;
}