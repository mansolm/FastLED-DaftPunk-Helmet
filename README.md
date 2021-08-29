# FastLED-DaftPunk-Helmet

PlatformIO project for a DaftPunk DJ Hemlemt with a 10x17 WS2812B matix in the visor. Controlled with an Arduino UNO with Bluetooth interaction via HC-06 module.

Wanted to control the leds with a ESP32 or Teensy4.0 for more RAM and better processing power and multioutput of data line. Was unable to due to the leds not responding correctly to the 3.3V One-Wire signals.
Did not have time to get a voltage level regualtor. 

To make up for the tiny RAM of the Arduino UNO the "avr/pgmspace" lib was used to store bit maps on the flash memory.

The Arduino and LED-strips was powered by a porable 12V battery and the Voltage was regualted with LD1085V50 voltage regulators. 
Comands from a Bluetooth terminal on a smartphone can also control what is displayed on the matrix. This makes for a nice wireless and portable DJ helmet. 

[![SC2 Video](https://github.com/MansOlm/FastLED-DaftPunk-Helmet/blob/master/video-1630273437.mp4)
