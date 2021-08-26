#include <Arduino.h>
#include "figures.h"
#include "constants.h"
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

  // diagonalRainbow();
  // starTwinkle(5, 50, 100);

  switch (getState())
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

  default:
    setAngel();
    break;
  }

  FastLED.show();
}