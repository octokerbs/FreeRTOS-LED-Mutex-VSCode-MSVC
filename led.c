#include <FreeRTOS.h>
#include <stdio.h>
#include <task.h>
#include <semphr.h>

#include "led.h"

char *currentColor = "RED";

void vLedColor(void *pvParameters)
{
    for (;;)
    {
        system("cls");
        printf("%s\n", currentColor);
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

void vLedStartRedColor(void *pvParameters)
{
    SemaphoreHandle_t myMutex = (SemaphoreHandle_t)pvParameters;

    for (;;)
    {
        if (xSemaphoreTake(myMutex, 0) == pdTRUE)
        {
            currentColor = "RED";
            xSemaphoreGive(myMutex);
        }
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

void vLedStartGreenColor(void *pvParameters)
{
    SemaphoreHandle_t myMutex = (SemaphoreHandle_t)pvParameters;

    for (;;)
    {
        int taskDuration = ((rand() % 10) + 1) * 100;
        int timeDelayForNewTask = ((rand() % 10) + 1) * 300;

        xSemaphoreTake(myMutex, portMAX_DELAY);
        currentColor = "GREEN";
        vTaskDelay(pdMS_TO_TICKS(taskDuration)); /* Working task turns led on ... */
        xSemaphoreGive(myMutex);

        vTaskDelay(pdMS_TO_TICKS(timeDelayForNewTask));
    }
}
