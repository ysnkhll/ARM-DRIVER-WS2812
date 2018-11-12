# ARM-DRIVER-WS2812
An ARM C driver for the WS2812 a.k.a. "NeoPixel". 
This was developed for the BlueNRG2 SoC. However, this should be easily portable to any other ARM based SoC.
This implementation uses SPI to generate the clock. Most of the functionality is self explanatory. You may need to rearange the 
structor of the colors as my chips were arranged as GRBW as apposed to RGBW.
