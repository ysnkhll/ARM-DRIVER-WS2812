# ARM-WS2812-DRIVER
An ARM C driver for the WS2812 a.k.a. "NeoPixel". 
This was developed for the BlueNRG2 SoC. However, this should be easily portable to any other ARM based SoC.
This implementation uses SPI to generate the clock. Most of the functionality is self explanatory. 

## Usage

### Initialization
1. LED_Configuration();
2. SPI_Configuration();

### Runtime
1. setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t w);
2. setLED(int color);
3. SPI_Send(uint8_t *command, uint8_t len);



N.B. You may need to rearange the order of the `colors[4]` variable inside of the `setColor` function.
My chips were arranged as GRBW as apposed to simply RGBW.
