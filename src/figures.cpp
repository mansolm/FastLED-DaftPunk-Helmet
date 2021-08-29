#include <Arduino.h>
#include <FastLED.h>
#include <avr/pgmspace.h>
#include "figures.h"
#include "constants.h"
#include "LEDS.h"
#include "BT.h"

static uint8_t activeFigure = 0;

void setFigure(const unsigned long *figure)
{

    clearFigure();
    for (uint8_t i = 0; i < (WIDTH * 15); i++)
    {
        if (pgm_read_dword(&figure[i]) != 0)
        {
            setLEDS((i % WIDTH), (i / WIDTH), pgm_read_dword(&figure[i]));
        }
    }
}

void clearFigure()
{
    if (activeFigure != getFigureState())
    {
        FastLED.clear();
        activeFigure = getFigureState();
    }
}

void setHeart()
{
    setFigure(heart);
}

void setHeartEmoji()
{
    setFigure(heartEmoji);
}

void setXD()
{
    setFigure(XD);
}

void setThoungEmoji()
{
    setFigure(toungEmoji);
}

void setDevil()
{

    setFigure(devil);
}

void setAngel()
{

    setFigure(angel);
}

void setTree()
{

    setFigure(tree);
}

void setHappy()
{

    setFigure(happy);
}

void setSuperHappy()
{

    setFigure(superHappy);
}