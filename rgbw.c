#include "rgbw.h"

#define GREEN 0, 255, 0, 0
#define ORANGE 255, 165, 0, 0
#define RED 255, 0, 0, 0
#define BLUE 0, 0, 255, 0
#define PINK 255, 105, 180, 0
#define PURPLE 128, 0, 128, 0
#define BLE_ADVERTISING_COLOR 0, 255, 255, 0 // Cyan
#define BLE_CONNECTED_COLOR 0, 255, 127, 0   // Spring Green
#define BLE_TRANSMIT_COLOR 255, 0, 255, 0    // Magenta

uint8_t led_buff[] = {LED_PULSE_0, LED_PULSE_0, LED_PULSE_0, LED_PULSE_0, LED_PULSE_0, LED_PULSE_0, LED_PULSE_0, LED_PULSE_0,  //g
                      LED_PULSE_0, LED_PULSE_0, LED_PULSE_0, LED_PULSE_0, LED_PULSE_0, LED_PULSE_0, LED_PULSE_0, LED_PULSE_0,  //r
                      LED_PULSE_0, LED_PULSE_0, LED_PULSE_0, LED_PULSE_0, LED_PULSE_0, LED_PULSE_0, LED_PULSE_0, LED_PULSE_0,  //b
                      LED_PULSE_0, LED_PULSE_0, LED_PULSE_0, LED_PULSE_0, LED_PULSE_0, LED_PULSE_0, LED_PULSE_0, LED_PULSE_0}; //w

uint8_t colors[4];

void LED_Configuration(void)
{
    GPIO_InitType GPIO_InitStructure;

    /* Enables the GPIO Clock */
    SysCtrl_PeripheralClockCmd(CLOCK_PERIPH_GPIO, ENABLE);

    /* LED */
    GPIO_InitStructure.GPIO_Pin = LED_RGBW;
    GPIO_InitStructure.GPIO_Mode = Serial0_Mode;
    GPIO_InitStructure.GPIO_Pull = DISABLE;
    GPIO_InitStructure.GPIO_HighPwr = DISABLE;
    GPIO_Init(&GPIO_InitStructure);

    /* SPI Initialization */
    SPI_Configuration();
}

void SPI_Configuration(void)
{
    SPI_InitType SPI_InitStructure;

    /* Enables the SPI Clock */
    SysCtrl_PeripheralClockCmd(CLOCK_PERIPH_SPI, ENABLE);

    /* Configure SPI in master mode */
    SPI_StructInit(&SPI_InitStructure);
    SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
    SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
    SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
    SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
    SPI_InitStructure.SPI_BaudRate = 8000000;
    SPI_Init(&SPI_InitStructure);

    /* Clear RX and TX FIFO */
    SPI_ClearTXFIFO();

    /* Set null character */
    SPI_SetDummyCharacter(0xFF);

    /* Set communication mode */
    SPI_SetMasterCommunicationMode(SPI_TRANSMIT_MODE);

    /* Enable SPI functionality */
    SPI_Cmd(ENABLE);
}

void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t w)
{
    colors[0] = g;
    colors[1] = r;
    colors[2] = b;
    colors[3] = w;
}

void setLED(int color)
{
    encode(led_buff);
    SPI_Send(led_buff, sizeof(led_buff));
    led_updated = TRUE;
}

void encode(uint8_t *output)
{
    uint8_t i;

    for (i = 0; i < 32; i++)
    {
        if ((colors[i / 8] >> (i % 8)) & 1)
        { //7 - i
            output[i] = LED_PULSE_1;
        }
        else
        {
            output[i] = LED_PULSE_0;
        }
    }
}

void SPI_Send(uint8_t *command, uint8_t len)
{
    uint8_t i;
    for (i = 0; i < len; i++)
    {
        /* Write data to send to TX FIFO */
        while (RESET == SPI_GetFlagStatus(SPI_FLAG_TFE))
            ;
        SPI_SendData(command[i]);
    }
}
