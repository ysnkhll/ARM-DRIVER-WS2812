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

#ifdef __cplusplus
}
#endif

#endif
