#include <Arduino.h>
#include <FastLED.h>
#include "figures.h"
#include "constants.h"
#include "LEDS.h"
#include "palettes.h"
#include "BT.h"

static uint8_t activeAnimation = 0;

void clearAnimation()
{
    if (activeAnimation != getAnimationState())
    {
        FastLED.clear();
        activeAnimation = getAnimationState();
    }
}

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

void flames()
{
    EVERY_N_MILLIS(100)
    {
        CRGBPalette16 palette = flame_palette;

        for (uint8_t i = 0; i < NUM_LEDS; i++)
        {
            setLEDSi(i, ColorFromPalette(palette, random8(255), 20, LINEARBLEND));
        }
    }
}

void drawEqualizer(uint8_t x, uint8_t level)
{
    CRGB colors[] = {0xff0000, 0xffe700, 0xdbff00, 0x20ff00, 0x00ffcc, 0x0089ff, 0x2000ff, 0xa700ff, 0xff00a3, 0xff0011};

    for (uint8_t i = 0; i < HEIGHT - 1; i++)
    {
        if (i < level)
        {
            CRGB color = CRGB(colors[x]);
            color.nscale8(i * 15);
            setLEDS(x, HEIGHT - i - 1, color);
        }
        else
        {
            setLEDS(x, HEIGHT - i - 1, CRGB::Black);
        }
    }
}

static long eq_count = 0;
void equalizer()
{
    static uint8_t levels[WIDTH];

    EVERY_N_MILLIS(10)
    {
        // eq_count++;
        // eq_count = eq_count % sizeof(long);

        uint8_t sin1 = beatsin8(64, 1, 15, 0, 78);
        uint8_t sin2 = beatsin8(53, 1, 15, 0, 140);
        uint8_t sin3 = beatsin8(42, 1, 15, 0, 34);
        uint8_t sin4 = beatsin8(75, 1, 15, 0, 183);
        uint8_t sin5 = beatsin8(53, 1, 15, 0, 241);
        uint8_t sin6 = beatsin8(48, 1, 15, 0, 47);
        uint8_t sin7 = beatsin8(83, 1, 15, 0, 89);
        uint8_t sin8 = beatsin8(74, 1, 15, 0, 120);

        levels[0] = (sin1 + sin2 + sin8) / 3;
        levels[1] = (sin4 + sin5 + sin7) / 3;
        levels[2] = (sin3 + sin6 + sin2) / 3;
        levels[3] = (sin1 + sin4 + sin5) / 3;
        levels[4] = (sin7 + sin4 + sin6) / 3;
        levels[5] = (sin7 + sin2 + sin5) / 3;
        levels[6] = (sin8 + sin1 + sin5) / 3;
        levels[7] = (sin6 + sin1 + sin3) / 3;
        levels[8] = (sin4 + sin7 + sin6) / 3;
        levels[9] = (sin3 + sin7 + sin1) / 3;

        // levels[0] = inoise8(beatsin8(34, 1, 150, 0, 0), eq_count) / 17;
        // levels[1] = inoise8(beatsin8(12, 1, 57, 0, 75), eq_count) / 17;
        // levels[2] = inoise8(beatsin8(23, 1, 213, 0, 173), eq_count) / 17;
        // levels[3] = inoise8(beatsin8(43, 1, 134, 0, 14), eq_count) / 17;
        // levels[4] = inoise8(beatsin8(27, 1, 143, 0, 84), eq_count) / 17;
        // levels[5] = inoise8(beatsin8(39, 1, 98, 0, 243), eq_count) / 17;
        // levels[6] = inoise8(beatsin8(19, 1, 198, 0, 132), eq_count) / 17;
        // levels[7] = inoise8(beatsin8(33, 1, 145, 0, 212), eq_count) / 17;
        // levels[8] = inoise8(beatsin8(22, 1, 137, 0, 79), eq_count) / 17;
        // levels[9] = inoise8(beatsin8(27, 1, 100, 0, 99), eq_count) / 17;

        // levels[0] = beatsin8(43, 1, 14, 0, 0);
        // levels[1] = beatsin8(62, 1, 14, 0, 75);
        // levels[2] = beatsin8(12, 1, 14, 0, 173);
        // levels[3] = beatsin8(86, 1, 14, 0, 14);
        // levels[4] = beatsin8(42, 1, 14, 0, 84);
        // levels[5] = beatsin8(74, 1, 14, 0, 243);
        // levels[6] = beatsin8(36, 1, 14, 0, 132);
        // levels[7] = beatsin8(16, 1, 14, 0, 212);
        // levels[8] = beatsin8(23, 1, 14, 0, 79);
        // levels[9] = beatsin8(45, 1, 14, 0, 99);

        for (uint8_t i = 0; i < WIDTH; i++)
        {
            drawEqualizer(i, levels[i]);
        }
    }
}
