#include <Arduino.h>
#include <FastLED.h>
#include <avr/pgmspace.h>
#include "figures.h"
#include "constants.h"
#include "LEDS.h"
#include "BT.h"

static uint8_t active = 0;

void clear()
{
    if (active != getState())
    {
        FastLED.clear();
        active = getState();
    }
}

void setEyes(uint8_t firstRow)
{
    clear();

    for (uint8_t i = 0; i < (WIDTH * 3); i++)
    {
        if (pgm_read_dword(&eyes[i]) != 0)
        {
            setLEDS((i % WIDTH), (firstRow - 1) + (i / WIDTH), pgm_read_dword(&eyes[i]));
        }
    }
}

void setMouth(uint8_t firstRow)
{

    clear();
    for (uint8_t i = 0; i < (WIDTH * 5); i++)
    {
        if (pgm_read_dword(&mouth[i]) != 0)
        {
            setLEDS((i % WIDTH), (firstRow - 1) + (i / WIDTH), pgm_read_dword(&mouth[i]));
        }
    }
}

void setDevil()
{

    clear();
    for (uint8_t i = 0; i < (WIDTH * 13); i++)
    {
        if (pgm_read_dword(&devil[i]) != 0)
        {
            setLEDS((i % WIDTH), (i / WIDTH), pgm_read_dword(&devil[i]));
        }
    }
}

void setAngel()
{

    clear();
    for (uint8_t i = 0; i < (WIDTH * 15); i++)
    {
        if (pgm_read_dword(&angel[i]) != 0)
        {
            setLEDS((i % WIDTH), (i / WIDTH), pgm_read_dword(&angel[i]));
        }
    }
}

void setTree()
{

    clear();
    for (uint8_t i = 0; i < (WIDTH * 15); i++)
    {
        if (pgm_read_dword(&tree[i]) != 0)
        {
            setLEDS((i % WIDTH), (i / WIDTH), pgm_read_dword(&tree[i]));
        }
    }
}

void setHappy()
{

    clear();
    for (uint8_t i = 0; i < (WIDTH * 15); i++)
    {
        if (pgm_read_dword(&happy[i]) != 0)
        {
            setLEDS((i % WIDTH), (i / WIDTH), pgm_read_dword(&happy[i]));
        }
    }
}

void setSuperHappy()
{

    clear();
    for (uint8_t i = 0; i < (WIDTH * 15); i++)
    {
        if (pgm_read_dword(&superHappy[i]) != 0)
        {
            setLEDS((i % WIDTH), (i / WIDTH), pgm_read_dword(&superHappy[i]));
        }
    }
}