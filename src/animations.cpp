#include <Arduino.h>
#include <FastLED.h>
#include "figures.h"
#include "constants.h"
#include "LEDS.h"
#include "palettes.h"

void flow()
{
    uint8_t sine = beatsin8(30, 0, NUM_LEDS, 0, 0);
    uint8_t sine2 = beatsin8(30, 0, NUM_LEDS, 0, 127);

    uint8_t sine3 = beatsin8(23, 0, NUM_LEDS, 0, 0);
    uint8_t sine4 = beatsin8(23, 0, NUM_LEDS, 0, 127);
    uint8_t r = beatsin8(30, 40, 200, 0, 0);
    uint8_t g = beatsin8(45, 15, 50, 0, 55);
    uint8_t b = beatsin8(15, 15, 145, 0, 100);

    setLEDSi((sine + sine3) / 2, CRGB(r, g, b));
    setLEDSi((sine2 + sine4) / 2, CRGB(g, b, r));

    fade(NUM_LEDS, 10);
}

static uint8_t diag_count = 0;
void diagonalRainbow()
{
    static CRGB colors[HEIGHT + WIDTH];
    CRGBPalette16 palette = nice_colors;

    EVERY_N_MILLIS(50)
    {

        diag_count = (diag_count + 5) % 256;

        colors[0] = ColorFromPalette(palette, diag_count, 50, LINEARBLEND);

        for (uint8_t i = HEIGHT + WIDTH - 1; i > 0; i--)
        {

            colors[i] = colors[i - 1];
        }

        for (uint8_t i = 0; i < HEIGHT; i++)
        {
            for (uint8_t j = 0; j < WIDTH; j++)
            {
                setLEDS(j, i, colors[i + j]);
            }
        }
    }
}

void starTwinkle(uint8_t intensity, uint8_t fade_v, uint8_t update_time)
{
    EVERY_N_MILLIS(update_time)
    {

        for (uint8_t i = 0; i < intensity; i++)
        {
            setLEDSi(random8(NUM_LEDS), CRGB::White);
        }
        fade(NUM_LEDS, fade_v);
    }
}