# FastLED-DaftPunk-Helmet

PlatformIO project for a DaftPunk DJ Hemlemt with a 10x17 WS2812B matix in the visor. Controlled with an Arduino UNO with Bluetooth interaction via HC-06 module.

Wanted to control the leds with a ESP32 or Teensy4.0 for more RAM and better processing power and multioutput of data line. Was unable to due to the leds not responding correctly to the 3.3V One-Wire signals.
Did not have time to get a voltage level regualtor. 

To make up for the tiny RAM of the Arduino UNO the "avr/pgmspace" lib was used to store bit maps on the flash memory.

The Arduino and LED-strips was powered by a porable 12V battery and the Voltage was regualted with LD1085V50 voltage regulators. 
Comands from a Bluetooth terminal on a smartphone can also control what is displayed on the matrix. This makes for a nice wireless and portable DJ helmet. 


## Images and Video of the Helmet
<img src="https://user-images.githubusercontent.com/47465593/131318763-4db21c6e-eeb4-4e8a-984c-2b80348201cb.jpg" width=50% height=50%>

<img src="https://user-images.githubusercontent.com/47465593/131318747-afa09a7e-ff98-4252-ae54-33a24a3ae379.jpg" width=50% height=50%>



https://user-images.githubusercontent.com/47465593/131267851-88a4c9f0-5dfe-4c7d-9f3b-7d2dffe182cc.mp4



