#ifndef __LAND_RGBW_H__
#define __LAND_RGBW_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
#include <YOUR_BOARD_CONFIG.h>

/*
	clock     = 8MHz
	1 cycle   = 125 ns
	0 pulse   = 375 ns    = 3     cycles = 3 HIGH 9 LOW
	1 pulse   = 750 ns    = 6     cycles = 6 HIGH 6 LOW
	period    = 1500 ns   = 12    cycles
	SET       = 80 us     = 640   cycles
	TOTAL = 1024 cycles
*/
#define LED_PULSE_0 0xc0 // 0b11000000
#define LED_PULSE_1 0xf8 // 0b11111000

#define LED_GREEN   1
#define LED_ORANGE  2
#define LED_RED     3
#define LED_BLUE    4

void LED_Configuration(void);
void SPI_Configuration(void);
void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t w);
void setLED(int color);
void encode(uint8_t *output);
void SPI_Send(uint8_t *command, uint8_t len);

// Globals
extern volatile uint8_t led_updated;

#ifdef __cplusplus
}
#endif

#endif
