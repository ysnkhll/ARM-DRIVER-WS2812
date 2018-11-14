#ifndef __RGBW_H__
#define __RGBW_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
#include <YOUR_BOARD_CONFIG.h> // Change this

#define LED_PULSE_0 0xc0 // 0b11000000
#define LED_PULSE_1 0xf8 // 0b11111000

void LED_Configuration(void);
void SPI_Configuration(void);
void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t w);
void setLED();
void encode(uint8_t *output);
void SPI_Send(uint8_t *command, uint8_t len);

// Globals
extern volatile uint8_t led_updated;
  
// Colors
#define GREEN 0, 255, 0, 0
#define ORANGE 255, 165, 0, 0
#define RED 255, 0, 0, 0
#define BLUE 0, 0, 255, 0
#define PINK 255, 105, 180, 0
#define PURPLE 128, 0, 128, 0
#define BLE_ADVERTISING_COLOR 0, 255, 255, 0 // Cyan
#define BLE_CONNECTED_COLOR 0, 255, 127, 0   // Spring Green
#define BLE_TRANSMIT_COLOR 255, 0, 255, 0    // Magenta


#ifdef __cplusplus
}
#endif

#endif
