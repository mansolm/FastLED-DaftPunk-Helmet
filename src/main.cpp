#include <Arduino.h>
#include "figures.h"
#include "LEDS.h"
#include "animations.h"
#include "BT.h"

void setup()
{
  Serial.begin(9600);
  ledSetup();
}

void loop()
{
  readBT();

  switch (getAnimationState())
  {
  case STARLIGHT:
    starTwinkle(5, 50, 100);
    break;

  case DIAG:
    diagonalRainbow();
    break;

  case FLAMES:
    flames();
    break;

  case EQ:
    equalizer();
    break;

  case RESET_A:
    clearAnimation();
    break;

  default:
    break;
  }

  switch (getFigureState())
  {
  case ANGEL:
    setAngel();
    break;

  case DEVIL:
    setDevil();
    break;

  case TREE:
    setTree();
    break;

  case HAPPY:
    setHappy();
    break;

  case SUPERHAPPY:
    setSuperHappy();
    break;

  case HEART:
    setHeart();
    break;

  case HEARTEMOJI:
    setHeartEmoji();
    break;

  case XD_F:
    setXD();
    break;

  case THOUNG:
    setThoungEmoji();
    break;

  case RESET_F:
    clearFigure();
    break;

  default:
    break;
  }

  FastLED.show();
}