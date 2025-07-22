#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>
#include <semphr.h>

#include "led.h"

int main()
{

    srand(time(NULL));

    SemaphoreHandle_t xMutex = xSemaphoreCreateMutex();
    if (xMutex == NULL)
    {
        printf("Failed to create mutex\n");
        return 1;
    }

    BaseType_t led = xTaskCreate(vLedColor, "LED", 1024, NULL, 1, NULL);
    if (led != pdPASS)
    {
        printf("Failed to create LED\n");
        return 1;
    }

    BaseType_t red = xTaskCreate(vLedStartRedColor, "RED", 1024, (void *)xMutex, 1, NULL);
    if (red != pdPASS)
    {
        printf("Failed to create RED\n");
        return 1;
    }

    BaseType_t green = xTaskCreate(vLedStartGreenColor, "GREEN", 1024, (void *)xMutex, 1, NULL);
    if (green != pdPASS)
    {
        printf("Failed to create GREEN\n");
        return 1;
    }

    vTaskStartScheduler();

    for (;;)
    {
    }
}